$NOMOD51
;------------------------------------------------------------------------------
;这个文件是C51编译器包的一部分
;Keil Elektronik GmbH and Keil Software, Inc.版权所有(c) 1988-2005
;版本8.01
;<<< Use Configuration Wizard in Context Menu >>>
;------------------------------------------------------------------------------
;
;用户自定义<h>上电初始化内存
;  使用以下EQU语句初始化内存
;  在处理器复位时可以定义:
;
; <o> IDATALEN: IDATA内存大小 <0x0-0x100>
;     <i> 注意:IDATA内存起始地址的绝对值总是0
;     <i>IDATA空间在物理上与DATA和BIT区域重叠。
IDATALEN        EQU     128
;
; <o> XDATASTART: XDATA内存起始地址 <0x0-0xFFFF> 
;     <i>XDATA内存的绝对起始地址
XDATASTART      EQU     0     
;
; <o> XDATALEN: XDATA内存大小 <0x0-0xFFFF> 
;     <i>XDATA内存长度(以字节为单位)。
XDATALEN        EQU     0      
;
; <o> PDATASTART: PDATA内存起始地址 <0x0-0xFFFF> 
;     <i>PDATA内存的绝对起始地址
PDATASTART      EQU     0
;
; <o> PDATALEN: PDATA内存大小 <0x0-0xFF> 
;     <i>PDATA内存长度(以字节为单位)。
PDATALEN        EQU     0
;
;</h>
;------------------------------------------------------------------------------
;
;<h> 可重入栈的初始化
;
;  下面的EQU语句定义了用于重入的堆栈指针
;  函数并初始化中断:
;
; <h> 在SMALL模型中可重入函数的堆栈空间。
;  <q> IBPSTACK: 启用SMALL模型可重入堆栈
;     <i> 在SMALL模型中可重入函数的堆栈空间。
IBPSTACK        EQU     0       ; 设置为1代表使用small型可重入模型。
;  <o> IBPSTACKTOP: SMALL模型堆栈的结束地址 <0x0-0xFF>
;     <i> 将堆栈顶部设置为最高位置。
IBPSTACKTOP     EQU     0xFF +1     ; 默认 0FFH+1  
; </h>
;
; <h> LARGE模型中可重入函数的堆栈空间。     
;  <q> XBPSTACK: 启用LARGE模型重入堆栈
;     <i> LARGE模型中可重入函数的堆栈空间。
XBPSTACK        EQU     0       ; 设置为1代表使用large型可重入模型。
;  <o> XBPSTACKTOP: LARGE模型堆栈的结束地址 <0x0-0xFFFF>
;     <i> 将堆栈顶部设置为最高位置。
XBPSTACKTOP     EQU     0xFFFF +1   ; 默认 0FFFFH+1 
; </h>
;
; <h> COMPACT模型中可重入函数的堆栈空间。   
;  <q> PBPSTACK: 启用COMPACT模型可重入堆栈
;     <i> COMPACT模型中可重入函数的堆栈空间。
PBPSTACK        EQU     0       ; 设置为1代表使用compact型可重入模型。
;
;   <o> PBPSTACKTOP: COMPACT模型堆栈的结束地址 <0x0-0xFFFF>
;     <i> 将堆栈顶部设置为最高位置。
PBPSTACKTOP     EQU     0xFF +1     ; 默认 0FFH+1  
; </h>
;</h>
;------------------------------------------------------------------------------
;
;  使用64kbyte xdata RAM的紧凑模型的内存页面
;  <e>精简模型页面定义
;
;  <i>定义用于PDATA变量的XDATA页面。 
;  <i>page必须与链接器调用中设置的page一致。
;
; 启用pdata内存页初始化
PPAGEENABLE     EQU     0       ; 如果使用pdata对象，则设置为1。
;
; <o> PPAGE数量 <0x0-0xFF> 
; <i>用于存放PDATA变量的页面数量。其地址最多为256字节。
PPAGE           EQU     0
;
; <o> 提供高8位地址字节的SFR地址 <0x0-0xFF> 
; <i>大多数8051和兼容型号使用P2作为高8位地址字节
PPAGE_SFR       DATA    0A0H
;
; </e>
;------------------------------------------------------------------------------

; 标准的SFR符号
ACC     DATA    0E0H
B       DATA    0F0H
SP      DATA    81H
DPL     DATA    82H
DPH     DATA    83H

                NAME    ?C_STARTUP


?C_C51STARTUP   SEGMENT   CODE
?STACK          SEGMENT   IDATA

                RSEG    ?STACK
                DS      1

                EXTRN CODE (?C_START)
                PUBLIC  ?C_STARTUP

                CSEG    AT      0
?C_STARTUP:     LJMP    STARTUP1

                RSEG    ?C_C51STARTUP

STARTUP1:

IF IDATALEN <> 0
                MOV     R0,#IDATALEN - 1
                CLR     A
IDATALOOP:      MOV     @R0,A
                DJNZ    R0,IDATALOOP
ENDIF

IF XDATALEN <> 0
                MOV     DPTR,#XDATASTART
                MOV     R7,#LOW (XDATALEN)
  IF (LOW (XDATALEN)) <> 0
                MOV     R6,#(HIGH (XDATALEN)) +1
  ELSE
                MOV     R6,#HIGH (XDATALEN)
  ENDIF
                CLR     A
XDATALOOP:      MOVX    @DPTR,A
                INC     DPTR
                DJNZ    R7,XDATALOOP
                DJNZ    R6,XDATALOOP
ENDIF

IF PPAGEENABLE <> 0
                MOV     PPAGE_SFR,#PPAGE
ENDIF

IF PDATALEN <> 0
                MOV     R0,#LOW (PDATASTART)
                MOV     R7,#LOW (PDATALEN)
                CLR     A
PDATALOOP:      MOVX    @R0,A
                INC     R0
                DJNZ    R7,PDATALOOP
ENDIF

IF IBPSTACK <> 0
EXTRN DATA (?C_IBP)

                MOV     ?C_IBP,#LOW IBPSTACKTOP
ENDIF

IF XBPSTACK <> 0
EXTRN DATA (?C_XBP)

                MOV     ?C_XBP,#HIGH XBPSTACKTOP
                MOV     ?C_XBP+1,#LOW XBPSTACKTOP
ENDIF

IF PBPSTACK <> 0
EXTRN DATA (?C_PBP)
                MOV     ?C_PBP,#LOW PBPSTACKTOP
ENDIF

                MOV     SP,#?STACK-1

; This code is required if you use L51_BANK.A51 with Banking Mode 4
;<h> Code Banking
; <q> Select Bank 0 for L51_BANK.A51 Mode 4
#if 0   
;     <i> Initialize bank mechanism to code bank 0 when using L51_BANK.A51 with Banking Mode 4.
EXTRN CODE (?B_SWITCH0)
                CALL    ?B_SWITCH0      ; init bank mechanism to code bank 0
#endif
;</h>
                LJMP    ?C_START

                END
