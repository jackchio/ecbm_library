#include "ecbm_core.h"  //ͳһ���غ���ͷ�ļ�
#if (ECBM_10MS_EN)&&(ECBM_STREAM_LIB_EN)&&(ECBM_STREAM_ECP_CH_COUNT)    //��鱾����û�б�ʹ��
/*--------------------------------------��������-----------------------------------*/
u8  es_ecp_status_gu8a   [ECBM_STREAM_ECP_CH_COUNT]; //״̬��������
u8  es_ecp_data_len_gu8a [ECBM_STREAM_ECP_CH_COUNT]; //���ڴ�Ų��������ݵĳ��ȡ�
u8  es_ecp_count_gu8a    [ECBM_STREAM_ECP_CH_COUNT]; //����ͳ��ʵ�ʽ��յĲ��������ݳ��ȡ�
u8  es_ecp_source_id_gu8a[ECBM_STREAM_ECP_CH_COUNT]; //ԴͷID�������֡�����ID������������
u8  es_ecp_target_id_gu8a[ECBM_STREAM_ECP_CH_COUNT]; //Ŀ��ID�������֡Ӧ�������ID���������ա�
u8  es_ecp_operation_gu8a[ECBM_STREAM_ECP_CH_COUNT]; //�����뻺�档
u16 es_ecp_addr16_ex_gu16a[ECBM_STREAM_ECP_CH_COUNT]; //16λ��չ��ַ���档
u16 es_ecp_addr16_gu16a   [ECBM_STREAM_ECP_CH_COUNT]; //16λ��ַ���档
u16 es_ecp_crc_gu16a      [ECBM_STREAM_ECP_CH_COUNT]; //���ڼ���������ݵ�CRC��
u16 es_ecp_crc_buf_gu16a  [ECBM_STREAM_ECP_CH_COUNT]; //���ڴ������֡���CRC��
u8  es_ecp_data_buf_gu8a[ECBM_STREAM_ECP_CH_COUNT][ES_ECP_DATA_BUF_MAX];//���ڶ�д�����Ļ��档
/*--------------------------------------������-----------------------------------*/
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
ecp���ú�����
-------------------------------------------------------*/
void es_ecp_reset(u8 ch){
    u8 id_u8;
    id_u8=ecbm_stream_ecp_chtoid(ch);
    es_ecp_status_gu8a    [id_u8]=ES_ECP_READY; //״̬����λ��
    es_ecp_data_len_gu8a  [id_u8]=0; //������������ݵĳ��ȡ�
    es_ecp_count_gu8a     [id_u8]=0; //���ͳ��ʵ�ʽ��յĲ��������ݳ��ȡ�
    es_ecp_source_id_gu8a [id_u8]=0; //���ԴͷID��
    es_ecp_target_id_gu8a [id_u8]=0; //���Ŀ��ID��
    es_ecp_operation_gu8a [id_u8]=0; //��������뻺�档
    es_ecp_addr16_ex_gu16a[id_u8]=0; //���16λ��չ��ַ���档
    es_ecp_addr16_gu16a   [id_u8]=0; //���16λ��ַ���档
    es_ecp_crc_gu16a      [id_u8]=0; //������ڼ���������ݵ�CRC��
    es_ecp_crc_buf_gu16a  [id_u8]=0; //������ڴ������֡���CRC��
}
/*-------------------------------------------------------
ͨ�ûظ�������
-------------------------------------------------------*/
void es_ecp_reply(u8 ch,u8 len,u8 cmd){
    u16 crc_u16,i_u16;
    u8 index_u8;
    index_u8=ecbm_stream_ecp_chtoid(ch);
    crc_u16=es_send_whit_crc(ch,0xffff,0xEC);      //֡ͷ��
    crc_u16=es_send_whit_crc(ch,crc_u16, (len));    //���ȡ�
    crc_u16=es_send_whit_crc(ch,crc_u16,~(len));    //���ȷ��롣
    crc_u16=es_send_whit_crc(ch,crc_u16,es_ecp_source_id_gu8a[index_u8]);   //˭�������ģ�������˭��
    crc_u16=es_send_whit_crc(ch,crc_u16,es_ecp_get_id(ch));    //���ϱ�����ID��
    crc_u16=es_send_whit_crc(ch,crc_u16,cmd);                  //��ִ��
    crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(es_ecp_addr16_ex_gu16a[index_u8]>>8));  //��ַ��λ��
    crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(es_ecp_addr16_ex_gu16a[index_u8]   ));  //��ַ��λ��
    crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(es_ecp_addr16_gu16a[index_u8]>>8));     //��ַ��λ��
    crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(es_ecp_addr16_gu16a[index_u8]   ));     //��ַ��λ��
    for(i_u16=0;i_u16<(u16)(len);i_u16++){
        crc_u16=es_send_whit_crc(ch,crc_u16,es_ecp_data_buf_gu8a[index_u8][i_u16]);
    }
    uart_char(ch,(u8)(crc_u16>>8)); 
    uart_char(ch,(u8)(crc_u16));
    uart_char(ch,0xBE);                       //֡β��
}
/*-------------------------------------------------------
00ָ�������
-------------------------------------------------------*/
void es_ecp_cmd00(u8 ch){
    u8 res_u8,index_u8;
    index_u8=ecbm_stream_ecp_chtoid(ch);
    res_u8=es_ecp_trig(ch,es_ecp_addr16_gu16a[index_u8]);  //ִ��ָ�����ĳЩ������
    if((es_ecp_target_id_gu8a[index_u8])||(es_ecp_source_id_gu8a[index_u8]==255)){ //������ǹ㲥�������ǵ��ԵĹ㲥��
        es_ecp_data_buf_gu8a[index_u8][0]=res_u8;       //��ִ�н���ŵ����档
        if(res_u8){                                     //������д�ģ�
            es_ecp_reply(ch,1,ES_ECP_CMD_ERROR_OPERATE);//�ڷ��ص�ʱ����Ҫ��ע��������
        }else{                                          //����Ļ���
            es_ecp_reply(ch,1,ES_ECP_CMD_TRIG_REPLY);   //���Ǳ�ע�����ظ���
        }
    }
}
/*-------------------------------------------------------
02ָ�������
-------------------------------------------------------*/
void es_ecp_cmd02(u8 ch){
    u8 arg_len_u8,res_u8,index_u8;
    index_u8=ecbm_stream_ecp_chtoid(ch);
    arg_len_u8=es_ecp_data_buf_gu8a[index_u8][0];               //�Ȱѳ���ȡ������
    res_u8=es_ecp_read(ch,es_ecp_addr16_gu16a[index_u8],es_ecp_data_buf_gu8a[index_u8],arg_len_u8);//ȥ��ȡ�Ĵ�����
    if((es_ecp_target_id_gu8a[index_u8])||(es_ecp_source_id_gu8a[index_u8]==255)){             //������ǹ㲥�������ǵ��ԵĹ㲥��
        if(res_u8){                                             //������д�ģ�
            es_ecp_data_buf_gu8a[index_u8][0]=res_u8;           //��ִ�н���ŵ����档
            es_ecp_reply(ch,1,ES_ECP_CMD_ERROR_OPERATE);        //�ڷ��ص�ʱ����Ҫ��ע��������
        }else{                                                  //����Ļ���
            es_ecp_reply(ch,arg_len_u8,ES_ECP_CMD_READ_REPLY);  //���Ǳ�ע��ȡ�ظ���
        }
    }
}
/*-------------------------------------------------------
04ָ�������
-------------------------------------------------------*/
void es_ecp_cmd04(u8 ch){
    u8 res_u8,index_u8;
    index_u8=ecbm_stream_ecp_chtoid(ch);
    res_u8=es_ecp_write(ch,es_ecp_addr16_gu16a[index_u8],es_ecp_data_buf_gu8a[index_u8],es_ecp_data_len_gu8a[index_u8]);//ȥд���ݡ�
    if((es_ecp_target_id_gu8a[index_u8])||(es_ecp_source_id_gu8a[index_u8]==255)){        //������ǹ㲥�������ǵ��ԵĹ㲥��
        es_ecp_data_buf_gu8a[index_u8][0]=res_u8;       //��ִ�н���ŵ����档
        if(res_u8){                                     //������д�ģ�
            es_ecp_reply(ch,1,ES_ECP_CMD_ERROR_OPERATE);//�ڷ��ص�ʱ����Ҫ��ע��������
        }else{                                          //����Ļ���
            es_ecp_reply(ch,1,ES_ECP_CMD_WRITE_REPLY);  //���Ǳ�עд��ظ���
        }
    }
}
/*-------------------------------------------------------
06��08ָ�������
-------------------------------------------------------*/
void es_ecp_cmd0608(u8 ch,u8 cmd){
    u8 res1_u8,res2_u8,temp_u8;
    u16 i_u16;
    u8 index_u8;
    index_u8=ecbm_stream_ecp_chtoid(ch);
    for(i_u16=0;i_u16<(u16)(es_ecp_data_len_gu8a[index_u8]);i_u16++){
        res1_u8=es_ecp_read(ch,es_ecp_addr16_gu16a[index_u8]+i_u16,&temp_u8,1);  //ȥ��ȡ�Ĵ�����
        if(cmd==ES_ECP_CMD_SET_BIT){
            temp_u8|=es_ecp_data_buf_gu8a[index_u8][i_u16];   //�������λ��
        }
        if(cmd==ES_ECP_CMD_RESET_BIT){
            temp_u8&=es_ecp_data_buf_gu8a[index_u8][i_u16];   //����Ǹ�λ��
        }
        res2_u8=es_ecp_write(ch,es_ecp_addr16_gu16a[index_u8]+i_u16,&temp_u8,1); //ȥд���ݡ�
        if((res1_u8+res2_u8)){  //���ν���￴����û�г���
            break;              //����������˳���
        }
    }
    if((es_ecp_target_id_gu8a[index_u8])||(es_ecp_source_id_gu8a[index_u8]==255)){ //������ǹ㲥�������ǵ��ԵĹ㲥��
        if(res1_u8){                                        //�����ȡ���д�ģ�
            es_ecp_data_buf_gu8a[index_u8][0]=res1_u8;
            es_ecp_reply(ch,1,ES_ECP_CMD_ERROR_OPERATE);    //�ڷ��ص�ʱ����Ҫ��ע��������
        }else{                                              //����Ļ���
            if(res2_u8){                                    //�����ǲ���д����ˡ�
                es_ecp_data_buf_gu8a[index_u8][0]=res2_u8;
                es_ecp_reply(ch,1,ES_ECP_CMD_ERROR_OPERATE);//�ڷ��ص�ʱ����Ҫ��ע��������
            }else{
                es_ecp_reply(ch,1,ES_ECP_CMD_SET_BIT_REPLY);//���Ǳ�ע��λ�ظ���
            }
        }
    }
}
/*-------------------------------------------------------
ECP����д������
-------------------------------------------------------*/
#if (ES_ECP_MASTER_EN)
    void es_ecp_master_write(u8 ch,u8 id,u16 addr,u8 * buf,u8 len){
        u8 count_u8;
        u16 crc_u16;
        crc_u16=es_send_whit_crc(ch,0xFFFF ,0xEC);     //֡ͷ��
        crc_u16=es_send_whit_crc(ch,crc_u16, (len));   //���ȡ�
        crc_u16=es_send_whit_crc(ch,crc_u16,~(len));   //���ȷ��롣
        crc_u16=es_send_whit_crc(ch,crc_u16,id);
        crc_u16=es_send_whit_crc(ch,crc_u16,es_ecp_get_id(ch)); //���ϱ�����ID��
        crc_u16=es_send_whit_crc(ch,crc_u16,ES_ECP_CMD_WRITE);
        crc_u16=es_send_whit_crc(ch,crc_u16,0x00);     //��ַ��λ��
        crc_u16=es_send_whit_crc(ch,crc_u16,0x00);     //��ַ��λ��
        crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(addr>>8));//��ַ��λ��
        crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(addr   ));//��ַ��λ��
        for(count_u8=0;count_u8<len;count_u8++){
            crc_u16=es_send_whit_crc(ch,crc_u16,buf[count_u8]);//�������ݡ�
        }
        uart_char(ch,(u8)(crc_u16>>8)); 
        uart_char(ch,(u8)(crc_u16));
        uart_char(ch,0xBE);  //֡β��
    }
