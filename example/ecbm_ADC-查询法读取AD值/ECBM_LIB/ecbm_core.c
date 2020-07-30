#include "ecbm_core.h"
/*------------------------------------��Դ��ͻ����---------------------------------*/
#if (ECBM_UART_EN == 0)&&(AUTO_DOWNLOAD_EN == 1)
#error �Զ����ع����򴮿ڿ�δ���ض�����ʧ�ܣ���ǰ��ecbm_core.hʹ�ܴ��ڿ⣡
#endif
#if (UART1_EN == 0)&&(AUTO_DOWNLOAD_EN == 1)
#error �Զ����ع����򴮿�1δʹ�ܶ�����ʧ�ܣ���ǰ��uart.hʹ�ܴ���1��
#endif
#if (UART1_IO != 0)&&(AUTO_DOWNLOAD_EN == 1)
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
/*-------------------------------------------------------
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
/************************************���ڵ���ģ��***************/#if AUTO_DOWNLOAD_EN
/*-------------------------------------------------------
�Զ���������ı���
-------------------------------------------------------*/
__IO u8 xdata old_char;  //������һ�ν��յ�����
__IO u8 xdata char_count;//��ͬ���ݼ���
__IO     bit  debug_busy;//����æ��־λ
/*-------------------------------------------------------
�������жϺ���
-------------------------------------------------------*/
void system_uart_reset(){
	if(SBUF!=old_char){			//�ж��ظ��ַ�������ַ����ظ�
		old_char=SBUF;			//�͸���oldchar
		char_count=0;			//����������
	}else{                      //����ַ��ظ�
		char_count++;			//���ظ�������+1
	}
	if(char_count>=233){		//���յ�233���ظ�����ʱ
		BL_RESET;				//����
	}
}
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
#if CHECK_EN
/*-------------------------------------------------------
ϵͳ��麯��
-------------------------------------------------------*/
void system_check(){
	u8 i,j;	
	debug("ECBM V%u.%u.%u on %s",(u16)ECBM_FVN,(u16)ECBM_RVN,(u16)ECBM_BVN,ECBM_MCU_NAME);//����汾�ź͵�Ƭ���ͺ�
	#if ECBM_MCU_ROM == 65024
		debug("64");
	#else
		debug("%2u",(u16)(ECBM_MCU_ROM>>10));
	#endif
	#if ECBM_MCU_UART > 1
		debug("S%1u",(u16)(ECBM_MCU_UART));
	#endif
	#if ECBM_MCU_ADC == 1024
		debug("A10");
	#elif ECBM_MCU_ADC == 4096
		debug("A12");
	#endif
	j=0;
	debug("\r\nChecking MCU");
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
		debug("XDATA :%u\tByte\r\n",(u16)ECBM_MCU_XDATA);//�������ļ��л�ȡXDATA����С
		debug("FLASH :%u\tByte\r\n",(u16)ECBM_MCU_ROM);//�������ļ��л�ȡFLASH����С
		debug("EEPROM:%u\tByte\r\n",(u16)ECBM_MCU_EEPROM);//�������ļ��л�ȡEEPROM����С
		debug("HSI   :%lu\tHz\r\n",ecbm_sys_clk);//����ڲ�����ֵ����ͼ�ν���������
		debug("LSI   :%u\tHz\r\n",REG_LSI);//����ڲ�����ֵ����ͼ�ν���������
		debug("BGV   :%u\tmV\r\n",REG_BGV);//����ڲ���ѹ��׼ֵ����Ҫ��STC-ISP������
	}	
}
#endif
/****************************************************************************/#endif
/*----------------------------------����ϵͳ����-----------------------------------*/
#define SYS_HSI_S 0 //�ڲ�����ʱ��HSI(��׼)
#define SYS_HSI_C 1 //�ڲ�����ʱ��HSI(�Զ���)
#define SYS_LSI   2 //�ڲ�����ʱ��LSI
#define SYS_HSE_A 3 //�ⲿ��Դ����
#define SYS_HSE_P 4 //�ⲿ��Դ����
void system_set_clock(u8 source){
	switch(source){
		case SYS_HSI_S:
		case SYS_HSI_C:{
			HIRCCR=0x80;          //ʹ��HSI�����ڲ�24M��IRC��
			while(!(HIRCCR&0x01));//�ȴ�ʱ���ȶ���
			CKSEL&=0xFC;            //�л���HSI��
			XOSCCR=0x00;            //�ر�����ʱ��Դ��ʡ�硣
			IRC32KCR=0x00;          //�ر�����ʱ��Դ��ʡ�硣
		}break;
		case SYS_LSI:{
			IRC32KCR=0x80;          //ʹ��LSI�����ڲ�32K��IRC��
			while(!(IRC32KCR&0x01));//�ȴ�ʱ���ȶ���
			CKSEL|=0x03;            //�л���LSI��
			XOSCCR=0x00;            //�ر�����ʱ��Դ��ʡ�硣
			HIRCCR=0x00;          //�ر�����ʱ��Դ��ʡ�硣
		}break;
		case SYS_HSE_A:{
			XOSCCR=0x80;            //ʹ��HSE����Դ���񣩡�
			while(!(XOSCCR&0x01));  //�ȴ�ʱ���ȶ���
			CKSEL=(CKSEL&0xFC)|0x01;//�л���HSE����Դ���񣩡�
			IRC32KCR=0x00;          //�ر�����ʱ��Դ��ʡ�硣
			HIRCCR=0x00;          //�ر�����ʱ��Դ��ʡ�硣
		}break;
		case SYS_HSE_P:{
			XOSCCR=0xC0;            //ʹ��HSE����Դ���񣩡�
			while(!(XOSCCR&0x01));  //�ȴ�ʱ���ȶ���
			CKSEL=(CKSEL&0xFC)|0x02;//�л���HSE����Դ���񣩡�
			IRC32KCR=0x00;          //�ر�����ʱ��Դ��ʡ�硣
			HIRCCR=0x00;          //�ر�����ʱ��Դ��ʡ�硣
		}break;
	}
}
void system_set_div(u8 div){
	if(div==0){     //�ų���0������ȶ�ѡ�
		CLKDIV=1;   //�������0�Ļ��͸ĳ�1��
	}else{
		CLKDIV=div; //�������0����ֱ��д��Ĵ�����
	}
}
/*-------------------------------------------------------
�⺯��ϵͳ��ʼ������
-------------------------------------------------------*/
void system_init(void){
	#if SYS_CLOCK == 0    
	u32 sys_count;
	#endif
	EX_SFR_ON;//�򿪶���ļĴ�����


	#define ECBM_SYSCLK_STEP1 48000
	#define ECBM_SYSCLK_STEP2 76000
	#define ECBM_SYSCLK_STEP  54000	
	
	
	#if SYS_CLOCK == 0//���ʹ���˱�׼Ƶ�ʣ�HSI����
	#if ECBM_MCU_MAIN_RAM == 2//����ǲ���������Ƶ�ε��ͺš�
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
	#elif SYS_CLOCK == 2
	ecbm_sys_clk=REG_LSI;
	#else 
	ecbm_sys_clk=SYS_CLK_SET;
	#endif
	ecbm_delay_base=ecbm_sys_clk/10000;
	#if SYS_CLOCK >1
	system_set_clock(SYS_CLOCK);
	#endif
	
	#if AUTO_DOWNLOAD_EN//�жϷ���Ҫ�����Զ����ء�
	old_char=0;         //��ʼ��������ر���
	char_count=0;       //��ʼ��������ر���
	debug_busy=0;       //��ʼ��������ر���
	uart_init();
	#endif
	#if SYSCLK_OUT_EN //�ж��Ƿ���Ҫ����ʱ�������
	CKSEL&=0x07;      //���׼����
	CKSEL|=SYSCLK_OUT;//��ͼ�ν��������д�������
	#endif
	#if ECBM_POWER_EN
		#if POWER_RST_CFG_EN
		power_rstcfg_init();
		#endif
	#endif
	EA_ON;//�����жϡ�
	#if CHECK_EN
	delay_ms(200);
	system_check();
	#endif
}
/*-------------------------------------------------------
������
-------------------------------------------------------*/
#if SYS_ERROR_EN
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
#if SOFT_DEBUG
#if ECBM_GPIO_EN == 0  
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
/**********************************strϵ�к���************************/#if SYS_STR_EN
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
/*�������۵�ר��******************CRC16ģ��***********************/#if SYS_CRC16_EN
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