#include "oled.h"
/*-------------------------------------------------------
OLED�������ź������������IICģʽ��
-------------------------------------------------------*/
void oled_set_soft_iic(oled_def * dev,u8 scl,u8 sda){
	dev->mode=OLED_SOFT_IIC;                  //����ģʽΪ���IIC��
	dev->id  =soft_iic_init_linkage(scl,sda); //��������������ʼ�����IIC��
	dev->scl_pin =scl;                        //����ʱ�ӽ����á�
	dev->sda_pin =sda;                        //�������ݽ����á�
}
/*-------------------------------------------------------
OLED�������ź���������Ӳ��IICģʽ��
-------------------------------------------------------*/
void oled_set_hard_iic(oled_def * dev,u8 scl,u8 sda){
	dev->mode=OLED_HARD_IIC;//����ģʽΪӲ��IIC��
	dev->id  =0;            //������������...
	scl      =scl;          //���õĲ��������������⾯�档
	sda      =sda;          //���õĲ��������������⾯�档
	iic_master_init();      //��ʼ��Ӳ��IIC��
}
/*-------------------------------------------------------
OLED�������ź������������SPIģʽ��
-------------------------------------------------------*/
void oled_set_soft_spi(oled_def * dev,u8 scl,u8 sda,u8 dc,u8 rst,u8 cs){
	if(cs!=Dxx){                                              //���CS��ָ���ˣ�
		dev->mode=OLED_SOFT_SPI|OLED_CS_ENABLE;               //��ô����ģʽΪ���SPI+CS��
		
	}else{                                                    //����
		dev->mode=OLED_SOFT_SPI;                              //ֻ����ģʽΪ���SPI��
	}
	dev->id      =soft_spi_init_linkage(scl,sda,Dxx,Dxx,0x95);//��ʼ�����SPI
	dev->scl_pin =scl;           //����ʱ�ӽ����á�
	dev->sda_pin =sda;           //�������ݽ����á�
	dev->rst_pin =rst;           //���渴λ�����á�
	dev->cs_pin  =cs;            //����Ƭѡ�����á�
	dev->dc_port =io2port(dc);   //����DC�ŵ�P�ڡ�
	dev->dc_pin  =io2pin (dc);   //����DC�ŵ�IO�ڡ�
	gpio_mode     (dc,GPIO_OUT); //DC������Ϊ���졣
	gpio_out      (dc,1);        //Ĭ�ϸߵ�ƽ��
	gpio_mode     (rst,GPIO_OUT);//��λ������Ϊ���졣
	gpio_out      (rst,1);       //Ĭ��Ϊ�ߵ�ƽ��
	gpio_mode     (cs,GPIO_OUT);   //Ƭѡ������Ϊ���졣
	gpio_out      (cs,1);          //Ĭ��Ϊ�ߵ�ƽ��
}	
/*-------------------------------------------------------
OLED�������ź���������Ӳ��SPIģʽ��
-------------------------------------------------------*/
void oled_set_hard_spi(oled_def * dev,u8 scl,u8 sda,u8 dc,u8 rst,u8 cs){
	if(cs!=Dxx){                                //���CS��ָ���ˣ�
		dev->mode=OLED_HARD_SPI|OLED_CS_ENABLE; //��ô����ģʽΪӲ��SPI+CS��
	}else{                                      //����
		dev->mode=OLED_HARD_SPI;                //ֻ����ģʽΪӲ��SPI��
	}
	scl=scl;                       //���õĲ��������������⾯�档
	sda=sda;                       //���õĲ��������������⾯�档
	dev->id      =0;               //������������...
	dev->rst_pin =rst;             //���渴λ�����á�
	dev->cs_pin  =cs;              //����Ƭѡ�����á�
	dev->dc_port =io2port(dc);     //����DC�ŵ�P�ڡ�
	dev->dc_pin  =io2pin (dc);     //����DC�ŵ�IO�ڡ�
	gpio_mode     (dc,GPIO_OUT);   //DC������Ϊ���졣
	gpio_out      (dc,1);          //Ĭ�ϸߵ�ƽ��
	gpio_mode     (rst,GPIO_OUT);  //��λ������Ϊ���졣
	gpio_out      (rst,1);         //Ĭ�ϸߵ�ƽ��
	gpio_mode     (cs,GPIO_OUT);   //Ƭѡ������Ϊ���졣
	gpio_out      (cs,1);          //Ĭ��Ϊ�ߵ�ƽ��
	spi_init();                    //��ʼ��Ӳ��SPI��
}
/*-------------------------------------------------------
OLED��д����������Ӳ��SPIģʽ��
-------------------------------------------------------*/
void oled_write_hard_spi(oled_def * dev,u8 cd,u8 buf){
	if(cd==oled_dat)
		gpio_out_fast(dev->dc_port,dev->dc_pin,1);
	else
		gpio_out_fast(dev->dc_port,dev->dc_pin,0);
	spi_send(buf);
}
/*-------------------------------------------------------
OLED��д�������������SPIģʽ��
-------------------------------------------------------*/
void oled_write_soft_spi(oled_def * dev,u8 cd,u8 buf){
	if(cd==oled_dat)
		gpio_out_fast(dev->dc_port,dev->dc_pin,1);
	else
		gpio_out_fast(dev->dc_port,dev->dc_pin,0);
	soft_spi_send(buf);
}
/*-------------------------------------------------------
OLED��д����������Ӳ��IICģʽ��
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
OLED��д�������������IICģʽ��
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
OLED��д������ͨ�á�
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
����OLED������
-------------------------------------------------------*/
void oled_on(oled_def * dev){
	oled_write(dev,oled_cmd,0xaf);
}
/*-------------------------------------------------------
�ر�OLED������
-------------------------------------------------------*/
void oled_off(oled_def * dev){
	oled_write(dev,oled_cmd,0xae);
}
/*-------------------------------------------------------
OLED����COM������������
-------------------------------------------------------*/
void oled_set_com(oled_def * dev,u8 num){
	oled_write(dev,oled_cmd,0xa8);
	oled_write(dev,oled_cmd,num);
}
/*-------------------------------------------------------
OLED���öԱȶȺ�����
-------------------------------------------------------*/
void oled_set_contrast(oled_def * dev,u8 val){
	oled_write(dev,oled_cmd,0x81);
	oled_write(dev,oled_cmd,val); 
}
/*-------------------------------------------------------
OLED��������ָ�뺯����
-------------------------------------------------------*/
void oled_set_pos(oled_def * dev,u8 x,u8 y){
	oled_write(dev,oled_cmd,0xb0+y);
	oled_write(dev,oled_cmd,((x&0xf0)>>4)|0x10);
	oled_write(dev,oled_cmd,x&0x0f);
}
/*-------------------------------------------------------
OLED�����߼�����ƫ�ƺ�����
-------------------------------------------------------*/
void oled_set_offset_logic(oled_def * dev,u8 offset){//�����߼����������Ӳ�����ŵ�ƫ��
	oled_write(dev,oled_cmd,0xd3);
	oled_write(dev,oled_cmd,offset);
}
/*-------------------------------------------------------
OLED����RAMƫ�ƺ�����
-------------------------------------------------------*/
void oled_set_offset_ram(oled_def * dev,u8 offset){//����RAM����߼����ŵ�ƫ��
	oled_write(dev,oled_cmd,0x40|offset);
}
/*-------------------------------------------------------
OLEDȫ�Ժ�����
-------------------------------------------------------*/
void oled_fill(oled_def * dev,u8 dat){//ˢ��SSD1306��RAM����128*8�ֽ�
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
OLED��ʾ������
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
OLED��ʾģʽ���ú�����
-------------------------------------------------------*/
void oled_set_display_mode(oled_def * dev,u8 mode){
	if(mode&0x01){
		oled_write(dev,oled_cmd,0xa0);//--Set SEG/Column Mapping     0xa0���ҷ��� 0xa1����
	}else{
		oled_write(dev,oled_cmd,0xa1);//--Set SEG/Column Mapping     0xa0���ҷ��� 0xa1����
	}
	if(mode&0x02){
		oled_write(dev,oled_cmd,0xc0);//Set COM/Row Scan Direction   0xc0���·��� 0xc8����	
		
	}else{
		oled_write(dev,oled_cmd,0xc8);//Set COM/Row Scan Direction   0xc0���·��� 0xc8����	
	}
	oled_write(dev,oled_cmd,0xda);//--set com pins hardware configuration
	oled_write(dev,oled_cmd,0x02|((mode&0x0C)<<2));
}
/*-------------------------------------------------------
OLED���ú�����
-------------------------------------------------------*/
void oled_set_display(oled_def * dev,u8 cmd){
	oled_write(dev,oled_cmd,cmd);
}
/*-------------------------------------------------------
OLED����Vcomh��ѹ������
-------------------------------------------------------*/
void oled_set_vcomh(oled_def * dev,u8 v){
	oled_write(dev,oled_cmd,0xdb);//--set vcomh
	oled_write(dev,oled_cmd,v);//Set VCOM Deselect Level
}
/*-------------------------------------------------------
OLED����DC-DC��·������
-------------------------------------------------------*/
void oled_set_dcdc(oled_def * dev,u8 en){
	oled_write(dev,oled_cmd,0x8d);//--set Charge Pump enable/disable
	oled_write(dev,oled_cmd,0x10|(en<<2));//--set(0x10) disable
}
/*-------------------------------------------------------
OLED����ɨƵʱ������
-------------------------------------------------------*/
void oled_set_pcc(oled_def * dev,u8 clk){
	oled_write(dev,oled_cmd,0xd9);//--set pre-charge period
	oled_write(dev,oled_cmd,clk);//Set Pre-Charge as 15 Clocks & Discharge as 1 Clock
}
/*-------------------------------------------------------
OLED���õ�ַģʽ������
-------------------------------------------------------*/
void oled_set_address_mode(oled_def * dev,u8 mode){
	oled_write(dev,oled_cmd,0x20);//-Set Page Addressing Mode (0x00/0x01/0x02)
	oled_write(dev,oled_cmd,mode);//
}
/*-------------------------------------------------------
OLED��������RC����������
-------------------------------------------------------*/
void oled_set_clk(oled_def * dev,u8 clk){
	oled_write(dev,oled_cmd,0xd5);
	oled_write(dev,oled_cmd,clk);
}
/*-------------------------------------------------------
OLED��ʼ��������
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
	oled_fill            (dev,0);  //��ʼ����
	oled_on              (dev);
	oled_set_pos         (dev,0,0); 	
	if((dev->mode)&OLED_CS_EN_MASK){
		gpio_out(dev->cs_pin,1);
	}
} 
/*-------------------------------------------------------
OLED�Զ���ʼ������
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
OLED��ʾģʽ���Ժ�����
-------------------------------------------------------*/
void oled_display_mode_test(oled_def * dev,u8 mode){
	u8 x=0,y=0;
	oled_set_display_mode(dev,mode);
	for(y=0;y<8;y++){        //�ڲ��Խ׶Σ�ֱ��д��8��page
		oled_set_pos(dev,x,y);
		for(x=0;x<128;x++){  //�ڲ��Խ׶Σ�ֱ��д��128����
			oled_write(dev,oled_dat,oled_display_mode_test_buf[x%16+mode*16]);
		}
	}
}
/*-------------------------------------------------------
OLED��Y��ƫ�Ʋ��Ժ�����
-------------------------------------------------------*/
void oled_display_y_test(oled_def * dev){
	u8 x=0,y=0;
	for(y=0;y<8;y++){        //�ڲ��Խ׶Σ�ֱ��д��8��page
		oled_set_pos(dev,x,y);
		for(x=0;x<128;x++){  //�ڲ��Խ׶Σ�ֱ��д��128����
			oled_write(dev,oled_dat,oled_display_mode_test_buf[x%8+y*16]);
		}
	}
}
/*-------------------------------------------------------
OLED��X��ƫ�Ʋ��Ժ�����
-------------------------------------------------------*/
void oled_display_x_test(oled_def * dev,u8 x_offset){
	u8 x=0,y=0;
	oled_fill(dev,0);
	for(y=0;y<8;y++){        //�ڲ��Խ׶Σ�ֱ��д��8��page
		oled_set_pos(dev,x_offset,y);
		for(x=0;x<4;x++){  //�ڲ��Խ׶Σ�ֱ��д��128����
			oled_write(dev,oled_dat,x_start[x]);
		}
		for(x=0;x<6;x++){  //�ڲ��Խ׶Σ�ֱ��д��128����
			oled_write(dev,oled_dat,oled_display_mode_test_buf[(x_offset/100)*16+x]);
		}
		for(x=0;x<6;x++){  //�ڲ��Խ׶Σ�ֱ��д��128����
			oled_write(dev,oled_dat,oled_display_mode_test_buf[(x_offset%100/10)*16+x]);
		}
		for(x=0;x<6;x++){  //�ڲ��Խ׶Σ�ֱ��д��128����
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
��ʾһ���ַ�����������������ʾ��
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
��ʽ����ʾ�ַ�������������������ʾ��
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
��ʾ��ǰ��OLED�ĸ�����Ϣ��
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