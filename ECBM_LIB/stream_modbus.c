#include "ecbm_core.h"  //ͳһ���غ���ͷ�ļ�
#if (ECBM_10MS_EN)&&(ECBM_STREAM_LIB_EN)&&(ECBM_STREAM_MODBUS_CH_COUNT)    //��鱾����û�б�ʹ��
/*--------------------------------------��������-----------------------------------*/
u8  es_modbus_rtu_mode_gu8a        [ECBM_STREAM_MODBUS_CH_COUNT]; //����ģʽ��
u8  es_modbus_rtu_send_id_gu8a     [ECBM_STREAM_MODBUS_CH_COUNT]; //���͵�ID��
u8  es_modbus_rtu_reply_count_gu8a [ECBM_STREAM_MODBUS_CH_COUNT]; //���ص�����������
u8  es_modbus_rtu_status_gu8a      [ECBM_STREAM_MODBUS_CH_COUNT]; //״̬��ʹ�õı�����
u8  es_modbus_rtu_broadcast_en_gu8a[ECBM_STREAM_MODBUS_CH_COUNT]; //�㲥ģʽ��
u8  es_modbus_rtu_fun_code_gu8a    [ECBM_STREAM_MODBUS_CH_COUNT]; //�����롣
u16 es_modbus_rtu_address_gu16a    [ECBM_STREAM_MODBUS_CH_COUNT]; //���ݵ�ַ��
u16 es_modbus_rtu_data_count_gu16a [ECBM_STREAM_MODBUS_CH_COUNT]; //����/������
u16 es_modbus_rtu_uart_crc_gu16a   [ECBM_STREAM_MODBUS_CH_COUNT]; //CRC���㻺�档
u16 es_modbus_rtu_crc_buf_gu16a    [ECBM_STREAM_MODBUS_CH_COUNT]; //CRC���档
u8  es_modbus_rtu_cmd_count_gu8a   [ECBM_STREAM_MODBUS_CH_COUNT]; //ָ��������
u8  es_modbus_rtu_count_gu8a       [ECBM_STREAM_MODBUS_CH_COUNT]; //ͨ�ü�����
#if ((ES_MODBUS_RTU_CMD10_EN)||(ES_MODBUS_RTU_MASTER_EN))
    u16 es_modbus_rtu_cmd_buf_gu16a[ECBM_STREAM_MODBUS_CH_COUNT][ES_MODBUS_RTU_BUF_SIZE];//ͨ�û��档
#endif
/*--------------------------------------������-----------------------------------*/
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
modbus���ú�����
-------------------------------------------------------*/
void es_modbus_rtu_reset(u8 ch){
    u8 id_u8;
    id_u8=ecbm_stream_modbus_chtoid(ch);
    es_modbus_rtu_mode_gu8a        [id_u8]=ES_MODBUS_RTU_MODE_SLAVE; //Ĭ�ϴӻ�ģʽ��
    es_modbus_rtu_send_id_gu8a     [id_u8]=0; //������͵�ID��
    es_modbus_rtu_reply_count_gu8a [id_u8]=0; //������ص�����������
    es_modbus_rtu_status_gu8a      [id_u8]=ES_MODBUS_RTU_READY; //��λ�ɵȴ�̬����
    es_modbus_rtu_broadcast_en_gu8a[id_u8]=0; //����㲥ģʽ��
    es_modbus_rtu_fun_code_gu8a    [id_u8]=0; //��������롣
    es_modbus_rtu_address_gu16a    [id_u8]=0; //������ݵ�ַ��
    es_modbus_rtu_data_count_gu16a [id_u8]=0; //�������/������
    es_modbus_rtu_uart_crc_gu16a   [id_u8]=0; //���CRC���㻺�档
    es_modbus_rtu_crc_buf_gu16a    [id_u8]=0; //���CRC���档
    es_modbus_rtu_cmd_count_gu8a   [id_u8]=0; //���ָ��������
    es_modbus_rtu_count_gu8a       [id_u8]=0; //���ͨ�ü�����
}
/*-------------------------------------------------------
modbus���ش����뺯����
-------------------------------------------------------*/
void es_modbus_rtu_err_num(u8 ch,u8 fun_num,u8 err_num){
    u8  id_u8;
    u16 crc_u16;
    if(es_modbus_rtu_broadcast_en_gu8a[ecbm_stream_modbus_chtoid(ch)]){  //ֻ�в��ǹ㲥֡��ʱ����ܻظ���
        id_u8=es_modbus_rtu_get_id(ch); //��ȡ����ID��
        crc_u16=es_send_whit_crc(ch,0xFFFF,id_u8);            //���͵�ַ��
        crc_u16=es_send_whit_crc(ch,crc_u16,0x80+fun_num);     //����0x80+������ظ���
        crc_u16=es_send_whit_crc(ch,crc_u16,err_num);          //�쳣�롣
        uart_char(ch,(u8)(crc_u16));    //����CRC��
        uart_char(ch,(u8)(crc_u16>>8));
    }
}
/*-------------------------------------------------------
1�Ź����봦������
-------------------------------------------------------*/
#if (ES_MODBUS_RTU_CMD01_EN)
    void es_modbus_rtu_cmd_0x01(u8 ch){
        u8 temp_u8,t1_u8,c1_u8,i_u8,j_u8,qw_u8,id_u8,index_u8;
        u16 crc_u16;
        index_u8=ecbm_stream_modbus_chtoid(ch);
        id_u8=es_modbus_rtu_get_id(ch);      //��ȡ����ID��
        if((es_modbus_rtu_data_count_gu16a[index_u8]>=1)&&(es_modbus_rtu_data_count_gu16a[index_u8]<=0x07D0)){          //��ȡ�ĸ���Ҫ��1�����ϣ��ҵ�ַ���ܴ���2000��
            if(((u32)(es_modbus_rtu_data_count_gu16a[index_u8])+(u32)(es_modbus_rtu_address_gu16a[index_u8]))<=65536UL){//�жϵ�ַ+������û�г��ޡ�
                if(es_modbus_rtu_broadcast_en_gu8a[index_u8]){              //����ǹ㲥֡����ô�㲻�ܻظ���
                    t1_u8=(u8)(es_modbus_rtu_data_count_gu16a[index_u8]/8); //ͳ��Ҫ��ȡ�������ܴչ����ٸ��ֽڡ�
                    if(es_modbus_rtu_data_count_gu16a[index_u8]%8)t1_u8++;  //ʣ�µĲ���8λ������ҲҪһ���ֽ������䡣
                    crc_u16=es_send_whit_crc(ch,0xFFFF,id_u8);              //���͵�ַ��
                    crc_u16=es_send_whit_crc(ch,crc_u16,0x01);              //���͹�����ظ���
                    crc_u16=es_send_whit_crc(ch,crc_u16,t1_u8);             //�������ݳ��ȡ�
                    for(i_u8=0;i_u8<t1_u8;i_u8++){  //����ʼλ�ÿ�ʼ��װ���ݡ�
                        temp_u8=0;                  //���������
                        if(es_modbus_rtu_data_count_gu16a[index_u8]>=8){    //���ʣ��Ҫ�������ݶ���8�����ء�
                            c1_u8=8;                //��ô����ѭ���ȶ�8�������ݡ�
                        }else{                      //����
                            c1_u8=(u8)(es_modbus_rtu_data_count_gu16a[index_u8]);  //���ж��ٶ����١�
                        }
                        for(j_u8=0;j_u8<c1_u8;j_u8++){      
                            es_modbus_cmd_read_bit(ch,es_modbus_rtu_address_gu16a[index_u8]++,&qw_u8);//����ַ�͵���ȡ�����У���ȡ��Ӧ�ı���ֵ��
                            if(qw_u8)temp_u8|=(1<<j_u8);        //��װ���ݡ�
                        }
                        crc_u16=es_send_whit_crc(ch,crc_u16,temp_u8);           //������װ�õ����ݡ�
                        es_modbus_rtu_data_count_gu16a[index_u8]-=(u16)c1_u8;   //����ʣ��Ҫ�������ݸ�����
                    }
                    uart_char(ch,(u8)(crc_u16));                //����CRC
                    uart_char(ch,(u8)(crc_u16>>8));
                }
            }else{                                              //�����ַ+��������65536��
                es_modbus_rtu_err_num(ch,0x01,0x02);//���ʹ�����02��
            }
        }else{                                              //�����������ͳ���2000�ˡ�
            es_modbus_rtu_err_num(ch,0x01,0x03);//���ʹ�����03��
        }
    }
