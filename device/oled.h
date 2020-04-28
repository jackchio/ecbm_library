#ifndef _OLED_H_ //头文件防止重加载必备，先看看有没有定义过这个，定义说明已经加载过一次了。
#define _OLED_H_ //没定义说明是首次加载，那么往下执行。并且定义这个宏定义，防止下一次被加载。
/*-------------------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2020 奈特

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
版本出现BUG时，请联系作者解决。
                             **************************
                             * 联系方式：进群778916610 *
							 ************************** 
------------------------------------------------------------------------------------*/
//-----------------以下是图形设置界面，可在Configuration Wizard界面设置-----------------
//<<< Use Configuration Wizard in Context Menu >>>
//<h>基于SSD1306的OLED初始化库
//<i>本OLED库大量依靠ECBM主库，请不要脱离主库使用。当然自己移植出去也是可以的。
//<h>面板参数
//<i>这些参数是和屏幕面板息息相关的，不同尺寸的oled参数一定不一样。相同尺寸的oled也有可能因为厂家不一样而不同。请根据实际情况来修改。
//<o>OLED横坐标像素
//<0-128:1>
//<i>本库基于SSD1306，最大支持128。
#define OLED_X_MAX 128
//<o>OLED纵坐标像素
//<16-64:8>
//<i>本库基于SSD1306，最大支持64，该数值必须是8的倍数且大于16（SSD1306要求）。
#define OLED_Y_MAX 64
#define OLED_PAGE_MAX (OLED_Y_MAX/8)
//<o>OLED的X轴相对于实际屏幕的偏移量
//<0-127:1>
//<i>该设置不会更改硬件配置，只会在软件上加一个偏移。通常只有X轴像素不到128时才使用。
#define OLED_OFFSET_XPIN 0
//<o>OLED的逻辑引脚(Y轴)相对于硬件引脚的偏移量
//<0-63:1>
//<i>移动逻辑引脚时，RAM的内容也会跟着移动,可输入0~63。仅当OLED的纵坐标像素小于64时设置该选项。
#define OLED_OFFSET_LOGIC 0
//<o>OLED的显示模式
//<0-15:1>
//<i>输入值范围为0~15。模式变量由三个参数构成，为了方便打包在一起，通过oled_display_mode_test函数测出当前的oled屏是何种显示模式，然后回来设置。
//<i>测试时屏幕上会显示0~f的代号对应0~15。将正确显示的代号输入该参数即可。比如4号模式下，oled是正常显示的。于是显示模式为4。
#define OLED_DISPLAY_MODE 7
//</h>
//<h>驱动芯片设置
//<i>这些设置对于所有基于SSD1306的屏幕都适用，除了对比度外，别的参数通常不需要更改。
//<o>OLED对比度
//<0-255:1>
//<i>对于单色屏来说也是亮度,可输入0~255。
#define OLED_CONTRAST 128
//<o>OLED的RAM内容相对于逻辑引脚的偏移量
//<0-63:1>
//<i>输入值范围为0~63，但通常不需要改动这个值，因为调节逻辑引脚时，RAM的内容会跟着移动。该值推荐为0。
#define OLED_OFFSET_RAM 0
//<o>OLED显示的内容
//<0xa4=>显示RAM <0xa5=>全亮
//<i>只有在第一次点亮时，为了检测oled好坏才会选择“全亮”选项。正常使用请选择“显示RAM”。
#define OLED_DISPLAY_SOURCE 0xA4
//<o>OLED屏内LED像素点的点亮方式
//<0xa6=>数据1亮，数据0灭 <0xa7=>数据0亮，数据1灭
//<i>相当于高电平点亮LED还是低电平点亮LED的问题。
#define OLED_DISPLAY_LED 0xA6
//<o>OLED屏的Vcomh电压
//<0x00=>0.65*VCC <0x10=>0.71*VCC <0x20=>0.77*VCC <0x30=>0.83*VCC <0x40=>0.89*VCC
//<i>该电压是屏内LED的驱动电压，设置得越高，屏幕就越亮。
#define OLED_VCOMH 0x20
//<o.0..3>OLED屏的Phase 1的周期
//<i>LED放电时间，由于电路中存在一定的寄生电容，所以LED两端的电压需要一定时间才能变为0，建议保持默认。
//<o.4..7>OLED屏的Phase 2的周期
//<i>LED充电时间，由于电路中存在一定的寄生电容，所以LED两端的电压需要一定时间才能变为VCC，建议保持默认。
#define OLED_PCC 241
//<o>OLED屏的地址寻址模式
//<0x00=>水平寻址 <0x01=>垂直寻址 <0x02=>页面寻址
//<i>试做版只有页面寻址模式下的写入函数，就保持默认吧。
#define OLED_ADRESS 0
//<o.4..7>OLED的时钟设置
//<i>时钟为参考值，由于制造精度和环境温飘等原因，会有一定的误差。
//<0=>333000Hz  <1=>337625Hz <2=>342250Hz <3=>346875Hz <4=>351500Hz 
//<5=>356125Hz  <6=>360750Hz <7=>365375Hz <8=>370000Hz <9=>374625Hz 
//<10=>379250Hz  <11=>383875Hz <12=>388500Hz <13=>393125Hz <14=>397750Hz 
//<15=>402375Hz  
//<o.0..3>OLED的时钟分频N
//<i>分频系数N，可输入0~15，对应分频1~16分频。
#define OLED_SYSCLK 192
//<q>OLED升压泵开关
//<i>OLED可以额外提供VCC，也可以使用自身的升压泵产生7.5V的电压供给VCC。
#define OLED_DC_DC 1
//</h>
//</h>
//<h>优化设置
//<i>可以把一些代码优化掉节省空间。
//<q>显示模式测试代码
//<i>该函数oled_display_mode_test只是在不明白当前OLED屏工作状态时使用。测试过之后就可以优化掉了。
#define OLED_DISPLAY_MODE_EN 1
//<q>OLED设置信息显示
//<i>该函数oled_information的用处是在调试时，能看到设置的信息。设置好了以后就可以优化掉了。
#define OLED_INFORMATION_EN 0
//<q>oled_printf函数
//<i>当你使用OLED仅仅是用于调试的时候，可以使用oled_printf函数。如果OLED只是UI库的一个组件，可以优化掉所有关于OLED库中显示字符的代码，转而去用UI库的显示代码。
#define OLED_PRINTF_EN 1
//</h>
//<<< end of configuration section >>>
//-----------------以上是图形设置界面，可在Configuration Wizard界面设置-----------------
/*---------------------------------------头文件------------------------------------*/
#include "ecbm_core.h"    //ECBM库的头文件，里面已经包含了STC8的头文件。
/*---------------------------------------宏定义------------------------------------*/
#define oled_cmd 0x00
#define oled_dat 0x40

