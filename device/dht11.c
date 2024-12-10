#include "dht11.h"//����ͷ�ļ�
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
DHT11�ĳ�ʼ��������
-------------------------------------------------------*/
void dht11_init(dht11_def * dev,u8 pin){
    dev->port=io2port(pin); //�����ͱ����������á�
    dev->pin =io2pin (pin);
    dev->temp=0;            //��������ʼ��Ϊ0��
    dev->humi=0;
    gpio_mode(pin,GPIO_IN); //����IO��Ϊ����ģʽ��
    gpio_out (pin,1);       //���߿��е�ƽΪ�ߵ�ƽ��
}
/*-------------------------------------------------------
DHT11�����к�����
-------------------------------------------------------*/
u8 dht11_run(dht11_def * dev){
    u8 timeout,i,t,j;
    u8 temp[5];
    u16 _5us,_10us,_30us;
    _5us=delay_set_us(5);
    _10us=delay_set_us(10);
    _30us=delay_set_us(30);
    gpio_out_fast(dev->port,dev->pin,0);//��ʼ�ź�
    delay_ms(19);           //����18ms����
    gpio_out_fast(dev->port,dev->pin,1);//��������
    delay_us(_30us);        //�ȴ�DHT11��Ӧ
    if(gpio_in_fast(dev->port,dev->pin)==0){    //�ж�DHT11�Ƿ���Ӧ�����û�е͵�ƽ˵��û��Ӧ
        timeout=2;
        while((gpio_in_fast(dev->port,dev->pin)==0)&&(timeout++))delay_us(_10us);//�ȴ��͵�ƽ��Ӧ����
        if(timeout==1)return 2;//��ʱ���أ�ʱ��Ϊ10us*255=2.5ms
        timeout=2;
        while((gpio_in_fast(dev->port,dev->pin)==1)&&(timeout++))delay_us(_10us);//�ȴ��ߵ�ƽ��Ӧ����
        if(timeout==1)return 2;//��ʱ����
        for(j=0;j<5;j++){//һ������5λ����
            t=0;        //������ʱ����
            for(i=0;i<8;i++){
                timeout=2;
                while((gpio_in_fast(dev->port,dev->pin)==0)&&(timeout++))delay_us(_5us);//�ȴ����ݿ�ʼ�źţ��͵�ƽ������
                if(timeout==1)return 2;//��ʱ����,ʱ��Ϊ1us*255=255us
                delay_us(_30us);//�͵�ƽ֮��ӵĸߵ�ƽ�ĳ���ʱ����26us~28us��ʾ0.��ô����ʱ29us�����ŵ�ƽ
                t<<=1;
                if(gpio_in_fast(dev->port,dev->pin)==1){//��ʱ���Ǹߵ�ƽ�Ļ���˵�������ݡ�1��
                    t|=1;
                }//����������ݡ�0������ɶ�����ø�
                timeout=2;
                while((gpio_in_fast(dev->port,dev->pin)==1)&&(timeout++))delay_us(_5us);//ȷ���ߵ�ƽ����
                if(timeout==1)return 2;//��ʱ
            }
            temp[j]=t;//����ʱ������ֵװ��������
        }
        t=temp[0]+temp[1]+temp[2]+temp[3];//����У���
        if(t==temp[4]){//У�����ȷ�ͷ���0����ʾһ������
            dev->temp=temp[2];
            dev->humi=temp[0];
            return 0;//����
        }
    }
    return 1;//���ݴ������
}
