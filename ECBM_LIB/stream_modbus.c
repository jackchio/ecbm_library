#include "ecbm_core.h"  //统一加载核心头文件
#if (ECBM_10MS_EN)&&(ECBM_STREAM_LIB_EN)&&(ECBM_STREAM_MODBUS_CH_COUNT)    //检查本库有没有被使能
/*--------------------------------------变量定义-----------------------------------*/
u8  es_modbus_rtu_mode_gu8a        [ECBM_STREAM_MODBUS_CH_COUNT]; //主从模式。
u8  es_modbus_rtu_send_id_gu8a     [ECBM_STREAM_MODBUS_CH_COUNT]; //发送的ID。
u8  es_modbus_rtu_reply_count_gu8a [ECBM_STREAM_MODBUS_CH_COUNT]; //返回的数据数量。
u8  es_modbus_rtu_status_gu8a      [ECBM_STREAM_MODBUS_CH_COUNT]; //状态机使用的变量。
u8  es_modbus_rtu_broadcast_en_gu8a[ECBM_STREAM_MODBUS_CH_COUNT]; //广播模式。
u8  es_modbus_rtu_fun_code_gu8a    [ECBM_STREAM_MODBUS_CH_COUNT]; //功能码。
u16 es_modbus_rtu_address_gu16a    [ECBM_STREAM_MODBUS_CH_COUNT]; //数据地址。
u16 es_modbus_rtu_data_count_gu16a [ECBM_STREAM_MODBUS_CH_COUNT]; //数据/个数。
u16 es_modbus_rtu_uart_crc_gu16a   [ECBM_STREAM_MODBUS_CH_COUNT]; //CRC计算缓存。
u16 es_modbus_rtu_crc_buf_gu16a    [ECBM_STREAM_MODBUS_CH_COUNT]; //CRC缓存。
u8  es_modbus_rtu_cmd_count_gu8a   [ECBM_STREAM_MODBUS_CH_COUNT]; //指令缓存计数。
u8  es_modbus_rtu_count_gu8a       [ECBM_STREAM_MODBUS_CH_COUNT]; //通用计数。
#if ((ES_MODBUS_RTU_CMD10_EN)||(ES_MODBUS_RTU_MASTER_EN))
    u16 es_modbus_rtu_cmd_buf_gu16a[ECBM_STREAM_MODBUS_CH_COUNT][ES_MODBUS_RTU_BUF_SIZE];//通用缓存。
#endif
/*--------------------------------------程序定义-----------------------------------*/
u8 ecbm_stream_modbus_chtoid(u8 ch){
    switch(ch){
        case 1:return (0);break;
        case 2:return ( ECBM_STREAM_CH1_EN*ECBM_STREAM_MODBUS_CH1_EN);break;
        case 3:return ((ECBM_STREAM_CH1_EN*ECBM_STREAM_MODBUS_CH1_EN)+(ECBM_STREAM_CH2_EN*ECBM_STREAM_MODBUS_CH2_EN));break;
        case 4:return ((ECBM_STREAM_CH1_EN*ECBM_STREAM_MODBUS_CH1_EN)+(ECBM_STREAM_CH2_EN*ECBM_STREAM_MODBUS_CH2_EN)+(ECBM_STREAM_CH3_EN*ECBM_STREAM_MODBUS_CH3_EN));break;
    }
    return (0);
}
/*-------------------------------------------------------
modbus重置函数。
-------------------------------------------------------*/
void es_modbus_rtu_reset(u8 ch){
    u8 id_u8;
    id_u8=ecbm_stream_modbus_chtoid(ch);
    es_modbus_rtu_mode_gu8a        [id_u8]=ES_MODBUS_RTU_MODE_SLAVE; //默认从机模式。
    es_modbus_rtu_send_id_gu8a     [id_u8]=0; //清除发送的ID。
    es_modbus_rtu_reply_count_gu8a [id_u8]=0; //清除返回的数据数量。
    es_modbus_rtu_status_gu8a      [id_u8]=ES_MODBUS_RTU_READY; //复位成等待态。。
    es_modbus_rtu_broadcast_en_gu8a[id_u8]=0; //清除广播模式。
    es_modbus_rtu_fun_code_gu8a    [id_u8]=0; //清除功能码。
    es_modbus_rtu_address_gu16a    [id_u8]=0; //清除数据地址。
    es_modbus_rtu_data_count_gu16a [id_u8]=0; //清除数据/个数。
    es_modbus_rtu_uart_crc_gu16a   [id_u8]=0; //清除CRC计算缓存。
    es_modbus_rtu_crc_buf_gu16a    [id_u8]=0; //清除CRC缓存。
    es_modbus_rtu_cmd_count_gu8a   [id_u8]=0; //清除指令缓存计数。
    es_modbus_rtu_count_gu8a       [id_u8]=0; //清除通用计数。
}
/*-------------------------------------------------------
modbus返回错误码函数。
-------------------------------------------------------*/
void es_modbus_rtu_err_num(u8 ch,u8 fun_num,u8 err_num){
    u8  id_u8;
    u16 crc_u16;
    if(es_modbus_rtu_broadcast_en_gu8a[ecbm_stream_modbus_chtoid(ch)]){  //只有不是广播帧的时候才能回复。
        id_u8=es_modbus_rtu_get_id(ch); //读取本机ID。
        crc_u16=es_send_whit_crc(ch,0xFFFF,id_u8);            //发送地址。
        crc_u16=es_send_whit_crc(ch,crc_u16,0x80+fun_num);     //发送0x80+功能码回复。
        crc_u16=es_send_whit_crc(ch,crc_u16,err_num);          //异常码。
        uart_char(ch,(u8)(crc_u16));    //发送CRC。
        uart_char(ch,(u8)(crc_u16>>8));
    }
}
/*-------------------------------------------------------
1号功能码处理函数。
-------------------------------------------------------*/
#if (ES_MODBUS_RTU_CMD01_EN)
    void es_modbus_rtu_cmd_0x01(u8 ch){
        u8 temp_u8,t1_u8,c1_u8,i_u8,j_u8,qw_u8,id_u8,index_u8;
        u16 crc_u16;
        index_u8=ecbm_stream_modbus_chtoid(ch);
        id_u8=es_modbus_rtu_get_id(ch);      //读取本机ID。
        if((es_modbus_rtu_data_count_gu16a[index_u8]>=1)&&(es_modbus_rtu_data_count_gu16a[index_u8]<=0x07D0)){          //读取的个数要在1个以上，且地址不能大于2000。
            if(((u32)(es_modbus_rtu_data_count_gu16a[index_u8])+(u32)(es_modbus_rtu_address_gu16a[index_u8]))<=65536UL){//判断地址+个数有没有超限。
                if(es_modbus_rtu_broadcast_en_gu8a[index_u8]){              //如果是广播帧，那么便不能回复。
                    t1_u8=(u8)(es_modbus_rtu_data_count_gu16a[index_u8]/8); //统计要读取的数据能凑够多少个字节。
                    if(es_modbus_rtu_data_count_gu16a[index_u8]%8)t1_u8++;  //剩下的不足8位的数据也要一个字节来传输。
                    crc_u16=es_send_whit_crc(ch,0xFFFF,id_u8);              //发送地址。
                    crc_u16=es_send_whit_crc(ch,crc_u16,0x01);              //发送功能码回复。
                    crc_u16=es_send_whit_crc(ch,crc_u16,t1_u8);             //发送数据长度。
                    for(i_u8=0;i_u8<t1_u8;i_u8++){  //从起始位置开始组装数据。
                        temp_u8=0;                  //清零变量。
                        if(es_modbus_rtu_data_count_gu16a[index_u8]>=8){    //如果剩余要读的数据多于8个比特。
                            c1_u8=8;                //那么本轮循环先读8比特数据。
                        }else{                      //否则，
                            c1_u8=(u8)(es_modbus_rtu_data_count_gu16a[index_u8]);  //就有多少读多少。
                        }
                        for(j_u8=0;j_u8<c1_u8;j_u8++){      
                            es_modbus_cmd_read_bit(ch,es_modbus_rtu_address_gu16a[index_u8]++,&qw_u8);//将地址送到读取函数中，获取对应的比特值。
                            if(qw_u8)temp_u8|=(1<<j_u8);        //组装数据。
                        }
                        crc_u16=es_send_whit_crc(ch,crc_u16,temp_u8);           //发送组装好的数据。
                        es_modbus_rtu_data_count_gu16a[index_u8]-=(u16)c1_u8;   //计算剩下要读的数据个数。
                    }
                    uart_char(ch,(u8)(crc_u16));                //发送CRC
                    uart_char(ch,(u8)(crc_u16>>8));
                }
            }else{                                              //如果地址+个数超过65536。
                es_modbus_rtu_err_num(ch,0x01,0x02);//发送错误码02。
            }
        }else{                                              //如果个数本身就超过2000了。
            es_modbus_rtu_err_num(ch,0x01,0x03);//发送错误码03。
        }
    }
