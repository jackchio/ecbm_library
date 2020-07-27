#ifndef _ECBM_LCD1602_H_
#define _ECBM_LCD1602_H_
/*-------------------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2019 ����

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

����˵����
	���������MIT��ԴЭ�����������ṩ������ֻ��֤ԭʼ�汾����������ά����BUG��
����ͨ�����紫���İ汾Ҳ�������޸Ĺ����ɴ˳��ֵ�BUG�������޹ء�������ʹ��ԭʼ
�汾����BUGʱ������ϵ���߽����
                             **************************
                             * ��ϵ��ʽ����Ⱥ778916610 *
							 ************************** 
------------------------------------------------------------------------------------*///���ǿ�ԴЭ�飬������ͼ�ν���ѡ�
//-------------------------------������ͼ�����ý��棬����Configuration Wizard��������----------------------------------------------------------
//<<< Use Configuration Wizard in Context Menu >>>
//<q>ECBM��������ʹ��
//<i>��ѡ��򹴣���ζ��LCD1602���ʹ��ECBM�����������������gpio���gpio_mode��������ֻҪECBM���������Ͳ����б����ϵ����⡣����֧�ֶ������µĴ��븴�á�
//<i>��ѡ��򹴣���ζ��LCD1602���ܵ���ʹ�ã���������������ECBM�⺯������Ҫ��ֲ�����Ĺ��캯��������ʱ���ټ���ECBM������ض��屨��Ŀ��ܣ���ע�⡣
#define ECBM_LINK_LCD1602_BIT 1 //��ECBM�����ӵ�ʹ�ܣ�������������ⵥ��ʹ��LCD1602���裬����Ϊ0��
//<<< end of configuration section >>>
//-------------------------------������ͼ�����ý��棬����Configuration Wizard��������----------------------------------------------------------

#define LCD_CMD 0            //���崫���������ָ��
#define LCD_DAT 1            //���崫�������������
#define LCD_CURSOR_ON        0x02//�й��
#define LCD_CURSOR_OFF       0x00//�޹��
#define LCD_CURSOR_ON_FLASH  0x03//�й�겢��˸
#define LCD_CURSOR_OFF_FLASH 0x01//�޹�겢��˸
#define LCD_CURSOR_LEFT      0x10//�������
#define LCD_CURSOR_RIGHT     0x14//�������

