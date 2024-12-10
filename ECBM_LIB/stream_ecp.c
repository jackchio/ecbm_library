#include "ecbm_core.h"  //统一加载核心头文件
#if (ECBM_10MS_EN)&&(ECBM_STREAM_LIB_EN)&&(ECBM_STREAM_ECP_CH_COUNT)    //检查本库有没有被使能
/*--------------------------------------变量定义-----------------------------------*/
u8  es_ecp_status_gu8a   [ECBM_STREAM_ECP_CH_COUNT]; //状态机变量。
u8  es_ecp_data_len_gu8a [ECBM_STREAM_ECP_CH_COUNT]; //用于存放参数、数据的长度。
u8  es_ecp_count_gu8a    [ECBM_STREAM_ECP_CH_COUNT]; //用于统计实际接收的参数、数据长度。
u8  es_ecp_source_id_gu8a[ECBM_STREAM_ECP_CH_COUNT]; //源头ID，代表该帧由这个ID的器件发出。
u8  es_ecp_target_id_gu8a[ECBM_STREAM_ECP_CH_COUNT]; //目标ID，代表该帧应该由这个ID的器件接收。
u8  es_ecp_operation_gu8a[ECBM_STREAM_ECP_CH_COUNT]; //操作码缓存。
u16 es_ecp_addr16_ex_gu16a[ECBM_STREAM_ECP_CH_COUNT]; //16位扩展地址缓存。
u16 es_ecp_addr16_gu16a   [ECBM_STREAM_ECP_CH_COUNT]; //16位地址缓存。
u16 es_ecp_crc_gu16a      [ECBM_STREAM_ECP_CH_COUNT]; //用于计算接收数据的CRC。
u16 es_ecp_crc_buf_gu16a  [ECBM_STREAM_ECP_CH_COUNT]; //用于存放数据帧里的CRC。
u8  es_ecp_data_buf_gu8a[ECBM_STREAM_ECP_CH_COUNT][ES_ECP_DATA_BUF_MAX];//用于读写操作的缓存。
/*--------------------------------------程序定义-----------------------------------*/
u8 ecbm_stream_ecp_chtoid(u8 ch){
    switch(ch){
        case 1:return (0);break;
        case 2:return ( ECBM_STREAM_CH1_EN*ECBM_STREAM_ECP_CH1_EN);break;
        case 3:return ((ECBM_STREAM_CH1_EN*ECBM_STREAM_ECP_CH1_EN)+(ECBM_STREAM_CH2_EN*ECBM_STREAM_ECP_CH2_EN));break;
        case 4:return ((ECBM_STREAM_CH1_EN*ECBM_STREAM_ECP_CH1_EN)+(ECBM_STREAM_CH2_EN*ECBM_STREAM_ECP_CH2_EN)+(ECBM_STREAM_CH3_EN*ECBM_STREAM_ECP_CH3_EN));break;
    }
    return (0);
}
/*-------------------------------------------------------
ecp重置函数。
-------------------------------------------------------*/
void es_ecp_reset(u8 ch){
    u8 id_u8;
    id_u8=ecbm_stream_ecp_chtoid(ch);
    es_ecp_status_gu8a    [id_u8]=ES_ECP_READY; //状态机复位。
    es_ecp_data_len_gu8a  [id_u8]=0; //清除参数和数据的长度。
    es_ecp_count_gu8a     [id_u8]=0; //清除统计实际接收的参数、数据长度。
    es_ecp_source_id_gu8a [id_u8]=0; //清除源头ID。
    es_ecp_target_id_gu8a [id_u8]=0; //清除目标ID。
    es_ecp_operation_gu8a [id_u8]=0; //清除操作码缓存。
    es_ecp_addr16_ex_gu16a[id_u8]=0; //清除16位扩展地址缓存。
    es_ecp_addr16_gu16a   [id_u8]=0; //清除16位地址缓存。
    es_ecp_crc_gu16a      [id_u8]=0; //清除用于计算接收数据的CRC。
    es_ecp_crc_buf_gu16a  [id_u8]=0; //清除用于存放数据帧里的CRC。
}
/*-------------------------------------------------------
通用回复函数。
-------------------------------------------------------*/
void es_ecp_reply(u8 ch,u8 len,u8 cmd){
    u16 crc_u16,i_u16;
    u8 index_u8;
    index_u8=ecbm_stream_ecp_chtoid(ch);
    crc_u16=es_send_whit_crc(ch,0xffff,0xEC);      //帧头。
    crc_u16=es_send_whit_crc(ch,crc_u16, (len));    //长度。
    crc_u16=es_send_whit_crc(ch,crc_u16,~(len));    //长度反码。
    crc_u16=es_send_whit_crc(ch,crc_u16,es_ecp_source_id_gu8a[index_u8]);   //谁发过来的，返还给谁。
    crc_u16=es_send_whit_crc(ch,crc_u16,es_ecp_get_id(ch));    //带上本机的ID。
    crc_u16=es_send_whit_crc(ch,crc_u16,cmd);                  //回执。
    crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(es_ecp_addr16_ex_gu16a[index_u8]>>8));  //地址高位。
    crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(es_ecp_addr16_ex_gu16a[index_u8]   ));  //地址低位。
    crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(es_ecp_addr16_gu16a[index_u8]>>8));     //地址高位。
    crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(es_ecp_addr16_gu16a[index_u8]   ));     //地址低位。
    for(i_u16=0;i_u16<(u16)(len);i_u16++){
        crc_u16=es_send_whit_crc(ch,crc_u16,es_ecp_data_buf_gu8a[index_u8][i_u16]);
    }
    uart_char(ch,(u8)(crc_u16>>8)); 
    uart_char(ch,(u8)(crc_u16));
    uart_char(ch,0xBE);                       //帧尾。
}
/*-------------------------------------------------------
00指令处理函数。
-------------------------------------------------------*/
void es_ecp_cmd00(u8 ch){
    u8 res_u8,index_u8;
    index_u8=ecbm_stream_ecp_chtoid(ch);
    res_u8=es_ecp_trig(ch,es_ecp_addr16_gu16a[index_u8]);  //执行指令，触发某些东西。
    if((es_ecp_target_id_gu8a[index_u8])||(es_ecp_source_id_gu8a[index_u8]==255)){ //如果不是广播，或者是电脑的广播。
        es_ecp_data_buf_gu8a[index_u8][0]=res_u8;       //把执行结果放到缓存。
        if(res_u8){                                     //如果是有错的，
            es_ecp_reply(ch,1,ES_ECP_CMD_ERROR_OPERATE);//在返回的时候需要标注操作错误。
        }else{                                          //否则的话，
            es_ecp_reply(ch,1,ES_ECP_CMD_TRIG_REPLY);   //就是标注触发回复。
        }
    }
}
/*-------------------------------------------------------
02指令处理函数。
-------------------------------------------------------*/
void es_ecp_cmd02(u8 ch){
    u8 arg_len_u8,res_u8,index_u8;
    index_u8=ecbm_stream_ecp_chtoid(ch);
    arg_len_u8=es_ecp_data_buf_gu8a[index_u8][0];               //先把长度取出来。
    res_u8=es_ecp_read(ch,es_ecp_addr16_gu16a[index_u8],es_ecp_data_buf_gu8a[index_u8],arg_len_u8);//去读取寄存器。
    if((es_ecp_target_id_gu8a[index_u8])||(es_ecp_source_id_gu8a[index_u8]==255)){             //如果不是广播，或者是电脑的广播。
        if(res_u8){                                             //如果是有错的，
            es_ecp_data_buf_gu8a[index_u8][0]=res_u8;           //把执行结果放到缓存。
            es_ecp_reply(ch,1,ES_ECP_CMD_ERROR_OPERATE);        //在返回的时候需要标注操作错误。
        }else{                                                  //否则的话，
            es_ecp_reply(ch,arg_len_u8,ES_ECP_CMD_READ_REPLY);  //就是标注读取回复。
        }
    }
}
/*-------------------------------------------------------
04指令处理函数。
-------------------------------------------------------*/
void es_ecp_cmd04(u8 ch){
    u8 res_u8,index_u8;
    index_u8=ecbm_stream_ecp_chtoid(ch);
    res_u8=es_ecp_write(ch,es_ecp_addr16_gu16a[index_u8],es_ecp_data_buf_gu8a[index_u8],es_ecp_data_len_gu8a[index_u8]);//去写数据。
    if((es_ecp_target_id_gu8a[index_u8])||(es_ecp_source_id_gu8a[index_u8]==255)){        //如果不是广播，或者是电脑的广播。
        es_ecp_data_buf_gu8a[index_u8][0]=res_u8;       //把执行结果放到缓存。
        if(res_u8){                                     //如果是有错的，
            es_ecp_reply(ch,1,ES_ECP_CMD_ERROR_OPERATE);//在返回的时候需要标注操作错误。
        }else{                                          //否则的话，
            es_ecp_reply(ch,1,ES_ECP_CMD_WRITE_REPLY);  //就是标注写入回复。
        }
    }
}
/*-------------------------------------------------------
06、08指令处理函数。
-------------------------------------------------------*/
void es_ecp_cmd0608(u8 ch,u8 cmd){
    u8 res1_u8,res2_u8,temp_u8;
    u16 i_u16;
    u8 index_u8;
    index_u8=ecbm_stream_ecp_chtoid(ch);
    for(i_u16=0;i_u16<(u16)(es_ecp_data_len_gu8a[index_u8]);i_u16++){
        res1_u8=es_ecp_read(ch,es_ecp_addr16_gu16a[index_u8]+i_u16,&temp_u8,1);  //去读取寄存器。
        if(cmd==ES_ECP_CMD_SET_BIT){
            temp_u8|=es_ecp_data_buf_gu8a[index_u8][i_u16];   //或就是置位。
        }
        if(cmd==ES_ECP_CMD_RESET_BIT){
            temp_u8&=es_ecp_data_buf_gu8a[index_u8][i_u16];   //与就是复位。
        }
        res2_u8=es_ecp_write(ch,es_ecp_addr16_gu16a[index_u8]+i_u16,&temp_u8,1); //去写数据。
        if((res1_u8+res2_u8)){  //两次结果里看看有没有出错。
            break;              //出错就立即退出。
        }
    }
    if((es_ecp_target_id_gu8a[index_u8])||(es_ecp_source_id_gu8a[index_u8]==255)){ //如果不是广播，或者是电脑的广播。
        if(res1_u8){                                        //如果读取是有错的，
            es_ecp_data_buf_gu8a[index_u8][0]=res1_u8;
            es_ecp_reply(ch,1,ES_ECP_CMD_ERROR_OPERATE);    //在返回的时候需要标注操作错误。
        }else{                                              //否则的话，
            if(res2_u8){                                    //看看是不是写入错了。
                es_ecp_data_buf_gu8a[index_u8][0]=res2_u8;
                es_ecp_reply(ch,1,ES_ECP_CMD_ERROR_OPERATE);//在返回的时候需要标注操作错误。
            }else{
                es_ecp_reply(ch,1,ES_ECP_CMD_SET_BIT_REPLY);//就是标注置位回复。
            }
        }
    }
}
/*-------------------------------------------------------
ECP主机写函数。
-------------------------------------------------------*/
#if (ES_ECP_MASTER_EN)
    void es_ecp_master_write(u8 ch,u8 id,u16 addr,u8 * buf,u8 len){
        u8 count_u8;
        u16 crc_u16;
        crc_u16=es_send_whit_crc(ch,0xFFFF ,0xEC);     //帧头。
        crc_u16=es_send_whit_crc(ch,crc_u16, (len));   //长度。
        crc_u16=es_send_whit_crc(ch,crc_u16,~(len));   //长度反码。
        crc_u16=es_send_whit_crc(ch,crc_u16,id);
        crc_u16=es_send_whit_crc(ch,crc_u16,es_ecp_get_id(ch)); //带上本机的ID。
        crc_u16=es_send_whit_crc(ch,crc_u16,ES_ECP_CMD_WRITE);
        crc_u16=es_send_whit_crc(ch,crc_u16,0x00);     //地址高位。
        crc_u16=es_send_whit_crc(ch,crc_u16,0x00);     //地址低位。
        crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(addr>>8));//地址高位。
        crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(addr   ));//地址低位。
        for(count_u8=0;count_u8<len;count_u8++){
            crc_u16=es_send_whit_crc(ch,crc_u16,buf[count_u8]);//发送数据。
        }
        uart_char(ch,(u8)(crc_u16>>8)); 
        uart_char(ch,(u8)(crc_u16));
        uart_char(ch,0xBE);  //帧尾。
    }
