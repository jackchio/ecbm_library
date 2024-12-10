#ifndef _ECBM_KEY_H_//头文件防止重加载必备，先看看有没有定义过这个，定义说明已经加载过一次了。
#define _ECBM_KEY_H_//没定义说明是首次加载，那么往下执行。并且定义这个宏定义，防止下一次被加载。
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
//------------------------------------------------------------------------------
#define key_u8 unsigned char
//------------------------------------------------------------------------------
#define KEY_EVENT_DOWN         0x01//按下事件
#define KEY_EVENT_ONE          0x02//单按事件
#define KEY_EVENT_HOLD         0x04//长按事件
#define KEY_EVENT_DOUBLE       0x08//双击事件

#define KEY_EVENT_LEVEL_DOWN   0x10//电平低事件（相对电平）
#define KEY_EVENT_LEVEL_UP     0x20//电平高事件（相对电平）
#define KEY_EVENT_EDGE_DOWN    0x40//电平下降事件（相对电平）
#define KEY_EVENT_EDGE_UP      0x80//电平上升事件（相对电平）

#define KEY_EVENT_HOLD_LOCK    0x01//长按锁定
#define KEY_EVENT_DOUBLE1_LOCK 0x02//双击1锁定
#define KEY_EVENT_DOUBLE2_LOCK 0x04//双击2锁定
//------------------------------------------------------------------------------
typedef struct{
    key_u8 key_val;       //本次的按键值
    key_u8 key_old_val;   //上次的按键值
    key_u8 key_up;        //抬起的键值
    key_u8 key_down;      //按下的键值
    key_u8 key_up_count;  //抬起的计时
    key_u8 key_down_count;//按下的计时
    key_u8 key_min_time;  //最小判定时间
    key_u8 key_max_time;  //最大判定时间
    key_u8 key_event;     //按键事件
    key_u8 key_lock;      //操作锁定值。
}key_def;
/*------------------------------------------------------------------------------
程序名：key_init
描  述：按键初始化函数
输  入：
    dev         要初始化的器件
    up_val      按键抬起时的键值
    down_val    按键按下时的键值
    min_time    按键最小判断时间（和双击有关）
    max_time    按键最大判断时间（和长按有关）
输  出：
    dev         初始化之后的器件
返回值：无
创建人：奈特
创建日期：2020-06-28
更改日期：
版本历史：
------------------------------------------------------------------------------*/
extern void key_init(key_def * dev,key_u8 up_val,key_u8 down_val,key_u8 min_time,key_u8 max_time);
/*------------------------------------------------------------------------------
程序名：key_deal
描  述：按键处理函数
输  入：
    dev     要处理的按键
    val     按键的键值
输  出：
    dev     按键的状态
返回值：无
创建人：奈特
创建日期：2020-06-28
更改日期：
版本历史：
------------------------------------------------------------------------------*/
extern void key_deal(key_def * dev,key_u8 val);
#endif  //和最上面的#ifndef配合成一个程序段。
        //以一个空行为结尾。