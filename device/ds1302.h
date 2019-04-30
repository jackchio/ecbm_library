#ifndef _ECBM_DS1302_H_
#define _ECBM_DS1302_H_
/*-------------------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2018 奈特

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

免责说明：
	本软件库以MIT开源协议免费向大众提供。作者只保证原始版本是由作者在维护修BUG，
其他通过网络传播的版本也许被二次修改过，由此出现的BUG与作者无关。而当您使用原始
版本出现BUG时，请联系作者解决。联系方式：进群778916610
------------------------------------------------------------------------------------*/
//-------------------------------以下是图形设置界面，可在Configuration Wizard界面设置----------------------------------------------------------
//<<< Use Configuration Wizard in Context Menu >>>
//<e>启用默认设置
//<i>由于本库支持多个设备，为了方便初始化，设立了这个默认设置。
//<i>当勾选此选项时，会开放函数void ds1302_set_default(ds1302_def * dev);将定义出来的结构体变量放入参数即能把结构体设置为默认值。
//<i>比如定义了ds1302_def dev1;在图形界面设置好默认设置后，调用ds1302_set_default(&dev1);即可把默认设置填入结构体dev1。
#define DS1302_DEFAULT_EN 1
//<o>秒
//<i>请输入BCD码。若不清楚BCD的定义，那么就先输入0x，再输入秒数。比如52秒，就输入0x52。
//<i>范围0x00~0x59
//<0x00-0x59:0x01>
#define DS1302_SECOND 0x00
//<o>分
//<i>请输入BCD码。若不清楚BCD的定义，那么就先输入0x，再输入分数。比如08分，就输入0x08。
//<i>范围0x00~0x59
//<0x00-0x59:0x01>
#define DS1302_MINUTE 0x08
//<o.0..5>时
//<i>请输入BCD码。若不清楚BCD的定义，那么就先输入0x，再输入小时数。比如9点钟，就输入0x09。
//<i>在24小时制内输入范围为0x00~0x23；在12小时制内输入范围为0x01~0x12；
//<0x00-0x23:0x01>
//<o.7>时制选择
//<0=>24小时制 <1=>12小时制
//<o.5>上下午选择
//<i>注意：如果选了24小时制，则此选项一定得是上午，否则数据会出错。
//<i>原因是该寄存器的bit5位是12小时制的AM/PM位，而bit5位、bit4位是24小时制的存放小时数十位上数字的存储位。
//<i>由于bit5位共用导致了冲突。所以在24小时制时只有设置为“上午”，才不会引起冲突。因为“上午”对应的值是0。
//<0=>上午 <1=>下午
#define DS1302_HOUR 0x10
//<o>日期
//<i>请输入BCD码。若不清楚BCD的定义，那么就先输入0x，再输入日期。比如14号，就输入0x14。
//<i>范围0x01~0x31
//<0x01-0x31:0x01>
#define DS1302_DATE 0x15
//<o>月份
//<i>请输入BCD码。若不清楚BCD的定义，那么就先输入0x，再输入月份。比如2月份，就输入0x02。
//<i>范围0x01~0x12
//<0x01-0x12:0x01>
#define DS1302_MONTH 0x02
//<o>星期
//<i>请输入BCD码。若不清楚BCD的定义，那么就先输入0x，再输入星期。比如星期四，就输入0x04。
//<i>范围0x01~0x07
//<0x01-0x07:0x01>
#define DS1302_DAY 0x05
//<o>年份
//<i>请输入BCD码。若不清楚BCD的定义，那么就先输入0x，再输入年份。比如19年，就输入0x19。
//<i>范围0x00~0x99。由于寄存器只能存两位数字。所以无论是1919年和2019年都是19年。需要留意百年虫问题。
//<0x01-0x31:0x01>
#define DS1302_YEAR 0x19
//<h>最大充电电流设置
//<i>从VCC2到VCC1的充电电流最大值=（VCC2电压-二极管数量*0.7V）/（电阻阻值）。
//<i>例如VCC2接5V电压，VCC1接一个超级电容。二极管数量为1，电阻阻值为2K。
//<i>那么Imax=（5.0V-1*0.7V）/2K=2.15mA。
//<o.2..3>VCC2到VCC1的二极管数量
//<1=>一个二极管 <2=>两个二极管
//<o.0..1>VCC2到VCC1的电阻阻值
//<1=>2K <2=>4K <3=>8K
#define DS1302_CHARGER 0xA5
//</h>
//</e>
//<<< end of configuration section >>>
//-------------------------------以上是图形设置界面，可在Configuration Wizard界面设置----------------------------------------------------------

