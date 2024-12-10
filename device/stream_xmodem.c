#include "ecbm_core.h"  //统一加载核心头文件
//未开发阶段！！
#if (0)&&(ECBM_10MS_EN)&&(ECBM_STREAM_LIB_EN)&&(ECBM_STREAM_XMODEM_CH_COUNT)    //检查本库有没有被使能
/*--------------------------------------变量定义-----------------------------------*/
u8    es_xmodem_buf_start  =0; //xmodem的数据在缓存中的开始位置。
u8    es_xmodem_sum        =0; //校验和。
u8    es_xmodem_pack       =0; //数据包编号。
u8    es_xmodem_status     =0; //Xmodem状态机状态。
u8    es_xmodem_count      =0; //接收数据计数。
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
xmodem开始接收函数。
-------------------------------------------------------*/
void es_xmodem_start(void){             //开启函数，用于开始传输数据。
    es_xmodem_pack=0;                   //清除包编号。
    es_xmodem_status=ES_XMODEM_READY;   //转到就绪态。
    uart_char(ECBM_STREAM_UART,ES_XMODEM_NAK);     //发送NACK，通知上位机开始通信。
}
/*-------------------------------------------------------
数据接收函数。
-------------------------------------------------------*/
void es_xmodem_exe(u8 dat){
    u8 i;
    switch(es_xmodem_status){
        case ES_XMODEM_READY:{//就绪状态。
            if(dat==ES_XMODEM_SOH){                     //如果收到SOH字段，
                es_xmodem_status=ES_XMODEM_READ_PACK;   //跳到读取包编号。
                es_xmodem_sum=dat;                      //从这里就开始计算校验和。
            }else if(dat==ES_XMODEM_EOT){               //如果收到EOT字段，
                uart_char(ECBM_STREAM_UART,ES_XMODEM_ACK);//发送ACK，通知上位机接收EOT了。
                es_xmodem_status=ES_XMODEM_STOP;        //到停止状态。
            }else if(dat==ES_XMODEM_CAN){               //如果收到CAN字段，
                es_xmodem_status=ES_XMODEM_STOP;        //跳到停止状态。
            }
        }break;
        case ES_XMODEM_READ_PACK:{//读取包编号。
            es_xmodem_pack=dat;                     //将当前的数据包编号存着。
            es_xmodem_sum+=dat;                     //计算校验和。
            es_xmodem_status=ES_XMODEM_CHECK_PACK;  //跳到确认包编号。
        }break;
        case ES_XMODEM_CHECK_PACK:{//确认包编号。
            if(es_xmodem_pack==(~dat)){                 //如果编号的反码正确。
                es_xmodem_status=ES_XMODEM_READ_MODE;   //跳到读数据模式。
                es_xmodem_sum+=dat;                     //计算校验和。
                es_xmodem_count=0;                      //重置缓存指针。
                if(ecbm_stream_start>=(ECBM_STREAM_SZIE-1)){//其实就是判断(start+1)>=szie。但是换成判断size-1的话可以规避255+1溢出问题。
                    es_xmodem_buf_start=0;              //如果确实大于size了，就从头开始。
                }else{                                  //否则就定位下一位。
                    es_xmodem_buf_start=ecbm_stream_start+1;//因为当前是包编号反码，下一位才是数据。
                }
            }else{                                      //反码不正确说明不是帧头，
                es_xmodem_status=ES_XMODEM_ERROR;       //跳到错误态。
            }            
        }break;
        case ES_XMODEM_READ_MODE:{//接收数据模式。
            es_xmodem_sum+=dat;                         //计算校验和。
            es_xmodem_count++;                          //缓存指针加一。
            if(es_xmodem_count>=128){                   //如果接收了128个数据，
                es_xmodem_status=ES_XMODEM_CHECK_DATA;  //进入检测数据校验。
            }                                           //数据都在stream缓存里，这里不用额外储存。
        }break;
        case ES_XMODEM_CHECK_DATA:{//检查校验和。
            if(dat==es_xmodem_sum){                     //如果校验正确，
                for(i=0;i<128;i++){                     //X-modem通常是一个包有128字节的数据。
                    es_xmodem_write_reg(es_xmodem_pack,i,ecbm_stream_buf[es_xmodem_buf_start]);//调用数据输入函数来处理这些数据。
                    es_xmodem_buf_start++;                      //每输入一个数据，变量就+1。
                    if(es_xmodem_buf_start>=ECBM_STREAM_SZIE){  //当然也要防止溢出。
                        es_xmodem_buf_start=0;                  //溢出就清零。
                    }
                }
                uart_char(ECBM_STREAM_UART,ES_XMODEM_ACK);         //发送ACK，通知上位机发下一包。
            }else{                                      //如果校验不正确，
                uart_char(ECBM_STREAM_UART,ES_XMODEM_NAK);         //发送NACK，通知上位机重发。
            }           
            es_xmodem_status=ES_XMODEM_READY;           //到了这一步，这一帧就处理完了，恢复到就绪态。         
        }break;
    }
}
#endif  //和最上面的#ifndef配合成一个程序段。
        //以一个空行为结尾。