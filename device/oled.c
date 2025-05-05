#include "oled.h"//加载头文件
/*------------------------------------资源冲突警告---------------------------------*/
#if ((OLED_HARD_SPI_EN+OLED_SOFT_SPI_EN+OLED_HARD_IIC_EN+OLED_SOFT_IIC_EN)==0)
#error OLED的所有通信协议都关闭了呢，起码得开放一个通信协议吧！
#endif
/*--------------------------------------程序定义-----------------------------------*/
#if OLED_SOFT_IIC_EN
/*-------------------------------------------------------
OLED设置引脚函数，用于软件IIC模式。
-------------------------------------------------------*/
extern u8 soft_iic_init_linkage(u8 scl,u8 sda);
void oled_set_soft_iic(oled_def * dev,u8 scl,u8 sda){
    dev->mode   =(dev->mode&0x0F)|OLED_SOFT_IIC;//设置模式为软件IIC。
    dev->id     =soft_iic_init_linkage(scl,sda);//调用内联函数初始化软件IIC。
    dev->scl_pin=scl;                           //保存时钟脚设置。
    dev->sda_pin=sda;                           //保存数据脚设置。
    dev->addr   =0x78;                          //默认地址是0x78。
}
/*-------------------------------------------------------
OLED的写函数，用于软件IIC模式。
-------------------------------------------------------*/
void oled_write_soft_iic(oled_def * dev,u8 cd,u8 buf,u16 len){
    u16 i;
    soft_iic_start   ();            //开始IIC。
    soft_iic_write   (dev->addr);   //写入OLED器件地址。
    soft_iic_read_ack();            //等待ACK。
    soft_iic_write   (cd);          //写入控制字。
    soft_iic_read_ack();            //等待ACK。
    for(i=0;i<len;i++){
        soft_iic_write(buf);        //写入数据/指令。
        soft_iic_read_ack();        //等待ACK。
    }
    soft_iic_stop();                //结束IIC。
}
/*-------------------------------------------------------
OLED的写函数扩充版，用于软件IIC模式。
-------------------------------------------------------*/
void oled_write_soft_iic_ex(oled_def * dev,u8 cd,u8 buf[],u16 len){
    u16 i;
    soft_iic_start   ();            //开始IIC。
    soft_iic_write   (dev->addr);   //写入OLED器件地址。
    soft_iic_read_ack();            //等待ACK。
    soft_iic_write   (cd);          //写入控制字。
    soft_iic_read_ack();
    for(i=0;i<len;i++){
        soft_iic_write(buf[i]);     //写入数据/指令。
        soft_iic_read_ack();        //等待ACK。
    }
    soft_iic_stop();                //结束IIC。
}
#endif
#if OLED_HARD_IIC_EN
/*-------------------------------------------------------
OLED设置引脚函数，用于硬件IIC模式。
-------------------------------------------------------*/
void oled_set_hard_iic(oled_def * dev,u8 scl,u8 sda){
    dev->mode   =(dev->mode&0x0F)|OLED_HARD_IIC;//设置模式为硬件IIC。
#if (ECBM_MCU==0x310201)||(ECBM_MCU==0x3102A1)
    if((scl==D32)&&(sda==D33)){//根据设置填入ID号。
        dev->id=IIC_PIN_P32_P33;
    }else if((scl==D54)&&(sda==D55)){
        dev->id=IIC_PIN_P54_P55;
    }
#else
    if((scl==D15)&&(sda==D14)){//根据设置填入ID号。
        dev->id=IIC_PIN_P15_P14;
    }else if((scl==D25)&&(sda==D24)){
        dev->id=IIC_PIN_P25_P24;
    }else if((scl==D77)&&(sda==D76)){
        dev->id=IIC_PIN_P77_P76;
    }else if((scl==D32)&&(sda==D33)){
        dev->id=IIC_PIN_P32_P33;
    }
#endif
    dev->scl_pin=scl;   //保存时钟脚设置。
    dev->sda_pin=sda;   //保存数据脚设置。
    dev->addr   =0x78;  //默认地址是0x78。
    iic_master_init();  //初始化硬件IIC。
    iic_set_pin(dev->id);
}
/*-------------------------------------------------------
OLED的写函数，用于硬件IIC模式。
-------------------------------------------------------*/
void oled_write_hard_iic(oled_def * dev,u8 cd,u8 buf,u16 len){
    u16 i;
    iic_start   ();     //开始IIC。
    iic_write   (dev->addr);//写入OLED器件地址。
    iic_read_ack();     //等待ACK。
    iic_write   (cd);   //写入控制字。
    iic_read_ack();     //等待ACK。
    for(i=0;i<len;i++){
        iic_write(buf); //写入数据/指令。
        iic_read_ack(); //等待ACK。
    }
    iic_stop();         //结束IIC。
}
/*-------------------------------------------------------
OLED的写函数扩充版，用于硬件IIC模式。
-------------------------------------------------------*/
void oled_write_hard_iic_ex(oled_def * dev,u8 cd,u8 buf[],u16 len){
    u16 i;
    iic_start   ();         //开始IIC。
    iic_write   (dev->addr);//写入OLED器件地址。
    iic_read_ack();         //等待ACK。
    iic_write   (cd);       //写入控制字。
    iic_read_ack();         //等待ACK。
    for(i=0;i<len;i++){
        iic_write(buf[i]);  //写入数据/指令。
        iic_read_ack();     //等待ACK。
    }
    iic_stop();             //结束IIC。
}
#endif
#if OLED_SOFT_SPI_EN
/*-------------------------------------------------------
OLED设置引脚函数，用于软件SPI模式。
-------------------------------------------------------*/
extern u8 soft_spi_init_linkage(u8 clk,u8 mosi,u8 miso,u8 mode);
void oled_set_soft_spi(oled_def * dev,u8 scl,u8 sda,u8 dc,u8 rst,u8 cs){
    if(cs!=Dxx){                                //如果CS脚指定了，
        dev->mode=(dev->mode&0x0F)|OLED_SOFT_SPI|OLED_CS_ENABLE; //那么设置模式为软件SPI+CS，
    }else{                                      //否则
        dev->mode=(dev->mode&0x0F)|OLED_SOFT_SPI;//只设置模式为软件SPI。
    }
    dev->id     =soft_spi_init_linkage(scl,sda,Dxx,0x96);//初始化软件SPI
    dev->scl_pin=scl;           //保存时钟脚设置。
    dev->sda_pin=sda;           //保存数据脚设置。
    dev->rst_pin=rst;           //保存复位脚设置。
    dev->cs_pin =cs;            //保存片选脚设置。
    dev->dc_pin =dc;            //保存DC脚设置。
    gpio_mode   (dc,GPIO_OUT);  //DC脚设置为推挽。
    gpio_out    (dc,1);         //默认高电平。
    gpio_mode   (rst,GPIO_OUT); //复位脚设置为推挽。
    gpio_out    (rst,1);        //默认为高电平。
    gpio_mode   (cs,GPIO_OUT);  //片选脚设置为推挽。
    gpio_out    (cs,1);         //默认为高电平。
}
/*-------------------------------------------------------
OLED的写函数，用于软件SPI模式。
-------------------------------------------------------*/
void oled_write_soft_spi(oled_def * dev,u8 cd,u8 buf){
    if(cd==oled_dat){           //根据参数判断是数据还是指令，
        gpio_out(dev->dc_pin,1);//是数据就置一。
    }else{
        gpio_out(dev->dc_pin,0);//是指令就置零。
    }
    soft_spi_send(buf);         //然后写数据/指令
}
#endif
#if OLED_HARD_SPI_EN
/*-------------------------------------------------------
OLED设置引脚函数，用于硬件SPI模式。
-------------------------------------------------------*/
void oled_set_hard_spi(oled_def * dev,u8 scl,u8 sda,u8 dc,u8 rst,u8 cs){
    if(cs!=Dxx){                                //如果CS脚指定了，
        dev->mode=(dev->mode&0x0F)|OLED_HARD_SPI|OLED_CS_ENABLE; //那么设置模式为硬件SPI+CS，
    }else{                                      //否则
        dev->mode=(dev->mode&0x0F)|OLED_HARD_SPI;//只设置模式为硬件SPI。
    }
    dev->scl_pin =scl;//保存时钟脚设置。
    dev->sda_pin =sda;//保存数据脚设置。
    if((scl==D15)&&(sda==D13)){
        dev->id=SPI_PIN_P12_P13_P14_P15;
    }else if((scl==D25)&&(sda==D23)){
        dev->id=SPI_PIN_P22_P23_P24_P25;
    }else if((scl==D77)&&(sda==D75)){
        dev->id=SPI_PIN_P74_P75_P76_P77;
    }else if((scl==D32)&&(sda==D34)){
        dev->id=SPI_PIN_P35_P34_P33_P32;
    }
    dev->rst_pin=rst;           //保存复位脚设置。
    dev->cs_pin =cs;            //保存片选脚设置。
    dev->dc_pin =dc;            //保存DC脚设置
    gpio_mode   (dc,GPIO_OUT);  //DC脚设置为推挽。
    gpio_out    (dc,1);         //默认高电平。
    gpio_mode   (rst,GPIO_OUT); //复位脚设置为推挽。
    gpio_out    (rst,1);        //默认高电平。
    gpio_mode   (cs,GPIO_OUT);  //片选脚设置为推挽。
    gpio_out    (cs,1);         //默认为高电平。
    spi_init();                 //初始化硬件SPI。
}
/*-------------------------------------------------------
OLED的写函数，用于硬件SPI模式。
-------------------------------------------------------*/
void oled_write_hard_spi(oled_def * dev,u8 cd,u8 buf){
    if(cd==oled_dat){           //根据参数判断是数据还是指令，
        gpio_out(dev->dc_pin,1);//是数据就置一。
    }else{
        gpio_out(dev->dc_pin,0);//是指令就置零。
    }
    spi_send(buf);              //然后写数据/指令
}
#endif
/*-------------------------------------------------------
OLED的写函数，通用。
-------------------------------------------------------*/
void oled_write(oled_def * dev,u8 cd,u8 buf){
    if((dev->mode&OLED_SERIAL_IIC_SPI_MASK)==0){//spi
        if(dev->mode&OLED_HARD_SOFT_WARE_MASK){ //hard
#if (OLED_HARD_SPI_EN)
            oled_write_hard_spi(dev,cd,buf);
#endif
        }else{                                  //soft
#if (OLED_SOFT_SPI_EN)
            oled_write_soft_spi(dev,cd,buf);
#endif
        }
    }else{//iic
        if(dev->mode&OLED_HARD_SOFT_WARE_MASK){ //hard
#if (OLED_HARD_IIC_EN)
            oled_write_hard_iic(dev,cd,buf,1);
#endif
        }else{                                  //soft
#if (OLED_SOFT_IIC_EN)
            oled_write_soft_iic(dev,cd,buf,1);
#endif
        }
    }
}
/*-------------------------------------------------------
开启OLED函数。
-------------------------------------------------------*/
void oled_on(oled_def * dev){
    oled_write(dev,oled_cmd,0xAF);
}
/*-------------------------------------------------------
关闭OLED函数。
-------------------------------------------------------*/
void oled_off(oled_def * dev){
    oled_write(dev,oled_cmd,0xAE);
}
/*-------------------------------------------------------
OLED设置COM引脚数函数。
-------------------------------------------------------*/
void oled_set_com(oled_def * dev,u8 num){
    oled_write(dev,oled_cmd,0xA8);
    oled_write(dev,oled_cmd,num);
}
/*-------------------------------------------------------
OLED设置对比度函数。
-------------------------------------------------------*/
void oled_set_contrast(oled_def * dev,u8 val){
    oled_write(dev,oled_cmd,0x81);
    oled_write(dev,oled_cmd,val); 
}
/*-------------------------------------------------------
OLED设置数据指针函数。
-------------------------------------------------------*/
void oled_set_pos(oled_def * dev,u8 x,u8 y){
    oled_write(dev,oled_cmd,0xB0+y);
    oled_write(dev,oled_cmd,((x&0xF0)>>4)|0x10);
    oled_write(dev,oled_cmd,x&0x0F);
}
/*-------------------------------------------------------
OLED设置逻辑引脚偏移函数。
-------------------------------------------------------*/
void oled_set_offset_logic(oled_def * dev,u8 offset){//设置逻辑引脚相对于硬件引脚的偏移
    oled_write(dev,oled_cmd,0xD3);
    oled_write(dev,oled_cmd,offset);
}
/*-------------------------------------------------------
OLED设置RAM偏移函数。
-------------------------------------------------------*/
void oled_set_offset_ram(oled_def * dev,u8 offset){//设置RAM相对逻辑引脚的偏移
    oled_write(dev,oled_cmd,0x40|offset);
}
/*-------------------------------------------------------
OLED显示模式设置函数。
-------------------------------------------------------*/
void oled_set_display_mode(oled_def * dev,u8 mode){
    if(mode&0x01){
        oled_write(dev,oled_cmd,0xA0);//--Set SEG/Column Mapping     0xa0左右反置 0xa1正常
    }else{
        oled_write(dev,oled_cmd,0xA1);//--Set SEG/Column Mapping     0xa0左右反置 0xa1正常
    }
    if(mode&0x02){
        oled_write(dev,oled_cmd,0xC0);//Set COM/Row Scan Direction   0xc0上下反置 0xc8正常
    }else{
        oled_write(dev,oled_cmd,0xC8);//Set COM/Row Scan Direction   0xc0上下反置 0xc8正常
    }
    oled_write(dev,oled_cmd,0xDA);//--set com pins hardware configuration
    oled_write(dev,oled_cmd,0x02|((mode&0x0C)<<2));
}
/*-------------------------------------------------------
OLED设置函数。
-------------------------------------------------------*/
void oled_set_reg(oled_def * dev,u8 cmd){
    oled_write(dev,oled_cmd,cmd);
}
/*-------------------------------------------------------
OLED设置Vcomh电压函数。
-------------------------------------------------------*/
void oled_set_vcomh(oled_def * dev,u8 v){
    oled_write(dev,oled_cmd,0xDB);//--set vcomh
    oled_write(dev,oled_cmd,v);//Set VCOM Deselect Level
}
/*-------------------------------------------------------
OLED设置DC-DC电路函数。
-------------------------------------------------------*/
void oled_set_dcdc(oled_def * dev,u8 en){
    oled_write(dev,oled_cmd,0x8D);//--set Charge Pump enable/disable
    oled_write(dev,oled_cmd,(0x10|en));//--set(0x10) disable
}
/*-------------------------------------------------------
OLED设置扫频时序函数。
-------------------------------------------------------*/
void oled_set_pcp(oled_def * dev,u8 clk){
    oled_write(dev,oled_cmd,0xD9);//--set pre-charge period
    oled_write(dev,oled_cmd,clk);//Set Pre-Charge as 15 Clocks & Discharge as 1 Clock
}
/*-------------------------------------------------------
OLED设置内置RC参数函数。
-------------------------------------------------------*/
void oled_set_clk(oled_def * dev,u8 clk){
    oled_write(dev,oled_cmd,0xD5);
    oled_write(dev,oled_cmd,clk);
}
/*-------------------------------------------------------
OLED设置地址模式函数。
-------------------------------------------------------*/
void oled_set_address_mode(oled_def * dev,u8 mode){
    oled_write(dev,oled_cmd,0x20);//-Set Page Addressing Mode (0x00/0x01/0x02)
    oled_write(dev,oled_cmd,mode);//
}
/*-------------------------------------------------------
OLED设置显示区域函数。
-------------------------------------------------------*/
void oled_set_area(oled_def * dev,u8 x_start,u8 page_start,u8 x_stop,u8 page_stop){
    oled_write(dev,oled_cmd,0x21);
    oled_write(dev,oled_cmd,x_start);
    oled_write(dev,oled_cmd,x_stop);
    oled_write(dev,oled_cmd,0x22);
    oled_write(dev,oled_cmd,page_start);
    oled_write(dev,oled_cmd,page_stop);
}
/*-------------------------------------------------------
OLED全显函数。
-------------------------------------------------------*/
void oled_fill(oled_def * dev,u8 dat){//刷满SSD1306的RAM，即128*8字节
    u16 x,max;
    max=((dev->oled_w)*(dev->oled_h/8));
    if((dev->mode&OLED_SERIAL_IIC_SPI_MASK)==0){//spi
        if((dev->mode)&OLED_CS_EN_MASK){
            gpio_out(dev->cs_pin,0);
        }
        if(dev->mode&OLED_HARD_SOFT_WARE_MASK){//hard
#if (OLED_HARD_SPI_EN)
            gpio_out(dev->dc_pin,0);
            oled_set_pos(dev,dev->oled_x,0);
            gpio_out(dev->dc_pin,1);
            for(x=0;x<max;x++){
                spi_send(dat);
            }
#endif
        }else{//soft
#if (OLED_SOFT_SPI_EN)
            gpio_out(dev->dc_pin,0);
            oled_set_pos(dev,dev->oled_x,0);
            gpio_out(dev->dc_pin,1);
            for(x=0;x<max;x++){
                soft_spi_send(dat);
            }	
#endif
        }
        if((dev->mode)&OLED_CS_EN_MASK){
            gpio_out(dev->cs_pin,1);
        }
    }else{//iic
        if(dev->mode&OLED_HARD_SOFT_WARE_MASK){//hard
#if (OLED_HARD_IIC_EN)
            oled_set_pos(dev,dev->oled_x,0);
            oled_write_hard_iic(dev,oled_dat,dat,max);
#endif
        }else{//soft
#if (OLED_SOFT_IIC_EN)
            oled_set_pos(dev,dev->oled_x,0);
            oled_write_soft_iic(dev,oled_dat,dat,max);
#endif
        }
    }
}
/*-------------------------------------------------------
OLED设置窗口函数，OLED的物理面板显示的就是这部分。
-------------------------------------------------------*/
void oled_set_windows(oled_def * dev,u8 w,u8 h,u8 x,u8 y){
    if(w<dev->oled_w){
        dev->win_w=w;
    }else{
        dev->win_w=dev->oled_w;
    }
    if(h<dev->oled_h){
        dev->win_h=h;
    }else{
        dev->win_h=dev->oled_h;
    }
    dev->win_x=x;
    dev->win_y=y;
}
/*-------------------------------------------------------
OLED设置显存函数。
-------------------------------------------------------*/
void oled_set_buf(oled_def * dev,u8 w,u8 h,u8 x,u8 y,u8 xdata * buf){
    dev->buf_w=w;
    dev->buf_h=h;
    dev->buf_win_x=x;
    dev->buf_win_y=y;
    dev->buf=buf;
}
/*-------------------------------------------------------
OLED显示函数。
-------------------------------------------------------*/
void oled_windows(oled_def * dev){
    u8 y;
    u16 c=0,cmax;
    if(dev->buf_w+dev->buf_h){
        if((dev->mode&OLED_SERIAL_IIC_SPI_MASK)==0){//spi
            if((dev->mode)&OLED_CS_EN_MASK){
                gpio_out(dev->cs_pin,0);
            }
            if(dev->mode&OLED_HARD_SOFT_WARE_MASK){//hard
#if (OLED_HARD_SPI_EN)
                for(y=0;y<(dev->win_h/8);y++){
                    gpio_out(dev->dc_pin,0);
                    oled_set_pos(dev,(dev->oled_x+dev->win_x),y+(dev->win_y/8));
                    gpio_out(dev->dc_pin,1);
                    c=dev->buf_win_x+((y+dev->buf_win_y/8)*dev->buf_w);
                    cmax=c+dev->win_w;
                    for(;c<cmax;c++){
                        spi_send(dev->buf[c]);
                    }
                }
#endif
            }else{//soft
#if (OLED_SOFT_SPI_EN)
                for(y=0;y<(dev->oled_h/8);y++){
                    gpio_out(dev->dc_pin,0);
                    oled_set_pos(dev,(dev->oled_x+dev->win_x),y+(dev->win_y/8));
                    gpio_out(dev->dc_pin,1);
                    c=dev->buf_win_x+((y+dev->buf_win_y/8)*dev->buf_w);
                    cmax=c+dev->win_w;
                    for(;c<cmax;c++){
                        soft_spi_send(dev->buf[c]);
                    }
                }
#endif
            }
            if((dev->mode)&OLED_CS_EN_MASK){
                gpio_out(dev->cs_pin,1);
            }
        }
        if(dev->mode&OLED_SERIAL_IIC_SPI_MASK){//iic
            if(dev->mode&OLED_HARD_SOFT_WARE_MASK){//hard
#if (OLED_HARD_IIC_EN)
                for(y=0;y<(dev->win_h/8);y++){
                    oled_set_pos(dev,(dev->oled_x+dev->win_x),y+(dev->win_y/8));
                    c=dev->buf_win_x+((y+dev->buf_win_y/8)*dev->buf_w);
                    oled_write_hard_iic_ex(dev,oled_dat,&dev->buf[c],dev->win_w);
                }
#endif
            }else{//soft
#if (OLED_SOFT_IIC_EN)
                for(y=0;y<(dev->win_h/8);y++){
                    oled_set_pos(dev,(dev->oled_x+dev->win_x),y+(dev->win_y/8));
                    c=dev->buf_win_x+((y+dev->buf_win_y/8)*dev->buf_w);
                    oled_write_soft_iic_ex(dev,oled_dat,&dev->buf[c],dev->win_w);
                }
#endif
            }
        }
    }
}
/*-------------------------------------------------------
OLED初始化函数。
-------------------------------------------------------*/
void oled_init(oled_def * dev,u8 oled_w,u8 oled_h,u8 oled_x_offset,u8 oled_y_offset,u8 oled_mode){  
    dev->oled_w   =oled_w;
    dev->oled_h   =oled_h;
    dev->oled_x   =oled_x_offset;
    dev->oled_y   =oled_y_offset;
    dev->win_w    =0;
    dev->win_h    =0;
    dev->win_x    =0;
    dev->win_y    =0;
    dev->buf_w    =0;
    dev->buf_h    =0;
    dev->buf_win_x=0;
    dev->buf_win_y=0;
    if((dev->mode)&OLED_CS_EN_MASK){
        gpio_out(dev->cs_pin,0);
    }
    if((dev->mode&OLED_SERIAL_IIC_SPI_MASK)==0){
        gpio_out(dev->rst_pin,0);
        delay_ms(100);
        gpio_out(dev->rst_pin,1);
    }
    oled_off                (dev);                      //关屏
    //---------------------非通用配置--------------------//
    oled_set_offset_logic   (dev,oled_y_offset);        //设置引脚偏移
    oled_set_display_mode   (dev,oled_mode&0x0F);       //设置显示模式
    oled_set_com            (dev,oled_h-1);             //设置引脚数
    oled_set_area           (dev,oled_x_offset,0,oled_x_offset+(oled_w-1),(oled_h-1)/8);//设置显示区域
    //----------------------通用配置---------------------//
    oled_set_clk            (dev,OLED_SYSCLK);          //设置OLED芯片频率
    oled_set_offset_ram     (dev,OLED_OFFSET_RAM);      //设置RAM偏移
    oled_set_dcdc           (dev,OLED_DC_DC);           //设置升压泵
    oled_set_address_mode   (dev,OLED_ADRESS);          //设置地址模式
    oled_set_reg            (dev,0xAD);                 //神秘的设置，至今没在手册上找到说明。
    oled_set_reg            (dev,0x30);                 //加上之后，亮度会提高到正常水平且亮度恢复更快。
    oled_set_contrast       (dev,OLED_CONTRAST);        //设置对比度
    oled_set_pcp            (dev,OLED_PCP);             //设置充电/保持的时钟
    oled_set_vcomh          (dev,OLED_VCOMH);           //设置驱动电压
    oled_set_reg            (dev,OLED_DISPLAY_SOURCE);  //设置显示RAM
    oled_set_reg            (dev,OLED_DISPLAY_LED);     //设置显示亮灭的逻辑
    //----------------------准备运行---------------------//
    oled_on                 (dev);                      //打开屏幕
    oled_fill               (dev,0);                    //初始清屏
    oled_set_pos            (dev,0,0);                  //设置光标点
    if((dev->mode)&OLED_CS_EN_MASK){
        gpio_out(dev->cs_pin,1);
    }
} 
/*-------------------------------------------------------
OLED自动初始化函数
-------------------------------------------------------*/
void oled_auto_init(oled_def * dev,char * str){
    u16 pos;
    u8 scl=Dxx,sda=Dxx,dc=Dxx,rst=Dxx,cs=Dxx,vcc=Dxx,gnd=Dxx;
    u8 w,h,x,y,mode;
    pos=str_find(str,"vcc="); if(pos!=0xffff){vcc =str_read_pin(str,pos);gpio_mode(vcc,GPIO_PP);gpio_out(vcc,1);}
    pos=str_find(str,"vdd="); if(pos!=0xffff){vcc =str_read_pin(str,pos);gpio_mode(vcc,GPIO_PP);gpio_out(vcc,1);}
    pos=str_find(str,"gnd="); if(pos!=0xffff){gnd =str_read_pin(str,pos);gpio_mode(gnd,GPIO_PP);gpio_out(gnd,0);}
    pos=str_find(str,"w=");   if(pos!=0xffff){w   =(u8)str_read_u16(str,pos);}else{w=OLED_X_MAX;}
    pos=str_find(str,"h=");   if(pos!=0xffff){h   =(u8)str_read_u16(str,pos);}else{h=OLED_Y_MAX;}
    pos=str_find(str,"x=");   if(pos!=0xffff){x   =(u8)str_read_u16(str,pos);}else{x=OLED_OFFSET_XPIN;}
    pos=str_find(str,"y=");   if(pos!=0xffff){y   =(u8)str_read_u16(str,pos);}else{y=OLED_OFFSET_LOGIC;}
    pos=str_find(str,"mode=");if(pos!=0xffff){mode=(u8)str_read_u16(str,pos);}else{mode=OLED_DISPLAY_MODE;}
    pos=str_find(str,"scl="); if(pos!=0xffff){scl =str_read_pin(str,pos);}
    pos=str_find(str,"d0=");  if(pos!=0xffff){scl =str_read_pin(str,pos+2);}
    pos=str_find(str,"sda="); if(pos!=0xffff){sda =str_read_pin(str,pos);}
    pos=str_find(str,"d1=");  if(pos!=0xffff){sda =str_read_pin(str,pos+2);}
    pos=str_find(str,"dc=");  if(pos!=0xffff){dc  =str_read_pin(str,pos);}
    pos=str_find(str,"rst="); if(pos!=0xffff){rst =str_read_pin(str,pos);}
    pos=str_find(str,"res="); if(pos!=0xffff){rst =str_read_pin(str,pos);}
    pos=str_find(str,"cs=");  if(pos!=0xffff){cs  =str_read_pin(str,pos);}
    if(str_find(str,"soft")!=0xffff){
        if(str_find(str,"iic")!=0xffff){goto soft_iic_id;}
        if(str_find(str,"spi")!=0xffff){goto soft_spi_id;}
    }
    //uart_printf(1,"check:[scl=D%02X][sda=D%02X][rst=D%02X][dc=D%02X]\r\n",(u16)scl,(u16)sda,(u16)rst,(u16)dc);
    if((dc==Dxx)&&(rst==Dxx)){
        if((scl==0x15)&&(sda==0x14)){
#if (OLED_HARD_IIC_EN)
            oled_set_hard_iic(dev,scl,sda);
            iic_set_pin(IIC_PIN_P15_P14);
#else
            goto soft_iic_id;
#endif
        }else if((scl==0x25)&&(sda==0x24)){
#if (OLED_HARD_IIC_EN)
            oled_set_hard_iic(dev,scl,sda);
            iic_set_pin(IIC_PIN_P25_P24);
#else
            goto soft_iic_id;
#endif
        }else if((scl==0x77)&&(sda==0x76)){
#if (OLED_HARD_IIC_EN)
            oled_set_hard_iic(dev,scl,sda);
            iic_set_pin(IIC_PIN_P77_P76);
#else
            goto soft_iic_id;
#endif
        }else if((scl==0x32)&&(sda==0x33)){
#if (OLED_HARD_IIC_EN)
            oled_set_hard_iic(dev,scl,sda);
            iic_set_pin(IIC_PIN_P32_P33);
#else
            goto soft_iic_id;
#endif
        }else{
            soft_iic_id:_nop_();
#if (OLED_SOFT_IIC_EN)
            oled_set_soft_iic(dev,scl,sda);
#endif
        }
    }else{
        if((scl==0x15)&&(sda==0x13)){
#if (OLED_HARD_SPI_EN)
            oled_set_hard_spi(dev,scl,sda,dc,rst,cs);
            spi_set_pin(SPI_PIN_P12_P13_P14_P15);
#else
            goto soft_spi_id;
#endif
        }else if((scl==0x25)&&(sda==0x23)){
#if (OLED_HARD_SPI_EN)
            oled_set_hard_spi(dev,scl,sda,dc,rst,cs);
            spi_set_pin(SPI_PIN_P22_P23_P24_P25);
#else
            goto soft_spi_id;
#endif
        }else if((scl==0x77)&&(sda==0x75)){
#if (OLED_HARD_SPI_EN)
            oled_set_hard_spi(dev,scl,sda,dc,rst,cs);
            spi_set_pin(SPI_PIN_P74_P75_P76_P77);
#else
            goto soft_spi_id;
#endif
        }else if((scl==0x32)&&(sda==0x34)){
#if (OLED_HARD_SPI_EN)
            oled_set_hard_spi(dev,scl,sda,dc,rst,cs);
            spi_set_pin(SPI_PIN_P35_P34_P33_P32);
#else
            goto soft_spi_id;
#endif
        }else{
            soft_spi_id:_nop_();
#if (OLED_SOFT_SPI_EN)
			uart_printf(1,"SOFT_SPI\r\n");
            oled_set_soft_spi(dev,scl,sda,dc,rst,cs);
#endif
        }
    }
    oled_init(dev,w,h,x,y,mode);
	oled_set_windows(dev,w,h,0,0);
}
#if OLED_DISPLAY_MODE_EN
u8 code oled_display_mode_test_buf[]={
0x00,0x3E,0x41,0x41,0x41,0x3E,0x00,0x00,/*"0"*/0xFF,0xFE,0xFC,0xF8,0xF0,0xE0,0xC0,0x80,
0x00,0x00,0x02,0x7F,0x00,0x00,0x00,0x00,/*"1"*/0xFF,0xFE,0xFC,0xF8,0xF0,0xE0,0xC0,0x80,
0x00,0x62,0x51,0x49,0x46,0x00,0x00,0x00,/*"2"*/0xFF,0xFE,0xFC,0xF8,0xF0,0xE0,0xC0,0x80,
0x00,0x00,0x41,0x49,0x49,0x36,0x00,0x00,/*"3"*/0xFF,0xFE,0xFC,0xF8,0xF0,0xE0,0xC0,0x80,
0x00,0x30,0x2C,0x22,0x7F,0x20,0x00,0x00,/*"4"*/0xFF,0xFE,0xFC,0xF8,0xF0,0xE0,0xC0,0x80,
0x00,0x00,0x4F,0x49,0x49,0x31,0x00,0x00,/*"5"*/0xFF,0xFE,0xFC,0xF8,0xF0,0xE0,0xC0,0x80,
0x00,0x3C,0x46,0x45,0x45,0x39,0x00,0x00,/*"6"*/0xFF,0xFE,0xFC,0xF8,0xF0,0xE0,0xC0,0x80,
0x00,0x01,0x61,0x1D,0x03,0x00,0x00,0x00,/*"7"*/0xFF,0xFE,0xFC,0xF8,0xF0,0xE0,0xC0,0x80,
0x00,0x36,0x49,0x49,0x49,0x36,0x00,0x00,/*"8"*/0xFF,0xFE,0xFC,0xF8,0xF0,0xE0,0xC0,0x80,
0x00,0x4E,0x51,0x51,0x71,0x1E,0x00,0x00,/*"9"*/0xFF,0xFE,0xFC,0xF8,0xF0,0xE0,0xC0,0x80,
0x00,0x60,0x1C,0x13,0x17,0x38,0x40,0x00,/*"A"*/0xFF,0xFE,0xFC,0xF8,0xF0,0xE0,0xC0,0x80,
0x00,0x00,0x7F,0x49,0x49,0x37,0x00,0x00,/*"B"*/0xFF,0xFE,0xFC,0xF8,0xF0,0xE0,0xC0,0x80,
0x00,0x3C,0x62,0x41,0x41,0x41,0x00,0x00,/*"C"*/0xFF,0xFE,0xFC,0xF8,0xF0,0xE0,0xC0,0x80,
0x00,0x00,0x7F,0x41,0x41,0x63,0x1E,0x00,/*"D"*/0xFF,0xFE,0xFC,0xF8,0xF0,0xE0,0xC0,0x80,
0x00,0x00,0x7F,0x49,0x49,0x49,0x00,0x00,/*"E"*/0xFF,0xFE,0xFC,0xF8,0xF0,0xE0,0xC0,0x80,
0x00,0x00,0x7F,0x09,0x09,0x00,0x00,0x00,/*"F"*/0xFF,0xFE,0xFC,0xF8,0xF0,0xE0,0xC0,0x80,
/* (8 X 8 , Segoe UI Symbol )*/
};
u8 code x_start[]={0xFF,0x24,0x42,0x81};
/*-------------------------------------------------------
OLED显示模式测试函数。
-------------------------------------------------------*/
void oled_display_mode_test(oled_def * dev,u8 mode){
    u8 x=0,y=0;
    oled_set_display_mode(dev,mode);
    for(y=0;y<SSD1306_RAM_PAGE;y++){
        oled_set_pos(dev,x,y);
        for(x=0;x<SSD1306_RAM_X;x++){
            oled_write(dev,oled_dat,oled_display_mode_test_buf[x%16+mode*16]);
        }
    }
}
/*-------------------------------------------------------
OLED的Y轴偏移测试函数。
-------------------------------------------------------*/
void oled_display_y_test(oled_def * dev){
    u8 x=0,y=0;
    oled_set_address_mode(dev,0x02);
    for(y=0;y<((dev->oled_h)/8);y++){
        oled_set_pos(dev,x,y);
        for(x=0;x<SSD1306_RAM_X;x++){
            oled_write(dev,oled_dat,oled_display_mode_test_buf[x%8+y*16]);
        }
    }
}
/*-------------------------------------------------------
OLED的X轴偏移测试函数。
-------------------------------------------------------*/
void oled_display_x_test(oled_def * dev,u8 x_offset){
    u8 x=0,y=0;
    oled_fill(dev,0);
    for(y=0;y<((dev->oled_h)/8);y++){        //在测试阶段，直接写满8个page
        oled_set_pos(dev,x_offset,y);
        for(x=0;x<4;x++){  //在测试阶段，直接写满128像素
            oled_write(dev,oled_dat,x_start[x]);
        }
        for(x=0;x<6;x++){  //在测试阶段，直接写满128像素
            oled_write(dev,oled_dat,oled_display_mode_test_buf[(x_offset/100)*16+x]);
        }
        for(x=0;x<6;x++){  //在测试阶段，直接写满128像素
            oled_write(dev,oled_dat,oled_display_mode_test_buf[(x_offset%100/10)*16+x]);
        }
        for(x=0;x<6;x++){  //在测试阶段，直接写满128像素
            oled_write(dev,oled_dat,oled_display_mode_test_buf[(x_offset%10)*16+x]);
        }
    }
}
#endif
#if (OLED_PRINTF_EN)
unsigned char code F6x8[]={
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,// sp
0x00, 0x00, 0x00, 0x2f, 0x00, 0x00,// !
0x00, 0x00, 0x07, 0x00, 0x07, 0x00,// "
0x00, 0x14, 0x7f, 0x14, 0x7f, 0x14,// #
0x00, 0x24, 0x2a, 0x7f, 0x2a, 0x12,// $
0x00, 0x23, 0x13, 0x08, 0x64, 0x62,//0x00, 0x62, 0x64, 0x08, 0x13, 0x23,// %
0x00, 0x36, 0x49, 0x55, 0x22, 0x50,// &
0x00, 0x00, 0x05, 0x03, 0x00, 0x00,// '
0x00, 0x00, 0x1c, 0x22, 0x41, 0x00,// (
0x00, 0x00, 0x41, 0x22, 0x1c, 0x00,// )
0x00, 0x14, 0x08, 0x3E, 0x08, 0x14,// *
0x00, 0x08, 0x08, 0x3E, 0x08, 0x08,// +
0x00, 0x00, 0x00, 0xA0, 0x60, 0x00,// ,
0x00, 0x08, 0x08, 0x08, 0x08, 0x08,// -
0x00, 0x00, 0x60, 0x60, 0x00, 0x00,// .
0x00, 0x20, 0x10, 0x08, 0x04, 0x02,// /
0x00, 0x3E, 0x51, 0x49, 0x45, 0x3E,// 0
0x00, 0x00, 0x42, 0x7F, 0x40, 0x00,// 1
0x00, 0x42, 0x61, 0x51, 0x49, 0x46,// 2
0x00, 0x21, 0x41, 0x45, 0x4B, 0x31,// 3
0x00, 0x18, 0x14, 0x12, 0x7F, 0x10,// 4
0x00, 0x27, 0x45, 0x45, 0x45, 0x39,// 5
0x00, 0x3C, 0x4A, 0x49, 0x49, 0x30,// 6
0x00, 0x01, 0x71, 0x09, 0x05, 0x03,// 7
0x00, 0x36, 0x49, 0x49, 0x49, 0x36,// 8
0x00, 0x06, 0x49, 0x49, 0x29, 0x1E,// 9
0x00, 0x00, 0x36, 0x36, 0x00, 0x00,// :
0x00, 0x00, 0x56, 0x36, 0x00, 0x00,// ;
0x00, 0x08, 0x14, 0x22, 0x41, 0x00,// <
0x00, 0x14, 0x14, 0x14, 0x14, 0x14,// =
0x00, 0x00, 0x41, 0x22, 0x14, 0x08,// >
0x00, 0x02, 0x01, 0x51, 0x09, 0x06,// ?
0x00, 0x32, 0x49, 0x59, 0x51, 0x3E,// @
0x00, 0x7C, 0x12, 0x11, 0x12, 0x7C,// A
0x00, 0x7F, 0x49, 0x49, 0x49, 0x36,// B
0x00, 0x3E, 0x41, 0x41, 0x41, 0x22,// C
0x00, 0x7F, 0x41, 0x41, 0x22, 0x1C,// D
0x00, 0x7F, 0x49, 0x49, 0x49, 0x41,// E
0x00, 0x7F, 0x09, 0x09, 0x09, 0x01,// F
0x00, 0x3E, 0x41, 0x49, 0x49, 0x7A,// G
0x00, 0x7F, 0x08, 0x08, 0x08, 0x7F,// H
0x00, 0x00, 0x41, 0x7F, 0x41, 0x00,// I
0x00, 0x20, 0x40, 0x41, 0x3F, 0x01,// J
0x00, 0x7F, 0x08, 0x14, 0x22, 0x41,// K
0x00, 0x7F, 0x40, 0x40, 0x40, 0x40,// L
0x00, 0x7F, 0x02, 0x0C, 0x02, 0x7F,// M
0x00, 0x7F, 0x04, 0x08, 0x10, 0x7F,// N
0x00, 0x3E, 0x41, 0x41, 0x41, 0x3E,// O
0x00, 0x7F, 0x09, 0x09, 0x09, 0x06,// P
0x00, 0x3E, 0x41, 0x51, 0x21, 0x5E,// Q
0x00, 0x7F, 0x09, 0x19, 0x29, 0x46,// R
0x00, 0x46, 0x49, 0x49, 0x49, 0x31,// S
0x00, 0x01, 0x01, 0x7F, 0x01, 0x01,// T
0x00, 0x3F, 0x40, 0x40, 0x40, 0x3F,// U
0x00, 0x1F, 0x20, 0x40, 0x20, 0x1F,// V
0x00, 0x3F, 0x40, 0x38, 0x40, 0x3F,// W
0x00, 0x63, 0x14, 0x08, 0x14, 0x63,// X
0x00, 0x07, 0x08, 0x70, 0x08, 0x07,// Y
0x00, 0x61, 0x51, 0x49, 0x45, 0x43,// Z
0x00, 0x00, 0x7F, 0x41, 0x41, 0x00,// [
0x00, 0x55, 0x2A, 0x55, 0x2A, 0x55,// 55
0x00, 0x00, 0x41, 0x41, 0x7F, 0x00,// ]
0x00, 0x04, 0x02, 0x01, 0x02, 0x04,// ^
0x00, 0x40, 0x40, 0x40, 0x40, 0x40,// _
0x00, 0x00, 0x01, 0x02, 0x04, 0x00,// '
0x00, 0x20, 0x54, 0x54, 0x54, 0x78,// a
0x00, 0x7F, 0x48, 0x44, 0x44, 0x38,// b
0x00, 0x38, 0x44, 0x44, 0x44, 0x20,// c
0x00, 0x38, 0x44, 0x44, 0x48, 0x7F,// d
0x00, 0x38, 0x54, 0x54, 0x54, 0x18,// e
0x00, 0x08, 0x7E, 0x09, 0x01, 0x02,// f
0x00, 0x18, 0xA4, 0xA4, 0xA4, 0x7C,// g
0x00, 0x7F, 0x08, 0x04, 0x04, 0x78,// h
0x00, 0x00, 0x44, 0x7D, 0x40, 0x00,// i
0x00, 0x40, 0x80, 0x84, 0x7D, 0x00,// j
0x00, 0x7F, 0x10, 0x28, 0x44, 0x00,// k
0x00, 0x00, 0x41, 0x7F, 0x40, 0x00,// l
0x00, 0x7C, 0x04, 0x18, 0x04, 0x78,// m
0x00, 0x7C, 0x08, 0x04, 0x04, 0x78,// n
0x00, 0x38, 0x44, 0x44, 0x44, 0x38,// o
0x00, 0xFC, 0x24, 0x24, 0x24, 0x18,// p
0x00, 0x18, 0x24, 0x24, 0x18, 0xFC,// q
0x00, 0x7C, 0x08, 0x04, 0x04, 0x08,// r
0x00, 0x48, 0x54, 0x54, 0x54, 0x20,// s
0x00, 0x04, 0x3F, 0x44, 0x40, 0x20,// t
0x00, 0x3C, 0x40, 0x40, 0x20, 0x7C,// u
0x00, 0x1C, 0x20, 0x40, 0x20, 0x1C,// v
0x00, 0x3C, 0x40, 0x30, 0x40, 0x3C,// w
0x00, 0x44, 0x28, 0x10, 0x28, 0x44,// x
0x00, 0x1C, 0xA0, 0xA0, 0xA0, 0x7C,// y
0x00, 0x44, 0x64, 0x54, 0x4C, 0x44,// z
0x14, 0x14, 0x14, 0x14, 0x14, 0x14,// horiz lines
};
#include "stdio.h"
/*-------------------------------------------------------
显示一个字符函数，用于裸屏显示。
-------------------------------------------------------*/
void oled_char(oled_def * dev,u8 x,u8 y,char ch){
    u8 i,c;
    c=ch-' ';
    oled_set_pos(dev,dev->oled_x+x,y);
    for(i=0;i<6;i++){
        oled_write(dev,oled_dat,F6x8[c*6+i]);
    }
}
/*-------------------------------------------------------
格式化显示字符串函数，用于裸屏显示。
-------------------------------------------------------*/
#if (ECBM_PRINTF_EN)
void oled_printf(oled_def * dev,u8 x,u8 y,char * str,...){
    char xdata buf[32];
    u8 len,i,x0,y0;
    va_list vp;
    va_start(vp, str);
    len=vsprintf(buf,str,vp);
    va_end(vp);
    x0=x;
    y0=y;
    for(i=0;i<len;i++){
        if(buf[i]=='\r'){x0=x;continue;}
        if(buf[i]=='\n'){y0++;continue;}
        if(x0>(dev->oled_w-6)){
            x0=x;
            y0++;
        }
        if(y0>((dev->oled_h-1)/8)){
            break;
        }
        oled_char(dev,x0,y0,buf[i]);
        x0+=6;
    }
}
#endif 
#endif 