//DS1302地址定义
#define DS1302_SECOND_ADDR     0x80//秒数据地址
#define DS1302_MINUTE_ADDR     0x82//分数据地址
#define DS1302_HOUR_ADDR    0x84//时数据地址
#define DS1302_DATE_ADDR    0x86//日数据地址
#define DS1302_MONTH_ADDR   0x88//月数据地址
#define DS1302_DAY_ADDR     0x8A//星期数据地址
#define DS1302_YEAR_ADDR    0x8C//年数据地址
#define DS1302_CONTROL_ADDR 0x8E//控制数据地址
#define DS1302_CHARGER_ADDR 0x90//充电控制器地址 					 
#define DS1302_RAM0  0xC0
#define DS1302_RAM1  0xC2
#define DS1302_RAM2  0xC4
#define DS1302_RAM3  0xC6
#define DS1302_RAM4  0xC8
#define DS1302_RAM5  0xCA
#define DS1302_RAM6  0xCC
#define DS1302_RAM7  0xCE
#define DS1302_RAM8  0xD0
#define DS1302_RAM9  0xD2
#define DS1302_RAM10 0xD4
#define DS1302_RAM11 0xD6
#define DS1302_RAM12 0xD8
#define DS1302_RAM13 0xDA
#define DS1302_RAM14 0xDC
#define DS1302_RAM15 0xDE
#define DS1302_RAM16 0xE0
#define DS1302_RAM17 0xE2
#define DS1302_RAM18 0xE4
#define DS1302_RAM19 0xE6
#define DS1302_RAM20 0xE8
#define DS1302_RAM21 0xEA
#define DS1302_RAM22 0xEC
#define DS1302_RAM23 0xEE
#define DS1302_RAM24 0xF0
#define DS1302_RAM25 0xF2
#define DS1302_RAM26 0xF4
#define DS1302_RAM27 0xF6
#define DS1302_RAM28 0xF8//最后3位RAM
#define DS1302_RAM29 0xFA//被征用为
#define DS1302_RAM30 0xFC//第一次初始化判断位

typedef struct{
	u8 rst_pin;
	u8 io_pin;
	u8 sck_pin;
	u8 year;
	u8 month;
	u8 date;
	u8 day;
	u8 hour;
	u8 minute;
	u8 second;
	u8 charger;
}ds1302_def;



//向DS1302写入一字节数据
void ds1302_write(ds1302_def * dev,u8 addr,u8 dat) 
{
	unsigned char i;
	gpio_out(dev->rst_pin,1);//启动DS1302总线					
	//写入目标地址：addr
	addr = addr & 0xFE;   //最低位置零，寄存器0位为0时写，为1时读
	for (i = 0; i < 8; i ++) {
		if (addr & 0x01){
			gpio_out(dev->io_pin,1);
		}else{
			gpio_out(dev->io_pin,0);
		}
		gpio_out(dev->sck_pin,1); //产生时钟
		gpio_out(dev->sck_pin,0);
		addr = addr >> 1;
	}	
	//写入数据：d
	for (i = 0; i < 8; i ++) {
		if (dat & 0x01) {
			gpio_out(dev->io_pin,1);
		}else{
			gpio_out(dev->io_pin,0);
		}
		gpio_out(dev->sck_pin,1);//产生时钟
		gpio_out(dev->sck_pin,0);
		dat = dat >> 1;
	}
	gpio_out(dev->rst_pin,0);//停止DS1302总线
}