#endif
/*-------------------------------------------------------
2号功能码处理函数。
-------------------------------------------------------*/
#if (ES_MODBUS_RTU_CMD02_EN)
    void es_modbus_rtu_cmd_0x02(u8 ch){
        u8 temp_u8,t1_u8,c1_u8,i_u8,j_u8,qw_u8,id_u8,index_u8;
        u16 crc_u16;
        index_u8=ecbm_stream_modbus_chtoid(ch);
        id_u8=es_modbus_rtu_get_id(ch);      //读取本机ID。
        if((es_modbus_rtu_data_count_gu16a[index_u8]>=1)&&(es_modbus_rtu_data_count_gu16a[index_u8]<=0x07D0)){              //读取的个数要在1个以上，且地址不能大于2000。
            if(((u32)(es_modbus_rtu_data_count_gu16a[index_u8])+(u32)(es_modbus_rtu_address_gu16a[index_u8]))<=65536UL){    //判断地址+个数有没有超限。
                    if(es_modbus_rtu_broadcast_en_gu8a[index_u8]){              //如果是广播帧，那么便不能回复。
                        t1_u8=(u8)(es_modbus_rtu_data_count_gu16a[index_u8]/8); //统计要读取的数据能凑够多少个字节。
                        if(es_modbus_rtu_data_count_gu16a[index_u8]%8)t1_u8++;  //剩下的不足8位的数据也要一个字节来传输。
                        crc_u16=es_send_whit_crc(ch,0xFFFF,id_u8);              //发送地址。
                        crc_u16=es_send_whit_crc(ch,crc_u16,0x02);              //发送功能码回复。
                        crc_u16=es_send_whit_crc(ch,crc_u16,t1_u8);             //发送数据长度。
                        for(i_u8=0;i_u8<t1_u8;i_u8++){      //从起始位置开始组装数据。
                            temp_u8=0;                      //清零变量。
                            if(es_modbus_rtu_data_count_gu16a[index_u8]>=8){    //如果剩余要读的数据多于8个比特。
                                c1_u8=8;                    //那么本轮循环先读8比特数据。
                            }else{                          //否则，
                                c1_u8=(u8)(es_modbus_rtu_data_count_gu16a[index_u8]);  //就有多少读多少。
                            }
                            for(j_u8=0;j_u8<c1_u8;j_u8++){      
                                es_modbus_cmd_read_io_bit(ch,es_modbus_rtu_address_gu16a[index_u8]++,&qw_u8);//将地址送到读取函数中，获取对应的比特值。
                                if(qw_u8)temp_u8|=(1<<j_u8);        //组装数据。
                            }
                            crc_u16=es_send_whit_crc(ch,crc_u16,temp_u8);           //发送组装好的数据。
                            es_modbus_rtu_data_count_gu16a[index_u8]-=(u16)c1_u8;   //计算剩下要读的数据个数。
                        }
                        uart_char(ch,(u8)(crc_u16));                //发送CRC。
                        uart_char(ch,(u8)(crc_u16>>8));
                    }
            }else{                                  //如果地址+个数超过2000。
                es_modbus_rtu_err_num(ch,0x02,0x02);//发送错误码02。
            }
        }else{                                  //如果个数本身就超过65536了。
            es_modbus_rtu_err_num(ch,0x02,0x03);//发送错误码03。
        }
    }
#endif
/*-------------------------------------------------------
3号功能码处理函数。
-------------------------------------------------------*/
#if (ES_MODBUS_RTU_CMD03_EN)
    void es_modbus_rtu_cmd_0x03(u8 ch){
        u8 id_u8,index_u8;
        u16 temp_u16,i_u16,crc_u16;
        index_u8=ecbm_stream_modbus_chtoid(ch);
        id_u8=es_modbus_rtu_get_id(ch);      //读取本机ID。
        if((es_modbus_rtu_data_count_gu16a[index_u8]>=1)&&(es_modbus_rtu_data_count_gu16a[index_u8]<=0x007D)){          //读取的个数要在1个以上，且地址不能大于125。
            if(((u32)(es_modbus_rtu_data_count_gu16a[index_u8])+(u32)(es_modbus_rtu_address_gu16a[index_u8]))<65536UL){ //判断地址+个数有没有超限。
                if(es_modbus_rtu_broadcast_en_gu8a[index_u8]){
                    crc_u16=es_send_whit_crc(ch,0xFFFF,id_u8);            //发送地址。
                    crc_u16=es_send_whit_crc(ch,crc_u16,0x03);             //发送功能码回复。
                    crc_u16=es_send_whit_crc(ch,crc_u16,es_modbus_rtu_data_count_gu16a[index_u8]*2);//发送回复字节数。
                    for(i_u16=0;i_u16<es_modbus_rtu_data_count_gu16a[index_u8];i_u16++){
                        es_modbus_cmd_read_reg(ch,es_modbus_rtu_address_gu16a[index_u8]+i_u16,&temp_u16);//从寄存器变量里把数据取出来。
                        crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(temp_u16>>8)); //发送数据。
                        crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(temp_u16));
                    }
                    uart_char(ch,(u8)(crc_u16));//发送CRC。
                    uart_char(ch,(u8)(crc_u16>>8));
                }
            }else{
                es_modbus_rtu_err_num(ch,0x03,0x02);//发送错误码02。
            }
        }else{                                  //如果个数本身就超过125了。
            es_modbus_rtu_err_num(ch,0x03,0x03);//发送错误码03。
        }
    }
