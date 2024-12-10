#include "ecbm_core.h"  //ͳһ���غ���ͷ�ļ�
/*------------------------------------��Դ��ͻ����---------------------------------*/
#if (ECBM_AUTO_DOWNLOAD_EN)
#   if (ECBM_UART_LIB_EN==0)
#       warning �򴮿ڿ�δʹ��,�Զ����ع���ʧЧ!
#   endif
#   if (ECBM_UART1_EN==0)
#       error �Զ����ع����򴮿�1δʹ�ܶ�����ʧ��,��ǰ��uart.hʹ�ܴ���1!
#   endif
#   if (ECBM_UART1_IO!=0)
#       error �Զ����ع�����Ҫ����1ӳ�䵽P30��P31,��ǰ��uart.h�޸Ĵ���1�����IO!
#   endif
#endif
/*---------------------------------------�궨��------------------------------------*/
#if         ((ECBM_MCU&0xF00000)==0x100000)
#   define	ECBM_MCU_NAME   "STC8F"
#elif       ((ECBM_MCU&0xF00000)==0x200000)
#   define	ECBM_MCU_NAME   "STC8A"
#elif       ((ECBM_MCU&0xF00000)==0x300000)
#   define	ECBM_MCU_NAME   "STC8G"
#elif       ((ECBM_MCU&0xF00000)==0x400000)
#   define	ECBM_MCU_NAME   "STC8H"
#elif       ((ECBM_MCU&0xF00000)==0x500000)
#   define	ECBM_MCU_NAME   "STC8C"
#endif
/*--------------------------------------��������-----------------------------------*/
union{
    u32 num32;
    u16 num16[2];
    u8  num8[4];
}data fast_cout;
#if ((ECBM_UART_LIB_EN)&&(ECBM_AUTO_DOWNLOAD_EN))
    bit auto_download_en_gb;                //�Զ����ص�ʹ��
    u8 data auto_download_old_char_gdu8;    //������һ�ν��յ�����
    u8 data auto_download_char_count_gdu8;  //��ͬ���ݼ���
#endif
/*--------------------------------------������-----------------------------------*/
#if (ECBM_DELAY_EN)
/*-------------------------------------------------------
���뼶��ʱ����
-------------------------------------------------------*/
void delay_ms(u16 ms){
    u16 i_u16;
    if(ms){
        do{
            i_u16=ECBM_SYSCLK_SETTING/10000;
            while(--i_u16);
        }while(--ms);    
    }
}
/*-------------------------------------------------------
΢�뼶��ʱ���������ģ�
-------------------------------------------------------*/
void delay_us(u16 us){
    u16 i_u16;
    i_u16=us;
	do{}while(--i_u16);
}
/*-------------------------------------------------------
΢�뼶��ʱ�����Ľ��ļ��㺯��
-------------------------------------------------------*/
u16 delay_set_us(u16 us){
//��ʽ����������ʱ��̫������ֳ�����������������������������ʱ����ֵ����������ĺ������á�
    fast_cout.num32=((u32)(ECBM_SYSCLK_SETTING/10000)*(u32)(us))*131;
    return fast_cout.num16[0]>>1;
}
#endif
/*-------------------------------------------------------
�������жϺ���
-------------------------------------------------------*/
#if ((ECBM_UART_LIB_EN)&&(ECBM_AUTO_DOWNLOAD_EN))
    void system_uart_reset(void){
        if(auto_download_old_char_gdu8!=UART1_GET_REG_SBUF){ //�ж��ظ��ַ�������ַ����ظ�
            auto_download_old_char_gdu8=UART1_GET_REG_SBUF;  //�͸���oldchar
            auto_download_char_count_gdu8=0;                 //����������
        }else{                                              //����ַ��ظ�
            if(auto_download_en_gb)auto_download_char_count_gdu8++;//���ظ�������+1
        }
        if(auto_download_char_count_gdu8>=233){          //���յ�233���ظ�����ʱ
            EA_DISABLE;                                 //�Ͽ������ж�
            while(1)POWER_RESET;                        //һֱ��������
        }
    }
