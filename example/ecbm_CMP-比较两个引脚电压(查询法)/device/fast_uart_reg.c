#include "fast_uart_reg.h"
/*--------------------------------------变量定义-----------------------------------*/
u8  fue_state          =0;  //串口接收状态机变量。
u8  fue_reg_point      =0;  //寄存器指针，指向要写入的寄存器。
u8  fue_cmd_buf[16]    ={0};//指令环形缓存，用于减轻串口中断压力。
u8  fue_cmd_wr_buf[16] ={0};//指令读写状态环形缓存，用于异步处理中分辨指令是读还是写。
u8  fue_cmd_start      =0;  //环形缓存的开始指针。
u8  fue_cmd_end        =0;  //环形缓存的结束指针。
u16 fue_reg_temp       =0;  //写入寄存器的缓存。
u16 fue_reg    [ECBM_FUE_MAX]={0};//寄存器本体，直接和功能挂钩。
u16 fue_reg_buf[ECBM_FUE_MAX]={0};//影子寄存器，串口写入的数据先在这里存放，验证后再存入本体。
/*------------------------------------资源冲突警告---------------------------------*/
#if (ECBM_FUE_EEPROM_EN == 1) && (ECBM_EEPROM_EN == 0)
#error EEPROM功能没有使能，请关闭FUE的保存功能或者打开片内EEPROM使能！
#endif
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
FUE功能的串口读取函数。
-------------------------------------------------------*/
void fue_in(u8 buf){
	switch(fue_state){
		case 0:{				//等待开始帧。
			if(buf=='['){		//检测到开始帧时，
				fue_state=1;	//到下一个状态，
				fue_reg_point=0;	//初始化寄存器地址。
			}
		}break;
		case 1:{				//登记寄存器地址。
			if(buf==']'){		//如果收到结束帧，
				fue_state=2;	//到下一个状态。
			}else if((buf>='0')&&(buf<='9')){//如果收到数字，
				fue_reg_point*=10;			//接收数字。
				fue_reg_point+=buf-'0';
			}else if(buf=='['){//如果在本状态再次收到开始帧，只做清零寄存器地址处理。
				fue_reg_point=0;	//初始化寄存器地址。
			}else{				//收到意外字符，
				fue_state=0;	//跳转回等待态。
			}
		}break;
		case 2:{				//等待后续帧。
			if(buf=='='){		//接收到后续帧后，
				fue_state=3;	//到下一个状态。
				fue_reg_temp=0;		//初始化寄存器内容缓存。
			}else if(buf=='['){//如果收到开始帧，
				fue_state=1;	//回到登记地址态。
				fue_reg_point=0;	//初始化寄存器地址。
			}else{				//收到意外字符，
				fue_state=0;	//跳转回等待态。
			}
		}break;
		case 3:{				//登记寄存器内容。
			if(buf=='?'){		//接收到读取指令，
				fue_cmd_buf[fue_cmd_end]=fue_reg_point;//记录到指令缓存中。
				fue_cmd_wr_buf[fue_cmd_end]=0;
				fue_cmd_end++;
				fue_cmd_end&=0x0f;
				fue_state=0;	
			}else if(buf=='['){//如果在这时候收到开始帧，
				fue_state=1;	//回退到登记地址的状态。
				fue_reg_point=0;	//初始化寄存器地址。
			}else if((buf=='x')||(buf=='X')){//
				fue_reg_temp=0;		//
				fue_state=4;	//
			}else if((buf>='0')&&(buf<='9')){	//如果收到数字，
				fue_reg_temp*=10;					//接收数字。
				fue_reg_temp+=buf-'0';
			}else if(buf=='.'){//如果收到结束帧，
				fue_reg_buf[fue_reg_point]=fue_reg_temp;//写入到寄存器。
				fue_cmd_buf[fue_cmd_end]=fue_reg_point;//记录到指令缓存中。
				fue_cmd_wr_buf[fue_cmd_end]=1;
				fue_cmd_end++;
				fue_cmd_end&=0x0f;
				fue_state=0;	
			}else{				//收到意外字符，
				fue_state=0;	//跳转回等待态。
			}
		}break;
		case 4:{				//登记寄存器内容(HEX模式)。
			if(buf=='?'){		//接收到读取指令，
				fue_cmd_buf[fue_cmd_end]=fue_reg_point;//记录到指令缓存中。
				fue_cmd_wr_buf[fue_cmd_end]=0;
				fue_cmd_end++;
				fue_cmd_end&=0x0f;
				fue_state=0;
			}else if(buf=='['){//如果在这时候收到开始帧，
				fue_state=1;	//回退到登记地址的状态。
				fue_reg_point=0;	//初始化寄存器地址。
			}else if((buf>='0')&&(buf<='9')){	//如果收到数字，
				fue_reg_temp*=16;					//接收数字。
				fue_reg_temp+=buf-'0';
			}else if((buf>='A')&&(buf<='F')){	//如果收到数字，
				fue_reg_temp*=16;					//接收数字。
				fue_reg_temp+=(buf-'A')+10;
			}else if((buf>='a')&&(buf<='f')){	//如果收到数字，
				fue_reg_temp*=16;					//接收数字。
				fue_reg_temp+=(buf-'a')+10;
			}else if(buf=='.'){//如果收到结束帧，
				fue_reg_buf[fue_reg_point]=fue_reg_temp;//写入到寄存器。
				fue_cmd_buf[fue_cmd_end]=fue_reg_point;//记录到指令缓存中。
				fue_cmd_wr_buf[fue_cmd_end]=1;
				fue_cmd_end++;
				fue_cmd_end&=0x0f;
				fue_state=0;	
			}else{				//收到意外字符，
				fue_state=0;	//跳转回等待态。
			}
		}break;
	}
}
/*-------------------------------------------------------
FUE的校对和返回函数。
-------------------------------------------------------*/
void fue_check(void){
	if(fue_cmd_start!=fue_cmd_end){//只在环形缓存中头尾指针不一致的时候才往下执行。
		if(fue_cmd_wr_buf[fue_cmd_start]){//判断是不是写指令，
			fue_cmd_wr_buf[fue_cmd_start]=0;//是的话，就请往下执行，请清除指令。
			switch(fue_cmd_buf[fue_cmd_start]){//根据指令缓存判断该响应的动作。
				case 0:{//0号寄存器存的是波特率的百分之一值。
					fue_reg[0]=fue_reg_buf[0];//将影子寄存器的值写入寄存器中，
					uart_set_baud(ECBM_FUE_UART_ID,(u32)fue_reg[0]*100);//同时扩大100倍成正确的波特率，然后修改波特率。
				}break;
#if	ECBM_FUE_EEPROM_EN == 1
				case 1:{//1号寄存器是触发寄存器，不会存入值。
					if(fue_reg_buf[1]==0xA55A){//但是你要是写入0xA55A的话，就会把当前所有的设置都保存下来。
						eeprom_write_ex(0,(u8 *)fue_reg,ECBM_FUE_MAX*2);//调用内部eeprom写函数保存信息。
					}
					if(fue_reg_buf[1]==0xF00F){//你要是写入0xF00F的话，就会读取保存的信息替换当前所有的设置。
						eeprom_read_ex(0,(u8 *)fue_reg,ECBM_FUE_MAX*2);//调用内部eeprom读函数读取信息。
					}
				}break;
#endif
				default:{//如果是其他寄存器，就直接把影子寄存器的值存入本体寄存器。
					fue_reg[fue_cmd_buf[fue_cmd_start]]=fue_reg_buf[fue_cmd_buf[fue_cmd_start]];
				}break;
			}
		}//下一句是返回值功能，在查询指令下，返回寄存器的值供查看。在写指令下，返回寄存器的值供写入验证。
		uart_printf(ECBM_FUE_UART_ID,"[%03u]=%u.\r\n",(u16)fue_cmd_buf[fue_cmd_start],(u16)fue_reg[fue_cmd_buf[fue_cmd_start]]);
		fue_cmd_start++;//环形缓存的做法，头指针++。
		fue_cmd_start&=0x0f;//限定在16字节。
	}
}
/*-------------------------------------------------------
FUE的初始化函数。
-------------------------------------------------------*/
void fue_init(void){
#if	ECBM_FUE_EEPROM_EN == 1	
	u8 i;
#endif	
	u16 temp;
#if   ECBM_FUE_UART_ID == 1	
	temp=UART1_BAUD_RATE/100;//写入波特率默认值。
#elif ECBM_FUE_UART_ID == 2
	temp=UART2_BAUD_RATE/100;//写入波特率默认值。
#elif ECBM_FUE_UART_ID == 3
	temp=UART3_BAUD_RATE/100;//写入波特率默认值。
#elif ECBM_FUE_UART_ID == 4
	temp=UART4_BAUD_RATE/100;//写入波特率默认值。
#endif
	fue_reg[0]=temp;
#if	ECBM_FUE_EEPROM_EN == 1	
	eeprom_init();//初始化内部的eeprom，现在STC都有这个。
	eeprom_read_ex(0,(u8 *)fue_reg,ECBM_FUE_MAX*2);//读取保存的值。
	if((fue_reg[0]==0xffff)||(fue_reg[0]!=temp)){//如果从来没有保存过，或者波特率有变化
		for(i=1;i<ECBM_FUE_MAX;i++){//就全部初始化为0。
			fue_reg[i]=0;
		}
		fue_reg[0]=temp;
		eeprom_write_ex(0,(u8 *)fue_reg,ECBM_FUE_MAX*2);//再将初始化的值写入。
	}
#endif
}