#endif
/*-------------------------------------------------------
ECP������������
-------------------------------------------------------*/
#if (ES_ECP_MASTER_EN)
    void es_ecp_master_read(u8 ch,u8 id,u16 addr,u8 len){
        u16 crc_u16;
        crc_u16=es_send_whit_crc(ch,crc_u16,0xEC);  //֡ͷ��
        crc_u16=es_send_whit_crc(ch,crc_u16,0x01);  //���ȡ�
        crc_u16=es_send_whit_crc(ch,crc_u16,0xFE);  //���ȷ��롣
        crc_u16=es_send_whit_crc(ch,crc_u16,id);    //�Է�ID��
        crc_u16=es_send_whit_crc(ch,crc_u16,es_ecp_get_id(ch)); //������ID��
        crc_u16=es_send_whit_crc(ch,crc_u16,ES_ECP_CMD_READ);//ָ�
        crc_u16=es_send_whit_crc(ch,crc_u16,0x00);          //32��ַ��λ��
        crc_u16=es_send_whit_crc(ch,crc_u16,0x00);          //32��ַ��λ��
        crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(addr>>8)); //16��ַ��λ��
        crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(addr   )); //16��ַ��λ��
        crc_u16=es_send_whit_crc(ch,crc_u16,len);           //�������ݡ�
        uart_char(ch,(u8)(crc_u16>>8));
        uart_char(ch,(u8)(crc_u16));
        uart_char(ch,0xBE);  //֡β��
    }
