#include "ecbm_core.h"      //ͳһ���غ���ͷ�ļ�
#if (ECBM_SOFTSPI_LIB_EN)   //��鱾����û�б�ʹ��
/*--------------------------------------��������-----------------------------------*/
u8  data soft_spi_def_clk_port_gdu8;
u8  data soft_spi_def_clk_pin_gdu8;
u8  data soft_spi_def_mosi_port_gdu8;
u8  data soft_spi_def_mosi_pin_gdu8;
u8  data soft_spi_def_miso_port_gdu8;
u8  data soft_spi_def_miso_pin_gdu8;
u8  data soft_spi_mode_gdu8=0;
u8 xdata soft_spi_index_gxu8=0;
u8 xdata soft_spi_max_gxu8=0;
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
���SPI�����л�������
-------------------------------------------------------*/
void soft_spi_set_pin(soft_spi_def * dev){
    if(soft_spi_index_gxu8!=dev->dev_id){                  //�ж�ID�ţ����Լ���8us@24MHz��ʱ�䡣
        soft_spi_def_clk_port_gdu8 =io2port(dev->clk_pin); //��ѹʱ�ӽŵ�P�ڡ�
        soft_spi_def_clk_pin_gdu8  =io2pin (dev->clk_pin); //��ѹʱ�ӽŵ�IO�ڡ�
        soft_spi_def_mosi_port_gdu8=io2port(dev->mosi_pin);//��ѹ��������ŵ�P�ڡ�
        soft_spi_def_mosi_pin_gdu8 =io2pin (dev->mosi_pin);//��ѹ��������ŵ�IO�ڡ�
        soft_spi_def_miso_port_gdu8=io2port(dev->miso_pin);//��ѹ��������ŵ�P�ڡ�
        soft_spi_def_miso_pin_gdu8 =io2pin (dev->miso_pin);//��ѹ��������ŵ�IO�ڡ�
        soft_spi_mode_gdu8=dev->mode;                      //����ģʽ��
        soft_spi_index_gxu8=dev->dev_id;                   //�л�ID��
    }    
}
/*-------------------------------------------------------
���SPI��ʼ��������
-------------------------------------------------------*/
void soft_spi_init(soft_spi_def * dev,u8 clk,u8 mosi,u8 miso,u8 mode){
    dev->clk_pin =clk;             //����ʱ�ӽ���Ϣ��
    dev->mosi_pin=mosi;            //���������������Ϣ��
    dev->miso_pin=miso;            //���������������Ϣ��
    dev->mode    =mode;            //����ģʽ��Ϣ��
    gpio_mode(clk, GPIO_OUT);      //ʱ�ӽ�����Ϊ���졣
    if(mode&SOFT_SPI_CPOL_MASK){   //�鿴ʱ�Ӽ������ã�
        gpio_out(clk,1);           //�����Ǹߵ�ƽ�����øߣ�
    }else{
        gpio_out(clk,0);           //�����ǵ͵�ƽ�����õ͡�
    }
    if(mode&SOFT_SPI_MOSI_EN_MASK){//�鿴MOSIʹ�ܣ�
        gpio_mode(mosi,GPIO_OUT);  //ʹ���˾�����Ϊ����ģʽ��
        gpio_out (mosi,1);         //Ĭ�ϸߵ�ƽ��
    }
    if(mode&SOFT_SPI_MISO_EN_MASK){//�鿴MISOʹ�ܣ�
        gpio_mode  (miso,GPIO_IN); //ʹ���˾�����Ϊ������ģʽ��
        gpio_out   (miso,1);       //Ĭ�ϸߵ�ƽ��
    }
    dev->dev_id=++soft_spi_max_gxu8;    //��ȡID�š�
    soft_spi_set_pin(dev);         //���ò�����ϵͳ��
} 
/*-------------------------------------------------------
���SPI�����л������������棩��
-------------------------------------------------------*/
void soft_spi_set_pin_linkage(u8 id,u8 clk,u8 mosi,u8 miso,u8 mode){
    if(soft_spi_index_gxu8!=id){                    //�ж�ID�ţ����Լ���8us@24MHz��ʱ�䡣
        soft_spi_def_clk_port_gdu8 =io2port(clk);   //��ѹʱ�ӽŵ�P�ڡ�
        soft_spi_def_clk_pin_gdu8  =io2pin (clk);   //��ѹʱ�ӽŵ�IO�ڡ�
        soft_spi_def_mosi_port_gdu8=io2port(mosi);  //��ѹ��������ŵ�P�ڡ�
        soft_spi_def_mosi_pin_gdu8 =io2pin (mosi);  //��ѹ��������ŵ�IO�ڡ�
        soft_spi_def_miso_port_gdu8=io2port(miso);  //��ѹ��������ŵ�P�ڡ�
        soft_spi_def_miso_pin_gdu8 =io2pin (miso);  //��ѹ��������ŵ�IO�ڡ�
        soft_spi_mode_gdu8=mode;                    //����ģʽ��
        soft_spi_index_gxu8=id;                     //�л�ID��
    }    
}
/*-------------------------------------------------------
���SPI��ʼ�������������棩��
-------------------------------------------------------*/
u8 soft_spi_init_linkage(u8 clk,u8 mosi,u8 miso,u8 mode){
    u8 id_u8;                         //ΨһID��
    gpio_mode(clk, GPIO_OUT);      //ʱ�ӽ�����Ϊ���졣
    if(mode&SOFT_SPI_CPOL_MASK){   //�鿴ʱ�Ӽ������ã�
        gpio_out(clk,1);           //�����Ǹߵ�ƽ�����øߣ�
    }else{
        gpio_out(clk,0);           //�����ǵ͵�ƽ�����õ͡�
    }
    if(mode&SOFT_SPI_MOSI_EN_MASK){//�鿴MOSIʹ�ܣ�
        gpio_mode(mosi,GPIO_OUT);  //ʹ���˾�����Ϊ����ģʽ��
        gpio_out (mosi,1);         //Ĭ�ϸߵ�ƽ��
    }
    if(mode&SOFT_SPI_MISO_EN_MASK){//�鿴MISOʹ�ܣ�
        gpio_mode  (miso,GPIO_IN); //ʹ���˾�����Ϊ������ģʽ��
        gpio_out   (miso,1);       //Ĭ�ϸߵ�ƽ��
    }
    id_u8 =++soft_spi_max_gxu8;            //��ȡID�š�
    soft_spi_set_pin_linkage(id_u8,clk,mosi,miso,mode);//���ò�����ϵͳ��
    return id_u8;                       //����ID�š�
} 
/*-------------------------------------------------------
���SPI����/���պ�����
-------------------------------------------------------*/
u8 soft_spi_send(u8 dat){
    u8 i_u8,j_u8,k_u8=0;
    if(soft_spi_mode_gdu8&SOFT_SPI_CPOL_MASK){                           //��ȡʱ�Ӽ��Բ�����
        gpio_out_fast(soft_spi_def_clk_port_gdu8,soft_spi_def_clk_pin_gdu8,1);//���ݲ�������һ��IO�ĳ�ʼ״̬��
    }else{
        gpio_out_fast(soft_spi_def_clk_port_gdu8,soft_spi_def_clk_pin_gdu8,0);//Ŀ����Ϊ�˷�ֹ�����Ÿ����µĵ�ƽ��λ��
    }
    if(soft_spi_mode_gdu8&SOFT_SPI_MSB_LSB_MASK){//������ȷ���λ��
        i_u8=0x80;
        for(j_u8=0;j_u8<8;j_u8++){                   //8λ�����ݡ�
            if(dat&i_u8){                      //���ݵ�ǰλ���������ƽ��
                gpio_out_fast(soft_spi_def_mosi_port_gdu8,soft_spi_def_mosi_pin_gdu8,1);
            }else{
                gpio_out_fast(soft_spi_def_mosi_port_gdu8,soft_spi_def_mosi_pin_gdu8,0);
            }
            gpio_toggle_fast(soft_spi_def_clk_port_gdu8,soft_spi_def_clk_pin_gdu8);//ʱ�ӽŵ�һ�η�ת��
            if((soft_spi_mode_gdu8&SOFT_SPI_MISO_EN_MASK)&&((soft_spi_mode_gdu8&SOFT_SPI_CPHA_MASK)==0)){//��ȡʱ����λ���á�
                if(gpio_in_fast(soft_spi_def_miso_port_gdu8,soft_spi_def_miso_pin_gdu8)){//�����ǵ�һ�η�ת���Ļ����Ͷ�MISO�š�
                    k_u8|=i_u8;//��MISO�ŵ����ݴ�����ʱ�����
                }
            }
            gpio_toggle_fast(soft_spi_def_clk_port_gdu8,soft_spi_def_clk_pin_gdu8);//ʱ�ӽŵڶ��η�ת��
            if((soft_spi_mode_gdu8&SOFT_SPI_MISO_EN_MASK)&&((soft_spi_mode_gdu8&SOFT_SPI_CPHA_MASK)==1)){//��ȡʱ����λ���á�
                if(gpio_in_fast(soft_spi_def_miso_port_gdu8,soft_spi_def_miso_pin_gdu8)){//�����ǵڶ��η�ת���Ļ����Ͷ�MISO�š�
                    k_u8|=i_u8;//��MISO�ŵ����ݴ�����ʱ�����
                }
            }
            i_u8>>=1;
        }
    }else{                                  //������ȷ���λ
        i_u8=0x01;
        for(j_u8=0;j_u8<8;j_u8++){                  //8λ�����ݡ�
            if(dat&i_u8){                     //���ݵ�ǰλ���������ƽ��
                gpio_out_fast(soft_spi_def_mosi_port_gdu8,soft_spi_def_mosi_pin_gdu8,1);
            }else{
                gpio_out_fast(soft_spi_def_mosi_port_gdu8,soft_spi_def_mosi_pin_gdu8,0);
            }
            gpio_toggle_fast(soft_spi_def_clk_port_gdu8,soft_spi_def_clk_pin_gdu8);//ʱ�ӽŵ�һ�η�ת��
            if((soft_spi_mode_gdu8&SOFT_SPI_MISO_EN_MASK)&&((soft_spi_mode_gdu8&SOFT_SPI_CPHA_MASK)==0)){//��ȡʱ����λ���á�
                if(gpio_in_fast(soft_spi_def_miso_port_gdu8,soft_spi_def_miso_pin_gdu8)){//�����ǵ�һ�η�ת���Ļ����Ͷ�MISO�š�
                    k_u8|=i_u8;//��MISO�ŵ����ݴ�����ʱ�����
                }
            }
            gpio_toggle_fast(soft_spi_def_clk_port_gdu8,soft_spi_def_clk_pin_gdu8);
            if((soft_spi_mode_gdu8&SOFT_SPI_MISO_EN_MASK)&&((soft_spi_mode_gdu8&SOFT_SPI_CPHA_MASK)==1)){//��ȡʱ����λ���á�
                if(gpio_in_fast(soft_spi_def_miso_port_gdu8,soft_spi_def_miso_pin_gdu8)){//�����ǵڶ��η�ת���Ļ����Ͷ�MISO�š�
                    k_u8|=i_u8;//��MISO�ŵ����ݴ�����ʱ�����
                }
            }
            i_u8<<=1;
        }
    }
    return k_u8;//���ػ���ֵ��
}
#endif  //���������#ifndef��ϳ�һ������Ρ�
        //��һ������Ϊ��β��