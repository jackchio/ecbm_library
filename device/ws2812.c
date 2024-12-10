#include "ws2812.h"//����ͷ�ļ�
/*------------------------------------��Դȱʧ����---------------------------------*/
#if (ECBM_DELAY_EN==0)
#   error WS2812��ʹ�õ���delay_us,���delay��ʹ��!
#endif
/*-------------------------------------���ݽŶ���-----------------------------------*/
sbit WS2812_IO=(ECBM_WS2812_IO_PORT+ECBM_WS2812_IO_PIN);
/*--------------------------------------��������-----------------------------------*/
u8 bdata ws2818_buf;            //�ڲ�ʹ�ñ�����������λ������ϡ�
u16 ws2818_delay_300us;         //�ڲ�ʹ�ñ�������¼��ʱ300uS�����ʱ������
sbit ws2818_buf_bit=ws2818_buf^7;//�ڲ�ʹ�ñ��������ڻ�ȡ���������D7λ��
/*--------------------------------------��ʱ����-----------------------------------*/
#if     (ECBM_SYSCLK_SETTING == 5529600UL)//����ϵͳʱ����ѡ��ϵ����
#   error Ƶ��̫�Ͳ�������ͨ������!
#elif   (ECBM_SYSCLK_SETTING == 6000000UL)
#   error Ƶ��̫�Ͳ�������ͨ������!
#elif   (ECBM_SYSCLK_SETTING == 11059200UL)
//580nS~1uS
#define WS2812_DELAY_T1H    {_nop_();_nop_();_nop_();_nop_();_nop_();}
//580nS~1uS
#define WS2812_DELAY_T1L    {}
//220nS~380nS
#define WS2812_DELAY_T0H    {}
//580nS~1uS
#define WS2812_DELAY_T0L    {}
#elif   (ECBM_SYSCLK_SETTING == 12000000UL)
//580nS~1uS
#define WS2812_DELAY_T1H    {_nop_();_nop_();_nop_();_nop_();_nop_();}
//580nS~1uS
#define WS2812_DELAY_T1L    {}
//220nS~380nS
#define WS2812_DELAY_T0H    {}
//580nS~1uS
#define WS2812_DELAY_T0L    {}
#elif   (ECBM_SYSCLK_SETTING == 18432000UL)
//580nS~1uS
#define WS2812_DELAY_T1H    {_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();}
//580nS~1uS
#define WS2812_DELAY_T1L    {}
//220nS~380nS
#define WS2812_DELAY_T0H    {_nop_();_nop_();}
//580nS~1uS
#define WS2812_DELAY_T0L    {_nop_();_nop_();_nop_();}
#elif   (ECBM_SYSCLK_SETTING == 20000000UL)
//580nS~1uS
#define WS2812_DELAY_T1H    {_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();}
//580nS~1uS
#define WS2812_DELAY_T1L    {_nop_();}
//220nS~380nS
#define WS2812_DELAY_T0H    {_nop_();_nop_();_nop_();}
//580nS~1uS
#define WS2812_DELAY_T0L    {_nop_();_nop_();_nop_();_nop_();}
#elif   (ECBM_SYSCLK_SETTING == 22118400UL)
//580nS~1uS
#define WS2812_DELAY_T1H    {_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();}
//580nS~1uS
#define WS2812_DELAY_T1L    {_nop_();_nop_();}
//220nS~380nS
#define WS2812_DELAY_T0H    {_nop_();_nop_();_nop_();_nop_();}
//580nS~1uS
#define WS2812_DELAY_T0L    {_nop_();_nop_();_nop_();_nop_();_nop_();}
#elif   (ECBM_SYSCLK_SETTING == 24000000UL)
//580nS~1uS
#define WS2812_DELAY_T1H    {_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();}
//580nS~1uS
#define WS2812_DELAY_T1L    {_nop_();_nop_();_nop_();}
//220nS~380nS
#define WS2812_DELAY_T0H    {_nop_();_nop_();_nop_();_nop_();_nop_();}
//580nS~1uS
#define WS2812_DELAY_T0L    {_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();}
#elif   (ECBM_SYSCLK_SETTING == 26000000UL)
//580nS~1uS
#define WS2812_DELAY_T1H    {_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();}
//580nS~1uS
#define WS2812_DELAY_T1L    {_nop_();_nop_();_nop_();_nop_();_nop_();}
//220nS~380nS
#define WS2812_DELAY_T0H    {_nop_();_nop_();_nop_();_nop_();_nop_();}
//580nS~1uS
#define WS2812_DELAY_T0L    {_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();}
#elif   (ECBM_SYSCLK_SETTING == 27000000UL)
//580nS~1uS
#define WS2812_DELAY_T1H    {_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();}
//580nS~1uS
#define WS2812_DELAY_T1L    {_nop_();_nop_();_nop_();_nop_();_nop_();}
//220nS~380nS
#define WS2812_DELAY_T0H    {_nop_();_nop_();_nop_();_nop_();_nop_();}
//580nS~1uS
#define WS2812_DELAY_T0L    {_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();}
#elif   (ECBM_SYSCLK_SETTING == 30000000UL)
//580nS~1uS
#define WS2812_DELAY_T1H    {_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();}
//580nS~1uS
#define WS2812_DELAY_T1L    {_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();}
//220nS~380nS
#define WS2812_DELAY_T0H    {_nop_();_nop_();_nop_();_nop_();_nop_();}
//580nS~1uS
#define WS2812_DELAY_T0L    {_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();}
#elif   (ECBM_SYSCLK_SETTING == 33000000UL)
//580nS~1uS
#define WS2812_DELAY_T1H    {_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();}
//580nS~1uS
#define WS2812_DELAY_T1L    {_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();}
//220nS~380nS
#define WS2812_DELAY_T0H    {_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();}
//580nS~1uS
#define WS2812_DELAY_T0L    {_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();}
#elif   (ECBM_SYSCLK_SETTING == 33177600UL)
//580nS~1uS
#define WS2812_DELAY_T1H    {_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();}
//580nS~1uS
#define WS2812_DELAY_T1L    {_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();}
//220nS~380nS
#define WS2812_DELAY_T0H    {_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();}
//580nS~1uS
#define WS2812_DELAY_T0L    {_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();}
#elif   (ECBM_SYSCLK_SETTING == 35000000UL)
//580nS~1uS
#define WS2812_DELAY_T1H    {_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();}
//580nS~1uS
#define WS2812_DELAY_T1L    {_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();}
//220nS~380nS
#define WS2812_DELAY_T0H    {_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();}
//580nS~1uS
#define WS2812_DELAY_T0L    {_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();}
#elif   (ECBM_SYSCLK_SETTING == 36864000UL)
//580nS~1uS
#define WS2812_DELAY_T1H    {_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();}
//580nS~1uS
#define WS2812_DELAY_T1L    {_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();}
//220nS~380nS
#define WS2812_DELAY_T0H    {_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();}
//580nS~1uS
#define WS2812_DELAY_T0L    {_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();}
#elif   (ECBM_SYSCLK_SETTING == 40000000UL)
//580nS~1uS
#define WS2812_DELAY_T1H    {_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();}
//580nS~1uS
#define WS2812_DELAY_T1L    {_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();}
//220nS~380nS
#define WS2812_DELAY_T0H    {_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();}
//580nS~1uS
#define WS2812_DELAY_T0L    {_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();}
#elif   (ECBM_SYSCLK_SETTING == 44236800UL)
//580nS~1uS
#define WS2812_DELAY_T1H    {_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();}
//580nS~1uS
#define WS2812_DELAY_T1L    {_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();}
//220nS~380nS
#define WS2812_DELAY_T0H    {_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();}
//580nS~1uS
#define WS2812_DELAY_T0L    {_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();}
#elif   (ECBM_SYSCLK_SETTING == 45000000UL)
//580nS~1uS
#define WS2812_DELAY_T1H    {_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();}
//580nS~1uS
#define WS2812_DELAY_T1L    {_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();}
//220nS~380nS
#define WS2812_DELAY_T0H    {_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();}
//580nS~1uS
#define WS2812_DELAY_T0L    {_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();}
#elif   (ECBM_SYSCLK_SETTING == 45158400UL)
//580nS~1uS
#define WS2812_DELAY_T1H    {_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();}
//580nS~1uS
#define WS2812_DELAY_T1L    {_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();}
//220nS~380nS
#define WS2812_DELAY_T0H    {_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();}
//580nS~1uS
#define WS2812_DELAY_T0L    {_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();}
#endif
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
WS2812�ĳ�ʼ��������
-------------------------------------------------------*/
void ws2812_init(void){
    #if     (ECBM_WS2812_IO_PORT==0x80)
        gpio_mode(0x00+ECBM_WS2812_IO_PIN,GPIO_OUT);
    #elif   (ECBM_WS2812_IO_PORT==0x90)
        gpio_mode(0x10+ECBM_WS2812_IO_PIN,GPIO_OUT);
    #elif   (ECBM_WS2812_IO_PORT==0xA0)
        gpio_mode(0x20+ECBM_WS2812_IO_PIN,GPIO_OUT);
    #elif   (ECBM_WS2812_IO_PORT==0xB0)
        gpio_mode(0x30+ECBM_WS2812_IO_PIN,GPIO_OUT);
    #elif   (ECBM_WS2812_IO_PORT==0xC0)
        gpio_mode(0x40+ECBM_WS2812_IO_PIN,GPIO_OUT);
    #elif   (ECBM_WS2812_IO_PORT==0xC8)
        gpio_mode(0x50+ECBM_WS2812_IO_PIN,GPIO_OUT);
    #elif   (ECBM_WS2812_IO_PORT==0xE8)
        gpio_mode(0x60+ECBM_WS2812_IO_PIN,GPIO_OUT);
    #elif   (ECBM_WS2812_IO_PORT==0xF8)
        gpio_mode(0x70+ECBM_WS2812_IO_PIN,GPIO_OUT);
    #endif
    ws2818_delay_300us=delay_set_us(300);
}
/*-------------------------------------------------------
WS2812�ķ��ͺ�����
-------------------------------------------------------*/
void ws2812_send(u8 dat[],u16 len){
    u8 i;
    u16 c;
    WS2812_IO=0;
    delay_us(ws2818_delay_300us);
    for(c=0;c<len;c++){
        WS2812_IO=0;
        ws2818_buf=dat[c];
        for(i=0;i<8;i++){
            WS2812_IO=1;
            if(ws2818_buf_bit){WS2812_DELAY_T1H;WS2812_IO=0;WS2812_DELAY_T1L;                
            }else{             WS2812_DELAY_T0H;WS2812_IO=0;WS2812_DELAY_T0L;}
            ws2818_buf<<=1;
        }
    }
    WS2812_IO=1;
}