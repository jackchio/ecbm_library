#include "ecbm_core.h"  //ͳһ���غ���ͷ�ļ�
#if ((ECBM_10MS_EN)&&(ECBM_STREAM_LIB_EN)&&(ECBM_STREAM_CH_COUNT))  //��鱾����û�б�ʹ��
/*--------------------------------------��������-----------------------------------*/
#if (ECBM_STREAM_CH1_EN)
u8 xdata ecbm_stream_ch1_buf_gxu8a[ECBM_STREAM_CH1_SZIE];//stream��ͨ��1���ջ��档
u8 ecbm_stream_ch1_point_gu8;                            //stream��ͨ��1���ջ����д���ַ��
u8 ecbm_stream_ch1_read_point_gu8;                       //stream��ͨ��1������Ľ��ȡ�
u8 ecbm_stream_ch1_count_gu8;                            //stream��ͨ��1���յ�������������
u8 ecbm_stream_ch1_time_gu8;                             //stream��ͨ��1��ʱ����ʱ������
u8 ecbm_stream_ch1_status_gu8;                           //stream��ͨ��1״̬��
#endif

#if (ECBM_STREAM_CH2_EN)
u8 xdata ecbm_stream_ch2_buf_gxu8a[ECBM_STREAM_CH2_SZIE];//stream��ͨ��2���ջ��档
u8 ecbm_stream_ch2_point_gu8;                            //stream��ͨ��2���ջ����д���ַ��
u8 ecbm_stream_ch2_read_point_gu8;                       //stream��ͨ��2������Ľ��ȡ�
u8 ecbm_stream_ch2_count_gu8;                            //stream��ͨ��2���յ�������������
u8 ecbm_stream_ch2_time_gu8;                             //stream��ͨ��2��ʱ����ʱ������
u8 ecbm_stream_ch2_status_gu8;                           //stream��ͨ��2״̬��
#endif

#if (ECBM_STREAM_CH3_EN)
u8 xdata ecbm_stream_ch3_buf_gxu8a[ECBM_STREAM_CH3_SZIE];//stream��ͨ��3���ջ��档
u8 ecbm_stream_ch3_point_gu8;                            //stream��ͨ��3���ջ����д���ַ��
u8 ecbm_stream_ch3_read_point_gu8;                       //stream��ͨ��3������Ľ��ȡ�
u8 ecbm_stream_ch3_count_gu8;                            //stream��ͨ��3���յ�������������
u8 ecbm_stream_ch3_time_gu8;                             //stream��ͨ��3��ʱ����ʱ������
u8 ecbm_stream_ch3_status_gu8;                           //stream��ͨ��3״̬��
#endif

