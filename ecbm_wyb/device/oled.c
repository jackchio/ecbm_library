#include "oled.h"
/*-------------------------------------------------------
OLED设置引脚函数，用于软件IIC模式。
-------------------------------------------------------*/
void oled_set_soft_iic(oled_def * dev,u8 scl,u8 sda){
	dev->mode=OLED_SOFT_IIC;                  //设置模式为软件IIC。
	dev->id  =soft_iic_init_linkage(scl,sda); //调用内联函数初始化软件IIC。
	dev->scl_pin =scl;                        //保存时钟脚设置。
	dev->sda_pin =sda;                        //保存数据脚设置。
}
/*-------------------------------------------------------
OLED设置引脚函数，用于硬件IIC模式。
-------------------------------------------------------*/
void oled_set_hard_iic(oled_def * dev,u8 scl,u8 sda){
	dev->mode=OLED_HARD_IIC;//设置模式为硬件IIC。
	dev->id  =0;            //先这样设置着...
	scl      =scl;          //无用的参数，这样做避免警告。
	sda      =sda;          //无用的参数，这样做避免警告。
	iic_master_init();      //初始化硬件IIC。
}
/*-------------------------------------------------------
OLED设置引脚函数，用于软件SPI模式。
-------------------------------------------------------*/
void oled_set_soft_spi(oled_def * dev,u8 scl,u8 sda,u8 dc,u8 rst,u8 cs){
	if(cs!=Dxx){                                              //如果CS脚指定了，
		dev->mode=OLED_SOFT_SPI|OLED_CS_ENABLE;               //那么设置模式为软件SPI+CS，
		
	}else{                                                    //否则
		dev->mode=OLED_SOFT_SPI;                              //只设置模式为软件SPI。
	}
	dev->id      =soft_spi_init_linkage(scl,sda,Dxx,Dxx,0x95);//初始化软件SPI
	dev->scl_pin =scl;           //保存时钟脚设置。
	dev->sda_pin =sda;           //保存数据脚设置。
	dev->rst_pin =rst;           //保存复位脚设置。
	dev->cs_pin  =cs;            //保存片选脚设置。
	dev->dc_port =io2port(dc);   //解析DC脚的P口。
	dev->dc_pin  =io2pin (dc);   //解析DC脚的IO口。
	gpio_mode     (dc,GPIO_OUT); //DC脚设置为推挽。
	gpio_out      (dc,1);        //默认高电平。
	gpio_mode     (rst,GPIO_OUT);//复位脚设置为推挽。
	gpio_out      (rst,1);       //默认为高电平。
	gpio_mode     (cs,GPIO_OUT);   //片选脚设置为推挽。
	gpio_out      (cs,1);          //默认为高电平。
}	
/*-------------------------------------------------------
OLED设置引脚函数，用于硬件SPI模式。
-------------------------------------------------------*/
void oled_set_hard_spi(oled_def * dev,u8 scl,u8 sda,u8 dc,u8 rst,u8 cs){
	if(cs!=Dxx){                                //如果CS脚指定了，
		dev->mode=OLED_HARD_SPI|OLED_CS_ENABLE; //那么设置模式为硬件SPI+CS，
	}else{                                      //否则
		dev->mode=OLED_HARD_SPI;                //只设置模式为硬件SPI。
	}
	scl=scl;                       //无用的参数，这样做避免警告。
	sda=sda;                       //无用的参数，这样做避免警告。
	dev->id      =0;               //先这样设置着...
	dev->rst_pin =rst;             //保存复位脚设置。
	dev->cs_pin  =cs;              //保存片选脚设置。
	dev->dc_port =io2port(dc);     //解析DC脚的P口。
	dev->dc_pin  =io2pin (dc);     //解析DC脚的IO口。
	gpio_mode     (dc,GPIO_OUT);   //DC脚设置为推挽。
	gpio_out      (dc,1);          //默认高电平。
	gpio_mode     (rst,GPIO_OUT);  //复位脚设置为推挽。
	gpio_out      (rst,1);         //默认高电平。
	gpio_mode     (cs,GPIO_OUT);   //片选脚设置为推挽。
	gpio_out      (cs,1);          //默认为高电平。
	spi_init();                    //初始化硬件SPI。
}
/*-------------------------------------------------------
OLED的写函数，用于硬件SPI模式。
-------------------------------------------------------*/
void oled_write_hard_spi(oled_def * dev,u8 cd,u8 buf){
	if(cd==oled_dat)
		gpio_out_fast(dev->dc_port,dev->dc_pin,1);
	else
		gpio_out_fast(dev->dc_port,dev->dc_pin,0);
	spi_send(buf);
}
/*-------------------------------------------------------
OLED的写函数，用于软件SPI模式。
-------------------------------------------------------*/
void oled_write_soft_spi(oled_def * dev,u8 cd,u8 buf){
	if(cd==oled_dat)
		gpio_out_fast(dev->dc_port,dev->dc_pin,1);
	else
		gpio_out_fast(dev->dc_port,dev->dc_pin,0);
	soft_spi_send(buf);
}
/*-------------------------------------------------------
OLED的写函数，用于硬件IIC模式。
-------------------------------------------------------*/
void oled_write_hard_iic(oled_def * dev,u8 cd,u8 buf){
	dev=dev;
	iic_start   ();
	iic_write   (0x78);
	iic_read_ack();
	iic_write   (cd);
	iic_read_ack();
	iic_write   (buf);
	iic_read_ack();
	iic_stop    ();
}
/*-------------------------------------------------------
OLED的写函数，用于软件IIC模式。
-------------------------------------------------------*/
void oled_write_soft_iic(oled_def * dev,u8 cd,u8 buf){
	dev=dev;
	soft_iic_start   ();
	soft_iic_write   (0x78);
	soft_iic_read_ack();
	soft_iic_write   (cd);
	soft_iic_read_ack();
	soft_iic_write   (buf);
	soft_iic_read_ack();
	soft_iic_stop    ();
}
/*-------------------------------------------------------
OLED的写函数，通用。
-------------------------------------------------------*/
void oled_write(oled_def * dev,u8 cd,u8 buf){
	if((dev->mode&OLED_SERIAL_IIC_SPI_MASK)==0){//spi
		if((dev->mode)&OLED_CS_EN_MASK){
			gpio_out(dev->cs_pin,0);
		}
		if(dev->mode&OLED_HARD_SOFT_WARE_MASK){ //hard
			oled_write_hard_spi(dev,cd,buf);
		}else{                                  //soft
			oled_write_soft_spi(dev,cd,buf);
		}
		if((dev->mode)&OLED_CS_EN_MASK){
			gpio_out(dev->cs_pin,1);
		}
	}else{                                      //iic
		if(dev->mode&OLED_HARD_SOFT_WARE_MASK){ //hard
			oled_write_hard_iic(dev,cd,buf);
		}else{                                  //soft
			oled_write_soft_iic(dev,cd,buf);
		}
	}
}
/*-------------------------------------------------------
开启OLED函数。
-------------------------------------------------------*/
void oled_on(oled_def * dev){
	oled_write(dev,oled_cmd,0xaf);
}
/*-------------------------------------------------------
关闭OLED函数。
-------------------------------------------------------*/
void oled_off(oled_def * dev){
	oled_write(dev,oled_cmd,0xae);
}
/*-------------------------------------------------------
OLED设置COM引脚数函数。
-------------------------------------------------------*/
void oled_set_com(oled_def * dev,u8 num){
	oled_write(dev,oled_cmd,0xa8);
	oled_write(dev,oled_cmd,num);
}
/*-------------------------------------------------------
OLED设置对比度函数。
-------------------------------------------------------*/
void oled_set_contrast(oled_def * dev,u8 val){
	oled_write(dev,oled_cmd,0x81);
	oled_write(dev,oled_cmd,val); 
}
/*-------------------------------------------------------
OLED设置数据指针函数。
-------------------------------------------------------*/
void oled_set_pos(oled_def * dev,u8 x,u8 y){
	oled_write(dev,oled_cmd,0xb0+y);
	oled_write(dev,oled_cmd,((x&0xf0)>>4)|0x10);
	oled_write(dev,oled_cmd,x&0x0f);
}
/*-------------------------------------------------------
OLED设置逻辑引脚偏移函数。
-------------------------------------------------------*/
void oled_set_offset_logic(oled_def * dev,u8 offset){//设置逻辑引脚相对于硬件引脚的偏移
	oled_write(dev,oled_cmd,0xd3);
	oled_write(dev,oled_cmd,offset);
}
/*-------------------------------------------------------
OLED设置RAM偏移函数。
-------------------------------------------------------*/
void oled_set_offset_ram(oled_def * dev,u8 offset){//设置RAM相对逻辑引脚的偏移
	oled_write(dev,oled_cmd,0x40|offset);
}
/*-------------------------------------------------------
OLED全显函数。
-------------------------------------------------------*/
void oled_fill(oled_def * dev,u8 dat){//刷满SSD1306的RAM，即128*8字节
	unsigned char y,x;
	if((dev->mode&OLED_SERIAL_IIC_SPI_MASK)==0){//spi
		if((dev->mode)&OLED_CS_EN_MASK){
			gpio_out(dev->cs_pin,0);
		}
		if(dev->mode&OLED_HARD_SOFT_WARE_MASK){//hard
			for(y=0;y<8;y++){
				gpio_out_fast(dev->dc_port,dev->dc_pin,0);
				spi_send(0xb0+y);
				spi_send(0x00);
				spi_send(0x10);
				gpio_out_fast(dev->dc_port,dev->dc_pin,1);
				for(x=0;x<128;x++){
					spi_send(dat);
				}	
			}
		}else{//soft
			soft_spi_set_pin_linkage(dev->id,dev->scl_pin,dev->sda_pin,Dxx,Dxx,0x95);
			for(y=0;y<8;y++){
				gpio_out_fast(dev->dc_port,dev->dc_pin,0);
				soft_spi_send(0xb0+y);
				soft_spi_send(0x00);
				soft_spi_send(0x10);
				gpio_out_fast(dev->dc_port,dev->dc_pin,1);
				for(x=0;x<128;x++){
					soft_spi_send(dat);
				}	
			}
			
		}
		if((dev->mode)&OLED_CS_EN_MASK){
			gpio_out(dev->cs_pin,1);
		}
	}else{//iic
		if(dev->mode&OLED_HARD_SOFT_WARE_MASK){//hard
			for(y=0;y<8;y++){
				oled_write_hard_iic(dev,oled_cmd,0xb0+y);
				oled_write_hard_iic(dev,oled_cmd,0x00);
				oled_write_hard_iic(dev,oled_cmd,0x10);
				for(x=0;x<128;x++){
					oled_write_hard_iic(dev,oled_dat,dat);
				}	
			}
		}else{//soft
			for(y=0;y<8;y++){
				oled_write_soft_iic(dev,oled_cmd,0xb0+y);
				oled_write_soft_iic(dev,oled_cmd,0x00);
				oled_write_soft_iic(dev,oled_cmd,0x10);
				for(x=0;x<128;x++){
					oled_write_soft_iic(dev,oled_dat,dat);
				}
			}
		}
	}
}
/*-------------------------------------------------------
OLED显示函数。
-------------------------------------------------------*/
void oled_show(oled_def * dev,u8 dat[]){
	unsigned char x,y,xmax,ymax,x1,x2;
	u16 c=0;
	ymax=dev->h/8;
	xmax=dev->w;
	x1=((dev->x&0xf0)>>4)|0x10;
	x2=dev->x&0x0f;
	
	if((dev->mode&OLED_SERIAL_IIC_SPI_MASK)==0){//spi
		if((dev->mode)&OLED_CS_EN_MASK){
			gpio_out(dev->cs_pin,0);
		}
		if(dev->mode&OLED_HARD_SOFT_WARE_MASK){//hard
			for(y=0;y<8;y++){
				gpio_out_fast(dev->dc_port,dev->dc_pin,0);
				spi_send(0xb0+y);
				spi_send(x1);
				spi_send(x2);
				gpio_out_fast(dev->dc_port,dev->dc_pin,1);
				for(x=0;x<128;x++){
					spi_send(dat[c++]);
				}	
			}
		}else{//soft
			soft_spi_set_pin_linkage(dev->id,dev->scl_pin,dev->sda_pin,Dxx,Dxx,0x95);
			for(y=0;y<8;y++){
				gpio_out_fast(dev->dc_port,dev->dc_pin,0);
				soft_spi_send(0xb0+y);
				soft_spi_send(x1);
				soft_spi_send(x2);
				gpio_out_fast(dev->dc_port,dev->dc_pin,1);
				for(x=0;x<128;x++){
					soft_spi_send(dat[c++]);
				}	
			}
		}
		if((dev->mode)&OLED_CS_EN_MASK){
			gpio_out(dev->cs_pin,1);
		}
	}else{//iic
		if(dev->mode&OLED_HARD_SOFT_WARE_MASK){//hard
			for(y=0;y<8;y++){
				oled_write_hard_iic(dev,oled_cmd,0xb0+y);
				oled_write_hard_iic(dev,oled_cmd,x1);
				oled_write_hard_iic(dev,oled_cmd,x2);
				for(x=0;x<128;x++){
					oled_write_hard_iic(dev,oled_dat,dat[c++]);
				}	
			}
		}else{//soft
			for(y=0;y<8;y++){
				oled_write_soft_iic(dev,oled_cmd,0xb0+y);
				oled_write_soft_iic(dev,oled_cmd,x1);
				oled_write_soft_iic(dev,oled_cmd,x2);
				for(x=0;x<128;x++){
					oled_write_soft_iic(dev,oled_dat,dat[c++]);
				}
			}
		}
	}
}
/*-------------------------------------------------------
OLED显示模式设置函数。
-------------------------------------------------------*/
void oled_set_display_mode(oled_def * dev,u8 mode){
	if(mode&0x01){
		oled_write(dev,oled_cmd,0xa0);//--Set SEG/Column Mapping     0xa0左右反置 0xa1正常
	}else{
		oled_write(dev,oled_cmd,0xa1);//--Set SEG/Column Mapping     0xa0左右反置 0xa1正常
	}
	if(mode&0x02){
		oled_write(dev,oled_cmd,0xc0);//Set COM/Row Scan Direction   0xc0上下反置 0xc8正常	
		
	}else{
		oled_write(dev,oled_cmd,0xc8);//Set COM/Row Scan Direction   0xc0上下反置 0xc8正常	
	}
	oled_write(dev,oled_cmd,0xda);//--set com pins hardware configuration
	oled_write(dev,oled_cmd,0x02|((mode&0x0C)<<2));
}
/*-------------------------------------------------------
OLED设置函数。
-------------------------------------------------------*/
void oled_set_display(oled_def * dev,u8 cmd){
	oled_write(dev,oled_cmd,cmd);
}
/*-------------------------------------------------------
OLED设置Vcomh电压函数。
-------------------------------------------------------*/
void oled_set_vcomh(oled_def * dev,u8 v){
	oled_write(dev,oled_cmd,0xdb);//--set vcomh
	oled_write(dev,oled_cmd,v);//Set VCOM Deselect Level
}
/*-------------------------------------------------------
OLED设置DC-DC电路函数。
-------------------------------------------------------*/
void oled_set_dcdc(oled_def * dev,u8 en){
	oled_write(dev,oled_cmd,0x8d);//--set Charge Pump enable/disable
	oled_write(dev,oled_cmd,0x10|(en<<2));//--set(0x10) disable
}
/*-------------------------------------------------------
OLED设置扫频时序函数。
-------------------------------------------------------*/
void oled_set_pcc(oled_def * dev,u8 clk){
	oled_write(dev,oled_cmd,0xd9);//--set pre-charge period
	oled_write(dev,oled_cmd,clk);//Set Pre-Charge as 15 Clocks & Discharge as 1 Clock
}
/*-------------------------------------------------------
OLED设置地址模式函数。
-------------------------------------------------------*/
void oled_set_address_mode(oled_def * dev,u8 mode){
	oled_write(dev,oled_cmd,0x20);//-Set Page Addressing Mode (0x00/0x01/0x02)
	oled_write(dev,oled_cmd,mode);//
}
/*-------------------------------------------------------
OLED设置内置RC参数函数。
-------------------------------------------------------*/
void oled_set_clk(oled_def * dev,u8 clk){
	oled_write(dev,oled_cmd,0xd5);
	oled_write(dev,oled_cmd,clk);
}
/*-------------------------------------------------------
OLED初始化函数。
-------------------------------------------------------*/
void oled_init(oled_def * dev,u8 w,u8 h,u8 xoffset,u8 yoffset,u8 mode){  
	dev->w=w;
	dev->h=h;
	dev->x=xoffset;
	dev->y=yoffset;
	if((dev->mode)&OLED_CS_EN_MASK){
		gpio_out(dev->cs_pin,0);
	}
	if((dev->mode&OLED_SERIAL_IIC_SPI_MASK)==0){
		gpio_out(dev->rst_pin,0);
		delay_ms(50);
		gpio_out(dev->rst_pin,1);
	}
	oled_off             (dev);
	oled_set_com         (dev,h-1);
	oled_set_contrast    (dev,OLED_CONTRAST);
	oled_set_offset_logic(dev,yoffset);
	oled_set_offset_ram  (dev,OLED_OFFSET_RAM);
	oled_set_display_mode(dev,mode);
	oled_set_display     (dev,OLED_DISPLAY_SOURCE);
	oled_set_display     (dev,OLED_DISPLAY_LED);
	oled_set_clk         (dev,OLED_SYSCLK);
	oled_set_pcc         (dev,OLED_PCC);//--set pre-charge period//Set Pre-Charge as 15 Clocks & Discharge as 1 Clock
	oled_set_vcomh       (dev,OLED_VCOMH);
	oled_set_address_mode(dev,OLED_ADRESS);
	oled_set_dcdc        (dev,OLED_DC_DC);
	oled_fill            (dev,0);  //初始清屏
	oled_on              (dev);
	oled_set_pos         (dev,0,0); 	
	if((dev->mode)&OLED_CS_EN_MASK){
		gpio_out(dev->cs_pin,1);
	}
} 
/*-------------------------------------------------------
OLED自动初始化函数
-------------------------------------------------------*/
void oled_auto_init(oled_def * dev,char * str){
	u16 pos;
	u8 scl=Dxx,sda=Dxx,dc=Dxx,rst=Dxx,cs=Dxx,vcc=Dxx,gnd=Dxx;
	u8 w,h,x,y,mode;
	pos=str_find(str,"vcc=");
	if(pos!=0xffff){
		vcc=str_read_pin(str,pos);
		gpio_mode(vcc,GPIO_PP);
		gpio_out(vcc,1);
	}
	pos=str_find(str,"vdd=");
	if(pos!=0xffff){
		vcc=str_read_pin(str,pos);
		gpio_mode(vcc,GPIO_PP);
		gpio_out(vcc,1);
	}
	pos=str_find(str,"gnd=");
	if(pos!=0xffff){
		gnd=str_read_pin(str,pos);
		gpio_mode(gnd,GPIO_PP);
		gpio_out(gnd,0);
	}	
	pos=str_find(str,"w=");
	if(pos!=0xffff){
		w=(u8)str_read_u16(str,pos);
	}else{
		w=OLED_X_MAX;
	}
	pos=str_find(str,"h=");
	if(pos!=0xffff){
		h=(u8)str_read_u16(str,pos);
	}else{
		h=OLED_Y_MAX;
	}
	pos=str_find(str,"x=");
	if(pos!=0xffff){
		x=(u8)str_read_u16(str,pos);
	}else{
		x=OLED_OFFSET_XPIN;
	}
	pos=str_find(str,"y=");
	if(pos!=0xffff){
		y=(u8)str_read_u16(str,pos);
	}else{
		y=OLED_OFFSET_LOGIC;
	}
	pos=str_find(str,"mode=");
	if(pos!=0xffff){
		mode=(u8)str_read_u16(str,pos);
	}else{
		mode=OLED_DISPLAY_MODE;
	}
	pos=str_find(str,"scl=");
	if(pos!=0xffff){
		scl=str_read_pin(str,pos);
	}
	pos=str_find(str,"d0=");
	if(pos!=0xffff){
		scl=str_read_pin(str,pos+2);
	}
	pos=str_find(str,"sda=");
	if(pos!=0xffff){
		sda=str_read_pin(str,pos);
	}
	pos=str_find(str,"d1=");
	if(pos!=0xffff){
		sda=str_read_pin(str,pos+2);
	}
	pos=str_find(str,"dc=");
	if(pos!=0xffff){
		dc=str_read_pin(str,pos);
	}
	pos=str_find(str,"rst=");
	if(pos!=0xffff){
		rst=str_read_pin(str,pos);
	}
	pos=str_find(str,"res=");
	if(pos!=0xffff){
		rst=str_read_pin(str,pos);
	}
	pos=str_find(str,"cs=");
	if(pos!=0xffff){
		cs=str_read_pin(str,pos);
	}
	if(str_find(str,"soft")!=0xffff){
		if(str_find(str,"iic")!=0xffff){
			goto soft_iic_id;
		}
		if(str_find(str,"spi")!=0xffff){
			goto soft_spi_id;
		}
	}
	if((dc==Dxx)&&(rst==Dxx)){
		if((scl==0x15)&&(sda==0x14)){
			oled_set_hard_iic(dev,scl,sda);
			iic_set_pin(IIC_PIN_P1);
		}else if((scl==0x25)&&(sda==0x24)){
			oled_set_hard_iic(dev,scl,sda);
			iic_set_pin(IIC_PIN_P2);
		}else if((scl==0x77)&&(sda==0x76)){
			oled_set_hard_iic(dev,scl,sda);
			iic_set_pin(IIC_PIN_P7);
		}else if((scl==0x32)&&(sda==0x33)){
			oled_set_hard_iic(dev,scl,sda);
			iic_set_pin(IIC_PIN_P3);
		}else{
			soft_iic_id:
			oled_set_soft_iic(dev,scl,sda);
		}
	}else{
		if((scl==0x15)&&(sda==0x13)){
			oled_set_hard_spi(dev,scl,sda,dc,rst,cs);
			spi_set_pin(SPI_PIN_P1);
		}else if((scl==0x25)&&(sda==0x23)){
			oled_set_hard_spi(dev,scl,sda,dc,rst,cs);
			spi_set_pin(SPI_PIN_P2);
		}else if((scl==0x77)&&(sda==0x75)){
			oled_set_hard_spi(dev,scl,sda,dc,rst,cs);
			spi_set_pin(SPI_PIN_P7);
		}else if((scl==0x32)&&(sda==0x34)){
			oled_set_hard_spi(dev,scl,sda,dc,rst,cs);
			spi_set_pin(SPI_PIN_P3);
		}else{
			soft_spi_id:
			oled_set_soft_spi(dev,scl,sda,dc,rst,cs);
			
		}
	}
	oled_init(dev,w,h,x,y,mode);
	
}
#if OLED_DISPLAY_MODE_EN
u8 code oled_display_mode_test_buf[]={
0x00,0x3E,0x41,0x41,0x41,0x3E,0x00,0x00,/*"0"*/0xFF,0xFE,0xFC,0xF8,0xF0,0xE0,0xC0,0x80,
0x00,0x00,0x02,0x7F,0x00,0x00,0x00,0x00,/*"1"*/0xFF,0xFE,0xFC,0xF8,0xF0,0xE0,0xC0,0x80,
0x00,0x62,0x51,0x49,0x46,0x00,0x00,0x00,/*"2"*/0xFF,0xFE,0xFC,0xF8,0xF0,0xE0,0xC0,0x80,
0x00,0x00,0x41,0x49,0x49,0x36,0x00,0x00,/*"3"*/0xFF,0xFE,0xFC,0xF8,0xF0,0xE0,0xC0,0x80,
0x00,0x30,0x2C,0x22,0x7F,0x20,0x00,0x00,/*"4"*/0xFF,0xFE,0xFC,0xF8,0xF0,0xE0,0xC0,0x80,
0x00,0x00,0x4F,0x49,0x49,0x31,0x00,0x00,/*"5"*/0xFF,0xFE,0xFC,0xF8,0xF0,0xE0,0xC0,0x80,
0x00,0x3C,0x46,0x45,0x45,0x39,0x00,0x00,/*"6"*/0xFF,0xFE,0xFC,0xF8,0xF0,0xE0,0xC0,0x80,
0x00,0x01,0x61,0x1D,0x03,0x00,0x00,0x00,/*"7"*/0xFF,0xFE,0xFC,0xF8,0xF0,0xE0,0xC0,0x80,
0x00,0x36,0x49,0x49,0x49,0x36,0x00,0x00,/*"8"*/0xFF,0xFE,0xFC,0xF8,0xF0,0xE0,0xC0,0x80,
0x00,0x4E,0x51,0x51,0x71,0x1E,0x00,0x00,/*"9"*/0xFF,0xFE,0xFC,0xF8,0xF0,0xE0,0xC0,0x80,
0x00,0x60,0x1C,0x13,0x17,0x38,0x40,0x00,/*"A"*/0xFF,0xFE,0xFC,0xF8,0xF0,0xE0,0xC0,0x80,
0x00,0x00,0x7F,0x49,0x49,0x37,0x00,0x00,/*"B"*/0xFF,0xFE,0xFC,0xF8,0xF0,0xE0,0xC0,0x80,
0x00,0x3C,0x62,0x41,0x41,0x41,0x00,0x00,/*"C"*/0xFF,0xFE,0xFC,0xF8,0xF0,0xE0,0xC0,0x80,
0x00,0x00,0x7F,0x41,0x41,0x63,0x1E,0x00,/*"D"*/0xFF,0xFE,0xFC,0xF8,0xF0,0xE0,0xC0,0x80,
0x00,0x00,0x7F,0x49,0x49,0x49,0x00,0x00,/*"E"*/0xFF,0xFE,0xFC,0xF8,0xF0,0xE0,0xC0,0x80,
0x00,0x00,0x7F,0x09,0x09,0x00,0x00,0x00,/*"F"*/0xFF,0xFE,0xFC,0xF8,0xF0,0xE0,0xC0,0x80,
/* (8 X 8 , Segoe UI Symbol )*/
};
u8 code x_start[]={0xFF,0x24,0x42,0x81};
/*-------------------------------------------------------
OLED显示模式测试函数。
-------------------------------------------------------*/
void oled_display_mode_test(oled_def * dev,u8 mode){
	u8 x=0,y=0;
	oled_set_display_mode(dev,mode);
	for(y=0;y<8;y++){        //在测试阶段，直接写满8个page
		oled_set_pos(dev,x,y);
		for(x=0;x<128;x++){  //在测试阶段，直接写满128像素
			oled_write(dev,oled_dat,oled_display_mode_test_buf[x%16+mode*16]);
		}
	}
}
/*-------------------------------------------------------
OLED的Y轴偏移测试函数。
-------------------------------------------------------*/
void oled_display_y_test(oled_def * dev){
	u8 x=0,y=0;
	for(y=0;y<8;y++){        //在测试阶段，直接写满8个page
		oled_set_pos(dev,x,y);
		for(x=0;x<128;x++){  //在测试阶段，直接写满128像素
			oled_write(dev,oled_dat,oled_display_mode_test_buf[x%8+y*16]);
		}
	}
}
/*-------------------------------------------------------
OLED的X轴偏移测试函数。
-------------------------------------------------------*/
void oled_display_x_test(oled_def * dev,u8 x_offset){
	u8 x=0,y=0;
	oled_fill(dev,0);
	for(y=0;y<8;y++){        //在测试阶段，直接写满8个page
		oled_set_pos(dev,x_offset,y);
		for(x=0;x<4;x++){  //在测试阶段，直接写满128像素
			oled_write(dev,oled_dat,x_start[x]);
		}
		for(x=0;x<6;x++){  //在测试阶段，直接写满128像素
			oled_write(dev,oled_dat,oled_display_mode_test_buf[(x_offset/100)*16+x]);
		}
		for(x=0;x<6;x++){  //在测试阶段，直接写满128像素
			oled_write(dev,oled_dat,oled_display_mode_test_buf[(x_offset%100/10)*16+x]);
		}
		for(x=0;x<6;x++){  //在测试阶段，直接写满128像素
			oled_write(dev,oled_dat,oled_display_mode_test_buf[(x_offset%10)*16+x]);
		}
	}
}
#endif
#if OLED_PRINTF_EN
unsigned char code F6x8[]={
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,// sp
0x00, 0x00, 0x00, 0x2f, 0x00, 0x00,// !
0x00, 0x00, 0x07, 0x00, 0x07, 0x00,// "
0x00, 0x14, 0x7f, 0x14, 0x7f, 0x14,// #
0x00, 0x24, 0x2a, 0x7f, 0x2a, 0x12,// $
0x00, 0x23, 0x13, 0x08, 0x64, 0x62,//0x00, 0x62, 0x64, 0x08, 0x13, 0x23,// %
0x00, 0x36, 0x49, 0x55, 0x22, 0x50,// &
0x00, 0x00, 0x05, 0x03, 0x00, 0x00,// '
0x00, 0x00, 0x1c, 0x22, 0x41, 0x00,// (
0x00, 0x00, 0x41, 0x22, 0x1c, 0x00,// )
0x00, 0x14, 0x08, 0x3E, 0x08, 0x14,// *
0x00, 0x08, 0x08, 0x3E, 0x08, 0x08,// +
0x00, 0x00, 0x00, 0xA0, 0x60, 0x00,// ,
0x00, 0x08, 0x08, 0x08, 0x08, 0x08,// -
0x00, 0x00, 0x60, 0x60, 0x00, 0x00,// .
0x00, 0x20, 0x10, 0x08, 0x04, 0x02,// /
0x00, 0x3E, 0x51, 0x49, 0x45, 0x3E,// 0
0x00, 0x00, 0x42, 0x7F, 0x40, 0x00,// 1
0x00, 0x42, 0x61, 0x51, 0x49, 0x46,// 2
0x00, 0x21, 0x41, 0x45, 0x4B, 0x31,// 3
0x00, 0x18, 0x14, 0x12, 0x7F, 0x10,// 4
0x00, 0x27, 0x45, 0x45, 0x45, 0x39,// 5
0x00, 0x3C, 0x4A, 0x49, 0x49, 0x30,// 6
0x00, 0x01, 0x71, 0x09, 0x05, 0x03,// 7
0x00, 0x36, 0x49, 0x49, 0x49, 0x36,// 8
0x00, 0x06, 0x49, 0x49, 0x29, 0x1E,// 9
0x00, 0x00, 0x36, 0x36, 0x00, 0x00,// :
0x00, 0x00, 0x56, 0x36, 0x00, 0x00,// ;
0x00, 0x08, 0x14, 0x22, 0x41, 0x00,// <
0x00, 0x14, 0x14, 0x14, 0x14, 0x14,// =
0x00, 0x00, 0x41, 0x22, 0x14, 0x08,// >
0x00, 0x02, 0x01, 0x51, 0x09, 0x06,// ?
0x00, 0x32, 0x49, 0x59, 0x51, 0x3E,// @
0x00, 0x7C, 0x12, 0x11, 0x12, 0x7C,// A
0x00, 0x7F, 0x49, 0x49, 0x49, 0x36,// B
0x00, 0x3E, 0x41, 0x41, 0x41, 0x22,// C
0x00, 0x7F, 0x41, 0x41, 0x22, 0x1C,// D
0x00, 0x7F, 0x49, 0x49, 0x49, 0x41,// E
0x00, 0x7F, 0x09, 0x09, 0x09, 0x01,// F
0x00, 0x3E, 0x41, 0x49, 0x49, 0x7A,// G
0x00, 0x7F, 0x08, 0x08, 0x08, 0x7F,// H
0x00, 0x00, 0x41, 0x7F, 0x41, 0x00,// I
0x00, 0x20, 0x40, 0x41, 0x3F, 0x01,// J
0x00, 0x7F, 0x08, 0x14, 0x22, 0x41,// K
0x00, 0x7F, 0x40, 0x40, 0x40, 0x40,// L
0x00, 0x7F, 0x02, 0x0C, 0x02, 0x7F,// M
0x00, 0x7F, 0x04, 0x08, 0x10, 0x7F,// N
0x00, 0x3E, 0x41, 0x41, 0x41, 0x3E,// O
0x00, 0x7F, 0x09, 0x09, 0x09, 0x06,// P
0x00, 0x3E, 0x41, 0x51, 0x21, 0x5E,// Q
0x00, 0x7F, 0x09, 0x19, 0x29, 0x46,// R
0x00, 0x46, 0x49, 0x49, 0x49, 0x31,// S
0x00, 0x01, 0x01, 0x7F, 0x01, 0x01,// T
0x00, 0x3F, 0x40, 0x40, 0x40, 0x3F,// U
0x00, 0x1F, 0x20, 0x40, 0x20, 0x1F,// V
0x00, 0x3F, 0x40, 0x38, 0x40, 0x3F,// W
0x00, 0x63, 0x14, 0x08, 0x14, 0x63,// X
0x00, 0x07, 0x08, 0x70, 0x08, 0x07,// Y
0x00, 0x61, 0x51, 0x49, 0x45, 0x43,// Z
0x00, 0x00, 0x7F, 0x41, 0x41, 0x00,// [
0x00, 0x55, 0x2A, 0x55, 0x2A, 0x55,// 55
0x00, 0x00, 0x41, 0x41, 0x7F, 0x00,// ]
0x00, 0x04, 0x02, 0x01, 0x02, 0x04,// ^
0x00, 0x40, 0x40, 0x40, 0x40, 0x40,// _
0x00, 0x00, 0x01, 0x02, 0x04, 0x00,// '
0x00, 0x20, 0x54, 0x54, 0x54, 0x78,// a
0x00, 0x7F, 0x48, 0x44, 0x44, 0x38,// b
0x00, 0x38, 0x44, 0x44, 0x44, 0x20,// c
0x00, 0x38, 0x44, 0x44, 0x48, 0x7F,// d
0x00, 0x38, 0x54, 0x54, 0x54, 0x18,// e
0x00, 0x08, 0x7E, 0x09, 0x01, 0x02,// f
0x00, 0x18, 0xA4, 0xA4, 0xA4, 0x7C,// g
0x00, 0x7F, 0x08, 0x04, 0x04, 0x78,// h
0x00, 0x00, 0x44, 0x7D, 0x40, 0x00,// i
0x00, 0x40, 0x80, 0x84, 0x7D, 0x00,// j
0x00, 0x7F, 0x10, 0x28, 0x44, 0x00,// k
0x00, 0x00, 0x41, 0x7F, 0x40, 0x00,// l
0x00, 0x7C, 0x04, 0x18, 0x04, 0x78,// m
0x00, 0x7C, 0x08, 0x04, 0x04, 0x78,// n
0x00, 0x38, 0x44, 0x44, 0x44, 0x38,// o
0x00, 0xFC, 0x24, 0x24, 0x24, 0x18,// p
0x00, 0x18, 0x24, 0x24, 0x18, 0xFC,// q
0x00, 0x7C, 0x08, 0x04, 0x04, 0x08,// r
0x00, 0x48, 0x54, 0x54, 0x54, 0x20,// s
0x00, 0x04, 0x3F, 0x44, 0x40, 0x20,// t
0x00, 0x3C, 0x40, 0x40, 0x20, 0x7C,// u
0x00, 0x1C, 0x20, 0x40, 0x20, 0x1C,// v
0x00, 0x3C, 0x40, 0x30, 0x40, 0x3C,// w
0x00, 0x44, 0x28, 0x10, 0x28, 0x44,// x
0x00, 0x1C, 0xA0, 0xA0, 0xA0, 0x7C,// y
0x00, 0x44, 0x64, 0x54, 0x4C, 0x44,// z
0x14, 0x14, 0x14, 0x14, 0x14, 0x14,// horiz lines
};
#include "stdio.h"
/*-------------------------------------------------------
显示一个字符函数，用于裸屏显示。
-------------------------------------------------------*/
void oled_char(oled_def * dev,u8 x,u8 y,char ch){
	u8 i,c;
	c=ch-' ';
	oled_set_pos(dev,x,y);
	for(i=0;i<6;i++){
		oled_write(dev,oled_dat,F6x8[c*6+i]);
	}
}
/*-------------------------------------------------------
格式化显示字符串函数，用于裸屏显示。
-------------------------------------------------------*/
void oled_printf(oled_def * dev,u8 x,u8 y,char * str,...){
	char xdata buf[64];
	u8 len,i,x0,y0;
	va_list vp;
    va_start(vp, str);
    len=vsprintf(buf,str,vp);
    va_end(vp);
	x0=x+dev->x;
	y0=y;
	for(i=0;i<len;i++){
		
		if(buf[i]=='\r'){
			x0=dev->x;
			continue;
		}
		if(buf[i]=='\n'){
			y0++;
			continue;
		}
		
		if(x0>(OLED_X_MAX-6)){
			x0=dev->x;
			y0++;
		}
		if(y0>=OLED_PAGE_MAX){
			break;
		}
		oled_char(dev,x0,y0,buf[i]);
		x0+=6;
	}
}
#endif
#if OLED_INFORMATION_EN 
/*-------------------------------------------------------
显示当前的OLED的各种信息。
-------------------------------------------------------*/
void oled_information(oled_def * dev){
	oled_printf(dev,16,0,"OLED Information");
	oled_printf(dev, 0,2,"Pixel   :%d X %d",(u16)OLED_X_MAX,(u16)OLED_Y_MAX);
	oled_printf(dev, 0,3,"Contrast:%d",     (u16)OLED_CONTRAST);
	oled_printf(dev, 0,4,"Offset  :%d(%d)", (u16)OLED_OFFSET_LOGIC,(u16)OLED_OFFSET_RAM);
	oled_printf(dev, 0,5,"Mode    :%d",     (u16)OLED_DISPLAY_MODE);
	#if OLED_DC_DC
		oled_printf(dev,0,6,"Vcomh   :%0.2fV",(0.65f+(float)(OLED_VCOMH>>4)*0.06f)*7.5);
	#else 
		oled_printf(dev,0,6,"Vcomh   :%0.2f*VCC",(0.65f+(float)(OLED_VCOMH>>4)*0.06f));
	#endif
	oled_printf(dev,0,7,"Rate    :%ld FPS",((u32)((OLED_SYSCLK&0xf0)>>4)*4625+333000)/((OLED_SYSCLK&0x0f)+1)/(OLED_Y_MAX)/(50+(OLED_PCC&0xf0>>4)+(OLED_PCC&0x0f)));
}
#endif