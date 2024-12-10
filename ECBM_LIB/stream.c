#include "ecbm_core.h"  //统一加载核心头文件
#if ((ECBM_10MS_EN)&&(ECBM_STREAM_LIB_EN)&&(ECBM_STREAM_CH_COUNT))  //检查本库有没有被使能
/*--------------------------------------变量定义-----------------------------------*/
#if (ECBM_STREAM_CH1_EN)
u8 xdata ecbm_stream_ch1_buf_gxu8a[ECBM_STREAM_CH1_SZIE];//stream的通道1接收缓存。
u8 ecbm_stream_ch1_point_gu8;                            //stream的通道1接收缓存的写入地址。
u8 ecbm_stream_ch1_read_point_gu8;                       //stream的通道1读缓存的进度。
u8 ecbm_stream_ch1_count_gu8;                            //stream的通道1接收到的数据数量。
u8 ecbm_stream_ch1_time_gu8;                             //stream的通道1定时器计时变量。
u8 ecbm_stream_ch1_status_gu8;                           //stream的通道1状态。
#endif

#if (ECBM_STREAM_CH2_EN)
u8 xdata ecbm_stream_ch2_buf_gxu8a[ECBM_STREAM_CH2_SZIE];//stream的通道2接收缓存。
u8 ecbm_stream_ch2_point_gu8;                            //stream的通道2接收缓存的写入地址。
u8 ecbm_stream_ch2_read_point_gu8;                       //stream的通道2读缓存的进度。
u8 ecbm_stream_ch2_count_gu8;                            //stream的通道2接收到的数据数量。
u8 ecbm_stream_ch2_time_gu8;                             //stream的通道2定时器计时变量。
u8 ecbm_stream_ch2_status_gu8;                           //stream的通道2状态。
#endif

#if (ECBM_STREAM_CH3_EN)
u8 xdata ecbm_stream_ch3_buf_gxu8a[ECBM_STREAM_CH3_SZIE];//stream的通道3接收缓存。
u8 ecbm_stream_ch3_point_gu8;                            //stream的通道3接收缓存的写入地址。
u8 ecbm_stream_ch3_read_point_gu8;                       //stream的通道3读缓存的进度。
u8 ecbm_stream_ch3_count_gu8;                            //stream的通道3接收到的数据数量。
u8 ecbm_stream_ch3_time_gu8;                             //stream的通道3定时器计时变量。
u8 ecbm_stream_ch3_status_gu8;                           //stream的通道3状态。
#endif

