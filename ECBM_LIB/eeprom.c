#include "ecbm_core.h"  //统一加载核心头文件
#if (ECBM_EEPROM_LIB_EN)      //检查本库有没有被使能
/*---------------------------------------宏定义------------------------------------*/
#if     (ECBM_SYSCLK_SETTING == 5529600UL)//根据系统时钟来选择系数。
#   define ECBM_EEPROM_WAIT_TIME   (4)
#elif   (ECBM_SYSCLK_SETTING == 6000000UL)
#   define ECBM_EEPROM_WAIT_TIME   (4)
#elif   (ECBM_SYSCLK_SETTING == 11059200UL)
#   define ECBM_EEPROM_WAIT_TIME   (3)
#elif   (ECBM_SYSCLK_SETTING == 12000000UL)
#   define ECBM_EEPROM_WAIT_TIME   (3)
#elif   (ECBM_SYSCLK_SETTING == 18432000UL)
#   define ECBM_EEPROM_WAIT_TIME   (2)
#elif   (ECBM_SYSCLK_SETTING == 20000000UL)
#   define ECBM_EEPROM_WAIT_TIME   (2)
#elif   (ECBM_SYSCLK_SETTING == 22118400UL)
#   define ECBM_EEPROM_WAIT_TIME   (2)
#elif   (ECBM_SYSCLK_SETTING == 24000000UL)
#   define ECBM_EEPROM_WAIT_TIME   (1)
#elif   (ECBM_SYSCLK_SETTING == 26000000UL)
#   define ECBM_EEPROM_WAIT_TIME   (1)
#elif   (ECBM_SYSCLK_SETTING == 27000000UL)
#   define ECBM_EEPROM_WAIT_TIME   (1)
#elif   (ECBM_SYSCLK_SETTING == 30000000UL)
#   define ECBM_EEPROM_WAIT_TIME   (0)
#elif   (ECBM_SYSCLK_SETTING == 33000000UL)
#   define ECBM_EEPROM_WAIT_TIME   (0)
#elif   (ECBM_SYSCLK_SETTING == 33177600UL)
#   define ECBM_EEPROM_WAIT_TIME   (0)
#elif   (ECBM_SYSCLK_SETTING == 35000000UL)
#   define ECBM_EEPROM_WAIT_TIME   (0)
#elif   (ECBM_SYSCLK_SETTING == 36864000UL)
#   define ECBM_EEPROM_WAIT_TIME   (0)
#elif   (ECBM_SYSCLK_SETTING == 40000000UL)
#   define ECBM_EEPROM_WAIT_TIME   (0)
#elif   (ECBM_SYSCLK_SETTING == 44236800UL)
#   define ECBM_EEPROM_WAIT_TIME   (0)
#elif   (ECBM_SYSCLK_SETTING == 45000000UL)
#   define ECBM_EEPROM_WAIT_TIME   (0)
#elif   (ECBM_SYSCLK_SETTING == 45158400UL)
#   define ECBM_EEPROM_WAIT_TIME   (0)
#endif
/*--------------------------------------变量定义-----------------------------------*/
#if (ECBM_EEPROM_EX_EN)
    u8 xdata eeprom_ex_buf_gxu8a[512];//用于整合数据的缓存
#endif
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
eeprom关闭函数。
-------------------------------------------------------*/
void eeprom_off(void){
    IAP_SET_REG_CONTR(0);       //关闭IAP功能
    IAP_CMD_NOP;                //清除命令寄存器
    IAP_TRIG_CLS;               //清除触发寄存器
    IAP_SET_REG_ADDR_H8(0xff);  //将地址设置到非IAP区域
    IAP_SET_REG_ADDR_L8(0xff);  //将地址设置到非IAP区域
}
/*-------------------------------------------------------
eeprom初始化函数。
-------------------------------------------------------*/
void eeprom_init(void){
    #if  (((ECBM_MCU&0xF00000)>0x200000)||(ECBM_MCU==0x2815C4))
        IAP_TPS=ECBM_SYSCLK_SETTING/1000000;
    #endif
    eeprom_off();
}
/*-------------------------------------------------------
eeprom擦除函数。
-------------------------------------------------------*/
void eeprom_erase(u16 addr){
    IAP_SET_REG_CONTR(ECBM_EEPROM_WAIT_TIME|IAP_EN);//使能IAP
    IAP_CMD_ERASE;              //设置IAP擦除命令
    IAP_SET_REG_ADDR_HL(addr);  //设置IAP地址
    IAP_TRIG_ON;                //触发命令
    _nop_();_nop_();_nop_();_nop_();_nop_();_nop_();//稍稍等待一下
    _nop_();_nop_();_nop_();_nop_();_nop_();_nop_();//稍稍等待一下
    eeprom_off();               //关闭IAP功能
}
/*-------------------------------------------------------
eeprom写函数。
-------------------------------------------------------*/
void eeprom_write(u16 addr,u8 dat){
    IAP_SET_REG_CONTR(ECBM_EEPROM_WAIT_TIME|IAP_EN);//使能IAP
    IAP_CMD_WRITE;              //设置IAP写命令
    IAP_SET_REG_ADDR_HL(addr);  //设置IAP地址
    IAP_SET_REG_DATA(dat);      //写IAP数据
    IAP_TRIG_ON;                //触发命令
    _nop_();_nop_();_nop_();_nop_();_nop_();_nop_();//稍稍等待一下
    _nop_();_nop_();_nop_();_nop_();_nop_();_nop_();//稍稍等待一下
    eeprom_off();               //关闭IAP功能
}
/*-------------------------------------------------------
eeprom读函数。
-------------------------------------------------------*/
u8 eeprom_read(u16 addr){
    u8 dat_u8;
    IAP_SET_REG_CONTR(ECBM_EEPROM_WAIT_TIME|IAP_EN);    //使能IAP
    IAP_CMD_READ;               //设置IAP读命令
    IAP_SET_REG_ADDR_HL(addr);  //设置IAP地址
    IAP_TRIG_ON;                //触发命令
    _nop_();_nop_();_nop_();_nop_();_nop_();_nop_();//稍稍等待一下
    _nop_();_nop_();_nop_();_nop_();_nop_();_nop_();//稍稍等待一下
    dat_u8=IAP_GET_REG_DATA;    //读IAP数据
    eeprom_off();               //关闭IAP功能
    return dat_u8;
}