#endif
/*-------------------------------------------------------
2�Ź����봦������
-------------------------------------------------------*/
#if (ES_MODBUS_RTU_CMD02_EN)
    void es_modbus_rtu_cmd_0x02(u8 ch){
        u8 temp_u8,t1_u8,c1_u8,i_u8,j_u8,qw_u8,id_u8,index_u8;
        u16 crc_u16;
        index_u8=ecbm_stream_modbus_chtoid(ch);
        id_u8=es_modbus_rtu_get_id(ch);      //��ȡ����ID��
        if((es_modbus_rtu_data_count_gu16a[index_u8]>=1)&&(es_modbus_rtu_data_count_gu16a[index_u8]<=0x07D0)){              //��ȡ�ĸ���Ҫ��1�����ϣ��ҵ�ַ���ܴ���2000��
            if(((u32)(es_modbus_rtu_data_count_gu16a[index_u8])+(u32)(es_modbus_rtu_address_gu16a[index_u8]))<=65536UL){    //�жϵ�ַ+������û�г��ޡ�
                    if(es_modbus_rtu_broadcast_en_gu8a[index_u8]){              //����ǹ㲥֡����ô�㲻�ܻظ���
                        t1_u8=(u8)(es_modbus_rtu_data_count_gu16a[index_u8]/8); //ͳ��Ҫ��ȡ�������ܴչ����ٸ��ֽڡ�
                        if(es_modbus_rtu_data_count_gu16a[index_u8]%8)t1_u8++;  //ʣ�µĲ���8λ������ҲҪһ���ֽ������䡣
                        crc_u16=es_send_whit_crc(ch,0xFFFF,id_u8);              //���͵�ַ��
                        crc_u16=es_send_whit_crc(ch,crc_u16,0x02);              //���͹�����ظ���
                        crc_u16=es_send_whit_crc(ch,crc_u16,t1_u8);             //�������ݳ��ȡ�
                        for(i_u8=0;i_u8<t1_u8;i_u8++){      //����ʼλ�ÿ�ʼ��װ���ݡ�
                            temp_u8=0;                      //���������
                            if(es_modbus_rtu_data_count_gu16a[index_u8]>=8){    //���ʣ��Ҫ�������ݶ���8�����ء�
                                c1_u8=8;                    //��ô����ѭ���ȶ�8�������ݡ�
                            }else{                          //����
                                c1_u8=(u8)(es_modbus_rtu_data_count_gu16a[index_u8]);  //���ж��ٶ����١�
                            }
                            for(j_u8=0;j_u8<c1_u8;j_u8++){      
                                es_modbus_cmd_read_io_bit(ch,es_modbus_rtu_address_gu16a[index_u8]++,&qw_u8);//����ַ�͵���ȡ�����У���ȡ��Ӧ�ı���ֵ��
                                if(qw_u8)temp_u8|=(1<<j_u8);        //��װ���ݡ�
                            }
                            crc_u16=es_send_whit_crc(ch,crc_u16,temp_u8);           //������װ�õ����ݡ�
                            es_modbus_rtu_data_count_gu16a[index_u8]-=(u16)c1_u8;   //����ʣ��Ҫ�������ݸ�����
                        }
                        uart_char(ch,(u8)(crc_u16));                //����CRC��
                        uart_char(ch,(u8)(crc_u16>>8));
                    }
            }else{                                  //�����ַ+��������2000��
                es_modbus_rtu_err_num(ch,0x02,0x02);//���ʹ�����02��
            }
        }else{                                  //�����������ͳ���65536�ˡ�
            es_modbus_rtu_err_num(ch,0x02,0x03);//���ʹ�����03��
        }
    }