#endif
/*-------------------------------------------------------
ϵͳ��麯��
-------------------------------------------------------*/
#if ((ECBM_UART_LIB_EN)&&(ECBM_UART1_EN)&&(ECBM_UART_PRINTF_EN)&&(ECBM_PRINTF_EN)&&(ECBM_MCU_CHECK_EN))
    void system_check(void){
        u8 i,j;    
        u16 aaa=0x1234;
        uart_printf(1,"ECBM V%bu.%bu.%bu on %s",ECBM_FVN,ECBM_RVN,ECBM_BVN,ECBM_MCU_NAME);//����汾�ź͵�Ƭ���ͺ�
        uart_printf(1,"%uK",(u16)((ECBM_MCU&0x0F0000)>>16));
        uart_printf(1,"%02u",(u16)(ECBM_MCU_ROM_SIZE));
        #if     (ECBM_MCU==0x110301)
            uart_printf(1,"-8PIN");
        #elif   (ECBM_MCU==0x110302)
            uart_printf(1,"S2-16PIN/20PIN");
        #elif   (ECBM_MCU==0x120502)
            uart_printf(1,"S2");
        #elif   (ECBM_MCU==0x120504)
            uart_printf(1,"S4");
        #elif   (ECBM_MCU==0x2405C2)
            uart_printf(1,"S2A12");
        #elif   (ECBM_MCU==0x2815C4)
            uart_printf(1,"D4");
        #elif   (ECBM_MCU==0x2805C4)
            uart_printf(1,"S4A12");
        #elif   (ECBM_MCU==0x3103A2)
            uart_printf(1,"-16PIN/20PIN");
        #elif   (ECBM_MCU==0x310201)
            uart_printf(1,"-8PIN ");
        #elif   (ECBM_MCU==0x3102A1)
            uart_printf(1,"A-8PIN");
        #elif   (ECBM_MCU==0x3103A1)
            uart_printf(1,"T-20PIN");
        #elif   (ECBM_MCU==0x3205A2)
            uart_printf(1,"S2");
        #elif   (ECBM_MCU==0x3205A4)
            uart_printf(1,"S4");
        #elif   (ECBM_MCU==0x4103A2)
            uart_printf(1,"-20PIN");
        #elif   (ECBM_MCU==0x4105A2)
            uart_printf(1,"-32PIN");    
        #elif   (ECBM_MCU==0x4305C2)
            uart_printf(1,"S2");    
        #elif   (ECBM_MCU==0x4305C4)
            uart_printf(1,"S4");
        #elif   (ECBM_MCU==0x4805C4)
            uart_printf(1,"U");    
        #elif   (ECBM_MCU==0x520502)
            uart_printf(1,"S2");    
        #elif   (ECBM_MCU==0x520504)
            uart_printf(1,"S4");
        #endif
        j=0;
        uart_printf(1,"\r\nChecking MCU ID");
        for(i=0;i<7;i++){
            uart_printf(1,".");
            if((REG_ID(i))==(MCUID[i])){
                j++;
            }
        }
        if(j!=7){
            uart_printf(1,"Error\r\nPlease check the setting of the MCU model\r\n");
        }else{
            uart_printf(1,"OK\r\nID    :");for(i=0;i<7;i++){uart_printf(1,"%02X",(u16)(MCUID[i]));}uart_printf(1,"\r\n");        //���ΨһID��
            uart_printf(1,"DATA  :128\tByte\r\n");//DATA���̶���128Byte
            uart_printf(1,"IDATA :128\tByte\r\n");//IDATA���̶���128Byte
            uart_(1,"XDATA :%u\tByte\r\n",(u16)((ECBM_MCU&0x0F0000)>>16)*1024);//�������ļ��л�ȡXDATA����С
            uart_printf(1,"FLASH :%lu\tByte\r\n",(u32)ECBM_MCU_ROM_SIZE*1024);//�������ļ��л�ȡFLASH����С
            uart_printf(1,"SYSCLK:%lu\tHz\r\n",ECBM_SYSCLK_SETTING);//����ڲ�����ֵ����ͼ�ν���������
            uart_printf(1,"BGV   :%u\tmV\r\n",REG_BGV);//����ڲ���ѹ��׼ֵ����Ҫ��STC-ISP������
            uart_printf(1,"ENDIAN:");
            if(*((char*)(&aaa))==0x12)uart_printf(1,"big\tendian\r\n");
            if(*((char*)(&aaa))==0x34)uart_printf(1,"little\tendian\r\n");
        }    
    }
