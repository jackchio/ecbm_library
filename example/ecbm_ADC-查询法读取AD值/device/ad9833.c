#include "ad9833.h"//ͳһ���غ���ͷ�ļ�

/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
ad9833��д������
-------------------------------------------------------*/
void ad9833_write(ad9833_def * dev,u16 txdata){
	u8 i;
	u16 _5us;
	_5us=delay_set_us(5);	//�������Ҫ��ʱ5us�ļ���ֵ��
	gpio_out(dev->sclk,1);	//ȷ����ʼͨ��ǰ��sclk�Ǹߵ�ƽ��
	gpio_out(dev->fsync,1);	//ȷ����ʼͨ��ǰ��fsync�Ǹߵ�ƽ��
	gpio_out(dev->fsync,0);	//����fsync�ţ���ʼͨ�š�
	for(i=0;i<16;i++){		//Ҫ��16λ���ݡ�
		if(txdata&0x8000){	//�����λ��ʼ����
			gpio_out(dev->sdata,1);
		}else{
			gpio_out(dev->sdata,0);
		}
		delay_us(_5us);		//����Ҫͨ��̫�죬��һ������ʱ��
		gpio_out(dev->sclk,0);//sclk�����͡�ͨ���½��ش������ݡ�
		delay_us(_5us);
		gpio_out(dev->sclk,1);//sclk�����ߣ����Ա䶯���ݽš�
		txdata <<= 1;		//ȡ��һλ���ݡ�
	}
	gpio_out(dev->fsync,1);//����fsync�ţ�����ͨ�š�
} 
/*-------------------------------------------------------
AD9833����Ƶ�ʺ�����
-------------------------------------------------------*/
void ad9833_set_freq(ad9833_def * dev,double freq){
	double   count;
	u32 count_hex;
	u16 count_lsb,count_msb;
	count=freq*(268435456.0f/(double)AD9833_MCLK);
	count_hex=(u32)(count);			//��������Ľ��ת����u32�ͣ�Ȼ���ֳ�����14λ���д���
	count_lsb=(u16)(count_hex);		//count_hex��16λ�͸�count_LSB
	count_lsb=count_lsb&0x3fff;		//ȥ�������λ��16λ����ȥ����λ������14λ
	count_msb=(u16)(count_hex>>14);	//count_hex��16λ�͸�count_HSB
	count_msb=count_msb&0x3fff;		//ȥ�������λ��16λ����ȥ����λ������14λ
	if((dev->config)&0x08){
		count_lsb=count_lsb|AD9833_FREQ1_REG_MASK;
		count_msb=count_msb|AD9833_FREQ1_REG_MASK;//ʹ��Ƶ�ʼĴ���1�������
	}else{
		count_lsb=count_lsb|AD9833_FREQ0_REG_MASK;
		count_msb=count_msb|AD9833_FREQ0_REG_MASK;//ʹ��Ƶ�ʼĴ���0�������
	}
	ad9833_write(dev,count_lsb); //L14��ѡ��Ƶ�ʼĴ���0�ĵ�14λ��������
	ad9833_write(dev,count_msb); //H14 Ƶ�ʼĴ����ĸ�14λ��������
}
/*-------------------------------------------------------
AD9833���ò��κ�����
-------------------------------------------------------*/
void ad9833_set_wave(ad9833_def * dev,u8 wave){
	u16 reg;
	reg=0x2000;
	if(dev->config&0x08){
		reg|=0x0800;
	}
	if(dev->config&0x04){
		reg|=0x0400;
	}
	switch(wave){
		case AD9833_OFF_WAVE:{
			reg|=AD9833_REG_OFF_WAVE;
		}break;
		case AD9833_TRI_WAVE:{
			reg|=AD9833_REG_TRI_WAVE;
		}break;
		case AD9833_SIN_WAVE:{
			reg|=AD9833_REG_SIN_WAVE;
		}break;
		case AD9833_SQU_WAVE:{
			reg|=AD9833_REG_SQU_WAVE;
		}break;
	}
	ad9833_write(dev,reg); 
}
/*-------------------------------------------------------
ad9833�ĳ�ʼ��������
-------------------------------------------------------*/
void ad9833_init(ad9833_def * dev,u8 fsync,u8 sclk,u8 sdata){
	dev->fsync=fsync;			//��������Ϣ����ṹ�壬��ͬ��
	dev->sclk =sclk;
	dev->sdata=sdata;
	gpio_mode(fsync,GPIO_OUT);	//����Ӧ����������Ϊ����ģʽ����Ϊֻ�������
	gpio_mode(sclk ,GPIO_OUT);
	gpio_mode(sdata,GPIO_OUT);
	ad9833_write(dev,0x0100);	//��λAD9833,��RESETλΪ1��ͬʱ��λ�����������λ�ĳ�0��
	ad9833_write(dev,AD9833_REG);//����AD9833Ϊ��ʼ״̬��
	#if   AD9833_REG == 0x2000 //ѡ�������Ҳ�
	dev->config=AD9833_SIN_WAVE;
	#elif AD9833_REG == 0x2002 //ѡ�������ǲ�
	dev->config=AD9833_TRI_WAVE;
	#elif AD9833_REG == 0x2068 //ѡ���˾��β�
	dev->config=AD9833_SQU_WAVE;
	#elif AD9833_REG == 0x20E8 //ѡ���˲����
	dev->config=AD9833_OFF_WAVE;
	#endif
	ad9833_set_freq(dev,AD9833_FREQ);
}
/*-------------------------------------------------------
��������
��  ����
��  �룺
��  ����
����ֵ��
�����ߣ�
�������̣�
�������ڣ�
�޸ļ�¼��
-------------------------------------------------------*/
//void ad9833_set_freqaddr(ad9833_def * dev,u8 addr){
//	if(addr){
//		dev->config|=0x08;
//	}else{
//		dev->config&=0xF7;
//	}
//}