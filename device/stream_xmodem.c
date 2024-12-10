#include "ecbm_core.h"  //ͳһ���غ���ͷ�ļ�
//δ�����׶Σ���
#if (0)&&(ECBM_10MS_EN)&&(ECBM_STREAM_LIB_EN)&&(ECBM_STREAM_XMODEM_CH_COUNT)    //��鱾����û�б�ʹ��
/*--------------------------------------��������-----------------------------------*/
u8    es_xmodem_buf_start  =0; //xmodem�������ڻ����еĿ�ʼλ�á�
u8    es_xmodem_sum        =0; //У��͡�
u8    es_xmodem_pack       =0; //���ݰ���š�
u8    es_xmodem_status     =0; //Xmodem״̬��״̬��
u8    es_xmodem_count      =0; //�������ݼ�����
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
xmodem��ʼ���պ�����
-------------------------------------------------------*/
void es_xmodem_start(void){             //�������������ڿ�ʼ�������ݡ�
    es_xmodem_pack=0;                   //�������š�
    es_xmodem_status=ES_XMODEM_READY;   //ת������̬��
    uart_char(ECBM_STREAM_UART,ES_XMODEM_NAK);     //����NACK��֪ͨ��λ����ʼͨ�š�
}
/*-------------------------------------------------------
���ݽ��պ�����
-------------------------------------------------------*/
void es_xmodem_exe(u8 dat){
    u8 i;
    switch(es_xmodem_status){
        case ES_XMODEM_READY:{//����״̬��
            if(dat==ES_XMODEM_SOH){                     //����յ�SOH�ֶΣ�
                es_xmodem_status=ES_XMODEM_READ_PACK;   //������ȡ����š�
                es_xmodem_sum=dat;                      //������Ϳ�ʼ����У��͡�
            }else if(dat==ES_XMODEM_EOT){               //����յ�EOT�ֶΣ�
                uart_char(ECBM_STREAM_UART,ES_XMODEM_ACK);//����ACK��֪ͨ��λ������EOT�ˡ�
                es_xmodem_status=ES_XMODEM_STOP;        //��ֹͣ״̬��
            }else if(dat==ES_XMODEM_CAN){               //����յ�CAN�ֶΣ�
                es_xmodem_status=ES_XMODEM_STOP;        //����ֹͣ״̬��
            }
        }break;
        case ES_XMODEM_READ_PACK:{//��ȡ����š�
            es_xmodem_pack=dat;                     //����ǰ�����ݰ���Ŵ��š�
            es_xmodem_sum+=dat;                     //����У��͡�
            es_xmodem_status=ES_XMODEM_CHECK_PACK;  //����ȷ�ϰ���š�
        }break;
        case ES_XMODEM_CHECK_PACK:{//ȷ�ϰ���š�
            if(es_xmodem_pack==(~dat)){                 //�����ŵķ�����ȷ��
                es_xmodem_status=ES_XMODEM_READ_MODE;   //����������ģʽ��
                es_xmodem_sum+=dat;                     //����У��͡�
                es_xmodem_count=0;                      //���û���ָ�롣
                if(ecbm_stream_start>=(ECBM_STREAM_SZIE-1)){//��ʵ�����ж�(start+1)>=szie�����ǻ����ж�size-1�Ļ����Թ��255+1������⡣
                    es_xmodem_buf_start=0;              //���ȷʵ����size�ˣ��ʹ�ͷ��ʼ��
                }else{                                  //����Ͷ�λ��һλ��
                    es_xmodem_buf_start=ecbm_stream_start+1;//��Ϊ��ǰ�ǰ���ŷ��룬��һλ�������ݡ�
                }
            }else{                                      //���벻��ȷ˵������֡ͷ��
                es_xmodem_status=ES_XMODEM_ERROR;       //��������̬��
            }            
        }break;
        case ES_XMODEM_READ_MODE:{//��������ģʽ��
            es_xmodem_sum+=dat;                         //����У��͡�
            es_xmodem_count++;                          //����ָ���һ��
            if(es_xmodem_count>=128){                   //���������128�����ݣ�
                es_xmodem_status=ES_XMODEM_CHECK_DATA;  //����������У�顣
            }                                           //���ݶ���stream��������ﲻ�ö��ⴢ�档
        }break;
        case ES_XMODEM_CHECK_DATA:{//���У��͡�
            if(dat==es_xmodem_sum){                     //���У����ȷ��
                for(i=0;i<128;i++){                     //X-modemͨ����һ������128�ֽڵ����ݡ�
                    es_xmodem_write_reg(es_xmodem_pack,i,ecbm_stream_buf[es_xmodem_buf_start]);//�����������뺯����������Щ���ݡ�
                    es_xmodem_buf_start++;                      //ÿ����һ�����ݣ�������+1��
                    if(es_xmodem_buf_start>=ECBM_STREAM_SZIE){  //��ȻҲҪ��ֹ�����
                        es_xmodem_buf_start=0;                  //��������㡣
                    }
                }
                uart_char(ECBM_STREAM_UART,ES_XMODEM_ACK);         //����ACK��֪ͨ��λ������һ����
            }else{                                      //���У�鲻��ȷ��
                uart_char(ECBM_STREAM_UART,ES_XMODEM_NAK);         //����NACK��֪ͨ��λ���ط���
            }           
            es_xmodem_status=ES_XMODEM_READY;           //������һ������һ֡�ʹ������ˣ��ָ�������̬��         
        }break;
    }
}
#endif  //���������#ifndef��ϳ�һ������Ρ�
        //��һ������Ϊ��β��