#if ECBM_LINK_LCD1602_BIT     //�����Ҫ��������
#include "ecbm_core.h"            //����ecbmͷ�ļ�
typedef struct{
	u8 lcd_rs_port;          //��ӦRS��
	u8 lcd_rs_pin;
	u8 lcd_rw_port;          //��ӦRW��
	u8 lcd_rw_pin;
	u8 lcd_en_port;          //��ӦEN��
	u8 lcd_en_pin;
	u8 lcd_data_port;        //��ӦD0~D7
}lcd1602_def;
void lcd_write(lcd1602_def * dev,bit cla,u8 dat){//д�뺯��
	gpio_out_fast(dev->lcd_rs_port,dev->lcd_rs_pin,cla);		
	gpio_out_fast(dev->lcd_rw_port,dev->lcd_rw_pin,0);
	gpio_write(dev->lcd_data_port,dat);
	delay_ms(1);
	gpio_out_fast(dev->lcd_en_port,dev->lcd_en_pin,1);
	gpio_out_fast(dev->lcd_en_port,dev->lcd_en_pin,0);
}
void lcd_clear(lcd1602_def * dev){//��������Ҫms�����ʱ�䡣
	lcd_write(dev,LCD_CMD,0x01);
}
void lcd_reset_cursor(lcd1602_def * dev){//���ص����Ͻ�
	lcd_write(dev,LCD_CMD,0x02);
}
void lcd_set_cursor(lcd1602_def * dev,u8 cmd){//����������
	if(cmd<4)lcd_write(dev,LCD_CMD,0x0C|cmd);
	else lcd_write(dev,LCD_CMD,cmd);
}
void lcd1602_printf(lcd1602_def * dev,u8 hang,u8 lie,char * str,...){//��ӡ���������ַ���ӡ��LCD1602��
	char xdata buf[16],n,i;
	va_list vp;
    va_start(vp, str);
    n=vsprintf(buf,str,vp);
    va_end(vp);
	if(hang==0){
		lcd_write(dev,LCD_CMD,0x80+lie); 
	}else if(hang==1){
		lcd_write(dev,LCD_CMD,0xC0+lie); 
	}
	for(i=0;i<n;i++){
		lcd_write(dev,LCD_DAT,buf[i]); 
	}
}
void lcd1602_init(lcd1602_def * dev,u8 rs,u8 rw,u8 en,u8 port){//��ʼ����������Ҫ�ṩʹ�õ�IO����Ϣ
	dev->lcd_rs_port=io2port(rs);
	dev->lcd_rs_pin=io2pin(rs);
	dev->lcd_rw_port=io2port(rw);
	dev->lcd_rw_pin=io2pin(rw);
	dev->lcd_en_port=io2port(en);
	dev->lcd_en_pin=io2pin(en);
	dev->lcd_data_port=port;
	lcd_write(dev,LCD_CMD,0x38);//8λ���ݣ�˫�У�5*7���� 
	lcd_write(dev,LCD_CMD,0x0C);//������ʾ�����ع�꣬��겻��˸ 
	lcd_write(dev,LCD_CMD,0x06);//��ʾ��ַ��������дһ�����ݺ���ʾλ������һλ 
	lcd_clear(dev);//���� 
	delay_ms(2);
}
#else    //��������ʹ���������￪ʼ��ֲ
#include "intrins.h"
#include <STDARG.H>
#include <stdio.h>
#define u8 unsigned char
sbit lcd_rs=P5^0;    //�޸�ʹ�õ�IO��
sbit lcd_rw=P5^1;    //�޸�ʹ�õ�IO��
sbit lcd_en=P5^2;    //�޸�ʹ�õ�IO��
#define lcd_data P4  //�޸�ʹ�õ�IO��
void Delay1ms()		 //��STC-ISP������
{
	unsigned char i, j;

	_nop_();
	_nop_();
	_nop_();
	i = 11;
	j = 190;
	do
	{
		while (--j);
	} while (--i);
}
void lcd_write(bit cla,u8 dat){
	lcd_rs=cla;		
	lcd_rw=0;
	lcd_data=dat;
	Delay1ms();
	lcd_en=1;
	lcd_en=0;
}
void lcd_clear(){
	lcd_write(LCD_CMD,0x01);
}
void lcd_reset_cursor(){
	lcd_write(LCD_CMD,0x02);
}
void lcd_set_cursor(u8 cmd){
	if(cmd<4)lcd_write(LCD_CMD,0x0C|cmd);
	else lcd_write(LCD_CMD,cmd);
}

void lcd1602_printf(u8 hang,u8 lie,char * str,...){
	char xdata buf[16],n,i;
	va_list vp;
    va_start(vp, str);
    n=vsprintf(buf,str,vp);
    va_end(vp);
	if(hang==0){
		lcd_write(LCD_CMD,0x80+lie); 
	}else if(hang==1){
		lcd_write(LCD_CMD,0xC0+lie); 
	}
	for(i=0;i<n;i++){
		lcd_write(LCD_DAT,buf[i]); 
	}
}
void lcd1602_init(){
	lcd_write(LCD_CMD,0x38);//8λ���ݣ�˫�У�5*7���� 
	lcd_write(LCD_CMD,0x0C);//������ʾ�����ع�꣬��겻��˸ 
	lcd_write(LCD_CMD,0x06);//��ʾ��ַ��������дһ�����ݺ���ʾλ������һλ 
	lcd_clear();//���� 
	Delay1ms();
	Delay1ms();
}
#endif
#endif
