#include "ecbm_core.h"  //统一加载核心头文件
/*------------------------------------资源冲突警告---------------------------------*/
#if (ECBM_AUTO_DOWNLOAD_EN)
#   if (ECBM_UART_LIB_EN==0)
#       warning 因串口库未使能,自动下载功能失效!
#   endif
#   if (ECBM_UART1_EN==0)
#       error 自动下载功能因串口1未使能而开启失败,请前往uart.h使能串口1!
#   endif
#   if (ECBM_UART1_IO!=0)
#       error 自动下载功能需要串口1映射到P30和P31,请前往uart.h修改串口1的输出IO!
#   endif
#endif
/*---------------------------------------宏定义------------------------------------*/
#if         ((ECBM_MCU&0xF00000)==0x100000)
#   define	ECBM_MCU_NAME   "STC8F"
#elif       ((ECBM_MCU&0xF00000)==0x200000)
#   define	ECBM_MCU_NAME   "STC8A"
#elif       ((ECBM_MCU&0xF00000)==0x300000)
#   define	ECBM_MCU_NAME   "STC8G"
#elif       ((ECBM_MCU&0xF00000)==0x400000)
#   define	ECBM_MCU_NAME   "STC8H"
#elif       ((ECBM_MCU&0xF00000)==0x500000)
#   define	ECBM_MCU_NAME   "STC8C"
#endif
/*--------------------------------------变量定义-----------------------------------*/
union{
    u32 num32;
    u16 num16[2];
    u8  num8[4];
}data fast_cout;
#if ((ECBM_UART_LIB_EN)&&(ECBM_AUTO_DOWNLOAD_EN))
    bit auto_download_en_gb;                //自动下载的使能
    u8 data auto_download_old_char_gdu8;    //保存上一次接收的数据
    u8 data auto_download_char_count_gdu8;  //相同数据计数
#endif
/*--------------------------------------程序定义-----------------------------------*/
#if (ECBM_DELAY_EN)
/*-------------------------------------------------------
毫秒级延时函数
-------------------------------------------------------*/
void delay_ms(u16 ms){
    u16 i_u16;
    if(ms){
        do{
            i_u16=ECBM_SYSCLK_SETTING/10000;
            while(--i_u16);
        }while(--ms);    
    }
}
/*-------------------------------------------------------
微秒级延时函数（节拍）
-------------------------------------------------------*/
void delay_us(u16 us){
    u16 i_u16;
    i_u16=us;
	do{}while(--i_u16);
}
/*-------------------------------------------------------
微秒级延时函数的节拍计算函数
-------------------------------------------------------*/
u16 delay_set_us(u16 us){
//公式计算所花的时间太长，拆分成两个函数。先用这个函数推算出延时的数值，再用下面的函数调用。
    fast_cout.num32=((u32)(ECBM_SYSCLK_SETTING/10000)*(u32)(us))*131;
    return fast_cout.num16[0]>>1;
}
#endif
/*-------------------------------------------------------
下载流判断函数
-------------------------------------------------------*/
#if ((ECBM_UART_LIB_EN)&&(ECBM_AUTO_DOWNLOAD_EN))
    void system_uart_reset(void){
        if(auto_download_old_char_gdu8!=UART1_GET_REG_SBUF){ //判断重复字符，如果字符不重复
            auto_download_old_char_gdu8=UART1_GET_REG_SBUF;  //就更新oldchar
            auto_download_char_count_gdu8=0;                 //计数器清零
        }else{                                              //如果字符重复
            if(auto_download_en_gb)auto_download_char_count_gdu8++;//则重复计数器+1
        }
        if(auto_download_char_count_gdu8>=233){          //接收到233个重复数据时
            EA_DISABLE;                                 //断开所有中断
            while(1)POWER_RESET;                        //一直尝试重启
        }
    }