#endif
/*-------------------------------------------------------
4号功能码处理函数。
-------------------------------------------------------*/
#if (ES_MODBUS_RTU_CMD04_EN)
    void es_modbus_rtu_cmd_0x04(u8 ch){
        u8 id_u8,index_u8;
        u16 temp_u16,i_u16,crc_u16;
        index_u8=ecbm_stream_modbus_chtoid(ch);
        id_u8=es_modbus_rtu_get_id(ch);      //读取本机ID。
        if((es_modbus_rtu_data_count_gu16a[index_u8]>=1)&&(es_modbus_rtu_data_count_gu16a[index_u8]<=0x007D)){          //读取的个数要在1个以上，且地址不能大于125。
            if(((u32)(es_modbus_rtu_data_count_gu16a[index_u8])+(u32)(es_modbus_rtu_address_gu16a[index_u8]))<65536UL){ //判断地址+个数有没有超限。
                if(es_modbus_rtu_broadcast_en_gu8a[index_u8]){
                    crc_u16=es_send_whit_crc(ch,0xFFFF,id_u8);            //发送地址。
                    crc_u16=es_send_whit_crc(ch,crc_u16,0x04);             //发送功能码回复。
                    crc_u16=es_send_whit_crc(ch,crc_u16,es_modbus_rtu_data_count_gu16a[index_u8]*2);//发送回复字节数。
                    for(i_u16=0;i_u16<es_modbus_rtu_data_count_gu16a[index_u8];i_u16++){
                        es_modbus_cmd_read_io_reg(ch,es_modbus_rtu_address_gu16a[index_u8]+i_u16,&temp_u16);//从寄存器变量里把数据取出来。
                        crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(temp_u16>>8));//发送数据。
                        crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(temp_u16));
                    }
                    uart_char(ch,(u8)(crc_u16));//发送CRC。
                    uart_char(ch,(u8)(crc_u16>>8));
                }
            }else{
                es_modbus_rtu_err_num(ch,0x04,0x02);//发送错误码02。
            }
        }else{                                  //如果个数本身就超过125了。
            es_modbus_rtu_err_num(ch,0x04,0x03);//发送错误码03。
        }
    }
#endif
/*-------------------------------------------------------
5号功能码处理函数。
-------------------------------------------------------*/
#if (ES_MODBUS_RTU_CMD05_EN)
    void es_modbus_rtu_cmd_0x05(u8 ch){
        u8 id_u8,index_u8;
        u16 crc_u16;
        index_u8=ecbm_stream_modbus_chtoid(ch);
        id_u8=es_modbus_rtu_get_id(ch);      //读取本机ID。
        if((es_modbus_rtu_data_count_gu16a[index_u8]==0x0000)||(es_modbus_rtu_data_count_gu16a[index_u8]==0xFF00)){//判断输出值是否合法。
            es_modbus_cmd_write_bit(ch,es_modbus_rtu_address_gu16a[index_u8],(u8)(es_modbus_rtu_data_count_gu16a[index_u8]>>8));
            if(es_modbus_rtu_broadcast_en_gu8a[index_u8]){
                crc_u16=es_send_whit_crc(ch,0xFFFF,id_u8);            //发送地址。
                crc_u16=es_send_whit_crc(ch,crc_u16,0x05);             //发送功能码回复。
                crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(es_modbus_rtu_address_gu16a[index_u8]>>8)); //发送地址回复。
                crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(es_modbus_rtu_address_gu16a[index_u8]));
                crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(es_modbus_rtu_data_count_gu16a[index_u8]>>8));//发送计数回复。
                crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(es_modbus_rtu_data_count_gu16a[index_u8]));
                uart_char(ch,(u8)(crc_u16));    //发送CRC。
                uart_char(ch,(u8)(crc_u16>>8));
            }    
        }else{                                  //如果不合法。 
            es_modbus_rtu_err_num(ch,0x05,0x03);//发送错误码03。
        }
    }
#endif
/*-------------------------------------------------------
6号功能码处理函数。
-------------------------------------------------------*/
#if (ES_MODBUS_RTU_CMD06_EN)
    void es_modbus_rtu_cmd_0x06(u8 ch){
        u8 id_u8,index_u8;
        u16 crc_u16;
        index_u8=ecbm_stream_modbus_chtoid(ch);
        id_u8=es_modbus_rtu_get_id(ch);      //读取本机ID。
        es_modbus_cmd_write_reg(ch,es_modbus_rtu_address_gu16a[index_u8],es_modbus_rtu_data_count_gu16a[index_u8]);//把数据写入寄存器。
        if(es_modbus_rtu_broadcast_en_gu8a[index_u8]){
            crc_u16=es_send_whit_crc(ch,0xFFFF,id_u8);    //发送地址。
            crc_u16=es_send_whit_crc(ch,crc_u16,0x06);     //发送功能码回复。
            crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(es_modbus_rtu_address_gu16a[index_u8]>>8));//发送地址。
            crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(es_modbus_rtu_address_gu16a[index_u8]));
            crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(es_modbus_rtu_data_count_gu16a[index_u8]>>8));//发送个数。
            crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(es_modbus_rtu_data_count_gu16a[index_u8]));
            uart_char(ch,(u8)(crc_u16));//发送CRC。
            uart_char(ch,(u8)(crc_u16>>8));
        }    
    }
#endif
/*-------------------------------------------------------
16号功能码处理函数。
-------------------------------------------------------*/
#if (ES_MODBUS_RTU_CMD10_EN)
    void es_modbus_rtu_cmd_0x10(u8 ch){
        u8 i_u8,id_u8,index_u8;
        u16 crc_u16;
        index_u8=ecbm_stream_modbus_chtoid(ch);
        id_u8=es_modbus_rtu_get_id(ch);      //读取本机ID。
        if((es_modbus_rtu_cmd_count_gu8a[index_u8]==0)||(es_modbus_rtu_cmd_count_gu8a[index_u8]!=(u8)(es_modbus_rtu_data_count_gu16a[index_u8]*2))){//如果数量不合。
            es_modbus_rtu_err_num(ch,es_modbus_rtu_fun_code_gu8a[index_u8],0x03);//字节数对不上，发送错误码03。
            return;
        }
        if((es_modbus_rtu_data_count_gu16a[index_u8]>=0x0001)&&(es_modbus_rtu_data_count_gu16a[index_u8]<=0x007B)){             //输入的数据个数得符合要求。
            if(((u32)(es_modbus_rtu_address_gu16a[index_u8])+(u32)(es_modbus_rtu_data_count_gu16a[index_u8]))<65536UL){             //地址不能超过65536。
                for(i_u8=0;i_u8<es_modbus_rtu_cmd_count_gu8a[index_u8];i_u8++){   
                    es_modbus_cmd_write_reg(ch,es_modbus_rtu_address_gu16a[index_u8]+i_u8,es_modbus_rtu_cmd_buf_gu16a[index_u8][i_u8]);  //把数据写入寄存器。
                }
                if(es_modbus_rtu_broadcast_en_gu8a[index_u8]){
                    crc_u16=es_send_whit_crc(ch,0xFFFF,id_u8);            //发送地址。
                    crc_u16=es_send_whit_crc(ch,crc_u16,0x10);             //发送功能码回复。
                    crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(es_modbus_rtu_address_gu16a[index_u8]>>8));//发送地址。
                    crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(es_modbus_rtu_address_gu16a[index_u8]));
                    crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(es_modbus_rtu_data_count_gu16a[index_u8]>>8));//发送个数。
                    crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(es_modbus_rtu_data_count_gu16a[index_u8]));
                    uart_char(ch,(u8)(crc_u16));    //发送CRC。
                    uart_char(ch,(u8)(crc_u16>>8));
                }   
            }else{
                es_modbus_rtu_err_num(ch,0x10,0x02);//发送错误码02。
            }
        }else{                                  //如果不合法。 
            es_modbus_rtu_err_num(ch,0x10,0x03);//发送错误码03。
        }
    }
