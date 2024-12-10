#include "ecbm_core.h"      //ͳһ���غ���ͷ�ļ�
#if (ECBM_SOFTIIC_LIB_EN)   //��鱾����û�б�ʹ��
/*--------------------------------------��������-----------------------------------*/
u8 data soft_iic_def_sda_port_gdu8;
u8 data soft_iic_def_sda_pin_gdu8;
u8 data soft_iic_def_scl_port_gdu8;
u8 data soft_iic_def_scl_pin_gdu8;
u8 data soft_iic_max_gdu8=0;
u8 data soft_iic_index_gdu8=0;
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
���IIC�����л�������
-------------------------------------------------------*/
void soft_iic_set_pin(soft_iic_def * dev){
    if(soft_iic_index_gdu8!=dev->dev_id){
        soft_iic_def_scl_port_gdu8=io2port(dev->scl_pin);
        soft_iic_def_scl_pin_gdu8 =io2pin (dev->scl_pin);
        soft_iic_def_sda_port_gdu8=io2port(dev->sda_pin);
        soft_iic_def_sda_pin_gdu8 =io2pin (dev->sda_pin);
        soft_iic_index_gdu8=dev->dev_id;
    }    
}
/*-------------------------------------------------------
���IIC��ʼ��������
-------------------------------------------------------*/
void soft_iic_init(soft_iic_def * dev,u8 scl,u8 sda){
    dev->scl_pin=scl;
    dev->sda_pin=sda;
    gpio_mode   (scl,GPIO_OD);//IIC��������Ҫ�ǿ�©ģʽ
    gpio_mode   (sda,GPIO_OD);//IIC��������Ҫ�ǿ�©ģʽ
    gpio_uppull (scl,1);    //IIC��Ҫһ����������
    gpio_uppull (sda,1);    //IIC��Ҫһ����������
    gpio_out    (scl,1);
    gpio_out    (sda,1);
    dev->dev_id =++soft_iic_max_gdu8;
    soft_iic_set_pin(dev);
}
/*-------------------------------------------------------
���IIC�����л������������棩��
-------------------------------------------------------*/
void soft_iic_set_pin_linkage(u8 id,u8 scl,u8 sda){
    if(soft_iic_index_gdu8!=id){
        soft_iic_def_scl_port_gdu8=io2port(scl);
        soft_iic_def_scl_pin_gdu8 =io2pin (scl);
        soft_iic_def_sda_port_gdu8=io2port(sda);
        soft_iic_def_sda_pin_gdu8 =io2pin (sda);
        soft_iic_index_gdu8=id;
    }    
}
/*-------------------------------------------------------
���IIC��ʼ�������������棩��
-------------------------------------------------------*/
u8 soft_iic_init_linkage(u8 scl,u8 sda){
    u8 id_u8;
    gpio_mode   (scl,GPIO_OD);//IIC��������Ҫ�ǿ�©ģʽ
    gpio_mode   (sda,GPIO_OD);//IIC��������Ҫ�ǿ�©ģʽ
    gpio_uppull (scl,1);      //IIC��Ҫһ����������
    gpio_uppull (sda,1);      //IIC��Ҫһ����������
    gpio_out    (scl,1);      //����IIC����
    gpio_out    (sda,1);
    id_u8 =++soft_iic_max_gdu8;
    soft_iic_set_pin_linkage(id_u8,scl,sda);
    return id_u8;
}
/*-------------------------------------------------------
���IIC����������
-------------------------------------------------------*/
u8 soft_iic_start(void){
    gpio_out_fast   (soft_iic_def_sda_port_gdu8,soft_iic_def_sda_pin_gdu8,1);
    gpio_out_fast   (soft_iic_def_scl_port_gdu8,soft_iic_def_scl_pin_gdu8,1);
    if(gpio_in_fast (soft_iic_def_sda_port_gdu8,soft_iic_def_sda_pin_gdu8)==0)return -1;/* SDA��Ϊ�͵�ƽ������æ,�˳� */
    gpio_toggle_fast(soft_iic_def_sda_port_gdu8,soft_iic_def_sda_pin_gdu8);
    if(gpio_in_fast (soft_iic_def_sda_port_gdu8,soft_iic_def_sda_pin_gdu8)==1)return -1;/* SDA��Ϊ�ߵ�ƽ�����߳���,�˳� */
    gpio_toggle_fast(soft_iic_def_scl_port_gdu8,soft_iic_def_scl_pin_gdu8);
    return 0;
}
/*-------------------------------------------------------
���IICֹͣ������
-------------------------------------------------------*/
void soft_iic_stop(void){
    gpio_out_fast   (soft_iic_def_sda_port_gdu8,soft_iic_def_sda_pin_gdu8,0);
    gpio_out_fast   (soft_iic_def_scl_port_gdu8,soft_iic_def_scl_pin_gdu8,0);
    gpio_toggle_fast(soft_iic_def_scl_port_gdu8,soft_iic_def_scl_pin_gdu8);
    gpio_toggle_fast(soft_iic_def_sda_port_gdu8,soft_iic_def_sda_pin_gdu8);
}
/*-------------------------------------------------------
���IIC����дACK������
-------------------------------------------------------*/
void soft_iic_write_ack(void){
    gpio_out_fast   (soft_iic_def_scl_port_gdu8,soft_iic_def_scl_pin_gdu8,0);
    gpio_out_fast   (soft_iic_def_sda_port_gdu8,soft_iic_def_sda_pin_gdu8,0);
    gpio_toggle_fast(soft_iic_def_scl_port_gdu8,soft_iic_def_scl_pin_gdu8);
    gpio_toggle_fast(soft_iic_def_scl_port_gdu8,soft_iic_def_scl_pin_gdu8);
}
/*-------------------------------------------------------
���IIC����дNO ACK������
-------------------------------------------------------*/
void soft_iic_write_nack(void){
    gpio_out_fast   (soft_iic_def_scl_port_gdu8,soft_iic_def_scl_pin_gdu8,0);
    gpio_out_fast   (soft_iic_def_sda_port_gdu8,soft_iic_def_sda_pin_gdu8,1);
    gpio_toggle_fast(soft_iic_def_scl_port_gdu8,soft_iic_def_scl_pin_gdu8);
    gpio_toggle_fast(soft_iic_def_scl_port_gdu8,soft_iic_def_scl_pin_gdu8);
}
/*-------------------------------------------------------
���IIC������ACK������
-------------------------------------------------------*/
u8 soft_iic_read_ack(void){
    gpio_out_fast   (soft_iic_def_scl_port_gdu8,soft_iic_def_scl_pin_gdu8,0);
    gpio_out_fast   (soft_iic_def_sda_port_gdu8,soft_iic_def_sda_pin_gdu8,1);
    gpio_toggle_fast(soft_iic_def_scl_port_gdu8,soft_iic_def_scl_pin_gdu8);
    if(gpio_in_fast (soft_iic_def_sda_port_gdu8,soft_iic_def_sda_pin_gdu8)==1){
        gpio_toggle_fast(soft_iic_def_scl_port_gdu8,soft_iic_def_scl_pin_gdu8);
        return -1;
    }
    gpio_toggle_fast(soft_iic_def_scl_port_gdu8,soft_iic_def_scl_pin_gdu8);
    return 0;
}
/*-------------------------------------------------------
���IIC����д������
-------------------------------------------------------*/
void soft_iic_write(u8 dat){
    u8 i,old;
    old=dat;
    if(dat&0x80){
        gpio_out_fast(soft_iic_def_sda_port_gdu8,soft_iic_def_sda_pin_gdu8,1);
    }else{
        gpio_out_fast(soft_iic_def_sda_port_gdu8,soft_iic_def_sda_pin_gdu8,0);
    }
    gpio_out_fast(soft_iic_def_scl_port_gdu8,soft_iic_def_scl_pin_gdu8,0);
    for(i=0;i<8;i++){
        if((old^dat)&0x80){
            gpio_toggle_fast(soft_iic_def_sda_port_gdu8,soft_iic_def_sda_pin_gdu8);
        }
        gpio_toggle_fast(soft_iic_def_scl_port_gdu8,soft_iic_def_scl_pin_gdu8);
        old=dat;
        dat<<=1;
        gpio_toggle_fast(soft_iic_def_scl_port_gdu8,soft_iic_def_scl_pin_gdu8);
    }
}
/*-------------------------------------------------------
���IIC������������
-------------------------------------------------------*/
u8 soft_iic_read(void){
    u8 i,dat;
    dat=0;
    gpio_out_fast(soft_iic_def_sda_port_gdu8,soft_iic_def_sda_pin_gdu8,1);
    for(i=0;i<8;i++){
        dat<<=1;
        gpio_out_fast(soft_iic_def_scl_port_gdu8,soft_iic_def_scl_pin_gdu8,1);
        if(gpio_in_fast(soft_iic_def_sda_port_gdu8,soft_iic_def_sda_pin_gdu8)==1){
            dat|=0x01;
        }
        gpio_out_fast(soft_iic_def_scl_port_gdu8,soft_iic_def_scl_pin_gdu8,0);
    }
    return dat;
}
/*-------------------------------------------------------
���IIC����Ѱ�Һ�����
-------------------------------------------------------*/
#if (SOFT_IIC_FIND_EN)
    u8 soft_iic_find(u8 addr[]){
        u8 i,c;
        c=0;
        for(i=0;i<128;i++){
            soft_iic_start();
            soft_iic_write(i<<1);
            if(soft_iic_read_ack()==0){
                addr[c]=(i<<1);
                c++;
            }
            soft_iic_stop();
        }    
        return c;
    }
#endif
#endif  //���������#ifndef��ϳ�һ������Ρ�
        //��һ������Ϊ��β��