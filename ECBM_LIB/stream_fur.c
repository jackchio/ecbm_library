#include "ecbm_core.h"  //ͳһ���غ���ͷ�ļ�
#if (ECBM_10MS_EN)&&(ECBM_STREAM_LIB_EN)&&(ECBM_STREAM_FUR_CH_COUNT)    //��鱾����û�б�ʹ��
/*--------------------------------------��������-----------------------------------*/
u8  es_fur_status_gu8a [ECBM_STREAM_FUR_CH_COUNT];
u16 es_fur_addr_gu16a  [ECBM_STREAM_FUR_CH_COUNT];
u16 es_fur_dat16_gu16a [ECBM_STREAM_FUR_CH_COUNT];
u8  es_fur_id_gu8a     [ECBM_STREAM_FUR_CH_COUNT];
u8  es_fur_dat8_gu8a   [ECBM_STREAM_FUR_CH_COUNT];
u8  es_fur_operate_gu8a[ECBM_STREAM_FUR_CH_COUNT];
u8  es_fur_temp8_gu8a  [ECBM_STREAM_FUR_CH_COUNT];
/*--------------------------------------������-----------------------------------*/
u8 ecbm_stream_fur_chtoid(u8 ch){
    switch(ch){
        case 1:return (0);break;
        case 2:return ( ECBM_STREAM_CH1_EN*ECBM_STREAM_FUR_CH1_EN);break;
        case 3:return ((ECBM_STREAM_CH1_EN*ECBM_STREAM_FUR_CH1_EN)+(ECBM_STREAM_CH2_EN*ECBM_STREAM_FUR_CH2_EN));break;
        case 4:return ((ECBM_STREAM_CH1_EN*ECBM_STREAM_FUR_CH1_EN)+(ECBM_STREAM_CH2_EN*ECBM_STREAM_FUR_CH2_EN)+(ECBM_STREAM_CH3_EN*ECBM_STREAM_FUR_CH3_EN));break;
    }
    return (0);
}
/*-------------------------------------------------------
FUR���ú�����
-------------------------------------------------------*/
void es_fur_reset(u8 ch){
    u8 id_u8;
    id_u8=ecbm_stream_fur_chtoid(ch);
    es_fur_status_gu8a [id_u8]=FUR_GET_ADDR;//һ�㶼��Ҫ���յ�ʱ������ã��������ú󵽽��յ�ַ״̬��
    es_fur_addr_gu16a  [id_u8]=0;           //FUR��ַ���㡣
    es_fur_dat16_gu16a [id_u8]=0;           //FUR���ݣ�16λ�����㡣
    es_fur_id_gu8a     [id_u8]=0;           //FUR��ID��ʱ�������㡣
    es_fur_dat8_gu8a   [id_u8]=0;           //FUR���ݣ�8λ�����㡣
    es_fur_operate_gu8a[id_u8]=0;           //FUR���������㡣
    es_fur_temp8_gu8a  [id_u8]=0;           //FUR��ʱ������8λ�����㡣
}
/*-------------------------------------------------------
FUR�������ݺ�������10���Ƶĸ�ʽ���͡�
-------------------------------------------------------*/
void es_fur_send_num_10(u8 ch,u16 num){
    u8 a_u8,b_u8,c_u8,d_u8,e_u8;
    a_u8=num       /10000;
    b_u8=num%10000/1000;
    c_u8=num%1000/100;
    d_u8=num%100/10;
    e_u8=num%10/1;
    if(a_u8)                uart_char(ch,a_u8+'0');
    if(a_u8|b_u8)           uart_char(ch,b_u8+'0');
    if(a_u8|b_u8|c_u8)      uart_char(ch,c_u8+'0');
    if(a_u8|b_u8|c_u8|d_u8) uart_char(ch,d_u8+'0');
                            uart_char(ch,e_u8+'0');
}
/*-------------------------------------------------------
FUR�������ݺ�������16���Ƶĸ�ʽ���͡�
-------------------------------------------------------*/
void es_fur_send_num_16(u8 ch,u16 num){
    u8 i_u8;
    u16 temp_u16;
    temp_u16=num;
    for(i_u8=0;i_u8<4;i_u8++){
        if((temp_u16&0xF000)<0xA000){
            uart_char(ch,'0'+(temp_u16&0xF000)>>12);
        }else{
            uart_char(ch,'A'+((temp_u16&0xF000)>>12)-10);
        }
        temp_u16<<=4;
    }
}
/*-------------------------------------------------------
FUR����ִ�к�����
-------------------------------------------------------*/
void es_fur_exe(u8 ch,u8 dat){
    u16 temp_u16,mask_u16;
    u8  operate_u8,id_u8;
    id_u8=ecbm_stream_fur_chtoid(ch);
    switch(es_fur_status_gu8a[id_u8]){
        case FUR_READY:{    //����״̬��
            //ɶҲ������
        }break;
        case FUR_GET_ADDR:{ //���յ�ַ״̬��
            if((dat>='0')&&(dat<='9')){    //����յ�����0~9��
                es_fur_addr_gu16a[id_u8]*=10;           //�ճ�һλ��
                es_fur_addr_gu16a[id_u8]+=(dat-'0');    //���ַ�ת�������ַ���ճ�����һλ�ϡ�
            }else if(dat=='@'){            //��Ҫ�ǽ��յ�@��˵����ID���ݡ�
                es_fur_status_gu8a[id_u8]=FUR_GET_ID;  //��ת������ID״̬��
            }else if((dat==']')||(dat==')')){//����յ�]����)��˵����ַ�Ѿ�������ϡ�
                es_fur_status_gu8a[id_u8]=FUR_GET_OP;  //��ת�����ղ���״̬��
            }else if((dat=='i')||(dat=='I')){//����յ���Сд��i�����ߴ�д��I��
                es_fur_status_gu8a[id_u8]=FUR_CMD_ID;  //˵�������ǲ�ID��ָ���ת����ID״̬��
            }else{                         //������յ������ַ���˵�����ճ����ˡ�
                es_fur_status_gu8a[id_u8]=FUR_READY;   //�ص�����״̬��
            }
        }break;
        case FUR_CMD_ID:{   //��ID״̬��
            if((dat=='d')||(dat=='D')){    //�����״̬�£�ֻ�ж��ǲ���ID�����Ǿ�����ȥ��
                es_fur_operate_gu8a[id_u8]|=FUR_FBID;  //��λ��ѯID��
            }else if(dat==']'){            //����յ�]��˵��ָ���Ѿ�������ϡ�
                es_fur_status_gu8a[id_u8]=FUR_GET_OP;  //��ת�����ղ���״̬��
            }else{                         //������յ������ַ���˵�����ճ����ˡ�
                es_fur_status_gu8a[id_u8]=FUR_READY;   //�ص�����״̬��
            }
        }break;
        case FUR_GET_ID:{   //����ID״̬��
            if((dat>='0')&&(dat<='9')){    //����յ�����0~9��
                es_fur_id_gu8a[id_u8]*=10;             //�ճ�һλ��
                es_fur_id_gu8a[id_u8]+=(dat-'0');      //���ַ�ת�������ַ���ճ�����һλ�ϡ�
            }else if(dat==']'){            //����յ�]��˵��ID�Ѿ�������ϡ�
                es_fur_status_gu8a[id_u8]=FUR_GET_OP;  //��ת�����ղ���״̬��
            }else{                         //������յ������ַ���˵�����ճ����ˡ�
                es_fur_status_gu8a[id_u8]=FUR_READY;   //�ص�����״̬��
            }
        }break;
        case FUR_GET_OP:{   //���ղ�����״̬��
            if(dat=='+'){                      //����յ�+�ţ�
                es_fur_operate_gu8a[id_u8]|=FUR_ADD;       //ִ�мӲ�����
                es_fur_status_gu8a [id_u8] =FUR_GET_OP_EX; //������չ����״̬��
            }else if(dat=='-'){                //����յ�-�ţ�
                es_fur_operate_gu8a[id_u8]|=FUR_DEC;       //ִ�м�������
                es_fur_status_gu8a [id_u8] =FUR_GET_OP_EX; //������չ����״̬��
            }else if(dat=='*'){                //����յ�*�ţ�
                es_fur_operate_gu8a[id_u8]|=FUR_MUL;       //ִ�г˲�����
                es_fur_status_gu8a [id_u8] =FUR_GET_OP_EX; //������չ����״̬��
            }else if(dat=='/'){                //����յ�/�ţ�
                es_fur_operate_gu8a[id_u8]|=FUR_DIV;       //ִ�г�������
                es_fur_status_gu8a [id_u8] =FUR_GET_OP_EX; //������չ����״̬��
            }else if(dat=='&'){                //����յ�&�ţ�
                es_fur_operate_gu8a[id_u8]|=FUR_AND;       //ִ���������
                es_fur_status_gu8a [id_u8] =FUR_GET_OP_EX; //������չ����״̬��
            }else if(dat=='|'){                //����յ�|�ţ�
                es_fur_operate_gu8a[id_u8]|=FUR_OR;        //ִ�л������
                es_fur_status_gu8a [id_u8] =FUR_GET_OP_EX; //������չ����״̬��
            }else if(dat=='^'){                //����յ�^�ţ�
                es_fur_operate_gu8a[id_u8]|=FUR_XOR;       //ִ����������
                es_fur_status_gu8a [id_u8] =FUR_GET_OP_EX; //������չ����״̬��
            }else if(dat=='.'){                //����յ�.�ţ�
                es_fur_operate_gu8a[id_u8]|=FUR_BIT;       //ִ��λ������
                es_fur_status_gu8a [id_u8] =FUR_GET_OP_EX; //������չ����״̬��
            }else if(dat=='='){                //����յ�=�ţ�
                es_fur_operate_gu8a[id_u8]|=FUR_EQU;       //ִ�и�ֵ������
                es_fur_status_gu8a [id_u8] =FUR_GET_DATA;  //������������״̬��ʮ���ƣ���
            }else if(dat=='x'){                //����������յ�x��������ʮ�����ơ�
                es_fur_operate_gu8a[id_u8]|=FUR_HEX;       //��λ��Ӧ�ı�־λ��������Ҫ��ת������״̬��
            }else if(dat=='?'){                //����յ�?�ţ�
                es_fur_operate_gu8a[id_u8]|=FUR_READ;      //ִ�ж�ȡ������
                es_fur_status_gu8a [id_u8] =FUR_WAIT_END;  //�����ȴ�����̬��
            }else{                             //������յ������ַ���˵�����ճ����ˡ�
                es_fur_status_gu8a[id_u8]=FUR_READY;       //�ص�����״̬��
            }
        }break;
        case FUR_GET_OP_EX:{//������չ����״̬��Ŀǰ���ǽ���λ������λ��ŵģ���
            if((dat>='0')&&(dat<='9')){        //����յ�����0~9��
                es_fur_dat8_gu8a[id_u8]*=10;               //�ճ�һλ��
                es_fur_dat8_gu8a[id_u8]+=(dat-'0');        //���ַ�ת�������ַ���ճ�����һλ�ϡ�
            }else if(dat=='='){                //����յ�=�ţ�
                es_fur_dat8_gu8a[id_u8]&=0x0F;             //���Ƹò������ܳ���15��Ȼ�������������
                es_fur_status_gu8a[id_u8]=FUR_GET_DATA;    //������������״̬��ʮ���ƣ���
            }else{                             //������յ������ַ���˵�����ճ����ˡ�
                es_fur_status_gu8a[id_u8]=FUR_READY;       //�ص�����״̬��
            }
        }break;
        case FUR_GET_DATA:{ //��������״̬��ʮ���ƣ���
            if((dat>='0')&&(dat<='9')){        //����յ�����0~9��
                es_fur_dat16_gu16a[id_u8]*=10;              //�ճ�һλ��
                es_fur_dat16_gu16a[id_u8]+=(dat-'0');       //���ַ�ת�������ַ���ճ�����һλ�ϡ�
            }else if(dat==';'){                //����յ���������
                es_fur_status_gu8a[id_u8]=FUR_END_DO;      //��������̬��
            }else if((dat=='x')||(dat=='X')){  //����յ�����x��˵������Ҫ�յ�16��������
                es_fur_dat16_gu16a[id_u8]=0;                //���16λ���ݱ�����
                es_fur_operate_gu8a[id_u8]|=FUR_HEX;       //������ͨ����16���Ʊ�ʾ��
                es_fur_status_gu8a[id_u8]=FUR_GET_DATA16;  //������������״̬��ʮ�����ƣ���
            }else{                             //������յ������ַ���˵�����ճ����ˡ�
                es_fur_status_gu8a[id_u8]=FUR_READY;       //�ص�����״̬��
            }
        }break;
        case FUR_GET_DATA16:{//��������״̬��ʮ�����ƣ���
            if((dat>='0')&&(dat<='9')){        //����յ�����0~9��
                es_fur_dat16_gu16a[id_u8]*=16;              //�ճ�4bit��
                es_fur_dat16_gu16a[id_u8]+=(dat-'0');       //���ַ�ת�������ַ���ճ���λ�ϡ�
            }else if((dat>='a')&&(dat<='f')){  //����յ�����Сд����ĸ��
                es_fur_dat16_gu16a[id_u8]*=16;         
                es_fur_dat16_gu16a[id_u8]+=(dat-'a'+10);    //������һ������ת���ַ���
            }else if((dat>='A')&&(dat<='F')){  //����յ����Ǵ�д����ĸ��
                es_fur_dat16_gu16a[id_u8]*=16;
                es_fur_dat16_gu16a[id_u8]+=(dat-'A'+10);    //������һ������ת���ַ���
            }else if(dat==';'){                //����յ���������
                es_fur_status_gu8a[id_u8]=FUR_END_DO;      //��������̬��
            }else{                             //������յ������ַ���˵�����ճ����ˡ�
                es_fur_status_gu8a[id_u8]=FUR_READY;       //�ص�����״̬��
            }
        }break;
        case FUR_WAIT_END:{ //�ȴ�������״̬��
            if(dat==';'){                      //����յ���������
                es_fur_status_gu8a[id_u8]=FUR_END_DO;      //������̬��
            }
        }break;
    }
    if(es_fur_status_gu8a[id_u8]==FUR_END_DO){     //���ڽ���̬��ʱ�򣬿�ʼ����ָ�
        operate_u8=es_fur_operate_gu8a[id_u8]&0x0F;
        if(operate_u8==FUR_FBID){//��ID�ǲ���Ҫ���ID�ģ��������ж������
            #if (ECBM_STREAM_FUR_UART_SEND_EN)
                uart_char(ch,'i');
                uart_char(ch,'d');
                uart_char(ch,'=');
                es_fur_send_num_10(ch,(u16)es_fur_get_id(ch));
                uart_char(ch,';');
                uart_char(ch,'\r');
                uart_char(ch,'\n');
            #endif
        }else{//���˲�ѯIDָ���⣬ʣ�µ�ָ���Ҫ��ID���бȽϡ�
            if( (es_fur_id_gu8a[id_u8]==0)||//����ǹ㲥��
                (es_fur_id_gu8a[id_u8]==es_fur_get_id(ch))){//����ID��ƥ���ϡ�
                temp_u16=es_fur_read_reg(ch,es_fur_addr_gu16a[id_u8]);
                if(es_fur_operate_gu8a[id_u8]&FUR_WRITE){   //�����֡���������������ģ�
                    switch(operate_u8){            //����ָ��������������صļĴ�����
                        case FUR_READ://���Ĵ�����
                            //ɶ����������
                        break;
                        case FUR_ADD://�Ĵ�������һ������
                            temp_u16+=es_fur_dat16_gu16a[id_u8];
                        break;
                        case FUR_DEC://�Ĵ�����ȥһ������
                            temp_u16-=es_fur_dat16_gu16a[id_u8];
                        break;
                        case FUR_MUL://�Ĵ�������һ������
                            temp_u16*=es_fur_dat16_gu16a[id_u8];
                        break;
                        case FUR_DIV://�Ĵ�������һ������
                            temp_u16/=es_fur_dat16_gu16a[id_u8];
                        break;
                        case FUR_AND://�Ĵ�������һ������
                            temp_u16&=es_fur_dat16_gu16a[id_u8];
                        break;
                        case FUR_OR://�Ĵ�������һ������
                            temp_u16|=es_fur_dat16_gu16a[id_u8];
                        break;
                        case FUR_XOR://�Ĵ��������һ������
                            temp_u16^=es_fur_dat16_gu16a[id_u8];
                        break;
                        case FUR_BIT://�Ĵ���λ��ֵ��
                            mask_u16=1<<es_fur_dat8_gu8a[id_u8];
                            if(es_fur_dat16_gu16a[id_u8]){
                                temp_u16|=mask_u16;
                            }else{
                                temp_u16&=~mask_u16;
                            }
                        break;
                        case FUR_EQU://�Ĵ�����ֵ��
                            temp_u16=es_fur_dat16_gu16a[id_u8];
                        break;
                    }
                    es_fur_write_reg(ch,es_fur_addr_gu16a[id_u8],temp_u16);
                    #if (ECBM_STREAM_FUR_UART_SEND_EN)
                        uart_char(ch,'(');
                        es_fur_send_num_10(ch,es_fur_addr_gu16a[id_u8]);
                        uart_char(ch,')');
                        uart_char(ch,'=');
                        if(es_fur_operate_gu8a[id_u8]&FUR_HEX){
                            uart_char(ch,'0');
                            uart_char(ch,'x');
                            es_fur_send_num_16(ch,temp_u16);
                        }else{
                            es_fur_send_num_10(ch,temp_u16);
                        }
                        uart_char(ch,';');
                        uart_char(ch,'\r');
                        uart_char(ch,'\n');
                    #endif
                }else{//�����֡�����Ǵӻ����صģ�
                    #if (ECBM_STREAM_FUR_MATER_EN)
                        es_fur_master_receive_callback(ch,es_fur_addr_gu16a,es_fur_dat16_gu16a);//ִ�дӻ����ջص���
                    #endif
                }
            }
        }
        es_fur_status_gu8a[id_u8]=FUR_READY;        //������ϣ�������״̬��
    }
    if(dat=='['){                       //�κ�ʱ������յ��˿�ʼ���[��
        es_fur_reset(ch);                 //�͵�������fur��
        es_fur_operate_gu8a[id_u8]|=FUR_WRITE;      //�ٴ���д���־��
    }else if(dat=='('){                 //������յ����Ǵӻ��������ݱ��(��
        es_fur_reset(ch);                 //��ֻ����fur��
    }
}
/*-------------------------------------------------------
FUR�������ͺ�����
-------------------------------------------------------*/
#if (ECBM_STREAM_FUR_MATER_EN)
    void es_fur_master_send(u8 ch,u16 addr,u8 id,u16 dat){
        uart_char(ch,'[');
        es_fur_send_num_10(ch,addr);
        if(id){
            uart_char(ch,'@');
            es_fur_send_num_10(ch,id);
        }
        uart_char(ch,']');
        uart_char(ch,'=');
        es_fur_send_num_10(ch,dat);
        uart_char(ch,';');
        uart_char(ch,'\r');
        uart_char(ch,'\n');
    }
#endif
/*-------------------------------------------------------
FUR������ȡ������
-------------------------------------------------------*/
#if (ECBM_STREAM_FUR_MATER_EN)
    void es_fur_master_read(u8 ch,u16 addr,u8 id){
        uart_char(ch,'[');
        es_fur_send_num_10(ch,addr);
        if(id){
            uart_char(ch,'@');
            es_fur_send_num_10(ch,id);
        }
        uart_char(ch,']');
        uart_char(ch,'?');
        uart_char(ch,';');
        uart_char(ch,'\r');
        uart_char(ch,'\n');
    }
#endif
#endif  //���������#ifndef��ϳ�һ������Ρ�
        //��һ������Ϊ��β��