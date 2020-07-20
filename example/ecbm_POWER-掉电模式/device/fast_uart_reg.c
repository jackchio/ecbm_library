#include "fast_uart_reg.h"
/*--------------------------------------��������-----------------------------------*/
fur_u8  fur_bit              =0;  //�Ĵ���λ����־��
fur_u8  fur_flag             =0;  //�Ĵ���״̬��
fur_u8  fur_state            =0;  //���ڽ���״̬��������
fur_u8  fur_cmd_start        =0;  //���λ���Ŀ�ʼָ�롣
fur_u8  fur_cmd_end          =0;  //���λ���Ľ���ָ�롣
fur_u8  fur_cmd_wr_buf[16]   ={0};//ָ���д״̬���λ��棬�����첽�����зֱ�ָ���Ƕ�����д��
fur_u16 fur_cmd_buf   [16]   ={0};//ָ��λ��棬���ڼ��ᴮ���ж�ѹ����
fur_u16 fur_reg_point        =0;  //�Ĵ���ָ�룬ָ��Ҫд��ļĴ�����
fur_u16 fur_reg_temp         =0;  //д��Ĵ����Ļ��档
fur_u16 fur_reg_buf   [16]   ={0};//Ӱ�ӼĴ���������д����������������ţ���֤���ٴ��뱾�塣
fur_u16 fur_reg[ECBM_FUR_REG_MAX+FUR_REG_OFFSET];//�Ĵ������壬ֱ�Ӻ͹��ܹҹ���
fur_u16 fur_addr                 ;//����ģʽ�£�������֤��ַ����ֵ��
fur_u16 fur_dat                  ;//����ģʽ�£�������֤���ݷ���ֵ��
fur_u16 fur_id                   ;//ID���˹���
/*------------------------------------��Դ��ͻ����---------------------------------*/
#if (ECBM_FUR_EEPROM_EN == 1) && (ECBM_EEPROM_EN == 0)
#error EEPROM����û��ʹ�ܣ���ر�FUR�ı��湦�ܻ��ߴ�Ƭ��EEPROMʹ�ܣ�
#endif
#if ECBM_UART_EN == 0
#error FUR�ǻ��ڴ��ڵ�Ӧ�ã����UARTʹ�ܣ�
#endif
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
FUR���ܵĴ��ڴ�ӡ������
-------------------------------------------------------*/
void fur_printf_base(const char * str,...){
	char xdata buf[64];  //�ַ������档
	va_list vp;          //���������ַ��
    va_start(vp, str);   //��ֵ�����ĵ�ַ��
    vsprintf(buf,str,vp);//ʹ�����õ�printf������ʽ����
    va_end(vp);          //ʹ����Ҫ�رա�
	uart_string(ECBM_FUR_UART_ID,buf);  //����ʽ��֮����ַ������ͳ�ȥ��
}
/*-------------------------------------------------------
FUR���ܵĴ��ڶ�ȡ������
-------------------------------------------------------*/
void fur_in(u8 buf){
	switch(fur_state){
		case 0:{				//�ȴ���ʼ֡��
			if(buf=='['){		//��⵽��ʼ֡ʱ��
				fur_state=1;	//����һ��״̬��
				fur_reg_point=0;	//��ʼ���Ĵ�����ַ��
			}
			if(buf=='h'){		//help
				fur_state=10;	//����һ��״̬��
			}
		}break;
		case 1:{				//�ǼǼĴ�����ַ��
			if(buf==']'){		//����յ�����֡��
				fur_state=2;	//����һ��״̬��
				fur_cmd_in=0;//��ʼ����дָ�
			}else if((buf>='0')&&(buf<='9')){//����յ����֣�
				fur_reg_point*=10;			//�������֡�
				fur_reg_point+=buf-'0';
			}else if(buf=='@'){//����յ���@��˵����ID�����ˡ�
				fur_id=0;
				fur_state=5;	//����һ��״̬��
			}else if(buf=='['){//����ڱ�״̬�ٴ��յ���ʼ֡��ֻ������Ĵ�����ַ����
				fur_reg_point=0;//��ʼ���Ĵ�����ַ��
			}else{				//�յ������ַ���
				fur_state=0;	//��ת�صȴ�̬��
			}
		}break;
		case 2:{				//�ȴ�����֡��
			if(buf=='='){		//���յ�����֡��
				fur_state=3;	//����һ��״̬��
				fur_bit=100;
				fur_reg_temp=0;		//��ʼ���Ĵ������ݻ��档
			}else if(buf=='&'){
				fur_cmd_in=0x10;//��ʼ����дָ�
			}else if(buf=='|'){
				fur_cmd_in=0x20;//��ʼ����дָ�
			}else if(buf=='['){//����յ���ʼ֡��
				fur_state=1;	//�ص��Ǽǵ�ַ̬��
				fur_reg_point=0;	//��ʼ���Ĵ�����ַ��
			}else if(buf=='^'){
				fur_bit=0;
				fur_state=6;
			}else{				//�յ������ַ���
				fur_state=0;	//��ת�صȴ�̬��
			}
		}break;
		case 3:{				//�ǼǼĴ������ݡ�
			if(buf=='?'){		//���յ���ȡָ�
				fur_cmd_buf[fur_cmd_end]=fur_reg_point;//��¼��ָ����С�
				fur_cmd_in=0;
				fur_cmd_end++;
				fur_cmd_end&=0x0f;
				fur_state=0;	
			}else if(buf=='['){//�������ʱ���յ���ʼ֡��
				fur_state=1;	//���˵��Ǽǵ�ַ��״̬��
				fur_reg_point=0;	//��ʼ���Ĵ�����ַ��
			}else if((buf=='x')||(buf=='X')){//
				fur_reg_temp=0;		//
				fur_state=4;	//
			}else if((buf>='0')&&(buf<='9')){	//����յ����֣�
				fur_reg_temp*=10;					//�������֡�
				fur_reg_temp+=buf-'0';
			}else if(buf=='.'){//����յ�����֡��
				fur_reg_buf[fur_cmd_end]=fur_reg_temp;//д�뵽�Ĵ�����
				fur_cmd_buf[fur_cmd_end]=fur_reg_point;//��¼��ָ����С�
				fur_cmd_in+=0x10;
				fur_cmd_end++;
				fur_cmd_end&=0x0f;
				fur_state=0;	
			}else{				//�յ������ַ���
				fur_state=0;	//��ת�صȴ�̬��
			}
		}break;
		case 4:{				//�ǼǼĴ�������(HEXģʽ)��
			if(buf=='?'){		//���յ���ȡָ�
				fur_cmd_buf[fur_cmd_end]=fur_reg_point;//��¼��ָ����С�
				fur_cmd_in=0;
				fur_cmd_end++;
				fur_cmd_end&=0x0f;
				fur_state=0;
			}else if(buf=='['){//�������ʱ���յ���ʼ֡��
				fur_state=1;	//���˵��Ǽǵ�ַ��״̬��
				fur_reg_point=0;	//��ʼ���Ĵ�����ַ��
			}else if((buf>='0')&&(buf<='9')){	//����յ����֣�
				fur_reg_temp*=16;					//�������֡�
				fur_reg_temp+=buf-'0';
			}else if((buf>='A')&&(buf<='F')){	//����յ����֣�
				fur_reg_temp*=16;					//�������֡�
				fur_reg_temp+=(buf-'A')+10;
			}else if((buf>='a')&&(buf<='f')){	//����յ����֣�
				fur_reg_temp*=16;					//�������֡�
				fur_reg_temp+=(buf-'a')+10;
			}else if(buf=='.'){//����յ�����֡��
				fur_reg_buf[fur_cmd_end]=fur_reg_temp;//д�뵽�Ĵ�����
				fur_cmd_buf[fur_cmd_end]=fur_reg_point;//��¼��ָ����С�
				fur_cmd_in+=0x10;
				fur_cmd_end++;
				fur_cmd_end&=0x0f;
				fur_state=0;	
			}else{				//�յ������ַ���
				fur_state=0;	//��ת�صȴ�̬��
			}
		}break;
		case 5:{//����ID��ַ
			if(buf==']'){		//����յ�����֡��
				if((fur_id&0x00ff)!=(fur_reg[1]&0x00ff)){
					fur_state=0;//��ת�صȴ�̬��
				}else{
					fur_state=2;	//����һ��״̬��
				}
			}else if((buf>='0')&&(buf<='9')){//����յ����֣�
				fur_id*=10;			//�������֡�
				fur_id+=buf-'0';
			}else if(buf=='['){//����ڱ�״̬�ٴ��յ���ʼ֡��ֻ������Ĵ�����ַ����
				fur_state=1;	//�ص��Ǽǵ�ַ̬��
				fur_reg_point=0;	//��ʼ���Ĵ�����ַ��
			}else{				//�յ������ַ���
				fur_state=0;	//��ת�صȴ�̬��
			}
		}break;
		case 6:{//����λ��ַ
			if(buf=='='){		//���յ�����֡��
				if(fur_bit<16){			
					fur_cmd_in=0x30+fur_bit;//��ʼ����дָ�
					fur_state=3;	//����һ��״̬��
					fur_reg_temp=0;		//��ʼ���Ĵ������ݻ��档
				}else{
					fur_state=0;	//��ת�صȴ�̬��
				}
			}else if((buf>='0')&&(buf<='9')){//����յ����֣�
				fur_bit*=10;			//�������֡�
				fur_bit+=buf-'0';
			}else if(buf=='['){//����ڱ�״̬�ٴ��յ���ʼ֡��ֻ������Ĵ�����ַ����
				fur_state=1;	//�ص��Ǽǵ�ַ̬��
				fur_reg_point=0;	//��ʼ���Ĵ�����ַ��
			}else{				//�յ������ַ���
				fur_state=0;	//��ת�صȴ�̬��
			}
		}break;
		case 10:{//e
			if(buf=='e'){		//help
				fur_state=11;	//����һ��״̬��
			}else if(buf=='['){		//��⵽��ʼ֡ʱ��
				fur_state=1;	//����һ��״̬��
				fur_reg_point=0;	//��ʼ���Ĵ�����ַ��
			}else{
				fur_state=0;	//����һ��״̬��
			}
		}break;
		case 11:{//l
			if(buf=='l'){		//help
				fur_state=12;	//����һ��״̬��
			}else if(buf=='['){		//��⵽��ʼ֡ʱ��
				fur_state=1;	//����һ��״̬��
				fur_reg_point=0;	//��ʼ���Ĵ�����ַ��
			}else{
				fur_state=0;	//����һ��״̬��
			}
		}break;
		case 12:{//p
			if(buf=='p'){		//help
				fur_state=13;	//����һ��״̬��
			}else if(buf=='['){		//��⵽��ʼ֡ʱ��
				fur_state=1;	//����һ��״̬��
				fur_reg_point=0;	//��ʼ���Ĵ�����ַ��
			}else{
				fur_state=0;	//����һ��״̬��
			}
		}break;
		case 13:{//.
			if(buf=='.'){		//����յ�����֡��
				fur_state=14;	//����help
				fur_dat=65535;
			}else if(buf=='['){		//��⵽��ʼ֡ʱ��
				fur_state=1;	//����һ��״̬��
				fur_reg_point=0;	//��ʼ���Ĵ�����ַ��
			}else if(buf=='-'){
				fur_state=15;	//����һ��״̬
				fur_dat=0;
			}else{
				fur_state=0;	//����һ��״̬��
			}
		}break;
		case 15:{
			if(buf=='.'){		//����յ�����֡��
				fur_state=14;	//����help
			}else if((buf>='0')&&(buf<='9')){//����յ����֣�
				fur_dat*=10;			//�������֡�
				fur_dat+=buf-'0';
			}else if(buf=='['){//����ڱ�״̬�ٴ��յ���ʼ֡��ֻ������Ĵ�����ַ����
				fur_reg_point=0;	//��ʼ���Ĵ�����ַ��
			}else{				//�յ������ַ���
				fur_state=0;	//��ת�صȴ�̬��
			}
		}break;
	}
}
/*-------------------------------------------------------
FUR��У�Ժͷ��غ�����
-------------------------------------------------------*/
void fur_check(void){
	if(fur_state==14){//��״̬˵����λ����Ҫһ�ݼĴ���˵�������˵����Ҫ��ǰд��
		fur_state=0;
		if(fur_dat==65535){
			fur_printf("Fast-Uart-Reg %s in ECBM\r\n",FUR_VER);
			fur_printf("����ID:%u\r\n",fur_reg[1]&0x00FF);//���ر���ID
			if(fur_reg[1]&0x8000){     
				fur_printf("��ʾģʽ:16����\r\n");
			}else{
				fur_printf("��ʾģʽ:10����\r\n");
			}
			fur_printf("REG[60000]:�����ʼĴ���(��д)\r\n");
			fur_printf("REG[60001]:�����Ĵ���  (ֻд)\r\n");
			fur_printf("REG[60002]:ID�żĴ���  (��д)\r\n");
			fur_printf("REG[60003]:�Ĵ�������\xFD  (ֻ��)\r\n");
			
			fur_printf("�����Ĵ���֧��:\r\n");
			fur_printf("[60001]=10.��ʾ10����\r\n");
			fur_printf("[60001]=16.��ʾ16����\r\n");
			#if	ECBM_FUR_EEPROM_EN == 1
			fur_printf("[60001]=0xA55A.��������\r\n");
			fur_printf("[60001]=0xF00F.��ȡ����\r\n");
			#endif
			fur_printf("\r\n�û��Ĵ���:%u ��\r\n",(u16)ECBM_FUR_REG_MAX);//���ؼĴ�������
		}
		#if ECBM_FUR_HELP_EN == 1
		fur_help(fur_dat);//���û�ж��������������ô����ָ��ض�������
		#else
		fur_printf("\r\n�û��Ĵ���˵����û��д��!\r\n");//����������û����������ʾһ�¡�
		#endif
	}
	while(fur_cmd_start!=fur_cmd_end){//ֻ�ڻ��λ�����ͷβָ�벻һ�µ�ʱ�������ִ�С�
		
/*------------------------------------------------����ִ�в��ֿ�ʼ---------------------------------------------------------*/	
		fur_addr=fur_cmd_buf[fur_cmd_start];//�����յ��ĵ�ַ����������
		fur_dat =fur_reg_buf[fur_cmd_start];//�����յ������ݽ���������
		if(fur_flag&FUR_FLAG_MS_M){//-------------��������������------------------------------------------------------------
			fur_flag|=FUR_M_FLAG_READ;//֪ͨ�ⲿ�������Ѿ��ɹ����ա�
		}else{//-----------------------------------�����Ǵӻ�����------------------------------------------------------------
			if(fur_addr<ECBM_FUR_REG_MAX){//�жϵ�ַ�Ƿ��ڹ涨��Χ�ڡ�			
				if((fur_cmd_out&0xf0)==0x10){//�ж��ǲ���ֱ��дָ�
					fur_cmd_out=0;//�ǵĻ������ָ�
					fur_reg_in(fur_addr,fur_dat);//���Ĵ�����д�����ݣ���Ȼ����Ҫ�е�ַƫ�ơ�
				}else if((fur_cmd_out&0xf0)==0x20){//�ж��ǲ�����дָ�
					fur_cmd_out=0;//�ǵĻ������ָ�
					fur_reg_in(fur_addr,fur_reg_out(fur_addr)&fur_dat);//��ԭ���Ĵ��������������µ�������д��ȥ��
				}else if((fur_cmd_out&0xf0)==0x30){//�ж��ǲ��ǻ�дָ�
					fur_cmd_out=0;//�ǵĻ������ָ�
					fur_reg_in(fur_addr,fur_reg_out(fur_addr)|fur_dat);//��ԭ���Ĵ��������ݻ����µ�������д��ȥ��
				}else if((fur_cmd_out&0xf0)==0x40){//�ж��ǲ��ǻ�дָ�
					if(fur_dat){
						fur_reg_in(fur_addr,fur_reg_out(fur_addr)|(1<<(fur_cmd_out&0x0f)));//
					}else{
						fur_reg_in(fur_addr,fur_reg_out(fur_addr)&(~(1<<(fur_cmd_out&0x0f))));//
					}
					fur_cmd_out=0;//�ǵĻ������ָ�
				}
				
				//��һ���Ƿ���ֵ���ܣ��ڲ�ѯָ���£����ؼĴ�����ֵ���鿴����дָ���£����ؼĴ�����ֵ��д����֤��
				if(fur_reg[1]&0x8000){
					fur_printf("[%u]=0x%04X.\r\n",fur_addr,fur_reg_out(fur_addr));
				}else{
					fur_printf("[%u]=%u.\r\n",fur_addr,fur_reg_out(fur_addr));
				}
				#if ECBM_FUR_WR_CALLBACK_EN == 1//��ִ���˼Ĵ�����д�����͵�����Ӧ�Ļص�������
				fur_reg_io_callback(fur_addr,fur_dat);
				#endif
			}else if(fur_addr==60000){//�жϵ�ַ�ǲ��ǲ����ʼĴ�����
				if(fur_cmd_out){//�ж��ǲ���дָ�
					fur_cmd_out=0;//�ǵĻ�����������ִ�У����ָ�
					fur_reg[0]=fur_dat;//��Ӱ�ӼĴ�����ֵд��Ĵ����У�
					fur_printf("OK[65535]=0.\r\n");//�ɹ�����ʱ������OK��
					uart_set_baud(ECBM_FUR_UART_ID,(u32)fur_reg[0]*100);//ͬʱ����100������ȷ�Ĳ����ʣ�Ȼ���޸Ĳ����ʡ�
				}else{
					fur_printf("BAUD=%lu\r\n",(u32)fur_reg[0]*100);//����ǲ�ѯָ��ͷ���
				}
			}else if(fur_addr==60001){//�жϵ�ַ�ǲ��Ǵ����Ĵ�����
				if(fur_cmd_out){//�ж��ǲ���дָ�
					fur_cmd_out=0;//�ǵĻ�����������ִ�У����ָ�
					if(fur_dat==0xA55A){//д��0xA55A�Ļ����ͻ�ѵ�ǰ���е����ö�����������
						#if	ECBM_FUR_EEPROM_EN == 1	
						eeprom_write_ex(0,(u8 *)fur_reg,(ECBM_FUR_REG_MAX+FUR_REG_OFFSET)*2);//�����ڲ�eepromд����������Ϣ��
						#else
						fur_flag|=FUR_FLAG_DATA;//�����湦��û�������������ݴ����־λ��
						#endif
					}else if(fur_dat==0xF00F){//д��0xF00F�Ļ����ͻ��ȡ�������Ϣ�滻��ǰ���е����á�
						#if	ECBM_FUR_EEPROM_EN == 1	
						eeprom_read_ex(0,(u8 *)fur_reg,(ECBM_FUR_REG_MAX+FUR_REG_OFFSET)*2);//�����ڲ�eeprom��������ȡ��Ϣ��
						#else
						fur_flag|=FUR_FLAG_DATA;//�����湦��û�������������ݴ����־λ��
						#endif
					}else if(fur_dat==10){//д��10�Ļ����ͻ���û��Ĵ�����ʾ��ʽ���ó�ʮ���ơ�
						fur_reg[1]&=0x7FFF;
					}else if(fur_dat==16){//д��16�Ļ����ͻ���û��Ĵ�����ʾ��ʽ���ó�ʮ�����ơ�
						fur_reg[1]|=0x8000;
					}else{
						fur_flag|=FUR_FLAG_DATA;//�Ĵ���60001�Ǵ����Ĵ��������ʲô����������Ҳ����һ�ִ���
					}
				}else{
					fur_flag|=FUR_FLAG_DATA;//�Ĵ���60001�Ǵ����Ĵ���������ֻд���ԣ�����Ƕ�ָ�Ҳ����һ�ִ���
				}
				if(fur_flag&FUR_FLAG_DATA){//������������Ĵ��������ݴ���Ҫ��ʱ�ش���Ϣ��
					#if ECBM_FUR_ERR_CALLBACK_EN == 0//��ʹ�ܴ���ص���ʱ�򣬲����㡣����ص������Ҳ���������
					fur_flag&=~FUR_FLAG_DATA;//������������־λ��
					#endif
					fur_printf("Reg Cmd Error![65535]=1.\r\n");
				}else{
					fur_printf("OK[65535]=0.\r\n");//�ɹ�����ʱ������OK��
				}
			}else if(fur_addr==60002){//ID�żĴ���
				if(fur_cmd_out){//�ж��ǲ���дָ�
					fur_cmd_out=0;//�ǵĻ�����������ִ�У����ָ�
					fur_dat&=0x00ff;
					fur_reg[1]&=0xff00;
					fur_reg[1]|=fur_dat;//�޸�ID��
				}
				fur_printf("ID[60002]=%u.\r\n",fur_reg[1]&0x00ff);
			}else if(fur_addr==60003){//�Ĵ��������Ĵ������е��ƣ�
				fur_printf("REG_NUM[60003]=%u.\r\n",(u16)ECBM_FUR_REG_MAX);
			}else{//���ַ��������ܶ�д�ģ����ش����롣
				#if ECBM_FUR_ERR_CALLBACK_EN == 1//�˴�����Ҳ������λ�ģ���������λ�������е���࣬�ͺϲ�������
				fur_flag|=FUR_FLAG_ADDR;//�õ�ַ�����־λ��
				#endif
				fur_printf("Reg Addr Error![65535]=2.\r\n");
			}
			#if ECBM_FUR_ERR_CALLBACK_EN == 1//��ִ���˼Ĵ�����д�����͵�����Ӧ�Ļص�������
			fur_error_callback(fur_flag&0x7F);
			#endif
		}
/*------------------------------------------------����ִ�в��ֽ���---------------------------------------------------------*/	
		fur_cmd_start++;//���λ����������ͷָ��++��
		fur_cmd_start&=0x0f;//�޶���16�ֽڡ�
	}
}			
/*-------------------------------------------------------
FUR�ĳ�ʼ��������
-------------------------------------------------------*/
void fur_init(void){
#if	ECBM_FUR_EEPROM_EN == 1	
	fur_u8 i;
#endif	
	fur_u16 temp;
#if   ECBM_FUR_UART_ID == 1	
	temp=UART1_BAUD_RATE/100;//д�벨����Ĭ��ֵ��
#elif ECBM_FUR_UART_ID == 2
	temp=UART2_BAUD_RATE/100;//д�벨����Ĭ��ֵ��
#elif ECBM_FUR_UART_ID == 3
	temp=UART3_BAUD_RATE/100;//д�벨����Ĭ��ֵ��
#elif ECBM_FUR_UART_ID == 4
	temp=UART4_BAUD_RATE/100;//д�벨����Ĭ��ֵ��
#endif
	fur_reg[0]=temp;
	fur_reg[1]=ECBM_FUR_ID;
#if	ECBM_FUR_EEPROM_EN == 1	
	eeprom_init();//��ʼ���ڲ���eeprom������STC���������
	eeprom_read_ex(0,(u8 *)fur_reg,(ECBM_FUR_REG_MAX+FUR_REG_OFFSET)*2);//��ȡ�����ֵ��
	if(fur_reg[0]==0xffff){//�������û�б���������߲������б仯
		for(i=0;i<(ECBM_FUR_REG_MAX+FUR_REG_OFFSET);i++){//��ȫ����ʼ��Ϊ0��
			fur_reg[i]=0;
		}
		fur_reg[0]=temp;
		fur_reg[1]=ECBM_FUR_ID;
		eeprom_write_ex(0,(u8 *)fur_reg,(ECBM_FUR_REG_MAX+FUR_REG_OFFSET)*2);//�ٽ���ʼ����ֵд�롣
	}
	uart_set_baud(ECBM_FUR_UART_ID,(u32)fur_reg[0]*100);
#endif
}

