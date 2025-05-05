#include "ecbm_core.h"  //ͳһ���غ���ͷ�ļ�
#if (ECBM_EEPROM_LIB_EN)      //��鱾����û�б�ʹ��
/*---------------------------------------�궨��------------------------------------*/
#if     (ECBM_SYSCLK_SETTING == 5529600UL)//����ϵͳʱ����ѡ��ϵ����
#   define ECBM_EEPROM_WAIT_TIME   (4)
#elif   (ECBM_SYSCLK_SETTING == 6000000UL)
#   define ECBM_EEPROM_WAIT_TIME   (4)
#elif   (ECBM_SYSCLK_SETTING == 11059200UL)
#   define ECBM_EEPROM_WAIT_TIME   (3)
#elif   (ECBM_SYSCLK_SETTING == 12000000UL)
#   define ECBM_EEPROM_WAIT_TIME   (3)
#elif   (ECBM_SYSCLK_SETTING == 18432000UL)
#   define ECBM_EEPROM_WAIT_TIME   (2)
#elif   (ECBM_SYSCLK_SETTING == 20000000UL)
#   define ECBM_EEPROM_WAIT_TIME   (2)
#elif   (ECBM_SYSCLK_SETTING == 22118400UL)
#   define ECBM_EEPROM_WAIT_TIME   (2)
#elif   (ECBM_SYSCLK_SETTING == 24000000UL)
#   define ECBM_EEPROM_WAIT_TIME   (1)
#elif   (ECBM_SYSCLK_SETTING == 26000000UL)
#   define ECBM_EEPROM_WAIT_TIME   (1)
#elif   (ECBM_SYSCLK_SETTING == 27000000UL)
#   define ECBM_EEPROM_WAIT_TIME   (1)
#elif   (ECBM_SYSCLK_SETTING == 30000000UL)
#   define ECBM_EEPROM_WAIT_TIME   (0)
#elif   (ECBM_SYSCLK_SETTING == 33000000UL)
#   define ECBM_EEPROM_WAIT_TIME   (0)
#elif   (ECBM_SYSCLK_SETTING == 33177600UL)
#   define ECBM_EEPROM_WAIT_TIME   (0)
#elif   (ECBM_SYSCLK_SETTING == 35000000UL)
#   define ECBM_EEPROM_WAIT_TIME   (0)
#elif   (ECBM_SYSCLK_SETTING == 36864000UL)
#   define ECBM_EEPROM_WAIT_TIME   (0)
#elif   (ECBM_SYSCLK_SETTING == 40000000UL)
#   define ECBM_EEPROM_WAIT_TIME   (0)
#elif   (ECBM_SYSCLK_SETTING == 44236800UL)
#   define ECBM_EEPROM_WAIT_TIME   (0)
#elif   (ECBM_SYSCLK_SETTING == 45000000UL)
#   define ECBM_EEPROM_WAIT_TIME   (0)
#elif   (ECBM_SYSCLK_SETTING == 45158400UL)
#   define ECBM_EEPROM_WAIT_TIME   (0)
#endif
/*--------------------------------------��������-----------------------------------*/
#if (ECBM_EEPROM_EX_EN)
    u8 xdata eeprom_ex_buf_gxu8a[512];//�����������ݵĻ���
#endif
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
eeprom�رպ�����
-------------------------------------------------------*/
void eeprom_off(void){
    IAP_SET_REG_CONTR(0);       //�ر�IAP����
    IAP_CMD_NOP;                //�������Ĵ���
    IAP_TRIG_CLS;               //��������Ĵ���
    IAP_SET_REG_ADDR_H8(0xff);  //����ַ���õ���IAP����
    IAP_SET_REG_ADDR_L8(0xff);  //����ַ���õ���IAP����
}
/*-------------------------------------------------------
eeprom��ʼ��������
-------------------------------------------------------*/
void eeprom_init(void){
    #if  (((ECBM_MCU&0xF00000)>0x200000)||(ECBM_MCU==0x2815C4))
        IAP_TPS=ECBM_SYSCLK_SETTING/1000000;
    #endif
    eeprom_off();
}
/*-------------------------------------------------------
eeprom����������
-------------------------------------------------------*/
void eeprom_erase(u16 addr){
    IAP_SET_REG_CONTR(ECBM_EEPROM_WAIT_TIME|IAP_EN);//ʹ��IAP
    IAP_CMD_ERASE;              //����IAP��������
    IAP_SET_REG_ADDR_HL(addr);  //����IAP��ַ
    IAP_TRIG_ON;                //��������
    _nop_();_nop_();_nop_();_nop_();_nop_();_nop_();//���Եȴ�һ��
    _nop_();_nop_();_nop_();_nop_();_nop_();_nop_();//���Եȴ�һ��
    eeprom_off();               //�ر�IAP����
}
/*-------------------------------------------------------
eepromд������
-------------------------------------------------------*/
void eeprom_write(u16 addr,u8 dat){
    IAP_SET_REG_CONTR(ECBM_EEPROM_WAIT_TIME|IAP_EN);//ʹ��IAP
    IAP_CMD_WRITE;              //����IAPд����
    IAP_SET_REG_ADDR_HL(addr);  //����IAP��ַ
    IAP_SET_REG_DATA(dat);      //дIAP����
    IAP_TRIG_ON;                //��������
    _nop_();_nop_();_nop_();_nop_();_nop_();_nop_();//���Եȴ�һ��
    _nop_();_nop_();_nop_();_nop_();_nop_();_nop_();//���Եȴ�һ��
    eeprom_off();               //�ر�IAP����
}
/*-------------------------------------------------------
eeprom��������
-------------------------------------------------------*/
u8 eeprom_read(u16 addr){
    u8 dat_u8;
    IAP_SET_REG_CONTR(ECBM_EEPROM_WAIT_TIME|IAP_EN);    //ʹ��IAP
    IAP_CMD_READ;               //����IAP������
    IAP_SET_REG_ADDR_HL(addr);  //����IAP��ַ
    IAP_TRIG_ON;                //��������
    _nop_();_nop_();_nop_();_nop_();_nop_();_nop_();//���Եȴ�һ��
    _nop_();_nop_();_nop_();_nop_();_nop_();_nop_();//���Եȴ�һ��
    dat_u8=IAP_GET_REG_DATA;    //��IAP����
    eeprom_off();               //�ر�IAP����
    return dat_u8;
}

