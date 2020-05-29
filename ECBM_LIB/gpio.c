#include "ecbm_core.h"
#if ECBM_GPIO_EN
u8 code ecbm_pin_mask[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
u8 data ecbm_port,ecbm_pin;
/*--------------------------------------������-----------------------------------*/
/*�������۵�ר��************************IO����ģ��******************************/#if 1
/*-------------------------------------------------------
IO�������������ú�����
-------------------------------------------------------*/
#if ECBM_GPIO_UPPULL_EN
void gpio_uppull(u8 pin,bit en){
	/*---�����￪ʼ�������ڽ��IO�ڱ�š�---*/
	if(pin==Dxx)goto gpio_uppull_end;
	ecbm_port=pin&0xf0;
	ecbm_pin =ecbm_pin_mask[pin&0x0f];
	if((pin&0x0f)>7){
		#if SYS_ERROR_EN
		error_printf("gpio_uppull(<D%02X>,%d);�����ڸ�IO\r\n",(u16)pin,(u16)en);
		#else
		while(1);
		#endif	
	}
	/*-------����������������ɡ�-------*/
	if(en){//�����ʹ�ܣ��򽫶�Ӧ��IO�����������衣
		switch(ecbm_port){
			#if ECBM_GPIO0_EN
			case 0x00:P0PU|=ecbm_pin;break;
			#endif
			#if ECBM_GPIO1_EN
			case 0x10:P1PU|=ecbm_pin;break;
			#endif
			#if ECBM_GPIO2_EN
			case 0x20:P2PU|=ecbm_pin;break;
			#endif
			#if ECBM_GPIO3_EN
			case 0x30:P3PU|=ecbm_pin;break;
			#endif
			#if ECBM_GPIO4_EN
			case 0x40:P4PU|=ecbm_pin;break;
			#endif
			#if ECBM_GPIO5_EN
			case 0x50:P5PU|=ecbm_pin;break;
			#endif
			#if ECBM_GPIO6_EN
			case 0x60:P6PU|=ecbm_pin;break;
			#endif
			#if ECBM_GPIO7_EN
			case 0x70:P7PU|=ecbm_pin;break;
			#endif
			#if SYS_ERROR_EN
			default:error_printf("gpio_uppull(<D%02X>,1);�����ڸ�IO\r\n",(u16)pin);break;
			#else
			default:while(1);break;
			#endif
		}
	}else{//�����ʧ�ܣ��򽫶�Ӧ��IOȡ���������衣
		switch(ecbm_port){
			#if ECBM_GPIO0_EN
			case 0x00:P0PU&=~ecbm_pin;break;
			#endif
			#if ECBM_GPIO1_EN
			case 0x10:P1PU&=~ecbm_pin;break;
			#endif
			#if ECBM_GPIO2_EN
			case 0x20:P2PU&=~ecbm_pin;break;
			#endif
			#if ECBM_GPIO3_EN
			case 0x30:P3PU&=~ecbm_pin;break;
			#endif
			#if ECBM_GPIO4_EN
			case 0x40:P4PU&=~ecbm_pin;break;
			#endif
			#if ECBM_GPIO5_EN
			case 0x50:P5PU&=~ecbm_pin;break;
			#endif
			#if ECBM_GPIO6_EN
			case 0x60:P6PU&=~ecbm_pin;break;
			#endif
			#if ECBM_GPIO7_EN
			case 0x70:P7PU&=~ecbm_pin;break;
			#endif
			#if SYS_ERROR_EN
			default:error_printf("gpio_uppull(<D%02X>,0);�����ڸ�IO\r\n",(u16)pin);break;
			#else
			default:while(1);break;
			#endif
		}
	}
	gpio_uppull_end:;
}
#endif
/*-------------------------------------------------------
����IO�ڹ���ģʽ������
-------------------------------------------------------*/
#if ECBM_GPIO_MODE_EN
void gpio_mode(u8 pin,u8 mode){
	/*---�����￪ʼ�������ڽ��IO�ڱ�š�---*/
	if(pin==Dxx)goto gpio_mode_end;
	ecbm_port=pin&0xf0;
	ecbm_pin=ecbm_pin_mask[pin&0x0f];
	if((pin&0x0f)>7){
		#if SYS_ERROR_EN
		error_printf("gpio_mode(<D%02X>,%d);�����ڸ�IO\r\n",(u16)pin,(u16)mode);
		#else
		while(1);
		#endif	
	}
	switch(ecbm_port){
		#if ECBM_GPIO0_EN
		case 0x00:ecbm_port=GPIO_P0;break;
		#endif
		#if ECBM_GPIO1_EN
		case 0x10:ecbm_port=GPIO_P1;break;
		#endif
		#if ECBM_GPIO2_EN
		case 0x20:ecbm_port=GPIO_P2;break;
		#endif
		#if ECBM_GPIO3_EN
		case 0x30:ecbm_port=GPIO_P3;break;
		#endif
		#if ECBM_GPIO4_EN
		case 0x40:ecbm_port=GPIO_P4;break;
		#endif
		#if ECBM_GPIO5_EN
		case 0x50:ecbm_port=GPIO_P5;break;
		#endif
		#if ECBM_GPIO6_EN
		case 0x60:ecbm_port=GPIO_P6;break;
		#endif
		#if ECBM_GPIO7_EN
		case 0x70:ecbm_port=GPIO_P7;break;
		#endif
		#if SYS_ERROR_EN
		default:error_printf("gpio_mode(<D%02X>,%d);�����ڸ�IO\r\n",(u16)pin,(u16)mode);break;
		#else
		default:while(1);break;
		#endif
	}
	/*-------����������������ɡ�-------*/
	if(mode>3){
		#if SYS_ERROR_EN
		error_printf("gpio_mode(D%02X,<%d>);�����ڸ�ģʽ\r\n",(u16)pin,(u16)mode);
		#else
		while(1);
		#endif
	}	
	#if ECBM_GPIO0_EN
	if(ecbm_port==GPIO_P0){//��������������趨��ͬ��IO���ã���ͬ��
		if(mode==GPIO_PU){P0M1&=~ecbm_pin;P0M0&=~ecbm_pin;}
		if(mode==GPIO_HZ){P0M1|= ecbm_pin;P0M0&=~ecbm_pin;}
		if(mode==GPIO_OD){P0M1|= ecbm_pin;P0M0|= ecbm_pin;}
		if(mode==GPIO_PP){P0M1&=~ecbm_pin;P0M0|= ecbm_pin;}
	}
	#endif
	#if ECBM_GPIO1_EN
	if(ecbm_port==GPIO_P1){
		if(mode==GPIO_PU){P1M1&=~ecbm_pin;P1M0&=~ecbm_pin;}
		if(mode==GPIO_HZ){P1M1|= ecbm_pin;P1M0&=~ecbm_pin;}
		if(mode==GPIO_OD){P1M1|= ecbm_pin;P1M0|= ecbm_pin;}
		if(mode==GPIO_PP){P1M1&=~ecbm_pin;P1M0|= ecbm_pin;}
	}
	#endif
	#if ECBM_GPIO2_EN
	if(ecbm_port==GPIO_P2){
		if(mode==GPIO_PU){P2M1&=~ecbm_pin;P2M0&=~ecbm_pin;}
		if(mode==GPIO_HZ){P2M1|= ecbm_pin;P2M0&=~ecbm_pin;}
		if(mode==GPIO_OD){P2M1|= ecbm_pin;P2M0|= ecbm_pin;}
		if(mode==GPIO_PP){P2M1&=~ecbm_pin;P2M0|= ecbm_pin;}
	}	
	#endif
	#if ECBM_GPIO3_EN
	if(ecbm_port==GPIO_P3){
		if(mode==GPIO_PU){P3M1&=~ecbm_pin;P3M0&=~ecbm_pin;}
		if(mode==GPIO_HZ){P3M1|= ecbm_pin;P3M0&=~ecbm_pin;}
		if(mode==GPIO_OD){P3M1|= ecbm_pin;P3M0|= ecbm_pin;}
		if(mode==GPIO_PP){P3M1&=~ecbm_pin;P3M0|= ecbm_pin;}
	}
	#endif
	#if ECBM_GPIO4_EN
	if(ecbm_port==GPIO_P4){
		if(mode==GPIO_PU){P4M1&=~ecbm_pin;P4M0&=~ecbm_pin;}
		if(mode==GPIO_HZ){P4M1|= ecbm_pin;P4M0&=~ecbm_pin;}
		if(mode==GPIO_OD){P4M1|= ecbm_pin;P4M0|= ecbm_pin;}
		if(mode==GPIO_PP){P4M1&=~ecbm_pin;P4M0|= ecbm_pin;}
	}
	#endif
	#if ECBM_GPIO5_EN
	if(ecbm_port==GPIO_P5){
		if(mode==GPIO_PU){P5M1&=~ecbm_pin;P5M0&=~ecbm_pin;}
		if(mode==GPIO_HZ){P5M1|= ecbm_pin;P5M0&=~ecbm_pin;}
		if(mode==GPIO_OD){P5M1|= ecbm_pin;P5M0|= ecbm_pin;}
		if(mode==GPIO_PP){P5M1&=~ecbm_pin;P5M0|= ecbm_pin;}
	}	
	#endif
	#if ECBM_GPIO6_EN
	if(ecbm_port==GPIO_P6){
		if(mode==GPIO_PU){P6M1&=~ecbm_pin;P6M0&=~ecbm_pin;}
		if(mode==GPIO_HZ){P6M1|= ecbm_pin;P6M0&=~ecbm_pin;}
		if(mode==GPIO_OD){P6M1|= ecbm_pin;P6M0|= ecbm_pin;}
		if(mode==GPIO_PP){P6M1&=~ecbm_pin;P6M0|= ecbm_pin;}
	}
	#endif
	#if ECBM_GPIO7_EN
	if(ecbm_port==GPIO_P7){
		if(mode==GPIO_PU){P7M1&=~ecbm_pin;P7M0&=~ecbm_pin;}
		if(mode==GPIO_HZ){P7M1|= ecbm_pin;P7M0&=~ecbm_pin;}
		if(mode==GPIO_OD){P7M1|= ecbm_pin;P7M0|= ecbm_pin;}
		if(mode==GPIO_PP){P7M1&=~ecbm_pin;P7M0|= ecbm_pin;}
	}	
	#endif
	gpio_mode_end:;
}
#endif
/*�������۵�ר��**************************************************************/#endif
/*�������۵�ר��**********************��ͨIO����ģ��****************************/#if 1
/*-------------------------------------------------------
P��д�뺯����ֱ��д��8λ���ݵ�ĳ��P���ϡ�
-------------------------------------------------------*/
#if ECBM_GPIO_WRITE_EN
void gpio_write(u8 port,u8 dat){
	switch(port){//ͨ���ж�P�ڱ�Ž��벻ͬ�ķ�֧��
		#if ECBM_GPIO0_EN
		case GPIO_P0:P0=dat;break;//�����ݷ��͵���Ӧ��P�ڣ���ͬ��
		#endif
		#if ECBM_GPIO1_EN
		case GPIO_P1:P1=dat;break;
		#endif
		#if ECBM_GPIO2_EN
		case GPIO_P2:P2=dat;break;
		#endif
		#if ECBM_GPIO3_EN
		case GPIO_P3:P3=dat;break;
		#endif
		#if ECBM_GPIO4_EN
		case GPIO_P4:P4=dat;break;
		#endif
		#if ECBM_GPIO5_EN
		case GPIO_P5:P5=dat;break;
		#endif
		#if ECBM_GPIO6_EN
		case GPIO_P6:P6=dat;break;
		#endif
		#if ECBM_GPIO7_EN
		case GPIO_P7:P7=dat;break;
		#endif
		case GPIO_Px:break;
		#if SYS_ERROR_EN
		default:error_printf("gpio_write(<%d>,%d);�����ڸ�P��\r\n",(u16)port,(u16)dat);break;
		#else
		default:while(1);break;
		#endif
	}
}
#endif
/*-------------------------------------------------------
P�ڶ���������������P�ڵ�ֵһ���Զ���(����)��
-------------------------------------------------------*/
#if ECBM_GPIO_READ_EN
u8   gpio_read(u8 port){
	switch(port){//ͨ���ж�P�ڱ�Ž��벻ͬ�ķ�֧��
		#if ECBM_GPIO0_EN
		case GPIO_P0:return P0;break;//����ӦP�ڵ�ֵ���أ���ͬ��
		#endif
		#if ECBM_GPIO1_EN
		case GPIO_P1:return P1;break;
		#endif
		#if ECBM_GPIO2_EN
		case GPIO_P2:return P2;break;
		#endif
		#if ECBM_GPIO3_EN
		case GPIO_P3:return P3;break;
		#endif
		#if ECBM_GPIO4_EN
		case GPIO_P4:return P4;break;
		#endif
		#if ECBM_GPIO5_EN
		case GPIO_P5:return P5;break;
		#endif
		#if ECBM_GPIO6_EN
		case GPIO_P6:return P6;break;
		#endif
		#if ECBM_GPIO7_EN
		case GPIO_P7:return P7;break;
		#endif
		case GPIO_Px:return 0xff;break;
		#if SYS_ERROR_EN
		default:error_printf("gpio_read(<P%d>);�����ڸ�P��\r\n",(u16)port);break;
		#else
		default:while(1);break;
		#endif
	}
	return 0xFF;
}
#endif
/*-------------------------------------------------------
IO�����������
-------------------------------------------------------*/
#if ECBM_GPIO_OUT_EN
void gpio_out(u8 pin,bit value){
	/*---�����￪ʼ�������ڽ��IO�ڱ�š�---*/
	if(pin==Dxx)goto gpio_out_end;
	ecbm_port=pin&0xf0;
	ecbm_pin =ecbm_pin_mask[pin&0x0f];
	if((pin&0x0f)>7){
		#if SYS_ERROR_EN
		error_printf("gpio_out(<D%02X>,%d);�����ڸ�IO\r\n",(u16)pin,(u16)value);
		#else
		while(1);
		#endif	
	}
	/*-------����������������ɡ�-------*/
	if(value){//�û�����ʵ������ߵ�ƽ���ٶȻ��һЩ��
		switch(ecbm_port){
			#if ECBM_GPIO0_EN
			case 0x00:P0|=ecbm_pin;break;
			#endif
			#if ECBM_GPIO1_EN
			case 0x10:P1|=ecbm_pin;break;
			#endif
			#if ECBM_GPIO2_EN
			case 0x20:P2|=ecbm_pin;break;
			#endif
			#if ECBM_GPIO3_EN
			case 0x30:P3|=ecbm_pin;break;
			#endif
			#if ECBM_GPIO4_EN
			case 0x40:P4|=ecbm_pin;break;
			#endif
			#if ECBM_GPIO5_EN
			case 0x50:P5|=ecbm_pin;break;
			#endif
			#if ECBM_GPIO6_EN
			case 0x60:P6|=ecbm_pin;break;
			#endif
			#if ECBM_GPIO7_EN
			case 0x70:P7|=ecbm_pin;break;
			#endif
			#if SYS_ERROR_EN
			default:error_printf("gpio_out(<D%02X>,1);�����ڸ�IO\r\n",(u16)pin);break;
			#else
			default:while(1);break;
			#endif
		}
	}else{//��������ʵ������͵�ƽ���ٶȻ��һЩ��
		switch(ecbm_port){
			#if ECBM_GPIO0_EN
			case 0x00:P0&=~ecbm_pin;break;
			#endif
			#if ECBM_GPIO1_EN
			case 0x10:P1&=~ecbm_pin;break;
			#endif
			#if ECBM_GPIO2_EN
			case 0x20:P2&=~ecbm_pin;break;
			#endif
			#if ECBM_GPIO3_EN
			case 0x30:P3&=~ecbm_pin;break;
			#endif
			#if ECBM_GPIO4_EN
			case 0x40:P4&=~ecbm_pin;break;
			#endif
			#if ECBM_GPIO5_EN
			case 0x50:P5&=~ecbm_pin;break;
			#endif
			#if ECBM_GPIO6_EN
			case 0x60:P6&=~ecbm_pin;break;
			#endif
			#if ECBM_GPIO7_EN
			case 0x70:P7&=~ecbm_pin;break;
			#endif
			#if SYS_ERROR_EN
			default:error_printf("gpio_out(<D%02X>,0);�����ڸ�IO\r\n",(u16)pin);break;
			#else
			default:while(1);break;
			#endif
		}		
	}
	gpio_out_end:;
}
#endif
/*-------------------------------------------------------
IO�����뺯����
-------------------------------------------------------*/
#if ECBM_GPIO_IN_EN
bit  gpio_in(u8 pin){
	u8 data value;
	/*---�����￪ʼ�������ڽ��IO�ڱ�š�---*/
	if(pin==Dxx)return 0;
	ecbm_port=pin&0xf0;
	ecbm_pin =ecbm_pin_mask[pin&0x0f];
	if((pin&0x0f)>7){
		#if SYS_ERROR_EN
		error_printf("gpio_in(<D%02X>);�����ڸ�IO\r\n",(u16)pin);
		#else
		while(1);
		#endif	
	}
	/*-------����������������ɡ�-------*/
	switch(ecbm_port){//ֱ�Ӷ�ȡ����P�ڵ�����
		#if ECBM_GPIO0_EN
		case 0x00:value=P0;break;
		#endif
		#if ECBM_GPIO1_EN
		case 0x10:value=P1;break;
		#endif
		#if ECBM_GPIO2_EN
		case 0x20:value=P2;break;
		#endif
		#if ECBM_GPIO3_EN
		case 0x30:value=P3;break;
		#endif
		#if ECBM_GPIO4_EN
		case 0x40:value=P4;break;
		#endif
		#if ECBM_GPIO5_EN
		case 0x50:value=P5;break;
		#endif
		#if ECBM_GPIO6_EN
		case 0x60:value=P6;break;
		#endif
		#if ECBM_GPIO7_EN
		case 0x70:value=P7;break;
		#endif
		#if SYS_ERROR_EN
		default:error_printf("gpio_in(<D%02X>);�����ڸ�IO\r\n",(u16)pin);break;
		#else
		default:while(1);break;
		#endif	
	}
	if(value&ecbm_pin)return 1;//ͨ������������ȡĳһλ�ĵ�ƽ״̬��
	else return 0;
}
#endif
/*-------------------------------------------------------
IO�ڵ�ƽ��ת������
-------------------------------------------------------*/
#if ECBM_GPIO_TOGGLE_EN
void gpio_toggle(u8 pin){
	/*---�����￪ʼ�������ڽ��IO�ڱ�š�---*/
	if(pin==Dxx)goto gpio_toggle_end;
	ecbm_port=pin&0xf0;
	ecbm_pin =ecbm_pin_mask[pin&0x0f];
	if((pin&0x0f)>7){
		#if SYS_ERROR_EN
		error_printf("gpio_toggle(<D%02X>);�����ڸ�IO\r\n",(u16)pin);
		#else
		while(1);
		#endif	
	}
	/*-------����������������ɡ�-------*/
	switch(ecbm_port){//���������ֱ�ӷ�ת��Ӧ��IO�ڡ�
		#if ECBM_GPIO0_EN
		case 0x00:P0^=ecbm_pin;break;
		#endif
		#if ECBM_GPIO1_EN
		case 0x10:P1^=ecbm_pin;break;
		#endif
		#if ECBM_GPIO2_EN
		case 0x20:P2^=ecbm_pin;break;
		#endif
		#if ECBM_GPIO3_EN
		case 0x30:P3^=ecbm_pin;break;
		#endif
		#if ECBM_GPIO4_EN
		case 0x40:P4^=ecbm_pin;break;
		#endif
		#if ECBM_GPIO5_EN
		case 0x50:P5^=ecbm_pin;break;
		#endif
		#if ECBM_GPIO6_EN
		case 0x60:P6^=ecbm_pin;break;
		#endif
		#if ECBM_GPIO7_EN
		case 0x70:P7^=ecbm_pin;break;
		#endif
		#if SYS_ERROR_EN
		default:error_printf("gpio_toggle(<D%02X>);�����ڸ�IO\r\n",(u16)pin);break;
		#else
		default:while(1);break;
		#endif	
	}
	gpio_toggle_end:;
}
#endif
/*�������۵�ר��**************************************************************/#endif
/*�������۵�ר��**********************����IO����ģ��****************************/#if 1
/*-------------------------------------------------------
IO�ڵ�ƽ���ٷ�ת������
-------------------------------------------------------*/
#if ECBM_GPIO_TOGGLE_FAST_EN
void gpio_toggle_fast(u8 port,u8 pin){
	switch(port){//������ķ�ת��������������������IO�����Ĵ��룬ʵ���Ƕδ���ǳ���ʱ��
		#if ECBM_GPIO0_EN
		case GPIO_P0:P0^=pin;break;
		#endif
		#if ECBM_GPIO1_EN
		case GPIO_P1:P1^=pin;break;
		#endif
		#if ECBM_GPIO2_EN
		case GPIO_P2:P2^=pin;break;
		#endif
		#if ECBM_GPIO3_EN
		case GPIO_P3:P3^=pin;break;
		#endif
		#if ECBM_GPIO4_EN
		case GPIO_P4:P4^=pin;break;
		#endif
		#if ECBM_GPIO5_EN
		case GPIO_P5:P5^=pin;break;
		#endif
		#if ECBM_GPIO6_EN
		case GPIO_P6:P6^=pin;break;
		#endif
		#if ECBM_GPIO7_EN
		case GPIO_P7:P7^=pin;break;
		#endif
		case GPIO_Px:break;
	}
}
#endif
/*-------------------------------------------------------
IO�ڵ�ƽ�������������
-------------------------------------------------------*/
#if ECBM_GPIO_OUT_FAST_EN
void gpio_out_fast   (u8 port,u8 pin,bit val){
	if(val){//������������������������������IO�����Ĵ��룬ʵ���Ƕδ���ǳ���ʱ��
		switch(port){
			#if ECBM_GPIO0_EN
			case GPIO_P0:P0|=pin;break;
			#endif
			#if ECBM_GPIO1_EN
			case GPIO_P1:P1|=pin;break;
			#endif
			#if ECBM_GPIO2_EN
			case GPIO_P2:P2|=pin;break;
			#endif
			#if ECBM_GPIO3_EN
			case GPIO_P3:P3|=pin;break;
			#endif
			#if ECBM_GPIO4_EN
			case GPIO_P4:P4|=pin;break;
			#endif
			#if ECBM_GPIO5_EN
			case GPIO_P5:P5|=pin;break;
			#endif
			#if ECBM_GPIO6_EN
			case GPIO_P6:P6|=pin;break;
			#endif
			#if ECBM_GPIO7_EN
			case GPIO_P7:P7|=pin;break;
			#endif
			case GPIO_Px:break;
		} 
	}else{
		switch(port){
			#if ECBM_GPIO0_EN
			case GPIO_P0:P0&=~pin;break;
			#endif
			#if ECBM_GPIO1_EN
			case GPIO_P1:P1&=~pin;break;
			#endif
			#if ECBM_GPIO2_EN
			case GPIO_P2:P2&=~pin;break;
			#endif
			#if ECBM_GPIO3_EN
			case GPIO_P3:P3&=~pin;break;
			#endif
			#if ECBM_GPIO4_EN
			case GPIO_P4:P4&=~pin;break;
			#endif
			#if ECBM_GPIO5_EN
			case GPIO_P5:P5&=~pin;break;
			#endif
			#if ECBM_GPIO6_EN
			case GPIO_P6:P6&=~pin;break;
			#endif
			#if ECBM_GPIO7_EN
			case GPIO_P7:P7&=~pin;break;
			#endif
			case GPIO_Px:break;
		} 
	}
}
#endif
/*-------------------------------------------------------
IO�ڵ�ƽ�������뺯����
-------------------------------------------------------*/
#if ECBM_GPIO_IN_FAST_EN
bit  gpio_in_fast    (u8 port,u8 pin){
	u8 val;
	switch(port){//����������뺯������������������IO�����Ĵ��룬ʵ���Ƕδ���ǳ���ʱ��
		#if ECBM_GPIO0_EN
		case GPIO_P0:val=P0;break;
		#endif
		#if ECBM_GPIO1_EN
		case GPIO_P1:val=P1;break;
		#endif
		#if ECBM_GPIO2_EN
		case GPIO_P2:val=P2;break;
		#endif
		#if ECBM_GPIO3_EN
		case GPIO_P3:val=P3;break;
		#endif
		#if ECBM_GPIO4_EN
		case GPIO_P4:val=P4;break;
		#endif
		#if ECBM_GPIO5_EN
		case GPIO_P5:val=P5;break;
		#endif
		#if ECBM_GPIO6_EN
		case GPIO_P6:val=P6;break;
		#endif
		#if ECBM_GPIO7_EN
		case GPIO_P7:val=P7;break;
		#endif
		case GPIO_Px:return 1;break;
	} 
	if(val&pin)return 1;
	else return 0;
}
#endif
/*�������۵�ר��**************************************************************/#endif
#endif