#endif
/*-------------------------------------------------------
3�Ź����봦������
-------------------------------------------------------*/
#if (ES_MODBUS_RTU_CMD03_EN)
    void es_modbus_rtu_cmd_0x03(u8 ch){
        u8 id_u8,index_u8;
        u16 temp_u16,i_u16,crc_u16;
        index_u8=ecbm_stream_modbus_chtoid(ch);
        id_u8=es_modbus_rtu_get_id(ch);      //��ȡ����ID��
        if((es_modbus_rtu_data_count_gu16a[index_u8]>=1)&&(es_modbus_rtu_data_count_gu16a[index_u8]<=0x007D)){          //��ȡ�ĸ���Ҫ��1�����ϣ��ҵ�ַ���ܴ���125��
            if(((u32)(es_modbus_rtu_data_count_gu16a[index_u8])+(u32)(es_modbus_rtu_address_gu16a[index_u8]))<65536UL){ //�жϵ�ַ+������û�г��ޡ�
                if(es_modbus_rtu_broadcast_en_gu8a[index_u8]){
                    crc_u16=es_send_whit_crc(ch,0xFFFF,id_u8);            //���͵�ַ��
                    crc_u16=es_send_whit_crc(ch,crc_u16,0x03);             //���͹�����ظ���
                    crc_u16=es_send_whit_crc(ch,crc_u16,es_modbus_rtu_data_count_gu16a[index_u8]*2);//���ͻظ��ֽ�����
                    for(i_u16=0;i_u16<es_modbus_rtu_data_count_gu16a[index_u8];i_u16++){
                        es_modbus_cmd_read_reg(ch,es_modbus_rtu_address_gu16a[index_u8]+i_u16,&temp_u16);//�ӼĴ��������������ȡ������
                        crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(temp_u16>>8)); //�������ݡ�
                        crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(temp_u16));
                    }
                    uart_char(ch,(u8)(crc_u16));//����CRC��
                    uart_char(ch,(u8)(crc_u16>>8));
                }
            }else{
                es_modbus_rtu_err_num(ch,0x03,0x02);//���ʹ�����02��
            }
        }else{                                  //�����������ͳ���125�ˡ�
            es_modbus_rtu_err_num(ch,0x03,0x03);//���ʹ�����03��
        }
    }
#endif
/*-------------------------------------------------------
4�Ź����봦������
-------------------------------------------------------*/
#if (ES_MODBUS_RTU_CMD04_EN)
    void es_modbus_rtu_cmd_0x04(u8 ch){
        u8 id_u8,index_u8;
        u16 temp_u16,i_u16,crc_u16;
        index_u8=ecbm_stream_modbus_chtoid(ch);
        id_u8=es_modbus_rtu_get_id(ch);      //��ȡ����ID��
        if((es_modbus_rtu_data_count_gu16a[index_u8]>=1)&&(es_modbus_rtu_data_count_gu16a[index_u8]<=0x007D)){          //��ȡ�ĸ���Ҫ��1�����ϣ��ҵ�ַ���ܴ���125��
            if(((u32)(es_modbus_rtu_data_count_gu16a[index_u8])+(u32)(es_modbus_rtu_address_gu16a[index_u8]))<65536UL){ //�жϵ�ַ+������û�г��ޡ�
                if(es_modbus_rtu_broadcast_en_gu8a[index_u8]){
                    crc_u16=es_send_whit_crc(ch,0xFFFF,id_u8);            //���͵�ַ��
                    crc_u16=es_send_whit_crc(ch,crc_u16,0x04);             //���͹�����ظ���
                    crc_u16=es_send_whit_crc(ch,crc_u16,es_modbus_rtu_data_count_gu16a[index_u8]*2);//���ͻظ��ֽ�����
                    for(i_u16=0;i_u16<es_modbus_rtu_data_count_gu16a[index_u8];i_u16++){
                        es_modbus_cmd_read_io_reg(ch,es_modbus_rtu_address_gu16a[index_u8]+i_u16,&temp_u16);//�ӼĴ��������������ȡ������
                        crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(temp_u16>>8));//�������ݡ�
                        crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(temp_u16));
                    }
                    uart_char(ch,(u8)(crc_u16));//����CRC��
                    uart_char(ch,(u8)(crc_u16>>8));
                }
            }else{
                es_modbus_rtu_err_num(ch,0x04,0x02);//���ʹ�����02��
            }
        }else{                                  //�����������ͳ���125�ˡ�
            es_modbus_rtu_err_num(ch,0x04,0x03);//���ʹ�����03��
        }
    }
