#include "ecbm_core.h"
/*------------------------------------资源冲突警告---------------------------------*/
#if (ECBM_UART_EN == 0)&&(AUTO_DOWNLOAD_EN == 1)
#error 自动下载功能因串口库未加载而开启失败，请前往ecbm_core.h使能串口库！
#endif
#if (UART1_EN == 0)&&(AUTO_DOWNLOAD_EN == 1)
#error 自动下载功能因串口1未使能而开启失败，请前往uart.h使能串口1！
#endif
#if (UART1_IO != 0)&&(AUTO_DOWNLOAD_EN == 1)
#error 自动下载功能需要串口1映射到P30和P31，请前往uart.h修改串口1的输出IO！
#endif
/*--------------------------------------变量定义-----------------------------------*/
u32 xdata ecbm_sys_clk=0;
u16 xdata ecbm_delay_base;
/*-----------------------------------可选模块设定----------------------------------*/
union{
	u32 num32;
	u16 num16[2];
	u8  num8[4];
}fast_cout;
/*-------------------------------------------------------
毫秒级延时函数
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
微秒级延时函数（节拍）
-------------------------------------------------------*/
void delay_us(u16 us){
	u16 i;
	i=us;
	while(i--);
}
/*-------------------------------------------------------
微秒级延时函数的节拍计算函数
-------------------------------------------------------*/
u16 delay_set_us(u16 us){
//公式计算所花的时间太长，拆分成两个函数。先用这个函数推算出延时的数值，再用下面的函数调用。
	fast_cout.num32=((u32)ecbm_delay_base*(u32)(us))*131;
	return fast_cout.num16[0]>>1;
}
/************************************串口调试模块***************/#if AUTO_DOWNLOAD_EN
/*-------------------------------------------------------
自动下载所需的变量
-------------------------------------------------------*/
__IO u8 xdata old_char;  //保存上一次接收的数据
__IO u8 xdata char_count;//相同数据计数
__IO     bit  debug_busy;//发送忙标志位
/*-------------------------------------------------------
下载流判断函数
-------------------------------------------------------*/
void system_uart_reset(){
	if(SBUF!=old_char){			//判断重复字符，如果字符不重复
		old_char=SBUF;			//就更新oldchar
		char_count=0;			//计数器清零
	}else{                      //如果字符重复
		char_count++;			//则重复计数器+1
	}
	if(char_count>=233){		//接收到233个重复数据时
		BL_RESET;				//重启
	}
}
/*-------------------------------------------------------
格式化发送函数
-------------------------------------------------------*/
void debug(const char * str,...){
	char xdata buf[64];  //字符串缓存。
	va_list vp;          //定义参数地址。
    va_start(vp, str);   //赋值参数的地址。
    vsprintf(buf,str,vp);//使用内置的printf函数格式化。
    va_end(vp);          //使用完要关闭。
	uart_string(1,buf);  //将格式化之后的字符串发送出去。
}
#if CHECK_EN
/*-------------------------------------------------------
系统检查函数
-------------------------------------------------------*/
void system_check(){
	u8 i,j;	
	debug("ECBM V%u.%u.%u on %s",(u16)ECBM_FVN,(u16)ECBM_RVN,(u16)ECBM_BVN,ECBM_MCU_NAME);//输出版本号和单片机型号
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
		if((REG_ID(i))==(*(MCUID+i))){
			j++;
		}
	}
	if(j!=7){
		debug("Error\r\nPlease check the setting of the MCU model\r\n");
	}else{
		debug("OK\r\nID    :");for(i=0;i<7;i++){debug("%X",(u16)(*(MCUID+i)));}debug("\r\n");		//输出唯一ID号
		debug("DATA  :128\tByte\r\n");//DATA区固定是128Byte
		debug("IDATA :128\tByte\r\n");//IDATA区固定是128Byte
		debug("XDATA :%u\tByte\r\n",(u16)ECBM_MCU_XDATA);//从配置文件中获取XDATA区大小
		debug("FLASH :%u\tByte\r\n",(u16)ECBM_MCU_ROM);//从配置文件中获取FLASH区大小
		debug("EEPROM:%u\tByte\r\n",(u16)ECBM_MCU_EEPROM);//从配置文件中获取EEPROM区大小
		debug("HSI   :%lu\tHz\r\n",ecbm_sys_clk);//输出内部晶振值，在图形界面上设置
		debug("LSI   :%u\tHz\r\n",REG_LSI);//输出内部晶振值，在图形界面上设置
		debug("BGV   :%u\tmV\r\n",REG_BGV);//输出内部电压基准值，需要在STC-ISP上设置
	}	
}
#endif
/****************************************************************************/#endif
/*----------------------------------其他系统函数-----------------------------------*/
#define SYS_HSI_S 0 //内部高速时钟HSI(标准)
#define SYS_HSI_C 1 //内部高速时钟HSI(自定义)
#define SYS_LSI   2 //内部低速时钟LSI
#define SYS_HSE_A 3 //外部有源晶振
#define SYS_HSE_P 4 //外部无源晶振
void system_set_clock(u8 source){
	switch(source){
		case SYS_HSI_S:
		case SYS_HSI_C:{
			HIRCCR=0x80;          //使能HSI，即内部24M的IRC。
			while(!(HIRCCR&0x01));//等待时钟稳定。
			CKSEL&=0xFC;            //切换到HSI。
			XOSCCR=0x00;            //关闭其他时钟源，省电。
			IRC32KCR=0x00;          //关闭其他时钟源，省电。
		}break;
		case SYS_LSI:{
			IRC32KCR=0x80;          //使能LSI，即内部32K的IRC。
			while(!(IRC32KCR&0x01));//等待时钟稳定。
			CKSEL|=0x03;            //切换到LSI。
			XOSCCR=0x00;            //关闭其他时钟源，省电。
			HIRCCR=0x00;          //关闭其他时钟源，省电。
		}break;
		case SYS_HSE_A:{
			XOSCCR=0x80;            //使能HSE（有源晶振）。
			while(!(XOSCCR&0x01));  //等待时钟稳定。
			CKSEL=(CKSEL&0xFC)|0x01;//切换到HSE（有源晶振）。
			IRC32KCR=0x00;          //关闭其他时钟源，省电。
			HIRCCR=0x00;          //关闭其他时钟源，省电。
		}break;
		case SYS_HSE_P:{
			XOSCCR=0xC0;            //使能HSE（无源晶振）。
			while(!(XOSCCR&0x01));  //等待时钟稳定。
			CKSEL=(CKSEL&0xFC)|0x02;//切换到HSE（无源晶振）。
			IRC32KCR=0x00;          //关闭其他时钟源，省电。
			HIRCCR=0x00;          //关闭其他时钟源，省电。
		}break;
	}
}
void system_set_div(u8 div){
	if(div==0){     //排除掉0这个不稳定选项。
		CLKDIV=1;   //如果输入0的话就改成1。
	}else{
		CLKDIV=div; //如果不是0，就直接写入寄存器。
	}
}
/*-------------------------------------------------------
库函数系统初始化函数
-------------------------------------------------------*/
void system_init(void){
	#if SYS_CLOCK == 0    
	u32 sys_count;
	#endif
	EX_SFR_ON;//打开额外的寄存器。


	#define ECBM_SYSCLK_STEP1 48000
	#define ECBM_SYSCLK_STEP2 76000
	#define ECBM_SYSCLK_STEP  54000	
	
	
	#if SYS_CLOCK == 0//如果使能了标准频率（HSI），
	#if ECBM_MCU_MAIN_RAM == 2//检查是不是有两个频段的型号。
		if(IRCBAND){//如果用的是33M频段，就用中心频率36M来计算。
			sys_count=36000000L-(s32)((s32)REG_HSI1-(s32)IRTRIM)*ECBM_SYSCLK_STEP2;
		}else{//如果用的是24M频段，就用中心频率24M来计算。
			sys_count=24000000L-(s32)((s32)REG_HSI-(s32)IRTRIM)*ECBM_SYSCLK_STEP1;
		}
	#else //如果是使用单频段的型号。
		sys_count=24000000L-(s32)((s32)REG_HSI-(s32)IRTRIM)*ECBM_SYSCLK_STEP;  //就用中心频率24M来计算。
	#endif
	sys_count/=CLKDIV;//算上分频系数。
	if      (sys_count<5764800L ){//格式化处理，计算会有误差，得到不一定是标准频率，在这里格式化成标准频率。
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
		ecbm_sys_clk=35000000;    //最大支持到33M
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
	
	#if AUTO_DOWNLOAD_EN//判断否需要开启自动下载。
	old_char=0;         //初始化串口相关变量
	char_count=0;       //初始化串口相关变量
	debug_busy=0;       //初始化串口相关变量
	uart_init();
	#endif
	#if SYSCLK_OUT_EN //判断是否需要开启时钟输出。
	CKSEL&=0x07;      //填充准备。
	CKSEL|=SYSCLK_OUT;//将图形界面的设置写入参数。
	#endif
	#if ECBM_POWER_EN
		#if POWER_RST_CFG_EN
		power_rstcfg_init();
		#endif
	#endif
	EA_ON;//打开总中断。
	#if CHECK_EN
	delay_ms(200);
	system_check();
	#endif
}
/*-------------------------------------------------------
错误函数
-------------------------------------------------------*/
#if SYS_ERROR_EN
void error_printf(const char * str,...){
	u8 ch,i;         //字符缓存、位发送计数。
	u16 j,len;       //字符发送计数、字符长度。
	char xdata buf[64];//字符串缓存。
	va_list vp;        //定义参数地址。
	u16 _100us; //不使能的话，就自己安排延时相关计数变量
	_100us=delay_set_us(100);//计算延时100us的节拍数
	va_start(vp, str); //赋值参数的地址。
	len=vsprintf(buf,str,vp);//使用内置的printf函数格式化。
	va_end(vp);	       //使用完要关闭。
	while(1){          //因为是错误提示，所以本函数永不退出。
		delay_ms(500);//延时500ms
		for(j=0;j<len;j++){
			error_io=1;      //默认高电平。
			error_io=0;      //拉低表示开始位。
			delay_us(_100us);//延时100us，根据9600波特率设定的。下同。
			ch=buf[j];       //将字符取出来。
			for(i=0;i<8;i++){//按位发送。
				if(ch&0x01){ //先发低位。
					error_io=1;
				}else{
					error_io=0;
				}	
				ch>>=1;      //发完右移，为了下次发送。
				delay_us(_100us);
			}
			error_io=1;      //发送完一个字节，拉高表示停止位。
			delay_us(_100us);
			delay_us(_100us);
		}
	}
}
#endif
/*---------------------------------其他非系统函数---------------------------------*/
/*-------------------------------------------------------
软件串口。
-------------------------------------------------------*/
#if SOFT_DEBUG
#if ECBM_GPIO_EN == 0  
#error 软调试功能需要GPIO库的支持，请确认GPIO库呈使能状态。
#endif 
void debug_soft(u8 io,const char * str,...){
	u8 i;                     //位发送计数。
	u16 j,len;                //字符发送计数、字符长度。
	u16 delay_debug;
	char xdata buf[64];       //字符串缓存。
	va_list vp;               //定义参数地址。
    va_start(vp, str);        //赋值参数的地址。
    len=vsprintf(buf,str,vp); //使用内置的printf函数格式化。
    va_end(vp);	              //使用完要关闭。
	delay_debug=delay_set_us(100);
	for(j=0;j<len;j++){
		gpio_out(io,1);       //默认高电平。
		gpio_out(io,0);       //拉低表示开始位。
		delay_us(delay_debug);//延时100us，根据9600波特率设定的。下同。
		for(i=0;i<8;i++){     //按位发送。
			if(buf[j]&0x01){  //先发低位。
				gpio_out(io,1);
			}else{
				gpio_out(io,0);
			}	
			buf[j]>>=1;       //发完右移，为了下次发送。
			delay_us(delay_debug);
		}
		gpio_out(io,1);       //发送完一个字节，拉高表示停止位。
		delay_us(delay_debug);//延时200us，和上面的解说一样。
		delay_us(delay_debug);
	}
}
#endif
/**********************************str系列函数************************/#if SYS_STR_EN
/*-------------------------------------------------------
字符串查找函数。
-------------------------------------------------------*/
u16 str_find(char * dest,char * key){
	u16 key_count=0,key_first=0,count=0;
	
	while(*dest){	//判断目标字符串。
		count++;	//记录循环的次数。
		if(key[key_count]==(*dest)){//假如关键词字符串当前位比对成功，
			key_count++;			//那么就比较下一位。
		}else{						//假如没有比对成功，
			key_count=0;			//那么就从头开始比对。
			key_first=count;		//重置第一位出现位置。
		}
		dest++;						//读取目标字符串的下一位。
		if(key[key_count]==0){		//如果关键词字符串比对完，
			return key_first;		//返回关键词字符串第一次出现的位置。
		} 
	}
	return 0xffff;//能运行到这一步，说明直到目标字符串结束都没有比对成功，返回-1。
	//优化了194字节
	
//	u16 dest_c,   key_c;  //变量计数函数。
//	u16 dest_len, key_len;//字符串长度。
//	char * dest_t,* key_t;//计算长度所需的临时变量。
//	dest_t  =dest;        //将目标字符串放入临时变量中。
//	key_t   =key;         //将查找关键字字符串放入临时变量中。
//	dest_len=0;           //清零计数变量。
//	key_len =0;           //清零计数变量。
//	while(*dest_t){       //计算出目标字符串的长度。
//		dest_len++;       //计算原理是判断字符串中非0字符的个数。
//		dest_t++;         //指针+1。下一次的字符是0的话，这个循环就结束了。
//	}
//	while(*key_t){        //计算出关键字字符串的长度。
//		key_len++;        //计算原理是判断字符串中非0字符的个数。
//		key_t++;          //指针+1。下一次的字符是0的话，这个循环就结束了。
//	}
//	if(dest_len<key_len){ //如果目标的长度比关键字的长度短，说明这是有问题的。
//		return 0xffff;    //返回0xFFFF。
//	}
//	for(dest_c=0;dest_c<=(dest_len-key_len);dest_c++){ //假如目标字符串有10个，关键字有3个。那么最多检测到第7个字符的时候就有结论了。
//		for(key_c=0;key_c<key_len;key_c++){            //关键字有几个，就判断几次。
//			if(dest[dest_c+key_c]!=key[key_c]){        //只要遇到有一个比对不上的，立马跳出这次判断。
//				break;
//			}
//		}
//		if(key_c==key_len){                            //只有全部比对完毕，才会相等。
//			return dest_c;                             //那么此时返回的就是关键字第一次出现在字符串里的位置。
//		}
//	}
//	return 0xffff;        //没找到就返回0xFFFF。
}
/*-------------------------------------------------------
IO信息读取函数。
-------------------------------------------------------*/
u8 str_read_pin(char * str,u16 pos){
	u8  dat=0,offset,count; //从左往右依次是读取的信息、字符串偏移和字数统计。
	count=0;                //字数统计清零。
	for(offset=0;offset<10;offset++){//预留10个偏移量。
		if((str[pos+offset]>='0')&&(str[pos+offset]<='7')){//IO口的编号都是从0~7。
			count++;                            //在这个范围内，字数+1。
			if(count==1){                       //如果是第一个数，
				dat=(str[pos+offset]-'0')<<4;   //解析出来放到高4位。
			}
			if(count==2){                       //如果是第二个数，
				dat=(str[pos+offset]-'0')|dat;  //解析出来放到低4位。
				return dat;                     //返回该值。
			}
		}
		if((str[pos+offset]>='8')&&(str[pos+offset]<='9')){//如果是8和9，那么只增加字数，不写入值。
			count++;
		}
		if(str[pos+offset]==',')break;//遇到逗号就退出。
		if(str[pos+offset]==0)break;  //字符串结束也退出。
	}
	return 	dat;
}
/*-------------------------------------------------------
u16变量读取函数。
-------------------------------------------------------*/
u16 str_read_u16(char * str,u16 pos){
	u16 dat=0; //读取的信息。
	u8  offset;//字符串偏移。
	for(offset=0;offset<20;offset++){//预留20个字符的偏移。
		if((str[pos+offset]>='0')&&(str[pos+offset]<='9')){//数字都是从0~9。
			dat*=10;                  //变量增加一位，即原来是12，就变成120，空出的个数就拿来装新的数。
			dat+=str[pos+offset]-'0'; //将新的数加到个位上。
		}
		if(str[pos+offset]==',')break;//遇到逗号就退出。
		if(str[pos+offset]=='.')break;//遇到点号就退出。
		if(str[pos+offset]==0)break;  //字符串结束也退出。
	}
	return 	dat;
}
/*-------------------------------------------------------
字符串推出指令函数（带字符串长度参数版）。
-------------------------------------------------------*/
u8 str_push_len(u8 * dest,u16 dlen,u8 * key,u16 klen){
	u16 i,j=0,start=0,stop=0;
	for(i=0;i<dlen;i++){		//从头开始，直到指定的长度。
		if(dest[i]==key[j]){	//把当前的字符和关键词比较成功，
			j++;				//取关键词的下一个字。
			if(j==klen){		//当关键词全部比对完成的时候。
				stop=i;			//保存【结束位置】。
				break;			//退出循环。
			}
		}else{					//如果当前的字符和关键词比较失败，
			j=0;				//下一次从头开始比对。
			start=i+1;			//更新【开始位置】为下一位（因为当前位失败了）。
		}
	}
	if(start<=stop){			//当比对成功的时候，【开始位置】肯定小于等于【结束位置】。
		for(i=start;i<stop;i++){//将从【开始位置】到【结束位置】之间的缓存全清零。
			dest[i]=0;
		}
		return 1;				//返回推出成功。
	}else{
		return 0;				//返回推出失败。
	}
}
/*****************************************************************************/#endif
/*程序区折叠专用******************CRC16模块***********************/#if SYS_CRC16_EN
/*-------------------------------------------------------
计算CRC16函数。
-------------------------------------------------------*/
u16 crc16(u8 buf[],u16 len){
    u16 crc_value= 0xFFFF; 							//初始化CRC变量各位为1。
    u8 i,j;											//循环用的临时变量。
    for(i=0;i<len;i++){								//计算缓存的每一个字节。
        crc_value^=buf[i];							//当前数据异或CRC低字节，在C51里可以直接处理。
        for(j=0;j<8;j++){							//计算每个字节的每一位。
            if(crc_value&0x01){						//判断右移前最低位是否为1。
                 crc_value=(crc_value>>1)^0xA001;	//如果为1则右移并异或表达式。
            }else{
                crc_value>>=1;						//否则直接右移一位。
            }           
        }
    } 
    return crc_value;								//返回计算CRC16的结果。
}
/*-------------------------------------------------------
插入CRC16函数。
-------------------------------------------------------*/
void crc16_insert_buf(u8 buf[],u16 len){
	u16 value;					//临时变量。
	value=crc16(buf,len-2);		//计算出CRC16值。
	buf[len-2]=(u8)(value>>8);	//按高位在前，
	buf[len-1]=(u8)(value);		//低位在后的顺序存放。
}
/*-------------------------------------------------------
检查CRC16函数。
-------------------------------------------------------*/
u8 crc16_check_buf(u8 buf[],u16 len){
	if(crc16(buf,len-2)==((buf[len-2]<<8)+(buf[len-1]))){//计算前面的CRC16值和后面保存的CRC16值比较。
		return 1;//比较成功返回1；
	}else{
		return 0;//比较失败返回0；
	}
}
/*程序区折叠专用************************************************************/#endif