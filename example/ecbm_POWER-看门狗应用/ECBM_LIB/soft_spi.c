#include "ecbm_core.h"//统一加载核心头文件
#if ECBM_SOFT_SPI_EN
u8 xdata soft_spi_def_clk_port;
u8 xdata soft_spi_def_clk_pin;
u8 xdata soft_spi_def_mosi_port;
u8 xdata soft_spi_def_mosi_pin;
u8 xdata soft_spi_def_miso_port;
u8 xdata soft_spi_def_miso_pin;
u8 xdata soft_spi_def_cs_port;
u8 xdata soft_spi_def_cs_pin;
u8 xdata soft_spi_mode=0;
u8 xdata soft_spi_index=0;
u8 xdata soft_spi_max=0;
/*-------------------------------------------------------
软件SPI引脚切换函数。
-------------------------------------------------------*/
void soft_spi_set_pin(soft_spi_def * dev){
	if(soft_spi_index!=dev->dev_id){                  //判断ID号，可以加速8us@24MHz的时间。
		soft_spi_def_clk_port =io2port(dev->clk_pin); //解压时钟脚的P口。
		soft_spi_def_clk_pin  =io2pin (dev->clk_pin); //解压时钟脚的IO口。
		soft_spi_def_mosi_port=io2port(dev->mosi_pin);//解压数据输出脚的P口。
		soft_spi_def_mosi_pin =io2pin (dev->mosi_pin);//解压数据输出脚的IO口。
		soft_spi_def_miso_port=io2port(dev->miso_pin);//解压数据输入脚的P口。
		soft_spi_def_miso_pin =io2pin (dev->miso_pin);//解压数据输入脚的IO口。
		soft_spi_def_cs_port  =io2port(dev->cs_pin);  //解压片选脚的P口。
		soft_spi_def_cs_pin   =io2pin (dev->cs_pin);  //解压片选脚的IO口。
		soft_spi_mode=dev->mode;                      //设置模式。
		soft_spi_index=dev->dev_id;                   //切换ID。
	}	
}
/*-------------------------------------------------------
软件SPI初始化函数。
-------------------------------------------------------*/
void soft_spi_init(soft_spi_def * dev,u8 clk,u8 mosi,u8 miso,u8 cs,u8 mode){
	dev->clk_pin =clk;             //保存时钟脚信息。
	dev->mosi_pin=mosi;            //保存数据输出脚信息。
	dev->miso_pin=miso;            //保存数据输入脚信息。
	dev->cs_pin  =cs;              //保存片选脚信息。
	dev->mode    =mode;            //保存模式信息。
	gpio_mode(clk, GPIO_PP);       //时钟脚设置为推挽。
	if(mode&SOFT_SPI_CPOL_MASK){   //查看时钟极性设置，
		gpio_out(clk,1);           //极性是高电平就先置高，
	}else{
		gpio_out(clk,0);           //极性是低电平就先置低。
	}
	if(mode&SOFT_SPI_MOSI_EN_MASK){//查看MOSI使能，
		gpio_mode(mosi,GPIO_PP);   //使能了就设置为推挽模式。
		gpio_out (mosi,1);         //默认高电平。
	}
	if(mode&SOFT_SPI_MISO_EN_MASK){//查看MISO使能，
		gpio_mode  (miso,GPIO_OD); //使能了就设置为开漏模式。
		gpio_uppull(miso,1);       //开启上拉电阻。
		gpio_out   (miso,1);       //默认高电平。
	}
	if(mode&SOFT_SPI_CS_EN_MASK){  //查看片选脚使能，
		gpio_mode(cs,GPIO_PP);     //使能了就设置为推挽模式。
		gpio_out (cs,1);           //默认高电平。
	}
	dev->dev_id=++soft_spi_max;    //获取ID号。
	soft_spi_set_pin(dev);         //设置参数到系统。
} 
/*-------------------------------------------------------
软件SPI引脚切换函数（内联版）。
-------------------------------------------------------*/
void soft_spi_set_pin_linkage(u8 id,u8 clk,u8 mosi,u8 miso,u8 cs,u8 mode){
	if(soft_spi_index!=id){                    //判断ID号，可以加速8us@24MHz的时间。
		soft_spi_def_clk_port =io2port(clk);   //解压时钟脚的P口。
		soft_spi_def_clk_pin  =io2pin (clk);   //解压时钟脚的IO口。
		soft_spi_def_mosi_port=io2port(mosi);  //解压数据输出脚的P口。
		soft_spi_def_mosi_pin =io2pin (mosi);  //解压数据输出脚的IO口。
		soft_spi_def_miso_port=io2port(miso);  //解压数据输入脚的P口。
		soft_spi_def_miso_pin =io2pin (miso);  //解压数据输入脚的IO口。
		soft_spi_def_cs_port  =io2port(cs);    //解压片选脚的P口。
		soft_spi_def_cs_pin   =io2pin (cs);    //解压片选脚的IO口。
		soft_spi_mode=mode;                    //设置模式。
		soft_spi_index=id;                     //切换ID。
	}	
}
/*-------------------------------------------------------
软件SPI初始化函数（内联版）。
-------------------------------------------------------*/
u8 soft_spi_init_linkage(u8 clk,u8 mosi,u8 miso,u8 cs,u8 mode){
	u8 id;                         //唯一ID号
	gpio_mode(clk, GPIO_PP);       //时钟脚设置为推挽。
	if(mode&SOFT_SPI_CPOL_MASK){   //查看时钟极性设置，
		gpio_out(clk,1);           //极性是高电平就先置高，
	}else{
		gpio_out(clk,0);           //极性是低电平就先置低。
	}
	if(mode&SOFT_SPI_MOSI_EN_MASK){//查看MOSI使能，
		gpio_mode(mosi,GPIO_PP);   //使能了就设置为推挽模式。
		gpio_out (mosi,1);         //默认高电平。
	}
	if(mode&SOFT_SPI_MISO_EN_MASK){//查看MISO使能，
		gpio_mode  (miso,GPIO_OD); //使能了就设置为开漏模式。
		gpio_uppull(miso,1);       //开启上拉电阻。
		gpio_out   (miso,1);       //默认高电平。
	}
	if(mode&SOFT_SPI_CS_EN_MASK){  //查看片选脚使能，
		gpio_mode(cs,GPIO_PP);     //使能了就设置为推挽模式。
		gpio_out (cs,1);           //默认高电平。
	}
	id =++soft_spi_max;            //获取ID号。
	soft_spi_set_pin_linkage(id,clk,mosi,miso,cs,mode);//设置参数到系统。
	return id;	                   //返回ID号。
} 
/*-------------------------------------------------------
软件SPI发送/接收函数。
-------------------------------------------------------*/
u8 soft_spi_send(u8 dat){
	u8 i,j,k=0;
	if(soft_spi_mode&SOFT_SPI_CPOL_MASK){                           //读取时钟极性参数。
		gpio_out_fast(soft_spi_def_clk_port,soft_spi_def_clk_pin,1);//根据参数设置一下IO的初始状态。
	}else{
		gpio_out_fast(soft_spi_def_clk_port,soft_spi_def_clk_pin,0);//目的是为了防止多引脚复用下的电平错位。
	}
	if((soft_spi_mode&(SOFT_SPI_CS_CON_MASK|SOFT_SPI_CS_EN_MASK))==(SOFT_SPI_CS_CON_MASK|SOFT_SPI_CS_EN_MASK)){
		gpio_out_fast(soft_spi_def_cs_port,soft_spi_def_cs_pin,0);//如果片选脚使能且由库函数控制，就拉低电平。
	}
	if(soft_spi_mode&SOFT_SPI_MSB_LSB_MASK){//如果是先发高位。
		i=0x80;
		for(j=0;j<8;j++){                   //8位的数据。
			if(dat&i){                      //根据当前位决定输出电平。
				gpio_out_fast(soft_spi_def_mosi_port,soft_spi_def_mosi_pin,1);
			}else{
				gpio_out_fast(soft_spi_def_mosi_port,soft_spi_def_mosi_pin,0);
			}
			gpio_toggle_fast(soft_spi_def_clk_port,soft_spi_def_clk_pin);//时钟脚第一次翻转。
			if((soft_spi_mode&SOFT_SPI_MISO_EN_MASK)&&((soft_spi_mode&SOFT_SPI_CPHA_MASK)==0)){//读取时钟相位设置。
				if(gpio_in_fast(soft_spi_def_miso_port,soft_spi_def_miso_pin)){//设置是第一次翻转读的话，就读MISO脚。
					k|=i;//将MISO脚的数据存入临时变量里。
				}
			}
			gpio_toggle_fast(soft_spi_def_clk_port,soft_spi_def_clk_pin);//时钟脚第二次翻转。
			if((soft_spi_mode&SOFT_SPI_MISO_EN_MASK)&&((soft_spi_mode&SOFT_SPI_CPHA_MASK)==1)){//读取时钟相位设置。
				if(gpio_in_fast(soft_spi_def_miso_port,soft_spi_def_miso_pin)){//设置是第二次翻转读的话，就读MISO脚。
					k|=i;//将MISO脚的数据存入临时变量里。
				}
			}
			i>>=1;
		}
	}else{                                  //如果是先发低位
		i=0x01;
		for(j=0;j<8;j++){                  //8位的数据。
			if(dat&i){                     //根据当前位决定输出电平。
				gpio_out_fast(soft_spi_def_mosi_port,soft_spi_def_mosi_pin,1);
			}else{
				gpio_out_fast(soft_spi_def_mosi_port,soft_spi_def_mosi_pin,0);
			}
			gpio_toggle_fast(soft_spi_def_clk_port,soft_spi_def_clk_pin);//时钟脚第一次翻转。
			if((soft_spi_mode&SOFT_SPI_MISO_EN_MASK)&&((soft_spi_mode&SOFT_SPI_CPHA_MASK)==0)){//读取时钟相位设置。
				if(gpio_in_fast(soft_spi_def_miso_port,soft_spi_def_miso_pin)){//设置是第一次翻转读的话，就读MISO脚。
					k|=i;//将MISO脚的数据存入临时变量里。
				}
			}
			gpio_toggle_fast(soft_spi_def_clk_port,soft_spi_def_clk_pin);
			if((soft_spi_mode&SOFT_SPI_MISO_EN_MASK)&&((soft_spi_mode&SOFT_SPI_CPHA_MASK)==1)){//读取时钟相位设置。
				if(gpio_in_fast(soft_spi_def_miso_port,soft_spi_def_miso_pin)){//设置是第二次翻转读的话，就读MISO脚。
					k|=i;//将MISO脚的数据存入临时变量里。
				}
			}
			i<<=1;
		}
	}
	if((soft_spi_mode&(SOFT_SPI_CS_CON_MASK|SOFT_SPI_CS_EN_MASK))==(SOFT_SPI_CS_CON_MASK|SOFT_SPI_CS_EN_MASK)){
		gpio_out_fast(soft_spi_def_cs_port,soft_spi_def_cs_pin,1);//如果片选脚使能且由库函数控制，就拉高电平。
	}
	return k;//返回缓存值。
}
#endif