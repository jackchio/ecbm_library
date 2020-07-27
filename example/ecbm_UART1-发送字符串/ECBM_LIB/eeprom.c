#include "ecbm_core.h"
#if ECBM_EEPROM_EN
/*--------------------------------------变量定义-----------------------------------*/
u8 eeprom_wait;//EEPROM的等待时间。
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
eeprom初始化函数。
-------------------------------------------------------*/
void eeprom_init(void){
	#if  ((ECBM_MCU_MAIN_RAM == 0)||(ECBM_MCU_MAIN_RAM == 1))
	u32 pro,cls;
//7
	pro=ecbm_sys_clk/7;
	cls=ecbm_sys_clk/5000;
//	debug("s=%lu,p=%lu,c=%lu\r\n",ecbm_sys_clk,pro,cls);
	if((pro<166666)&&(pro>90909)&&(cls>111)&&(cls<250)){
		eeprom_wait=7;
		goto eep_end;
	}
//6
	pro=ecbm_sys_clk/14;
	cls=ecbm_sys_clk/10000;
//	debug("s=%lu,p=%lu,c=%lu\r\n",ecbm_sys_clk,pro,cls);
	if((pro<166666)&&(pro>90909)&&(cls>111)&&(cls<250)){
		eeprom_wait=6;
		goto eep_end;
	}
//5
	pro=ecbm_sys_clk/21;
	cls=ecbm_sys_clk/15000;
//	debug("s=%lu,p=%lu,c=%lu\r\n",ecbm_sys_clk,pro,cls);
	if((pro<166666)&&(pro>90909)&&(cls>111)&&(cls<250)){
		eeprom_wait=5;
		goto eep_end;
	}	
//4
	pro=ecbm_sys_clk/42;
	cls=ecbm_sys_clk/30000;
//	debug("s=%lu,p=%lu,c=%lu\r\n",ecbm_sys_clk,pro,cls);
	if((pro<166666)&&(pro>90909)&&(cls>111)&&(cls<250)){
		eeprom_wait=4;
		goto eep_end;
	}	
//3
	pro=ecbm_sys_clk/84;
	cls=ecbm_sys_clk/60000;
//	debug("s=%lu,p=%lu,c=%lu\r\n",ecbm_sys_clk,pro,cls);
	if((pro<166666)&&(pro>90909)&&(cls>111)&&(cls<250)){
		eeprom_wait=3;
		goto eep_end;
	}
//2
	pro=ecbm_sys_clk/140;
	cls=ecbm_sys_clk/100000;
//	debug("s=%lu,p=%lu,c=%lu\r\n",ecbm_sys_clk,pro,cls);
	if((pro<166666)&&(pro>90909)&&(cls>111)&&(cls<250)){
		eeprom_wait=2;
		goto eep_end;
	}	
//1
	pro=ecbm_sys_clk/168;
	cls=ecbm_sys_clk/120000;
//	debug("s=%lu,p=%lu,c=%lu\r\n",ecbm_sys_clk,pro,cls);
	if((pro<166666)&&(pro>90909)&&(cls>111)&&(cls<250)){
		eeprom_wait=1;
		goto eep_end;
	}
//0
	pro=ecbm_sys_clk/301;
	cls=ecbm_sys_clk/215000;
//	debug("s=%lu,p=%lu,c=%lu\r\n",ecbm_sys_clk,pro,cls);
	if((pro<166666)&&(pro>90909)&&(cls>111)&&(cls<250)){
		eeprom_wait=0;
		goto eep_end;
	}	
	eep_end:
	pro=0;
	cls=0;
//	debug("wait=%u\r\n",(u16)eeprom_wait);
	#elif ECBM_MCU_MAIN_RAM == 2
	eeprom_wait=ecbm_sys_clk/1000000;
	IAP_TPS=eeprom_wait;
	eeprom_wait=0;
	#endif
}
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
	if(addr<ECBM_EEPROM_SIZE){		 //地址在范围内才会擦除
		IAP_CONTR = eeprom_wait|0x80;//使能IAP
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
	if(addr<ECBM_EEPROM_SIZE){		 //地址在范围内才会写入
		IAP_CONTR = eeprom_wait|0x80;//使能IAP
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
	if(addr>=ECBM_EEPROM_SIZE)return 0xff;//地址超出之后，返回FF
    IAP_CONTR = eeprom_wait|0x80;    //使能IAP
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
#if ECBM_EEPROM_EX_EN
/*-------------------------------------------------------
eeprom读函数延伸版(extension)。
-------------------------------------------------------*/
void eeprom_read_ex(u16 addr,u8 * dat,u16 num){
	u16 i;
	for(i=0;i<num;i++){
		dat[i]=eeprom_read(addr+i);
	}
}
/*-------------------------------------------------------
eeprom写函数延伸版(extension)。
-------------------------------------------------------*/
void eeprom_write_ex(u16 addr,u8 * dat,u16 num){
	u8 xdata eeprom_buf[512];//用于整合数据的缓存
	u16 num_yu;				//剩余要写的数据的数量。
	u16 area;				//操作扇区。
	u16 area_addr_yu;		//扇区余下的地址数量。
	u16 area_start_addr;	//扇区开始地址。
	u16 area_stop_addr;		//扇区结束地址。
	u16 addr_offset;		//地址偏移。
	u16 dat_offset=0;		//数据偏移。
	u16 address;			//操作地址。
	u16 i;					//临时变量。
	address=addr;			//将地址参数赋值给操作地址。
	num_yu=num;				//将参数数量赋值为剩余数量。
	do{
		area=address>>9;						//获取扇区。
		area_start_addr=(area<<9);				//获取扇区开始的地址。
		area_stop_addr=(area<<9)+512;			//获取扇区末尾的地址。
		area_addr_yu=area_stop_addr-address;	//末尾地址减操作地址，得到地址剩余数量。
		if(num_yu<=area_addr_yu){				//如果要写的数少于地址剩余数量，说明不用跨扇区。
			for(i=0;i<512;i++){					//将原来的数据读出来。
				eeprom_buf[i]=eeprom_read(area_start_addr+i);
			}
			eeprom_erase(area_start_addr);		//清空扇区。
			addr_offset=address-area_start_addr;//获取地址偏移。
			for(i=0;i<num_yu;i++){				//修改数据。
				eeprom_buf[addr_offset+i]=dat[dat_offset+i];
			}
			for(i=0;i<512;i++){					//将数据写回去。
				eeprom_write(area_start_addr+i,eeprom_buf[i]);
			}
			break;								//写完就跳出循环。
		}else{									//如果要写的数多于地址剩余量。
			for(i=0;i<512;i++){					//将原来的数据读出来。
				eeprom_buf[i]=eeprom_read(area_start_addr+i);
			}
			eeprom_erase(area_start_addr);		//清空扇区。
			addr_offset=address-area_start_addr;//获取地址偏移。
			for(i=0;i<area_addr_yu;i++){		//修改数据。
				eeprom_buf[addr_offset+i]=dat[dat_offset+i];
			}
			for(i=0;i<512;i++){					//将数据写回去。
				eeprom_write(area_start_addr+i,eeprom_buf[i]);
			}
			address+=area_addr_yu;				//写了多少，地址就加多少。
			num_yu -=area_addr_yu;				//剩余数量就要减多少。
			dat_offset+=area_addr_yu;			//缓存的偏移就加多少。
		}
	}while(1);	
}
#endif
#endif
