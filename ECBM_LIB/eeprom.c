#include "ecbm_core.h"
#if ECBM_EEPROM_EN
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
eeprom�رպ�����
-------------------------------------------------------*/
void eeprom_off(){
    IAP_CONTR = 0;   //�ر�IAP����
    IAP_CMD   = 0;   //�������Ĵ���
    IAP_TRIG  = 0;   //��������Ĵ���
    IAP_ADDRH = 0xff;//����ַ���õ���IAP����
    IAP_ADDRL = 0xff;//����ַ���õ���IAP����
}
/*-------------------------------------------------------
eeprom����������
-------------------------------------------------------*/
void eeprom_erase(u16 addr){
#if ECBM_EEPROM_SIZE_EN
	if(addr<ECBM_EEPROM_SIZE){		 //��ַ�ڷ�Χ�ڲŻ����
#else
	if(addr<EEPROM_SIZE){		     //��ַ�ڷ�Χ�ڲŻ����
#endif
		IAP_CONTR = EEPROM_WAIT|0x80;//ʹ��IAP
		IAP_CMD   = 3;               //����IAP��������
		IAP_ADDRL = addr;            //����IAP�͵�ַ
		IAP_ADDRH = addr >> 8;       //����IAP�ߵ�ַ
		IAP_TRIG  = 0x5a;            //д��������(0x5a)
		IAP_TRIG  = 0xa5;            //д��������(0xa5)
		_nop_();                     //���Եȴ�һ��
		eeprom_off();                //�ر�IAP����
	}
}
/*-------------------------------------------------------
eepromд������
-------------------------------------------------------*/
void eeprom_write(u16 addr,u8 dat){
#if ECBM_EEPROM_SIZE_EN
	if(addr<ECBM_EEPROM_SIZE){		 //��ַ�ڷ�Χ�ڲŻ�д��
#else
	if(addr<EEPROM_SIZE){		     //��ַ�ڷ�Χ�ڲŻ�д��
#endif
		IAP_CONTR = EEPROM_WAIT|0x80;//ʹ��IAP
		IAP_CMD   = 2;               //����IAPд����
		IAP_ADDRL = addr;            //����IAP�͵�ַ
		IAP_ADDRH = addr >> 8;       //����IAP�ߵ�ַ
		IAP_DATA  = dat;             //дIAP����
		IAP_TRIG  = 0x5a;            //д��������(0x5a)
		IAP_TRIG  = 0xa5;            //д��������(0xa5)
		_nop_();                     //���Եȴ�һ��
		eeprom_off();                //�ر�IAP����
	}
}
/*-------------------------------------------------------
eeprom��������
-------------------------------------------------------*/
u8 eeprom_read(u16 addr){
    u8 dat;
#if ECBM_EEPROM_SIZE_EN
	if(addr>=ECBM_EEPROM_SIZE)return 0xff;//��ַ����֮�󣬷���FF
#else
	if(addr>=EEPROM_SIZE)return 0xff;//��ַ����֮�󣬷���FF
#endif	
    IAP_CONTR = EEPROM_WAIT|0x80;    //ʹ��IAP
    IAP_CMD   = 1;                   //����IAP������
    IAP_ADDRL = addr;                //����IAP�͵�ַ
    IAP_ADDRH = addr >> 8;           //����IAP�ߵ�ַ
    IAP_TRIG  = 0x5a;                //д��������(0x5a)
    IAP_TRIG  = 0xa5;                //д��������(0xa5)
    _nop_();                         //���Եȴ�һ��
    dat       = IAP_DATA;            //��IAP����
    eeprom_off();                    //�ر�IAP����
    return dat;
}
#endif
