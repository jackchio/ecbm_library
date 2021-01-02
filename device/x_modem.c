#include "x_modem.h"
/*--------------------------------------变量定义-----------------------------------*/
u8 x_modem_data[128];		//接收数据缓存。
u8 x_modem_sum			=0;	//校验和。
u8 x_modem_pack			=0;	//数据包编号。
u8 x_modem_status		=0;	//Xmodem状态机状态。
u8 x_modem_count		=0;	//接收数据计数。
u8 x_modem_timer_count	=0;	//超时计数。
u8 x_modem_timer_max	=0;	//超时最大值。
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
数据接收函数。
-------------------------------------------------------*/
void x_modem_receive(u8 x_modem_buf){
	switch(x_modem_status){
		case X_MODEM_READY:{//就绪状态。
			if(x_modem_buf==0x01){					//如果收到SOH字段，
				x_modem_status=X_MODEM_READ_PACK;	//跳到读取包编号。
				x_modem_sum=x_modem_buf;			//从这里就开始计算校验和。
				x_modem_timer_count=0;				//清除时间计数。
			}
			if(x_modem_buf==0x04){					//如果收到EOT字段，
				x_modem_status=X_MODEM_FINISH;		//跳到结束状态。
				x_modem_timer_count=0;				//清除时间计数。
			}
			if(x_modem_buf==0x18){					//如果收到CAN字段，
				x_modem_status=X_MODEM_STOP;		//跳到停止状态。
				x_modem_timer_count=0;				//清除时间计数。
			}
		}break;
		case X_MODEM_READ_PACK:{//读取包编号。
			x_modem_pack=x_modem_buf;				//将当前的数据包编号存着。
			x_modem_sum+=x_modem_buf;				//计算校验和。
			x_modem_status=X_MODEM_CHECK_PACK;		//跳到确认包编号。
			x_modem_timer_count=0;					//清除时间计数。
		}break;
		case X_MODEM_CHECK_PACK:{//确认包编号。
			if(x_modem_pack==(~x_modem_buf)){		//如果编号的反码正确。
				x_modem_status=X_MODEM_READ_MODE;	//跳到读数据模式。
				x_modem_sum+=x_modem_buf;			//计算校验和。
				x_modem_timer_count=0;				//清除时间计数。
				x_modem_count=0;					//重置缓存指针。
			}else{									//不正确说明不是帧头，
				x_modem_status=X_MODEM_ERROR;		//跳到错误态。
			}			
		}break;
		case X_MODEM_READ_MODE:{//接收数据模式。
			x_modem_timer_count=0;					//清除时间计数。
			x_modem_data[x_modem_count]=x_modem_buf;//将数据填入缓存。
			x_modem_sum+=x_modem_buf;				//计算校验和。
			x_modem_count++;						//缓存指针加一。
			if(x_modem_count>=128){					//如果接收了128个数据
				x_modem_status=X_MODEM_CHECK_DATA;	//进入检测数据校验。
			}			
		}break;
		case X_MODEM_CHECK_DATA:{//检查校验和。
			x_modem_timer_count=0;					//清除时间计数。
			if(x_modem_buf==x_modem_sum){			//如果校验正确，
				x_modem_status=X_MODEM_DOING;		//跳到完成状态。
			}else{									//如果校验不正确，
				x_modem_status=X_MODEM_AGAIN;		//跳到重发状态。
			}					
		}break;
	}
}
/*-------------------------------------------------------
数据处理函数。
-------------------------------------------------------*/
void x_modem_run(void){		//处理函数，放在主循环中。
	switch(x_modem_status){
		case X_MODEM_AGAIN:{//重发状态。
			x_modem_timer_count=0;			//清除时间计数。
			x_modem_send(0x15);				//发送NACK，通知上位机重发。
			x_modem_status=X_MODEM_READY;	//恢复到就绪态。
		}break;
		case X_MODEM_DOING:{//完成状态。
			x_modem_do();					//运行该函数，请自行完善。
			x_modem_timer_count=0;			//清除时间计数。
			x_modem_send(0x06);				//发送ACK，通知上位机发下一包。
			x_modem_status=X_MODEM_READY;	//恢复到就绪态。
		}break;
		case X_MODEM_FINISH:{//结束状态。
			x_modem_timer_count=0;			//清除时间计数。
			x_modem_send(0x06);				//发送ACK，通知上位机接收EOT了。
			x_modem_status=X_MODEM_STOP;	//到停止状态。
			x_modem_done();
		}break;
	}
}
/*-------------------------------------------------------
传输开始函数。
-------------------------------------------------------*/
void x_modem_start(void){	//开启函数，用于开始传输数据。
	x_modem_timer_count=0;			//清除时间计数。
	x_modem_pack=0;					//清除包编号。
	x_modem_status=X_MODEM_READY;	//转到就绪态。
	x_modem_send(0x15);				//发送NACK，通知上位机开始通信。
}
/*-------------------------------------------------------
计时函数。
-------------------------------------------------------*/
void x_modem_timer(void){	//跑时间函数，放在定时器中断里。
	if(x_modem_timer_count<x_modem_timer_max){	//如果时间还没跑到超时，
		x_modem_timer_count++;					//就不断的加时间。
	}else{										//如果超时了，
		x_modem_status=X_MODEM_STOP;			//就切换到停止状态。
	}
}
/*-------------------------------------------------------
初始化函数。
-------------------------------------------------------*/
void x_modem_init(u8 max){	//初始化函数，放在主循环前。
	u8 i;
	x_modem_timer_max=max;		//设置超时时间。
	x_modem_status=X_MODEM_STOP;//默认停止态。
	for(i=0;i<128;i++){			//清除缓存区。
		x_modem_data[i]=0;
	}
	x_modem_sum=0;				//清零校验和。
	x_modem_pack=0;				//清除包编号。
	x_modem_count=0;			//清零数据计数器。
	x_modem_timer_count=0;		//清零时间计数器。
}