#include "ecbm_core.h"      //统一加载核心头文件
#if (ECBM_SOFTSPI_LIB_EN)   //检查本库有没有被使能
/*--------------------------------------变量定义-----------------------------------*/
u8  data soft_spi_def_clk_port_gdu8;
u8  data soft_spi_def_clk_pin_gdu8;
u8  data soft_spi_def_mosi_port_gdu8;
u8  data soft_spi_def_mosi_pin_gdu8;
u8  data soft_spi_def_miso_port_gdu8;
u8  data soft_spi_def_miso_pin_gdu8;
u8  data soft_spi_mode_gdu8=0;
u8 xdata soft_spi_index_gxu8=0;
u8 xdata soft_spi_max_gxu8=0;
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
软件SPI引脚切换函数。
-------------------------------------------------------*/
void soft_spi_set_pin(soft_spi_def * dev){
    if(soft_spi_index_gxu8!=dev->dev_id){                  //判断ID号，可以加速8us@24MHz的时间。
        soft_spi_def_clk_port_gdu8 =io2port(dev->clk_pin); //解压时钟脚的P口。
        soft_spi_def_clk_pin_gdu8  =io2pin (dev->clk_pin); //解压时钟脚的IO口。
        soft_spi_def_mosi_port_gdu8=io2port(dev->mosi_pin);//解压数据输出脚的P口。
        soft_spi_def_mosi_pin_gdu8 =io2pin (dev->mosi_pin);//解压数据输出脚的IO口。
        soft_spi_def_miso_port_gdu8=io2port(dev->miso_pin);//解压数据输入脚的P口。
        soft_spi_def_miso_pin_gdu8 =io2pin (dev->miso_pin);//解压数据输入脚的IO口。
        soft_spi_mode_gdu8=dev->mode;                      //设置模式。
        soft_spi_index_gxu8=dev->dev_id;                   //切换ID。
    }    
}
/*-------------------------------------------------------
软件SPI初始化函数。
-------------------------------------------------------*/
void soft_spi_init(soft_spi_def * dev,u8 clk,u8 mosi,u8 miso,u8 mode){
    dev->clk_pin =clk;             //保存时钟脚信息。
    dev->mosi_pin=mosi;            //保存数据输出脚信息。
    dev->miso_pin=miso;            //保存数据输入脚信息。
    dev->mode    =mode;            //保存模式信息。
    gpio_mode(clk, GPIO_OUT);      //时钟脚设置为推挽。
    if(mode&SOFT_SPI_CPOL_MASK){   //查看时钟极性设置，
        gpio_out(clk,1);           //极性是高电平就先置高，
    }else{
        gpio_out(clk,0);           //极性是低电平就先置低。
    }
    if(mode&SOFT_SPI_MOSI_EN_MASK){//查看MOSI使能，
        gpio_mode(mosi,GPIO_OUT);  //使能了就设置为推挽模式。
        gpio_out (mosi,1);         //默认高电平。
    }
    if(mode&SOFT_SPI_MISO_EN_MASK){//查看MISO使能，
        gpio_mode  (miso,GPIO_IN); //使能了就设置为弱上拉模式。
        gpio_out   (miso,1);       //默认高电平。
    }
    dev->dev_id=++soft_spi_max_gxu8;    //获取ID号。
    soft_spi_set_pin(dev);         //设置参数到系统。
} 
/*-------------------------------------------------------
软件SPI引脚切换函数（内联版）。
-------------------------------------------------------*/
void soft_spi_set_pin_linkage(u8 id,u8 clk,u8 mosi,u8 miso,u8 mode){
    if(soft_spi_index_gxu8!=id){                    //判断ID号，可以加速8us@24MHz的时间。
        soft_spi_def_clk_port_gdu8 =io2port(clk);   //解压时钟脚的P口。
        soft_spi_def_clk_pin_gdu8  =io2pin (clk);   //解压时钟脚的IO口。
        soft_spi_def_mosi_port_gdu8=io2port(mosi);  //解压数据输出脚的P口。
        soft_spi_def_mosi_pin_gdu8 =io2pin (mosi);  //解压数据输出脚的IO口。
        soft_spi_def_miso_port_gdu8=io2port(miso);  //解压数据输入脚的P口。
        soft_spi_def_miso_pin_gdu8 =io2pin (miso);  //解压数据输入脚的IO口。
        soft_spi_mode_gdu8=mode;                    //设置模式。
        soft_spi_index_gxu8=id;                     //切换ID。
    }    
}
/*-------------------------------------------------------
软件SPI初始化函数（内联版）。
-------------------------------------------------------*/
u8 soft_spi_init_linkage(u8 clk,u8 mosi,u8 miso,u8 mode){
    u8 id_u8;                         //唯一ID号
    gpio_mode(clk, GPIO_OUT);      //时钟脚设置为推挽。
    if(mode&SOFT_SPI_CPOL_MASK){   //查看时钟极性设置，
        gpio_out(clk,1);           //极性是高电平就先置高，
    }else{
        gpio_out(clk,0);           //极性是低电平就先置低。
    }
    if(mode&SOFT_SPI_MOSI_EN_MASK){//查看MOSI使能，
        gpio_mode(mosi,GPIO_OUT);  //使能了就设置为推挽模式。
        gpio_out (mosi,1);         //默认高电平。
    }
    if(mode&SOFT_SPI_MISO_EN_MASK){//查看MISO使能，
        gpio_mode  (miso,GPIO_IN); //使能了就设置为弱上拉模式。
        gpio_out   (miso,1);       //默认高电平。
    }
    id_u8 =++soft_spi_max_gxu8;            //获取ID号。
    soft_spi_set_pin_linkage(id_u8,clk,mosi,miso,mode);//设置参数到系统。
    return id_u8;                       //返回ID号。
} 
/*-------------------------------------------------------
软件SPI发送/接收函数。
-------------------------------------------------------*/
u8 soft_spi_send(u8 dat){
    u8 i_u8,j_u8,k_u8=0;
    if(soft_spi_mode_gdu8&SOFT_SPI_CPOL_MASK){                           //读取时钟极性参数。
        gpio_out_fast(soft_spi_def_clk_port_gdu8,soft_spi_def_clk_pin_gdu8,1);//根据参数设置一下IO的初始状态。
    }else{
        gpio_out_fast(soft_spi_def_clk_port_gdu8,soft_spi_def_clk_pin_gdu8,0);//目的是为了防止多引脚复用下的电平错位。
    }
    if(soft_spi_mode_gdu8&SOFT_SPI_MSB_LSB_MASK){//如果是先发高位。
        i_u8=0x80;
        for(j_u8=0;j_u8<8;j_u8++){                   //8位的数据。
            if(dat&i_u8){                      //根据当前位决定输出电平。
                gpio_out_fast(soft_spi_def_mosi_port_gdu8,soft_spi_def_mosi_pin_gdu8,1);
            }else{
                gpio_out_fast(soft_spi_def_mosi_port_gdu8,soft_spi_def_mosi_pin_gdu8,0);
            }
            gpio_toggle_fast(soft_spi_def_clk_port_gdu8,soft_spi_def_clk_pin_gdu8);//时钟脚第一次翻转。
            if((soft_spi_mode_gdu8&SOFT_SPI_MISO_EN_MASK)&&((soft_spi_mode_gdu8&SOFT_SPI_CPHA_MASK)==0)){//读取时钟相位设置。
                if(gpio_in_fast(soft_spi_def_miso_port_gdu8,soft_spi_def_miso_pin_gdu8)){//设置是第一次翻转读的话，就读MISO脚。
                    k_u8|=i_u8;//将MISO脚的数据存入临时变量里。
                }
            }
            gpio_toggle_fast(soft_spi_def_clk_port_gdu8,soft_spi_def_clk_pin_gdu8);//时钟脚第二次翻转。
            if((soft_spi_mode_gdu8&SOFT_SPI_MISO_EN_MASK)&&((soft_spi_mode_gdu8&SOFT_SPI_CPHA_MASK)==1)){//读取时钟相位设置。
                if(gpio_in_fast(soft_spi_def_miso_port_gdu8,soft_spi_def_miso_pin_gdu8)){//设置是第二次翻转读的话，就读MISO脚。
                    k_u8|=i_u8;//将MISO脚的数据存入临时变量里。
                }
            }
            i_u8>>=1;
        }
    }else{                                  //如果是先发低位
        i_u8=0x01;
        for(j_u8=0;j_u8<8;j_u8++){                  //8位的数据。
            if(dat&i_u8){                     //根据当前位决定输出电平。
                gpio_out_fast(soft_spi_def_mosi_port_gdu8,soft_spi_def_mosi_pin_gdu8,1);
            }else{
                gpio_out_fast(soft_spi_def_mosi_port_gdu8,soft_spi_def_mosi_pin_gdu8,0);
            }
            gpio_toggle_fast(soft_spi_def_clk_port_gdu8,soft_spi_def_clk_pin_gdu8);//时钟脚第一次翻转。
            if((soft_spi_mode_gdu8&SOFT_SPI_MISO_EN_MASK)&&((soft_spi_mode_gdu8&SOFT_SPI_CPHA_MASK)==0)){//读取时钟相位设置。
                if(gpio_in_fast(soft_spi_def_miso_port_gdu8,soft_spi_def_miso_pin_gdu8)){//设置是第一次翻转读的话，就读MISO脚。
                    k_u8|=i_u8;//将MISO脚的数据存入临时变量里。
                }
            }
            gpio_toggle_fast(soft_spi_def_clk_port_gdu8,soft_spi_def_clk_pin_gdu8);
            if((soft_spi_mode_gdu8&SOFT_SPI_MISO_EN_MASK)&&((soft_spi_mode_gdu8&SOFT_SPI_CPHA_MASK)==1)){//读取时钟相位设置。
                if(gpio_in_fast(soft_spi_def_miso_port_gdu8,soft_spi_def_miso_pin_gdu8)){//设置是第二次翻转读的话，就读MISO脚。
                    k_u8|=i_u8;//将MISO脚的数据存入临时变量里。
                }
            }
            i_u8<<=1;
        }
    }
    return k_u8;//返回缓存值。
}
#endif  //和最上面的#ifndef配合成一个程序段。
        //以一个空行为结尾。