#if (ECBM_STREAM_CH4_EN)
u8 xdata ecbm_stream_ch4_buf_gxu8a[ECBM_STREAM_CH4_SZIE];//stream的通道4接收缓存。
u8 ecbm_stream_ch4_point_gu8;                            //stream的通道4接收缓存的写入地址。
u8 ecbm_stream_ch4_read_point_gu8;                       //stream的通道4读缓存的进度。
u8 ecbm_stream_ch4_count_gu8;                            //stream的通道4接收到的数据数量。
u8 ecbm_stream_ch4_time_gu8;                             //stream的通道4定时器计时变量。
u8 ecbm_stream_ch4_status_gu8;                           //stream的通道4状态。
#endif
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
stream初始化函数。
-------------------------------------------------------*/
void ecbm_stream_init(void){
    u8 i_u8;
    #if (ECBM_STREAM_CH1_EN)
        for(i_u8=0;i_u8<ECBM_STREAM_CH1_SZIE;i_u8++){
            ecbm_stream_ch1_buf_gxu8a[i_u8]=0;
        }
        ecbm_stream_ch1_point_gu8=0;
        ecbm_stream_ch1_read_point_gu8=0;
        ecbm_stream_ch1_count_gu8=0;
        ecbm_stream_ch1_time_gu8=0;
        ecbm_stream_ch1_status_gu8=0;
    #endif  
    #if (ECBM_STREAM_CH2_EN)
        for(i_u8=0;i_u8<ECBM_STREAM_CH2_SZIE;i_u8++){
            ecbm_stream_ch2_buf_gxu8a[i_u8]=0;
        }
        ecbm_stream_ch2_point_gu8=0;
        ecbm_stream_ch2_read_point_gu8=0;
        ecbm_stream_ch2_count_gu8=0;
        ecbm_stream_ch2_time_gu8=0;
        ecbm_stream_ch2_status_gu8=0;
    #endif       
    #if (ECBM_STREAM_CH3_EN)
        for(i_u8=0;i_u8<ECBM_STREAM_CH3_SZIE;i_u8++){
            ecbm_stream_ch3_buf_gxu8a[i_u8]=0;
        }
        ecbm_stream_ch3_point_gu8=0;
        ecbm_stream_ch3_read_point_gu8=0;
        ecbm_stream_ch3_count_gu8=0;
        ecbm_stream_ch3_time_gu8=0;
        ecbm_stream_ch3_status_gu8=0;
    #endif    
    #if (ECBM_STREAM_CH4_EN)
        for(i_u8=0;i_u8<ECBM_STREAM_CH4_SZIE;i_u8++){
            ecbm_stream_ch4_buf_gxu8a[i_u8]=0;
        }
        ecbm_stream_ch4_point_gu8=0;
        ecbm_stream_ch4_read_point_gu8=0;
        ecbm_stream_ch4_count_gu8=0;
        ecbm_stream_ch4_time_gu8=0;
        ecbm_stream_ch4_status_gu8=0;
    #endif
}
/*-------------------------------------------------------
时间运行函数。
-------------------------------------------------------*/  
void ecbm_stream_timer_run(void){
    #if (ECBM_STREAM_CH1_EN)
        if(ecbm_stream_ch1_status_gu8&ECBM_STREAM_TIME_EN){      //处于运行状态时。
            ecbm_stream_ch1_time_gu8++;                          //每次定时器中断加一次。
            if(ecbm_stream_ch1_time_gu8>ECBM_STREAM_TIME_MAX){   //超过了间隔时间最大值时。
                ecbm_stream_ch1_status_gu8|=ECBM_STREAM_TIME_OUT;//变成超时状态。
            }
            if(ecbm_stream_ch1_time_gu8>ECBM_STREAM_IDLE_MAX){    //超过了空闲时间最大值时。
                ecbm_stream_ch1_status_gu8|=ECBM_STREAM_UART_IDLE;//变成空闲状态。
                ecbm_stream_ch1_status_gu8&=~ECBM_STREAM_TIME_EN; //空闲时关闭计时。
            }
        }
    #endif      
    
    #if (ECBM_STREAM_CH2_EN)
        if(ecbm_stream_ch2_status_gu8&ECBM_STREAM_TIME_EN){      //处于运行状态时。
            ecbm_stream_ch2_time_gu8++;                          //每次定时器中断加一次。
            if(ecbm_stream_ch2_time_gu8>ECBM_STREAM_TIME_MAX){   //超过了间隔时间最大值时。
                ecbm_stream_ch2_status_gu8|=ECBM_STREAM_TIME_OUT;//变成超时状态。
            }
            if(ecbm_stream_ch2_time_gu8>ECBM_STREAM_IDLE_MAX){    //超过了空闲时间最大值时。
                ecbm_stream_ch2_status_gu8|=ECBM_STREAM_UART_IDLE;//变成空闲状态。
                ecbm_stream_ch2_status_gu8&=~ECBM_STREAM_TIME_EN; //空闲时关闭计时。
            }
        }
    #endif      
    
    #if (ECBM_STREAM_CH3_EN)
        if(ecbm_stream_ch3_status_gu8&ECBM_STREAM_TIME_EN){      //处于运行状态时。
            ecbm_stream_ch3_time_gu8++;                          //每次定时器中断加一次。
            if(ecbm_stream_ch3_time_gu8>ECBM_STREAM_TIME_MAX){   //超过了间隔时间最大值时。
                ecbm_stream_ch3_status_gu8|=ECBM_STREAM_TIME_OUT;//变成超时状态。
            }
            if(ecbm_stream_ch3_time_gu8>ECBM_STREAM_IDLE_MAX){    //超过了空闲时间最大值时。
                ecbm_stream_ch3_status_gu8|=ECBM_STREAM_UART_IDLE;//变成空闲状态。
                ecbm_stream_ch3_status_gu8&=~ECBM_STREAM_TIME_EN; //空闲时关闭计时。
            }
        }
    #endif   
        
    #if (ECBM_STREAM_CH4_EN)
        if(ecbm_stream_ch4_status_gu8&ECBM_STREAM_TIME_EN){      //处于运行状态时。
            ecbm_stream_ch4_time_gu8++;                          //每次定时器中断加一次。
            if(ecbm_stream_ch4_time_gu8>ECBM_STREAM_TIME_MAX){   //超过了间隔时间最大值时。
                ecbm_stream_ch4_status_gu8|=ECBM_STREAM_TIME_OUT;//变成超时状态。
            }
            if(ecbm_stream_ch4_time_gu8>ECBM_STREAM_IDLE_MAX){    //超过了空闲时间最大值时。
                ecbm_stream_ch4_status_gu8|=ECBM_STREAM_UART_IDLE;//变成空闲状态。
                ecbm_stream_ch4_status_gu8&=~ECBM_STREAM_TIME_EN; //空闲时关闭计时。
            }
        }
    #endif
}
/*-------------------------------------------------------
流处理主函数函数。
-------------------------------------------------------*/
void ecbm_stream_main(void){
    u8 dat_u8;
    
    #if (ECBM_STREAM_CH1_EN)//进入处理的条件：
        if(ecbm_stream_ch1_status_gu8&ECBM_STREAM_TIME_OUT){//必须是接收超时状态，这个状态代表已经过了一段时间没有新的数据过来了。
            if((ecbm_stream_ch1_count_gu8>0)&&(ecbm_stream_ch1_count_gu8<ECBM_STREAM_CH1_SZIE)){//判断接收到的数据的数量是否合法。
                ecbm_stream_ch1_status_gu8&=~ECBM_STREAM_TIME_OUT;  //开始处理数据了，清除这个标志位。
                while(ecbm_stream_ch1_count_gu8){
                    dat_u8=ecbm_stream_ch1_buf_gxu8a[ecbm_stream_ch1_read_point_gu8];
                    ecbm_stream_ch1_count_gu8--;
                    #if (ECBM_STREAM_USER_CH1_EN)
                    ecbm_stream_user_exe(1,dat_u8);
                    #endif
                    #if (ECBM_STREAM_FUR_CH1_EN)
                    es_fur_exe(1,dat_u8);
                    #endif
                    #if (ECBM_STREAM_MODBUS_CH1_EN)
                    es_modbus_rtu_exe(1,dat_u8);
                    #endif
                    #if (ECBM_STREAM_ECP_CH1_EN)
                    es_ecp_exe(1,dat_u8);
                    #endif
                    ecbm_stream_ch1_read_point_gu8++;
                    if(ecbm_stream_ch1_read_point_gu8>=ECBM_STREAM_CH1_SZIE){
                        ecbm_stream_ch1_read_point_gu8=0;
                    }
                }
            }
        }
        if(ecbm_stream_ch1_status_gu8&ECBM_STREAM_UART_IDLE){
            ecbm_stream_ch1_status_gu8&=~ECBM_STREAM_UART_IDLE;
            #if (ECBM_STREAM_FUR_CH1_EN)
                es_fur_reset(1);
            #endif
            #if (ECBM_STREAM_MODBUS_CH1_EN)
                es_modbus_rtu_reset(1);
            #endif
            #if (ECBM_STREAM_ECP_CH1_EN)
                es_ecp_reset(1);
            #endif     
        }
    #endif
    
    #if (ECBM_STREAM_CH2_EN)//进入处理的条件：
        if(ecbm_stream_ch2_status_gu8&ECBM_STREAM_TIME_OUT){//必须是接收超时状态，这个状态代表已经过了一段时间没有新的数据过来了。
            if((ecbm_stream_ch2_count_gu8>0)&&(ecbm_stream_ch2_count_gu8<ECBM_STREAM_CH2_SZIE)){//判断接收到的数据的数量是否合法。
                ecbm_stream_ch2_status_gu8&=~ECBM_STREAM_TIME_OUT;  //开始处理数据了，清除这个标志位。
                while(ecbm_stream_ch2_count_gu8){
                    dat_u8=ecbm_stream_ch2_buf_gxu8a[ecbm_stream_ch2_read_point_gu8];
                    ecbm_stream_ch2_count_gu8--;
                    #if (ECBM_STREAM_USER_CH2_EN)
                    ecbm_stream_user_exe(2,dat_u8);
                    #endif
                    #if (ECBM_STREAM_FUR_CH2_EN)
                    es_fur_exe(2,dat_u8);
                    #endif
                    #if (ECBM_STREAM_MODBUS_CH2_EN)
                    es_modbus_rtu_exe(2,dat_u8);
                    #endif
                    #if (ECBM_STREAM_ECP_CH2_EN)
                    es_ecp_exe(2,dat_u8);
                    #endif
                    ecbm_stream_ch2_read_point_gu8++;
                    if(ecbm_stream_ch2_read_point_gu8>=ECBM_STREAM_CH2_SZIE){
                        ecbm_stream_ch2_read_point_gu8=0;
                    }
                }
            }
        }
        if(ecbm_stream_ch2_status_gu8&ECBM_STREAM_UART_IDLE){
            ecbm_stream_ch2_status_gu8&=~ECBM_STREAM_UART_IDLE;
            #if (ECBM_STREAM_FUR_CH2_EN)
                es_fur_reset(2);
            #endif
            #if (ECBM_STREAM_MODBUS_CH2_EN)
                es_modbus_rtu_reset(2);
            #endif
            #if (ECBM_STREAM_ECP_CH2_EN)
                es_ecp_reset(2);
            #endif     
        }
    #endif
    
    #if (ECBM_STREAM_CH3_EN)//进入处理的条件：
        if(ecbm_stream_ch3_status_gu8&ECBM_STREAM_TIME_OUT){//必须是接收超时状态，这个状态代表已经过了一段时间没有新的数据过来了。
            if((ecbm_stream_ch3_count_gu8>0)&&(ecbm_stream_ch3_count_gu8<ECBM_STREAM_CH3_SZIE)){//判断接收到的数据的数量是否合法。
                ecbm_stream_ch3_status_gu8&=~ECBM_STREAM_TIME_OUT;  //开始处理数据了，清除这个标志位。
                while(ecbm_stream_ch3_count_gu8){
                    dat_u8=ecbm_stream_ch3_buf_gxu8a[ecbm_stream_ch3_read_point_gu8];
                    ecbm_stream_ch3_count_gu8--;
                    #if (ECBM_STREAM_USER_CH3_EN)
                    ecbm_stream_user_exe(3,dat_u8);
                    #endif
                    #if (ECBM_STREAM_FUR_CH3_EN)
                    es_fur_exe(3,dat_u8);
                    #endif
                    #if (ECBM_STREAM_MODBUS_CH3_EN)
                    es_modbus_rtu_exe(3,dat_u8);
                    #endif
                    #if (ECBM_STREAM_ECP_CH3_EN)
                    es_ecp_exe(3,dat_u8);
                    #endif
                    ecbm_stream_ch3_read_point_gu8++;
                    if(ecbm_stream_ch3_read_point_gu8>=ECBM_STREAM_CH3_SZIE){
                        ecbm_stream_ch3_read_point_gu8=0;
                    }
                }
            }
        }
        if(ecbm_stream_ch3_status_gu8&ECBM_STREAM_UART_IDLE){
            ecbm_stream_ch3_status_gu8&=~ECBM_STREAM_UART_IDLE;
            #if (ECBM_STREAM_FUR_CH3_EN)
                es_fur_reset(3);
            #endif
            #if (ECBM_STREAM_MODBUS_CH3_EN)
                es_modbus_rtu_reset(3);
            #endif
            #if (ECBM_STREAM_ECP_CH3_EN)
                es_ecp_reset(3);
            #endif     
        }
    #endif
    
    #if (ECBM_STREAM_CH4_EN)//进入处理的条件：
        if(ecbm_stream_ch4_status_gu8&ECBM_STREAM_TIME_OUT){//必须是接收超时状态，这个状态代表已经过了一段时间没有新的数据过来了。
            if((ecbm_stream_ch4_count_gu8>0)&&(ecbm_stream_ch4_count_gu8<ECBM_STREAM_CH4_SZIE)){//判断接收到的数据的数量是否合法。
                ecbm_stream_ch4_status_gu8&=~ECBM_STREAM_TIME_OUT;  //开始处理数据了，清除这个标志位。
                while(ecbm_stream_ch4_count_gu8){
                    dat_u8=ecbm_stream_ch4_buf_gxu8a[ecbm_stream_ch4_read_point_gu8];
                    ecbm_stream_ch4_count_gu8--;
                    #if (ECBM_STREAM_USER_CH4_EN)
                    ecbm_stream_user_exe(4,dat_u8);
                    #endif
                    #if (ECBM_STREAM_FUR_CH4_EN)
                    es_fur_exe(4,dat_u8);
                    #endif
                    #if (ECBM_STREAM_MODBUS_CH4_EN)
                    es_modbus_rtu_exe(4,dat_u8);
                    #endif
                    #if (ECBM_STREAM_ECP_CH4_EN)
                    es_ecp_exe(4,dat_u8);
                    #endif
                    ecbm_stream_ch4_read_point_gu8++;
                    if(ecbm_stream_ch4_read_point_gu8>=ECBM_STREAM_CH4_SZIE){
                        ecbm_stream_ch4_read_point_gu8=0;
                    }
                }
            }
        }
        if(ecbm_stream_ch4_status_gu8&ECBM_STREAM_UART_IDLE){
            ecbm_stream_ch4_status_gu8&=~ECBM_STREAM_UART_IDLE;
            #if (ECBM_STREAM_FUR_CH4_EN)
                es_fur_reset(4);
            #endif
            #if (ECBM_STREAM_MODBUS_CH4_EN)
                es_modbus_rtu_reset(4);
            #endif
            #if (ECBM_STREAM_ECP_CH4_EN)
                es_ecp_reset(4);
            #endif     
        }
    #endif
}
/*-------------------------------------------------------
流处理比对函数。
-------------------------------------------------------*/
#if (ECBM_STREAM_CMP_EN)
void ecbm_stream_strcmp(u8 dat,u8 code * str,u8 * count){
    if(str[*count]==dat){    //判断一下当前串口数据和关键字的某个字符是否一样。
        (*count)++;          //一样的话，计数+1，下次循环就会判断下一个字符了。
    }else{                   //不一样的话，
        *count=0;            //计数清零。但是在本次循环中，计数清零会引入关键字的一个新字符。
        if(str[*count]==dat){//既然出现了新字符就要判断下是否与当前串口数据符合。
            (*count)++;      //符合就计数+1。
        }
    }
}
#endif
/*-------------------------------------------------------
CRC16校验函数。
-------------------------------------------------------*/
#if (ECBM_STREAM_MODBUS_CH_COUNT+ECBM_STREAM_ECP_CH_COUNT)
    u16 es_crc16(u16 crc,u8 buf){
        u8 j;
        u16 crc_buf;
        crc_buf=crc^buf;                    //当前数据异或CRC低字节，在C51里可以直接处理。
        for(j=0;j<8;j++){                   //计算每个字节的每一位。
            if(crc_buf&0x01){               //判断右移前最低位是否为1。
                crc_buf=(crc_buf>>1)^0xA001;//如果为1则右移并异或表达式。
            }else{
                crc_buf>>=1;                //否则直接右移一位。
            }           
        }
        return crc_buf;
    }
    u16 es_send_whit_crc(u8 ch,u16 crc,u8 dat){
        uart_char(ch,dat);
        return es_crc16(crc,dat);
    }
#endif
#endif  //和最上面的#ifndef配合成一个程序段。
        //以一个空行为结尾。