#endif
/*-------------------------------------------------------
ECP主机读函数。
-------------------------------------------------------*/
#if (ES_ECP_MASTER_EN)
    void es_ecp_master_read(u8 ch,u8 id,u16 addr,u8 len){
        u16 crc_u16;
        crc_u16=es_send_whit_crc(ch,crc_u16,0xEC);  //帧头。
        crc_u16=es_send_whit_crc(ch,crc_u16,0x01);  //长度。
        crc_u16=es_send_whit_crc(ch,crc_u16,0xFE);  //长度反码。
        crc_u16=es_send_whit_crc(ch,crc_u16,id);    //对方ID。
        crc_u16=es_send_whit_crc(ch,crc_u16,es_ecp_get_id(ch)); //本机的ID。
        crc_u16=es_send_whit_crc(ch,crc_u16,ES_ECP_CMD_READ);//指令。
        crc_u16=es_send_whit_crc(ch,crc_u16,0x00);          //32地址高位。
        crc_u16=es_send_whit_crc(ch,crc_u16,0x00);          //32地址低位。
        crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(addr>>8)); //16地址高位。
        crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(addr   )); //16地址低位。
        crc_u16=es_send_whit_crc(ch,crc_u16,len);           //发送数据。
        uart_char(ch,(u8)(crc_u16>>8));
        uart_char(ch,(u8)(crc_u16));
        uart_char(ch,0xBE);  //帧尾。
    }
