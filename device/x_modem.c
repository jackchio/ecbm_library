#include "x_modem.h"
/*--------------------------------------��������-----------------------------------*/
u8 x_modem_data[128];		//�������ݻ��档
u8 x_modem_sum			=0;	//У��͡�
u8 x_modem_pack			=0;	//���ݰ���š�
u8 x_modem_status		=0;	//Xmodem״̬��״̬��
u8 x_modem_count		=0;	//�������ݼ�����
u8 x_modem_timer_count	=0;	//��ʱ������
u8 x_modem_timer_max	=0;	//��ʱ���ֵ��
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
���ݽ��պ�����
-------------------------------------------------------*/
void x_modem_receive(u8 x_modem_buf){
	switch(x_modem_status){
		case X_MODEM_READY:{//����״̬��
			if(x_modem_buf==0x01){					//����յ�SOH�ֶΣ�
				x_modem_status=X_MODEM_READ_PACK;	//������ȡ����š�
				x_modem_sum=x_modem_buf;			//������Ϳ�ʼ����У��͡�
				x_modem_timer_count=0;				//���ʱ�������
			}
			if(x_modem_buf==0x04){					//����յ�EOT�ֶΣ�
				x_modem_status=X_MODEM_FINISH;		//��������״̬��
				x_modem_timer_count=0;				//���ʱ�������
			}
			if(x_modem_buf==0x18){					//����յ�CAN�ֶΣ�
				x_modem_status=X_MODEM_STOP;		//����ֹͣ״̬��
				x_modem_timer_count=0;				//���ʱ�������
			}
		}break;
		case X_MODEM_READ_PACK:{//��ȡ����š�
			x_modem_pack=x_modem_buf;				//����ǰ�����ݰ���Ŵ��š�
			x_modem_sum+=x_modem_buf;				//����У��͡�
			x_modem_status=X_MODEM_CHECK_PACK;		//����ȷ�ϰ���š�
			x_modem_timer_count=0;					//���ʱ�������
		}break;
		case X_MODEM_CHECK_PACK:{//ȷ�ϰ���š�
			if(x_modem_pack==(~x_modem_buf)){		//�����ŵķ�����ȷ��
				x_modem_status=X_MODEM_READ_MODE;	//����������ģʽ��
				x_modem_sum+=x_modem_buf;			//����У��͡�
				x_modem_timer_count=0;				//���ʱ�������
				x_modem_count=0;					//���û���ָ�롣
			}else{									//����ȷ˵������֡ͷ��
				x_modem_status=X_MODEM_ERROR;		//��������̬��
			}			
		}break;
		case X_MODEM_READ_MODE:{//��������ģʽ��
			x_modem_timer_count=0;					//���ʱ�������
			x_modem_data[x_modem_count]=x_modem_buf;//���������뻺�档
			x_modem_sum+=x_modem_buf;				//����У��͡�
			x_modem_count++;						//����ָ���һ��
			if(x_modem_count>=128){					//���������128������
				x_modem_status=X_MODEM_CHECK_DATA;	//����������У�顣
			}			
		}break;
		case X_MODEM_CHECK_DATA:{//���У��͡�
			x_modem_timer_count=0;					//���ʱ�������
			if(x_modem_buf==x_modem_sum){			//���У����ȷ��
				x_modem_status=X_MODEM_DOING;		//�������״̬��
			}else{									//���У�鲻��ȷ��
				x_modem_status=X_MODEM_AGAIN;		//�����ط�״̬��
			}					
		}break;
	}
}
/*-------------------------------------------------------
���ݴ�������
-------------------------------------------------------*/
void x_modem_run(void){		//��������������ѭ���С�
	switch(x_modem_status){
		case X_MODEM_AGAIN:{//�ط�״̬��
			x_modem_timer_count=0;			//���ʱ�������
			x_modem_send(0x15);				//����NACK��֪ͨ��λ���ط���
			x_modem_status=X_MODEM_READY;	//�ָ�������̬��
		}break;
		case X_MODEM_DOING:{//���״̬��
			x_modem_do();					//���иú��������������ơ�
			x_modem_timer_count=0;			//���ʱ�������
			x_modem_send(0x06);				//����ACK��֪ͨ��λ������һ����
			x_modem_status=X_MODEM_READY;	//�ָ�������̬��
		}break;
		case X_MODEM_FINISH:{//����״̬��
			x_modem_timer_count=0;			//���ʱ�������
			x_modem_send(0x06);				//����ACK��֪ͨ��λ������EOT�ˡ�
			x_modem_status=X_MODEM_STOP;	//��ֹͣ״̬��
			x_modem_done();
		}break;
	}
}
/*-------------------------------------------------------
���俪ʼ������
-------------------------------------------------------*/
void x_modem_start(void){	//�������������ڿ�ʼ�������ݡ�
	x_modem_timer_count=0;			//���ʱ�������
	x_modem_pack=0;					//�������š�
	x_modem_status=X_MODEM_READY;	//ת������̬��
	x_modem_send(0x15);				//����NACK��֪ͨ��λ����ʼͨ�š�
}
/*-------------------------------------------------------
��ʱ������
-------------------------------------------------------*/
void x_modem_timer(void){	//��ʱ�亯�������ڶ�ʱ���ж��
	if(x_modem_timer_count<x_modem_timer_max){	//���ʱ�仹û�ܵ���ʱ��
		x_modem_timer_count++;					//�Ͳ��ϵļ�ʱ�䡣
	}else{										//�����ʱ�ˣ�
		x_modem_status=X_MODEM_STOP;			//���л���ֹͣ״̬��
	}
}
/*-------------------------------------------------------
��ʼ��������
-------------------------------------------------------*/
void x_modem_init(u8 max){	//��ʼ��������������ѭ��ǰ��
	u8 i;
	x_modem_timer_max=max;		//���ó�ʱʱ�䡣
	x_modem_status=X_MODEM_STOP;//Ĭ��ֹ̬ͣ��
	for(i=0;i<128;i++){			//�����������
		x_modem_data[i]=0;
	}
	x_modem_sum=0;				//����У��͡�
	x_modem_pack=0;				//�������š�
	x_modem_count=0;			//�������ݼ�������
	x_modem_timer_count=0;		//����ʱ���������
}