#endif
/*-------------------------------------------------------
�⺯��ϵͳ��ʼ������
-------------------------------------------------------*/
void system_init(void){
    #if (SYSTEM_CLEAR_XDATA_LEN)//��������������Ϊ0���ͱ������µĴ��룺
    u16 i_u16;//����������
    for(i_u16=0;i_u16<SYSTEM_CLEAR_XDATA_LEN;i_u16++){//ѭ�����㡣
        (*((u8  volatile xdata *)i_u16))=0;//����XDATA���֡�
    }
    #endif
    EX_SFR_ENABLE;//�򿪶���ļĴ�����
    //---------------�Զ�����--------------//
    #if ((ECBM_UART_LIB_EN)&&(ECBM_AUTO_DOWNLOAD_EN))//�жϷ���Ҫ�����Զ����ء�
        auto_download_en_gb=1;         //���Զ�����ʹ��
        auto_download_old_char_gdu8=0;   //��ʼ��������ر���
        auto_download_char_count_gdu8=0; //��ʼ��������ر���
        uart_init();
    #endif
    //--------------10mS����--------------//
    #if (ECBM_10MS_EN)
        #if     (ECBM_10MS_TIMER==0)
            TIMER0_SET_MODE_12T;    //�趨������ʱ���Ҫ��12��Ƶ��
            TIMER0_SET_REG_HL(65536UL-(u16)((ECBM_SYSCLK_SETTING*10000)/12/1000000));//�궨������ڱ����ھ��ܼ���ã���������Ĺ�ʽ����ԭ����ʽ�ܷ����޸ġ�
            TIMER0_SET_MODE_TIMER;  //����Ϊ��ʱ��ģʽ��
            TIMER0_IT_ENABLE;       //���жϿ��ء�
            TIMER0_POWER_ON;        //�򿪶�ʱ����
        #elif   (ECBM_10MS_TIMER==1)
            TIMER1_SET_MODE_12T;    //�趨������ʱ���Ҫ��12��Ƶ��
            TIMER1_SET_REG_HL(65536UL-(u16)((ECBM_SYSCLK_SETTING*10000)/12/1000000));//�궨������ڱ����ھ��ܼ���ã���������Ĺ�ʽ����ԭ����ʽ�ܷ����޸ġ�
            TIMER1_SET_MODE_TIMER;  //����Ϊ��ʱ��ģʽ��
            TIMER1_IT_ENABLE;       //���жϿ��ء�
            TIMER1_POWER_ON;        //�򿪶�ʱ����
        #elif   (ECBM_10MS_TIMER==2)
            TIMER2_SET_MODE_12T;    //�趨������ʱ���Ҫ��12��Ƶ��
            TIMER2_SET_REG_HL(65536UL-(u16)((ECBM_SYSCLK_SETTING*10000)/12/1000000));//�궨������ڱ����ھ��ܼ���ã���������Ĺ�ʽ����ԭ����ʽ�ܷ����޸ġ�
            TIMER2_SET_MODE_TIMER;  //����Ϊ��ʱ��ģʽ��
            TIMER2_IT_ENABLE;       //���жϿ��ء�
            TIMER2_POWER_ON;        //�򿪶�ʱ����
        #elif   (ECBM_10MS_TIMER==3)
            TIMER3_SET_MODE_12T;    //�趨������ʱ���Ҫ��12��Ƶ��
            TIMER3_SET_REG_HL(65536UL-(u16)((ECBM_SYSCLK_SETTING*10000)/12/1000000));//�궨������ڱ����ھ��ܼ���ã���������Ĺ�ʽ����ԭ����ʽ�ܷ����޸ġ�
            TIMER3_SET_MODE_TIMER;  //����Ϊ��ʱ��ģʽ��
            TIMER3_IT_ENABLE;       //���жϿ��ء�
            TIMER3_POWER_ON;        //�򿪶�ʱ����
        #elif   (ECBM_10MS_TIMER==4)
            TIMER4_SET_MODE_12T;    //�趨������ʱ���Ҫ��12��Ƶ��
            TIMER4_SET_REG_HL(65536UL-(u16)((ECBM_SYSCLK_SETTING*10000)/12/1000000));//�궨������ڱ����ھ��ܼ���ã���������Ĺ�ʽ����ԭ����ʽ�ܷ����޸ġ�
            TIMER4_SET_MODE_TIMER;  //����Ϊ��ʱ��ģʽ��
            TIMER4_IT_ENABLE;       //���жϿ��ء�
            TIMER4_POWER_ON;        //�򿪶�ʱ����
        #endif
        #if ((ECBM_STREAM_LIB_EN)&&(ECBM_STREAM_CH_COUNT))
            ecbm_stream_init();
        #endif        
    #endif    
    //-------------����Ӳ������------------//
    #if ((ECBM_POWER_LIB_EN)&&(ECBM_POWER_RST_CFG_EN))
        power_rstcfg_init();
    #endif    
    //-------------ʱ���������------------//    
    #if (ECBM_SYSCLK_OUT_EN) //�ж��Ƿ���Ҫ����ʱ�������
        #if ((ECBM_MCU&0xF00000)>0x200000)//����ǲ���GH��
            #if (ECBM_SYSLCK_OUT_PIN)
                CLK_SET_OUT_TO_P16_GH;
            #else
                CLK_SET_OUT_TO_P54_GH;
            #endif
            CLK_OUT_SET_DIV_GH(ECBM_SYSCLK_OUT_SETTING_GH);
        #else
            #if (ECBM_SYSLCK_OUT_PIN)
                CLK_SET_OUT_TO_P16_FA;
            #else
                CLK_SET_OUT_TO_P54_FA;
            #endif
            CLK_OUT_SET_DIV_FA(ECBM_SYSCLK_OUT_SETTING_FA);
        #endif
    #endif
//--------------����ȷ��---------------//
    EA_ENABLE;//�����жϡ�
    #if ((ECBM_UART_LIB_EN)&&(ECBM_UART1_EN)&&(ECBM_UART_PRINTF_EN)&&(ECBM_PRINTF_EN)&&(ECBM_MCU_CHECK_EN))
        delay_ms(500);
        system_check();
    #endif
}
/*---------------------------------������ϵͳ����---------------------------------*/
/**********************************strϵ�к���************************/#if (ECBM_STRING_EN)
/*-------------------------------------------------------
�ַ������Һ�����
-------------------------------------------------------*/
u16 str_find(s8 * dest,s8 * key){
    u16 key_count_u16,key_first_u16,count_u16;
    key_count_u16=0;    //���������
    key_first_u16=0;
    count_u16    =0;
    while(*dest){       //�ж�Ŀ���ַ�����
        if(key[key_count_u16]==(*dest)){//����ؼ����ַ�����ǰλ�ȶԳɹ���
            key_count_u16++;            //��ô�ͱȽ���һλ��
        }else if(key[0]==(*dest)){	    //���統ǰλû�жԱȳɹ����Ϳ����ǲ���Ҫ��ͷ��ʼ�Աȡ�
			key_count_u16=1;			//��ͷ�Աȳɹ���˵���ٴ��ҵ������ƵĹؼ��ʣ���ô�´ξʹӵڶ�����ʼ�Աȡ�
        }else{                          //����û�бȶԳɹ���
            key_count_u16=0;            //��ô�ʹ�ͷ��ʼ�ȶԡ�
        }
		count_u16++;    				//��¼ѭ���Ĵ��������ڼ���ؼ��ʳ��ֵ�λ�á�
        dest++;                         //��ȡĿ���ַ�������һλ��
        if(key[key_count_u16]==0){      //����ؼ����ַ����ȶ��꣬
            return (count_u16-key_count_u16);//���عؼ����ַ�����һ�γ��ֵ�λ�á�
        } 
    }
    return 0xffff;//�����е���һ����˵��ֱ��Ŀ���ַ���������û�бȶԳɹ�������-1��
}
/*-------------------------------------------------------
IO��Ϣ��ȡ������
-------------------------------------------------------*/
u8 str_read_pin(s8 * str,u16 pos){
    u8  dat_u8,offset_u8,count_u8;  //�������������Ƕ�ȡ����Ϣ���ַ���ƫ�ƺ�����ͳ�ơ�
    dat_u8=0;                       //�������㡣
    count_u8=0;                     //����ͳ�����㡣
    for(offset_u8=0;offset_u8<10;offset_u8++){      //Ԥ��10��ƫ������
        if((str[pos+offset_u8]>='0')&&(str[pos+offset_u8]<='7')){//IO�ڵı�Ŷ��Ǵ�0~7��
            count_u8++;                             //�������Χ�ڣ�����+1��
            if(count_u8==1){                        //����ǵ�һ������
                dat_u8=(str[pos+offset_u8]-'0')<<4; //���������ŵ���4λ��
            }
            if(count_u8==2){                        //����ǵڶ�������
                dat_u8=(str[pos+offset_u8]-'0')|dat_u8;//���������ŵ���4λ��
                return dat_u8;                      //���ظ�ֵ��
            }
        }
        if((str[pos+offset_u8]>='8')&&(str[pos+offset_u8]<='9')){//�����8��9����ôֻ������������д��ֵ��
            count_u8++;
        }
        if(str[pos+offset_u8]==',')break;//�������ž��˳���
        if(str[pos+offset_u8]==0)break;  //�ַ�������Ҳ�˳���
    }
    return dat_u8;
}
/*-------------------------------------------------------
u16������ȡ������
-------------------------------------------------------*/
u16 str_read_u16(s8 * str,u16 pos){
    u16 dat_u16;    //��ȡ����Ϣ��
    u8  offset_u8;  //�ַ���ƫ�ơ�
    dat_u16=0;
    for(offset_u8=0;offset_u8<20;offset_u8++){//Ԥ��20���ַ���ƫ�ơ�
        if((str[pos+offset_u8]>='0')&&(str[pos+offset_u8]<='9')){//���ֶ��Ǵ�0~9��
            dat_u16*=10;                    //��������һλ����ԭ����12���ͱ��120���ճ��ĸ���������װ�µ�����
            dat_u16+=str[pos+offset_u8]-'0';//���µ����ӵ���λ�ϡ�
        }
        if(str[pos+offset_u8]==',')break;//�������ž��˳���
        if(str[pos+offset_u8]=='.')break;//������ž��˳���
        if(str[pos+offset_u8]==0)break;  //�ַ�������Ҳ�˳���
    }
    return dat_u16;
}
/*-------------------------------------------------------
�ַ����Ƴ�ָ��������ַ������Ȳ����棩��
-------------------------------------------------------*/
u8 str_push_len(u8 * dest,u16 dlen,u8 * key,u16 klen){
    u16 i_u16,j_u16,start_u16,stop_u16;
    j_u16    =0;                        //������ֱ�����
    start_u16=0;
    stop_u16 =0;
    for(i_u16=0;i_u16<dlen;i_u16++){    //��ͷ��ʼ��ֱ��ָ���ĳ��ȡ�
        if(dest[i_u16]==key[j_u16]){    //�ѵ�ǰ���ַ��͹ؼ��ʱȽϳɹ���
            j_u16++;                    //ȡ�ؼ��ʵ���һ���֡�
            if(j_u16==klen){            //���ؼ���ȫ���ȶ���ɵ�ʱ��
                stop_u16=i_u16;         //���桾����λ�á���
                break;                  //�˳�ѭ����
            }
        }else{                          //�����ǰ���ַ��͹ؼ��ʱȽ�ʧ�ܣ�
            j_u16=0;                    //��һ�δ�ͷ��ʼ�ȶԡ�
            start_u16=i_u16+1;          //���¡���ʼλ�á�Ϊ��һλ����Ϊ��ǰλʧ���ˣ���
        }
    }
    if(start_u16<=stop_u16){            //���ȶԳɹ���ʱ�򣬡���ʼλ�á��϶�С�ڵ��ڡ�����λ�á���
        for(i_u16=start_u16;i_u16<stop_u16;i_u16++){//���ӡ���ʼλ�á���������λ�á�֮��Ļ���ȫ���㡣
            dest[i_u16]=0;
        }
        return 1;                //�����Ƴ��ɹ���
    }else{
        return 0;                //�����Ƴ�ʧ�ܡ�
    }
}
/*****************************************************************************/#endif