#endif
/*-------------------------------------------------------
modbus_rtu解析执行函数。
-------------------------------------------------------*/
void es_modbus_rtu_exe(u8 ch,u8 dat){
    u8 i_u8,temp_u8,mask_u8,index_u8;
    i_u8=i_u8;
    temp_u8=temp_u8;
    mask_u8=mask_u8;
    index_u8=ecbm_stream_modbus_chtoid(ch);

    if(es_modbus_rtu_mode_gu8a[index_u8]==ES_MODBUS_RTU_MODE_SLAVE){//从机模式
        switch(es_modbus_rtu_status_gu8a[index_u8]){
            case ES_MODBUS_RTU_READY:{                          //就绪，等待接收数据。
                if((dat==es_modbus_rtu_get_id(ch))||(dat==0)){  //如果收到的ID和本机的匹配。
                    es_modbus_rtu_status_gu8a      [index_u8]=ES_MODBUS_RTU_FUN_NUM;//切换到功能码识别。
                    es_modbus_rtu_broadcast_en_gu8a[index_u8]=dat;     //写入通信模式，为了简化代码，采用直接赋值。
                    es_modbus_rtu_fun_code_gu8a    [index_u8]=0;       //清零功能码缓存。
                    es_modbus_rtu_uart_crc_gu16a   [index_u8]=es_crc16(0xFFFF,dat);//计算CRC。
                }
            }break;
            case ES_MODBUS_RTU_FUN_NUM:{        //正在接收功能码。
                es_modbus_rtu_fun_code_gu8a [index_u8]=dat;
                es_modbus_rtu_status_gu8a   [index_u8]=ES_MODBUS_RTU_ADDRH;    //现阶段不做功能码的限制，报错将移动到CRC结束。
                es_modbus_rtu_uart_crc_gu16a[index_u8]=es_crc16(es_modbus_rtu_uart_crc_gu16a[index_u8],dat);
            }break;
            case ES_MODBUS_RTU_ADDRH:{                        //接收地址的高8位。
                es_modbus_rtu_address_gu16a [index_u8]=(u16)(dat)<<8;    //组装地址。
                es_modbus_rtu_status_gu8a   [index_u8]=ES_MODBUS_RTU_ADDRL;//到下一步。
                es_modbus_rtu_uart_crc_gu16a[index_u8]=es_crc16(es_modbus_rtu_uart_crc_gu16a[index_u8],dat);
            }break;
            case ES_MODBUS_RTU_ADDRL:{                        //接收地址的低8位。
                es_modbus_rtu_address_gu16a [index_u8]+=(u16)(dat);              //组装地址。
                es_modbus_rtu_status_gu8a   [index_u8]=ES_MODBUS_RTU_DATA_COUNTH;  //到下一步。
                es_modbus_rtu_uart_crc_gu16a[index_u8]=es_crc16(es_modbus_rtu_uart_crc_gu16a[index_u8],dat);//计算CRC。
            }break;
            case ES_MODBUS_RTU_DATA_COUNTH:{                  //接收数据/个数的高8位。
                es_modbus_rtu_data_count_gu16a[index_u8]=(u16)(dat)<<8;         //组装数据/个数。
                es_modbus_rtu_status_gu8a     [index_u8]=ES_MODBUS_RTU_DATA_COUNTL;  //到下一步。
                es_modbus_rtu_uart_crc_gu16a  [index_u8]=es_crc16(es_modbus_rtu_uart_crc_gu16a[index_u8],dat);//计算CRC。
            }break;
            case ES_MODBUS_RTU_DATA_COUNTL:{                  //接收数据/个数的低8位。
                es_modbus_rtu_data_count_gu16a  [index_u8]+=(u16)(dat);           //组装数据/个数。
                if(es_modbus_rtu_fun_code_gu8a  [index_u8]==0x10){
                    es_modbus_rtu_cmd_count_gu8a[index_u8]=0;
                    es_modbus_rtu_status_gu8a   [index_u8]=ES_MODBUS_RTU_BYTE_COUNT;//到字节读取。
                }else{
                    es_modbus_rtu_status_gu8a[index_u8]=ES_MODBUS_RTU_CRCL;//到CRC。
                }
                es_modbus_rtu_uart_crc_gu16a[index_u8]=es_crc16(es_modbus_rtu_uart_crc_gu16a[index_u8],dat);//计算CRC。
            }break;
            case ES_MODBUS_RTU_CRCL:{                         //接收CRC的低8位。
                es_modbus_rtu_crc_buf_gu16a[index_u8]=(u16)(dat);       //组合CRC。
                es_modbus_rtu_status_gu8a  [index_u8]=ES_MODBUS_RTU_CRCH; //到下一步。
            }break;
            case ES_MODBUS_RTU_CRCH:{                         //接收CRC的高8位。
                es_modbus_rtu_crc_buf_gu16a[index_u8]+=(u16)dat<<8;           //组合CRC。
                if(es_modbus_rtu_crc_buf_gu16a[index_u8]==es_modbus_rtu_uart_crc_gu16a[index_u8]){//判断接收的CRC和计算的CRC是否相等。
                    #if (ES_MODBUS_RTU_CMD_ALL_EN)
                        switch(es_modbus_rtu_fun_code_gu8a[index_u8]){//根据功能码来选择对应的动作。
                            #if (ES_MODBUS_RTU_CMD01_EN)
                                case 0x01:es_modbus_rtu_cmd_0x01(ch);break;
                            #endif
                            #if (ES_MODBUS_RTU_CMD02_EN)
                                case 0x02:es_modbus_rtu_cmd_0x02(ch);break;
                            #endif
                            #if (ES_MODBUS_RTU_CMD03_EN)
                                case 0x03:es_modbus_rtu_cmd_0x03(ch);break;
                            #endif
                            #if (ES_MODBUS_RTU_CMD04_EN)
                                case 0x04:es_modbus_rtu_cmd_0x04(ch);break;
                            #endif
                            #if (ES_MODBUS_RTU_CMD05_EN)
                                case 0x05:es_modbus_rtu_cmd_0x05(ch);break;
                            #endif
                            #if (ES_MODBUS_RTU_CMD06_EN)
                                case 0x06:es_modbus_rtu_cmd_0x06(ch);break;
                            #endif
                            #if (ES_MODBUS_RTU_CMD10_EN)
                                case 0x10:es_modbus_rtu_cmd_0x10(ch);break;
                            #endif
                            default:{
                                es_modbus_rtu_err_num(ch,es_modbus_rtu_fun_code_gu8a[index_u8],0x01);//发送错误码01。
                            }break;//不支持的功能码就返回0x80+功能码。
                        }
                    #endif
                }
                #if (ES_MODBUS_RTU_CRC_ERR_EN)
                    else{                                          //否则，
                        es_modbus_rtu_crc_err_callback(ch);//就跳到CRC错误界面。
                    }
                #endif
                es_modbus_rtu_status_gu8a[index_u8]=ES_MODBUS_RTU_READY;
            }break;
            #if (ES_MODBUS_RTU_CMD10_EN)
                case ES_MODBUS_RTU_BYTE_COUNT:{                   //接收数据字节数。
                    es_modbus_rtu_cmd_count_gu8a[index_u8]=dat;
                    es_modbus_rtu_count_gu8a[index_u8]=0;
                    es_modbus_rtu_status_gu8a[index_u8]=ES_MODBUS_RTU_DATAH;//调到对应的处理界面。
                    es_modbus_rtu_uart_crc_gu16a[index_u8]=es_crc16(es_modbus_rtu_uart_crc_gu16a[index_u8],dat);//计算CRC。
                }break;
                case ES_MODBUS_RTU_DATAH:{
                    es_modbus_rtu_cmd_buf_gu16a [index_u8][es_modbus_rtu_count_gu8a[index_u8]/2]=((u16)(dat))<<8;
                    es_modbus_rtu_count_gu8a[index_u8]++;
                    if(es_modbus_rtu_count_gu8a[index_u8]==(u8)(es_modbus_rtu_cmd_count_gu8a[index_u8])){
                        es_modbus_rtu_status_gu8a[index_u8]=ES_MODBUS_RTU_CRCL;//到CRC。
                    }else{
                        es_modbus_rtu_status_gu8a   [index_u8]=ES_MODBUS_RTU_DATAL;   //到低8位。
                    }
                    es_modbus_rtu_uart_crc_gu16a[index_u8]=es_crc16(es_modbus_rtu_uart_crc_gu16a[index_u8],dat);//计算CRC。
                }break;
                case ES_MODBUS_RTU_DATAL:{
                    es_modbus_rtu_cmd_buf_gu16a[index_u8][es_modbus_rtu_count_gu8a[index_u8]/2]+=((u16)(dat));
                    es_modbus_rtu_count_gu8a[index_u8]++;
                    if(es_modbus_rtu_count_gu8a[index_u8]==(u8)(es_modbus_rtu_cmd_count_gu8a[index_u8])){
                        es_modbus_rtu_status_gu8a[index_u8]=ES_MODBUS_RTU_CRCL;//到CRC。
                    }else{
                        es_modbus_rtu_status_gu8a[index_u8]=ES_MODBUS_RTU_DATAH;//到下一个数据的高8位。
                    }
                    es_modbus_rtu_uart_crc_gu16a[index_u8]=es_crc16(es_modbus_rtu_uart_crc_gu16a[index_u8],dat);//计算CRC。
                }break;
            #endif
        }
    }else{//主机模式
        #if (ES_MODBUS_RTU_MASTER_EN)
            switch(es_modbus_rtu_status_gu8a[index_u8]){
                case ES_MODBUS_RTU_READY:{                          //等待从机返回。
                    if(es_modbus_rtu_send_id_gu8a[index_u8]==dat){                 //主机接收只有一个限定，就是返回的ID必须是发送的ID。
                        es_modbus_rtu_status_gu8a[index_u8]=ES_MODBUS_RTU_FUN_NUM; //切换到功能码识别。
                        es_modbus_rtu_fun_code_gu8a[index_u8]=0;                   //清零功能码缓存。
                        es_modbus_rtu_uart_crc_gu16a[index_u8]=es_crc16(0xFFFF,dat);//计算CRC。
                    }
                }break;
                case ES_MODBUS_RTU_FUN_NUM:{        //正在接收功能码。
                    es_modbus_rtu_fun_code_gu8a[index_u8]=dat;     //保存功能码，之后都用得到。
                    if(es_modbus_rtu_fun_code_gu8a[index_u8]<127){
                        switch(es_modbus_rtu_fun_code_gu8a[index_u8]){ //判断是不是本机支持的功能码。
                            #if (ES_MODBUS_RTU_MASTER_CMD01_EN)
                                case 0x01://读线圈
                            #endif
                            #if (ES_MODBUS_RTU_MASTER_CMD02_EN)
                                case 0x02://读离散量输入
                            #endif
                            #if (ES_MODBUS_RTU_MASTER_CMD03_EN)
                                case 0x03://读多个寄存器
                            #endif
                            #if (ES_MODBUS_RTU_MASTER_CMD04_EN)    
                                case 0x04://读输入寄存器
                            #endif    
                            #if (ES_MODBUS_RTU_MASTER_CMD_01020304_EN)
                                {//以上4种功能码的返回格式是一样的。
                                    es_modbus_rtu_status_gu8a[index_u8]=ES_MODBUS_RTU_RETURN_COUNT;            //跳到接收返回数量。
                                    es_modbus_rtu_uart_crc_gu16a[index_u8]=es_crc16(es_modbus_rtu_uart_crc_gu16a[index_u8],dat);//计算CRC。
                                }break;
                            #endif    
                            #if (ES_MODBUS_RTU_MASTER_CMD05_EN)    
                                case 0x05://写单个线圈
                            #endif    
                            #if (ES_MODBUS_RTU_MASTER_CMD06_EN)  
                                case 0x06://写单个寄存器
                            #endif    
                            #if (ES_MODBUS_RTU_MASTER_CMD10_EN)      
                                case 0x10://写多个寄存器
                            #endif     
                            #if (ES_MODBUS_RTU_MASTER_CMD_050610_EN)
                                {//以上3种功能码的返回格式是一样的。
                                    es_modbus_rtu_status_gu8a[index_u8]=ES_MODBUS_RTU_ADDRH;                   //跳到接收返回地址。
                                    es_modbus_rtu_uart_crc_gu16a[index_u8]=es_crc16(es_modbus_rtu_uart_crc_gu16a[index_u8],dat);//计算CRC。
                                }break;
                            #endif
                            default:{//如果不是以上7种，那么说明现在还没支持这个指令。
                                es_modbus_rtu_status_gu8a[index_u8]=ES_MODBUS_RTU_READY;//回到待机。
                            }break;
                        }
                    }else{
                        es_modbus_rtu_status_gu8a[index_u8]=ES_MODBUS_RTU_ERROR_CODE;
                        es_modbus_rtu_uart_crc_gu16a[index_u8]=es_crc16(es_modbus_rtu_uart_crc_gu16a[index_u8],dat);//计算CRC。
                    }
                }break;
                case ES_MODBUS_RTU_ERROR_CODE:{
                    es_modbus_rtu_reply_count_gu8a[index_u8]=dat;//借用一下这个变量来存错误码。
                    es_modbus_rtu_status_gu8a[index_u8]=ES_MODBUS_RTU_CRCL;                    //跳到接收返回地址。
                    es_modbus_rtu_uart_crc_gu16a[index_u8]=es_crc16(es_modbus_rtu_uart_crc_gu16a[index_u8],dat);//计算CRC。
                }break;
                #if (ES_MODBUS_RTU_MASTER_CMD_01020304_EN)
                    case ES_MODBUS_RTU_RETURN_COUNT:{   //接收返回数量。
                        es_modbus_rtu_reply_count_gu8a[index_u8]=dat;  //保存这个数量，单位是字节。
                        es_modbus_rtu_cmd_count_gu8a  [index_u8]=0;    //清零计数变量。
                        switch(es_modbus_rtu_fun_code_gu8a[index_u8]){ //不同的指令有不同的处理。
                            default:break;
                            #if (ES_MODBUS_RTU_MASTER_CMD01_EN)  
                                case 0x01://读线圈
                            #endif
                            #if (ES_MODBUS_RTU_MASTER_CMD02_EN) 
                                case 0x02://读离散量输入
                            #endif
                            #if (ES_MODBUS_RTU_MASTER_CMD_0102_EN)
                                {//以上两个指令是一个字节存8个线圈的数据。
                                    es_modbus_rtu_status_gu8a[index_u8]=ES_MODBUS_RTU_0102_RETURN;//跳到[01H][02H]处理。
                                }break;
                            #endif
                            #if (ES_MODBUS_RTU_MASTER_CMD03_EN)  
                                case 0x03://读多个寄存器
                            #endif
                            #if (ES_MODBUS_RTU_MASTER_CMD04_EN)  
                                case 0x04://读输入寄存器
                            #endif
                            #if (ES_MODBUS_RTU_MASTER_CMD_0304_EN)
                                {//以上两个指令是两个字节存一个寄存器的数据。
                                    es_modbus_rtu_status_gu8a[index_u8]=ES_MODBUS_RTU_0304_RETURN;//跳到[03H][04H]处理。
                                }break;
                            #endif
                        }
                        es_modbus_rtu_uart_crc_gu16a[index_u8]=es_crc16(es_modbus_rtu_uart_crc_gu16a[index_u8],dat);//计算CRC。
                    }break;
                #endif
                #if (ES_MODBUS_RTU_MASTER_CMD_0102_EN)
                    case ES_MODBUS_RTU_0102_RETURN:{                                //[01H][02H]指令的处理。
                        es_modbus_rtu_cmd_buf_gu16a[index_u8][es_modbus_rtu_cmd_count_gu8a[index_u8]++]=dat;       //将接收的数据保存下来。
                        es_modbus_rtu_uart_crc_gu16a[index_u8]=es_crc16(es_modbus_rtu_uart_crc_gu16a[index_u8],dat);//计算CRC。
                        if(es_modbus_rtu_cmd_count_gu8a[index_u8]>=es_modbus_rtu_reply_count_gu8a[index_u8]){     //当接收的数量达到要求时，
                            es_modbus_rtu_status_gu8a[index_u8]=ES_MODBUS_RTU_CRCL;                //到接收CRC。
                        }
                    }break;
                #endif
                #if (ES_MODBUS_RTU_MASTER_CMD_0304_EN)
                    case ES_MODBUS_RTU_0304_RETURN:{                                //[03H][04H]指令的处理。
                        if(es_modbus_rtu_cmd_count_gu8a[index_u8]%2){                              //当接收数量为奇数时，
                            es_modbus_rtu_cmd_buf_gu16a[index_u8][es_modbus_rtu_cmd_count_gu8a[index_u8]>>1]<<=8;  //把上次接收的数据左移到高8位。
                            es_modbus_rtu_cmd_buf_gu16a[index_u8][es_modbus_rtu_cmd_count_gu8a[index_u8]>>1]+=dat; //然后加入数据到低8位。
                        }else{                                                      //当接收数量为偶数或者0时，
                            es_modbus_rtu_cmd_buf_gu16a[index_u8][es_modbus_rtu_cmd_count_gu8a[index_u8]>>1]=dat;  //直接加入数据。
                        }//虽然modbus的数据帧决定了接收数量是偶数，但还是按照“需要加数据的时候才移位”的习惯，把左移操作放在了低8位数据出现的执行语句中。
                        es_modbus_rtu_cmd_count_gu8a[index_u8]++;                                  //已接收数量加一。
                        es_modbus_rtu_uart_crc_gu16a[index_u8]=es_crc16(es_modbus_rtu_uart_crc_gu16a[index_u8],dat);//计算CRC。
                        if(es_modbus_rtu_cmd_count_gu8a[index_u8]>=es_modbus_rtu_reply_count_gu8a[index_u8]){     //当接收的数量达到要求时，
                            es_modbus_rtu_status_gu8a[index_u8]=ES_MODBUS_RTU_CRCL;                //到接收CRC。
                        }
                    }break;
                #endif
                #if (ES_MODBUS_RTU_MASTER_CMD_050610_EN)
                    case ES_MODBUS_RTU_ADDRH:{                      //接收返回地址的高8位。
                        es_modbus_rtu_cmd_buf_gu16a[index_u8][0]=(u16)dat<<8;       //组装地址。
                        es_modbus_rtu_status_gu8a[index_u8]=ES_MODBUS_RTU_ADDRL;   //到下一步。
                        es_modbus_rtu_uart_crc_gu16a[index_u8]=es_crc16(es_modbus_rtu_uart_crc_gu16a[index_u8],dat);//计算CRC。
                    }break;
                    case ES_MODBUS_RTU_ADDRL:{                          //接收返回地址的低8位。
                        es_modbus_rtu_cmd_buf_gu16a[index_u8][0]+=(u16)(dat);             //组装地址。
                        es_modbus_rtu_status_gu8a[index_u8]=ES_MODBUS_RTU_DATA_COUNTH; //到下一步。
                        es_modbus_rtu_uart_crc_gu16a[index_u8]=es_crc16(es_modbus_rtu_uart_crc_gu16a[index_u8],dat);//计算CRC。
                    }break;
                    case ES_MODBUS_RTU_DATA_COUNTH:{                    //接收返回个数的高8位。
                        es_modbus_rtu_cmd_buf_gu16a[index_u8][1]=(u16)(dat)<<8;           //组装返回个数。
                        es_modbus_rtu_status_gu8a[index_u8]=ES_MODBUS_RTU_DATA_COUNTL; //到下一步。
                        es_modbus_rtu_uart_crc_gu16a[index_u8]=es_crc16(es_modbus_rtu_uart_crc_gu16a[index_u8],dat);//计算CRC。
                    }break;
                    case ES_MODBUS_RTU_DATA_COUNTL:{            //接收返回个数的低8位。
                        es_modbus_rtu_cmd_buf_gu16a[index_u8][1]+=(u16)(dat);     //组装返回个数。
                        es_modbus_rtu_status_gu8a[index_u8]=ES_MODBUS_RTU_CRCL;//到CRC。
                        es_modbus_rtu_uart_crc_gu16a[index_u8]=es_crc16(es_modbus_rtu_uart_crc_gu16a[index_u8],dat);//计算CRC。
                    }break;
                #endif
                case ES_MODBUS_RTU_CRCL:{                       //接收CRC的低8位。
                    es_modbus_rtu_crc_buf_gu16a[index_u8]=(u16)(dat);           //把CRC的低8位存起来。
                    es_modbus_rtu_status_gu8a[index_u8]=ES_MODBUS_RTU_CRCH;    //到下一步。
                }break;
                case ES_MODBUS_RTU_CRCH:{                       //接收CRC的高8位。
                    es_modbus_rtu_crc_buf_gu16a[index_u8]+=(u16)(dat)<<8;       //拼接两次数据得到完整CRC。
                    if(es_modbus_rtu_crc_buf_gu16a[index_u8]==es_modbus_rtu_uart_crc_gu16a[index_u8]){
                        switch(es_modbus_rtu_fun_code_gu8a[index_u8]){
                            default:break;
                            #if (ES_MODBUS_RTU_MASTER_CMD01_EN)
                                case 0x01:{
                                    for(i_u8=0;i_u8<es_modbus_rtu_data_count_gu16a[index_u8];i_u8++){
                                        mask_u8=0x01<<(i_u8%8);
                                        temp_u8=(i_u8/8);
                                        if(es_modbus_rtu_cmd_buf_gu16a[index_u8][temp_u8]&mask_u8){
                                            mask_u8=1;
                                        }else{
                                            mask_u8=0;
                                        }
                                        es_modbus_rtu_master_0x01_callback(ch,es_modbus_rtu_send_id_gu8a[index_u8],es_modbus_rtu_address_gu16a[index_u8]+i_u8,mask_u8);
                                    }
                                }break;
                            #endif
                            #if (ES_MODBUS_RTU_MASTER_CMD02_EN)
                                case 0x02:{
                                    for(i_u8=0;i_u8<es_modbus_rtu_data_count_gu16a[index_u8];i_u8++){
                                        mask_u8=0x01<<(i_u8%8);
                                        temp_u8=(i_u8/8);
                                        if(es_modbus_rtu_cmd_buf_gu16a[index_u8][temp_u8]&mask_u8){
                                            mask_u8=1;
                                        }else{
                                            mask_u8=0;
                                        }
                                        es_modbus_rtu_master_0x02_callback(ch,es_modbus_rtu_send_id_gu8a[index_u8],es_modbus_rtu_address_gu16a[index_u8]+i_u8,mask_u8);
                                    }
                                }break;
                            #endif
                            #if (ES_MODBUS_RTU_MASTER_CMD03_EN)
                                case 0x03:{
                                    for(i_u8=0;i_u8<es_modbus_rtu_data_count_gu16a[index_u8];i_u8++){
                                        es_modbus_rtu_master_0x03_callback(ch,es_modbus_rtu_send_id_gu8a[index_u8],es_modbus_rtu_address_gu16a[index_u8]+i_u8,es_modbus_rtu_cmd_buf_gu16a[index_u8][i_u8]);
                                    }
                                }break;
                            #endif
                            #if (ES_MODBUS_RTU_MASTER_CMD04_EN)
                                case 0x04:{
                                    for(i_u8=0;i_u8<es_modbus_rtu_data_count_gu16a[index_u8];i_u8++){
                                        es_modbus_rtu_master_0x04_callback(ch,es_modbus_rtu_send_id_gu8a[index_u8],es_modbus_rtu_address_gu16a[index_u8]+i_u8,es_modbus_rtu_cmd_buf_gu16a[index_u8][i_u8]);
                                    }
                                }break;
                            #endif
                            #if (ES_MODBUS_RTU_MASTER_CMD05_EN)
                                case 0x05:{
                                    if(es_modbus_rtu_cmd_buf_gu16a[index_u8][1]){
                                        es_modbus_rtu_master_0x05_callback(ch,es_modbus_rtu_send_id_gu8a[index_u8],es_modbus_rtu_cmd_buf_gu16a[index_u8][0],1); 
                                    }else{
                                        es_modbus_rtu_master_0x05_callback(ch,es_modbus_rtu_send_id_gu8a[index_u8],es_modbus_rtu_cmd_buf_gu16a[index_u8][0],0);
                                    }
                                }break;
                            #endif
                            #if (ES_MODBUS_RTU_MASTER_CMD06_EN)
                                case 0x06:{
                                    es_modbus_rtu_master_0x06_callback(ch,es_modbus_rtu_send_id_gu8a[index_u8],es_modbus_rtu_cmd_buf_gu16a[index_u8][0],es_modbus_rtu_cmd_buf_gu16a[index_u8][1]);
                                }break;
                            #endif
                            #if (ES_MODBUS_RTU_MASTER_CMD10_EN)
                                case 0x10:{
                                    es_modbus_rtu_master_0x10_callback(ch,es_modbus_rtu_send_id_gu8a[index_u8],es_modbus_rtu_cmd_buf_gu16a[index_u8][0],es_modbus_rtu_cmd_buf_gu16a[index_u8][1]);
                                }break;
                            #endif
                        }
                        if(es_modbus_rtu_fun_code_gu8a[index_u8]>127){
                            es_modbus_rtu_master_err_code_callback(ch,es_modbus_rtu_send_id_gu8a[index_u8],es_modbus_rtu_fun_code_gu8a[index_u8]-0x80,es_modbus_rtu_reply_count_gu8a[index_u8]);
                        }
                    }else{
                        #if (ES_MODBUS_RTU_MASTER_CRC_ERR_EN)
                            es_modbus_rtu_master_crc_err_callback(ch,es_modbus_rtu_send_id_gu8a[index_u8]);
                        #endif
                    }
                }break;
            }
        #endif
    }
}
/*-------------------------------------------------------
设置从机模式函数。
-------------------------------------------------------*/
#if (ES_MODBUS_RTU_MASTER_EN)
    void es_modbus_rtu_set_slave_mode(u8 ch){
        u8 index_u8;
        index_u8=ecbm_stream_modbus_chtoid(ch);
        es_modbus_rtu_mode_gu8a  [index_u8]=ES_MODBUS_RTU_MODE_SLAVE;
        es_modbus_rtu_status_gu8a[index_u8]=ES_MODBUS_RTU_READY;
    }
