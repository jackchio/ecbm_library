#include "fast_uart_reg.h"
/*--------------------------------------��������-----------------------------------*/
u8  fue_state          =0;  //���ڽ���״̬��������
u8  fue_reg_point      =0;  //�Ĵ���ָ�룬ָ��Ҫд��ļĴ�����
u8  fue_cmd_buf[16]    ={0};//ָ��λ��棬���ڼ��ᴮ���ж�ѹ����
u8  fue_cmd_wr_buf[16] ={0};//ָ���д״̬���λ��棬�����첽�����зֱ�ָ���Ƕ�����д��
u8  fue_cmd_start      =0;  //���λ���Ŀ�ʼָ�롣
u8  fue_cmd_end        =0;  //���λ���Ľ���ָ�롣
u16 fue_reg_temp       =0;  //д��Ĵ����Ļ��档
u16 fue_reg    [ECBM_FUE_MAX]={0};//�Ĵ������壬ֱ�Ӻ͹��ܹҹ���
u16 fue_reg_buf[ECBM_FUE_MAX]={0};//Ӱ�ӼĴ���������д����������������ţ���֤���ٴ��뱾�塣
/*------------------------------------��Դ��ͻ����---------------------------------*/
#if (ECBM_FUE_EEPROM_EN == 1) && (ECBM_EEPROM_EN == 0)
#error EEPROM����û��ʹ�ܣ���ر�FUE�ı��湦�ܻ��ߴ�Ƭ��EEPROMʹ�ܣ�
#endif
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
FUE���ܵĴ��ڶ�ȡ������
-------------------------------------------------------*/
void fue_in(u8 buf){
	switch(fue_state){
		case 0:{				//�ȴ���ʼ֡��
			if(buf=='['){		//��⵽��ʼ֡ʱ��
				fue_state=1;	//����һ��״̬��
				fue_reg_point=0;	//��ʼ���Ĵ�����ַ��
			}
		}break;
		case 1:{				//�ǼǼĴ�����ַ��
			if(buf==']'){		//����յ�����֡��
				fue_state=2;	//����һ��״̬��
			}else if((buf>='0')&&(buf<='9')){//����յ����֣�
				fue_reg_point*=10;			//�������֡�
				fue_reg_point+=buf-'0';
			}else if(buf=='['){//����ڱ�״̬�ٴ��յ���ʼ֡��ֻ������Ĵ�����ַ����
				fue_reg_point=0;	//��ʼ���Ĵ�����ַ��
			}else{				//�յ������ַ���
				fue_state=0;	//��ת�صȴ�̬��
			}
		}break;
		case 2:{				//�ȴ�����֡��
			if(buf=='='){		//���յ�����֡��
				fue_state=3;	//����һ��״̬��
				fue_reg_temp=0;		//��ʼ���Ĵ������ݻ��档
			}else if(buf=='['){//����յ���ʼ֡��
				fue_state=1;	//�ص��Ǽǵ�ַ̬��
				fue_reg_point=0;	//��ʼ���Ĵ�����ַ��
			}else{				//�յ������ַ���
				fue_state=0;	//��ת�صȴ�̬��
			}
		}break;
		case 3:{				//�ǼǼĴ������ݡ�
			if(buf=='?'){		//���յ���ȡָ�
				fue_cmd_buf[fue_cmd_end]=fue_reg_point;//��¼��ָ����С�
				fue_cmd_wr_buf[fue_cmd_end]=0;
				fue_cmd_end++;
				fue_cmd_end&=0x0f;
				fue_state=0;	
			}else if(buf=='['){//�������ʱ���յ���ʼ֡��
				fue_state=1;	//���˵��Ǽǵ�ַ��״̬��
				fue_reg_point=0;	//��ʼ���Ĵ�����ַ��
			}else if((buf=='x')||(buf=='X')){//
				fue_reg_temp=0;		//
				fue_state=4;	//
			}else if((buf>='0')&&(buf<='9')){	//����յ����֣�
				fue_reg_temp*=10;					//�������֡�
				fue_reg_temp+=buf-'0';
			}else if(buf=='.'){//����յ�����֡��
				fue_reg_buf[fue_reg_point]=fue_reg_temp;//д�뵽�Ĵ�����
				fue_cmd_buf[fue_cmd_end]=fue_reg_point;//��¼��ָ����С�
				fue_cmd_wr_buf[fue_cmd_end]=1;
				fue_cmd_end++;
				fue_cmd_end&=0x0f;
				fue_state=0;	
			}else{				//�յ������ַ���
				fue_state=0;	//��ת�صȴ�̬��
			}
		}break;
		case 4:{				//�ǼǼĴ�������(HEXģʽ)��
			if(buf=='?'){		//���յ���ȡָ�
				fue_cmd_buf[fue_cmd_end]=fue_reg_point;//��¼��ָ����С�
				fue_cmd_wr_buf[fue_cmd_end]=0;
				fue_cmd_end++;
				fue_cmd_end&=0x0f;
				fue_state=0;
			}else if(buf=='['){//�������ʱ���յ���ʼ֡��
				fue_state=1;	//���˵��Ǽǵ�ַ��״̬��
				fue_reg_point=0;	//��ʼ���Ĵ�����ַ��
			}else if((buf>='0')&&(buf<='9')){	//����յ����֣�
				fue_reg_temp*=16;					//�������֡�
				fue_reg_temp+=buf-'0';
			}else if((buf>='A')&&(buf<='F')){	//����յ����֣�
				fue_reg_temp*=16;					//�������֡�
				fue_reg_temp+=(buf-'A')+10;
			}else if((buf>='a')&&(buf<='f')){	//����յ����֣�
				fue_reg_temp*=16;					//�������֡�
				fue_reg_temp+=(buf-'a')+10;
			}else if(buf=='.'){//����յ�����֡��
				fue_reg_buf[fue_reg_point]=fue_reg_temp;//д�뵽�Ĵ�����
				fue_cmd_buf[fue_cmd_end]=fue_reg_point;//��¼��ָ����С�
				fue_cmd_wr_buf[fue_cmd_end]=1;
				fue_cmd_end++;
				fue_cmd_end&=0x0f;
				fue_state=0;	
			}else{				//�յ������ַ���
				fue_state=0;	//��ת�صȴ�̬��
			}
		}break;
	}
}
/*-------------------------------------------------------
FUE��У�Ժͷ��غ�����
-------------------------------------------------------*/
void fue_check(void){
	if(fue_cmd_start!=fue_cmd_end){//ֻ�ڻ��λ�����ͷβָ�벻һ�µ�ʱ�������ִ�С�
		if(fue_cmd_wr_buf[fue_cmd_start]){//�ж��ǲ���дָ�
			fue_cmd_wr_buf[fue_cmd_start]=0;//�ǵĻ�����������ִ�У������ָ�
			switch(fue_cmd_buf[fue_cmd_start]){//����ָ����жϸ���Ӧ�Ķ�����
				case 0:{//0�żĴ�������ǲ����ʵİٷ�֮һֵ��
					fue_reg[0]=fue_reg_buf[0];//��Ӱ�ӼĴ�����ֵд��Ĵ����У�
					uart_set_baud(ECBM_FUE_UART_ID,(u32)fue_reg[0]*100);//ͬʱ����100������ȷ�Ĳ����ʣ�Ȼ���޸Ĳ����ʡ�
				}break;
#if	ECBM_FUE_EEPROM_EN == 1
				case 1:{//1�żĴ����Ǵ����Ĵ������������ֵ��
					if(fue_reg_buf[1]==0xA55A){//������Ҫ��д��0xA55A�Ļ����ͻ�ѵ�ǰ���е����ö�����������
						eeprom_write_ex(0,(u8 *)fue_reg,ECBM_FUE_MAX*2);//�����ڲ�eepromд����������Ϣ��
					}
					if(fue_reg_buf[1]==0xF00F){//��Ҫ��д��0xF00F�Ļ����ͻ��ȡ�������Ϣ�滻��ǰ���е����á�
						eeprom_read_ex(0,(u8 *)fue_reg,ECBM_FUE_MAX*2);//�����ڲ�eeprom��������ȡ��Ϣ��
					}
				}break;
#endif
				default:{//����������Ĵ�������ֱ�Ӱ�Ӱ�ӼĴ�����ֵ���뱾��Ĵ�����
					fue_reg[fue_cmd_buf[fue_cmd_start]]=fue_reg_buf[fue_cmd_buf[fue_cmd_start]];
				}break;
			}
		}//��һ���Ƿ���ֵ���ܣ��ڲ�ѯָ���£����ؼĴ�����ֵ���鿴����дָ���£����ؼĴ�����ֵ��д����֤��
		uart_printf(ECBM_FUE_UART_ID,"[%03u]=%u.\r\n",(u16)fue_cmd_buf[fue_cmd_start],(u16)fue_reg[fue_cmd_buf[fue_cmd_start]]);
		fue_cmd_start++;//���λ����������ͷָ��++��
		fue_cmd_start&=0x0f;//�޶���16�ֽڡ�
	}
}
/*-------------------------------------------------------
FUE�ĳ�ʼ��������
-------------------------------------------------------*/
void fue_init(void){
#if	ECBM_FUE_EEPROM_EN == 1	
	u8 i;
#endif	
	u16 temp;
#if   ECBM_FUE_UART_ID == 1	
	temp=UART1_BAUD_RATE/100;//д�벨����Ĭ��ֵ��
#elif ECBM_FUE_UART_ID == 2
	temp=UART2_BAUD_RATE/100;//д�벨����Ĭ��ֵ��
#elif ECBM_FUE_UART_ID == 3
	temp=UART3_BAUD_RATE/100;//д�벨����Ĭ��ֵ��
#elif ECBM_FUE_UART_ID == 4
	temp=UART4_BAUD_RATE/100;//д�벨����Ĭ��ֵ��
#endif
	fue_reg[0]=temp;
#if	ECBM_FUE_EEPROM_EN == 1	
	eeprom_init();//��ʼ���ڲ���eeprom������STC���������
	eeprom_read_ex(0,(u8 *)fue_reg,ECBM_FUE_MAX*2);//��ȡ�����ֵ��
	if((fue_reg[0]==0xffff)||(fue_reg[0]!=temp)){//�������û�б���������߲������б仯
		for(i=1;i<ECBM_FUE_MAX;i++){//��ȫ����ʼ��Ϊ0��
			fue_reg[i]=0;
		}
		fue_reg[0]=temp;
		eeprom_write_ex(0,(u8 *)fue_reg,ECBM_FUE_MAX*2);//�ٽ���ʼ����ֵд�롣
	}
#endif
}