#endif
/*-------------------------------------------------------
5�Ź����봦������
-------------------------------------------------------*/
#if (ES_MODBUS_RTU_CMD05_EN)
    void es_modbus_rtu_cmd_0x05(u8 ch){
        u8 id_u8,index_u8;
        u16 crc_u16;
        index_u8=ecbm_stream_modbus_chtoid(ch);
        id_u8=es_modbus_rtu_get_id(ch);      //��ȡ����ID��
        if((es_modbus_rtu_data_count_gu16a[index_u8]==0x0000)||(es_modbus_rtu_data_count_gu16a[index_u8]==0xFF00)){//�ж����ֵ�Ƿ�Ϸ���
            es_modbus_cmd_write_bit(ch,es_modbus_rtu_address_gu16a[index_u8],(u8)(es_modbus_rtu_data_count_gu16a[index_u8]>>8));
            if(es_modbus_rtu_broadcast_en_gu8a[index_u8]){
                crc_u16=es_send_whit_crc(ch,0xFFFF,id_u8);            //���͵�ַ��
                crc_u16=es_send_whit_crc(ch,crc_u16,0x05);             //���͹�����ظ���
                crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(es_modbus_rtu_address_gu16a[index_u8]>>8)); //���͵�ַ�ظ���
                crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(es_modbus_rtu_address_gu16a[index_u8]));
                crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(es_modbus_rtu_data_count_gu16a[index_u8]>>8));//���ͼ����ظ���
                crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(es_modbus_rtu_data_count_gu16a[index_u8]));
                uart_char(ch,(u8)(crc_u16));    //����CRC��
                uart_char(ch,(u8)(crc_u16>>8));
            }    
        }else{                                  //������Ϸ��� 
            es_modbus_rtu_err_num(ch,0x05,0x03);//���ʹ�����03��
        }
    }
#endif
/*-------------------------------------------------------
6�Ź����봦������
-------------------------------------------------------*/
#if (ES_MODBUS_RTU_CMD06_EN)
    void es_modbus_rtu_cmd_0x06(u8 ch){
        u8 id_u8,index_u8;
        u16 crc_u16;
        index_u8=ecbm_stream_modbus_chtoid(ch);
        id_u8=es_modbus_rtu_get_id(ch);      //��ȡ����ID��
        es_modbus_cmd_write_reg(ch,es_modbus_rtu_address_gu16a[index_u8],es_modbus_rtu_data_count_gu16a[index_u8]);//������д��Ĵ�����
        if(es_modbus_rtu_broadcast_en_gu8a[index_u8]){
            crc_u16=es_send_whit_crc(ch,0xFFFF,id_u8);    //���͵�ַ��
            crc_u16=es_send_whit_crc(ch,crc_u16,0x06);     //���͹�����ظ���
            crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(es_modbus_rtu_address_gu16a[index_u8]>>8));//���͵�ַ��
            crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(es_modbus_rtu_address_gu16a[index_u8]));
            crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(es_modbus_rtu_data_count_gu16a[index_u8]>>8));//���͸�����
            crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(es_modbus_rtu_data_count_gu16a[index_u8]));
            uart_char(ch,(u8)(crc_u16));//����CRC��
            uart_char(ch,(u8)(crc_u16>>8));
        }    
    }
#endif
/*-------------------------------------------------------
16�Ź����봦������
-------------------------------------------------------*/
#if (ES_MODBUS_RTU_CMD10_EN)
    void es_modbus_rtu_cmd_0x10(u8 ch){
        u8 i_u8,id_u8,index_u8;
        u16 crc_u16;
        index_u8=ecbm_stream_modbus_chtoid(ch);
        id_u8=es_modbus_rtu_get_id(ch);      //��ȡ����ID��
        if((es_modbus_rtu_cmd_count_gu8a[index_u8]==0)||(es_modbus_rtu_cmd_count_gu8a[index_u8]!=(u8)(es_modbus_rtu_data_count_gu16a[index_u8]*2))){//����������ϡ�
            es_modbus_rtu_err_num(ch,es_modbus_rtu_fun_code_gu8a[index_u8],0x03);//�ֽ����Բ��ϣ����ʹ�����03��
            return;
        }
        if((es_modbus_rtu_data_count_gu16a[index_u8]>=0x0001)&&(es_modbus_rtu_data_count_gu16a[index_u8]<=0x007B)){             //��������ݸ����÷���Ҫ��
            if(((u32)(es_modbus_rtu_address_gu16a[index_u8])+(u32)(es_modbus_rtu_data_count_gu16a[index_u8]))<65536UL){             //��ַ���ܳ���65536��
                for(i_u8=0;i_u8<es_modbus_rtu_cmd_count_gu8a[index_u8];i_u8++){   
                    es_modbus_cmd_write_reg(ch,es_modbus_rtu_address_gu16a[index_u8]+i_u8,es_modbus_rtu_cmd_buf_gu16a[index_u8][i_u8]);  //������д��Ĵ�����
                }
                if(es_modbus_rtu_broadcast_en_gu8a[index_u8]){
                    crc_u16=es_send_whit_crc(ch,0xFFFF,id_u8);            //���͵�ַ��
                    crc_u16=es_send_whit_crc(ch,crc_u16,0x10);             //���͹�����ظ���
                    crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(es_modbus_rtu_address_gu16a[index_u8]>>8));//���͵�ַ��
                    crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(es_modbus_rtu_address_gu16a[index_u8]));
                    crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(es_modbus_rtu_data_count_gu16a[index_u8]>>8));//���͸�����
                    crc_u16=es_send_whit_crc(ch,crc_u16,(u8)(es_modbus_rtu_data_count_gu16a[index_u8]));
                    uart_char(ch,(u8)(crc_u16));    //����CRC��
                    uart_char(ch,(u8)(crc_u16>>8));
                }   
            }else{
                es_modbus_rtu_err_num(ch,0x10,0x02);//���ʹ�����02��
            }
        }else{                                  //������Ϸ��� 
            es_modbus_rtu_err_num(ch,0x10,0x03);//���ʹ�����03��
        }
    }