#endif
/*-------------------------------------------------------
主机01号功能码发送函数。
-------------------------------------------------------*/
#if ((ES_MODBUS_RTU_MASTER_EN)&&(ES_MODBUS_RTU_MASTER_CMD01_EN))
    void es_modbus_rtu_master_0x01(u8 ch,u8 id,u16 addr,u16 len){
        u16 crc_u16;
        u8 index_u8;
        index_u8=ecbm_stream_modbus_chtoid(ch);
        es_modbus_rtu_mode_gu8a[index_u8]=ES_MODBUS_RTU_MODE_MASTER;
        es_modbus_rtu_send_id_gu8a[index_u8]=id;
        crc_u16=es_send_whit_crc(ch,0xFFFF,id);
        crc_u16=es_send_whit_crc(ch,crc_u16,0x01);
        crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(addr>>8));
        crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(addr   ));
        if(len==0)len=1;
        if(len>2000)len=2000;
        crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(len>>8));
        crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(len   ));
        uart_char(ch,(u8)(crc_u16   ));
        uart_char(ch,(u8)(crc_u16>>8));
    }
#endif
/*-------------------------------------------------------
主机02号功能码发送函数。
-------------------------------------------------------*/
#if ((ES_MODBUS_RTU_MASTER_EN)&&(ES_MODBUS_RTU_MASTER_CMD02_EN))
    void es_modbus_rtu_master_0x02(u8 ch,u8 id,u16 addr,u16 len){
        u16 crc_u16;
        u8 index_u8;
        index_u8=ecbm_stream_modbus_chtoid(ch);
        es_modbus_rtu_mode_gu8a[index_u8]=ES_MODBUS_RTU_MODE_MASTER;
        es_modbus_rtu_send_id_gu8a[index_u8]=id;
        crc_u16=es_send_whit_crc(ch,0xFFFF,id);
        crc_u16=es_send_whit_crc(ch,crc_u16,0x02);
        crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(addr>>8));
        crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(addr   ));
        if(len==0)len=1;
        if(len>2000)len=2000;
        crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(len>>8));
        crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(len   ));
        uart_char(ch,(u8)(crc_u16   ));
        uart_char(ch,(u8)(crc_u16>>8));
    }