#endif
/*-------------------------------------------------------
系统检查函数
-------------------------------------------------------*/
#if ((ECBM_UART_LIB_EN)&&(ECBM_UART1_EN)&&(ECBM_UART_PRINTF_EN)&&(ECBM_PRINTF_EN)&&(ECBM_MCU_CHECK_EN))
    void system_check(void){
        u8 i,j;    
        u16 aaa=0x1234;
        uart_printf(1,"ECBM V%bu.%bu.%bu on %s",ECBM_FVN,ECBM_RVN,ECBM_BVN,ECBM_MCU_NAME);//输出版本号和单片机型号
        uart_printf(1,"%uK",(u16)((ECBM_MCU&0x0F0000)>>16));
        uart_printf(1,"%02u",(u16)(ECBM_MCU_ROM_SIZE));
        #if     (ECBM_MCU==0x110301)
            uart_printf(1,"-8PIN");
        #elif   (ECBM_MCU==0x110302)
            uart_printf(1,"S2-16PIN/20PIN");
        #elif   (ECBM_MCU==0x120502)
            uart_printf(1,"S2");
        #elif   (ECBM_MCU==0x120504)
            uart_printf(1,"S4");
        #elif   (ECBM_MCU==0x2405C2)
            uart_printf(1,"S2A12");
        #elif   (ECBM_MCU==0x2815C4)
            uart_printf(1,"D4");
        #elif   (ECBM_MCU==0x2805C4)
            uart_printf(1,"S4A12");
        #elif   (ECBM_MCU==0x3103A2)
            uart_printf(1,"-16PIN/20PIN");
        #elif   (ECBM_MCU==0x310201)
            uart_printf(1,"-8PIN ");
        #elif   (ECBM_MCU==0x3102A1)
            uart_printf(1,"A-8PIN");
        #elif   (ECBM_MCU==0x3103A1)
            uart_printf(1,"T-20PIN");
        #elif   (ECBM_MCU==0x3205A2)
            uart_printf(1,"S2");
        #elif   (ECBM_MCU==0x3205A4)
            uart_printf(1,"S4");
        #elif   (ECBM_MCU==0x4103A2)
            uart_printf(1,"-20PIN");
        #elif   (ECBM_MCU==0x4105A2)
            uart_printf(1,"-32PIN");    
        #elif   (ECBM_MCU==0x4305C2)
            uart_printf(1,"S2");    
        #elif   (ECBM_MCU==0x4305C4)
            uart_printf(1,"S4");
        #elif   (ECBM_MCU==0x4805C4)
            uart_printf(1,"U");    
        #elif   (ECBM_MCU==0x520502)
            uart_printf(1,"S2");    
        #elif   (ECBM_MCU==0x520504)
            uart_printf(1,"S4");
        #endif
        j=0;
        uart_printf(1,"\r\nChecking MCU ID");
        for(i=0;i<7;i++){
            uart_printf(1,".");
            if((REG_ID(i))==(MCUID[i])){
                j++;
            }
        }
        if(j!=7){
            uart_printf(1,"Error\r\nPlease check the setting of the MCU model\r\n");
        }else{
            uart_printf(1,"OK\r\nID    :");for(i=0;i<7;i++){uart_printf(1,"%02X",(u16)(MCUID[i]));}uart_printf(1,"\r\n");        //输出唯一ID号
            uart_printf(1,"DATA  :128\tByte\r\n");//DATA区固定是128Byte
            uart_printf(1,"IDATA :128\tByte\r\n");//IDATA区固定是128Byte
            uart_(1,"XDATA :%u\tByte\r\n",(u16)((ECBM_MCU&0x0F0000)>>16)*1024);//从配置文件中获取XDATA区大小
            uart_printf(1,"FLASH :%lu\tByte\r\n",(u32)ECBM_MCU_ROM_SIZE*1024);//从配置文件中获取FLASH区大小
            uart_printf(1,"SYSCLK:%lu\tHz\r\n",ECBM_SYSCLK_SETTING);//输出内部晶振值，在图形界面上设置
            uart_printf(1,"BGV   :%u\tmV\r\n",REG_BGV);//输出内部电压基准值，需要在STC-ISP上设置
            uart_printf(1,"ENDIAN:");
            if(*((char*)(&aaa))==0x12)uart_printf(1,"big\tendian\r\n");
            if(*((char*)(&aaa))==0x34)uart_printf(1,"little\tendian\r\n");
        }    
    }