#define OLED_SERIAL_PARALLEL_MASK 0X80//通信形式位
#define OLED_SERIAL               0x80//串行通信
#define OLED_PARALLEL             0x7F//并行通信

#define OLED_HARD_SOFT_WARE_MASK  0X40//软/硬件选择位
#define OLED_HARDWARE_SERIAL      0X40//硬件
#define OLED_SOFTWARE_SERIAL      0XBF//软件

#define OLED_SERIAL_IIC_SPI_MASK  0x20//IIC/SPI选择位
#define OLED_SERIAL_IIC           0x20//IIC
#define OLED_SERIAL_SPI           0xDF//SPI

#define OLED_CS_EN_MASK           0x10//CS脚使能位
#define OLED_CS_ENABLE            0x10//使能CS脚
#define OLED_CS_DISABLE           0xEF//不使能CS脚

#define OLED_HARD_SPI (OLED_SERIAL|OLED_HARDWARE_SERIAL)                  //用硬件SPI驱动OLED
#define OLED_HARD_IIC (OLED_SERIAL|OLED_HARDWARE_SERIAL|OLED_SERIAL_IIC)  //用硬件IIC驱动OLED
#define OLED_SOFT_SPI (OLED_SERIAL)                                       //用软件SPI驱动OLED
#define OLED_SOFT_IIC (OLED_SERIAL|OLED_SERIAL_IIC)                       //用软件IIC驱动OLED
/*--------------------------------------变量定义-----------------------------------*/
typedef struct{
	u8 w;		//宽度（物理屏幕尺寸）。
	u8 h;		//高度（物理屏幕尺寸）。
	u8 x;		//X轴偏移（物理屏幕）。
	u8 y;		//Y轴偏移（物理屏幕）。
	u8 mode;	//显示模式（物理屏幕）。
	u8 buf_w;	//缓存的总宽度（虚拟屏幕尺寸）。
	u8 buf_h;	//缓存的总高度（虚拟屏幕尺寸）。
	u8 buf_x;	//缓存的X轴偏移（虚拟屏幕）。
	u8 buf_y;	//缓存的Y轴偏移（虚拟屏幕）。
//|  D7  | D6  |  D5   |  D4 |  D3  |  D2  |  D1  |  D0  |	
//|SP/PP |HW/SW|IIC/SPI|CS_EN|  --  |  --  |  --  |  --  |
	u8 scl_pin;
	u8 sda_pin; 
	u8 dc_port;//DC的操作会在循环之中，所以是需要优化的。
	u8 dc_pin;
	u8 rst_pin;
	u8 cs_pin;
	u8 id;
}oled_def;
/*--------------------------------------程序定义-----------------------------------*/
/*程序区折叠专用***********************底层驱动模块****************************/#if 1
/*-------------------------------------------------------
函数名：oled_set_soft_iic
描  述：OLED设置引脚函数，用于软件IIC模式。
输  入：
		dev  -  OLED器件的信息包。
		scl  -  IIC模式下的时钟脚。
		sda  -  IIC模式下的数据脚。
输  出：无
返回值：无
创建者：奈特
调用例程：无，这是内部调用的函数。
创建日期：2019-10-23
修改记录：
2020-03-01：修复了在多器件下，由于scl脚和sda脚没有保存导致的通信问题。
-------------------------------------------------------*/
extern void oled_set_soft_iic(oled_def * dev,u8 scl,u8 sda);
/*-------------------------------------------------------
函数名：oled_set_hard_iic
描  述：OLED设置引脚函数，用于硬件IIC模式。
输  入：
		dev  -  OLED器件的信息包。
		scl  -  IIC模式下的时钟脚。
		sda  -  IIC模式下的数据脚。
输  出：无
返回值：无
创建者：奈特
调用例程：无，这是内部调用的函数。
创建日期：2019-10-23
修改记录：
-------------------------------------------------------*/
extern void oled_set_hard_iic(oled_def * dev,u8 scl,u8 sda);
/*-------------------------------------------------------
函数名：oled_set_soft_spi
描  述：OLED设置引脚函数，用于软件SPI模式。
输  入：
		dev  -  OLED器件的信息包。
		scl  -  SPI模式下的时钟脚。
		sda  -  SPI模式下的数据脚。
		dc   -  SPI模式下的数据/指令选择脚。
		rst  -  SPI模式下的复位脚。
		cs   -  SPI模式下的片选脚。
输  出：无
返回值：无
创建者：奈特
调用例程：无，这是内部调用的函数。
创建日期：2019-10-23
修改记录：
2020-03-01：修复了在多器件下，由于scl脚和sda脚没有保存导致的通信问题。
-------------------------------------------------------*/
extern void oled_set_soft_spi(oled_def * dev,u8 scl,u8 sda,u8 dc,u8 rst,u8 cs);
/*-------------------------------------------------------
函数名：oled_set_hard_spi
描  述：OLED设置引脚函数，用于硬件SPI模式。
输  入：
		dev  -  OLED器件的信息包。
		scl  -  SPI模式下的时钟脚。
		sda  -  SPI模式下的数据脚。
		dc   -  SPI模式下的数据/指令选择脚。
		rst  -  SPI模式下的复位脚。
		cs   -  SPI模式下的片选脚。
输  出：无
返回值：无
创建者：奈特
调用例程：无，这是内部调用的函数。
创建日期：2019-10-23
修改记录：
-------------------------------------------------------*/
extern void oled_set_hard_spi(oled_def * dev,u8 scl,u8 sda,u8 dc,u8 rst,u8 cs);
/*-------------------------------------------------------
函数名：oled_write_hard_spi
描  述：OLED的写函数，用于硬件SPI模式。
输  入：
		dev  -  OLED器件的信息包。
		cd   -  指定缓存里存的是指令还是数据，可输入oled_cmd或oled_dat。
		buf  -  存放指令或数据的缓存。
输  出：无
返回值：无
创建者：奈特
调用例程：无，这是内部调用的函数。
创建日期：2019-10-23
修改记录：
-------------------------------------------------------*/
extern void oled_write_hard_spi(oled_def * dev,u8 cd,u8 buf);
/*-------------------------------------------------------
函数名：oled_write_soft_spi
描  述：OLED的写函数，用于软件SPI模式。
输  入：
		dev  -  OLED器件的信息包。
		cd   -  指定缓存里存的是指令还是数据，可输入oled_cmd或oled_dat。
		buf  -  存放指令或数据的缓存。
输  出：无
返回值：无
创建者：奈特
调用例程：无，这是内部调用的函数。
创建日期：2019-10-23
修改记录：
-------------------------------------------------------*/
extern void oled_write_soft_spi(oled_def * dev,u8 cd,u8 buf);
/*-------------------------------------------------------
函数名：oled_write_hard_iic
描  述：OLED的写函数，用于硬件IIC模式。
输  入：
		dev  -  OLED器件的信息包。
		cd   -  指定缓存里存的是指令还是数据，可输入oled_cmd或oled_dat。
		buf  -  存放指令或数据的缓存。
输  出：无
返回值：无
创建者：奈特
调用例程：无，这是内部调用的函数。
创建日期：2019-10-23
修改记录：
-------------------------------------------------------*/
extern void oled_write_hard_iic(oled_def * dev,u8 cd,u8 buf);
/*-------------------------------------------------------
函数名：oled_write_soft_iic
描  述：OLED的写函数，用于软件IIC模式。
输  入：
		dev  -  OLED器件的信息包。
		cd   -  指定缓存里存的是指令还是数据，可输入oled_cmd或oled_dat。
		buf  -  存放指令或数据的缓存。
输  出：无
返回值：无
创建者：奈特
调用例程：无，这是内部调用的函数。
创建日期：2019-10-23
修改记录：
-------------------------------------------------------*/
extern void oled_write_soft_iic(oled_def * dev,u8 cd,u8 buf);
/*-------------------------------------------------------
函数名：oled_write
描  述：OLED的写函数，通用。
输  入：
		dev  -  OLED器件的信息包。
		cd   -  指定缓存里存的是指令还是数据，可输入oled_cmd或oled_dat。
		buf  -  存放指令或数据的缓存。
输  出：无
返回值：无
创建者：奈特
调用例程：无，这是内部调用的函数。
创建日期：2019-10-23
修改记录：
-------------------------------------------------------*/
extern void oled_write(oled_def * dev,u8 cd,u8 buf);
/*程序区折叠专用**************************************************************/#endif