#endif
/*-------------------------------------------------------
主机03号功能码发送函数。
-------------------------------------------------------*/
#if ((ES_MODBUS_RTU_MASTER_EN)&&(ES_MODBUS_RTU_MASTER_CMD03_EN))
    void es_modbus_rtu_master_0x03(u8 ch,u8 id,u16 addr,u16 len){
        u16 crc_u16;
        u8 index_u8;
        index_u8=ecbm_stream_modbus_chtoid(ch);
        es_modbus_rtu_mode_gu8a[index_u8]=ES_MODBUS_RTU_MODE_MASTER;
        es_modbus_rtu_send_id_gu8a[index_u8]=id;
        crc_u16=es_send_whit_crc(ch,0xFFFF,id);
        crc_u16=es_send_whit_crc(ch,crc_u16,0x03);
        crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(addr>>8));
        crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(addr   ));
        if(len==0)len=1;
        if(len>125)len=125;
        crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(len>>8));
        crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(len   ));
        uart_char(ch,(u8)(crc_u16   ));
        uart_char(ch,(u8)(crc_u16>>8));
    }
#endif
/*-------------------------------------------------------
主机04号功能码发送函数。
-------------------------------------------------------*/
#if ((ES_MODBUS_RTU_MASTER_EN)&&(ES_MODBUS_RTU_MASTER_CMD04_EN))
    void es_modbus_rtu_master_0x04(u8 ch,u8 id,u16 addr,u16 len){
        u16 crc_u16;
        u8 index_u8;
        index_u8=ecbm_stream_modbus_chtoid(ch);
        es_modbus_rtu_mode_gu8a[index_u8]=ES_MODBUS_RTU_MODE_MASTER;
        es_modbus_rtu_send_id_gu8a[index_u8]=id;
        crc_u16=es_send_whit_crc(ch,0xFFFF,id);
        crc_u16=es_send_whit_crc(ch,crc_u16,0x04);
        crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(addr>>8));
        crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(addr   ));
        if(len==0)len=1;
        if(len>125)len=125;
        crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(len>>8));
        crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(len   ));
        uart_char(ch,(u8)(crc_u16   ));
        uart_char(ch,(u8)(crc_u16>>8));
    }