#if (ECBM_STREAM_CH4_EN)
u8 xdata ecbm_stream_ch4_buf_gxu8a[ECBM_STREAM_CH4_SZIE];//stream��ͨ��4���ջ��档
u8 ecbm_stream_ch4_point_gu8;                            //stream��ͨ��4���ջ����д���ַ��
u8 ecbm_stream_ch4_read_point_gu8;                       //stream��ͨ��4������Ľ��ȡ�
u8 ecbm_stream_ch4_count_gu8;                            //stream��ͨ��4���յ�������������
u8 ecbm_stream_ch4_time_gu8;                             //stream��ͨ��4��ʱ����ʱ������
u8 ecbm_stream_ch4_status_gu8;                           //stream��ͨ��4״̬��
#endif
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
stream��ʼ��������
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
ʱ�����к�����
-------------------------------------------------------*/  
void ecbm_stream_timer_run(void){
    #if (ECBM_STREAM_CH1_EN)
        if(ecbm_stream_ch1_status_gu8&ECBM_STREAM_TIME_EN){      //��������״̬ʱ��
            ecbm_stream_ch1_time_gu8++;                          //ÿ�ζ�ʱ���жϼ�һ�Ρ�
            if(ecbm_stream_ch1_time_gu8>ECBM_STREAM_TIME_MAX){   //�����˼��ʱ�����ֵʱ��
                ecbm_stream_ch1_status_gu8|=ECBM_STREAM_TIME_OUT;//��ɳ�ʱ״̬��
            }
            if(ecbm_stream_ch1_time_gu8>ECBM_STREAM_IDLE_MAX){    //�����˿���ʱ�����ֵʱ��
                ecbm_stream_ch1_status_gu8|=ECBM_STREAM_UART_IDLE;//��ɿ���״̬��
                ecbm_stream_ch1_status_gu8&=~ECBM_STREAM_TIME_EN; //����ʱ�رռ�ʱ��
            }
        }
    #endif      
    
    #if (ECBM_STREAM_CH2_EN)
        if(ecbm_stream_ch2_status_gu8&ECBM_STREAM_TIME_EN){      //��������״̬ʱ��
            ecbm_stream_ch2_time_gu8++;                          //ÿ�ζ�ʱ���жϼ�һ�Ρ�
            if(ecbm_stream_ch2_time_gu8>ECBM_STREAM_TIME_MAX){   //�����˼��ʱ�����ֵʱ��
                ecbm_stream_ch2_status_gu8|=ECBM_STREAM_TIME_OUT;//��ɳ�ʱ״̬��
            }
            if(ecbm_stream_ch2_time_gu8>ECBM_STREAM_IDLE_MAX){    //�����˿���ʱ�����ֵʱ��
                ecbm_stream_ch2_status_gu8|=ECBM_STREAM_UART_IDLE;//��ɿ���״̬��
                ecbm_stream_ch2_status_gu8&=~ECBM_STREAM_TIME_EN; //����ʱ�رռ�ʱ��
            }
        }
    #endif      
    
    #if (ECBM_STREAM_CH3_EN)
        if(ecbm_stream_ch3_status_gu8&ECBM_STREAM_TIME_EN){      //��������״̬ʱ��
            ecbm_stream_ch3_time_gu8++;                          //ÿ�ζ�ʱ���жϼ�һ�Ρ�
            if(ecbm_stream_ch3_time_gu8>ECBM_STREAM_TIME_MAX){   //�����˼��ʱ�����ֵʱ��
                ecbm_stream_ch3_status_gu8|=ECBM_STREAM_TIME_OUT;//��ɳ�ʱ״̬��
            }
            if(ecbm_stream_ch3_time_gu8>ECBM_STREAM_IDLE_MAX){    //�����˿���ʱ�����ֵʱ��
                ecbm_stream_ch3_status_gu8|=ECBM_STREAM_UART_IDLE;//��ɿ���״̬��
                ecbm_stream_ch3_status_gu8&=~ECBM_STREAM_TIME_EN; //����ʱ�رռ�ʱ��
            }
        }
    #endif   
        
    #if (ECBM_STREAM_CH4_EN)
        if(ecbm_stream_ch4_status_gu8&ECBM_STREAM_TIME_EN){      //��������״̬ʱ��
            ecbm_stream_ch4_time_gu8++;                          //ÿ�ζ�ʱ���жϼ�һ�Ρ�
            if(ecbm_stream_ch4_time_gu8>ECBM_STREAM_TIME_MAX){   //�����˼��ʱ�����ֵʱ��
                ecbm_stream_ch4_status_gu8|=ECBM_STREAM_TIME_OUT;//��ɳ�ʱ״̬��
            }
            if(ecbm_stream_ch4_time_gu8>ECBM_STREAM_IDLE_MAX){    //�����˿���ʱ�����ֵʱ��
                ecbm_stream_ch4_status_gu8|=ECBM_STREAM_UART_IDLE;//��ɿ���״̬��
                ecbm_stream_ch4_status_gu8&=~ECBM_STREAM_TIME_EN; //����ʱ�رռ�ʱ��
            }
        }
    #endif
}
/*-------------------------------------------------------
������������������
-------------------------------------------------------*/
void ecbm_stream_main(void){
    u8 dat_u8;
    
    #if (ECBM_STREAM_CH1_EN)//���봦���������
        if(ecbm_stream_ch1_status_gu8&ECBM_STREAM_TIME_OUT){//�����ǽ��ճ�ʱ״̬�����״̬�����Ѿ�����һ��ʱ��û���µ����ݹ����ˡ�
            if((ecbm_stream_ch1_count_gu8>0)&&(ecbm_stream_ch1_count_gu8<ECBM_STREAM_CH1_SZIE)){//�жϽ��յ������ݵ������Ƿ�Ϸ���
                ecbm_stream_ch1_status_gu8&=~ECBM_STREAM_TIME_OUT;  //��ʼ���������ˣ���������־λ��
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
    
    #if (ECBM_STREAM_CH2_EN)//���봦���������
        if(ecbm_stream_ch2_status_gu8&ECBM_STREAM_TIME_OUT){//�����ǽ��ճ�ʱ״̬�����״̬�����Ѿ�����һ��ʱ��û���µ����ݹ����ˡ�
            if((ecbm_stream_ch2_count_gu8>0)&&(ecbm_stream_ch2_count_gu8<ECBM_STREAM_CH2_SZIE)){//�жϽ��յ������ݵ������Ƿ�Ϸ���
                ecbm_stream_ch2_status_gu8&=~ECBM_STREAM_TIME_OUT;  //��ʼ���������ˣ���������־λ��
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
    
    #if (ECBM_STREAM_CH3_EN)//���봦���������
        if(ecbm_stream_ch3_status_gu8&ECBM_STREAM_TIME_OUT){//�����ǽ��ճ�ʱ״̬�����״̬�����Ѿ�����һ��ʱ��û���µ����ݹ����ˡ�
            if((ecbm_stream_ch3_count_gu8>0)&&(ecbm_stream_ch3_count_gu8<ECBM_STREAM_CH3_SZIE)){//�жϽ��յ������ݵ������Ƿ�Ϸ���
                ecbm_stream_ch3_status_gu8&=~ECBM_STREAM_TIME_OUT;  //��ʼ���������ˣ���������־λ��
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
    
    #if (ECBM_STREAM_CH4_EN)//���봦���������
        if(ecbm_stream_ch4_status_gu8&ECBM_STREAM_TIME_OUT){//�����ǽ��ճ�ʱ״̬�����״̬�����Ѿ�����һ��ʱ��û���µ����ݹ����ˡ�
            if((ecbm_stream_ch4_count_gu8>0)&&(ecbm_stream_ch4_count_gu8<ECBM_STREAM_CH4_SZIE)){//�жϽ��յ������ݵ������Ƿ�Ϸ���
                ecbm_stream_ch4_status_gu8&=~ECBM_STREAM_TIME_OUT;  //��ʼ���������ˣ���������־λ��
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
������ȶԺ�����
-------------------------------------------------------*/
#if (ECBM_STREAM_CMP_EN)
void ecbm_stream_strcmp(u8 dat,u8 code * str,u8 * count){
    if(str[*count]==dat){    //�ж�һ�µ�ǰ�������ݺ͹ؼ��ֵ�ĳ���ַ��Ƿ�һ����
        (*count)++;          //һ���Ļ�������+1���´�ѭ���ͻ��ж���һ���ַ��ˡ�
    }else{                   //��һ���Ļ���
        *count=0;            //�������㡣�����ڱ���ѭ���У��������������ؼ��ֵ�һ�����ַ���
        if(str[*count]==dat){//��Ȼ���������ַ���Ҫ�ж����Ƿ��뵱ǰ�������ݷ��ϡ�
            (*count)++;      //���Ͼͼ���+1��
        }
    }
}
#endif
/*-------------------------------------------------------
CRC16У�麯����
-------------------------------------------------------*/
#if (ECBM_STREAM_MODBUS_CH_COUNT+ECBM_STREAM_ECP_CH_COUNT)
    u16 es_crc16(u16 crc,u8 buf){
        u8 j;
        u16 crc_buf;
        crc_buf=crc^buf;                    //��ǰ�������CRC���ֽڣ���C51�����ֱ�Ӵ���
        for(j=0;j<8;j++){                   //����ÿ���ֽڵ�ÿһλ��
            if(crc_buf&0x01){               //�ж�����ǰ���λ�Ƿ�Ϊ1��
                crc_buf=(crc_buf>>1)^0xA001;//���Ϊ1�����Ʋ������ʽ��
            }else{
                crc_buf>>=1;                //����ֱ������һλ��
            }           
        }
        return crc_buf;
    }
    u16 es_send_whit_crc(u8 ch,u16 crc,u8 dat){
        uart_char(ch,dat);
        return es_crc16(crc,dat);
    }
#endif
#endif  //���������#ifndef��ϳ�һ������Ρ�
        //��һ������Ϊ��β��