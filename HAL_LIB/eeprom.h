#ifndef _ECBM_EEPROM_H_
#define _ECBM_EEPROM_H_
#include "ecbm.h"
//常用的eeprom扇区的快捷访问，最多可使用32K
#define sector0  0x0000
#define sector1  0x0200
#define sector2  0x0400
#define sector3  0x0600
#define sector4  0x0800
#define sector5  0x0A00
#define sector6  0x0C00
#define sector7  0x0E00
#define sector8  0x1000
#define sector9  0x1200
#define sector10 0x1400
#define sector11 0x1600
#define sector12 0x1800
#define sector13 0x1A00
#define sector14 0x1C00
#define sector15 0x1E00
#define sector16 0x2000
#define sector17 0x2200
#define sector18 0x2400
#define sector19 0x2600
#define sector20 0x2800
#define sector21 0x2A00
#define sector22 0x2C00
#define sector23 0x2E00
#define sector24 0x3000
#define sector25 0x3200
#define sector26 0x3400
#define sector27 0x3600
#define sector28 0x3800
#define sector29 0x3A00
#define sector30 0x3C00
#define sector31 0x3E00
#define sector32 0x4000
#define sector33 0x4200
#define sector34 0x4400
#define sector35 0x4600
#define sector36 0x4800
#define sector37 0x4A00
#define sector38 0x4C00
#define sector39 0x4E00
#define sector40 0x5000
#define sector41 0x5200
#define sector42 0x5400
#define sector43 0x5600
#define sector44 0x5800
#define sector45 0x5A00
#define sector46 0x5C00
#define sector47 0x5E00
#define sector48 0x6000
#define sector49 0x6200
#define sector50 0x6400
#define sector51 0x6600
#define sector52 0x6800
#define sector53 0x6A00
#define sector54 0x6C00
#define sector55 0x6E00
#define sector56 0x7000
#define sector57 0x7200
#define sector58 0x7400
#define sector59 0x7600
#define sector60 0x7800
#define sector61 0x7A00
#define sector62 0x7C00
#define sector63 0x7E00
__IO u8 xdata eeprom_wait_time;
u8 eeprom_init(){
	u8 sz;
	u16 pl;//通过查表知道当前的时钟频率对应的等待时间。STCISP工具提供的频率都符合下表的要求。
	u16 code max[8]={1167,2333,3500,7000,14000,23333,28000,50167};
	u16 code min[8]={833,1667,2500,5000,10000,16667,20000,35833};
	pl=(sys_clock/1000);
	for(sz=0;sz<8;sz++){
		if((pl>min[sz])&&(pl<max[sz])){
			eeprom_wait_time=0x80|(7-sz);
			return eeprom_wait_time;
		}
	}
	LED_ON;
	while(1);//如果用了非法的频率，那么就不能往下走。以保护eeprom功能为主。
}
void eeprom_off(){
    IAP_CONTR = 0;            //关闭IAP功能
    IAP_CMD = 0;              //清除命令寄存器
    IAP_TRIG = 0;             //清除触发寄存器
    IAP_ADDRH = 0xff;         //将地址设置到非IAP区域
    IAP_ADDRL = 0xff;
}
u8 eeprom_read(u16 addr){
    u8 dat;
		if(addr>=EEPROM_SIZE)return 0xff;		 //地址超出之后，返回FF
    IAP_CONTR = eeprom_wait_time;        //使能IAP
    IAP_CMD = 1;                         //设置IAP读命令
    IAP_ADDRL = addr;                    //设置IAP低地址
    IAP_ADDRH = addr >> 8;               //设置IAP高地址
    IAP_TRIG = 0x5a;                     //写触发命令(0x5a)
    IAP_TRIG = 0xa5;                     //写触发命令(0xa5)
    _nop_();
    dat = IAP_DATA;                      //读IAP数据
    eeprom_off();                    //关闭IAP功能

    return dat;
}
void eeprom_write(u16 addr, u8 dat){
		if(addr<EEPROM_SIZE){										//地址在范围内才会写入
			IAP_CONTR = eeprom_wait_time;         //使能IAP
			IAP_CMD = 2;                          //设置IAP写命令
			IAP_ADDRL = addr;                     //设置IAP低地址
			IAP_ADDRH = addr >> 8;                //设置IAP高地址
			IAP_DATA = dat;                       //写IAP数据
			IAP_TRIG = 0x5a;                      //写触发命令(0x5a)
			IAP_TRIG = 0xa5;                      //写触发命令(0xa5)
			_nop_();
			eeprom_off();                     //关闭IAP功能
		}
}
void eeprom_erase(u16 addr){
		if(addr<EEPROM_SIZE){										 //地址在范围内才会擦除
			IAP_CONTR = eeprom_wait_time;          //使能IAP
			IAP_CMD = 3;                           //设置IAP擦除命令
			IAP_ADDRL = addr;                      //设置IAP低地址
			IAP_ADDRH = addr >> 8;                 //设置IAP高地址
			IAP_TRIG = 0x5a;                       //写触发命令(0x5a)
			IAP_TRIG = 0xa5;                       //写触发命令(0xa5)
			_nop_();                               //
			eeprom_off();                      //关闭IAP功能
		}
}
#endif
