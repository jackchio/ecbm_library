#include "ecbm_core.h"
/*------------------------------------��Դ��ͻ����---------------------------------*/
#if (ECBM_UART_LIB_EN == 0)&&(ECBM_AUTO_DOWNLOAD_EN == 1)
#error �Զ����ع����򴮿ڿ�δ���ض�����ʧ�ܣ���ǰ��ecbm_core.hʹ�ܴ��ڿ⣡
#endif
#if (ECBM_UART1_EN == 0)&&(ECBM_AUTO_DOWNLOAD_EN == 1)
#error �Զ����ع����򴮿�1δʹ�ܶ�����ʧ�ܣ���ǰ��uart.hʹ�ܴ���1��
#endif
#if (ECBM_UART1_IO != 0)&&(ECBM_AUTO_DOWNLOAD_EN == 1)
#error �Զ����ع�����Ҫ����1ӳ�䵽P30��P31����ǰ��uart.h�޸Ĵ���1�����IO��
#endif
/*--------------------------------------��������-----------------------------------*/
u32 xdata ecbm_sys_clk=0;
u16 xdata ecbm_delay_base;
/*-----------------------------------��ѡģ���趨----------------------------------*/
union{
	u32 num32;
	u16 num16[2];
	u8  num8[4];
}fast_cout;
/*-----------------------------------------`--------------
���뼶��ʱ����
-------------------------------------------------------*/
void delay_ms(u16 ms){
	u16 i;
 	if(ms){
		do{
			i=ecbm_delay_base;
			while(--i);
		}while(--ms);	
	}
}
/*-------------------------------------------------------
΢�뼶��ʱ���������ģ�
-------------------------------------------------------*/
void delay_us(u16 us){
	u16 i;
	i=us;
	while(i--);
}
/*-------------------------------------------------------
΢�뼶��ʱ�����Ľ��ļ��㺯��
-------------------------------------------------------*/
u16 delay_set_us(u16 us){
//��ʽ����������ʱ��̫������ֳ�����������������������������ʱ����ֵ����������ĺ������á�
	fast_cout.num32=((u32)ecbm_delay_base*(u32)(us))*131;
	return fast_cout.num16[0]>>1;
}
/************************************���ڵ���ģ��***************/#if ECBM_AUTO_DOWNLOAD_EN
/*-------------------------------------------------------
�Զ���������ı���
-------------------------------------------------------*/
__IO u8 xdata old_char;  //������һ�ν��յ�����
__IO u8 xdata char_count;//��ͬ���ݼ���
/*-------------------------------------------------------
�������жϺ���
-------------------------------------------------------*/
void system_uart_reset(){
	if(old_char!=UART1_GET_REG_SBUF){//�ж��ظ��ַ�������ַ����ظ�
		old_char=UART1_GET_REG_SBUF;	//�͸���oldchar
		char_count=0;				//����������
	}else{							//����ַ��ظ�
		char_count++;				//���ظ�������+1
	}
	if(char_count>=233){			//���յ�233���ظ�����ʱ
		_nop_();
		POWER_RESET;				//����
		_nop_();
		_nop_();
	}
}
#if ECBM_MCU_CHECK_EN
/*-------------------------------------------------------
ϵͳ��麯��
-------------------------------------------------------*/
void system_check(){
	u8 i,j;	
	u16 aaa=0x1234;
	debug("ECBM V%u.%u.%u on %s",(u16)ECBM_FVN,(u16)ECBM_RVN,(u16)ECBM_BVN,ECBM_MCU_NAME);//����汾�ź͵�Ƭ���ͺ�
	debug("%uK",(u16)((ECBM_MCU&0x0F0000)>>16));
	debug("%02u",(u16)(ECBM_MCU_ROM_SIZE));
#if		ECBM_MCU	==	0x110301
	debug("-8PIN");
#elif	ECBM_MCU	==	0x110302
	debug("S2-16PIN/20PIN");
#elif	ECBM_MCU	==	0x120502
	debug("S2");
#elif	ECBM_MCU	==	0x120504
	debug("S4");
#elif	ECBM_MCU	==	0x2405C2
	debug("S2A12");
#elif	ECBM_MCU	==	0x2805C4
	debug("S4A12");
#elif	ECBM_MCU	==	0x3103A2
	debug("-16PIN/20PIN");
#elif	ECBM_MCU	==	0x310201
	debug("-8PIN ");
#elif	ECBM_MCU	==	0x3102A1
	debug("A-8PIN");
#elif	ECBM_MCU	==	0x3103A1
	debug("T-20PIN");
#elif	ECBM_MCU	==	0x3205A2
	debug("S2");
#elif	ECBM_MCU	==	0x3205A4
	debug("S4");
#elif	ECBM_MCU	==	0x4103A2
	debug("-20PIN");
#elif	ECBM_MCU	==	0x4105A2
	debug("-32PIN");	
#elif	ECBM_MCU	==	0x4205C4
	debug("T-48PIN");
#elif	ECBM_MCU	==	0x4305C2
	debug("S2-48PIN");	
#elif	ECBM_MCU	==	0x4305C4
	debug("S4-48PIN");
#elif	ECBM_MCU	==	0x4805C4
	debug("U-48PIN/64PIN");	
#endif
	j=0;
	debug("\r\nChecking MCU ID");
	for(i=0;i<7;i++){
		debug(".");
		if((REG_ID(i))==(MCUID[i])){
			j++;
		}
	}
	if(j!=7){
		debug("Error\r\nPlease check the setting of the MCU model\r\n");
	}else{
		debug("OK\r\nID    :");for(i=0;i<7;i++){debug("%02X",(u16)(MCUID[i]));}debug("\r\n");		//���ΨһID��
		debug("DATA  :128\tByte\r\n");//DATA���̶���128Byte
		debug("IDATA :128\tByte\r\n");//IDATA���̶���128Byte
		debug("XDATA :%u\tByte\r\n",(u16)((ECBM_MCU&0x0F0000)>>16)*1024);//�������ļ��л�ȡXDATA����С
		debug("FLASH :%lu\tByte\r\n",(u32)ECBM_MCU_ROM_SIZE*1024);//�������ļ��л�ȡFLASH����С
		debug("EEPROM:%u\tByte\r\n",(u16)512);//�������ļ��л�ȡEEPROM����С
		debug("SYSCLK:%lu\tHz\r\n",ecbm_sys_clk);//����ڲ�����ֵ����ͼ�ν���������
		debug("LSI   :%u\tHz\r\n",REG_LSI);//����ڲ�����ֵ����ͼ�ν���������
		debug("BGV   :%u\tmV\r\n",REG_BGV);//����ڲ���ѹ��׼ֵ����Ҫ��STC-ISP������
		debug("ENDIAN:");
		if(*((char*)(&aaa))==0x12)debug("big\tendian\r\n");
		if(*((char*)(&aaa))==0x34)debug("little\tendian\r\n");
	}	
}
#endif
/****************************************************************************/#endif
/*-------------------------------------------------------
��ʽ�����ͺ���
-------------------------------------------------------*/
void debug(const char * str,...){
	char xdata buf[64];  //�ַ������档
	va_list vp;          //���������ַ��
    va_start(vp, str);   //��ֵ�����ĵ�ַ��
    vsprintf(buf,str,vp);//ʹ�����õ�printf������ʽ����
    va_end(vp);          //ʹ����Ҫ�رա�
	uart_string(1,buf);  //����ʽ��֮����ַ������ͳ�ȥ��
}
/*----------------------------------����ϵͳ����-----------------------------------*/
#define SYS_HSI_S 0 //�ڲ�����ʱ��HSI(��׼)
#define SYS_HSI_C 1 //�ڲ�����ʱ��HSI(�Զ���)
#define SYS_LSI   2 //�ڲ�����ʱ��LSI
#define SYS_LSE   3 //�ⲿ����ʱ��LSI
#define SYS_HSE_A 4 //�ⲿ��Դ����
#define SYS_HSE_P 5 //�ⲿ��Դ����
void system_set_clock(u8 source){
	switch(source){
		case SYS_HSI_S:
		case SYS_HSI_C:{
			CLK_HSI_POWER_ON;	//ʹ��HSI�����ڲ�24M��IRC��
			CLK_SET_SOURCE_HSI;	//�л���HSI��
			CLK_HSE_POWER_OFF;	//�ر�����ʱ��Դ��ʡ�硣
			CLK_LSE_POWER_OFF;	//�ر�����ʱ��Դ��ʡ�硣
			CLK_LSI_POWER_OFF;	//�ر�����ʱ��Դ��ʡ�硣
		}break;
		case SYS_LSI:{
			CLK_LSI_POWER_ON;	//ʹ��LSI�����ڲ�32K��IRC��
			CLK_SET_SOURCE_LSI;	//�л���LSI��
			CLK_HSI_POWER_OFF;	//�ر�����ʱ��Դ��ʡ�硣
			CLK_LSE_POWER_OFF;	//�ر�����ʱ��Դ��ʡ�硣
			CLK_HSE_POWER_OFF;	//�ر�����ʱ��Դ��ʡ�硣
		}break;
		case SYS_LSE:{
			CLK_LSE_POWER_ON;	//ʹ��LSE�����ⲿ���پ���
			CLK_SET_SOURCE_LSE;	//�л���LSE��
			CLK_LSI_POWER_OFF;	//�ر�����ʱ��Դ��ʡ�硣
			CLK_HSI_POWER_OFF;	//�ر�����ʱ��Դ��ʡ�硣
			CLK_HSE_POWER_OFF;	//�ر�����ʱ��Դ��ʡ�硣
		}break;
		case SYS_HSE_A:{
			CLK_HSE_A_POWER_ON;	//ʹ��HSE����Դ���񣩡�
			CLK_SET_SOURCE_HSE;	//�л���HSE��
			CLK_HSI_POWER_OFF;	//�ر�����ʱ��Դ��ʡ�硣
			CLK_LSE_POWER_OFF;	//�ر�����ʱ��Դ��ʡ�硣
			CLK_LSI_POWER_OFF;	//�ر�����ʱ��Դ��ʡ�硣
		}break;
		case SYS_HSE_P:{
			CLK_HSE_P_POWER_ON;	//ʹ��HSE����Դ���񣩡�
			CLK_SET_SOURCE_HSE;	//�л���HSE��
			CLK_HSI_POWER_OFF;	//�ر�����ʱ��Դ��ʡ�硣
			CLK_LSE_POWER_OFF;	//�ر�����ʱ��Դ��ʡ�硣
			CLK_LSI_POWER_OFF;	//�ر�����ʱ��Դ��ʡ�硣
		}break;
	}
}
void system_set_div(u8 div){
	if(div==0){					//�ų���0������ȶ�ѡ�
		CLK_SET_REG_CLKDIV(1);	//�������0�Ļ��͸ĳ�1��
	}else{
		CLK_SET_REG_CLKDIV(div);//�������0����ֱ��д��Ĵ�����
	}
}
/*-------------------------------------------------------
�⺯��ϵͳ��ʼ������
-------------------------------------------------------*/
void system_init(void){
	#define ECBM_SYSCLK_STEP1 48000
	#define ECBM_SYSCLK_STEP2 76000
	#define ECBM_SYSCLK_STEP  54000	
	#if ECBM_SYSCLK_TYPE == 0    
	u32 sys_count;
	#endif
	EX_SFR_ENABLE;//�򿪶���ļĴ�����
//-------------��ȡϵͳʱ��------------//
#if ECBM_SYSCLK_TYPE == 0//���ʹ���˱�׼Ƶ�ʣ�HSI����
	#if ((ECBM_MCU&0xF00000)>0x200000)//����ǲ���������Ƶ�ε��ͺš�
		if(IRCBAND){//����õ���33MƵ�Σ���������Ƶ��36M�����㡣
			sys_count=36000000L-(s32)((s32)REG_HSI1-(s32)IRTRIM)*ECBM_SYSCLK_STEP2;
		}else{//����õ���24MƵ�Σ���������Ƶ��24M�����㡣
			sys_count=24000000L-(s32)((s32)REG_HSI-(s32)IRTRIM)*ECBM_SYSCLK_STEP1;
		}
	#else //�����ʹ�õ�Ƶ�ε��ͺš�
		sys_count=24000000L-(s32)((s32)REG_HSI-(s32)IRTRIM)*ECBM_SYSCLK_STEP;  //��������Ƶ��24M�����㡣
	#endif
	sys_count/=CLKDIV;//���Ϸ�Ƶϵ����
	if      (sys_count<5764800L ){//��ʽ����������������õ���һ���Ǳ�׼Ƶ�ʣ��������ʽ���ɱ�׼Ƶ�ʡ�
		ecbm_sys_clk=5529600;
	}else if(sys_count<8529600L ){
		ecbm_sys_clk=6000000;
	}else if(sys_count<11529600L){
		ecbm_sys_clk=11059200;
	}else if(sys_count<15216000L){
		ecbm_sys_clk=12000000;
	}else if(sys_count<19216000L){
		ecbm_sys_clk=18432000;
	}else if(sys_count<21059200L){
		ecbm_sys_clk=20000000;
	}else if(sys_count<23059200L){
		ecbm_sys_clk=22118400;
	}else if(sys_count<25500000L){
		ecbm_sys_clk=24000000;
	}else if(sys_count<28500000L){
		ecbm_sys_clk=27000000;
	}else if(sys_count<31500000L){
		ecbm_sys_clk=30000000;
	}else if(sys_count<33500000L){
		ecbm_sys_clk=33177600;
	}else{
		ecbm_sys_clk=35000000;    //���֧�ֵ�33M
	}
#elif ECBM_SYSCLK_TYPE == 2//���ʹ�����ڲ�����ʱ�ӣ�
	ecbm_sys_clk=REG_LSI;//��ram�����ʱ��ֵ��
#else 
	ecbm_sys_clk=SYS_CLK_SET;
#endif
#if ECBM_SYSCLK_TYPE >1//���ݽ����ѡ������ʱ��Դ��
	system_set_clock(ECBM_SYSCLK_TYPE);
#endif	
//-------------������ʱ��׼------------//		
	ecbm_delay_base=ecbm_sys_clk/10000;
//---------------�Զ�����--------------//
#if ECBM_AUTO_DOWNLOAD_EN//�жϷ���Ҫ�����Զ����ء�
	old_char=0;         //��ʼ��������ر���
	char_count=0;       //��ʼ��������ر���
	uart_init();
#endif
//-------------����Ӳ������------------//
#if ECBM_POWER_LIB_EN
	#if ECBM_POWER_RST_CFG_EN
		power_rstcfg_init();
	#endif
#endif	
//-------------ʱ���������------------//	
#if ECBM_SYSCLK_OUT_EN //�ж��Ƿ���Ҫ����ʱ�������
	#if ((ECBM_MCU&0xF00000)>0x200000)//����ǲ���GH��
		#if ECBM_SYSLCK_OUT_PIN
			CLK_SET_OUT_TO_P16_GH;
		#else
			CLK_SET_OUT_TO_P54_GH;
		#endif
		CLK_OUT_SET_DIV_GH(ECBM_SYSCLK_OUT_SETTING_GH);
	#else
		#if ECBM_SYSLCK_OUT_PIN
			CLK_SET_OUT_TO_P16_FA;
		#else
			CLK_SET_OUT_TO_P54_FA;
		#endif
		CLK_OUT_SET_DIV_FA(ECBM_SYSCLK_OUT_SETTING_FA);
	#endif
#endif
//--------------����ȷ��---------------//
	EA_ENABLE;//�����жϡ�
#if ECBM_MCU_CHECK_EN
	delay_ms(500);
	system_check();
#endif
}
/*-------------------------------------------------------
������
-------------------------------------------------------*/
#if ECBM_ERROR_PRINTF_EN
void error_printf(const char * str,...){
	u8 ch,i;         //�ַ����桢λ���ͼ�����
	u16 j,len;       //�ַ����ͼ������ַ����ȡ�
	char xdata buf[64];//�ַ������档
	va_list vp;        //���������ַ��
	u16 _100us; //��ʹ�ܵĻ������Լ�������ʱ��ؼ�������
	_100us=delay_set_us(100);//������ʱ100us�Ľ�����
	va_start(vp, str); //��ֵ�����ĵ�ַ��
	len=vsprintf(buf,str,vp);//ʹ�����õ�printf������ʽ����
	va_end(vp);	       //ʹ����Ҫ�رա�
	while(1){          //��Ϊ�Ǵ�����ʾ�����Ա����������˳���
		delay_ms(500);//��ʱ500ms
		for(j=0;j<len;j++){
			error_io=1;      //Ĭ�ϸߵ�ƽ��
			error_io=0;      //���ͱ�ʾ��ʼλ��
			delay_us(_100us);//��ʱ100us������9600�������趨�ġ���ͬ��
			ch=buf[j];       //���ַ�ȡ������
			for(i=0;i<8;i++){//��λ���͡�
				if(ch&0x01){ //�ȷ���λ��
					error_io=1;
				}else{
					error_io=0;
				}	
				ch>>=1;      //�������ƣ�Ϊ���´η��͡�
				delay_us(_100us);
			}
			error_io=1;      //������һ���ֽڣ����߱�ʾֹͣλ��
			delay_us(_100us);
			delay_us(_100us);
		}
	}
}
#endif
/*---------------------------------������ϵͳ����---------------------------------*/
/*-------------------------------------------------------
������ڡ�
-------------------------------------------------------*/
#if ECBM_SOFT_DEBUG_EN
#if ECBM_GPIO_LIB_EN == 0  
#error ����Թ�����ҪGPIO���֧�֣���ȷ��GPIO���ʹ��״̬��
#endif 
void debug_soft(u8 io,const char * str,...){
	u8 i;                     //λ���ͼ�����
	u16 j,len;                //�ַ����ͼ������ַ����ȡ�
	u16 delay_debug;
	char xdata buf[64];       //�ַ������档
	va_list vp;               //���������ַ��
    va_start(vp, str);        //��ֵ�����ĵ�ַ��
    len=vsprintf(buf,str,vp); //ʹ�����õ�printf������ʽ����
    va_end(vp);	              //ʹ����Ҫ�رա�
	delay_debug=delay_set_us(100);
	for(j=0;j<len;j++){
		gpio_out(io,1);       //Ĭ�ϸߵ�ƽ��
		gpio_out(io,0);       //���ͱ�ʾ��ʼλ��
		delay_us(delay_debug);//��ʱ100us������9600�������趨�ġ���ͬ��
		for(i=0;i<8;i++){     //��λ���͡�
			if(buf[j]&0x01){  //�ȷ���λ��
				gpio_out(io,1);
			}else{
				gpio_out(io,0);
			}	
			buf[j]>>=1;       //�������ƣ�Ϊ���´η��͡�
			delay_us(delay_debug);
		}
		gpio_out(io,1);       //������һ���ֽڣ����߱�ʾֹͣλ��
		delay_us(delay_debug);//��ʱ200us��������Ľ�˵һ����
		delay_us(delay_debug);
	}
}
#endif
/**********************************strϵ�к���************************/#if ECBM_STRING_EN
/*-------------------------------------------------------
�ַ������Һ�����
-------------------------------------------------------*/
u16 str_find(char * dest,char * key){
	u16 key_count=0,key_first=0,count=0;
	while(*dest){	//�ж�Ŀ���ַ�����
		count++;	//��¼ѭ���Ĵ�����
		if(key[key_count]==(*dest)){//����ؼ����ַ�����ǰλ�ȶԳɹ���
			key_count++;			//��ô�ͱȽ���һλ��
		}else{						//����û�бȶԳɹ���
			key_count=0;			//��ô�ʹ�ͷ��ʼ�ȶԡ�
			key_first=count;		//���õ�һλ����λ�á�
		}
		dest++;						//��ȡĿ���ַ�������һλ��
		if(key[key_count]==0){		//����ؼ����ַ����ȶ��꣬
			return key_first;		//���عؼ����ַ�����һ�γ��ֵ�λ�á�
		} 
	}
	return 0xffff;//�����е���һ����˵��ֱ��Ŀ���ַ���������û�бȶԳɹ�������-1��
	//�Ż���194�ֽ�
	
//	u16 dest_c,   key_c;  //��������������
//	u16 dest_len, key_len;//�ַ������ȡ�
//	char * dest_t,* key_t;//���㳤���������ʱ������
//	dest_t  =dest;        //��Ŀ���ַ���������ʱ�����С�
//	key_t   =key;         //�����ҹؼ����ַ���������ʱ�����С�
//	dest_len=0;           //�������������
//	key_len =0;           //�������������
//	while(*dest_t){       //�����Ŀ���ַ����ĳ��ȡ�
//		dest_len++;       //����ԭ�����ж��ַ����з�0�ַ��ĸ�����
//		dest_t++;         //ָ��+1����һ�ε��ַ���0�Ļ������ѭ���ͽ����ˡ�
//	}
//	while(*key_t){        //������ؼ����ַ����ĳ��ȡ�
//		key_len++;        //����ԭ�����ж��ַ����з�0�ַ��ĸ�����
//		key_t++;          //ָ��+1����һ�ε��ַ���0�Ļ������ѭ���ͽ����ˡ�
//	}
//	if(dest_len<key_len){ //���Ŀ��ĳ��ȱȹؼ��ֵĳ��ȶ̣�˵������������ġ�
//		return 0xffff;    //����0xFFFF��
//	}
//	for(dest_c=0;dest_c<=(dest_len-key_len);dest_c++){ //����Ŀ���ַ�����10�����ؼ�����3������ô����⵽��7���ַ���ʱ����н����ˡ�
//		for(key_c=0;key_c<key_len;key_c++){            //�ؼ����м��������жϼ��Ρ�
//			if(dest[dest_c+key_c]!=key[key_c]){        //ֻҪ������һ���ȶԲ��ϵģ�������������жϡ�
//				break;
//			}
//		}
//		if(key_c==key_len){                            //ֻ��ȫ���ȶ���ϣ��Ż���ȡ�
//			return dest_c;                             //��ô��ʱ���صľ��ǹؼ��ֵ�һ�γ������ַ������λ�á�
//		}
//	}
//	return 0xffff;        //û�ҵ��ͷ���0xFFFF��
}
/*-------------------------------------------------------
IO��Ϣ��ȡ������
-------------------------------------------------------*/
u8 str_read_pin(char * str,u16 pos){
	u8  dat=0,offset,count; //�������������Ƕ�ȡ����Ϣ���ַ���ƫ�ƺ�����ͳ�ơ�
	count=0;                //����ͳ�����㡣
	for(offset=0;offset<10;offset++){//Ԥ��10��ƫ������
		if((str[pos+offset]>='0')&&(str[pos+offset]<='7')){//IO�ڵı�Ŷ��Ǵ�0~7��
			count++;                            //�������Χ�ڣ�����+1��
			if(count==1){                       //����ǵ�һ������
				dat=(str[pos+offset]-'0')<<4;   //���������ŵ���4λ��
			}
			if(count==2){                       //����ǵڶ�������
				dat=(str[pos+offset]-'0')|dat;  //���������ŵ���4λ��
				return dat;                     //���ظ�ֵ��
			}
		}
		if((str[pos+offset]>='8')&&(str[pos+offset]<='9')){//�����8��9����ôֻ������������д��ֵ��
			count++;
		}
		if(str[pos+offset]==',')break;//�������ž��˳���
		if(str[pos+offset]==0)break;  //�ַ�������Ҳ�˳���
	}
	return 	dat;
}
/*-------------------------------------------------------
u16������ȡ������
-------------------------------------------------------*/
u16 str_read_u16(char * str,u16 pos){
	u16 dat=0; //��ȡ����Ϣ��
	u8  offset;//�ַ���ƫ�ơ�
	for(offset=0;offset<20;offset++){//Ԥ��20���ַ���ƫ�ơ�
		if((str[pos+offset]>='0')&&(str[pos+offset]<='9')){//���ֶ��Ǵ�0~9��
			dat*=10;                  //��������һλ����ԭ����12���ͱ��120���ճ��ĸ���������װ�µ�����
			dat+=str[pos+offset]-'0'; //���µ����ӵ���λ�ϡ�
		}
		if(str[pos+offset]==',')break;//�������ž��˳���
		if(str[pos+offset]=='.')break;//������ž��˳���
		if(str[pos+offset]==0)break;  //�ַ�������Ҳ�˳���
	}
	return 	dat;
}
/*-------------------------------------------------------
�ַ����Ƴ�ָ��������ַ������Ȳ����棩��
-------------------------------------------------------*/
u8 str_push_len(u8 * dest,u16 dlen,u8 * key,u16 klen){
	u16 i,j=0,start=0,stop=0;
	for(i=0;i<dlen;i++){		//��ͷ��ʼ��ֱ��ָ���ĳ��ȡ�
		if(dest[i]==key[j]){	//�ѵ�ǰ���ַ��͹ؼ��ʱȽϳɹ���
			j++;				//ȡ�ؼ��ʵ���һ���֡�
			if(j==klen){		//���ؼ���ȫ���ȶ���ɵ�ʱ��
				stop=i;			//���桾����λ�á���
				break;			//�˳�ѭ����
			}
		}else{					//�����ǰ���ַ��͹ؼ��ʱȽ�ʧ�ܣ�
			j=0;				//��һ�δ�ͷ��ʼ�ȶԡ�
			start=i+1;			//���¡���ʼλ�á�Ϊ��һλ����Ϊ��ǰλʧ���ˣ���
		}
	}
	if(start<=stop){			//���ȶԳɹ���ʱ�򣬡���ʼλ�á��϶�С�ڵ��ڡ�����λ�á���
		for(i=start;i<stop;i++){//���ӡ���ʼλ�á���������λ�á�֮��Ļ���ȫ���㡣
			dest[i]=0;
		}
		return 1;				//�����Ƴ��ɹ���
	}else{
		return 0;				//�����Ƴ�ʧ�ܡ�
	}
}
/*****************************************************************************/#endif
/*�������۵�ר��******************CRC16ģ��***********************/#if ECBM_CRC16_EN
/*-------------------------------------------------------
����CRC16������
-------------------------------------------------------*/
u16 crc16(u8 buf[],u16 len){
    u16 crc_value= 0xFFFF; 							//��ʼ��CRC������λΪ1��
    u8 i,j;											//ѭ���õ���ʱ������
    for(i=0;i<len;i++){								//���㻺���ÿһ���ֽڡ�
        crc_value^=buf[i];							//��ǰ�������CRC���ֽڣ���C51�����ֱ�Ӵ���
        for(j=0;j<8;j++){							//����ÿ���ֽڵ�ÿһλ��
            if(crc_value&0x01){						//�ж�����ǰ���λ�Ƿ�Ϊ1��
                 crc_value=(crc_value>>1)^0xA001;	//���Ϊ1�����Ʋ������ʽ��
            }else{
                crc_value>>=1;						//����ֱ������һλ��
            }           
        }
    } 
    return crc_value;								//���ؼ���CRC16�Ľ����
}
/*-------------------------------------------------------
����CRC16������
-------------------------------------------------------*/
void crc16_insert_buf(u8 buf[],u16 len){
	u16 value;					//��ʱ������
	value=crc16(buf,len-2);		//�����CRC16ֵ��
	buf[len-2]=(u8)(value>>8);	//����λ��ǰ��
	buf[len-1]=(u8)(value);		//��λ�ں��˳���š�
}
/*-------------------------------------------------------
���CRC16������
-------------------------------------------------------*/
u8 crc16_check_buf(u8 buf[],u16 len){
	if(crc16(buf,len-2)==((buf[len-2]<<8)+(buf[len-1]))){//����ǰ���CRC16ֵ�ͺ��汣���CRC16ֵ�Ƚϡ�
		return 1;//�Ƚϳɹ�����1��
	}else{
		return 0;//�Ƚ�ʧ�ܷ���0��
	}
}
/*�������۵�ר��************************************************************/#endif