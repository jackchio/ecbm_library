#include "at24cxx.h"
/*--------------------------------------变量定义-----------------------------------*/
u8 xdata at24_model=0;
/*--------------------------------------程序定义-----------------------------------*/
/*程序区折叠专用*************************通用模块*******************************/#if 1
/*-------------------------------------------------------
设置工作状态函数，将一个器件设置为工作状态。
-------------------------------------------------------*/
void at24_set_work(at24_def * dev){
	soft_iic_set_pin_linkage(dev->id,dev->scl,dev->sda);//把当前器件信息切换到IIC的当前设置。	
	at24_model=dev->model;								//把当前器件型号切换到AT24的当前设置。
}
/*-------------------------------------------------------
AT24CXX系列的初始化函数。
-------------------------------------------------------*/
void at24_init(at24_def * dev,u8 model,u8 scl,u8 sda){
	dev->scl=scl;							//将SCL引脚保存。
	dev->sda=sda;							//将SDA引脚保存。
	dev->model=model;					    //将型号信息保存。
	dev->id=soft_iic_init_linkage(scl,sda);	//初始化引脚。
	at24_set_work(dev);						//切换控制器到当前器件。
}
/*-------------------------------------------------------
AT24系列的写函数，支持多个数据写入。
-------------------------------------------------------*/
u8 at24_write(u16 addr,u8 dat[],u16 num){
	u32 i;			//for循环专用。
	u32 addr_max;	//地址的最大值。
	u32 num_max;	//可写入的数量。
	
	u16 sector_old;	//上一次的扇区。
	u8 sector_size; //扇区的大小
	u8 iic_addr;	//IIC的地址。
	
	switch(at24_model&0xF0){//通过型号变量来判断地址最大值。
		case AT24CXX :{
			return AT24_ERROR_INIT;//返回错误码-初始化错误。
		}break;
		case AT24C01 :{
			addr_max=128;//AT24C01最多有128个字节的空间。
			iic_addr=AT24_ADDR+(at24_model&0x07);
			sector_size=8;
		}break;
		case AT24C02 :{
			addr_max=256;//AT24C02最多有256个字节的空间。
			iic_addr=AT24_ADDR+(at24_model&0x07);
			sector_size=16;
		}break;
		case AT24C04 :{
			addr_max=512;//AT24C04最多有512个字节的空间。
			iic_addr=AT24_ADDR+(at24_model&0x06)+(u8)(addr>>8);
			sector_size=16;
		}break;
		case AT24C08 :{
			addr_max=1024;//AT24C08最多有1024个字节的空间。
			iic_addr=AT24_ADDR+(at24_model&0x04)+(u8)(addr>>8);
			sector_size=16;
		}break;
		case AT24C16 :{
			addr_max=2048;//AT24C16最多有2048个字节的空间。
			iic_addr=AT24_ADDR+(u8)(addr>>8);
			sector_size=16;
		}break;
		case AT24C32 :{
			addr_max=4096;//AT24C16最多有2048个字节的空间。
			iic_addr=AT24_ADDR+(at24_model&0x07);
			sector_size=32;
		}break;
		case AT24C64 :{
			addr_max=8192;//AT24C16最多有2048个字节的空间。
			iic_addr=AT24_ADDR+(at24_model&0x07);
			sector_size=32;
		}break;
		case AT24C128:{
			addr_max=16384;//AT24C16最多有2048个字节的空间。
			iic_addr=AT24_ADDR+(at24_model&0x07);
			sector_size=32;
		}break;
		case AT24C256:{
			addr_max=32768;//AT24C16最多有2048个字节的空间。
			iic_addr=AT24_ADDR+(at24_model&0x07);
			sector_size=32;
		}break;
		case AT24C512:{
			addr_max=65536;//AT24C16最多有65536个字节的空间。
			iic_addr=AT24_ADDR+(at24_model&0x07);
			sector_size=32;
		}break;
	}
	if(addr>addr_max){			//如果初始地址就超过了最大值，
		return AT24_ERROR_ADDR;	//返回错误码-地址错误。
	}
	if(((u32)addr+(u32)num)>addr_max){	//如果是地址溢出，
		num_max=addr_max-(u32)addr;	//减少写入数据，防止溢出。
	}else{
		num_max=(u32)num;			//没溢出就全写进去。
	}
	sector_old=addr/sector_size;		//计算扇区。
//	debug("W=%02X\r\n",(u16)(iic_addr<<1));//调试用。
	soft_iic_start();			//IIC开始。
	soft_iic_write(iic_addr<<1);	//先写IIC器件地址。
	if(soft_iic_read_ack()!=0){	//读ACK。
		soft_iic_stop();		//IIC停止。
		return AT24_ERROR_NOACK;//如果没有ACK，说明器件不存在。返回错误码-无回应错误。
	}
	if(sector_size==32){
		soft_iic_write(addr/256);	//再写EEPROM内存地址。
		if(soft_iic_read_ack()!=0){	//读ACK。
			soft_iic_stop();		//IIC停止。
			return AT24_ERROR_NOACK;//如果没有ACK，说明器件不存在。返回错误码-无回应错误。
		}
	}
	soft_iic_write(addr%256);	//再写EEPROM内存地址。
	if(soft_iic_read_ack()!=0){	//读ACK。
		soft_iic_stop();		//IIC停止。
		return AT24_ERROR_NOACK;//如果没有ACK，说明器件不存在。返回错误码-无回应错误。
	}
	for(i=0;i<num_max;i++){		//开始传输数据。
		if(sector_old!=(((u32)addr+i)/sector_size)){	//假如跳扇区了，
			sector_old=(((u32)addr+i)/sector_size);	//更新扇区信息。
			soft_iic_stop();	//IIC停止。
			
			switch(at24_model&0xF0){//重新计算地址。
				case AT24C01 :{
					iic_addr=AT24_ADDR+(at24_model&0x07);
				}break;
				case AT24C02 :{
					iic_addr=AT24_ADDR+(at24_model&0x07);
				}break;
				case AT24C04 :{
					iic_addr=AT24_ADDR+(at24_model&0x06)+(u8)((addr+i)>>8);
				}break;
				case AT24C08 :{
					iic_addr=AT24_ADDR+(at24_model&0x04)+(u8)((addr+i)>>8);
				}break;
				case AT24C16 :{
					iic_addr=AT24_ADDR+(u8)((addr+i)>>8);
				}break;
				case AT24C32 :{
					iic_addr=AT24_ADDR+(at24_model&0x07);
				}break;
				case AT24C64 :{
					iic_addr=AT24_ADDR+(at24_model&0x07);
				}break;
				case AT24C128:{
					iic_addr=AT24_ADDR+(at24_model&0x07);
				}break;
				case AT24C256:{
					iic_addr=AT24_ADDR+(at24_model&0x07);
				}break;
				case AT24C512:{
					iic_addr=AT24_ADDR+(at24_model&0x07);
				}break;
			}
//			debug("W=%02X-%02X(%02d)\r\n",(u16)iic_addr,(addr+i)%256,sector);//调试用。
			delay_ms(10);		//手册上的缓存写入时间（最大值）。
			soft_iic_start();	//IIC开始。
			soft_iic_write(iic_addr<<1);//先写IIC器件地址。
			if(soft_iic_read_ack()!=0){	//读ACK。
				soft_iic_stop();		//IIC停止。
				return AT24_ERROR_NOACK;//如果没有ACK，说明器件不存在。返回错误码-无回应错误。
			}
			if(sector_size==32){
				soft_iic_write((addr+i)/256);	//再写EEPROM内存地址。
				if(soft_iic_read_ack()!=0){	//读ACK。
					soft_iic_stop();		//IIC停止。
					return AT24_ERROR_NOACK;//如果没有ACK，说明器件不存在。返回错误码-无回应错误。
				}
			}
			soft_iic_write((addr+i)%256);
			if(soft_iic_read_ack()!=0){	//读ACK。
				soft_iic_stop();		//IIC停止。
				return AT24_ERROR_NOACK;//如果没有ACK，说明器件不存在。返回错误码-无回应错误。
			}
		}
		soft_iic_write(dat[i]);	//写入数据。
		if(soft_iic_read_ack()!=0){	//读ACK。
			soft_iic_stop();		//IIC停止。
			return AT24_ERROR_SEND;//如果没有ACK，说明通信出了问题。返回错误码-发送错误。
		}
	}	
	soft_iic_stop();//IIC停止。
	if(((u32)addr+(u32)num)>addr_max){	 //如果地址有溢出的风险，
		return AT24_ERROR_NUMBER;//返回错误码-数量错误。
	}
	return AT24_OK;//啥错都没有就返回正常。
}
/*-------------------------------------------------------
AT24系列的读函数，支持多个数据读取。
-------------------------------------------------------*/
u8 at24_read(u16 addr,u8 dat[],u16 num){
    u32 i;			//for循环专用。
	u32 addr_max;	//地址的最大值。
	u32 num_max;	//可写入的数量。
	u8 iic_addr;	//IIC的地址。
	switch(at24_model&0xF0){//通过型号变量来判断地址最大值。
		case AT24CXX :{
			return AT24_ERROR_INIT;//返回错误码-初始化错误。
		}break;
		case AT24C01 :{
			addr_max=128;//AT24C01最多有128个字节的空间。
			iic_addr=AT24_ADDR+(at24_model&0x07);
		}break;
		case AT24C02 :{
			addr_max=256;//AT24C02最多有256个字节的空间。
			iic_addr=AT24_ADDR+(at24_model&0x07);
		}break;
		case AT24C04 :{
			addr_max=512;//AT24C04最多有512个字节的空间。
			iic_addr=AT24_ADDR+(at24_model&0x06)+(u8)(addr>>8);
		}break;
		case AT24C08 :{
			addr_max=1024;//AT24C08最多有1024个字节的空间。
			iic_addr=AT24_ADDR+(at24_model&0x04)+(u8)(addr>>8);
		}break;
		case AT24C16 :{
			addr_max=2048;//AT24C16最多有2048个字节的空间。
			iic_addr=AT24_ADDR+(u8)(addr>>8);
		}break;
		case AT24C32 :{
			addr_max=4096;//AT24C16最多有2048个字节的空间。
			iic_addr=AT24_ADDR+(at24_model&0x07);
		}break;
		case AT24C64 :{
			addr_max=8192;//AT24C16最多有2048个字节的空间。
			iic_addr=AT24_ADDR+(at24_model&0x07);
		}break;
		case AT24C128:{
			addr_max=16384;//AT24C16最多有2048个字节的空间。
			iic_addr=AT24_ADDR+(at24_model&0x07);
		}break;
		case AT24C256:{
			addr_max=32768;//AT24C16最多有2048个字节的空间。
			iic_addr=AT24_ADDR+(at24_model&0x07);
		}break;
		case AT24C512:{
			addr_max=65536;//AT24C16最多有65536个字节的空间。
			iic_addr=AT24_ADDR+(at24_model&0x07);
		}break;
	}
	if(addr>addr_max){			//如果初始地址就超过了最大值，
		return AT24_ERROR_ADDR;	//返回错误码-地址错误。
	}
	if(((u32)addr+(u32)num)>addr_max){	//如果是地址溢出，
		num_max=addr_max-(u32)addr;	//减少写入数据，防止溢出。
	}else{
		num_max=(u32)num;			//没溢出就全写进去。
	}
//	debug("R=%02X-%02X\r\n",(u16)iic_addr,addr%256);//调试用。
 	soft_iic_start();			//IIC开始。
	soft_iic_write(iic_addr<<1);	//先写IIC器件地址。
	if(soft_iic_read_ack()!=0){	//读ACK。
		soft_iic_stop();		//IIC停止。
		return AT24_ERROR_NOACK;//如果没有ACK，说明器件不存在。返回错误码-无回应错误。
	}
	if(addr_max>2048){
		soft_iic_write(addr/256);	//再写EEPROM内存地址。
		if(soft_iic_read_ack()!=0){	//读ACK。
			soft_iic_stop();		//IIC停止。
			return AT24_ERROR_NOACK;//如果没有ACK，说明器件不存在。返回错误码-无回应错误。
		}
	}
	soft_iic_write(addr%256);
	if(soft_iic_read_ack()!=0){	//读ACK。
		soft_iic_stop();		//IIC停止。
		return AT24_ERROR_NOACK;//如果没有ACK，说明器件不存在。返回错误码-无回应错误。
	}
	soft_iic_start();			//IIC重新开始，这是读动作的需求。
	soft_iic_write((iic_addr<<1)+1);	//写IIC器件地址，并设置读取位。
	for(i=0;i<num_max;i++){		//开始读取数据。
		soft_iic_write_ack();	//发送一个ACK，表示连续读。
		dat[i]=soft_iic_read();	//读取数据。
	}
	soft_iic_write_nack();//停止读取了就发送NOACK。
	soft_iic_stop();//IIC停止。
	if((addr+num)>addr_max){	 //如果地址有溢出的风险，
		return AT24_ERROR_NUMBER;//返回错误码-数量错误。
	}
	return AT24_OK;//啥错都没有就返回正常。
}
/*程序区折叠专用**************************************************************/#endif
/*程序区折叠专用*************************全写模块***********/#if AT24CXX_WRITE_ALL_EN
/*-------------------------------------------------------
AT24系列的全写函数。
-------------------------------------------------------*/
void at24_write_all(void){
	u16 max;//循环最大值。
	u16 i,j;//两层for循环的临时变量。
	u8 re;      //操作结果缓存。
	u8 buf[128];//操作缓存。
	switch(at24_model&0xF0){//根据型号来选择。
		default      :max= 0 ;debug("model=unkonw\r\n" ) ;break;//未知型号。
		case AT24C01 :max= 1 ;debug("model=AT24C01\r\n") ;break;//AT24C01， 容量是1  *128=128  字节。
		case AT24C02 :max= 2 ;debug("model=AT24C02\r\n") ;break;//AT24C02， 容量是2  *128=256  字节。
		case AT24C04 :max= 4 ;debug("model=AT24C04\r\n") ;break;//AT24C04， 容量是4  *128=512  字节。
		case AT24C08 :max= 8 ;debug("model=AT24C08\r\n") ;break;//AT24C08， 容量是8  *128=1024 字节。
		case AT24C16 :max=16 ;debug("model=AT24C16\r\n") ;break;//AT24C16， 容量是16 *128=2048 字节。
		case AT24C32 :max=32 ;debug("model=AT24C32\r\n") ;break;//AT24C32， 容量是32 *128=4096 字节。
		case AT24C64 :max=64 ;debug("model=AT24C64\r\n") ;break;//AT24C64， 容量是64 *128=8192 字节。
		case AT24C128:max=128;debug("model=AT24C128\r\n");break;//AT24C128，容量是128*128=16384字节。
		case AT24C256:max=256;debug("model=AT24C256\r\n");break;//AT24C256，容量是256*128=32768字节。
		case AT24C512:max=512;debug("model=AT24C512\r\n");break;//AT24C512，容量是512*128=65536字节。
	}
	for(i=0;i<max;i++){//循环写入eeprom芯片。
		for(j=0;j<128;j++){//由于空间比较大，以128字节为一块来写入。
			buf[j]=i;//每块的值由当前的i来决定。
		}
		delay_ms(10);//写入与写入之间都要有至少10ms的延时。
		re=at24_write(i*128,buf,128);//写入数据。
		switch(re){//根据返回的结果，解析写入的结果。
			case AT24_OK          :debug("%03u-Ok!\r\n",          i);break;//写入成功。
			case AT24_ERROR_INIT  :debug("%03u-Init error!\r\n",  i);break;//初始化错误。
			case AT24_ERROR_NOACK :debug("%03u-Noack error!\r\n", i);break;//器件未回复。
			case AT24_ERROR_SEND  :debug("%03u-Send error!\r\n",  i);break;//发送失败。
			case AT24_ERROR_ADDR  :debug("%03u-Addr error!\r\n",  i);break;//地址错误。
			case AT24_ERROR_NUMBER:debug("%03u-Number error!\r\n",i);break;//发送数量错误。
		}
	}
}
/*程序区折叠专用**************************************************************/#endif
/*程序区折叠专用*************************全读模块************/#if AT24CXX_READ_ALL_EN
/*-------------------------------------------------------
AT24系列的全读函数。
-------------------------------------------------------*/
void at24_read_all(void){
	u16 max;//循环最大值。
	u16 i,j,k;//三个for循环的临时变量。
	u8 buf[128];//操作缓存。
	switch(at24_model&0xF0){//根据型号来选择。
		default      :max= 0 ;debug("model=unkonw\r\n" ) ;break;//未知型号。
		case AT24C01 :max= 1 ;debug("model=AT24C01\r\n") ;break;//AT24C01， 容量是1  *128=128  字节。
		case AT24C02 :max= 2 ;debug("model=AT24C02\r\n") ;break;//AT24C02， 容量是2  *128=256  字节。
		case AT24C04 :max= 4 ;debug("model=AT24C04\r\n") ;break;//AT24C04， 容量是4  *128=512  字节。
		case AT24C08 :max= 8 ;debug("model=AT24C08\r\n") ;break;//AT24C08， 容量是8  *128=1024 字节。
		case AT24C16 :max=16 ;debug("model=AT24C16\r\n") ;break;//AT24C16， 容量是16 *128=2048 字节。
		case AT24C32 :max=32 ;debug("model=AT24C32\r\n") ;break;//AT24C32， 容量是32 *128=4096 字节。
		case AT24C64 :max=64 ;debug("model=AT24C64\r\n") ;break;//AT24C64， 容量是64 *128=8192 字节。
		case AT24C128:max=128;debug("model=AT24C128\r\n");break;//AT24C128，容量是128*128=16384字节。
		case AT24C256:max=256;debug("model=AT24C256\r\n");break;//AT24C256，容量是256*128=32768字节。
		case AT24C512:max=512;debug("model=AT24C512\r\n");break;//AT24C512，容量是512*128=65536字节。
	}
	if(max){//如果是未知型号，就不用再读取了。
		debug("      00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F\r\n");  //绘出一个表格。
		debug("-------------------------------------------------------\r\n");//表格的分割线。
		for(k=0;k<max;k++){//循环读取芯片。
			for(i=0;i<128;i++){
				buf[i]=0;//清缓存。
			}
			at24_read(k*128,buf,128);//读取128字节的数据，和写入缓存的数量对应。
			for(i=0;i<8;i++){//由于为了和写入对应搞的128字节缓存，以16字节一行，128字节就是8行。
				debug("%04X: ",k*128+(i<<4));//每行以地址开头。
				for(j=0;j<16;j++){//一行显示16字节的数据。
					debug("%02X ",(u16)buf[i*16+j]);//以HEX形式显示。
				}
				debug("|");//分隔符。
				for(j=0;j<16;j++){//以ASCII码形式再显示一遍。
					if((buf[i*16+j]>=32)&&(buf[i*16+j]<=127)){//只发送能显示的ASCII码。
						debug("%c",buf[i*16+j]);
					}else{//不能显示的ASCII码都发空格。
						debug(" ");
					}
				}
				debug("\r\n");
			}
		}
		debug("-------------------------------------------------------\r\n");//表格的底线。
		debug("total:%lu\r\n",((u32)k*128));//读取总数统计。
	}
}
/*程序区折叠专用**************************************************************/#endif
/*程序区折叠专用***********************自动初始化模块********/#if AT24CXX_AUTO_INIT_EN
/*-------------------------------------------------------
AT24系列单字节地址型号的写函数，只为了check函数存在。
-------------------------------------------------------*/
u8 at24_write_char(u8 iic,u8 addr,u8 dat){
	soft_iic_start();			//IIC开始。
	soft_iic_write(iic);	//先写IIC器件地址。
	if(soft_iic_read_ack()!=0){	//读ACK。
		soft_iic_stop();		//IIC停止。
		return AT24_ERROR_NOACK;//如果没有ACK，说明器件不存在。返回错误码-无回应错误。
	}
	soft_iic_write(addr);	//再写EEPROM内存地址。
	if(soft_iic_read_ack()!=0){	//读ACK。
		soft_iic_stop();		//IIC停止。
		return AT24_ERROR_NOACK;//如果没有ACK，说明器件不存在。返回错误码-无回应错误。
	}
	soft_iic_write(dat);	//写入数据。
	if(soft_iic_read_ack()!=0){	//读ACK。
		soft_iic_stop();		//IIC停止。
		return AT24_ERROR_SEND;//如果没有ACK，说明通信出了问题。返回错误码-发送错误。
	}	
	soft_iic_stop();//IIC停止。
	return AT24_OK;//啥错都没有就返回正常。
}
/*-------------------------------------------------------
AT24系列单字节地址型号的读函数，只为了check函数存在。
-------------------------------------------------------*/
u8 at24_read_char(u8 iic,u8 addr,u8 * dat){
 	soft_iic_start();			//IIC开始。
	soft_iic_write(iic);	//先写IIC器件地址。
	if(soft_iic_read_ack()!=0){	//读ACK。
		soft_iic_stop();		//IIC停止。
		return AT24_ERROR_NOACK;//如果没有ACK，说明器件不存在。返回错误码-无回应错误。
	}
	soft_iic_write(addr);
	if(soft_iic_read_ack()!=0){	//读ACK。
		soft_iic_stop();		//IIC停止。
		return AT24_ERROR_NOACK;//如果没有ACK，说明器件不存在。返回错误码-无回应错误。
	}
	soft_iic_start();			//IIC重新开始，这是读动作的需求。
	soft_iic_write(iic+1);	//写IIC器件地址，并设置读取位。
	if(soft_iic_read_ack()!=0){	//读ACK。
		soft_iic_stop();		//IIC停止。
		return AT24_ERROR_NOACK;//如果没有ACK，说明器件不存在。返回错误码-无回应错误。
	}
	*dat=soft_iic_read();	//读取数据。
	soft_iic_write_nack();//停止读取了就发送NOACK。
	soft_iic_stop();//IIC停止。
	return AT24_OK;//啥错都没有就返回正常。
}
/*-------------------------------------------------------
AT24系列双字节地址型号的写函数，只为了check函数存在。
-------------------------------------------------------*/
u8 at24_write_int(u8 iic,u16 addr,u8 dat){
	soft_iic_start();			//IIC开始。
	soft_iic_write(iic);	//先写IIC器件地址。
	if(soft_iic_read_ack()!=0){	//读ACK。
		soft_iic_stop();		//IIC停止。
		return AT24_ERROR_NOACK;//如果没有ACK，说明器件不存在。返回错误码-无回应错误。
	}
	soft_iic_write(addr/256);	//再写EEPROM内存地址。
	if(soft_iic_read_ack()!=0){	//读ACK。
		soft_iic_stop();		//IIC停止。
		return AT24_ERROR_NOACK;//如果没有ACK，说明器件不存在。返回错误码-无回应错误。
	}
	soft_iic_write(addr%256);	//再写EEPROM内存地址。
	if(soft_iic_read_ack()!=0){	//读ACK。
		soft_iic_stop();		//IIC停止。
		return AT24_ERROR_NOACK;//如果没有ACK，说明器件不存在。返回错误码-无回应错误。
	}
	soft_iic_write(dat);	//写入数据。
	if(soft_iic_read_ack()!=0){	//读ACK。
		soft_iic_stop();		//IIC停止。
		return AT24_ERROR_SEND;//如果没有ACK，说明通信出了问题。返回错误码-发送错误。
	}	
	soft_iic_stop();//IIC停止。
	return AT24_OK;//啥错都没有就返回正常。
}
/*-------------------------------------------------------
AT24系列双字节地址型号的读函数，只为了check函数存在。
-------------------------------------------------------*/
u8 at24_read_int(u8 iic,u16 addr,u8 * dat){
 	soft_iic_start();			//IIC开始。
	soft_iic_write(iic);	//先写IIC器件地址。
	if(soft_iic_read_ack()!=0){	//读ACK。
		soft_iic_stop();		//IIC停止。
		return AT24_ERROR_NOACK;//如果没有ACK，说明器件不存在。返回错误码-无回应错误。
	}
	soft_iic_write(addr/256);
	if(soft_iic_read_ack()!=0){	//读ACK。
		soft_iic_stop();		//IIC停止。
		return AT24_ERROR_NOACK;//如果没有ACK，说明器件不存在。返回错误码-无回应错误。
	}
	soft_iic_write(addr%256);
	if(soft_iic_read_ack()!=0){	//读ACK。
		soft_iic_stop();		//IIC停止。
		return AT24_ERROR_NOACK;//如果没有ACK，说明器件不存在。返回错误码-无回应错误。
	}
	soft_iic_start();			//IIC重新开始，这是读动作的需求。
	soft_iic_write(iic+1);	//写IIC器件地址，并设置读取位。
	if(soft_iic_read_ack()!=0){	//读ACK。
		soft_iic_stop();		//IIC停止。
		return AT24_ERROR_NOACK;//如果没有ACK，说明器件不存在。返回错误码-无回应错误。
	}
	*dat=soft_iic_read();	//读取数据。
	soft_iic_write_nack();//停止读取了就发送NOACK。
	soft_iic_stop();//IIC停止。
	return AT24_OK;//啥错都没有就返回正常。
}
/*-------------------------------------------------------
AT24系列判断型号函数，只为了auto_init函数存在。
-------------------------------------------------------*/
u8 at24_addr_check(void){
	u8 i,count,addr,save[8];//一堆临时变量。
	count=0;                //统计值清零。
	for(i=0;i<8;i++){       //eeprom最多有8个地址。
		soft_iic_start();   //开始IIC。
		soft_iic_write((i<<1)+0xA0);//依次写入8个地址。
		if(soft_iic_read_ack()==0){ //判断有没有回复。
			if(count==0){           //只读取第一次回复的地址。
				addr=(i<<1)+0xA0;   //把地址保存起来。
			}
			count++;                //统计总的相应的地址个数。
		}
		soft_iic_stop();            //停止IIC。
	}
	if(count==8){       //如果有8个地址的话，
		return AT24C16; //说明是AT24C16。
	}
	if(count==4){       //如果有4个地址的话，
		return AT24C08+((addr>>1)&0x04);//说明是AT24C08，同时把剩下的地址包含到地址里去。
	}
	if(count==2){       //如果有2个地址的话，
		return AT24C04+((addr>>1)&0x06);//说明是AT24C04，同时把剩下的地址包含到地址里去。
	}
	if(count==1){      //如果只有1个地址，那么情况就多了。需要仔细判别。
		at24_read_char (addr,127,&save[0]);                 //先读地址127。
		at24_read_char (addr,255,&save[1]);                 //先读地址255。
		at24_write_char(addr,127,(save[0]+1));delay_ms(10); //为了保证不重复，把原数+1再写回去。
		at24_write_char(addr,255,(save[1]+2));delay_ms(10); //为了保证不重复，把原数+2再写回去。
		at24_read_char (addr,127,&save[2]);                 //再读地址127。
		at24_read_char (addr,255,&save[3]);                 //再读地址255。
		if((save[2]==save[3])&&(save[3]==(u8)(save[1]+2))){ //如果后读的127的数据和255的一样，且和255的数据一样。
			at24_write_char(addr,127,save[0]);delay_ms(10); //说明255地址是无效的，255的数据覆盖了127。那么将127的原数据还原。
			return AT24C01+((addr>>1)&0x07);                //说明是AT24C01，同时把剩下的地址包含到地址里去。
		}else if((save[2]==(u8)(save[0]+1))&&(save[3]==(u8)(save[1]+2))){//如果两次读写的都不一样，且读和写一致。
			at24_write_char(addr,127,save[0]);delay_ms(10); //说明两个地址都可写，且不重复。那么就把原来的数据都还原。
			at24_write_char(addr,255,save[1]);delay_ms(10); //还原数据。
			return AT24C02+((addr>>1)&0x07);                //说明是AT24C02，同时把剩下的地址包含到地址里去。
		}else{//以上就判断出了单字节地址的所有型号，下面开始判断双字节的型号。
			at24_read_int (addr,4095, &i);       //先把原来的数读出来，
			at24_read_int (addr,8191, &save[0]); //一方面为了保护原数据，
			at24_read_int (addr,16383,&save[1]); //另一方面也是为了写入数据的不重复。
			at24_read_int (addr,32767,&save[2]); //
			at24_read_int (addr,65535,&save[3]); //
			at24_write_int(addr,8191, (save[0]+1));delay_ms(10);//将读出来的数据，
			at24_write_int(addr,16383,(save[1]+2));delay_ms(10);//加上一个不同的数，
			at24_write_int(addr,32767,(save[2]+3));delay_ms(10);//再写回去，
			at24_write_int(addr,65535,(save[3]+4));delay_ms(10);//以此来保证不重复。	
			at24_read_int (addr,4095,&count);    //然后再读一遍，
			at24_read_int (addr,8191,&save[4]);  //用于比对数据，
			at24_read_int (addr,16383,&save[5]); //通过比对结果来判断型号。
			at24_read_int (addr,32767,&save[6]); //
			at24_read_int (addr,65535,&save[7]); //

			//debug("[%02X]-[%02X]-[%02X]-[%02X]-[%02X]\r\n",(u16)i,
			//(u16)(save[0]+1),(u16)(save[1]+2),(u16)(save[2]+3),(u16)(save[3]+4));
			//debug("[%02X]-[%02X]-[%02X]-[%02X]-[%02X]\r\n",(u16)count,
			//(u16)save[4],(u16)save[5],(u16)save[6],(u16)save[7]);
			if((count==save[4])&&(count==(u8)(save[3]+4))){ //如果4095的数据和8191相等，且等于65535的值。
				at24_write_int(addr,4095,i);delay_ms(10);   //说明只有4095地址有效，其他都被覆盖了。那么就把4095的原数据存回去。
				return AT24C32+((addr>>1)&0x07);            //返回型号AT24C32，同时包含器件地址。
			}else{//如果4095的数据和8191的数据不相等，那么继续往下判断。
				if((save[4]==save[5])&&(save[4]==(u8)(save[3]+4))){//如果8191和16383的数据相等，且等于65535的值。
					at24_write_int(addr,4095,i);delay_ms(10);      //有效地址到8191，其他的被覆盖了。那么就把4095的原数据存回去。
					at24_write_int(addr,8191,save[0]);delay_ms(10);//8191的原数据也存回去。
					return AT24C64+((addr>>1)&0x07);               //返回型号AT24C64，同时包含器件地址。
				}else{//如果4095的数据和8191的数据不相等，8191和16383的数据也不相等，那么继续往下判断。
					if((save[5]==save[6])&&(save[5]==(u8)(save[3]+4))){ //如果16383和32767的数据相等，且等于65535的值。
						at24_write_int(addr,4095,i);delay_ms(10);       //有效地址到16383，其他的被覆盖了。那么就把4095的原数据存回去。
						at24_write_int(addr,8191,save[0]);delay_ms(10); //8191的原数据也存回去。
						at24_write_int(addr,16383,save[1]);delay_ms(10);//16383的原数据也存回去。
						return AT24C128+((addr>>1)&0x07);               //返回型号AT24C128，同时包含器件地址。
					}else{//如果4095、8191、16383三个数据互不相等，那么继续往下判断。
						if((save[6]==save[7])&&(save[6]==(u8)(save[3]+4))){ //如果32767和65535的数据相等。
							at24_write_int(addr,4095,i);delay_ms(10);       //有效地址到32767，其他的被覆盖了。那么就把4095的原数据存回去。
							at24_write_int(addr,8191,save[0]);delay_ms(10); //8191的原数据也存回去。
							at24_write_int(addr,16383,save[1]);delay_ms(10);//16383的原数据也存回去。
							at24_write_int(addr,32767,save[2]);delay_ms(10);//32767的原数据也存回去。
							return AT24C256+((addr>>1)&0x07);               //返回型号AT24C256，同时包含器件地址。
						}else{//如果写入的数据都互不相同，那么所有地址都有效，该芯片是AT24C512。
							at24_write_int(addr,4095,i);delay_ms(10);       //4095的原数据存回去。
							at24_write_int(addr,8191,save[0]);delay_ms(10); //8191的原数据也存回去。
							at24_write_int(addr,16383,save[1]);delay_ms(10);//16383的原数据也存回去。
							at24_write_int(addr,32767,save[2]);delay_ms(10);//32767的原数据也存回去。
							at24_write_int(addr,65535,save[3]);delay_ms(10);//65535的原数据也存回去。
							return AT24C512+((addr>>1)&0x07);               //返回型号AT24C512，同时包含器件地址。
						}
					}
				}
			}
		}
	}
	return AT24CXX;
}
/*-------------------------------------------------------
AT24系列的自动初始化函数。
-------------------------------------------------------*/
void at24_auto_init(at24_def * dev,u8 scl,u8 sda){
	dev->scl=scl;							//将SCL引脚保存。
	dev->sda=sda;							//将SDA引脚保存。				
	dev->id=soft_iic_init_linkage(scl,sda);	//初始化引脚。
	dev->model=at24_addr_check();           //检测型号信息并保存。
	at24_set_work(dev);						//切换控制器到当前器件。
}
/*程序区折叠专用**************************************************************/#endif
