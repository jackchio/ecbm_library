#include "key.h"
//------------------------------------------------------------------------------
/*------------------------------------------------------------------------------
������ʼ������
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
����������
------------------------------------------------------------------------------*/
void key_deal(key_def * dev,key_u8 val){
    key_u8 level;   //����һ����ʱ������
    level=0;    //��ʱ�������㡣
    dev->key_event = 0;     //�����־λ
    dev->key_val   = val;   //��ȡ�¼�ֵ
    if(dev->key_val==dev->key_down){//�����ǰ״̬�ǰ��£�
        level|=KEY_EVENT_LEVEL_DOWN;//�ð��µ�ƽ��־λ��
        if(dev->key_down_count<=dev->key_max_time){//���������ж�ʱ���ڣ�
            dev->key_down_count++;//��Ҫ��¼���µ�ʱ�䡣
            if(dev->key_down_count==dev->key_max_time){//��������趨��ʱ�䣬
                dev->key_event=KEY_EVENT_HOLD;//��HOLD��־λ
                dev->key_lock=KEY_EVENT_HOLD_LOCK;//����HOLD
            }
        }
        if(dev->key_old_val==dev->key_up){//�ж��ǲ��ǰ����أ���һ�����½��أ���
            level|=KEY_EVENT_EDGE_DOWN;//�ð��±��ر�־λ��
            if(dev->key_up_count<dev->key_min_time){//�������ʱ��С����С�ж�ʱ�䣬
                if(dev->key_lock==KEY_EVENT_DOUBLE1_LOCK){
                    dev->key_lock=KEY_EVENT_DOUBLE2_LOCK;//˫����־λ��һ���ұ�������λ��
                }
            }else{
                dev->key_event=KEY_EVENT_DOWN;//���±�־λ��һ���ұ�������λ��
            }
            dev->key_down_count=0;
        }
    }
    if(dev->key_val==dev->key_up){//�����ǰ״̬��̧��
        level|=KEY_EVENT_LEVEL_UP;
        if(dev->key_up_count<=dev->key_max_time){//���������ж�ʱ���ڣ�
            dev->key_up_count++;//��Ҫ��¼̧���ʱ�䡣
            if((dev->key_up_count>=dev->key_min_time)&&(dev->key_lock==KEY_EVENT_DOUBLE1_LOCK)){
                dev->key_event=KEY_EVENT_ONE;
                dev->key_lock=0;
            }
            if(dev->key_up_count==dev->key_max_time){//��������趨��ʱ�䣬
                dev->key_lock=0;
            }
        }
        if(dev->key_old_val==dev->key_down){//�ж��ǲ���̧���أ���һ���������أ�   
            level|=KEY_EVENT_EDGE_UP;            
            if(dev->key_lock!=KEY_EVENT_HOLD_LOCK){
                if(dev->key_down_count>=dev->key_min_time){//�������ʱ��С����С�ж�ʱ��
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
    dev->key_old_val=dev->key_val;//�����ֵ������һ�η�����
}