//从DS1302读出一字节数据
u8 ds1302_read(ds1302_def * dev,u8 addr) {
	unsigned char i,temp;	
	gpio_out(dev->rst_pin,1);//启动DS1302总线
	//写入目标地址：addr
	addr = addr | 0x01;    //最低位置高，寄存器0位为0时写，为1时读
	for (i = 0; i < 8; i ++) {
		if (addr & 0x01) {
			gpio_out(dev->io_pin,1);
		}else{
			gpio_out(dev->io_pin,0);
		}
		gpio_out(dev->sck_pin,1); //产生时钟
		gpio_out(dev->sck_pin,0);
		addr = addr >> 1;
	}	
	//输出数据：temp
	for (i = 0; i < 8; i ++) {
		temp = temp >> 1;
		if (gpio_in(dev->io_pin)) {
			temp |= 0x80;
		}else{
			temp &= 0x7F;
		}
		gpio_out(dev->sck_pin,1); //产生时钟
		gpio_out(dev->sck_pin,0);
	}	
	gpio_out(dev->rst_pin,0);//停止DS1302总线
	return temp;
}
void ds1302_set_default(ds1302_def * dev){
	dev->year   =DS1302_YEAR;
	dev->month  =DS1302_MONTH;
	dev->date   =DS1302_DATE;
	dev->day    =DS1302_DAY;
	dev->hour   =DS1302_HOUR;
	dev->minute =DS1302_MINUTE;
	dev->second =DS1302_SECOND;
	dev->charger=DS1302_CHARGER;
}
void ds1302_save(ds1302_def * dev){
	ds1302_write(dev,DS1302_CONTROL_ADDR, 0x00);		//关闭写保护
	ds1302_write(dev,DS1302_SECOND_ADDR,  0x80);		//暂停时钟 
	ds1302_write(dev,DS1302_CHARGER_ADDR, dev->charger);//充电设置
	ds1302_write(dev,DS1302_YEAR_ADDR,    dev->year);	//年 
	ds1302_write(dev,DS1302_MONTH_ADDR,   dev->month);	//月 
	ds1302_write(dev,DS1302_DATE_ADDR,    dev->date);	//日 
	ds1302_write(dev,DS1302_DAY_ADDR,     dev->day);    //周 
	ds1302_write(dev,DS1302_HOUR_ADDR,    dev->hour);	//时 
	ds1302_write(dev,DS1302_MINUTE_ADDR,  dev->minute); //分
	ds1302_write(dev,DS1302_SECOND_ADDR,  dev->second); //秒
	ds1302_write(dev,DS1302_CONTROL_ADDR, 0x80);        //打开写保护
}
void ds1302_init(ds1302_def * dev,u8 rst_pin,u8 io_pin,u8 sck_pin){
	u8 check;
	dev->rst_pin=rst_pin;
	dev->io_pin=io_pin;
	dev->sck_pin=sck_pin;
	gpio_mode(dev->rst_pin,GPIO_OUT);
	gpio_mode(dev->io_pin,GPIO_OUT);
	gpio_mode(dev->sck_pin,GPIO_OUT);
	gpio_out(dev->rst_pin,0);
	gpio_out(dev->sck_pin,0);
	gpio_out(dev->io_pin,1);
	if(ds1302_read(dev,DS1302_RAM28)==0xEC){
		check=1;
	}else{
		check=0;
	}	
	if(ds1302_read(dev,DS1302_RAM29)==0xB3){
		check+=1;
	}	
	if(ds1302_read(dev,DS1302_RAM30)==233){
		check+=1;
	}
	if(check!=3){
		ds1302_save(dev);
		ds1302_write(dev,DS1302_CONTROL_ADDR,0x00);		   //关闭写保护
		ds1302_write(dev,DS1302_RAM28,0xEC);
		ds1302_write(dev,DS1302_RAM29,0xB3);
		ds1302_write(dev,DS1302_RAM30,233);
		ds1302_write(dev,DS1302_CONTROL_ADDR,0x80);		   //关闭写保护
	}
}
void ds1302_load(ds1302_def * dev){
	dev->year  =ds1302_read(dev,DS1302_YEAR_ADDR);	//年 
	dev->month =ds1302_read(dev,DS1302_MONTH_ADDR);	//月 
	dev->date  =ds1302_read(dev,DS1302_DATE_ADDR);	//日 
	dev->hour  =ds1302_read(dev,DS1302_HOUR_ADDR);	//时 
	dev->minute=ds1302_read(dev,DS1302_MINUTE_ADDR);//分 
	dev->second=ds1302_read(dev,DS1302_SECOND_ADDR);//秒
	dev->day   =ds1302_read(dev,DS1302_DAY_ADDR);	//周 	
}
#endif