#endif
/*-------------------------------------------------------
modbus_rtu����ִ�к�����
-------------------------------------------------------*/
void es_modbus_rtu_exe(u8 ch,u8 dat){
    u8 i_u8,temp_u8,mask_u8,index_u8;
    i_u8=i_u8;
    temp_u8=temp_u8;
    mask_u8=mask_u8;
    index_u8=ecbm_stream_modbus_chtoid(ch);

    if(es_modbus_rtu_mode_gu8a[index_u8]==ES_MODBUS_RTU_MODE_SLAVE){//�ӻ�ģʽ
        switch(es_modbus_rtu_status_gu8a[index_u8]){
            case ES_MODBUS_RTU_READY:{                          //�������ȴ��������ݡ�
                if((dat==es_modbus_rtu_get_id(ch))||(dat==0)){  //����յ���ID�ͱ�����ƥ�䡣
                    es_modbus_rtu_status_gu8a      [index_u8]=ES_MODBUS_RTU_FUN_NUM;//�л���������ʶ��
                    es_modbus_rtu_broadcast_en_gu8a[index_u8]=dat;     //д��ͨ��ģʽ��Ϊ�˼򻯴��룬����ֱ�Ӹ�ֵ��
                    es_modbus_rtu_fun_code_gu8a    [index_u8]=0;       //���㹦���뻺�档
                    es_modbus_rtu_uart_crc_gu16a   [index_u8]=es_crc16(0xFFFF,dat);//����CRC��
                }
            }break;
            case ES_MODBUS_RTU_FUN_NUM:{        //���ڽ��չ����롣
                es_modbus_rtu_fun_code_gu8a [index_u8]=dat;
                es_modbus_rtu_status_gu8a   [index_u8]=ES_MODBUS_RTU_ADDRH;    //�ֽ׶β�������������ƣ������ƶ���CRC������
                es_modbus_rtu_uart_crc_gu16a[index_u8]=es_crc16(es_modbus_rtu_uart_crc_gu16a[index_u8],dat);
            }break;
            case ES_MODBUS_RTU_ADDRH:{                        //���յ�ַ�ĸ�8λ��
                es_modbus_rtu_address_gu16a [index_u8]=(u16)(dat)<<8;    //��װ��ַ��
                es_modbus_rtu_status_gu8a   [index_u8]=ES_MODBUS_RTU_ADDRL;//����һ����
                es_modbus_rtu_uart_crc_gu16a[index_u8]=es_crc16(es_modbus_rtu_uart_crc_gu16a[index_u8],dat);
            }break;
            case ES_MODBUS_RTU_ADDRL:{                        //���յ�ַ�ĵ�8λ��
                es_modbus_rtu_address_gu16a [index_u8]+=(u16)(dat);              //��װ��ַ��
                es_modbus_rtu_status_gu8a   [index_u8]=ES_MODBUS_RTU_DATA_COUNTH;  //����һ����
                es_modbus_rtu_uart_crc_gu16a[index_u8]=es_crc16(es_modbus_rtu_uart_crc_gu16a[index_u8],dat);//����CRC��
            }break;
            case ES_MODBUS_RTU_DATA_COUNTH:{                  //��������/�����ĸ�8λ��
                es_modbus_rtu_data_count_gu16a[index_u8]=(u16)(dat)<<8;         //��װ����/������
                es_modbus_rtu_status_gu8a     [index_u8]=ES_MODBUS_RTU_DATA_COUNTL;  //����һ����
                es_modbus_rtu_uart_crc_gu16a  [index_u8]=es_crc16(es_modbus_rtu_uart_crc_gu16a[index_u8],dat);//����CRC��
            }break;
            case ES_MODBUS_RTU_DATA_COUNTL:{                  //��������/�����ĵ�8λ��
                es_modbus_rtu_data_count_gu16a  [index_u8]+=(u16)(dat);           //��װ����/������
                if(es_modbus_rtu_fun_code_gu8a  [index_u8]==0x10){
                    es_modbus_rtu_cmd_count_gu8a[index_u8]=0;
                    es_modbus_rtu_status_gu8a   [index_u8]=ES_MODBUS_RTU_BYTE_COUNT;//���ֽڶ�ȡ��
                }else{
                    es_modbus_rtu_status_gu8a[index_u8]=ES_MODBUS_RTU_CRCL;//��CRC��
                }
                es_modbus_rtu_uart_crc_gu16a[index_u8]=es_crc16(es_modbus_rtu_uart_crc_gu16a[index_u8],dat);//����CRC��
            }break;
            case ES_MODBUS_RTU_CRCL:{                         //����CRC�ĵ�8λ��
                es_modbus_rtu_crc_buf_gu16a[index_u8]=(u16)(dat);       //���CRC��
                es_modbus_rtu_status_gu8a  [index_u8]=ES_MODBUS_RTU_CRCH; //����һ����
            }break;
            case ES_MODBUS_RTU_CRCH:{                         //����CRC�ĸ�8λ��
                es_modbus_rtu_crc_buf_gu16a[index_u8]+=(u16)dat<<8;           //���CRC��
                if(es_modbus_rtu_crc_buf_gu16a[index_u8]==es_modbus_rtu_uart_crc_gu16a[index_u8]){//�жϽ��յ�CRC�ͼ����CRC�Ƿ���ȡ�
                    #if (ES_MODBUS_RTU_CMD_ALL_EN)
                        switch(es_modbus_rtu_fun_code_gu8a[index_u8]){//���ݹ�������ѡ���Ӧ�Ķ�����
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
                                es_modbus_rtu_err_num(ch,es_modbus_rtu_fun_code_gu8a[index_u8],0x01);//���ʹ�����01��
                            }break;//��֧�ֵĹ�����ͷ���0x80+�����롣
                        }
                    #endif
                }
                #if (ES_MODBUS_RTU_CRC_ERR_EN)
                    else{                                          //����
                        es_modbus_rtu_crc_err_callback(ch);//������CRC������档
                    }
                #endif
                es_modbus_rtu_status_gu8a[index_u8]=ES_MODBUS_RTU_READY;
            }break;
            #if (ES_MODBUS_RTU_CMD10_EN)
                case ES_MODBUS_RTU_BYTE_COUNT:{                   //���������ֽ�����
                    es_modbus_rtu_cmd_count_gu8a[index_u8]=dat;
                    es_modbus_rtu_count_gu8a[index_u8]=0;
                    es_modbus_rtu_status_gu8a[index_u8]=ES_MODBUS_RTU_DATAH;//������Ӧ�Ĵ�����档
                    es_modbus_rtu_uart_crc_gu16a[index_u8]=es_crc16(es_modbus_rtu_uart_crc_gu16a[index_u8],dat);//����CRC��
                }break;
                case ES_MODBUS_RTU_DATAH:{
                    es_modbus_rtu_cmd_buf_gu16a [index_u8][es_modbus_rtu_count_gu8a[index_u8]/2]=((u16)(dat))<<8;
                    es_modbus_rtu_count_gu8a[index_u8]++;
                    if(es_modbus_rtu_count_gu8a[index_u8]==(u8)(es_modbus_rtu_cmd_count_gu8a[index_u8])){
                        es_modbus_rtu_status_gu8a[index_u8]=ES_MODBUS_RTU_CRCL;//��CRC��
                    }else{
                        es_modbus_rtu_status_gu8a   [index_u8]=ES_MODBUS_RTU_DATAL;   //����8λ��
                    }
                    es_modbus_rtu_uart_crc_gu16a[index_u8]=es_crc16(es_modbus_rtu_uart_crc_gu16a[index_u8],dat);//����CRC��
                }break;
                case ES_MODBUS_RTU_DATAL:{
                    es_modbus_rtu_cmd_buf_gu16a[index_u8][es_modbus_rtu_count_gu8a[index_u8]/2]+=((u16)(dat));
                    es_modbus_rtu_count_gu8a[index_u8]++;
                    if(es_modbus_rtu_count_gu8a[index_u8]==(u8)(es_modbus_rtu_cmd_count_gu8a[index_u8])){
                        es_modbus_rtu_status_gu8a[index_u8]=ES_MODBUS_RTU_CRCL;//��CRC��
                    }else{
                        es_modbus_rtu_status_gu8a[index_u8]=ES_MODBUS_RTU_DATAH;//����һ�����ݵĸ�8λ��
                    }
                    es_modbus_rtu_uart_crc_gu16a[index_u8]=es_crc16(es_modbus_rtu_uart_crc_gu16a[index_u8],dat);//����CRC��
                }break;
            #endif
        }
    }else{//����ģʽ
        #if (ES_MODBUS_RTU_MASTER_EN)
            switch(es_modbus_rtu_status_gu8a[index_u8]){
                case ES_MODBUS_RTU_READY:{                          //�ȴ��ӻ����ء�
                    if(es_modbus_rtu_send_id_gu8a[index_u8]==dat){                 //��������ֻ��һ���޶������Ƿ��ص�ID�����Ƿ��͵�ID��
                        es_modbus_rtu_status_gu8a[index_u8]=ES_MODBUS_RTU_FUN_NUM; //�л���������ʶ��
                        es_modbus_rtu_fun_code_gu8a[index_u8]=0;                   //���㹦���뻺�档
                        es_modbus_rtu_uart_crc_gu16a[index_u8]=es_crc16(0xFFFF,dat);//����CRC��
                    }
                }break;
                case ES_MODBUS_RTU_FUN_NUM:{        //���ڽ��չ����롣
                    es_modbus_rtu_fun_code_gu8a[index_u8]=dat;     //���湦���룬֮���õõ���
                    if(es_modbus_rtu_fun_code_gu8a[index_u8]<127){
                        switch(es_modbus_rtu_fun_code_gu8a[index_u8]){ //�ж��ǲ��Ǳ���֧�ֵĹ����롣
                            #if (ES_MODBUS_RTU_MASTER_CMD01_EN)
                                case 0x01://����Ȧ
                            #endif
                            #if (ES_MODBUS_RTU_MASTER_CMD02_EN)
                                case 0x02://����ɢ������
                            #endif
                            #if (ES_MODBUS_RTU_MASTER_CMD03_EN)
                                case 0x03://������Ĵ���
                            #endif
                            #if (ES_MODBUS_RTU_MASTER_CMD04_EN)    
                                case 0x04://������Ĵ���
                            #endif    
                            #if (ES_MODBUS_RTU_MASTER_CMD_01020304_EN)
                                {//����4�ֹ�����ķ��ظ�ʽ��һ���ġ�
                                    es_modbus_rtu_status_gu8a[index_u8]=ES_MODBUS_RTU_RETURN_COUNT;            //�������շ���������
                                    es_modbus_rtu_uart_crc_gu16a[index_u8]=es_crc16(es_modbus_rtu_uart_crc_gu16a[index_u8],dat);//����CRC��
                                }break;
                            #endif    
                            #if (ES_MODBUS_RTU_MASTER_CMD05_EN)    
                                case 0x05://д������Ȧ
                            #endif    
                            #if (ES_MODBUS_RTU_MASTER_CMD06_EN)  
                                case 0x06://д�����Ĵ���
                            #endif    
                            #if (ES_MODBUS_RTU_MASTER_CMD10_EN)      
                                case 0x10://д����Ĵ���
                            #endif     
                            #if (ES_MODBUS_RTU_MASTER_CMD_050610_EN)
                                {//����3�ֹ�����ķ��ظ�ʽ��һ���ġ�
                                    es_modbus_rtu_status_gu8a[index_u8]=ES_MODBUS_RTU_ADDRH;                   //�������շ��ص�ַ��
                                    es_modbus_rtu_uart_crc_gu16a[index_u8]=es_crc16(es_modbus_rtu_uart_crc_gu16a[index_u8],dat);//����CRC��
                                }break;
                            #endif
                            default:{//�����������7�֣���ô˵�����ڻ�û֧�����ָ�
                                es_modbus_rtu_status_gu8a[index_u8]=ES_MODBUS_RTU_READY;//�ص�������
                            }break;
                        }
                    }else{
                        es_modbus_rtu_status_gu8a[index_u8]=ES_MODBUS_RTU_ERROR_CODE;
                        es_modbus_rtu_uart_crc_gu16a[index_u8]=es_crc16(es_modbus_rtu_uart_crc_gu16a[index_u8],dat);//����CRC��
                    }
                }break;
                case ES_MODBUS_RTU_ERROR_CODE:{
                    es_modbus_rtu_reply_count_gu8a[index_u8]=dat;//����һ�����������������롣
                    es_modbus_rtu_status_gu8a[index_u8]=ES_MODBUS_RTU_CRCL;                    //�������շ��ص�ַ��
                    es_modbus_rtu_uart_crc_gu16a[index_u8]=es_crc16(es_modbus_rtu_uart_crc_gu16a[index_u8],dat);//����CRC��
                }break;
                #if (ES_MODBUS_RTU_MASTER_CMD_01020304_EN)
                    case ES_MODBUS_RTU_RETURN_COUNT:{   //���շ���������
                        es_modbus_rtu_reply_count_gu8a[index_u8]=dat;  //���������������λ���ֽڡ�
                        es_modbus_rtu_cmd_count_gu8a  [index_u8]=0;    //�������������
                        switch(es_modbus_rtu_fun_code_gu8a[index_u8]){ //��ͬ��ָ���в�ͬ�Ĵ���
                            default:break;
                            #if (ES_MODBUS_RTU_MASTER_CMD01_EN)  
                                case 0x01://����Ȧ
                            #endif
                            #if (ES_MODBUS_RTU_MASTER_CMD02_EN) 
                                case 0x02://����ɢ������
                            #endif
                            #if (ES_MODBUS_RTU_MASTER_CMD_0102_EN)
                                {//��������ָ����һ���ֽڴ�8����Ȧ�����ݡ�
                                    es_modbus_rtu_status_gu8a[index_u8]=ES_MODBUS_RTU_0102_RETURN;//����[01H][02H]����
                                }break;
                            #endif
                            #if (ES_MODBUS_RTU_MASTER_CMD03_EN)  
                                case 0x03://������Ĵ���
                            #endif
                            #if (ES_MODBUS_RTU_MASTER_CMD04_EN)  
                                case 0x04://������Ĵ���
                            #endif
                            #if (ES_MODBUS_RTU_MASTER_CMD_0304_EN)
                                {//��������ָ���������ֽڴ�һ���Ĵ��������ݡ�
                                    es_modbus_rtu_status_gu8a[index_u8]=ES_MODBUS_RTU_0304_RETURN;//����[03H][04H]����
                                }break;
                            #endif
                        }
                        es_modbus_rtu_uart_crc_gu16a[index_u8]=es_crc16(es_modbus_rtu_uart_crc_gu16a[index_u8],dat);//����CRC��
                    }break;
                #endif
                #if (ES_MODBUS_RTU_MASTER_CMD_0102_EN)
                    case ES_MODBUS_RTU_0102_RETURN:{                                //[01H][02H]ָ��Ĵ���
                        es_modbus_rtu_cmd_buf_gu16a[index_u8][es_modbus_rtu_cmd_count_gu8a[index_u8]++]=dat;       //�����յ����ݱ���������
                        es_modbus_rtu_uart_crc_gu16a[index_u8]=es_crc16(es_modbus_rtu_uart_crc_gu16a[index_u8],dat);//����CRC��
                        if(es_modbus_rtu_cmd_count_gu8a[index_u8]>=es_modbus_rtu_reply_count_gu8a[index_u8]){     //�����յ������ﵽҪ��ʱ��
                            es_modbus_rtu_status_gu8a[index_u8]=ES_MODBUS_RTU_CRCL;                //������CRC��
                        }
                    }break;
                #endif
                #if (ES_MODBUS_RTU_MASTER_CMD_0304_EN)
                    case ES_MODBUS_RTU_0304_RETURN:{                                //[03H][04H]ָ��Ĵ���
                        if(es_modbus_rtu_cmd_count_gu8a[index_u8]%2){                              //����������Ϊ����ʱ��
                            es_modbus_rtu_cmd_buf_gu16a[index_u8][es_modbus_rtu_cmd_count_gu8a[index_u8]>>1]<<=8;  //���ϴν��յ��������Ƶ���8λ��
                            es_modbus_rtu_cmd_buf_gu16a[index_u8][es_modbus_rtu_cmd_count_gu8a[index_u8]>>1]+=dat; //Ȼ��������ݵ���8λ��
                        }else{                                                      //����������Ϊż������0ʱ��
                            es_modbus_rtu_cmd_buf_gu16a[index_u8][es_modbus_rtu_cmd_count_gu8a[index_u8]>>1]=dat;  //ֱ�Ӽ������ݡ�
                        }//��Ȼmodbus������֡�����˽���������ż���������ǰ��ա���Ҫ�����ݵ�ʱ�����λ����ϰ�ߣ������Ʋ��������˵�8λ���ݳ��ֵ�ִ������С�
                        es_modbus_rtu_cmd_count_gu8a[index_u8]++;                                  //�ѽ���������һ��
                        es_modbus_rtu_uart_crc_gu16a[index_u8]=es_crc16(es_modbus_rtu_uart_crc_gu16a[index_u8],dat);//����CRC��
                        if(es_modbus_rtu_cmd_count_gu8a[index_u8]>=es_modbus_rtu_reply_count_gu8a[index_u8]){     //�����յ������ﵽҪ��ʱ��
                            es_modbus_rtu_status_gu8a[index_u8]=ES_MODBUS_RTU_CRCL;                //������CRC��
                        }
                    }break;
                #endif
                #if (ES_MODBUS_RTU_MASTER_CMD_050610_EN)
                    case ES_MODBUS_RTU_ADDRH:{                      //���շ��ص�ַ�ĸ�8λ��
                        es_modbus_rtu_cmd_buf_gu16a[index_u8][0]=(u16)dat<<8;       //��װ��ַ��
                        es_modbus_rtu_status_gu8a[index_u8]=ES_MODBUS_RTU_ADDRL;   //����һ����
                        es_modbus_rtu_uart_crc_gu16a[index_u8]=es_crc16(es_modbus_rtu_uart_crc_gu16a[index_u8],dat);//����CRC��
                    }break;
                    case ES_MODBUS_RTU_ADDRL:{                          //���շ��ص�ַ�ĵ�8λ��
                        es_modbus_rtu_cmd_buf_gu16a[index_u8][0]+=(u16)(dat);             //��װ��ַ��
                        es_modbus_rtu_status_gu8a[index_u8]=ES_MODBUS_RTU_DATA_COUNTH; //����һ����
                        es_modbus_rtu_uart_crc_gu16a[index_u8]=es_crc16(es_modbus_rtu_uart_crc_gu16a[index_u8],dat);//����CRC��
                    }break;
                    case ES_MODBUS_RTU_DATA_COUNTH:{                    //���շ��ظ����ĸ�8λ��
                        es_modbus_rtu_cmd_buf_gu16a[index_u8][1]=(u16)(dat)<<8;           //��װ���ظ�����
                        es_modbus_rtu_status_gu8a[index_u8]=ES_MODBUS_RTU_DATA_COUNTL; //����һ����
                        es_modbus_rtu_uart_crc_gu16a[index_u8]=es_crc16(es_modbus_rtu_uart_crc_gu16a[index_u8],dat);//����CRC��
                    }break;
                    case ES_MODBUS_RTU_DATA_COUNTL:{            //���շ��ظ����ĵ�8λ��
                        es_modbus_rtu_cmd_buf_gu16a[index_u8][1]+=(u16)(dat);     //��װ���ظ�����
                        es_modbus_rtu_status_gu8a[index_u8]=ES_MODBUS_RTU_CRCL;//��CRC��
                        es_modbus_rtu_uart_crc_gu16a[index_u8]=es_crc16(es_modbus_rtu_uart_crc_gu16a[index_u8],dat);//����CRC��
                    }break;
                #endif
                case ES_MODBUS_RTU_CRCL:{                       //����CRC�ĵ�8λ��
                    es_modbus_rtu_crc_buf_gu16a[index_u8]=(u16)(dat);           //��CRC�ĵ�8λ��������
                    es_modbus_rtu_status_gu8a[index_u8]=ES_MODBUS_RTU_CRCH;    //����һ����
                }break;
                case ES_MODBUS_RTU_CRCH:{                       //����CRC�ĸ�8λ��
                    es_modbus_rtu_crc_buf_gu16a[index_u8]+=(u16)(dat)<<8;       //ƴ���������ݵõ�����CRC��
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
���ôӻ�ģʽ������
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
����01�Ź����뷢�ͺ�����
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
����02�Ź����뷢�ͺ�����
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
����03�Ź����뷢�ͺ�����
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
����04�Ź����뷢�ͺ�����
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
����05�Ź����뷢�ͺ�����
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
����06�Ź����뷢�ͺ�����
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
����16�Ź����뷢�ͺ�����
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
#endif  //���������#ifndef��ϳ�һ������Ρ�
        //��һ������Ϊ��β��