/*-------------------------------------------------------
FUR�Ĵ������ú�����
-------------------------------------------------------*/
void fur_reg_uart_reset(void){
	uart_set_baud(ECBM_FUR_UART_ID,115200);
}
/*-------------------------------------------------------
FUR�����Ķ�ȡ���������ڶ�ȡ��һ���ӻ��ļĴ�����
-------------------------------------------------------*/
u16 fur_read(u16 addr){
	fur_u16 timeout=2000;		//�趨��ʱʱ��Ϊ2�롣
	fur_flag|=FUR_FLAG_MS_M;//�趨FURΪ����ģʽ��
	fur_printf("[%u]=?.\r\n",addr);//���Ͳ�ѯָ�
	fur_flag&=~FUR_M_FLAG_TIME;//���㳬ʱ��־λ��
	while(timeout--){		//ѭ���ȴ����г�ʱ�ж���
		delay_ms(1);		//ÿ1ms
		fur_check();		//��ѯһ�����ݡ�
		if(fur_flag&FUR_M_FLAG_READ){//���յ�����ʱ��
			if(addr==fur_addr){//������صĵ�ַ�ͷ��͵ĵ�ַһ�£�
				fur_flag|=FUR_M_FLAG_OK;//������Ϊ����ȷ���ա�
				fur_flag&=FUR_FLAG_MS_S;//�л����ӻ�ģʽ��
				return fur_dat;//���ؽ��յ����ݡ�
			}else{//������صĵ�ַ�ͷ��͵ĵ�ַ��һ�£�
				if(fur_addr==65535){//�ҷ��ص�ַΪ65535��
					switch(fur_dat){//˵�����䷢���˴��󣬽��յ��������Ǵ����롣
						case 1:fur_flag|=FUR_M_FLAG_DATA;break;//��������룬����Ӧ��־λ��
						case 2:fur_flag|=FUR_M_FLAG_ADDR;break;
					}
				}else{//�����������ַ����Ȼ���������ԭ��δ֪��
					fur_flag|=FUR_M_FLAG_ADDR;//�������Եľ��Ƿ��صĵ�ַ�����⡣
				}
				#if ECBM_FUR_ERR_CALLBACK_EN == 1
				fur_error_callback(fur_flag&0x7F);//���ó���ص�������
				#endif
				fur_flag&=FUR_FLAG_MS_S;//�л����ӻ�ģʽ��
				return 0;//Ĭ�Ϸ���0��
			}
		}
	}
	if(timeout==65535){//�����ʱ�Ļ���
		fur_flag|=FUR_M_FLAG_TIME;//�ó�ʱ��־λ��
	}
	fur_flag&=FUR_FLAG_MS_S;//�л����ӻ�ģʽ��
	return 0;//Ĭ�Ϸ���0��
}
/*-------------------------------------------------------
FUR�����Ķ�д������������һ���ӻ��ļĴ���д��һ��ֵ��
-------------------------------------------------------*/
void fur_write(u16 addr,u16 dat){
	fur_u16 timeout=2000;		//�趨��ʱʱ��Ϊ2�롣
	fur_flag|=FUR_FLAG_MS_M;//�趨FURΪ����ģʽ��
	fur_printf("[%u]=%u.\r\n",addr,dat);//���Ͷ�дָ�
	fur_flag&=~FUR_M_FLAG_TIME;//���㳬ʱ��־λ��
	while(timeout--){		//ѭ���ȴ����г�ʱ�ж���
		delay_ms(1);		//ÿ1ms
		fur_check();		//��ѯһ�����ݡ�
		if(fur_flag&FUR_M_FLAG_READ){//���յ�����ʱ��
			if(addr==fur_addr){//������صĵ�ַ�ͷ��͵ĵ�ַһ�£�
				if(dat==fur_dat){//�ҷ��ص�����Ҳһ�£�
					fur_flag|=FUR_M_FLAG_OK;//������Ϊ����ȷ���ա�
					goto fur_write_return;//����ѭ����ֱ�ﺯ��β��
				}else{//������ص����������⣬
					fur_flag|=FUR_M_FLAG_DATA;//�����ݴ����־λ��
					goto fur_write_return;//����ѭ����ֱ�ﺯ��β��
				}				
			}else{//������صĵ�ַ�ͷ��͵ĵ�ַ��һ�£�
				if(fur_addr==65535){//�ҷ��ص�ַΪ65535��
					switch(fur_dat){//˵�����䷢���˴��󣬽��յ��������Ǵ����롣
						case 1:fur_flag|=FUR_M_FLAG_DATA;break;//��������룬����Ӧ��־λ��
						case 2:fur_flag|=FUR_M_FLAG_ADDR;break;
					}
				}else{//�����������ַ����Ȼ���������ԭ��δ֪��
					fur_flag|=FUR_M_FLAG_ADDR;//�������Եľ��Ƿ��صĵ�ַ�����⡣
				}
				#if ECBM_FUR_ERR_CALLBACK_EN == 1
				fur_error_callback(fur_flag&0x7F);//���ó���ص�������
				#endif
				goto fur_write_return;//����ѭ����ֱ�ﺯ��β��
			}
		}
	}
	if(timeout==65535){//�����ʱ�Ļ���
		fur_flag|=FUR_M_FLAG_TIME;//�ó�ʱ��־λ��
	}
fur_write_return:
	fur_flag&=FUR_FLAG_MS_S;//�л����ӻ�ģʽ��
}