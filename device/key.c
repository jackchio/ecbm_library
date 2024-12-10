#include "key.h"
//------------------------------------------------------------------------------
/*------------------------------------------------------------------------------
按键初始化函数
------------------------------------------------------------------------------*/
void key_init(key_def * dev,key_u8 up_val,key_u8 down_val,key_u8 min_time,key_u8 max_time){
    dev->key_up      = up_val;
    dev->key_down    = down_val;
    dev->key_min_time= min_time;
    dev->key_max_time= max_time;
    dev->key_old_val = up_val;
    dev->key_event   = 0;
    dev->key_lock    = 0;
}
/*------------------------------------------------------------------------------
按键处理函数
------------------------------------------------------------------------------*/
void key_deal(key_def * dev,key_u8 val){
    key_u8 level;   //创建一个临时变量。
    level=0;    //临时变量清零。
    dev->key_event = 0;     //清零标志位
    dev->key_val   = val;   //读取新键值
    if(dev->key_val==dev->key_down){//如果当前状态是按下，
        level|=KEY_EVENT_LEVEL_DOWN;//置按下电平标志位。
        if(dev->key_down_count<=dev->key_max_time){//如果在最大判定时间内，
            dev->key_down_count++;//就要记录按下的时间。
            if(dev->key_down_count==dev->key_max_time){//如果到了设定的时间，
                dev->key_event=KEY_EVENT_HOLD;//置HOLD标志位
                dev->key_lock=KEY_EVENT_HOLD_LOCK;//锁定HOLD
            }
        }
        if(dev->key_old_val==dev->key_up){//判断是不是按下沿（不一定是下降沿），
            level|=KEY_EVENT_EDGE_DOWN;//置按下边沿标志位。
            if(dev->key_up_count<dev->key_min_time){//如果按下时间小于最小判断时间，
                if(dev->key_lock==KEY_EVENT_DOUBLE1_LOCK){
                    dev->key_lock=KEY_EVENT_DOUBLE2_LOCK;//双击标志位置一，且保留锁定位。
                }
            }else{
                dev->key_event=KEY_EVENT_DOWN;//按下标志位置一，且保留锁定位。
            }
            dev->key_down_count=0;
        }
    }
    if(dev->key_val==dev->key_up){//如果当前状态是抬起，
        level|=KEY_EVENT_LEVEL_UP;
        if(dev->key_up_count<=dev->key_max_time){//如果在最大判定时间内，
            dev->key_up_count++;//就要记录抬起的时间。
            if((dev->key_up_count>=dev->key_min_time)&&(dev->key_lock==KEY_EVENT_DOUBLE1_LOCK)){
                dev->key_event=KEY_EVENT_ONE;
                dev->key_lock=0;
            }
            if(dev->key_up_count==dev->key_max_time){//如果到了设定的时间，
                dev->key_lock=0;
            }
        }
        if(dev->key_old_val==dev->key_down){//判断是不是抬起沿（不一定是上升沿）   
            level|=KEY_EVENT_EDGE_UP;            
            if(dev->key_lock!=KEY_EVENT_HOLD_LOCK){
                if(dev->key_down_count>=dev->key_min_time){//如果按下时间小于最小判断时间
                    dev->key_event=KEY_EVENT_ONE;
                    dev->key_lock=0;
                }else{
                    if(dev->key_lock==KEY_EVENT_DOUBLE2_LOCK){
                        dev->key_event=KEY_EVENT_DOUBLE;
                        dev->key_lock=0;
                    }else{
                        dev->key_lock=KEY_EVENT_DOUBLE1_LOCK; 
                    }
                }
            }else{
                dev->key_lock=0;
            }
            dev->key_up_count=0;
        }
    }
    dev->key_event|=level;
    dev->key_old_val=dev->key_val;//保存键值，供下一次分析。
}