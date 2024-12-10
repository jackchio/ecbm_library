#include "ecbm_core.h"  //统一加载核心头文件
#if (ECBM_POWER_LIB_EN) //检查本库有没有被使能
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
复位函数，复位之后从main函数开始运行。
-------------------------------------------------------*/
#if (ECBM_POWER_RESET_EN)
    void power_reset_code(void){
        _nop_();
        MCU_RESET;
        _nop_();
        _nop_();
    }
#endif
/*-------------------------------------------------------
复位函数，复位之后从系统BootLoader开始运行。
-------------------------------------------------------*/
#if (ECBM_POWER_RESET_EN)
    void power_reset_isp(void){
        _nop_();
        POWER_RESET;
        _nop_();
        _nop_();
    }
#endif
/*-------------------------------------------------------
掉电函数。
-------------------------------------------------------*/
#if (ECBM_POWER_CONTROL_EN)
    void power_powerdown(void){
        #if (ECBM_POWER_WKTC_CONFIG&0x8000)    //如果开了唤醒定时器使能。
            WKT_SET_REG_COUNT(ECBM_POWER_WKTC_CONFIG);//就给唤醒定时器赋值。
        #endif
        _nop_();
        POWER_DOWN;
        _nop_();
        _nop_();
    }
#endif   
/*-------------------------------------------------------
CPU空闲函数。
-------------------------------------------------------*/
#if (ECBM_POWER_CONTROL_EN)
    void power_cpu_idle(void){
        _nop_();
        POWER_IDLE;
        _nop_();
        _nop_();
    }
#endif
/*----------------------------
看门狗开启函数
-----------------------------*/
#if (ECBM_POWER_WDOG_EN)
    void wdt_start(void){
        WDT_SET_REG_CONTR(ECBM_POWER_WDT_MODE|EN_WDT);
    }
#endif
/*----------------------------
喂狗函数
-----------------------------*/
#if (ECBM_POWER_WDOG_EN)
    void wdt_feed(void){
        WDT_CLR;
    }
#endif
/*-------------------------------------------------------
复位寄存器初始化函数。
-------------------------------------------------------*/
#if (ECBM_POWER_RST_CFG_EN)
    void power_rstcfg_init(void){
        SYS_SET_REG_RSTCFG(ECBM_POWER_RST_CFG_MODE);
    }
#endif
#endif  //和最上面的#ifndef配合成一个程序段。
        //以一个空行为结尾。