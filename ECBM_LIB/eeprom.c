#include "ecbm_core.h"
#if ECBM_EEPROM_EN
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
eeprom关闭函数。
-------------------------------------------------------*/
void eeprom_off(){
    IAP_CONTR = 0;   //关闭IAP功能
    IAP_CMD   = 0;   //清除命令寄存器
    IAP_TRIG  = 0;   //清除触发寄存器
    IAP_ADDRH = 0xff;//将地址设置到非IAP区域
    IAP_ADDRL = 0xff;//将地址设置到非IAP区域
}
/*-------------------------------------------------------
eeprom擦除函数。
-------------------------------------------------------*/
void eeprom_erase(u16 addr){
#if ECBM_EEPROM_SIZE_EN
	if(addr<ECBM_EEPROM_SIZE){		 //地址在范围内才会擦除
#else
	if(addr<EEPROM_SIZE){		     //地址在范围内才会擦除
#endif
		IAP_CONTR = EEPROM_WAIT|0x80;//使能IAP
		IAP_CMD   = 3;               //设置IAP擦除命令
		IAP_ADDRL = addr;            //设置IAP低地址
		IAP_ADDRH = addr >> 8;       //设置IAP高地址
		IAP_TRIG  = 0x5a;            //写触发命令(0x5a)
		IAP_TRIG  = 0xa5;            //写触发命令(0xa5)
		_nop_();                     //稍稍等待一下
		eeprom_off();                //关闭IAP功能
	}
}
/*-------------------------------------------------------
eeprom写函数。
-------------------------------------------------------*/
void eeprom_write(u16 addr,u8 dat){
#if ECBM_EEPROM_SIZE_EN
	if(addr<ECBM_EEPROM_SIZE){		 //地址在范围内才会写入
#else
	if(addr<EEPROM_SIZE){		     //地址在范围内才会写入
#endif
		IAP_CONTR = EEPROM_WAIT|0x80;//使能IAP
		IAP_CMD   = 2;               //设置IAP写命令
		IAP_ADDRL = addr;            //设置IAP低地址
		IAP_ADDRH = addr >> 8;       //设置IAP高地址
		IAP_DATA  = dat;             //写IAP数据
		IAP_TRIG  = 0x5a;            //写触发命令(0x5a)
		IAP_TRIG  = 0xa5;            //写触发命令(0xa5)
		_nop_();                     //稍稍等待一下
		eeprom_off();                //关闭IAP功能
	}
}
/*-------------------------------------------------------
eeprom读函数。
-------------------------------------------------------*/
u8 eeprom_read(u16 addr){
    u8 dat;
#if ECBM_EEPROM_SIZE_EN
	if(addr>=ECBM_EEPROM_SIZE)return 0xff;//地址超出之后，返回FF
#else
	if(addr>=EEPROM_SIZE)return 0xff;//地址超出之后，返回FF
#endif	
    IAP_CONTR = EEPROM_WAIT|0x80;    //使能IAP
    IAP_CMD   = 1;                   //设置IAP读命令
    IAP_ADDRL = addr;                //设置IAP低地址
    IAP_ADDRH = addr >> 8;           //设置IAP高地址
    IAP_TRIG  = 0x5a;                //写触发命令(0x5a)
    IAP_TRIG  = 0xa5;                //写触发命令(0xa5)
    _nop_();                         //稍稍等待一下
    dat       = IAP_DATA;            //读IAP数据
    eeprom_off();                    //关闭IAP功能
    return dat;
}
#endif
