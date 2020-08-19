#include "fast_uart_reg.h"
/*--------------------------------------变量定义-----------------------------------*/
fur_u8  fur_bit              =0;  //寄存器位数标志。
fur_u8  fur_flag             =0;  //寄存器状态。
fur_u8  fur_state            =0;  //串口接收状态机变量。
fur_u8  fur_cmd_start        =0;  //环形缓存的开始指针。
fur_u8  fur_cmd_end          =0;  //环形缓存的结束指针。
fur_u8  fur_cmd_wr_buf[16]   ={0};//指令读写状态环形缓存，用于异步处理中分辨指令是读还是写。
fur_u16 fur_cmd_buf   [16]   ={0};//指令环形缓存，用于减轻串口中断压力。
fur_u16 fur_reg_point        =0;  //寄存器指针，指向要写入的寄存器。
fur_u16 fur_reg_temp         =0;  //写入寄存器的缓存。
fur_u16 fur_reg_buf   [16]   ={0};//影子寄存器，串口写入的数据先在这里存放，验证后再存入本体。
fur_u16 fur_reg[ECBM_FUR_REG_MAX+FUR_REG_OFFSET];//寄存器本体，直接和功能挂钩。
fur_u16 fur_addr                 ;//主机模式下，用于验证地址返回值。
fur_u16 fur_dat                  ;//主机模式下，用于验证数据返回值。
fur_u16 fur_id                   ;//ID过滤功能
/*------------------------------------资源冲突警告---------------------------------*/
#if (ECBM_FUR_EEPROM_EN == 1) && (ECBM_EEPROM_EN == 0)
#error EEPROM功能没有使能，请关闭FUR的保存功能或者打开片内EEPROM使能！
#endif
#if ECBM_UART_EN == 0
#error FUR是基于串口的应用，请打开UART使能！
#endif
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
FUR功能的串口打印函数。
-------------------------------------------------------*/
void fur_printf_base(const char * str,...){
	char xdata buf[64];  //字符串缓存。
	va_list vp;          //定义参数地址。
    va_start(vp, str);   //赋值参数的地址。
    vsprintf(buf,str,vp);//使用内置的printf函数格式化。
    va_end(vp);          //使用完要关闭。
	uart_string(ECBM_FUR_UART_ID,buf);  //将格式化之后的字符串发送出去。
}
/*-------------------------------------------------------
FUR功能的串口读取函数。
-------------------------------------------------------*/
void fur_in(u8 buf){
	switch(fur_state){
		case 0:{				//等待开始帧。
			if(buf=='['){		//检测到开始帧时，
				fur_state=1;	//到下一个状态，
				fur_reg_point=0;	//初始化寄存器地址。
			}
			if(buf=='h'){		//help
				fur_state=10;	//到下一个状态，
			}
		}break;
		case 1:{				//登记寄存器地址。
			if(buf==']'){		//如果收到结束帧，
				fur_state=2;	//到下一个状态。
				fur_cmd_in=0;//初始化读写指令。
			}else if((buf>='0')&&(buf<='9')){//如果收到数字，
				fur_reg_point*=10;			//接收数字。
				fur_reg_point+=buf-'0';
			}else if(buf=='@'){//如果收到了@，说明有ID过滤了。
				fur_id=0;
				fur_state=5;	//到下一个状态。
			}else if(buf=='['){//如果在本状态再次收到开始帧，只做清零寄存器地址处理。
				fur_reg_point=0;//初始化寄存器地址。
			}else{				//收到意外字符，
				fur_state=0;	//跳转回等待态。
			}
		}break;
		case 2:{				//等待后续帧。
			if(buf=='='){		//接收到后续帧后，
				fur_state=3;	//到下一个状态。
				fur_bit=100;
				fur_reg_temp=0;		//初始化寄存器内容缓存。
			}else if(buf=='&'){
				fur_cmd_in=0x10;//初始化读写指令。
			}else if(buf=='|'){
				fur_cmd_in=0x20;//初始化读写指令。
			}else if(buf=='['){//如果收到开始帧，
				fur_state=1;	//回到登记地址态。
				fur_reg_point=0;	//初始化寄存器地址。
			}else if(buf=='^'){
				fur_bit=0;
				fur_state=6;
			}else{				//收到意外字符，
				fur_state=0;	//跳转回等待态。
			}
		}break;
		case 3:{				//登记寄存器内容。
			if(buf=='?'){		//接收到读取指令，
				fur_cmd_buf[fur_cmd_end]=fur_reg_point;//记录到指令缓存中。
				fur_cmd_in=0;
				fur_cmd_end++;
				fur_cmd_end&=0x0f;
				fur_state=0;	
			}else if(buf=='['){//如果在这时候收到开始帧，
				fur_state=1;	//回退到登记地址的状态。
				fur_reg_point=0;	//初始化寄存器地址。
			}else if((buf=='x')||(buf=='X')){//
				fur_reg_temp=0;		//
				fur_state=4;	//
			}else if((buf>='0')&&(buf<='9')){	//如果收到数字，
				fur_reg_temp*=10;					//接收数字。
				fur_reg_temp+=buf-'0';
			}else if(buf=='.'){//如果收到结束帧，
				fur_reg_buf[fur_cmd_end]=fur_reg_temp;//写入到寄存器。
				fur_cmd_buf[fur_cmd_end]=fur_reg_point;//记录到指令缓存中。
				fur_cmd_in+=0x10;
				fur_cmd_end++;
				fur_cmd_end&=0x0f;
				fur_state=0;	
			}else{				//收到意外字符，
				fur_state=0;	//跳转回等待态。
			}
		}break;
		case 4:{				//登记寄存器内容(HEX模式)。
			if(buf=='?'){		//接收到读取指令，
				fur_cmd_buf[fur_cmd_end]=fur_reg_point;//记录到指令缓存中。
				fur_cmd_in=0;
				fur_cmd_end++;
				fur_cmd_end&=0x0f;
				fur_state=0;
			}else if(buf=='['){//如果在这时候收到开始帧，
				fur_state=1;	//回退到登记地址的状态。
				fur_reg_point=0;	//初始化寄存器地址。
			}else if((buf>='0')&&(buf<='9')){	//如果收到数字，
				fur_reg_temp*=16;					//接收数字。
				fur_reg_temp+=buf-'0';
			}else if((buf>='A')&&(buf<='F')){	//如果收到数字，
				fur_reg_temp*=16;					//接收数字。
				fur_reg_temp+=(buf-'A')+10;
			}else if((buf>='a')&&(buf<='f')){	//如果收到数字，
				fur_reg_temp*=16;					//接收数字。
				fur_reg_temp+=(buf-'a')+10;
			}else if(buf=='.'){//如果收到结束帧，
				fur_reg_buf[fur_cmd_end]=fur_reg_temp;//写入到寄存器。
				fur_cmd_buf[fur_cmd_end]=fur_reg_point;//记录到指令缓存中。
				fur_cmd_in+=0x10;
				fur_cmd_end++;
				fur_cmd_end&=0x0f;
				fur_state=0;	
			}else{				//收到意外字符，
				fur_state=0;	//跳转回等待态。
			}
		}break;
		case 5:{//接收ID地址
			if(buf==']'){		//如果收到结束帧，
				if((fur_id&0x00ff)!=(fur_reg[1]&0x00ff)){
					fur_state=0;//跳转回等待态。
				}else{
					fur_state=2;	//到下一个状态。
				}
			}else if((buf>='0')&&(buf<='9')){//如果收到数字，
				fur_id*=10;			//接收数字。
				fur_id+=buf-'0';
			}else if(buf=='['){//如果在本状态再次收到开始帧，只做清零寄存器地址处理。
				fur_state=1;	//回到登记地址态。
				fur_reg_point=0;	//初始化寄存器地址。
			}else{				//收到意外字符，
				fur_state=0;	//跳转回等待态。
			}
		}break;
		case 6:{//接收位地址
			if(buf=='='){		//接收到后续帧后，
				if(fur_bit<16){			
					fur_cmd_in=0x30+fur_bit;//初始化读写指令。
					fur_state=3;	//到下一个状态。
					fur_reg_temp=0;		//初始化寄存器内容缓存。
				}else{
					fur_state=0;	//跳转回等待态。
				}
			}else if((buf>='0')&&(buf<='9')){//如果收到数字，
				fur_bit*=10;			//接收数字。
				fur_bit+=buf-'0';
			}else if(buf=='['){//如果在本状态再次收到开始帧，只做清零寄存器地址处理。
				fur_state=1;	//回到登记地址态。
				fur_reg_point=0;	//初始化寄存器地址。
			}else{				//收到意外字符，
				fur_state=0;	//跳转回等待态。
			}
		}break;
		case 10:{//e
			if(buf=='e'){		//help
				fur_state=11;	//到下一个状态，
			}else if(buf=='['){		//检测到开始帧时，
				fur_state=1;	//到下一个状态，
				fur_reg_point=0;	//初始化寄存器地址。
			}else{
				fur_state=0;	//到下一个状态，
			}
		}break;
		case 11:{//l
			if(buf=='l'){		//help
				fur_state=12;	//到下一个状态，
			}else if(buf=='['){		//检测到开始帧时，
				fur_state=1;	//到下一个状态，
				fur_reg_point=0;	//初始化寄存器地址。
			}else{
				fur_state=0;	//到下一个状态，
			}
		}break;
		case 12:{//p
			if(buf=='p'){		//help
				fur_state=13;	//到下一个状态，
			}else if(buf=='['){		//检测到开始帧时，
				fur_state=1;	//到下一个状态，
				fur_reg_point=0;	//初始化寄存器地址。
			}else{
				fur_state=0;	//到下一个状态，
			}
		}break;
		case 13:{//.
			if(buf=='.'){		//如果收到结束帧，
				fur_state=14;	//触发help
				fur_dat=65535;
			}else if(buf=='['){		//检测到开始帧时，
				fur_state=1;	//到下一个状态，
				fur_reg_point=0;	//初始化寄存器地址。
			}else if(buf=='-'){
				fur_state=15;	//到下一个状态
				fur_dat=0;
			}else{
				fur_state=0;	//到下一个状态，
			}
		}break;
		case 15:{
			if(buf=='.'){		//如果收到结束帧，
				fur_state=14;	//触发help
			}else if((buf>='0')&&(buf<='9')){//如果收到数字，
				fur_dat*=10;			//接收数字。
				fur_dat+=buf-'0';
			}else if(buf=='['){//如果在本状态再次收到开始帧，只做清零寄存器地址处理。
				fur_reg_point=0;	//初始化寄存器地址。
			}else{				//收到意外字符，
				fur_state=0;	//跳转回等待态。
			}
		}break;
	}
}
/*-------------------------------------------------------
FUR的校对和返回函数。
-------------------------------------------------------*/
void fur_check(void){
	if(fur_state==14){//该状态说明上位机需要一份寄存器说明。这个说明需要提前写。
		fur_state=0;
		if(fur_dat==65535){
			fur_printf("Fast-Uart-Reg %s in ECBM\r\n",FUR_VER);
			fur_printf("本机ID:%u\r\n",fur_reg[1]&0x00FF);//返回本机ID
			if(fur_reg[1]&0x8000){     
				fur_printf("显示模式:16进制\r\n");
			}else{
				fur_printf("显示模式:10进制\r\n");
			}
			fur_printf("REG[60000]:波特率寄存器(读写)\r\n");
			fur_printf("REG[60001]:触发寄存器  (只写)\r\n");
			fur_printf("REG[60002]:ID号寄存器  (读写)\r\n");
			fur_printf("REG[60003]:寄存器总数\xFD  (只读)\r\n");
			
			fur_printf("触发寄存器支持:\r\n");
			fur_printf("[60001]=10.显示10进制\r\n");
			fur_printf("[60001]=16.显示16进制\r\n");
			#if	ECBM_FUR_EEPROM_EN == 1
			fur_printf("[60001]=0xA55A.保存设置\r\n");
			fur_printf("[60001]=0xF00F.读取设置\r\n");
			#endif
			fur_printf("\r\n用户寄存器:%u 个\r\n",(u16)ECBM_FUR_REG_MAX);//返回寄存器数量
		}
		#if ECBM_FUR_HELP_EN == 1
		fur_help(fur_dat);//如果没有定义这个函数，那么本条指令必定死机。
		#else
		fur_printf("\r\n用户寄存器说明书没有写呢!\r\n");//若帮助功能没开启，则提示一下。
		#endif
	}
	while(fur_cmd_start!=fur_cmd_end){//只在环形缓存中头尾指针不一致的时候才往下执行。
		
/*------------------------------------------------主体执行部分开始---------------------------------------------------------*/	
		fur_addr=fur_cmd_buf[fur_cmd_start];//将接收到的地址解析出来。
		fur_dat =fur_reg_buf[fur_cmd_start];//将接收到的数据解析出来。
		if(fur_flag&FUR_FLAG_MS_M){//-------------以下是主机部分------------------------------------------------------------
			fur_flag|=FUR_M_FLAG_READ;//通知外部函数，已经成功接收。
		}else{//-----------------------------------以下是从机部分------------------------------------------------------------
			if(fur_addr<ECBM_FUR_REG_MAX){//判断地址是否在规定范围内。			
				if((fur_cmd_out&0xf0)==0x10){//判断是不是直接写指令，
					fur_cmd_out=0;//是的话就清除指令。
					fur_reg_in(fur_addr,fur_dat);//往寄存器里写入数据，当然必须要有地址偏移。
				}else if((fur_cmd_out&0xf0)==0x20){//判断是不是与写指令，
					fur_cmd_out=0;//是的话就清除指令。
					fur_reg_in(fur_addr,fur_reg_out(fur_addr)&fur_dat);//将原来寄存器的内容与上新的内容再写进去。
				}else if((fur_cmd_out&0xf0)==0x30){//判断是不是或写指令，
					fur_cmd_out=0;//是的话就清除指令。
					fur_reg_in(fur_addr,fur_reg_out(fur_addr)|fur_dat);//将原来寄存器的内容或上新的内容再写进去。
				}else if((fur_cmd_out&0xf0)==0x40){//判断是不是或写指令，
					if(fur_dat){
						fur_reg_in(fur_addr,fur_reg_out(fur_addr)|(1<<(fur_cmd_out&0x0f)));//
					}else{
						fur_reg_in(fur_addr,fur_reg_out(fur_addr)&(~(1<<(fur_cmd_out&0x0f))));//
					}
					fur_cmd_out=0;//是的话就清除指令。
				}
				
				//下一句是返回值功能，在查询指令下，返回寄存器的值供查看。在写指令下，返回寄存器的值供写入验证。
				if(fur_reg[1]&0x8000){
					fur_printf("[%u]=0x%04X.\r\n",fur_addr,fur_reg_out(fur_addr));
				}else{
					fur_printf("[%u]=%u.\r\n",fur_addr,fur_reg_out(fur_addr));
				}
				#if ECBM_FUR_WR_CALLBACK_EN == 1//当执行了寄存器读写操作就调用相应的回调函数。
				fur_reg_io_callback(fur_addr,fur_dat);
				#endif
			}else if(fur_addr==60000){//判断地址是不是波特率寄存器。
				if(fur_cmd_out){//判断是不是写指令，
					fur_cmd_out=0;//是的话，就请往下执行，清除指令。
					fur_reg[0]=fur_dat;//将影子寄存器的值写入寄存器中，
					fur_printf("OK[65535]=0.\r\n");//成功接收时，返回OK。
					uart_set_baud(ECBM_FUR_UART_ID,(u32)fur_reg[0]*100);//同时扩大100倍成正确的波特率，然后修改波特率。
				}else{
					fur_printf("BAUD=%lu\r\n",(u32)fur_reg[0]*100);//如果是查询指令，就返回
				}
			}else if(fur_addr==60001){//判断地址是不是触发寄存器。
				if(fur_cmd_out){//判断是不是写指令，
					fur_cmd_out=0;//是的话，就请往下执行，清除指令。
					if(fur_dat==0xA55A){//写入0xA55A的话，就会把当前所有的设置都保存下来。
						#if	ECBM_FUR_EEPROM_EN == 1	
						eeprom_write_ex(0,(u8 *)fur_reg,(ECBM_FUR_REG_MAX+FUR_REG_OFFSET)*2);//调用内部eeprom写函数保存信息。
						#else
						fur_flag|=FUR_FLAG_DATA;//若保存功能没开启，则置数据错误标志位。
						#endif
					}else if(fur_dat==0xF00F){//写入0xF00F的话，就会读取保存的信息替换当前所有的设置。
						#if	ECBM_FUR_EEPROM_EN == 1	
						eeprom_read_ex(0,(u8 *)fur_reg,(ECBM_FUR_REG_MAX+FUR_REG_OFFSET)*2);//调用内部eeprom读函数读取信息。
						#else
						fur_flag|=FUR_FLAG_DATA;//若保存功能没开启，则置数据错误标志位。
						#endif
					}else if(fur_dat==10){//写入10的话，就会把用户寄存器显示格式设置成十进制。
						fur_reg[1]&=0x7FFF;
					}else if(fur_dat==16){//写入16的话，就会把用户寄存器显示格式设置成十六进制。
						fur_reg[1]|=0x8000;
					}else{
						fur_flag|=FUR_FLAG_DATA;//寄存器60001是触发寄存器，如果什么都不触发，也算是一种错误。
					}
				}else{
					fur_flag|=FUR_FLAG_DATA;//寄存器60001是触发寄存器，具有只写属性，如果是读指令，也算是一种错误。
				}
				if(fur_flag&FUR_FLAG_DATA){//如果发生触发寄存器的数据错误，要及时回传信息。
					#if ECBM_FUR_ERR_CALLBACK_EN == 0//不使能错误回调的时候，才清零。否则回调函数找不到参数。
					fur_flag&=~FUR_FLAG_DATA;//处理完就清零标志位。
					#endif
					fur_printf("Reg Cmd Error![65535]=1.\r\n");
				}else{
					fur_printf("OK[65535]=0.\r\n");//成功接收时，返回OK。
				}
			}else if(fur_addr==60002){//ID号寄存器
				if(fur_cmd_out){//判断是不是写指令，
					fur_cmd_out=0;//是的话，就请往下执行，清除指令。
					fur_dat&=0x00ff;
					fur_reg[1]&=0xff00;
					fur_reg[1]|=fur_dat;//修改ID号
				}
				fur_printf("ID[60002]=%u.\r\n",fur_reg[1]&0x00ff);
			}else if(fur_addr==60003){//寄存器数量寄存器（有点绕）
				fur_printf("REG_NUM[60003]=%u.\r\n",(u16)ECBM_FUR_REG_MAX);
			}else{//因地址错误而不能读写的，返回错误码。
				#if ECBM_FUR_ERR_CALLBACK_EN == 1//此处本来也是清零位的，但是先置位再清零有点多余，就合并起来。
				fur_flag|=FUR_FLAG_ADDR;//置地址错误标志位。
				#endif
				fur_printf("Reg Addr Error![65535]=2.\r\n");
			}
			#if ECBM_FUR_ERR_CALLBACK_EN == 1//当执行了寄存器读写操作就调用相应的回调函数。
			fur_error_callback(fur_flag&0x7F);
			#endif
		}
/*------------------------------------------------主体执行部分结束---------------------------------------------------------*/	
		fur_cmd_start++;//环形缓存的做法，头指针++。
		fur_cmd_start&=0x0f;//限定在16字节。
	}
}			
/*-------------------------------------------------------
FUR的初始化函数。
-------------------------------------------------------*/
void fur_init(void){
#if	ECBM_FUR_EEPROM_EN == 1	
	fur_u8 i;
#endif	
	fur_u16 temp;
#if   ECBM_FUR_UART_ID == 1	
	temp=UART1_BAUD_RATE/100;//写入波特率默认值。
#elif ECBM_FUR_UART_ID == 2
	temp=UART2_BAUD_RATE/100;//写入波特率默认值。
#elif ECBM_FUR_UART_ID == 3
	temp=UART3_BAUD_RATE/100;//写入波特率默认值。
#elif ECBM_FUR_UART_ID == 4
	temp=UART4_BAUD_RATE/100;//写入波特率默认值。
#endif
	fur_reg[0]=temp;
	fur_reg[1]=ECBM_FUR_ID;
#if	ECBM_FUR_EEPROM_EN == 1	
	eeprom_init();//初始化内部的eeprom，现在STC都有这个。
	eeprom_read_ex(0,(u8 *)fur_reg,(ECBM_FUR_REG_MAX+FUR_REG_OFFSET)*2);//读取保存的值。
	if(fur_reg[0]==0xffff){//如果从来没有保存过，或者波特率有变化
		for(i=0;i<(ECBM_FUR_REG_MAX+FUR_REG_OFFSET);i++){//就全部初始化为0。
			fur_reg[i]=0;
		}
		fur_reg[0]=temp;
		fur_reg[1]=ECBM_FUR_ID;
		eeprom_write_ex(0,(u8 *)fur_reg,(ECBM_FUR_REG_MAX+FUR_REG_OFFSET)*2);//再将初始化的值写入。
	}
	uart_set_baud(ECBM_FUR_UART_ID,(u32)fur_reg[0]*100);
#endif
}