#endif
/*-------------------------------------------------------
ECP����ִ�к�����
-------------------------------------------------------*/
void es_ecp_exe(u8 ch,u8 dat){
    u8 index_u8;
    index_u8=ecbm_stream_ecp_chtoid(ch);
    switch(es_ecp_status_gu8a[index_u8]){
        case ES_ECP_READY:{                                         //׼��״̬��
            if(dat==0xEC){                                          //��ȡ��֡ͷ��ʱ��
                es_ecp_status_gu8a[index_u8]=ES_ECP_GET_DATA_LEN;   //ȥ��ȡ����֡���ȡ�
                es_ecp_crc_gu16a[index_u8]=es_crc16(0xffff,0xEC);   //����CRC������֡ͷ��CRC��
            }
        }break;
        case ES_ECP_GET_DATA_LEN:{                                  //��ȡ����֡����״̬��
            es_ecp_data_len_gu8a[index_u8]=dat;                     //��ȡ����֡���ȡ�
            es_ecp_status_gu8a[index_u8]=ES_ECP_CHECK_DATA_LEN;     //ȥȷ������֡���ȡ�            
            es_ecp_crc_gu16a[index_u8]=es_crc16(es_ecp_crc_gu16a[index_u8],dat);//��������֡���ȵ�CRC��
        }break;
        case ES_ECP_CHECK_DATA_LEN:{                        //ȷ������֡����״̬��
            if(es_ecp_data_len_gu8a[index_u8]==(~dat)){                    //�ŷ������;֮һ���ǿ���������ǿʶ��֡ͷ��
                es_ecp_status_gu8a[index_u8]=ES_ECP_GET_TARGET_ID;         //ȷ����ȷ֮��ȥ��ȡĿ��ID��
                es_ecp_crc_gu16a[index_u8]=es_crc16(es_ecp_crc_gu16a[index_u8],dat);    //��������֡���ȷ����CRC��
            }else{                                                      //������ǳ��ȵķ��룬˵���ⲻ��һ���Ϸ���֡ͷ��
                if(es_ecp_data_len_gu8a==0xEC){                         //����һ�£��ǲ���һ������0xEC�����ˡ�
                    es_ecp_status_gu8a[index_u8]=ES_ECP_CHECK_DATA_LEN; //�ǵĻ������ֽھ�Ӧ��������֡�����ˣ���ô��һ�����ǵ�ȷ������֡����״̬��
                    es_ecp_data_len_gu8a[index_u8]=dat;                 //������֡���ȴ�á�
                    es_ecp_crc_gu16a[index_u8]=es_crc16(0xffff,0xEC);   //����CRC������֡ͷ��CRC��
                    es_ecp_crc_gu16a[index_u8]=es_crc16(es_ecp_crc_gu16a[index_u8],dat);//��������֡���ȵ�CRC��
                }else{                                          //���ǵĻ����Ǿ��ٿ����ǲ����⼸���жϵ�ʱ������0xEC�źš�
                    if(dat==0xEC){                              //���һ���ж�֡ͷ�ˡ�
                        es_ecp_status_gu8a[index_u8]=ES_ECP_GET_DATA_LEN; //�ǵĻ�����Ҫ���¶�ȡһ������֡���ȡ�
                        es_ecp_crc_gu16a[index_u8]=es_crc16(0xffff,0xEC); //����CRC������֡ͷ��CRC��
                    }else{                                          //�����ﻹ���ǵĻ���˵�����յ�����ȫ�Ǹ��š�
                        es_ecp_status_gu8a[index_u8]=ES_ECP_READY;  //�ص�׼��״̬��
                    }//ע�����
                }   //֮����������Ҫ�ж���ô�࣬����Ϊ�ڴ����������ͨ������Ҳ�����0xEC�ģ�����˵��һ����0xEC����Ϊ��֡ͷ��Ҫ���ų��Ⱥͳ��ȷ����ۺ��жϡ�
            }       //��Ȼ��ţ�Ǽ���ԣ���ͨ���ݳ��ֺϷ�֡ͷ��0xEC�����ȣ����ȷ��룩�ĸ���Ҳ����0�����ж�3���ֽ����еĸ�����ԶԶ����ֻ�ж�1���ֽڵġ�
        }break;
        case ES_ECP_GET_TARGET_ID:{                             //��ȡĿ��ID״̬��
            es_ecp_target_id_gu8a[index_u8]=dat;               //��ȡĿ��ID��
            es_ecp_status_gu8a[index_u8]=ES_ECP_GET_SOURCE_ID;  //ȥ��ȡ���ͷ�ID��
            es_ecp_crc_gu16a[index_u8]=es_crc16(es_ecp_crc_gu16a[index_u8],dat);//����Ŀ��ID��CRC��
        }break;
        case ES_ECP_GET_SOURCE_ID:{                 //��ȡ���ͷ�ID״̬��
            es_ecp_source_id_gu8a[index_u8]=dat;                   //��ȡ���ͷ�ID��
            es_ecp_status_gu8a[index_u8]=ES_ECP_GET_OPERATION;     //ȥ��ȡ�����롣
            es_ecp_crc_gu16a[index_u8]=es_crc16(es_ecp_crc_gu16a[index_u8],dat);//���㷢�ͷ�ID��CRC��
        }break;
        case ES_ECP_GET_OPERATION:{                 //��ȡ������״̬��
            es_ecp_operation_gu8a[index_u8]=dat;                   //��������롣
            es_ecp_status_gu8a[index_u8]=ES_ECP_GET_ADDR_31_24;    //ȥ��ȡ��ַ��
            es_ecp_crc_gu16a[index_u8]=es_crc16(es_ecp_crc_gu16a[index_u8],dat);//����������CRC��
        }break;
        case ES_ECP_GET_ADDR_31_24:{                //��ȡ��ַ31~24λ״̬��
            es_ecp_addr16_ex_gu16a[index_u8]=(u16)(dat);        //�����ַ��λ��
            es_ecp_status_gu8a[index_u8]=ES_ECP_GET_ADDR_23_16; //�����ַ�Ǹ�32λ��Ƭ����Ԥ����51��Ƭ��������ĺ��塣
            es_ecp_crc_gu16a[index_u8]=es_crc16(es_ecp_crc_gu16a[index_u8],0x00);//Ԥ����ҲҪ����0x00��CRC��
        }break;
        case ES_ECP_GET_ADDR_23_16:{                //��ȡ��ַ23~16λ״̬��
            es_ecp_addr16_ex_gu16a[index_u8]<<=8;               //����һ�εĵ�ַ��
            es_ecp_addr16_ex_gu16a[index_u8]+=(u16)(dat);       //����һ�εĵ�ַ�ϲ���һ��
            es_ecp_status_gu8a[index_u8]=ES_ECP_GET_ADDR_15_8;  //�����ַ�Ǹ�32λ��Ƭ����Ԥ����51��Ƭ��������ĺ��塣
            es_ecp_crc_gu16a[index_u8]=es_crc16(es_ecp_crc_gu16a[index_u8],0x00);//Ԥ����ҲҪ����0x00��CRC��
        }break;
        case ES_ECP_GET_ADDR_15_8:{                 //��ȡ��ַ15~8λ״̬��
            es_ecp_addr16_gu16a[index_u8]=(u16)(dat);           //�����ַ��λ��
            es_ecp_status_gu8a[index_u8]=ES_ECP_GET_ADDR_7_0;   //ȥ��ȡ��ַ��λ��
            es_ecp_crc_gu16a[index_u8]=es_crc16(es_ecp_crc_gu16a[index_u8],dat);//�����ַ��λ��CRC��
        }break;
        case ES_ECP_GET_ADDR_7_0:{                  //��ȡ��ַ7~0λ״̬��
            es_ecp_addr16_gu16a[index_u8]<<=8;                  //����һ�εĵ�ַ��
            es_ecp_addr16_gu16a[index_u8]+=(u16)(dat);          //����һ�εĵ�ַ�ϲ���һ��
            if(es_ecp_data_len_gu8a[index_u8]){                 //������ݳ��ȴ��ڣ�
                es_ecp_status_gu8a[index_u8]=ES_ECP_GET_DATA;   //�͵���ȡ����״̬��
                es_ecp_count_gu8a[index_u8]=0;                  //�������ݼ��������� 
            }else{                                              //���ݳ���Ϊ0�Ļ���
                es_ecp_status_gu8a[index_u8]=ES_ECP_GET_CRC_H;  //��ȥ��ȡCRC��
            }
            es_ecp_crc_gu16a[index_u8]=es_crc16(es_ecp_crc_gu16a[index_u8],dat);//�����ַ��λ��CRC��
        }break;
        case ES_ECP_GET_DATA:{                      //��ȡ����������״̬��
            es_ecp_data_buf_gu8a[index_u8][es_ecp_count_gu8a[index_u8]++]=dat;  //�����������ݴ��뻺�棬Ȼ�����+1��
            if(es_ecp_count_gu8a[index_u8]>=es_ecp_data_len_gu8a[index_u8]){    //�������ﵽĿ��ʱ��
                es_ecp_status_gu8a[index_u8]=ES_ECP_GET_CRC_H;                  //��ȥ��ȡCRC��
            }
            es_ecp_crc_gu16a[index_u8]=es_crc16(es_ecp_crc_gu16a[index_u8],dat);//�������ݵ�CRC��
        }break;
        case ES_ECP_GET_CRC_H:{                 //��ȡCRC��λ״̬��
            es_ecp_crc_buf_gu16a[index_u8]=(u16)(dat);      //��װCRC��
            es_ecp_status_gu8a[index_u8]=ES_ECP_GET_CRC_L;  //����һ����
        }break;
        case ES_ECP_GET_CRC_L:{                 //��ȡCRC��λ״̬��
            es_ecp_crc_buf_gu16a[index_u8]<<=8;         //��װCRC��
            es_ecp_crc_buf_gu16a[index_u8]+=(u16)(dat);
            es_ecp_status_gu8a[index_u8]=ES_ECP_END;    //���ж�֡β�׶��ˡ�
        }break;
        case ES_ECP_END:{                       //�ж�֡β״̬��
            es_ecp_status_gu8a[index_u8]=ES_ECP_READY;         //�����ǲ���֡β�������Իص�׼��״̬�ˡ�
            if((dat==0xBE)&&(es_ecp_crc_buf_gu16a[index_u8]==es_ecp_crc_gu16a[index_u8])){//���Ǽ�⵽�Ϸ���CRC��֡βʱ����ִ��֡�ڶ�����
                if((es_ecp_target_id_gu8a[index_u8]==es_ecp_get_id(ch))||(es_ecp_target_id_gu8a[index_u8]==0)){//ȷ�ϱ�֡�����Ƿ��������ģ�������ǹ㲥��
                    switch(es_ecp_operation_gu8a[index_u8]){//���ݲ�������ִ����Ӧ������
                        case ES_ECP_CMD_TRIG://������
                            es_ecp_cmd00(ch);
                        break;
                        case ES_ECP_CMD_TRIG_REPLY://�����ظ���
                        break;

                        case ES_ECP_CMD_READ://��ȡ��
                            es_ecp_cmd02(ch);
                        break;
                        case ES_ECP_CMD_READ_REPLY://��ȡ�ظ���
                            #if (ES_ECP_MASTER_EN)
                            es_ecp_read_callback(ch,es_ecp_addr16_gu16a[index_u8],es_ecp_data_buf_gu8a[index_u8],es_ecp_data_len_gu8a[index_u8]);
                            #endif                    
                        break;

                        
                        case ES_ECP_CMD_WRITE://д�롣
                            es_ecp_cmd04(ch);
                        break;
                        case ES_ECP_CMD_WRITE_REPLY://д��ظ���
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
#endif  //���������#ifndef��ϳ�һ������Ρ�
        //��һ������Ϊ��β��