/*-------------------------------------------------------
eeprom�����������(extension)��
-------------------------------------------------------*/
#if (ECBM_EEPROM_EX_EN)
    void eeprom_read_ex(u16 addr,u8 * dat,u16 num){
        u16 i_u16;
        for(i_u16=0;i_u16<num;i_u16++){
            dat[i_u16]=eeprom_read(addr+i_u16);
        }
    }
#endif
/*-------------------------------------------------------
eepromд���������(extension)��
-------------------------------------------------------*/
#if (ECBM_EEPROM_EX_EN)
    void eeprom_write_ex(u16 addr,u8 * dat,u16 num){
        u16 num_yu_u16;         //ʣ��Ҫд�����ݵ�������
        u16 area_u16;           //����������
        u16 area_addr_yu_u16;   //�������µĵ�ַ������
        u16 area_start_addr_u16;//������ʼ��ַ��
        u16 area_stop_addr_u16; //����������ַ��
        u16 addr_offset_u16;    //��ַƫ�ơ�
        u16 dat_offset_u16=0;   //����ƫ�ơ�
        u16 address_u16;        //������ַ��
        u16 i_u16;              //��ʱ������
        address_u16=addr;       //����ַ������ֵ��������ַ��
        num_yu_u16=num;         //������������ֵΪʣ��������
        do{
            area_u16=address_u16>>9;                    //��ȡ������
            area_start_addr_u16=(area_u16<<9);          //��ȡ������ʼ�ĵ�ַ��
            area_stop_addr_u16=(area_u16<<9)+512;       //��ȡ����ĩβ�ĵ�ַ��
            area_addr_yu_u16=area_stop_addr_u16-address_u16;//ĩβ��ַ��������ַ���õ���ַʣ��������
            if(num_yu_u16<=area_addr_yu_u16){           //���Ҫд�������ڵ�ַʣ��������˵�����ÿ�������
                for(i_u16=0;i_u16<512;i_u16++){             //��ԭ�������ݶ�������
                    eeprom_ex_buf_gxu8a[i_u16]=eeprom_read(area_start_addr_u16+i_u16);
                }
                eeprom_erase(area_start_addr_u16);      //���������
                addr_offset_u16=address_u16-area_start_addr_u16;//��ȡ��ַƫ�ơ�
                for(i_u16=0;i_u16<num_yu_u16;i_u16++){              //�޸����ݡ�
                    eeprom_ex_buf_gxu8a[addr_offset_u16+i_u16]=dat[dat_offset_u16+i_u16];
                }
                for(i_u16=0;i_u16<512;i_u16++){                 //������д��ȥ��
                    eeprom_write(area_start_addr_u16+i_u16,eeprom_ex_buf_gxu8a[i_u16]);
                }
                break;                              //д�������ѭ����
            }else{                                  //���Ҫд�������ڵ�ַʣ������
                for(i_u16=0;i_u16<512;i_u16++){                 //��ԭ�������ݶ�������
                    eeprom_ex_buf_gxu8a[i_u16]=eeprom_read(area_start_addr_u16+i_u16);
                }
                eeprom_erase(area_start_addr_u16);      //���������
                addr_offset_u16=address_u16-area_start_addr_u16;//��ȡ��ַƫ�ơ�
                for(i_u16=0;i_u16<area_addr_yu_u16;i_u16++){        //�޸����ݡ�
                    eeprom_ex_buf_gxu8a[addr_offset_u16+i_u16]=dat[dat_offset_u16+i_u16];
                }
                for(i_u16=0;i_u16<512;i_u16++){                 //������д��ȥ��
                    eeprom_write(area_start_addr_u16+i_u16,eeprom_ex_buf_gxu8a[i_u16]);
                }
                address_u16   +=area_addr_yu_u16;   //д�˶��٣���ַ�ͼӶ��١�
                num_yu_u16    -=area_addr_yu_u16;   //ʣ��������Ҫ�����١�
                dat_offset_u16+=area_addr_yu_u16;   //�����ƫ�ƾͼӶ��١�
            }
        }while(1);
    }
#endif
#endif  //���������#ifndef��ϳ�һ������Ρ�
        //��һ������Ϊ��β��