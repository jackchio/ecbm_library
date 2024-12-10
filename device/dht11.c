#include "dht11.h"//加载头文件
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
DHT11的初始化函数。
-------------------------------------------------------*/
void dht11_init(dht11_def * dev,u8 pin){
    dev->port=io2port(pin); //解析和保存引脚配置。
    dev->pin =io2pin (pin);
    dev->temp=0;            //将变量初始化为0。
    dev->humi=0;
    gpio_mode(pin,GPIO_IN); //设置IO口为输入模式。
    gpio_out (pin,1);       //总线空闲电平为高电平。
}
/*-------------------------------------------------------
DHT11的运行函数。
-------------------------------------------------------*/
u8 dht11_run(dht11_def * dev){
    u8 timeout,i,t,j;
    u8 temp[5];
    u16 _5us,_10us,_30us;
    _5us=delay_set_us(5);
    _10us=delay_set_us(10);
    _30us=delay_set_us(30);
    gpio_out_fast(dev->port,dev->pin,0);//开始信号
    delay_ms(19);           //拉低18ms以上
    gpio_out_fast(dev->port,dev->pin,1);//拉高总线
    delay_us(_30us);        //等待DHT11响应
    if(gpio_in_fast(dev->port,dev->pin)==0){    //判断DHT11是否响应，如果没有低电平说明没响应
        timeout=2;
        while((gpio_in_fast(dev->port,dev->pin)==0)&&(timeout++))delay_us(_10us);//等待低电平响应结束
        if(timeout==1)return 2;//超时返回，时间为10us*255=2.5ms
        timeout=2;
        while((gpio_in_fast(dev->port,dev->pin)==1)&&(timeout++))delay_us(_10us);//等待高电平响应结束
        if(timeout==1)return 2;//超时返回
        for(j=0;j<5;j++){//一共接收5位数据
            t=0;        //清零临时变量
            for(i=0;i<8;i++){
                timeout=2;
                while((gpio_in_fast(dev->port,dev->pin)==0)&&(timeout++))delay_us(_5us);//等待数据开始信号（低电平）结束
                if(timeout==1)return 2;//超时返回,时间为1us*255=255us
                delay_us(_30us);//低电平之后接的高电平的持续时间在26us~28us表示0.那么就延时29us看引脚电平
                t<<=1;
                if(gpio_in_fast(dev->port,dev->pin)==1){//此时还是高电平的话，说明是数据“1”
                    t|=1;
                }//否则就是数据“0”，就啥都不用干
                timeout=2;
                while((gpio_in_fast(dev->port,dev->pin)==1)&&(timeout++))delay_us(_5us);//确保高电平结束
                if(timeout==1)return 2;//超时
            }
            temp[j]=t;//将临时变量的值装填到输出数组
        }
        t=temp[0]+temp[1]+temp[2]+temp[3];//计算校验和
        if(t==temp[4]){//校验和正确就返回0，表示一切正常
            dev->temp=temp[2];
            dev->humi=temp[0];
            return 0;//正常
        }
    }
    return 1;//数据传输错误
}
