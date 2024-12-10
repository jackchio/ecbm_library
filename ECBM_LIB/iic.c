#include "ecbm_core.h"  //统一加载核心头文件
#if (ECBM_IIC_LIB_EN)      //检查本库有没有被使能
/*--------------------------------------变量定义-----------------------------------*/
bit iic_master_busy_gb;
u8 xdata iic_index_gxu8;
bit eiicp_trig_gb;                         
u8  eiicp_data_count_gu8; 
u8  eiicp_data_buf_gu8a[ECBM_IIC_BUF_MAX]; 
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
IIC的引脚设置函数。
-------------------------------------------------------*/
void iic_set_pin(u8 group){
    #if ((ECBM_MCU==0x310201)||(ECBM_MCU==0x3102A1))
        switch(group){
            case IIC_PIN_P32_P33:{//切换至D32和D33
                P3M1|=0x0C;//0000 1100 IIC的引脚需要是开漏模式
                P3M0|=0x0C;//0000 1100 IIC的引脚需要是开漏模式
                P3PU|=0x0C;//0000 1100 IIC需要一个上拉电阻       
            }break;
            case IIC_PIN_P54_P55:{//切换至D54和D55
                P5M1|=0x30;//0011 0000 IIC的引脚需要是开漏模式
                P5M0|=0x30;//0011 0000 IIC的引脚需要是开漏模式
                P5PU|=0x30;//0011 0000 IIC需要一个上拉电阻
            }break;
            default:break;
        }    
    #else
        switch(group){
            case IIC_PIN_P15_P14:{//切换至D14和D15
                P1M1|=0x30;//0011 0000 IIC的引脚需要是开漏模式
                P1M0|=0x30;//0011 0000 IIC的引脚需要是开漏模式
                P1PU|=0x30;//0011 0000 IIC需要一个上拉电阻       
            }break;
            case IIC_PIN_P25_P24:{//切换至D24和D25
                P2M1|=0x30;//0011 0000 IIC的引脚需要是开漏模式
                P2M0|=0x30;//0011 0000 IIC的引脚需要是开漏模式
                P2PU|=0x30;//0011 0000 IIC需要一个上拉电阻
            }break;
            case IIC_PIN_P77_P76:{//切换至D76和D77
                P7M1|=0xC0;//1100 0000 IIC的引脚需要是开漏模式
                P7M0|=0xC0;//1100 0000 IIC的引脚需要是开漏模式
                P7PU|=0xC0;//1100 0000 IIC需要一个上拉电阻
            }break;
            case IIC_PIN_P32_P33:{//切换至D32和D33
                P3M1|=0x0C;//0000 1100 IIC的引脚需要是开漏模式
                P3M0|=0x0C;//0000 1100 IIC的引脚需要是开漏模式
                P3PU|=0x0C;//0000 1100 IIC需要一个上拉电阻
            }break;
            default:break;
        }
    #endif
    IIC_SET_PIN(group);
}
/*-------------------------------------------------------
IIC的引脚设置函数（内联版）。
-------------------------------------------------------*/
void iic_set_pin_linkage(u8 group){
    if(iic_index_gxu8!=group){
        iic_index_gxu8=group;
        IIC_POWER_OFF;
        IIC_SET_PIN(group);
        IIC_POWER_ON;
    }
}
/*-------------------------------------------------------
IIC的引脚还原函数。
-------------------------------------------------------*/
void iic_reset_pin(u8 group){
    #if ((ECBM_MCU==0x310201)||(ECBM_MCU==0x3102A1))
        switch(group){
            case IIC_PIN_P32_P33:{//还原D32和D33
                P3M1&=~0x0C;//1111 0011 还原引脚模式
                P3M0&=~0x0C;//1111 0011 还原引脚模式
                P3PU&=~0x0C;//1111 0011 去掉上拉电阻       
            }break;
            case IIC_PIN_P54_P55:{//还原D54和D55
                P5M1&=~0x30;//1100 1111 还原引脚模式
                P5M0&=~0x30;//1100 1111 还原引脚模式
                P5PU&=~0x30;//1100 1111 去掉上拉电阻
            }break;
            default:break;
        }    
    #else
        switch(group){
            case IIC_PIN_P15_P14:{//还原D14和D15
                P1M1&=~0x30;//1100 1111 还原引脚模式
                P1M0&=~0x30;//1100 1111 还原引脚模式
                P1PU&=~0x30;//1100 1111 去掉上拉电阻      
            }break;
            case IIC_PIN_P25_P24:{//还原D24和D25
                P2M1&=~0x30;//1100 1111 还原引脚模式
                P2M0&=~0x30;//1100 1111 还原引脚模式
                P2PU&=~0x30;//1100 1111 去掉上拉电阻
            }break;
            case IIC_PIN_P77_P76:{//还原D76和D77
                P7M1&=~0xC0;//0011 1111 还原引脚模式
                P7M0&=~0xC0;//0011 1111 还原引脚模式
                P7PU&=~0xC0;//0011 1111 去掉上拉电阻
            }break;
            case IIC_PIN_P32_P33:{//还原D32和D33
                P3M1&=~0x0C;//1111 0011 还原引脚模式
                P3M0&=~0x0C;//1111 0011 还原引脚模式
                P3PU&=~0x0C;//1111 0011 去掉上拉电阻
            }break;
            default:break;
        }
    #endif
}
/*-------------------------------------------------------
IIC主机初始化函数。
-------------------------------------------------------*/
void iic_master_init(void){
    u8 res_u8=63;
    res_u8=(u8)(((ECBM_SYSCLK_SETTING/2/ECBM_IIC_WAIT)-4)/2);//计算出时钟所需的参数。
    IIC_SET_SPEED(res_u8);      //等待时钟。
    iic_set_master_mode();      //设置为主机。
    iic_set_pin(ECBM_IIC_IO);
    iic_index_gxu8=ECBM_IIC_IO; //保存当前用到的index号。
    IIC_POWER_ON;               //开启IIC。
}
/*-------------------------------------------------------
IIC从机初始化函数。
-------------------------------------------------------*/
void iic_slave_init(void){
    u8 res_u8=63;
    res_u8=(u8)(((ECBM_SYSCLK_SETTING/2/ECBM_IIC_WAIT)-4)/2);//计算出时钟所需的参数。
    IIC_SET_SPEED(res_u8);      //等待时钟。
    #if (ECBM_EIICP_EN)
        IIC_SET_REG_SLADR(0xEC);//设置从机地址。
    #else 
        #if (ECBM_IIC_SLAVE_ADDR_EN)
            IIC_SET_REG_SLADR(ECBM_IIC_SLAVE_ADDR<<1);//设置从机地址为配置页面的地址。
        #else
            IIC_SET_REG_SLADR(0x01);//设置从机地址为0，同时D0置一取消地址筛选。
        #endif
    #endif
    iic_set_slave_mode();       //设置为从机。
    iic_set_pin(ECBM_IIC_IO);
    iic_index_gxu8=ECBM_IIC_IO; //保存当前用到的index号。
    IIC_POWER_ON;               //开启IIC。
}
/*-------------------------------------------------------
IIC设置主机函数。
-------------------------------------------------------*/
void iic_set_master_mode(void){
    IIC_SET_REG_SLCR(1);//关闭所有接收中断。
    IIC_SET_REG_MSST(0);//清除所有主机标志位。
    IIC_SET_MODE_MASTER;//设置为主机。
    //主机会在发送指令和数据的时候置位发送中断，所以这里不用使能发送的中断。
}
/*-------------------------------------------------------
：IIC设置从机函数。
-------------------------------------------------------*/
void iic_set_slave_mode(void){
    IIC_SET_REG_MSCR(0);    //关闭所有发送中断。
    IIC_SET_REG_SLST(0);    //清除所有从机标志位。
    IIC_SET_MODE_SLAVE;     //设置为从机。
    IIC_SET_REG_SLCR(0x78); //打开所有接收中断。 
}
/*-------------------------------------------------------
IIC的各种操作函数。请根据器件的协议来排布。
iic_start     :开始函数，对应IIC开始帧。
iic_stop      :停止函数，对应IIC停止帧。
iic_write     :写数据函数，往总线上写1字节数据。
iic_write_ack :写ACK函数，往总线上写一个ACK。
iic_write_nack:写NO ACK函数，往总线上写一个NO ACK。
iic_read      :读数据函数，读取总线上一个字节的数据。
iic_read_ack  :读ACK函数，读取总线上是否有ACK。
-------------------------------------------------------*/
void iic_start(void){
    u16 timeout_u16=ECBM_IIC_TIMEOUT;
    iic_master_busy_gb=1;
    IIC_CMD_START;//发送START命令
    while(iic_master_busy_gb&&(timeout_u16--));
}
void iic_stop(void){
    u16 timeout_u16=ECBM_IIC_TIMEOUT;
    iic_master_busy_gb = 1;
    IIC_CMD_STOP;//发送STOP命令
    while(iic_master_busy_gb&&(timeout_u16--));
}
void iic_write(u8 dat){
    u16 timeout_u16=ECBM_IIC_TIMEOUT;
    IIC_SET_REG_DATA(dat);//写数据到数据缓冲区
    iic_master_busy_gb=1;
    IIC_CMD_TX_DATA;//发送SEND命令
    while(iic_master_busy_gb&&(timeout_u16--));
}
void iic_write_ack(void){
    u16 timeout_u16=ECBM_IIC_TIMEOUT;
    iic_master_busy_gb=1;
    IIC_CMD_TX_ACK; //发送ACK命令
    while(iic_master_busy_gb&&(timeout_u16--));
}
void iic_write_nack(void){
    u16 timeout_u16=ECBM_IIC_TIMEOUT;
    iic_master_busy_gb=1;
    IIC_CMD_TX_NACK; //发送ACK命令
    while(iic_master_busy_gb&&(timeout_u16--));
}
u8 iic_read(void){
    u16 timeout_u16=ECBM_IIC_TIMEOUT;
    iic_master_busy_gb=1;
    IIC_CMD_RX_DATA;  //发送RECV命令
    while(iic_master_busy_gb&&(timeout_u16--));
    return IIC_GET_REG_DATA;
}
bit iic_read_ack(void){
    u16 timeout_u16=ECBM_IIC_TIMEOUT;
    iic_master_busy_gb=1;
    IIC_CMD_RX_ACK; //发送读ACK命令
    while(iic_master_busy_gb&&(timeout_u16--));
    return IIC_GET_ACK>>1;
}
/*-------------------------------------------------------
EIICP主机模式基础发送函数。
-------------------------------------------------------*/
#if (ECBM_EIICP_EN)
void eiicp_master_base(u8 target_id,u8 operate,u16 addr,u8 * dat,u8 len){
    u16 timeout_u16=ECBM_IIC_TIMEOUT;
    u8 temp[8],i;
    iic_set_master_mode();          //设置为主机。
    //第一步：发送器件标识。
    //第二步：发送目标ID。
    temp[0]=target_id;
    //第三步：发送本机ID。
    temp[1]=eiicp_get_id();
    //第四步：发送操作码。
    temp[2]=operate;
    //第五步：发送地址的24~31。
    temp[3]=0;//但是32位地址是给32位机预留的，这里发送0。
    //第六步：发送地址的16~23。
    temp[4]=0;//但是32位地址是给32位机预留的，这里发送0。
    //第七步：发送地址的8~15。   
    temp[5]=(u8)(addr>>8);
    //第八步：发送地址的0~7。      
    temp[6]=(u8)(addr); 
    //第九步：发送数据的长度。  
    temp[7]=len;

    iic_master_busy_gb=1;           //忙标志位置位。由于IIC发送是硬件发送，和代码的执行位置是异步的，因此要先置忙标志位才能正确的涵盖整个发送流程。
    IIC_SET_REG_DATA(0xEC);         //发送器件标识。
    IIC_CMD_START_TXDATA_RXACK;     //发送START+WRITE+readACK命令
    while(iic_master_busy_gb&&(timeout_u16--));//等待忙标志位清零。
    for(i=0;i<8;i++){
        iic_master_busy_gb=1;       //忙标志位置位。
        IIC_SET_REG_DATA(temp[i]);  //发送数据包。
        IIC_CMD_TXDATA_RXACK;       //发送数据并读ACK。
        while(iic_master_busy_gb&&(timeout_u16--));//等待忙标志位清零。
    }
    //第十步：循环发送数据。
    if(operate==EIICP_CMD_WRITE){
        for(i=0;i<len;i++){
            iic_master_busy_gb=1;       //忙标志位置位。
            IIC_SET_REG_DATA(dat[i]);   //发送数据。
            IIC_CMD_TXDATA_RXACK;       //发送数据并读ACK。
            while(iic_master_busy_gb&&(timeout_u16--));//等待忙标志位清零。
        }
    }
    //结束。
    iic_master_busy_gb=1;           //忙标志位置位。
    IIC_CMD_STOP;
    while(iic_master_busy_gb&&(timeout_u16--));//等待忙标志位清零。
    iic_set_slave_mode();//设置为从机。
}
/*-------------------------------------------------------
EIICP主机模式触发函数。
-------------------------------------------------------*/
void eiicp_master_trig(u8 target_id,u16 addr){
    eiicp_master_base(target_id,EIICP_CMD_TRIG,addr,(u8 *)(0),0);
}
/*-------------------------------------------------------
EIICP主机模式写函数。
-------------------------------------------------------*/
void eiicp_master_write(u8 target_id,u16 addr,u8 * dat,u8 len){
    eiicp_master_base(target_id,EIICP_CMD_WRITE,addr,dat,len);
}
/*-------------------------------------------------------
EIICP主机模式读函数。
-------------------------------------------------------*/
void eiicp_master_read(u8 target_id,u16 addr,u8 len){
    eiicp_master_base(target_id,EIICP_CMD_READ,addr,(u8 *)(0),len);
}
/*-------------------------------------------------------
EIICP协议的主函数。
-------------------------------------------------------*/
void eiicp_main(void){
    u8  id_u8,len_u8,operate_u8;
    u16 i_u16,addr_u16;
    if(eiicp_trig_gb){
        eiicp_trig_gb=0;
        if(eiicp_data_buf_gu8a[0]==0xEC){//先判断是不是EIICP协议的标识。
            if(eiicp_data_buf_gu8a[1]==eiicp_get_id()){ //再看看是不是传给本机的消息。
                //由于接下来会复用缓存数组，所以得把关键信息先提取出来：
                id_u8     =eiicp_data_buf_gu8a[2];  //保存对方的ID。
                operate_u8=eiicp_data_buf_gu8a[3];  //保存操作数。
                addr_u16  =(u16)(eiicp_data_buf_gu8a[6])*256+(u16)(eiicp_data_buf_gu8a[7]);//把地址拼好。
                len_u8    =eiicp_data_buf_gu8a[8];  //保存数据长度。
                switch(operate_u8){//根据操作数来决定干嘛。
                    case EIICP_CMD_TRIG:{//触发
                        eiicp_base_reg_trig(addr_u16);//调用回调函数。
                        eiicp_master_base(id_u8,EIICP_CMD_TRIG_REPLY,addr_u16,(u8 *)(0),0);//反馈本次通信。
                    }break;
                    case EIICP_CMD_TRIG_REPLY:{//触发回复
                        eiicp_master_trig_callback(addr_u16);//调用回调函数。
                    }break;
                    case EIICP_CMD_READ:{//读取
                        for(i_u16=0;i_u16<(u16)(len_u8);i_u16++){
                            eiicp_data_buf_gu8a[i_u16]=eiicp_base_reg_read(addr_u16+i_u16);//调用回调函数。
                        }
                        eiicp_master_base(id_u8,EIICP_CMD_READ_REPLY,addr_u16,eiicp_data_buf_gu8a,len_u8);
                    }break;
                    case EIICP_CMD_READ_REPLY:{//读取回复。
                        for(i_u16=0;i_u16<(u16)(len_u8);i_u16++){
                            eiicp_master_read_callback(addr_u16+i_u16,eiicp_data_buf_gu8a[9+i_u16]);//调用回调函数。
                        }
                    }break;
                    case EIICP_CMD_WRITE:{//写入。
                        for(i_u16=0;i_u16<(u16)(len_u8);i_u16++){
                            eiicp_base_reg_write(addr_u16+i_u16,eiicp_data_buf_gu8a[9+i_u16]);
                        }
                        eiicp_master_base(id_u8,EIICP_CMD_WRITE_REPLY,addr_u16,(u8 *)(0),0);
                    }break;
                    case EIICP_CMD_WRITE_REPLY:{//写入回复。
                        eiicp_master_write_callback(addr_u16);
                    }break;
                }
            }
        }
    }
}
#endif
#endif  //和最上面的#ifndef配合成一个程序段。
        //以一个空行为结尾。