/*程序区折叠专用***********************系统操作模块****************************/#if 1
/*-------------------------------------------------------
函数名：oled_on
描  述：开启OLED函数，用于打开OLED的电源。
输  入：
		dev  -  OLED器件的信息包。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-10-23
修改记录：
-------------------------------------------------------*/
extern void oled_on              (oled_def * dev);
/*-------------------------------------------------------
函数名：oled_off
描  述：关闭OLED函数，用于关闭OLED的电源。
输  入：
		dev  -  OLED器件的信息包。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-10-23
修改记录：
-------------------------------------------------------*/
extern void oled_off             (oled_def * dev);
/*-------------------------------------------------------
函数名：oled_set_com
描  述：OLED设置COM引脚数函数。
输  入：
		dev  -  OLED器件的信息包。
		num  -  纵向像素-1，比如128x64就填63。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-10-23
修改记录：
-------------------------------------------------------*/
extern void oled_set_com         (oled_def * dev,u8 num);
/*-------------------------------------------------------
函数名：oled_set_contrast
描  述：OLED设置对比度函数，对于单色屏来说也可以称之为亮度。
输  入：
		dev  -  OLED器件的信息包。
		val  -  可输入0~255。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-10-23
修改记录：
-------------------------------------------------------*/
extern void oled_set_contrast    (oled_def * dev,u8 val);
/*-------------------------------------------------------
函数名：oled_set_pos
描  述：OLED设置数据指针函数，写画面数据的时候要用。
输  入：
		dev  -  OLED器件的信息包。
		x    -  X轴的位置，也就是横坐标。可输入0~128（针对12864屏）。
		y    -  Y轴的位置，也就是纵坐标。可输入0~8（页地址，每8个行整合为一页，针对12864就是64/8=8）。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-10-23
修改记录：
-------------------------------------------------------*/
extern void oled_set_pos         (oled_def * dev,u8 x,u8 y);
/*-------------------------------------------------------
函数名：oled_set_offset_logic
描  述：OLED设置逻辑引脚偏移函数，修改逻辑引脚到物理引脚的映射顺序。
输  入：
		dev    -  OLED器件的信息包。
		offset -  请根据实际情况输入。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-10-23
修改记录：
-------------------------------------------------------*/
extern void oled_set_offset_logic(oled_def * dev,u8 offset);
/*-------------------------------------------------------
函数名：oled_set_offset_ram
描  述：OLED设置RAM偏移函数，修改RAM到逻辑引脚的映射顺序。
输  入：
		dev    -  OLED器件的信息包。
		offset -  请根据实际情况输入。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-10-23
修改记录：
-------------------------------------------------------*/
extern void oled_set_offset_ram  (oled_def * dev,u8 offset);
/*-------------------------------------------------------
函数名：oled_fill
描  述：OLED全显函数，用于在屏幕显示一个数据。
输  入：
		dev  -  OLED器件的信息包。
		dat  -  其实也只有0x00和0xff有点作用。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-10-23
修改记录：
-------------------------------------------------------*/
extern void oled_fill            (oled_def * dev,u8 dat);
/*-------------------------------------------------------
函数名：oled_set_display_mode
描  述：OLED显示模式设置函数，用于设置屏幕的显示模式。
输  入：
		dev   -  OLED器件的信息包。
		mode  -  可输入0~15，根据具体情况输入。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-10-23
修改记录：
-------------------------------------------------------*/
extern void oled_set_display_mode(oled_def * dev,u8 mode);
/*-------------------------------------------------------
函数名：oled_set_display
描  述：OLED设置函数，用于普通单指令的设置。
输  入：
		dev  -  OLED器件的信息包。
		cmd  -  根据具体情况输入。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-10-23
修改记录：
-------------------------------------------------------*/
extern void oled_set_display     (oled_def * dev,u8 cmd);
/*-------------------------------------------------------
函数名：oled_set_vcomh
描  述：OLED设置Vcomh电压函数。
输  入：
		dev  -  OLED器件的信息包。
		v    -  根据具体情况输入。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-10-23
修改记录：
-------------------------------------------------------*/
extern void oled_set_vcomh       (oled_def * dev,u8 v);
/*-------------------------------------------------------
函数名：oled_set_dcdc
描  述：OLED设置DC-DC电路函数。
输  入：
		dev  -  OLED器件的信息包。
		en   -  使能标志位。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-10-23
修改记录：
-------------------------------------------------------*/
extern void oled_set_dcdc        (oled_def * dev,u8 en);
/*-------------------------------------------------------
函数名：oled_set_pcc
描  述：OLED设置扫频时序函数。
输  入：
		dev  -  OLED器件的信息包。
		clk  -  请谨慎输入。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-10-23
修改记录：
-------------------------------------------------------*/
extern void oled_set_pcc         (oled_def * dev,u8 clk);
/*-------------------------------------------------------
函数名：oled_set_address_mode
描  述：OLED设置地址模式函数，内置函数，不用考虑怎么用。
输  入：
		dev  -  OLED器件的信息包。
		mode -  3个模式影响不大。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-10-23
修改记录：
-------------------------------------------------------*/
extern void oled_set_address_mode(oled_def * dev,u8 mode);
/*-------------------------------------------------------
函数名：oled_set_clk
描  述：OLED设置内置RC参数函数。
输  入：
		dev  -  OLED器件的信息包。
		clk  -  请谨慎输入。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-10-23
修改记录：
-------------------------------------------------------*/
extern void oled_set_clk         (oled_def * dev,u8 clk);
/*程序区折叠专用**************************************************************/#endif
/*-------------------------------------------------------
函数名：oled_show
描  述：OLED显示函数，用于把一个显存显示到屏幕上。
输  入：
		dev   -  OLED器件的信息包。
		dat[] -  显存数组。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-10-23
修改记录：
-------------------------------------------------------*/
extern void oled_show(oled_def * dev,u8 dat[]);
/*-------------------------------------------------------
函数名：oled_init
描  述：OLED初始化函数。
输  入：
		dev  -  OLED器件的信息包。
		w    -  横像素数量，比如128。
		h    -  纵像素数量，比如64。
		xoffset - 横坐标偏移。
		yoffset - 纵坐标偏移。
		mode -  显示模式。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-10-23
修改记录：
-------------------------------------------------------*/
extern void oled_init(oled_def * dev,u8 w,u8 h,u8 xoffset,u8 yoffset,u8 mode);
/*-------------------------------------------------------
函数名：oled_auto_init
描  述：OLED自动初始化函数，只需要描述一下硬件连接就行了。
输  入：
		dev  -  OLED器件的信息包。
		str  -  描述硬件设置的字符串。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-10-23
修改记录：
2020-03-07:修复GND引脚不能正确读取的BUG。
-------------------------------------------------------*/
extern void oled_auto_init(oled_def * dev,char * str);
/*程序区折叠专用***********************调试测试模块*********/#if OLED_DISPLAY_MODE_EN
extern u8 code oled_display_mode_test_buf[];//测试专用字模。仅在测试的时候才定义。
extern u8 code x_start[];//测试专用字模。仅在测试的时候才定义。
/*-------------------------------------------------------
函数名：oled_display_mode_test
描  述：OLED显示模式测试函数。当你不清楚OLED的实际内部连接的时候，可以通过该函数试出来。
输  入：dev  -  需要操作的器件。
		mode -  需要做测试得模式号。一共有16种模式，即0x00~0x0f。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-10-23
修改记录：
-------------------------------------------------------*/
extern void oled_display_mode_test(oled_def * dev,u8 mode);
/*-------------------------------------------------------
函数名：oled_display_y_test
描  述：OLED的Y轴偏移测试函数。当你不清楚OLED从第几行开始显示的时候，可以通过该函数试出来。
输  入：dev  -  需要操作的器件。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-10-23
修改记录：
-------------------------------------------------------*/
extern void oled_display_y_test   (oled_def * dev);
/*-------------------------------------------------------
函数名：oled_display_x_test
描  述：OLED的X轴偏移测试函数。当你不清楚OLED从第几列开始显示的时候，可以通过该函数试出来。
输  入：dev      -  需要操作的器件。
		x_offset -  X轴的偏移量。 
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-10-23
修改记录：
-------------------------------------------------------*/
extern void oled_display_x_test   (oled_def * dev,u8 x_offset);
/*程序区折叠专用************************************************************/#endif
/*程序区折叠专用************************printf模块***************/#if OLED_PRINTF_EN
#include "stdio.h"
extern unsigned char code F6x8[];//6x8的字模，当选用printf功能的时候，需要定义。
/*-------------------------------------------------------
函数名：oled_char
描  述：显示一个字符函数，用于裸屏显示。
输  入：dev  -  需要操作的器件。
		x   -   显示的位置的X轴坐标。
		y   -   显示的位置的Y轴坐标。注意裸屏的Y轴是8个小数一个坐标值。
		ch  -   显示的字符。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-10-23
修改记录：
-------------------------------------------------------*/
extern void oled_char(oled_def * dev,u8 x,u8 y,char ch);
/*-------------------------------------------------------
函数名：oled_printf
描  述：格式化显示字符串函数，用于裸屏显示。
输  入：dev   -  需要操作的器件。
		x     -  显示的位置的X轴坐标。
		y     -  显示的位置的Y轴坐标。注意裸屏的Y轴是8个小数一个坐标值。
		str   -  格式化的字符串。
		...   -   字符串里需要替代的变量的值。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-10-23
修改记录：
-------------------------------------------------------*/
extern void oled_printf(oled_def * dev,u8 x,u8 y,char * str,...);
/*程序区折叠专用**************************************************************/#endif
/*程序区折叠专用***********************显示信息模块***********/#if OLED_INFORMATION_EN 
/*-------------------------------------------------------
函数名：oled_information
描  述：显示当前的OLED的各种信息。当然由于信息较多，只能在128x64的屏幕上才能完整显示完。
输  入：dev   -  需要操作的器件。
输  出：无
返回值：无
创建者：奈特
调用例程：无
创建日期：2019-10-23
修改记录：
-------------------------------------------------------*/
extern void oled_information(oled_def * dev);
/*程序区折叠专用**************************************************************/#endif
#endif