/*-------------------------------------------------------
FUR的串口重置函数。
-------------------------------------------------------*/
void fur_reg_uart_reset(void){
	uart_set_baud(ECBM_FUR_UART_ID,115200);
}
/*-------------------------------------------------------
FUR主机的读取函数，用于读取另一个从机的寄存器。
-------------------------------------------------------*/
u16 fur_read(u16 addr){
	fur_u16 timeout=2000;		//设定超时时间为2秒。
	fur_flag|=FUR_FLAG_MS_M;//设定FUR为主机模式。
	fur_printf("[%u]=?.\r\n",addr);//发送查询指令。
	fur_flag&=~FUR_M_FLAG_TIME;//清零超时标志位。
	while(timeout--){		//循环等待，有超时判定。
		delay_ms(1);		//每1ms
		fur_check();		//查询一次数据。
		if(fur_flag&FUR_M_FLAG_READ){//接收到数据时，
			if(addr==fur_addr){//如果返回的地址和发送的地址一致，
				fur_flag|=FUR_M_FLAG_OK;//可以认为是正确接收。
				fur_flag&=FUR_FLAG_MS_S;//切换到从机模式。
				return fur_dat;//返回接收的数据。
			}else{//如果返回的地址和发送的地址不一致，
				if(fur_addr==65535){//且返回地址为65535。
					switch(fur_dat){//说明传输发生了错误，接收到的数据是错误码。
						case 1:fur_flag|=FUR_M_FLAG_DATA;break;//翻译错误码，置相应标志位。
						case 2:fur_flag|=FUR_M_FLAG_ADDR;break;
					}
				}else{//如果是其他地址，虽然产生问题的原因未知，
					fur_flag|=FUR_M_FLAG_ADDR;//但最明显的就是返回的地址有问题。
				}
				#if ECBM_FUR_ERR_CALLBACK_EN == 1
				fur_error_callback(fur_flag&0x7F);//调用出错回调函数。
				#endif
				fur_flag&=FUR_FLAG_MS_S;//切换到从机模式。
				return 0;//默认返回0。
			}
		}
	}
	if(timeout==65535){//如果超时的话，
		fur_flag|=FUR_M_FLAG_TIME;//置超时标志位。
	}
	fur_flag&=FUR_FLAG_MS_S;//切换到从机模式。
	return 0;//默认返回0。
}
/*-------------------------------------------------------
FUR主机的读写函数，用于向一个从机的寄存器写入一个值。
-------------------------------------------------------*/
void fur_write(u16 addr,u16 dat){
	fur_u16 timeout=2000;		//设定超时时间为2秒。
	fur_flag|=FUR_FLAG_MS_M;//设定FUR为主机模式。
	fur_printf("[%u]=%u.\r\n",addr,dat);//发送读写指令。
	fur_flag&=~FUR_M_FLAG_TIME;//清零超时标志位。
	while(timeout--){		//循环等待，有超时判定。
		delay_ms(1);		//每1ms
		fur_check();		//查询一次数据。
		if(fur_flag&FUR_M_FLAG_READ){//接收到数据时，
			if(addr==fur_addr){//如果返回的地址和发送的地址一致，
				if(dat==fur_dat){//且返回的数据也一致，
					fur_flag|=FUR_M_FLAG_OK;//可以认为是正确接收。
					goto fur_write_return;//跳出循环，直达函数尾。
				}else{//如果返回的数据有问题，
					fur_flag|=FUR_M_FLAG_DATA;//置数据错误标志位。
					goto fur_write_return;//跳出循环，直达函数尾。
				}				
			}else{//如果返回的地址和发送的地址不一致，
				if(fur_addr==65535){//且返回地址为65535。
					switch(fur_dat){//说明传输发生了错误，接收到的数据是错误码。
						case 1:fur_flag|=FUR_M_FLAG_DATA;break;//翻译错误码，置相应标志位。
						case 2:fur_flag|=FUR_M_FLAG_ADDR;break;
					}
				}else{//如果是其他地址，虽然产生问题的原因未知，
					fur_flag|=FUR_M_FLAG_ADDR;//但最明显的就是返回的地址有问题。
				}
				#if ECBM_FUR_ERR_CALLBACK_EN == 1
				fur_error_callback(fur_flag&0x7F);//调用出错回调函数。
				#endif
				goto fur_write_return;//跳出循环，直达函数尾。
			}
		}
	}
	if(timeout==65535){//如果超时的话，
		fur_flag|=FUR_M_FLAG_TIME;//置超时标志位。
	}
fur_write_return:
	fur_flag&=FUR_FLAG_MS_S;//切换到从机模式。
}