#endif
/*-------------------------------------------------------
ECP解析执行函数。
-------------------------------------------------------*/
void es_ecp_exe(u8 ch,u8 dat){
    u8 index_u8;
    index_u8=ecbm_stream_ecp_chtoid(ch);
    switch(es_ecp_status_gu8a[index_u8]){
        case ES_ECP_READY:{                                         //准备状态。
            if(dat==0xEC){                                          //读取到帧头的时候，
                es_ecp_status_gu8a[index_u8]=ES_ECP_GET_DATA_LEN;   //去读取数据帧长度。
                es_ecp_crc_gu16a[index_u8]=es_crc16(0xffff,0xEC);   //重置CRC，计算帧头的CRC。
            }
        }break;
        case ES_ECP_GET_DATA_LEN:{                                  //读取数据帧长度状态。
            es_ecp_data_len_gu8a[index_u8]=dat;                     //读取数据帧长度。
            es_ecp_status_gu8a[index_u8]=ES_ECP_CHECK_DATA_LEN;     //去确认数据帧长度。            
            es_ecp_crc_gu16a[index_u8]=es_crc16(es_ecp_crc_gu16a[index_u8],dat);//计算数据帧长度的CRC。
        }break;
        case ES_ECP_CHECK_DATA_LEN:{                        //确认数据帧长度状态。
            if(es_ecp_data_len_gu8a[index_u8]==(~dat)){                    //放反码的用途之一就是可以用来加强识别帧头。
                es_ecp_status_gu8a[index_u8]=ES_ECP_GET_TARGET_ID;         //确认正确之后，去获取目标ID。
                es_ecp_crc_gu16a[index_u8]=es_crc16(es_ecp_crc_gu16a[index_u8],dat);    //计算数据帧长度反码的CRC。
            }else{                                                      //如果不是长度的反码，说明这不是一个合法的帧头。
                if(es_ecp_data_len_gu8a==0xEC){                         //回溯一下，是不是一个多余0xEC干扰了。
                    es_ecp_status_gu8a[index_u8]=ES_ECP_CHECK_DATA_LEN; //是的话，本字节就应该是数据帧长度了，那么下一步就是到确认数据帧长度状态。
                    es_ecp_data_len_gu8a[index_u8]=dat;                 //把数据帧长度存好。
                    es_ecp_crc_gu16a[index_u8]=es_crc16(0xffff,0xEC);   //重置CRC，计算帧头的CRC。
                    es_ecp_crc_gu16a[index_u8]=es_crc16(es_ecp_crc_gu16a[index_u8],dat);//计算数据帧长度的CRC。
                }else{                                          //不是的话，那就再看看是不是这几步判断的时候来了0xEC信号。
                    if(dat==0xEC){                              //最后一次判断帧头了。
                        es_ecp_status_gu8a[index_u8]=ES_ECP_GET_DATA_LEN; //是的话，需要重新读取一遍数据帧长度。
                        es_ecp_crc_gu16a[index_u8]=es_crc16(0xffff,0xEC); //重置CRC，计算帧头的CRC。
                    }else{                                          //到这里还不是的话，说明接收到的完全是干扰。
                        es_ecp_status_gu8a[index_u8]=ES_ECP_READY;  //回到准备状态。
                    }//注意事项：
                }   //之所以在这里要判断那么多，是因为在传输过程中普通数据里也会出现0xEC的，就是说别一遇到0xEC就认为是帧头，要连着长度和长度反码综合判断。
            }       //虽然钻牛角尖而言，普通数据出现合法帧头（0xEC，长度，长度反码）的概率也不是0，但判断3个字节误判的概率是远远低于只判断1个字节的。
        }break;
        case ES_ECP_GET_TARGET_ID:{                             //读取目标ID状态。
            es_ecp_target_id_gu8a[index_u8]=dat;               //读取目标ID。
            es_ecp_status_gu8a[index_u8]=ES_ECP_GET_SOURCE_ID;  //去读取发送方ID。
            es_ecp_crc_gu16a[index_u8]=es_crc16(es_ecp_crc_gu16a[index_u8],dat);//计算目标ID的CRC。
        }break;
        case ES_ECP_GET_SOURCE_ID:{                 //读取发送方ID状态。
            es_ecp_source_id_gu8a[index_u8]=dat;                   //读取发送方ID。
            es_ecp_status_gu8a[index_u8]=ES_ECP_GET_OPERATION;     //去读取操作码。
            es_ecp_crc_gu16a[index_u8]=es_crc16(es_ecp_crc_gu16a[index_u8],dat);//计算发送方ID的CRC。
        }break;
        case ES_ECP_GET_OPERATION:{                 //读取操作码状态。
            es_ecp_operation_gu8a[index_u8]=dat;                   //保存操作码。
            es_ecp_status_gu8a[index_u8]=ES_ECP_GET_ADDR_31_24;    //去读取地址。
            es_ecp_crc_gu16a[index_u8]=es_crc16(es_ecp_crc_gu16a[index_u8],dat);//计算操作码的CRC。
        }break;
        case ES_ECP_GET_ADDR_31_24:{                //读取地址31~24位状态。
            es_ecp_addr16_ex_gu16a[index_u8]=(u16)(dat);        //保存地址高位。
            es_ecp_status_gu8a[index_u8]=ES_ECP_GET_ADDR_23_16; //这个地址是给32位单片机的预留，51单片机有另外的含义。
            es_ecp_crc_gu16a[index_u8]=es_crc16(es_ecp_crc_gu16a[index_u8],0x00);//预留的也要计算0x00的CRC。
        }break;
        case ES_ECP_GET_ADDR_23_16:{                //读取地址23~16位状态。
            es_ecp_addr16_ex_gu16a[index_u8]<<=8;               //把上一次的地址，
            es_ecp_addr16_ex_gu16a[index_u8]+=(u16)(dat);       //和这一次的地址合并在一起。
            es_ecp_status_gu8a[index_u8]=ES_ECP_GET_ADDR_15_8;  //这个地址是给32位单片机的预留，51单片机有另外的含义。
            es_ecp_crc_gu16a[index_u8]=es_crc16(es_ecp_crc_gu16a[index_u8],0x00);//预留的也要计算0x00的CRC。
        }break;
        case ES_ECP_GET_ADDR_15_8:{                 //读取地址15~8位状态。
            es_ecp_addr16_gu16a[index_u8]=(u16)(dat);           //保存地址高位。
            es_ecp_status_gu8a[index_u8]=ES_ECP_GET_ADDR_7_0;   //去读取地址低位。
            es_ecp_crc_gu16a[index_u8]=es_crc16(es_ecp_crc_gu16a[index_u8],dat);//计算地址高位的CRC。
        }break;
        case ES_ECP_GET_ADDR_7_0:{                  //读取地址7~0位状态。
            es_ecp_addr16_gu16a[index_u8]<<=8;                  //把上一次的地址，
            es_ecp_addr16_gu16a[index_u8]+=(u16)(dat);          //和这一次的地址合并在一起。
            if(es_ecp_data_len_gu8a[index_u8]){                 //如果数据长度存在，
                es_ecp_status_gu8a[index_u8]=ES_ECP_GET_DATA;   //就到读取数据状态。
                es_ecp_count_gu8a[index_u8]=0;                  //清零数据计数变量。 
            }else{                                              //数据长度为0的话，
                es_ecp_status_gu8a[index_u8]=ES_ECP_GET_CRC_H;  //就去读取CRC。
            }
            es_ecp_crc_gu16a[index_u8]=es_crc16(es_ecp_crc_gu16a[index_u8],dat);//计算地址低位的CRC。
        }break;
        case ES_ECP_GET_DATA:{                      //读取参数、数据状态。
            es_ecp_data_buf_gu8a[index_u8][es_ecp_count_gu8a[index_u8]++]=dat;  //将参数、数据存入缓存，然后计数+1。
            if(es_ecp_count_gu8a[index_u8]>=es_ecp_data_len_gu8a[index_u8]){    //当计数达到目标时，
                es_ecp_status_gu8a[index_u8]=ES_ECP_GET_CRC_H;                  //就去读取CRC。
            }
            es_ecp_crc_gu16a[index_u8]=es_crc16(es_ecp_crc_gu16a[index_u8],dat);//计算数据的CRC。
        }break;
        case ES_ECP_GET_CRC_H:{                 //读取CRC高位状态。
            es_ecp_crc_buf_gu16a[index_u8]=(u16)(dat);      //组装CRC。
            es_ecp_status_gu8a[index_u8]=ES_ECP_GET_CRC_L;  //到下一步。
        }break;
        case ES_ECP_GET_CRC_L:{                 //读取CRC低位状态。
            es_ecp_crc_buf_gu16a[index_u8]<<=8;         //组装CRC。
            es_ecp_crc_buf_gu16a[index_u8]+=(u16)(dat);
            es_ecp_status_gu8a[index_u8]=ES_ECP_END;    //到判断帧尾阶段了。
        }break;
        case ES_ECP_END:{                       //判断帧尾状态。
            es_ecp_status_gu8a[index_u8]=ES_ECP_READY;         //不管是不是帧尾，都可以回到准备状态了。
            if((dat==0xBE)&&(es_ecp_crc_buf_gu16a[index_u8]==es_ecp_crc_gu16a[index_u8])){//但是检测到合法的CRC和帧尾时才能执行帧内动作。
                if((es_ecp_target_id_gu8a[index_u8]==es_ecp_get_id(ch))||(es_ecp_target_id_gu8a[index_u8]==0)){//确认本帧数据是发往本机的，亦或者是广播。
                    switch(es_ecp_operation_gu8a[index_u8]){//根据操作码来执行相应动作。
                        case ES_ECP_CMD_TRIG://触发。
                            es_ecp_cmd00(ch);
                        break;
                        case ES_ECP_CMD_TRIG_REPLY://触发回复。
                        break;

                        case ES_ECP_CMD_READ://读取。
                            es_ecp_cmd02(ch);
                        break;
                        case ES_ECP_CMD_READ_REPLY://读取回复。
                            #if (ES_ECP_MASTER_EN)
                            es_ecp_read_callback(ch,es_ecp_addr16_gu16a[index_u8],es_ecp_data_buf_gu8a[index_u8],es_ecp_data_len_gu8a[index_u8]);
                            #endif                    
                        break;

                        
                        case ES_ECP_CMD_WRITE://写入。
                            es_ecp_cmd04(ch);
                        break;
                        case ES_ECP_CMD_WRITE_REPLY://写入回复。
                        break;

                        case ES_ECP_CMD_SET_BIT:
                        case ES_ECP_CMD_RESET_BIT:
                            es_ecp_cmd0608(ch,es_ecp_operation_gu8a[index_u8]);
                        break;    
                    }
                }
            }
        }break;
    }
}
#endif  //和最上面的#ifndef配合成一个程序段。
        //以一个空行为结尾。