#endif
/*-------------------------------------------------------
主机05号功能码发送函数。
-------------------------------------------------------*/
#if ((ES_MODBUS_RTU_MASTER_EN)&&(ES_MODBUS_RTU_MASTER_CMD05_EN))
    void es_modbus_rtu_master_0x05(u8 ch,u8 id,u16 addr,u8 dat){
        u16 crc_u16;
        u8 index_u8;
        index_u8=ecbm_stream_modbus_chtoid(ch);
        es_modbus_rtu_mode_gu8a[index_u8]=ES_MODBUS_RTU_MODE_MASTER;
        es_modbus_rtu_send_id_gu8a[index_u8]=id;
        crc_u16=es_send_whit_crc(ch,0xFFFF,id);
        crc_u16=es_send_whit_crc(ch,crc_u16,0x05);
        crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(addr>>8));
        crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(addr   ));
        if(dat){
            crc_u16=es_send_whit_crc(ch,crc_u16,0xFF);
        }else{
            crc_u16=es_send_whit_crc(ch,crc_u16,0x00);
        }
        crc_u16=es_send_whit_crc(ch,crc_u16,0x00);
        uart_char(ch,(u8)(crc_u16   ));
        uart_char(ch,(u8)(crc_u16>>8));
    }
#endif
/*-------------------------------------------------------
主机06号功能码发送函数。
-------------------------------------------------------*/
#if ((ES_MODBUS_RTU_MASTER_EN)&&(ES_MODBUS_RTU_MASTER_CMD06_EN))
    void es_modbus_rtu_master_0x06(u8 ch,u8 id,u16 addr,u16 dat){
        u16 crc_u16;
        u8 index_u8;
        index_u8=ecbm_stream_modbus_chtoid(ch);
        es_modbus_rtu_mode_gu8a[index_u8]=ES_MODBUS_RTU_MODE_MASTER;
        es_modbus_rtu_send_id_gu8a[index_u8]=id;
        crc_u16=es_send_whit_crc(ch,0xFFFF,id);
        crc_u16=es_send_whit_crc(ch,crc_u16,0x06);
        crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(addr>>8));
        crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(addr   ));
        crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(dat>>8));
        crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(dat   ));
        uart_char(ch,(u8)(crc_u16   ));
        uart_char(ch,(u8)(crc_u16>>8));
    }
