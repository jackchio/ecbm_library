#include "ecbm_core.h"  //统一加载核心头文件
#if (ECBM_LCD_LIB_EN)      //检查本库有没有被使能
/*--------------------------------------变量定义-----------------------------------*/
union{
    u32 num32;
    u16 num16[2];
    u8  num8[4];
}lcd_cout;
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
液晶初始化函数。
-------------------------------------------------------*/
void lcd_init(void){
	u32	value_u32,clk_u32,com_u32;
    com_u32=0;
    #if (ECBM_LCD_COMX_EN&0x01)
        gpio_mode(D50,GPIO_HZ);//P5.0设置为高阻输入COM0
        com_u32++;
    #endif
    #if (ECBM_LCD_COMX_EN&0x02)
        gpio_mode(D51,GPIO_HZ);//P5.1设置为高阻输入COM1
        com_u32++;
    #endif
    #if (ECBM_LCD_COMX_EN&0x04)
        gpio_mode(D35,GPIO_HZ);//P3.5设置为高阻输入COM2
        com_u32++;
    #endif
    #if (ECBM_LCD_COMX_EN&0x08)
        gpio_mode(D36,GPIO_HZ);//P3.6设置为高阻输入COM3
        com_u32++;
    #endif  
    LCD_SET_REG_CFG(ECBM_LCD_CFG);
	LCD_SET_REG_DBLEN(ECBM_LCD_DBLEN);// 设置LCD显示时的死区时间长度, 取值0~7.
    #if (ECBM_LCD_CFG&0x80)
        clk_u32=32768;
    #else
        clk_u32=ECBM_SYSCLK_SETTING;
    #endif
    value_u32=clk_u32/(2*com_u32*ECBM_LCD_FRAMERATE)-1-ECBM_LCD_DBLEN;
    
    lcd_cout.num32=value_u32;
    LCD_SET_REG_COMLENL(lcd_cout.num8[3]);// COM时间长度设置 低字节COMLEN[7:0]
    LCD_SET_REG_COMLENM(lcd_cout.num8[2]);// COM时间长度设置 中字节COMLEN[15:8]
    LCD_SET_REG_COMLENH(lcd_cout.num8[1]);// COM时间长度设置 高字节COMLEN[19:16]


    LCD_SET_REG_BLINKRATE(ECBM_LCD_FRAMERATE/ECBM_LCD_BLANKRATE);// 闪烁率配置寄存器, LCD闪烁率 = LCD刷新率 / BLINKRATE[7:0] Hz
	LCD_SET_REG_COMON(ECBM_LCD_COMX_EN);    // COM使能寄存器
    LCD_SET_REG_SEGON1(ECBM_LCD_SEG0_EN|ECBM_LCD_SEG1_EN|ECBM_LCD_SEG2_EN|ECBM_LCD_SEG3_EN|ECBM_LCD_SEGON1);// SEG线使能寄存器1, SEG7~SEG0
    LCD_SET_REG_SEGON2(ECBM_LCD_SEGON2);// SEG线使能寄存器2, SEG15~SEG8
    LCD_SET_REG_SEGON3(ECBM_LCD_SEGON3);// SEG线使能寄存器3, SEG23~SEG16
    LCD_SET_REG_SEGON4(ECBM_LCD_SEGON4);// SEG线使能寄存器4, SEG31~SEG24
    LCD_SET_REG_SEGON5(ECBM_LCD_SEGON5);// SEG线使能寄存器5, SEG39~SEG32
    LCD_SET_REG_CFG2(ECBM_LCD_CFG2_SEG0|ECBM_LCD_CFG2_SEG1|ECBM_LCD_CFG2_SEG2|ECBM_LCD_CFG2_SEG3);
    #if (ECBM_LCD_SEG0_EN==0x01)
        #if (ECBM_LCD_CFG2_SEG0==0x00)
            gpio_mode(D15,GPIO_HZ);//P1.5设置为高阻输入SEG0
        #else
            gpio_mode(D77,GPIO_HZ);//P7.7设置为高阻输入SEG0
        #endif
    #endif
    #if (ECBM_LCD_SEG1_EN==0x02)
        #if (ECBM_LCD_CFG2_SEG1==0x00)
            gpio_mode(D14,GPIO_HZ);//P1.4设置为高阻输入SEG1
        #else
            gpio_mode(D76,GPIO_HZ);//P7.6设置为高阻输入SEG1
        #endif
    #endif
    #if (ECBM_LCD_SEG2_EN==0x04)
        #if (ECBM_LCD_CFG2_SEG2==0x00)
            gpio_mode(D13,GPIO_HZ);//P1.3设置为高阻输入SEG2
        #else
            gpio_mode(D75,GPIO_HZ);//P7.5设置为高阻输入SEG2
        #endif
    #endif
    #if ((ECBM_LCD_SEG3_EN==0x08)&&(ECBM_LCD_CFG2_SEG3==0x08))
        gpio_mode(D74,GPIO_HZ);//P7.4设置为高阻输入SEG3
    #endif
    #if (ECBM_LCD_SEGON1&0x10)
        gpio_mode(D47,GPIO_HZ);//P4.7设置为高阻输入SEG4
    #endif
    #if (ECBM_LCD_SEGON1&0x20)
        gpio_mode(D11,GPIO_HZ);//P1.1设置为高阻输入SEG5
    #endif    
    #if (ECBM_LCD_SEGON1&0x40)
        gpio_mode(D10,GPIO_HZ);//P1.0设置为高阻输入SEG6
    #endif     
    #if (ECBM_LCD_SEGON1&0x80)
        gpio_mode(D07,GPIO_HZ);//P0.7设置为高阻输入SEG7
    #endif     
    #if (ECBM_LCD_SEGON2&0x01)
        gpio_mode(D06,GPIO_HZ);//P0.6设置为高阻输入SEG8
    #endif     
    #if (ECBM_LCD_SEGON2&0x02)
        gpio_mode(D05,GPIO_HZ);//P0.5设置为高阻输入SEG9
    #endif       
    #if (ECBM_LCD_SEGON2&0x04)
        gpio_mode(D53,GPIO_HZ);//P5.3设置为高阻输入SEG10
    #endif   
    #if (ECBM_LCD_SEGON2&0x08)
        gpio_mode(D52,GPIO_HZ);//P5.2设置为高阻输入SEG11
    #endif       
    #if (ECBM_LCD_SEGON2&0x10)
        gpio_mode(D04,GPIO_HZ);//P0.4设置为高阻输入SEG12
    #endif           
    #if (ECBM_LCD_SEGON2&0x20)
        gpio_mode(D03,GPIO_HZ);//P0.3设置为高阻输入SEG13
    #endif        
    #if (ECBM_LCD_SEGON2&0x40)
        gpio_mode(D02,GPIO_HZ);//P0.2设置为高阻输入SEG14
    #endif        
    #if (ECBM_LCD_SEGON2&0x80)
        gpio_mode(D01,GPIO_HZ);//P0.1设置为高阻输入SEG15
    #endif        
    #if (ECBM_LCD_SEGON3&0x01)
        gpio_mode(D00,GPIO_HZ);//P0.0设置为高阻输入SEG16
    #endif     
    #if (ECBM_LCD_SEGON3&0x02)
        gpio_mode(D46,GPIO_HZ);//P4.6设置为高阻输入SEG17
    #endif       
    #if (ECBM_LCD_SEGON3&0x04)
        gpio_mode(D45,GPIO_HZ);//P4.5设置为高阻输入SEG18
    #endif   
    #if (ECBM_LCD_SEGON3&0x08)
        gpio_mode(D27,GPIO_HZ);//P2.7设置为高阻输入SEG19
    #endif       
    #if (ECBM_LCD_SEGON3&0x10)
        gpio_mode(D26,GPIO_HZ);//P2.6设置为高阻输入SEG20
    #endif           
    #if (ECBM_LCD_SEGON3&0x20)
        gpio_mode(D25,GPIO_HZ);//P2.5设置为高阻输入SEG21
    #endif        
    #if (ECBM_LCD_SEGON3&0x40)
        gpio_mode(D24,GPIO_HZ);//P2.4设置为高阻输入SEG22
    #endif        
    #if (ECBM_LCD_SEGON3&0x80)
        gpio_mode(D23,GPIO_HZ);//P2.3设置为高阻输入SEG23
    #endif    
    #if (ECBM_LCD_SEGON4&0x01)
        gpio_mode(D22,GPIO_HZ);//P2.2设置为高阻输入SEG24
    #endif     
    #if (ECBM_LCD_SEGON4&0x02)
        gpio_mode(D21,GPIO_HZ);//P2.1设置为高阻输入SEG25
    #endif       
    #if (ECBM_LCD_SEGON4&0x04)
        gpio_mode(D20,GPIO_HZ);//P2.0设置为高阻输入SEG26
    #endif   
    #if (ECBM_LCD_SEGON4&0x08)
        gpio_mode(D44,GPIO_HZ);//P4.4设置为高阻输入SEG27
    #endif       
    #if (ECBM_LCD_SEGON4&0x10)
        gpio_mode(D43,GPIO_HZ);//P4.3设置为高阻输入SEG28
    #endif           
    #if (ECBM_LCD_SEGON4&0x20)
        gpio_mode(D42,GPIO_HZ);//P4.2设置为高阻输入SEG29
    #endif        
    #if (ECBM_LCD_SEGON4&0x40)
        gpio_mode(D41,GPIO_HZ);//P4.1设置为高阻输入SEG30
    #endif        
    #if (ECBM_LCD_SEGON4&0x80)
        gpio_mode(D37,GPIO_HZ);//P3.7设置为高阻输入SEG31
    #endif 
    #if (ECBM_LCD_SEGON5&0x01)
        gpio_mode(D73,GPIO_HZ);//P7.3设置为高阻输入SEG32
    #endif     
    #if (ECBM_LCD_SEGON5&0x02)
        gpio_mode(D72,GPIO_HZ);//P7.2设置为高阻输入SEG33
    #endif       
    #if (ECBM_LCD_SEGON5&0x04)
        gpio_mode(D71,GPIO_HZ);//P7.1设置为高阻输入SEG34
    #endif   
    #if (ECBM_LCD_SEGON5&0x08)
        gpio_mode(D70,GPIO_HZ);//P7.0设置为高阻输入SEG35
    #endif       
    #if (ECBM_LCD_SEGON5&0x10)
        gpio_mode(D60,GPIO_HZ);//P6.0设置为高阻输入SEG36
    #endif           
    #if (ECBM_LCD_SEGON5&0x20)
        gpio_mode(D61,GPIO_HZ);//P6.1设置为高阻输入SEG37
    #endif        
    #if (ECBM_LCD_SEGON5&0x40)
        gpio_mode(D62,GPIO_HZ);//P6.2设置为高阻输入SEG38
    #endif        
    #if (ECBM_LCD_SEGON5&0x80)
        gpio_mode(D63,GPIO_HZ);//P6.3设置为高阻输入SEG39
    #endif   
    
    LCD_SET_REG_C0S0_7(0);
    LCD_SET_REG_C0S8_15(0);
    LCD_SET_REG_C0S16_23(0);
    LCD_SET_REG_C0S24_31(0);
    LCD_SET_REG_C0S32_39(0);
    LCD_SET_REG_C1S0_7(0);
    LCD_SET_REG_C1S8_15(0);
    LCD_SET_REG_C1S16_23(0);
    LCD_SET_REG_C1S24_31(0);
    LCD_SET_REG_C1S32_39(0);
    LCD_SET_REG_C2S0_7(0);
    LCD_SET_REG_C2S8_15(0);
    LCD_SET_REG_C2S16_23(0);
    LCD_SET_REG_C2S24_31(0);
    LCD_SET_REG_C2S32_39(0);
    LCD_SET_REG_C3S0_7(0);
    LCD_SET_REG_C3S8_15(0);
    LCD_SET_REG_C3S16_23(0);
    LCD_SET_REG_C3S24_31(0);
    LCD_SET_REG_C3S32_39(0);
   
    LCD_SET_REG_CR(ECBM_LCD_CR);
    LCD_POWER_ON;
}

