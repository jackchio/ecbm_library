#include "ecbm_core.h"
#if ECBM_GPIO_EN
/*--------------------------------------程序定义-----------------------------------*/
/*程序区折叠专用************************IO设置模块******************************/#if 1
/*-------------------------------------------------------
IO口上拉电阻配置函数。
-------------------------------------------------------*/
#if ECBM_GPIO_UPPULL_EN
void gpio_uppull(u8 pin,bit en){
	u8 io_port,io_pin;
	/*---从这里开始，都是在解读IO口编号。---*/
	if(pin==Dxx)goto gpio_uppull_end;
	io_port=pin&0xf0;
	io_pin=0x01<<(pin&0x0f);
	if((pin&0x0f)>7){
		#if SYS_ERROR_EN
		error_printf("gpio_uppull(<D%02X>,%d);不存在该IO\r\n",(u16)pin,(u16)en);
		#else
		while(1);
		#endif	
	}
	/*-------到这里结束，解读完成。-------*/
	if(en){//如果是使能，则将对应的IO配置上拉电阻。
		switch(io_port){
			#if ECBM_GPIO0_EN
			case 0x00:P0PU|=io_pin;break;
			#endif
			#if ECBM_GPIO1_EN
			case 0x10:P1PU|=io_pin;break;
			#endif
			#if ECBM_GPIO2_EN
			case 0x20:P2PU|=io_pin;break;
			#endif
			#if ECBM_GPIO3_EN
			case 0x30:P3PU|=io_pin;break;
			#endif
			#if ECBM_GPIO4_EN
			case 0x40:P4PU|=io_pin;break;
			#endif
			#if ECBM_GPIO5_EN
			case 0x50:P5PU|=io_pin;break;
			#endif
			#if ECBM_GPIO6_EN
			case 0x60:P6PU|=io_pin;break;
			#endif
			#if ECBM_GPIO7_EN
			case 0x70:P7PU|=io_pin;break;
			#endif
			#if SYS_ERROR_EN
			default:error_printf("gpio_uppull(<D%02X>,1);不存在该IO\r\n",(u16)pin);break;
			#else
			default:while(1);break;
			#endif
		}
	}else{//如果是失能，则将对应的IO取消上拉电阻。
		switch(io_port){
			#if ECBM_GPIO0_EN
			case 0x00:P0PU&=~io_pin;break;
			#endif
			#if ECBM_GPIO1_EN
			case 0x10:P1PU&=~io_pin;break;
			#endif
			#if ECBM_GPIO2_EN
			case 0x20:P2PU&=~io_pin;break;
			#endif
			#if ECBM_GPIO3_EN
			case 0x30:P3PU&=~io_pin;break;
			#endif
			#if ECBM_GPIO4_EN
			case 0x40:P4PU&=~io_pin;break;
			#endif
			#if ECBM_GPIO5_EN
			case 0x50:P5PU&=~io_pin;break;
			#endif
			#if ECBM_GPIO6_EN
			case 0x60:P6PU&=~io_pin;break;
			#endif
			#if ECBM_GPIO7_EN
			case 0x70:P7PU&=~io_pin;break;
			#endif
			#if SYS_ERROR_EN
			default:error_printf("gpio_uppull(<D%02X>,0);不存在该IO\r\n",(u16)pin);break;
			#else
			default:while(1);break;
			#endif
		}
	}
	gpio_uppull_end:;
}
#endif
/*-------------------------------------------------------
设置IO口工作模式函数。
-------------------------------------------------------*/
#if ECBM_GPIO_MODE_EN
void gpio_mode(u8 pin,u8 mode){
	u8 io_port,io_pin;
	/*---从这里开始，都是在解读IO口编号。---*/
	if(pin==Dxx)goto gpio_mode_end;
	io_port=pin&0xf0;
	io_pin=0x01<<(pin&0x0f);
	if((pin&0x0f)>7){
		#if SYS_ERROR_EN
		error_printf("gpio_mode(<D%02X>,%d);不存在该IO\r\n",(u16)pin,(u16)mode);
		#else
		while(1);
		#endif	
	}
	switch(io_port){
		#if ECBM_GPIO0_EN
		case 0x00:io_port=GPIO_P0;break;
		#endif
		#if ECBM_GPIO1_EN
		case 0x10:io_port=GPIO_P1;break;
		#endif
		#if ECBM_GPIO2_EN
		case 0x20:io_port=GPIO_P2;break;
		#endif
		#if ECBM_GPIO3_EN
		case 0x30:io_port=GPIO_P3;break;
		#endif
		#if ECBM_GPIO4_EN
		case 0x40:io_port=GPIO_P4;break;
		#endif
		#if ECBM_GPIO5_EN
		case 0x50:io_port=GPIO_P5;break;
		#endif
		#if ECBM_GPIO6_EN
		case 0x60:io_port=GPIO_P6;break;
		#endif
		#if ECBM_GPIO7_EN
		case 0x70:io_port=GPIO_P7;break;
		#endif
		#if SYS_ERROR_EN
		default:error_printf("gpio_mode(<D%02X>,%d);不存在该IO\r\n",(u16)pin,(u16)mode);break;
		#else
		default:while(1);break;
		#endif
	}
	/*-------到这里结束，解读完成。-------*/
	if(mode>3){
		#if SYS_ERROR_EN
		error_printf("gpio_mode(D%02X,<%d>);不存在该模式\r\n",(u16)pin,(u16)mode);
		#else
		while(1);
		#endif
	}	
	#if ECBM_GPIO0_EN
	if(io_port==GPIO_P0){//根据输入参数来设定不同的IO配置，下同。
		if(mode==GPIO_PU){P0M1&=~io_pin;P0M0&=~io_pin;}
		if(mode==GPIO_HZ){P0M1|= io_pin;P0M0&=~io_pin;}
		if(mode==GPIO_OD){P0M1|= io_pin;P0M0|= io_pin;}
		if(mode==GPIO_PP){P0M1&=~io_pin;P0M0|= io_pin;}
	}
	#endif
	#if ECBM_GPIO1_EN
	if(io_port==GPIO_P1){
		if(mode==GPIO_PU){P1M1&=~io_pin;P1M0&=~io_pin;}
		if(mode==GPIO_HZ){P1M1|= io_pin;P1M0&=~io_pin;}
		if(mode==GPIO_OD){P1M1|= io_pin;P1M0|= io_pin;}
		if(mode==GPIO_PP){P1M1&=~io_pin;P1M0|= io_pin;}
	}
	#endif
	#if ECBM_GPIO2_EN
	if(io_port==GPIO_P2){
		if(mode==GPIO_PU){P2M1&=~io_pin;P2M0&=~io_pin;}
		if(mode==GPIO_HZ){P2M1|= io_pin;P2M0&=~io_pin;}
		if(mode==GPIO_OD){P2M1|= io_pin;P2M0|= io_pin;}
		if(mode==GPIO_PP){P2M1&=~io_pin;P2M0|= io_pin;}
	}	
	#endif
	#if ECBM_GPIO3_EN
	if(io_port==GPIO_P3){
		if(mode==GPIO_PU){P3M1&=~io_pin;P3M0&=~io_pin;}
		if(mode==GPIO_HZ){P3M1|= io_pin;P3M0&=~io_pin;}
		if(mode==GPIO_OD){P3M1|= io_pin;P3M0|= io_pin;}
		if(mode==GPIO_PP){P3M1&=~io_pin;P3M0|= io_pin;}
	}
	#endif
	#if ECBM_GPIO4_EN
	if(io_port==GPIO_P4){
		if(mode==GPIO_PU){P4M1&=~io_pin;P4M0&=~io_pin;}
		if(mode==GPIO_HZ){P4M1|= io_pin;P4M0&=~io_pin;}
		if(mode==GPIO_OD){P4M1|= io_pin;P4M0|= io_pin;}
		if(mode==GPIO_PP){P4M1&=~io_pin;P4M0|= io_pin;}
	}
	#endif
	#if ECBM_GPIO5_EN
	if(io_port==GPIO_P5){
		if(mode==GPIO_PU){P5M1&=~io_pin;P5M0&=~io_pin;}
		if(mode==GPIO_HZ){P5M1|= io_pin;P5M0&=~io_pin;}
		if(mode==GPIO_OD){P5M1|= io_pin;P5M0|= io_pin;}
		if(mode==GPIO_PP){P5M1&=~io_pin;P5M0|= io_pin;}
	}	
	#endif
	#if ECBM_GPIO6_EN
	if(io_port==GPIO_P6){
		if(mode==GPIO_PU){P6M1&=~io_pin;P6M0&=~io_pin;}
		if(mode==GPIO_HZ){P6M1|= io_pin;P6M0&=~io_pin;}
		if(mode==GPIO_OD){P6M1|= io_pin;P6M0|= io_pin;}
		if(mode==GPIO_PP){P6M1&=~io_pin;P6M0|= io_pin;}
	}
	#endif
	#if ECBM_GPIO7_EN
	if(io_port==GPIO_P7){
		if(mode==GPIO_PU){P7M1&=~io_pin;P7M0&=~io_pin;}
		if(mode==GPIO_HZ){P7M1|= io_pin;P7M0&=~io_pin;}
		if(mode==GPIO_OD){P7M1|= io_pin;P7M0|= io_pin;}
		if(mode==GPIO_PP){P7M1&=~io_pin;P7M0|= io_pin;}
	}	
	#endif
	gpio_mode_end:;
}
#endif
/*程序区折叠专用**************************************************************/#endif
/*程序区折叠专用**********************普通IO操作模块****************************/#if 1
/*-------------------------------------------------------
P口写入函数，直接写入8位数据到某个P口上。
-------------------------------------------------------*/
#if ECBM_GPIO_WRITE_EN
void gpio_write(u8 port,u8 dat){
	switch(port){//通过判断P口编号进入不同的分支。
		#if ECBM_GPIO0_EN
		case GPIO_P0:P0=dat;break;//将数据发送到对应的P口，下同。
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
		default:error_printf("gpio_write(<%d>,%d);不存在该P口\r\n",(u16)port,(u16)dat);break;
		#else
		default:while(1);break;
		#endif
	}
}
#endif
/*-------------------------------------------------------
P口读出函数，将整个P口的值一次性读出(并口)。
-------------------------------------------------------*/
#if ECBM_GPIO_READ_EN
u8   gpio_read(u8 port){
	switch(port){//通过判断P口编号进入不同的分支。
		#if ECBM_GPIO0_EN
		case GPIO_P0:return P0;break;//将对应P口的值返回，下同。
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
		default:error_printf("gpio_read(<P%d>);不存在该P口\r\n",(u16)port);break;
		#else
		default:while(1);break;
		#endif
	}
	return 0xFF;
}
#endif
/*-------------------------------------------------------
IO口输出函数。
-------------------------------------------------------*/
#if ECBM_GPIO_OUT_EN
void gpio_out(u8 pin,bit value){
	u8 port,io_pin;
	/*---从这里开始，都是在解读IO口编号。---*/
	if(pin==Dxx)goto gpio_out_end;
	port=pin&0xf0;
	io_pin=0x01<<(pin&0x0f);
	if((pin&0x0f)>7){
		#if SYS_ERROR_EN
		error_printf("gpio_out(<D%02X>,%d);不存在该IO\r\n",(u16)pin,(u16)value);
		#else
		while(1);
		#endif	
	}
	/*-------到这里结束，解读完成。-------*/
	if(value){//用或运算实现输出高电平，速度会快一些。
		switch(port){
			#if ECBM_GPIO0_EN
			case 0x00:P0|=io_pin;break;
			#endif
			#if ECBM_GPIO1_EN
			case 0x10:P1|=io_pin;break;
			#endif
			#if ECBM_GPIO2_EN
			case 0x20:P2|=io_pin;break;
			#endif
			#if ECBM_GPIO3_EN
			case 0x30:P3|=io_pin;break;
			#endif
			#if ECBM_GPIO4_EN
			case 0x40:P4|=io_pin;break;
			#endif
			#if ECBM_GPIO5_EN
			case 0x50:P5|=io_pin;break;
			#endif
			#if ECBM_GPIO6_EN
			case 0x60:P6|=io_pin;break;
			#endif
			#if ECBM_GPIO7_EN
			case 0x70:P7|=io_pin;break;
			#endif
			#if SYS_ERROR_EN
			default:error_printf("gpio_out(<D%02X>,1);不存在该IO\r\n",(u16)pin);break;
			#else
			default:while(1);break;
			#endif
		}
	}else{//用与运算实现输出低电平，速度会快一些。
		switch(port){
			#if ECBM_GPIO0_EN
			case 0x00:P0&=~io_pin;break;
			#endif
			#if ECBM_GPIO1_EN
			case 0x10:P1&=~io_pin;break;
			#endif
			#if ECBM_GPIO2_EN
			case 0x20:P2&=~io_pin;break;
			#endif
			#if ECBM_GPIO3_EN
			case 0x30:P3&=~io_pin;break;
			#endif
			#if ECBM_GPIO4_EN
			case 0x40:P4&=~io_pin;break;
			#endif
			#if ECBM_GPIO5_EN
			case 0x50:P5&=~io_pin;break;
			#endif
			#if ECBM_GPIO6_EN
			case 0x60:P6&=~io_pin;break;
			#endif
			#if ECBM_GPIO7_EN
			case 0x70:P7&=~io_pin;break;
			#endif
			#if SYS_ERROR_EN
			default:error_printf("gpio_out(<D%02X>,0);不存在该IO\r\n",(u16)pin);break;
			#else
			default:while(1);break;
			#endif
		}		
	}
	gpio_out_end:;
}
#endif
/*-------------------------------------------------------
IO口输入函数。
-------------------------------------------------------*/
#if ECBM_GPIO_IN_EN
bit  gpio_in(u8 pin){
	u8 port,io_pin,value;
	/*---从这里开始，都是在解读IO口编号。---*/
	if(pin==Dxx)return 0;
	port=pin&0xf0;
	io_pin=0x01<<(pin&0x0f);
	if((pin&0x0f)>7){
		#if SYS_ERROR_EN
		error_printf("gpio_in(<D%02X>);不存在该IO\r\n",(u16)pin);
		#else
		while(1);
		#endif	
	}
	/*-------到这里结束，解读完成。-------*/
	switch(port){//直接读取整个P口的数据
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
		default:error_printf("gpio_in(<D%02X>);不存在该IO\r\n",(u16)pin);break;
		#else
		default:while(1);break;
		#endif	
	}
	if(value&io_pin)return 1;//通过与运算来获取某一位的电平状态。
	else return 0;
}
#endif
/*程序区折叠专用**************************************************************/#endif
/*程序区折叠专用**********************快速IO操作模块****************************/#if 1
/*-------------------------------------------------------
IO口电平翻转函数。
-------------------------------------------------------*/
#if ECBM_GPIO_TOGGLE_EN
void gpio_toggle(u8 pin){
	u8 port,io_pin;
	/*---从这里开始，都是在解读IO口编号。---*/
	if(pin==Dxx)goto gpio_toggle_end;
	port=pin&0xf0;
	io_pin=0x01<<(pin&0x0f);
	if((pin&0x0f)>7){
		#if SYS_ERROR_EN
		error_printf("gpio_toggle(<D%02X>);不存在该IO\r\n",(u16)pin);
		#else
		while(1);
		#endif	
	}
	/*-------到这里结束，解读完成。-------*/
	switch(port){//用异或运算直接翻转对应的IO口。
		#if ECBM_GPIO0_EN
		case 0x00:P0^=io_pin;break;
		#endif
		#if ECBM_GPIO1_EN
		case 0x10:P1^=io_pin;break;
		#endif
		#if ECBM_GPIO2_EN
		case 0x20:P2^=io_pin;break;
		#endif
		#if ECBM_GPIO3_EN
		case 0x30:P3^=io_pin;break;
		#endif
		#if ECBM_GPIO4_EN
		case 0x40:P4^=io_pin;break;
		#endif
		#if ECBM_GPIO5_EN
		case 0x50:P5^=io_pin;break;
		#endif
		#if ECBM_GPIO6_EN
		case 0x60:P6^=io_pin;break;
		#endif
		#if ECBM_GPIO7_EN
		case 0x70:P7^=io_pin;break;
		#endif
		#if SYS_ERROR_EN
		default:error_printf("gpio_toggle(<D%02X>);不存在该IO\r\n",(u16)pin);break;
		#else
		default:while(1);break;
		#endif	
	}
	gpio_toggle_end:;
}
#endif
/*-------------------------------------------------------
IO口电平快速翻转函数。
-------------------------------------------------------*/
#if ECBM_GPIO_TOGGLE_FAST_EN
void gpio_toggle_fast(u8 port,u8 pin){
	switch(port){//与上面的翻转函数比起来，就是少了IO解析的代码，实测那段代码非常耗时。
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
IO口电平快速输出函数。
-------------------------------------------------------*/
#if ECBM_GPIO_OUT_FAST_EN
void gpio_out_fast   (u8 port,u8 pin,bit val){
	if(val){//与上面的输出函数比起来，就是少了IO解析的代码，实测那段代码非常耗时。
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
IO口电平快速输入函数。
-------------------------------------------------------*/
#if ECBM_GPIO_IN_FAST_EN
bit  gpio_in_fast    (u8 port,u8 pin){
	u8 val;
	switch(port){//与上面的输入函数比起来，就是少了IO解析的代码，实测那段代码非常耗时。
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
/*程序区折叠专用**************************************************************/#endif
#endif