#endif
/*-------------------------------------------------------
库函数系统初始化函数
-------------------------------------------------------*/
void system_init(void){
    #if (SYSTEM_CLEAR_XDATA_LEN)//如果清零的数量不为0，就编译以下的代码：
    u16 i_u16;//计数变量。
    for(i_u16=0;i_u16<SYSTEM_CLEAR_XDATA_LEN;i_u16++){//循环清零。
        (*((u8  volatile xdata *)i_u16))=0;//清零XDATA部分。
    }
    #endif
    EX_SFR_ENABLE;//打开额外的寄存器。
    //---------------自动下载--------------//
    #if ((ECBM_UART_LIB_EN)&&(ECBM_AUTO_DOWNLOAD_EN))//判断否需要开启自动下载。
        auto_download_en_gb=1;         //打开自动下载使能
        auto_download_old_char_gdu8=0;   //初始化串口相关变量
        auto_download_char_count_gdu8=0; //初始化串口相关变量
        uart_init();
    #endif
    //--------------10mS联盟--------------//
    #if (ECBM_10MS_EN)
        #if     (ECBM_10MS_TIMER==0)
            TIMER0_SET_MODE_12T;    //设定更长的时间就要用12分频。
            TIMER0_SET_REG_HL(65536UL-(u16)((ECBM_SYSCLK_SETTING*10000)/12/1000000));//宏定义计算在编译期就能计算好，所以这里的公式保留原初样式能方便修改。
            TIMER0_SET_MODE_TIMER;  //设置为定时器模式。
            TIMER0_IT_ENABLE;       //打开中断开关。
            TIMER0_POWER_ON;        //打开定时器。
        #elif   (ECBM_10MS_TIMER==1)
            TIMER1_SET_MODE_12T;    //设定更长的时间就要用12分频。
            TIMER1_SET_REG_HL(65536UL-(u16)((ECBM_SYSCLK_SETTING*10000)/12/1000000));//宏定义计算在编译期就能计算好，所以这里的公式保留原初样式能方便修改。
            TIMER1_SET_MODE_TIMER;  //设置为定时器模式。
            TIMER1_IT_ENABLE;       //打开中断开关。
            TIMER1_POWER_ON;        //打开定时器。
        #elif   (ECBM_10MS_TIMER==2)
            TIMER2_SET_MODE_12T;    //设定更长的时间就要用12分频。
            TIMER2_SET_REG_HL(65536UL-(u16)((ECBM_SYSCLK_SETTING*10000)/12/1000000));//宏定义计算在编译期就能计算好，所以这里的公式保留原初样式能方便修改。
            TIMER2_SET_MODE_TIMER;  //设置为定时器模式。
            TIMER2_IT_ENABLE;       //打开中断开关。
            TIMER2_POWER_ON;        //打开定时器。
        #elif   (ECBM_10MS_TIMER==3)
            TIMER3_SET_MODE_12T;    //设定更长的时间就要用12分频。
            TIMER3_SET_REG_HL(65536UL-(u16)((ECBM_SYSCLK_SETTING*10000)/12/1000000));//宏定义计算在编译期就能计算好，所以这里的公式保留原初样式能方便修改。
            TIMER3_SET_MODE_TIMER;  //设置为定时器模式。
            TIMER3_IT_ENABLE;       //打开中断开关。
            TIMER3_POWER_ON;        //打开定时器。
        #elif   (ECBM_10MS_TIMER==4)
            TIMER4_SET_MODE_12T;    //设定更长的时间就要用12分频。
            TIMER4_SET_REG_HL(65536UL-(u16)((ECBM_SYSCLK_SETTING*10000)/12/1000000));//宏定义计算在编译期就能计算好，所以这里的公式保留原初样式能方便修改。
            TIMER4_SET_MODE_TIMER;  //设置为定时器模式。
            TIMER4_IT_ENABLE;       //打开中断开关。
            TIMER4_POWER_ON;        //打开定时器。
        #endif
        #if ((ECBM_STREAM_LIB_EN)&&(ECBM_STREAM_CH_COUNT))
            ecbm_stream_init();
        #endif        
    #endif    
    //-------------基本硬件设置------------//
    #if ((ECBM_POWER_LIB_EN)&&(ECBM_POWER_RST_CFG_EN))
        power_rstcfg_init();
    #endif    
    //-------------时钟输出设置------------//    
    #if (ECBM_SYSCLK_OUT_EN) //判断是否需要开启时钟输出。
        #if ((ECBM_MCU&0xF00000)>0x200000)//检查是不是GH。
            #if (ECBM_SYSLCK_OUT_PIN)
                CLK_SET_OUT_TO_P16_GH;
            #else
                CLK_SET_OUT_TO_P54_GH;
            #endif
            CLK_OUT_SET_DIV_GH(ECBM_SYSCLK_OUT_SETTING_GH);
        #else
            #if (ECBM_SYSLCK_OUT_PIN)
                CLK_SET_OUT_TO_P16_FA;
            #else
                CLK_SET_OUT_TO_P54_FA;
            #endif
            CLK_OUT_SET_DIV_FA(ECBM_SYSCLK_OUT_SETTING_FA);
        #endif
    #endif
//--------------设置确认---------------//
    EA_ENABLE;//打开总中断。
    #if ((ECBM_UART_LIB_EN)&&(ECBM_UART1_EN)&&(ECBM_UART_PRINTF_EN)&&(ECBM_PRINTF_EN)&&(ECBM_MCU_CHECK_EN))
        delay_ms(500);
        system_check();
    #endif
}
/*---------------------------------其他非系统函数---------------------------------*/
/**********************************str系列函数************************/#if (ECBM_STRING_EN)
/*-------------------------------------------------------
字符串查找函数。
-------------------------------------------------------*/
u16 str_find(s8 * dest,s8 * key){
    u16 key_count_u16,key_first_u16,count_u16;
    key_count_u16=0;    //清零变量。
    key_first_u16=0;
    count_u16    =0;
    while(*dest){       //判断目标字符串。
        if(key[key_count_u16]==(*dest)){//假如关键词字符串当前位比对成功，
            key_count_u16++;            //那么就比较下一位。
        }else if(key[0]==(*dest)){	    //假如当前位没有对比成功，就看看是不是要从头开始对比。
			key_count_u16=1;			//从头对比成功，说明再次找到了疑似的关键词，那么下次就从第二个开始对比。
        }else{                          //假如没有比对成功，
            key_count_u16=0;            //那么就从头开始比对。
        }
		count_u16++;    				//记录循环的次数，用于计算关键词出现的位置。
        dest++;                         //读取目标字符串的下一位。
        if(key[key_count_u16]==0){      //如果关键词字符串比对完，
            return (count_u16-key_count_u16);//返回关键词字符串第一次出现的位置。
        } 
    }
    return 0xffff;//能运行到这一步，说明直到目标字符串结束都没有比对成功，返回-1。
}
/*-------------------------------------------------------
IO信息读取函数。
-------------------------------------------------------*/
u8 str_read_pin(s8 * str,u16 pos){
    u8  dat_u8,offset_u8,count_u8;  //从左往右依次是读取的信息、字符串偏移和字数统计。
    dat_u8=0;                       //缓存清零。
    count_u8=0;                     //字数统计清零。
    for(offset_u8=0;offset_u8<10;offset_u8++){      //预留10个偏移量。
        if((str[pos+offset_u8]>='0')&&(str[pos+offset_u8]<='7')){//IO口的编号都是从0~7。
            count_u8++;                             //在这个范围内，字数+1。
            if(count_u8==1){                        //如果是第一个数，
                dat_u8=(str[pos+offset_u8]-'0')<<4; //解析出来放到高4位。
            }
            if(count_u8==2){                        //如果是第二个数，
                dat_u8=(str[pos+offset_u8]-'0')|dat_u8;//解析出来放到低4位。
                return dat_u8;                      //返回该值。
            }
        }
        if((str[pos+offset_u8]>='8')&&(str[pos+offset_u8]<='9')){//如果是8和9，那么只增加字数，不写入值。
            count_u8++;
        }
        if(str[pos+offset_u8]==',')break;//遇到逗号就退出。
        if(str[pos+offset_u8]==0)break;  //字符串结束也退出。
    }
    return dat_u8;
}
/*-------------------------------------------------------
u16变量读取函数。
-------------------------------------------------------*/
u16 str_read_u16(s8 * str,u16 pos){
    u16 dat_u16;    //读取的信息。
    u8  offset_u8;  //字符串偏移。
    dat_u16=0;
    for(offset_u8=0;offset_u8<20;offset_u8++){//预留20个字符的偏移。
        if((str[pos+offset_u8]>='0')&&(str[pos+offset_u8]<='9')){//数字都是从0~9。
            dat_u16*=10;                    //变量增加一位，即原来是12，就变成120，空出的个数就拿来装新的数。
            dat_u16+=str[pos+offset_u8]-'0';//将新的数加到个位上。
        }
        if(str[pos+offset_u8]==',')break;//遇到逗号就退出。
        if(str[pos+offset_u8]=='.')break;//遇到点号就退出。
        if(str[pos+offset_u8]==0)break;  //字符串结束也退出。
    }
    return dat_u16;
}
/*-------------------------------------------------------
字符串推出指令函数（带字符串长度参数版）。
-------------------------------------------------------*/
u8 str_push_len(u8 * dest,u16 dlen,u8 * key,u16 klen){
    u16 i_u16,j_u16,start_u16,stop_u16;
    j_u16    =0;                        //清零各种变量。
    start_u16=0;
    stop_u16 =0;
    for(i_u16=0;i_u16<dlen;i_u16++){    //从头开始，直到指定的长度。
        if(dest[i_u16]==key[j_u16]){    //把当前的字符和关键词比较成功，
            j_u16++;                    //取关键词的下一个字。
            if(j_u16==klen){            //当关键词全部比对完成的时候。
                stop_u16=i_u16;         //保存【结束位置】。
                break;                  //退出循环。
            }
        }else{                          //如果当前的字符和关键词比较失败，
            j_u16=0;                    //下一次从头开始比对。
            start_u16=i_u16+1;          //更新【开始位置】为下一位（因为当前位失败了）。
        }
    }
    if(start_u16<=stop_u16){            //当比对成功的时候，【开始位置】肯定小于等于【结束位置】。
        for(i_u16=start_u16;i_u16<stop_u16;i_u16++){//将从【开始位置】到【结束位置】之间的缓存全清零。
            dest[i_u16]=0;
        }
        return 1;                //返回推出成功。
    }else{
        return 0;                //返回推出失败。
    }
}
/*****************************************************************************/#endif