void lcd_write(u8 com,u8 group,u8 dat){
    switch(com){
        default:break;
        case 0:{ 
            switch(group){
                default:break;
                case 0:{LCD_SET_REG_C0S0_7(dat);}break;
                case 1:{LCD_SET_REG_C0S8_15(dat);}break;
                case 2:{LCD_SET_REG_C0S16_23(dat);}break;
                case 3:{LCD_SET_REG_C0S24_31(dat);}break;   
                case 4:{LCD_SET_REG_C0S32_39(dat);}break;      
            }
        }break;
        case 1:{
            switch(group){
                default:break;
                case 0:{LCD_SET_REG_C1S0_7(dat);}break;
                case 1:{LCD_SET_REG_C1S8_15(dat);}break;
                case 2:{LCD_SET_REG_C1S16_23(dat);}break;
                case 3:{LCD_SET_REG_C1S24_31(dat);}break;   
                case 4:{LCD_SET_REG_C1S32_39(dat);}break;      
            }
        }break;   
        case 2:{
            switch(group){
                default:break;
                case 0:{LCD_SET_REG_C2S0_7(dat);}break;
                case 1:{LCD_SET_REG_C2S8_15(dat);}break;
                case 2:{LCD_SET_REG_C2S16_23(dat);}break;
                case 3:{LCD_SET_REG_C2S24_31(dat);}break;   
                case 4:{LCD_SET_REG_C2S32_39(dat);}break;      
            }        
        }break;
        case 3:{
            switch(group){
                default:break;
                case 0:{LCD_SET_REG_C3S0_7(dat);}break;
                case 1:{LCD_SET_REG_C3S8_15(dat);}break;
                case 2:{LCD_SET_REG_C3S16_23(dat);}break;
                case 3:{LCD_SET_REG_C3S24_31(dat);}break;   
                case 4:{LCD_SET_REG_C3S32_39(dat);}break;      
            }          
        }break;       
    }
}
#endif  //和最上面的#ifndef配合成一个程序段。
        //以一个空行为结尾。