/*-------------------------------------------------------
eeprom读函数延伸版(extension)。
-------------------------------------------------------*/
#if (ECBM_EEPROM_EX_EN)
    void eeprom_read_ex(u16 addr,u8 * dat,u16 num){
        u16 i_u16;
        for(i_u16=0;i_u16<num;i_u16++){
            dat[i_u16]=eeprom_read(addr+i_u16);
        }
    }
#endif
/*-------------------------------------------------------
eeprom写函数延伸版(extension)。
-------------------------------------------------------*/
#if (ECBM_EEPROM_EX_EN)
    void eeprom_write_ex(u16 addr,u8 * dat,u16 num){
        u16 num_yu_u16;         //剩余要写的数据的数量。
        u16 area_u16;           //操作扇区。
        u16 area_addr_yu_u16;   //扇区余下的地址数量。
        u16 area_start_addr_u16;//扇区开始地址。
        u16 area_stop_addr_u16; //扇区结束地址。
        u16 addr_offset_u16;    //地址偏移。
        u16 dat_offset_u16=0;   //数据偏移。
        u16 address_u16;        //操作地址。
        u16 i_u16;              //临时变量。
        address_u16=addr;       //将地址参数赋值给操作地址。
        num_yu_u16=num;         //将参数数量赋值为剩余数量。
        do{
            area_u16=address_u16>>9;                    //获取扇区。
            area_start_addr_u16=(area_u16<<9);          //获取扇区开始的地址。
            area_stop_addr_u16=(area_u16<<9)+512;       //获取扇区末尾的地址。
            area_addr_yu_u16=area_stop_addr_u16-address_u16;//末尾地址减操作地址，得到地址剩余数量。
            if(num_yu_u16<=area_addr_yu_u16){           //如果要写的数少于地址剩余数量，说明不用跨扇区。
                for(i_u16=0;i_u16<512;i_u16++){             //将原来的数据读出来。
                    eeprom_ex_buf_gxu8a[i_u16]=eeprom_read(area_start_addr_u16+i_u16);
                }
                eeprom_erase(area_start_addr_u16);      //清空扇区。
                addr_offset_u16=address_u16-area_start_addr_u16;//获取地址偏移。
                for(i_u16=0;i_u16<num_yu_u16;i_u16++){              //修改数据。
                    eeprom_ex_buf_gxu8a[addr_offset_u16+i_u16]=dat[dat_offset_u16+i_u16];
                }
                for(i_u16=0;i_u16<512;i_u16++){                 //将数据写回去。
                    eeprom_write(area_start_addr_u16+i_u16,eeprom_ex_buf_gxu8a[i_u16]);
                }
                break;                              //写完就跳出循环。
            }else{                                  //如果要写的数多于地址剩余量。
                for(i_u16=0;i_u16<512;i_u16++){                 //将原来的数据读出来。
                    eeprom_ex_buf_gxu8a[i_u16]=eeprom_read(area_start_addr_u16+i_u16);
                }
                eeprom_erase(area_start_addr_u16);      //清空扇区。
                addr_offset_u16=address_u16-area_start_addr_u16;//获取地址偏移。
                for(i_u16=0;i_u16<area_addr_yu_u16;i_u16++){        //修改数据。
                    eeprom_ex_buf_gxu8a[addr_offset_u16+i_u16]=dat[dat_offset_u16+i_u16];
                }
                for(i_u16=0;i_u16<512;i_u16++){                 //将数据写回去。
                    eeprom_write(area_start_addr_u16+i_u16,eeprom_ex_buf_gxu8a[i_u16]);
                }
                address_u16   +=area_addr_yu_u16;   //写了多少，地址就加多少。
                num_yu_u16    -=area_addr_yu_u16;   //剩余数量就要减多少。
                dat_offset_u16+=area_addr_yu_u16;   //缓存的偏移就加多少。
            }
        }while(1);
    }
#endif
#endif  //和最上面的#ifndef配合成一个程序段。
        //以一个空行为结尾。