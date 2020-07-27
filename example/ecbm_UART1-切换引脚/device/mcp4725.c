#include "mcp4725.h"//ͳһ���غ���ͷ�ļ�
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
MCP4725�ĳ�ʼ��������ʹ�����IIC��
-------------------------------------------------------*/
void mcp4725_soft_init(mcp4725_def * dev,u8 scl,u8 sda){
	dev->config=MCP4725_SOFT_IIC;//����Ϊ���IIC����ʽ��
	dev->scl_pin=scl;//����ʱ�ӽš�
	dev->sda_pin=sda;//�������ݽš�
	dev->addr=0xC0;	 //����Ĭ�ϵ�оƬ��ַ��
	dev->id=soft_iic_init_linkage(scl,sda);//��ʼ�����IIC������ȡID�š�
}
/*-------------------------------------------------------
MCP4725�ĳ�ʼ��������ʹ��Ӳ��IIC��
-------------------------------------------------------*/
void mcp4725_hard_init(mcp4725_def * dev,u8 scl,u8 sda){
	dev->config=MCP4725_HARD_IIC;//����ΪӲ��IIC����ʽ��
	dev->scl_pin=scl;//����ʱ�ӽš�
	dev->sda_pin=sda;//�������ݽš�
	dev->addr=0xC0;	 //����Ĭ�ϵ�оƬ��ַ��
	iic_master_init();
	dev->id=0;
}
/*-------------------------------------------------------
MCP4725�����õ�ַ������
-------------------------------------------------------*/
void mcp4725_set_addr(mcp4725_def * dev,u8 addr){
	dev->addr=0xC0;						//��λ��0xC0�ǹ̶��ģ�
	if((addr>=0)&&(addr<=7)){			//�����ַ����ȷ�ķ�Χ�ڡ�
		dev->addr=(dev->addr)|(addr<<1);//IIC��D0�Ƕ�дλ������Ҫ����1λ��
	}
}
/*-------------------------------------------------------
MCP4725�����к�����
-------------------------------------------------------*/
void mcp4725_run(mcp4725_def * dev,u16 dat){
	if((dev->config&MCP4725_IIC_MASK)==MCP4725_SOFT_IIC){
		soft_iic_set_pin_linkage(dev->id,dev->scl_pin,dev->sda_pin);//�л��ܽš�
		soft_iic_start   ();			//��ʼͨ�š�
		soft_iic_write   (dev->addr);	//��дIIC��ַ��
		soft_iic_read_ack();			//�ȴ���Ӧ��
		soft_iic_write   (0x00|((u8)(dat>>8)&0x0f));//����ģʽ��ֻд��Ĵ�����ͬʱд��4λ��
		soft_iic_read_ack();			//�ȴ���Ӧ��
		soft_iic_write   ((u8)dat);		//д��8λ��
		soft_iic_read_ack();			//�ȴ���Ӧ��
		soft_iic_stop    ();			//����ͨ�š�
	}else{
		iic_start   ();			//��ʼͨ�š�
		iic_write   (dev->addr);//��дIIC��ַ��
		iic_read_ack();			//�ȴ���Ӧ��
		iic_write   (0x00|((u8)(dat>>8)&0x0f));//����ģʽ��ֻд��Ĵ�����ͬʱд��4λ��
		iic_read_ack();			//�ȴ���Ӧ��
		iic_write   ((u8)dat);	//д��8λ��
		iic_read_ack();			//�ȴ���Ӧ��
		iic_stop    ();			//����ͨ�š�
	}
}
/*-------------------------------------------------------
MCP4725�����������
-------------------------------------------------------*/
void mcp4725_out(mcp4725_def * dev,float vcc,float out){
	mcp4725_run(dev,(u16)(out/vcc*4096));
}