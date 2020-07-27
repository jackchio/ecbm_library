#include "ecbm_core.h"//ͳһ���غ���ͷ�ļ�
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
���SPI�����л�������
-------------------------------------------------------*/
void soft_spi_set_pin(soft_spi_def * dev){
	if(soft_spi_index!=dev->dev_id){                  //�ж�ID�ţ����Լ���8us@24MHz��ʱ�䡣
		soft_spi_def_clk_port =io2port(dev->clk_pin); //��ѹʱ�ӽŵ�P�ڡ�
		soft_spi_def_clk_pin  =io2pin (dev->clk_pin); //��ѹʱ�ӽŵ�IO�ڡ�
		soft_spi_def_mosi_port=io2port(dev->mosi_pin);//��ѹ��������ŵ�P�ڡ�
		soft_spi_def_mosi_pin =io2pin (dev->mosi_pin);//��ѹ��������ŵ�IO�ڡ�
		soft_spi_def_miso_port=io2port(dev->miso_pin);//��ѹ��������ŵ�P�ڡ�
		soft_spi_def_miso_pin =io2pin (dev->miso_pin);//��ѹ��������ŵ�IO�ڡ�
		soft_spi_def_cs_port  =io2port(dev->cs_pin);  //��ѹƬѡ�ŵ�P�ڡ�
		soft_spi_def_cs_pin   =io2pin (dev->cs_pin);  //��ѹƬѡ�ŵ�IO�ڡ�
		soft_spi_mode=dev->mode;                      //����ģʽ��
		soft_spi_index=dev->dev_id;                   //�л�ID��
	}	
}
/*-------------------------------------------------------
���SPI��ʼ��������
-------------------------------------------------------*/
void soft_spi_init(soft_spi_def * dev,u8 clk,u8 mosi,u8 miso,u8 cs,u8 mode){
	dev->clk_pin =clk;             //����ʱ�ӽ���Ϣ��
	dev->mosi_pin=mosi;            //���������������Ϣ��
	dev->miso_pin=miso;            //���������������Ϣ��
	dev->cs_pin  =cs;              //����Ƭѡ����Ϣ��
	dev->mode    =mode;            //����ģʽ��Ϣ��
	gpio_mode(clk, GPIO_PP);       //ʱ�ӽ�����Ϊ���졣
	if(mode&SOFT_SPI_CPOL_MASK){   //�鿴ʱ�Ӽ������ã�
		gpio_out(clk,1);           //�����Ǹߵ�ƽ�����øߣ�
	}else{
		gpio_out(clk,0);           //�����ǵ͵�ƽ�����õ͡�
	}
	if(mode&SOFT_SPI_MOSI_EN_MASK){//�鿴MOSIʹ�ܣ�
		gpio_mode(mosi,GPIO_PP);   //ʹ���˾�����Ϊ����ģʽ��
		gpio_out (mosi,1);         //Ĭ�ϸߵ�ƽ��
	}
	if(mode&SOFT_SPI_MISO_EN_MASK){//�鿴MISOʹ�ܣ�
		gpio_mode  (miso,GPIO_OD); //ʹ���˾�����Ϊ��©ģʽ��
		gpio_uppull(miso,1);       //�����������衣
		gpio_out   (miso,1);       //Ĭ�ϸߵ�ƽ��
	}
	if(mode&SOFT_SPI_CS_EN_MASK){  //�鿴Ƭѡ��ʹ�ܣ�
		gpio_mode(cs,GPIO_PP);     //ʹ���˾�����Ϊ����ģʽ��
		gpio_out (cs,1);           //Ĭ�ϸߵ�ƽ��
	}
	dev->dev_id=++soft_spi_max;    //��ȡID�š�
	soft_spi_set_pin(dev);         //���ò�����ϵͳ��
} 
/*-------------------------------------------------------
���SPI�����л������������棩��
-------------------------------------------------------*/
void soft_spi_set_pin_linkage(u8 id,u8 clk,u8 mosi,u8 miso,u8 cs,u8 mode){
	if(soft_spi_index!=id){                    //�ж�ID�ţ����Լ���8us@24MHz��ʱ�䡣
		soft_spi_def_clk_port =io2port(clk);   //��ѹʱ�ӽŵ�P�ڡ�
		soft_spi_def_clk_pin  =io2pin (clk);   //��ѹʱ�ӽŵ�IO�ڡ�
		soft_spi_def_mosi_port=io2port(mosi);  //��ѹ��������ŵ�P�ڡ�
		soft_spi_def_mosi_pin =io2pin (mosi);  //��ѹ��������ŵ�IO�ڡ�
		soft_spi_def_miso_port=io2port(miso);  //��ѹ��������ŵ�P�ڡ�
		soft_spi_def_miso_pin =io2pin (miso);  //��ѹ��������ŵ�IO�ڡ�
		soft_spi_def_cs_port  =io2port(cs);    //��ѹƬѡ�ŵ�P�ڡ�
		soft_spi_def_cs_pin   =io2pin (cs);    //��ѹƬѡ�ŵ�IO�ڡ�
		soft_spi_mode=mode;                    //����ģʽ��
		soft_spi_index=id;                     //�л�ID��
	}	
}
/*-------------------------------------------------------
���SPI��ʼ�������������棩��
-------------------------------------------------------*/
u8 soft_spi_init_linkage(u8 clk,u8 mosi,u8 miso,u8 cs,u8 mode){
	u8 id;                         //ΨһID��
	gpio_mode(clk, GPIO_PP);       //ʱ�ӽ�����Ϊ���졣
	if(mode&SOFT_SPI_CPOL_MASK){   //�鿴ʱ�Ӽ������ã�
		gpio_out(clk,1);           //�����Ǹߵ�ƽ�����øߣ�
	}else{
		gpio_out(clk,0);           //�����ǵ͵�ƽ�����õ͡�
	}
	if(mode&SOFT_SPI_MOSI_EN_MASK){//�鿴MOSIʹ�ܣ�
		gpio_mode(mosi,GPIO_PP);   //ʹ���˾�����Ϊ����ģʽ��
		gpio_out (mosi,1);         //Ĭ�ϸߵ�ƽ��
	}
	if(mode&SOFT_SPI_MISO_EN_MASK){//�鿴MISOʹ�ܣ�
		gpio_mode  (miso,GPIO_OD); //ʹ���˾�����Ϊ��©ģʽ��
		gpio_uppull(miso,1);       //�����������衣
		gpio_out   (miso,1);       //Ĭ�ϸߵ�ƽ��
	}
	if(mode&SOFT_SPI_CS_EN_MASK){  //�鿴Ƭѡ��ʹ�ܣ�
		gpio_mode(cs,GPIO_PP);     //ʹ���˾�����Ϊ����ģʽ��
		gpio_out (cs,1);           //Ĭ�ϸߵ�ƽ��
	}
	id =++soft_spi_max;            //��ȡID�š�
	soft_spi_set_pin_linkage(id,clk,mosi,miso,cs,mode);//���ò�����ϵͳ��
	return id;	                   //����ID�š�
} 
/*-------------------------------------------------------
���SPI����/���պ�����
-------------------------------------------------------*/
u8 soft_spi_send(u8 dat){
	u8 i,j,k=0;
	if(soft_spi_mode&SOFT_SPI_CPOL_MASK){                           //��ȡʱ�Ӽ��Բ�����
		gpio_out_fast(soft_spi_def_clk_port,soft_spi_def_clk_pin,1);//���ݲ�������һ��IO�ĳ�ʼ״̬��
	}else{
		gpio_out_fast(soft_spi_def_clk_port,soft_spi_def_clk_pin,0);//Ŀ����Ϊ�˷�ֹ�����Ÿ����µĵ�ƽ��λ��
	}
	if((soft_spi_mode&(SOFT_SPI_CS_CON_MASK|SOFT_SPI_CS_EN_MASK))==(SOFT_SPI_CS_CON_MASK|SOFT_SPI_CS_EN_MASK)){
		gpio_out_fast(soft_spi_def_cs_port,soft_spi_def_cs_pin,0);//���Ƭѡ��ʹ�����ɿ⺯�����ƣ������͵�ƽ��
	}
	if(soft_spi_mode&SOFT_SPI_MSB_LSB_MASK){//������ȷ���λ��
		i=0x80;
		for(j=0;j<8;j++){                   //8λ�����ݡ�
			if(dat&i){                      //���ݵ�ǰλ���������ƽ��
				gpio_out_fast(soft_spi_def_mosi_port,soft_spi_def_mosi_pin,1);
			}else{
				gpio_out_fast(soft_spi_def_mosi_port,soft_spi_def_mosi_pin,0);
			}
			gpio_toggle_fast(soft_spi_def_clk_port,soft_spi_def_clk_pin);//ʱ�ӽŵ�һ�η�ת��
			if((soft_spi_mode&SOFT_SPI_MISO_EN_MASK)&&((soft_spi_mode&SOFT_SPI_CPHA_MASK)==0)){//��ȡʱ����λ���á�
				if(gpio_in_fast(soft_spi_def_miso_port,soft_spi_def_miso_pin)){//�����ǵ�һ�η�ת���Ļ����Ͷ�MISO�š�
					k|=i;//��MISO�ŵ����ݴ�����ʱ�����
				}
			}
			gpio_toggle_fast(soft_spi_def_clk_port,soft_spi_def_clk_pin);//ʱ�ӽŵڶ��η�ת��
			if((soft_spi_mode&SOFT_SPI_MISO_EN_MASK)&&((soft_spi_mode&SOFT_SPI_CPHA_MASK)==1)){//��ȡʱ����λ���á�
				if(gpio_in_fast(soft_spi_def_miso_port,soft_spi_def_miso_pin)){//�����ǵڶ��η�ת���Ļ����Ͷ�MISO�š�
					k|=i;//��MISO�ŵ����ݴ�����ʱ�����
				}
			}
			i>>=1;
		}
	}else{                                  //������ȷ���λ
		i=0x01;
		for(j=0;j<8;j++){                  //8λ�����ݡ�
			if(dat&i){                     //���ݵ�ǰλ���������ƽ��
				gpio_out_fast(soft_spi_def_mosi_port,soft_spi_def_mosi_pin,1);
			}else{
				gpio_out_fast(soft_spi_def_mosi_port,soft_spi_def_mosi_pin,0);
			}
			gpio_toggle_fast(soft_spi_def_clk_port,soft_spi_def_clk_pin);//ʱ�ӽŵ�һ�η�ת��
			if((soft_spi_mode&SOFT_SPI_MISO_EN_MASK)&&((soft_spi_mode&SOFT_SPI_CPHA_MASK)==0)){//��ȡʱ����λ���á�
				if(gpio_in_fast(soft_spi_def_miso_port,soft_spi_def_miso_pin)){//�����ǵ�һ�η�ת���Ļ����Ͷ�MISO�š�
					k|=i;//��MISO�ŵ����ݴ�����ʱ�����
				}
			}
			gpio_toggle_fast(soft_spi_def_clk_port,soft_spi_def_clk_pin);
			if((soft_spi_mode&SOFT_SPI_MISO_EN_MASK)&&((soft_spi_mode&SOFT_SPI_CPHA_MASK)==1)){//��ȡʱ����λ���á�
				if(gpio_in_fast(soft_spi_def_miso_port,soft_spi_def_miso_pin)){//�����ǵڶ��η�ת���Ļ����Ͷ�MISO�š�
					k|=i;//��MISO�ŵ����ݴ�����ʱ�����
				}
			}
			i<<=1;
		}
	}
	if((soft_spi_mode&(SOFT_SPI_CS_CON_MASK|SOFT_SPI_CS_EN_MASK))==(SOFT_SPI_CS_CON_MASK|SOFT_SPI_CS_EN_MASK)){
		gpio_out_fast(soft_spi_def_cs_port,soft_spi_def_cs_pin,1);//���Ƭѡ��ʹ�����ɿ⺯�����ƣ������ߵ�ƽ��
	}
	return k;//���ػ���ֵ��
}
#endif