#endif
/*-------------------------------------------------------
主机16号功能码发送函数。
-------------------------------------------------------*/
#if ((ES_MODBUS_RTU_MASTER_EN)&&(ES_MODBUS_RTU_MASTER_CMD10_EN))
    void es_modbus_rtu_master_0x10(u8 ch,u8 id,u16 addr,u16 * dat,u16 len){
        u16 crc_u16,i_u16;
        u8 index_u8;
        index_u8=ecbm_stream_modbus_chtoid(ch);
        es_modbus_rtu_mode_gu8a[index_u8]=ES_MODBUS_RTU_MODE_MASTER;
        es_modbus_rtu_send_id_gu8a[index_u8]=id;
        crc_u16=es_send_whit_crc(ch,0xFFFF,id);
        crc_u16=es_send_whit_crc(ch,crc_u16,0x10);
        crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(addr>>8));
        crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(addr   ));
        if(len==0)len=1;
        if(len>120)len=120;
        crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(len>>8));
        crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(len   ));
        crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(len*2 ));
        for(i_u16=0;i_u16<len;i_u16++){
            crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(dat[i_u16]>>8));
            crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(dat[i_u16]   ));
        }
        uart_char(ch,(u8)(crc_u16   ));
        uart_char(ch,(u8)(crc_u16>>8));
    }
#endif
#endif  //和最上面的#ifndef配合成一个程序段。
        //以一个空行为结尾。