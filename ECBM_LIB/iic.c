#include "ecbm_core.h"  //ͳһ���غ���ͷ�ļ�
#if (ECBM_IIC_LIB_EN)      //��鱾����û�б�ʹ��
/*--------------------------------------��������-----------------------------------*/
bit iic_master_busy_gb;
u8 xdata iic_index_gxu8;
bit eiicp_trig_gb;                         
u8  eiicp_data_count_gu8; 
u8  eiicp_data_buf_gu8a[ECBM_IIC_BUF_MAX]; 
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
IIC���������ú�����
-------------------------------------------------------*/
void iic_set_pin(u8 group){
    #if ((ECBM_MCU==0x310201)||(ECBM_MCU==0x3102A1))
        switch(group){
            case IIC_PIN_P32_P33:{//�л���D32��D33
                P3M1|=0x0C;//0000 1100 IIC��������Ҫ�ǿ�©ģʽ
                P3M0|=0x0C;//0000 1100 IIC��������Ҫ�ǿ�©ģʽ
                P3PU|=0x0C;//0000 1100 IIC��Ҫһ����������       
            }break;
            case IIC_PIN_P54_P55:{//�л���D54��D55
                P5M1|=0x30;//0011 0000 IIC��������Ҫ�ǿ�©ģʽ
                P5M0|=0x30;//0011 0000 IIC��������Ҫ�ǿ�©ģʽ
                P5PU|=0x30;//0011 0000 IIC��Ҫһ����������
            }break;
            default:break;
        }    
    #else
        switch(group){
            case IIC_PIN_P15_P14:{//�л���D14��D15
                P1M1|=0x30;//0011 0000 IIC��������Ҫ�ǿ�©ģʽ
                P1M0|=0x30;//0011 0000 IIC��������Ҫ�ǿ�©ģʽ
                P1PU|=0x30;//0011 0000 IIC��Ҫһ����������       
            }break;
            case IIC_PIN_P25_P24:{//�л���D24��D25
                P2M1|=0x30;//0011 0000 IIC��������Ҫ�ǿ�©ģʽ
                P2M0|=0x30;//0011 0000 IIC��������Ҫ�ǿ�©ģʽ
                P2PU|=0x30;//0011 0000 IIC��Ҫһ����������
            }break;
            case IIC_PIN_P77_P76:{//�л���D76��D77
                P7M1|=0xC0;//1100 0000 IIC��������Ҫ�ǿ�©ģʽ
                P7M0|=0xC0;//1100 0000 IIC��������Ҫ�ǿ�©ģʽ
                P7PU|=0xC0;//1100 0000 IIC��Ҫһ����������
            }break;
            case IIC_PIN_P32_P33:{//�л���D32��D33
                P3M1|=0x0C;//0000 1100 IIC��������Ҫ�ǿ�©ģʽ
                P3M0|=0x0C;//0000 1100 IIC��������Ҫ�ǿ�©ģʽ
                P3PU|=0x0C;//0000 1100 IIC��Ҫһ����������
            }break;
            default:break;
        }
    #endif
    IIC_SET_PIN(group);
}
/*-------------------------------------------------------
IIC���������ú����������棩��
-------------------------------------------------------*/
void iic_set_pin_linkage(u8 group){
    if(iic_index_gxu8!=group){
        iic_index_gxu8=group;
        IIC_POWER_OFF;
        IIC_SET_PIN(group);
        IIC_POWER_ON;
    }
}
/*-------------------------------------------------------
IIC�����Ż�ԭ������
-------------------------------------------------------*/
void iic_reset_pin(u8 group){
    #if ((ECBM_MCU==0x310201)||(ECBM_MCU==0x3102A1))
        switch(group){
            case IIC_PIN_P32_P33:{//��ԭD32��D33
                P3M1&=~0x0C;//1111 0011 ��ԭ����ģʽ
                P3M0&=~0x0C;//1111 0011 ��ԭ����ģʽ
                P3PU&=~0x0C;//1111 0011 ȥ����������       
            }break;
            case IIC_PIN_P54_P55:{//��ԭD54��D55
                P5M1&=~0x30;//1100 1111 ��ԭ����ģʽ
                P5M0&=~0x30;//1100 1111 ��ԭ����ģʽ
                P5PU&=~0x30;//1100 1111 ȥ����������
            }break;
            default:break;
        }    
    #else
        switch(group){
            case IIC_PIN_P15_P14:{//��ԭD14��D15
                P1M1&=~0x30;//1100 1111 ��ԭ����ģʽ
                P1M0&=~0x30;//1100 1111 ��ԭ����ģʽ
                P1PU&=~0x30;//1100 1111 ȥ����������      
            }break;
            case IIC_PIN_P25_P24:{//��ԭD24��D25
                P2M1&=~0x30;//1100 1111 ��ԭ����ģʽ
                P2M0&=~0x30;//1100 1111 ��ԭ����ģʽ
                P2PU&=~0x30;//1100 1111 ȥ����������
            }break;
            case IIC_PIN_P77_P76:{//��ԭD76��D77
                P7M1&=~0xC0;//0011 1111 ��ԭ����ģʽ
                P7M0&=~0xC0;//0011 1111 ��ԭ����ģʽ
                P7PU&=~0xC0;//0011 1111 ȥ����������
            }break;
            case IIC_PIN_P32_P33:{//��ԭD32��D33
                P3M1&=~0x0C;//1111 0011 ��ԭ����ģʽ
                P3M0&=~0x0C;//1111 0011 ��ԭ����ģʽ
                P3PU&=~0x0C;//1111 0011 ȥ����������
            }break;
            default:break;
        }
    #endif
}
/*-------------------------------------------------------
IIC������ʼ��������
-------------------------------------------------------*/
void iic_master_init(void){
    u8 res_u8=63;
    res_u8=(u8)(((ECBM_SYSCLK_SETTING/2/ECBM_IIC_WAIT)-4)/2);//�����ʱ������Ĳ�����
    IIC_SET_SPEED(res_u8);      //�ȴ�ʱ�ӡ�
    iic_set_master_mode();      //����Ϊ������
    iic_set_pin(ECBM_IIC_IO);
    iic_index_gxu8=ECBM_IIC_IO; //���浱ǰ�õ���index�š�
    IIC_POWER_ON;               //����IIC��
}
/*-------------------------------------------------------
IIC�ӻ���ʼ��������
-------------------------------------------------------*/
void iic_slave_init(void){
    u8 res_u8=63;
    res_u8=(u8)(((ECBM_SYSCLK_SETTING/2/ECBM_IIC_WAIT)-4)/2);//�����ʱ������Ĳ�����
    IIC_SET_SPEED(res_u8);      //�ȴ�ʱ�ӡ�
    #if (ECBM_EIICP_EN)
        IIC_SET_REG_SLADR(0xEC);//���ôӻ���ַ��
    #else 
        #if (ECBM_IIC_SLAVE_ADDR_EN)
            IIC_SET_REG_SLADR(ECBM_IIC_SLAVE_ADDR<<1);//���ôӻ���ַΪ����ҳ��ĵ�ַ��
        #else
            IIC_SET_REG_SLADR(0x01);//���ôӻ���ַΪ0��ͬʱD0��һȡ����ַɸѡ��
        #endif
    #endif
    iic_set_slave_mode();       //����Ϊ�ӻ���
    iic_set_pin(ECBM_IIC_IO);
    iic_index_gxu8=ECBM_IIC_IO; //���浱ǰ�õ���index�š�
    IIC_POWER_ON;               //����IIC��
}
/*-------------------------------------------------------
IIC��������������
-------------------------------------------------------*/
void iic_set_master_mode(void){
    IIC_SET_REG_SLCR(1);//�ر����н����жϡ�
    IIC_SET_REG_MSST(0);//�������������־λ��
    IIC_SET_MODE_MASTER;//����Ϊ������
    //�������ڷ���ָ������ݵ�ʱ����λ�����жϣ��������ﲻ��ʹ�ܷ��͵��жϡ�
}
/*-------------------------------------------------------
��IIC���ôӻ�������
-------------------------------------------------------*/
void iic_set_slave_mode(void){
    IIC_SET_REG_MSCR(0);    //�ر����з����жϡ�
    IIC_SET_REG_SLST(0);    //������дӻ���־λ��
    IIC_SET_MODE_SLAVE;     //����Ϊ�ӻ���
    IIC_SET_REG_SLCR(0x78); //�����н����жϡ� 
}
/*-------------------------------------------------------
IIC�ĸ��ֲ��������������������Э�����Ų���
iic_start     :��ʼ��������ӦIIC��ʼ֡��
iic_stop      :ֹͣ��������ӦIICֹͣ֡��
iic_write     :д���ݺ�������������д1�ֽ����ݡ�
iic_write_ack :дACK��������������дһ��ACK��
iic_write_nack:дNO ACK��������������дһ��NO ACK��
iic_read      :�����ݺ�������ȡ������һ���ֽڵ����ݡ�
iic_read_ack  :��ACK��������ȡ�������Ƿ���ACK��
-------------------------------------------------------*/
void iic_start(void){
    u16 timeout_u16=ECBM_IIC_TIMEOUT;
    iic_master_busy_gb=1;
    IIC_CMD_START;//����START����
    while(iic_master_busy_gb&&(timeout_u16--));
}
void iic_stop(void){
    u16 timeout_u16=ECBM_IIC_TIMEOUT;
    iic_master_busy_gb = 1;
    IIC_CMD_STOP;//����STOP����
    while(iic_master_busy_gb&&(timeout_u16--));
}
void iic_write(u8 dat){
    u16 timeout_u16=ECBM_IIC_TIMEOUT;
    IIC_SET_REG_DATA(dat);//д���ݵ����ݻ�����
    iic_master_busy_gb=1;
    IIC_CMD_TX_DATA;//����SEND����
    while(iic_master_busy_gb&&(timeout_u16--));
}
void iic_write_ack(void){
    u16 timeout_u16=ECBM_IIC_TIMEOUT;
    iic_master_busy_gb=1;
    IIC_CMD_TX_ACK; //����ACK����
    while(iic_master_busy_gb&&(timeout_u16--));
}
void iic_write_nack(void){
    u16 timeout_u16=ECBM_IIC_TIMEOUT;
    iic_master_busy_gb=1;
    IIC_CMD_TX_NACK; //����ACK����
    while(iic_master_busy_gb&&(timeout_u16--));
}
u8 iic_read(void){
    u16 timeout_u16=ECBM_IIC_TIMEOUT;
    iic_master_busy_gb=1;
    IIC_CMD_RX_DATA;  //����RECV����
    while(iic_master_busy_gb&&(timeout_u16--));
    return IIC_GET_REG_DATA;
}
bit iic_read_ack(void){
    u16 timeout_u16=ECBM_IIC_TIMEOUT;
    iic_master_busy_gb=1;
    IIC_CMD_RX_ACK; //���Ͷ�ACK����
    while(iic_master_busy_gb&&(timeout_u16--));
    return IIC_GET_ACK>>1;
}
/*-------------------------------------------------------
EIICP����ģʽ�������ͺ�����
-------------------------------------------------------*/
#if (ECBM_EIICP_EN)
void eiicp_master_base(u8 target_id,u8 operate,u16 addr,u8 * dat,u8 len){
    u16 timeout_u16=ECBM_IIC_TIMEOUT;
    u8 temp[8],i;
    iic_set_master_mode();          //����Ϊ������
    //��һ��������������ʶ��
    //�ڶ���������Ŀ��ID��
    temp[0]=target_id;
    //�����������ͱ���ID��
    temp[1]=eiicp_get_id();
    //���Ĳ������Ͳ����롣
    temp[2]=operate;
    //���岽�����͵�ַ��24~31��
    temp[3]=0;//����32λ��ַ�Ǹ�32λ��Ԥ���ģ����﷢��0��
    //�����������͵�ַ��16~23��
    temp[4]=0;//����32λ��ַ�Ǹ�32λ��Ԥ���ģ����﷢��0��
    //���߲������͵�ַ��8~15��   
    temp[5]=(u8)(addr>>8);
    //�ڰ˲������͵�ַ��0~7��      
    temp[6]=(u8)(addr); 
    //�ھŲ����������ݵĳ��ȡ�  
    temp[7]=len;

    iic_master_busy_gb=1;           //æ��־λ��λ������IIC������Ӳ�����ͣ��ʹ����ִ��λ�����첽�ģ����Ҫ����æ��־λ������ȷ�ĺ��������������̡�
    IIC_SET_REG_DATA(0xEC);         //����������ʶ��
    IIC_CMD_START_TXDATA_RXACK;     //����START+WRITE+readACK����
    while(iic_master_busy_gb&&(timeout_u16--));//�ȴ�æ��־λ���㡣
    for(i=0;i<8;i++){
        iic_master_busy_gb=1;       //æ��־λ��λ��
        IIC_SET_REG_DATA(temp[i]);  //�������ݰ���
        IIC_CMD_TXDATA_RXACK;       //�������ݲ���ACK��
        while(iic_master_busy_gb&&(timeout_u16--));//�ȴ�æ��־λ���㡣
    }
    //��ʮ����ѭ���������ݡ�
    if(operate==EIICP_CMD_WRITE){
        for(i=0;i<len;i++){
            iic_master_busy_gb=1;       //æ��־λ��λ��
            IIC_SET_REG_DATA(dat[i]);   //�������ݡ�
            IIC_CMD_TXDATA_RXACK;       //�������ݲ���ACK��
            while(iic_master_busy_gb&&(timeout_u16--));//�ȴ�æ��־λ���㡣
        }
    }
    //������
    iic_master_busy_gb=1;           //æ��־λ��λ��
    IIC_CMD_STOP;
    while(iic_master_busy_gb&&(timeout_u16--));//�ȴ�æ��־λ���㡣
    iic_set_slave_mode();//����Ϊ�ӻ���
}
/*-------------------------------------------------------
EIICP����ģʽ����������
-------------------------------------------------------*/
void eiicp_master_trig(u8 target_id,u16 addr){
    eiicp_master_base(target_id,EIICP_CMD_TRIG,addr,(u8 *)(0),0);
}
/*-------------------------------------------------------
EIICP����ģʽд������
-------------------------------------------------------*/
void eiicp_master_write(u8 target_id,u16 addr,u8 * dat,u8 len){
    eiicp_master_base(target_id,EIICP_CMD_WRITE,addr,dat,len);
}
/*-------------------------------------------------------
EIICP����ģʽ��������
-------------------------------------------------------*/
void eiicp_master_read(u8 target_id,u16 addr,u8 len){
    eiicp_master_base(target_id,EIICP_CMD_READ,addr,(u8 *)(0),len);
}
/*-------------------------------------------------------
EIICPЭ�����������
-------------------------------------------------------*/
void eiicp_main(void){
    u8  id_u8,len_u8,operate_u8;
    u16 i_u16,addr_u16;
    if(eiicp_trig_gb){
        eiicp_trig_gb=0;
        if(eiicp_data_buf_gu8a[0]==0xEC){//���ж��ǲ���EIICPЭ��ı�ʶ��
            if(eiicp_data_buf_gu8a[1]==eiicp_get_id()){ //�ٿ����ǲ��Ǵ�����������Ϣ��
                //���ڽ������Ḵ�û������飬���Եðѹؼ���Ϣ����ȡ������
                id_u8     =eiicp_data_buf_gu8a[2];  //����Է���ID��
                operate_u8=eiicp_data_buf_gu8a[3];  //�����������
                addr_u16  =(u16)(eiicp_data_buf_gu8a[6])*256+(u16)(eiicp_data_buf_gu8a[7]);//�ѵ�ַƴ�á�
                len_u8    =eiicp_data_buf_gu8a[8];  //�������ݳ��ȡ�
                switch(operate_u8){//���ݲ��������������
                    case EIICP_CMD_TRIG:{//����
                        eiicp_base_reg_trig(addr_u16);//���ûص�������
                        eiicp_master_base(id_u8,EIICP_CMD_TRIG_REPLY,addr_u16,(u8 *)(0),0);//��������ͨ�š�
                    }break;
                    case EIICP_CMD_TRIG_REPLY:{//�����ظ�
                        eiicp_master_trig_callback(addr_u16);//���ûص�������
                    }break;
                    case EIICP_CMD_READ:{//��ȡ
                        for(i_u16=0;i_u16<(u16)(len_u8);i_u16++){
                            eiicp_data_buf_gu8a[i_u16]=eiicp_base_reg_read(addr_u16+i_u16);//���ûص�������
                        }
                        eiicp_master_base(id_u8,EIICP_CMD_READ_REPLY,addr_u16,eiicp_data_buf_gu8a,len_u8);
                    }break;
                    case EIICP_CMD_READ_REPLY:{//��ȡ�ظ���
                        for(i_u16=0;i_u16<(u16)(len_u8);i_u16++){
                            eiicp_master_read_callback(addr_u16+i_u16,eiicp_data_buf_gu8a[9+i_u16]);//���ûص�������
                        }
                    }break;
                    case EIICP_CMD_WRITE:{//д�롣
                        for(i_u16=0;i_u16<(u16)(len_u8);i_u16++){
                            eiicp_base_reg_write(addr_u16+i_u16,eiicp_data_buf_gu8a[9+i_u16]);
                        }
                        eiicp_master_base(id_u8,EIICP_CMD_WRITE_REPLY,addr_u16,(u8 *)(0),0);
                    }break;
                    case EIICP_CMD_WRITE_REPLY:{//д��ظ���
                        eiicp_master_write_callback(addr_u16);
                    }break;
                }
            }
        }
    }
}
#endif
#endif  //���������#ifndef��ϳ�һ������Ρ�
        //��һ������Ϊ��β��