#ifndef _ECBM_EDS_H_//头文件防止重加载必备，先看看有没有定义过这个，定义说明已经加载过一次了。
#define _ECBM_EDS_H_//没定义说明是首次加载，那么往下执行。并且定义这个宏定义，防止下一次被加载。
/*-------------------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2023 奈特

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
                            ***************************
                            * 联系方式 ：进群778916610 *
                            * 若1群满人：进群927297508 *
                            ***************************
------------------------------------------------------------------------------------*/
//-----------------以下是图形设置界面，可在Configuration Wizard界面设置-----------------
//<<< Use Configuration Wizard in Context Menu >>>
//<o>读取校验和出错后的处理方式
//<i>当读取的时候出现校验和错误，可以选择自己处理或者自动回滚。
//<i>为了防止无止境的回滚导致死循环，回滚次数最大为5次，5次之后还是错误的话，也还是需要自己处理。
//<i>通常由意外断电引起的写入错误，只需要回滚一次就可以了。如果真的出现5次都错的情况，还请增加硬件上的防护或者检查业务代码是否有改写EDS所在扇区的语句。
//<1=>自行处理
//<5=>回滚数据
#define EDS_ERROR_SUM_HANDLING (5)
//<<< end of configuration section >>>
//-----------------以上是图形设置界面，可在Configuration Wizard界面设置-----------------
/*-------------------------------------头文件加载-----------------------------------*/
#include "ecbm_core.h"    //ECBM库的头文件，里面已经包含了STC8的头文件。
/*---------------------------------------宏定义------------------------------------*/
#define EDS_OK          (0)   //EDS操作正常。
#define EDS_ERR_NULL    (1)   //找不到EDS标识，说明该扇区没有在EDS的管理当中。
#define EDS_ERR_ID      (2)   //EDS中的ID错误，说明该地址可能不是EDS管理的首扇区。
#define EDS_ERR_SECTOR  (3)   //EDS初始化时扇区没设置对。

#define EDS_ERR_SUM     (4)   //EDS数据校验和错误。
#define EDS_ERR_DATA    (5)   //EDS数据错误。 

#define EDS_WAR_DATA    (6)   //EDS数据警告，该数据可能不是最新的。

#define EDS_DATA_VOID   (7)   //EDS内没有数据。
#define EDS_DATA_EXISTS (8)   //EDS数据已存在，跳过本次写入操作。
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
函数名：eds_init
描  述：eds初始化函数。
输  入：
    sector_start    起始扇区。
    sector_szie     扇区数量/总大小。
    pack_len        数据包大小。
输  出：无
返回值：
    EDS_OK          EDS所有都正常。
    EDS_ERR_SECTOR  EDS初始化时扇区没设置对。
    EDS_DATA_VOID   EDS内没有数据。
创建者：奈特
调用例程：无
创建日期：2022-04-21
修改记录：
-------------------------------------------------------*/
extern u8 eds_init(u8 sector_start,u8 sector_szie,u16 pack_len);
/*-------------------------------------------------------
函数名：eds_write
描  述：eds写函数。
输  入：
    sector_start    起始扇区。
    buf             要写入的数据包。
输  出：无
返回值：
    EDS_OK          EDS所有都正常。
    EDS_ERR_NULL    找不到EDS。
    EDS_ERR_ID      EDS中的ID错误。
    EDS_DATA_VOID   EDS内没有数据。
创建者：奈特
调用例程：无
创建日期：2022-04-21
修改记录：
-------------------------------------------------------*/
extern u8 eds_write(u8 sector_start,u8 * buf);
/*-------------------------------------------------------
函数名：eds_read
描  述：eds读函数。
输  入：
    sector_start    起始扇区。
输  出：
    buf             读取到的数据包。
返回值：
    EDS_OK          EDS所有都正常。
    EDS_ERR_NULL    找不到EDS。
    EDS_ERR_ID      EDS中的ID错误。
    EDS_DATA_VOID   EDS内没有数据。
创建者：奈特
调用例程：无
创建日期：2022-04-21
修改记录：
-------------------------------------------------------*/
extern u8 eds_read(u8 sector_start,u8 * buf);
#endif  //和最上面的#ifndef配合成一个程序段。
        //以一个空行为结尾。