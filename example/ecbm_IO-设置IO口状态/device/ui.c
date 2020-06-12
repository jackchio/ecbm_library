#include "ui.h"
/*--------------------------------------��������-----------------------------------*/
u8 xdata ui_system_buff[UI_SYSTEM_BUFF_SIZE];//ͨ�û��滺�档
u8 code * ui_font_english;
u8 code * ui_font_chinese;
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
UI�������������
-------------------------------------------------------*/
void ui_cls(void){
	u16 i;								//��ʱ������
	for(i=0;i<UI_SYSTEM_BUFF_SIZE;i++){ //������Ϣ����ѭ������β��
		ui_system_buff[i]=0x00;			//���㡣
	}
}
/*-------------------------------------------------------
UI��д�㺯����
-------------------------------------------------------*/
void ui_write_point(u8 x,u8 y,u8 state){
	u8 y0,z;
	if((x<UI_WIDTH)&&(y<UI_HEIGHT)){	//��Ч��Χ�жϡ�
		y0=y%8;							//ȡ��λ�á�
		z=0x01<<y0;						//�ѵ�λ�÷�������ݡ�
		y0=y/8;							//ȡҳ��ַ��
		switch(state){					//��ȡ���״̬��
			case point_off:{			//�رյ��ʱ��
				z=~z;					//�����ݷ���
				ui_system_buff[x+UI_WIDTH*y0]&=z;//����������Ѷ�Ӧλ���㡣
			}break;
			case point_on :{			//�򿪵��ʱ��
				ui_system_buff[x+UI_WIDTH*y0]|=z;//��������Ѷ�Ӧλ��һ��
			}break;
			case point_tog:{			//��ת���ʱ��
				ui_system_buff[x+UI_WIDTH*y0]^=z;//���������Ѷ�Ӧλȡ����
			}break;
		}		
	}
}
/*-------------------------------------------------------
UI�Ķ��㺯����
-------------------------------------------------------*/
u8 ui_read_point(u8 x,u8 y){
	u8 y0,z;
	if((x<UI_WIDTH)&&(y<UI_HEIGHT)){		//��Ч��Χ�жϡ�
		y0=y%8;								//ȡ��λ�á�
		z=0x01<<y0;							//�ѵ�λ�÷�������ݡ�
		y0=y/8;								//ȡҳ��ַ��
		if(ui_system_buff[x+UI_WIDTH*y0]&z){//��������ȡ��Ԫ���ݣ��͵���������֮���֪�����״̬��
			return 1;						//��һ��������1~255�����1��
		}									//�����else return 0�������return 0�ϲ����Եýṹ����Щ��
	}
	return 0;								//���ڴ�����ֵ�ĺ�������Ҫ��һ��return�����Ծͺ�����ĺϲ��ˡ�
}
/*-------------------------------------------------------
UI��д�ֽں�����
-------------------------------------------------------*/
void ui_write_byte(u8 x,u8 y,u8 dat,u8 mode){
	u8 dat_back,out_mask,i,data_point=0x01,y_offset;
	if((mode&0x04)==0){			//���û��ʹ��������ƣ�
		out_mask=0xff;			//��ô��ȫ�����
	}else{						//���ʹ����������ƣ��Ϳ���ʹ�����������ݡ�
		if((mode&0x01)==0){		//���ʹ����ֻ���0��
			out_mask=dat^0xff;	//ͨ����ת����λ��������0����maskλ��
		}else{					//���ʹ����ֻ���1��
			out_mask=dat;		//��ôԭ�������ݿ���ֱ������mask��
		}
	}
	if((mode&0x02)==0){			//���û��ʹ�ܷ�תλ��
		dat_back=dat;			//���ݾͰ�ԭ�������
	}else{						//���ʹ���˷�תλ��
		dat_back=dat^0xff;		//������ȫ��ȡ����
	}
	y_offset=y;					//��y��ƫ�Ʊ��浽��ʱ������
	for(i=0;i<8;i++){			//һ���ֽ���8λ��
		if(out_mask&data_point){//�����������λ����������ĵط�������ʾ��
			if(dat_back&data_point){//�������ݣ�������1�Ļ���
				ui_write_point(x,y_offset,1);//�͵������ء�
			}else{					//������0�Ļ���
				ui_write_point(x,y_offset,0);//��Ϩ�����ء�
			}
		}
		y_offset++;				//д��һλ�ã���Ҫ����һ��λ�á�
		data_point=data_point<<1;//д��һλ���ݾ�Ҫ����һλ���ݣ������Ǵӵ�λ����λ��
	}
}
/*-------------------------------------------------------
UI����ʾ�ַ�����(Ӣ��)��
-------------------------------------------------------*/
void ui_char_e(u8 x,u8 y,u8 ch,u8 mode){
	u8 ht,ht_i,w_i,y0,w,h,char_point;
	u16 addr;
	w=ui_font_english[0];//��ȡ��ģ�Ŀ�ȡ�
	h=ui_font_english[1];//��ȡ��ģ�ĸ߶ȡ�
	ht=(h-1)/8;  //��ȡһ������ռ��ҳ������//1-8:0      9-16:1     17-24:2
	char_point=ch-' ';			//��������ʾ����
	for(ht_i=0;ht_i<=ht;ht_i++){//һ����ռ����ҳ���ѭ�����ٴΡ�
		y0=y+ht_i*8;			//��Ϊͨ������һ��8�����أ�������һ��Ҫ����8��
		addr=char_point*w*(ht+1)/*�����������Ŀ���ַ�֮ǰ�����ݵģ�char_point�ǵ�ǰ�ַ���w*(ht+1)������һ����ģ��ռ���ֽ�����*/\
			+ht_i*w/*������ڶ����ַ��ģ�����wi�ķ�Χ������ַ��Ŀ�ȣ����Ե���ģ��һ�������������ʱ����Ҫ��������ڶ�����...��*/\
			+2;/*ǰ�����ַ�������ַ��Ŀ�����ݡ�*/
		for(w_i=0;w_i<w;w_i++){	//x��ƫ��������Ǵ�0����ȡ�
			ui_write_byte(x+w_i,y0,ui_font_english[w_i/*����ǰ���X��ƫ�Ƶ�����ƫ�ƣ���forѭ���Ķ����ҹ���*/\
			+addr],mode);
			
		}
	}
}
/*-------------------------------------------------------
UI����ʾ�ַ�����(����)��
-------------------------------------------------------*/
void ui_char_c(u8 x,u8 y,u8 ch1,u8 ch2,u8 mode){
	u8 ht,ht_i,w_i,y0,w,h,max,i;
	u16 addr;
	w=ui_font_chinese[0];//��ȡ��ģ�Ŀ�ȡ�
	h=ui_font_chinese[1];//��ȡ��ģ�ĸ߶ȡ�
	max=ui_font_chinese[2];
	ht=(h-1)/8;  //��ȡһ������ռ��ҳ������//1-8:0      9-16:1     17-24:2
	for(i=1;i<=max;i++){
		if((ui_font_chinese[i*26]==ch1)&&(ui_font_chinese[i*26+1]==ch2)){
			addr=i*26+2;
			for(ht_i=0;ht_i<=ht;ht_i++){//һ����ռ����ҳ���ѭ�����ٴΡ�
				y0=y+ht_i*8;			//��Ϊͨ������һ��8�����أ�������һ��Ҫ����8��
				for(w_i=0;w_i<w;w_i++){	//x��ƫ��������Ǵ�0����ȡ�
					ui_write_byte(x+w_i,y0,ui_font_chinese[addr++],mode);
				}
			}
			break;
		}
	}
	if(i>max){
		addr=2;
		for(ht_i=0;ht_i<=ht;ht_i++){//һ����ռ����ҳ���ѭ�����ٴΡ�
			y0=y+ht_i*8;			//��Ϊͨ������һ��8�����أ�������һ��Ҫ����8��
			for(w_i=0;w_i<w;w_i++){	//x��ƫ��������Ǵ�0����ȡ�
				ui_write_byte(x+w_i,y0,ui_font_chinese[addr++],mode);
			}
		}
	}
}
/*-------------------------------------------------------
UI��printf������
-------------------------------------------------------*/
void ui_printf(u8 x,u8 y,u8 mode,const char * str,...){
	u8 xi,yi,w,h,c;
	u16 len,j;
	u8 buf[UI_PRINTF_BUFF_SIZE];	//printf��Ҫ�Ļ��档
	va_list vp;						//���������ַ��
    va_start(vp, str);				//��ʼ��������ַ��
    len=vsprintf(buf,str,vp);		//��ʽ���ַ�����
    va_end(vp);						//����������
	xi=x;		//�Ӳ����õ���ʼX��λ�á�
	yi=y;		//�Ӳ����õ���ʼY��λ�á�
	for(j=0;j<len;j++){//��ʾ���е��ַ���
		if(buf[j]<0x80){
			c=1;
			w=ui_font_english[0];//��ȡ��ģ�Ŀ�ȡ�
			h=ui_font_english[1];//��ȡ��ģ�ĸ߶ȡ�
			if(((xi+w)>UI_WIDTH)||(buf[j]=='\n')){	//���ַ�������������������з�ʱ��
				xi=x;								//����X�����굽��ʼλ�á�
				yi+=h;								//Y���ƶ�һ����ģ�ĸ߶ȡ�
				if(buf[j]=='\n'){					//������������з������еģ�
					j++;							//��ôҪ�ӵ���һλ�Ա������ui_char�������ʾ��
					if(j==len)break;				//�����һλ�ͽ����ˣ�������ѭ����
					}
			}
			ui_char_e(xi,yi,buf[j],mode);			//��ʾ�ַ���
			xi+=w;									//������ƶ�һ���ַ��Ŀ�ȣ�������һ���ַ���ʾ��
		}else{
			if(c)xi++;
			c=0;
			w=ui_font_chinese[0];//��ȡ��ģ�Ŀ�ȡ�
			h=ui_font_chinese[1];//��ȡ��ģ�ĸ߶ȡ�
			if((xi+w)>UI_WIDTH){
				xi=x;								//����X�����굽��ʼλ�á�
				yi+=h;								//Y���ƶ�һ����ģ�ĸ߶ȡ�
			}
			ui_char_c(xi,yi,buf[j],buf[j+1],mode);	//��ʾ�ַ���
			j++;
			xi+=w;									//������ƶ�һ���ַ��Ŀ�ȣ�������һ���ַ���ʾ��
		}
	}
}
/*-------------------------------------------------------
UI�Ĳ���������ʾ������
-------------------------------------------------------*/
void ui_error(u8 x,u8 y){
	u8 i;
	u8 code err_buff[]={0x18,0x24,0x42,0x81,0xAD,0x81,0x42,0x24,0x18,0x00,0xBE,0xAA,0xAA,0x80,0xB8,0x88,0x80,0xB8,0x88,0x80};
	for(i=0;i<20;i++){
		ui_write_byte(x+i,y,err_buff[i],0);//��ָ��λ����ʾerrͼ�ꡣ
	}
}
/*-------------------------------------------------------
UI�������κ�����
-------------------------------------------------------*/
 void ui_fill_frame(u8 x1,u8 y1,u8 x2,u8 y2,u8 state){
	u8 xi,yi,up,down,y1_page,y2_page,ud;
	if(x1>x2){			//�ж�X�������Ƿ���Ϲ��
		ui_error(x1,y1);//�����Ͼ���ʾerrͼ�ꡣ
		return;			//ͬʱ�˳�������
	}
	if(y1>y2){			//�ж�Y�������Ƿ���Ϲ��
		ui_error(x1,y1);//�����Ͼ���ʾerrͼ�ꡣ
		return;			//ͬʱ�˳�������
	}
	up=0xff<<(y1%8);	//���㶥���Ǽ��ŵ����ݡ�
	down=0xff>>(7-y2%8);//����ײ��Ǽ��ŵ����ݡ�
	ud=up&down;			//��������͵ײ���ͬһ��ҳ�棬��ôȡ�м乫���ġ�
	y1_page=y1/8;		//��ʼҳ�档
	y2_page=y2/8;		//��ֹ���档
	if(y1_page==y2_page){//��������͵ײ���ͬһ��ҳ�棬
		switch(state){	//����״̬�����������
			case 0:{	//�������Ϩ��㣬
				ud=~ud;	//��Դ����ȡ����
				for(xi=x1;xi<=x2;xi++){//�Ӿ�����ߵ��ұߣ�
					ui_system_buff[xi+UI_WIDTH*y1_page]&=ud;//����д��0��
				}
			}break;
			case 1:{	//�����������㣬
				for(xi=x1;xi<=x2;xi++){//�Ӿ�����ߵ��ұߣ�
					ui_system_buff[xi+UI_WIDTH*y1_page]|=ud;//����д��1��
				}
			}break;
			case 2:{	//�������ȡ���㣬
				for(xi=x1;xi<=x2;xi++){//�Ӿ�����ߵ��ұߣ�
					ui_system_buff[xi+UI_WIDTH*y1_page]^=ud;//����ȡ����
				}
			}break;
		}
	}else{//��������͵ײ�����ͬһ��ҳ�棬���Ƕ��ҳ�档
		switch(state){	//����״̬�����������
			case 0:{	//�������Ϩ��㣬
				up=~up;	//��Դ����ȡ����
				down=~down;//��Դ����ȡ����
				for(xi=x1;xi<=x2;xi++){//���붥���͵ײ������ݣ������ﶼ�����㡣
					ui_system_buff[xi+UI_WIDTH*y1_page]&=up;
					ui_system_buff[xi+UI_WIDTH*y2_page]&=down;
				}
				if((y2_page-y1_page)>1){//�������͵ײ�֮�仹�����ݵ�ʱ��
					for(yi=y1_page+1;yi<y2_page;yi++){
						for(xi=x1;xi<=x2;xi++){
							ui_system_buff[xi+UI_WIDTH*yi]=0x00;//��֮��������ж����㡣
						}
					}
				}
			}break;
			case 1:{//����Ĳ���������Ĳ�ֻ࣬����Ϊ�����ſ��������ӣ�ʵ�ʾ�����һ��
				for(xi=x1;xi<=x2;xi++){
					ui_system_buff[xi+UI_WIDTH*y1_page]|=up;
					ui_system_buff[xi+UI_WIDTH*y2_page]|=down;
				}
				if((y2_page-y1_page)>1){
					for(yi=y1_page+1;yi<y2_page;yi++){
						for(xi=x1;xi<=x2;xi++){
							ui_system_buff[xi+UI_WIDTH*yi]=0xff;
						}
					}
				}
			}break;
			case 2:{//����Ĳ���������Ĳ�ֻ࣬����Ϊ�����ſ��������ӣ�ʵ�ʾ���ȡ����
				for(xi=x1;xi<=x2;xi++){
					ui_system_buff[xi+UI_WIDTH*y1_page]^=up;
					ui_system_buff[xi+UI_WIDTH*y2_page]^=down;
				}
				if((y2_page-y1_page)>1){
					for(yi=y1_page+1;yi<y2_page;yi++){
						for(xi=x1;xi<=x2;xi++){
							ui_system_buff[xi+UI_WIDTH*yi]^=0xff;
						}
					}
				}
			}break;
		}				
	}
//	�ɳ������Ա�
//	for(xi=x1;xi<=x2;xi++){
//		for(yi=y1;yi<=y2;yi++){
//			ui_write_point(xi,yi,state);
//		}
//	}	

}
/*-------------------------------------------------------
UI�Ļ��ߺ�����
-------------------------------------------------------*/
void ui_draw_line(u8 x1,u8 y1,u8 x2,u8 y2,u8 state){
	u16 t; 
	s16 xerr=0,yerr=0,delta_x,delta_y,distance; 
	s16 incx,incy,uRow,uCol; 
	delta_x=x2-x1; 
	delta_y=y2-y1; 
	uRow=x1; 
	uCol=y1; 
	if(delta_x>0)incx=1; 
	else if(delta_x==0)incx=0;
	else {incx=-1;delta_x=-delta_x;} 
	if(delta_y>0)incy=1; 
	else if(delta_y==0)incy=0;
	else{incy=-1;delta_y=-delta_y;} 
	if( delta_x>delta_y)distance=delta_x; 
	else distance=delta_y; 
	for(t=0;t<=distance+1;t++ )
	{  
		ui_write_point(uRow,uCol,state);
		xerr+=delta_x ; 
		yerr+=delta_y ; 
		if(xerr>distance) 
		{ 
			xerr-=distance; 
			uRow+=incx; 
		} 
		if(yerr>distance) 
		{ 
			yerr-=distance; 
			uCol+=incy; 
		} 
	}  
}
/*-------------------------------------------------------
UI�Ļ����ߺ�����
-------------------------------------------------------*/
void ui_draw_wline(u8 x1,u8 x2,u8 y,u8 state){
	u8 x,yi,z;
	if(x1>x2){			//�ж�X�������Ƿ���Ϲ��
		ui_error(x1,y);	//�����Ͼ���ʾerrͼ�ꡣ
		return;			//ͬʱ�˳�������
	}
	z=0x01<<(y%8);
	yi=y/8;
	switch(state){
		case 0:{
			z=~z;
			for(x=x1;x<=x2;x++){
				ui_system_buff[x+UI_WIDTH*yi]&=z;	
			}	
		}break;
		case 1:{
			for(x=x1;x<=x2;x++){
				ui_system_buff[x+UI_WIDTH*yi]|=z;	
			}
		}break;
		case 2:{
			for(x=x1;x<=x2;x++){
				ui_system_buff[x+UI_WIDTH*yi]^=z;	
			}
		}break;
	}
//�ɳ���
//	for(x=x1;x<=x2;x++){
//		ui_write_point(x,y,state);		
//	}	
}
/*-------------------------------------------------------
UI�Ļ����ߺ�����
-------------------------------------------------------*/
void ui_draw_hline(u8 x,u8 y1,u8 y2,u8 state){
	u8 yi,up,down,y1_page,y2_page,ud;
	if(y1>y2){			//�ж�Y�������Ƿ���Ϲ��
		ui_error(x,y1);//�����Ͼ���ʾerrͼ�ꡣ
		return;			//ͬʱ�˳�������
	}
	up=0xff<<(y1%8);	//���㶥���Ǽ��ŵ����ݡ�
	down=0xff>>(7-y2%8);//����ײ��Ǽ��ŵ����ݡ�
	ud=up&down;			//��������͵ײ���ͬһ��ҳ�棬��ôȡ�м乫���ġ�
	y1_page=y1/8;		//��ʼҳ�档
	y2_page=y2/8;		//��ֹ���档
	if(y1_page==y2_page){//��������͵ײ���ͬһ��ҳ�棬
		switch(state){	//����״̬�����������
			case 0:{	//�������Ϩ��㣬
				ud=~ud;	//��Դ����ȡ����
				ui_system_buff[x+UI_WIDTH*y1_page]&=ud;//����д��0��
			}break;
			case 1:{	//�����������㣬
				ui_system_buff[x+UI_WIDTH*y1_page]|=ud;//����д��1��
			}break;
			case 2:{	//�������ȡ���㣬
				ui_system_buff[x+UI_WIDTH*y1_page]^=ud;//����ȡ����
			}break;
		}
	}else{//��������͵ײ�����ͬһ��ҳ�棬���Ƕ��ҳ�档
		switch(state){	//����״̬�����������
			case 0:{	//�������Ϩ��㣬
				up=~up;	//��Դ����ȡ����
				down=~down;//��Դ����ȡ����
				ui_system_buff[x+UI_WIDTH*y1_page]&=up;//���붥���͵ײ������ݣ������ﶼ�����㡣
				ui_system_buff[x+UI_WIDTH*y2_page]&=down;
				if((y2_page-y1_page)>1){//�������͵ײ�֮�仹�����ݵ�ʱ��
					for(yi=y1_page+1;yi<y2_page;yi++){
						ui_system_buff[x+UI_WIDTH*yi]=0x00;//��֮��������ж����㡣
					}
				}
			}break;
			case 1:{//����Ĳ���������Ĳ�ֻ࣬����Ϊ�����ſ��������ӣ�ʵ�ʾ�����һ��
				ui_system_buff[x+UI_WIDTH*y1_page]|=up;
				ui_system_buff[x+UI_WIDTH*y2_page]|=down;
				if((y2_page-y1_page)>1){
					for(yi=y1_page+1;yi<y2_page;yi++){
						ui_system_buff[x+UI_WIDTH*yi]=0xff;
					}
				}
			}break;
			case 2:{//����Ĳ���������Ĳ�ֻ࣬����Ϊ�����ſ��������ӣ�ʵ�ʾ���ȡ����
				ui_system_buff[x+UI_WIDTH*y1_page]^=up;
				ui_system_buff[x+UI_WIDTH*y2_page]^=down;
				if((y2_page-y1_page)>1){
					for(yi=y1_page+1;yi<y2_page;yi++){
						ui_system_buff[x+UI_WIDTH*yi]^=0xff;
					}
				}
			}break;
		}				
	}
//	ԭ�������ڶԱȡ�
//	for(yi=y1;yi<=y2;yi++){
//		ui_write_point(x,yi,state);		
//	}
}
/*-------------------------------------------------------
UI�Ļ����κ�����
-------------------------------------------------------*/
void ui_draw_frame(u8 x1,u8 y1,u8 x2,u8 y2,u8 state){
	if(x1>x2){			//�ж�X�������Ƿ���Ϲ��
		ui_error(x1,y1);//�����Ͼ���ʾerrͼ�ꡣ
		return;			//ͬʱ�˳�������
	}
	if(y1>y2){			//�ж�Y�������Ƿ���Ϲ��
		ui_error(x1,y1);//�����Ͼ���ʾerrͼ�ꡣ
		return;			//ͬʱ�˳�������
	}
	ui_draw_wline(x1,x2,y1,state);//���ϱߺ��ߡ�
	ui_draw_wline(x1,x2,y2,state);//���±ߺ��ߡ�
	ui_draw_hline(x1,y1,y2,state);//��������ߡ�
	ui_draw_hline(x2,y1,y2,state);//��������ߡ�
}
/*-------------------------------------------------------
UI�Ļ�Բ������
-------------------------------------------------------*/
void ui_draw_circle(u8 x0,u8 y0,u8 r,u8 opt,u8 state){
	s16 x,y;
	s16 di;
	x=0;
	y=r;	  
	di=3-(r<<1); 
	while(x<=y){            
		if((opt==1)||(opt==5)){
			ui_write_point(x0-x,y0-y,state);	//����
			ui_write_point(x0-y,y0-x,state);    //����
		}
		if((opt==2)||(opt==5)){
			ui_write_point(x0+x,y0-y,state);    //���� 
			ui_write_point(x0+y,y0-x,state);    //���� 
		}
		if((opt==3)||(opt==5)){
			ui_write_point(x0+x,y0+y,state);    //���� 
			ui_write_point(x0+y,y0+x,state);    //����
		}
		if((opt==4)||(opt==5)){
			ui_write_point(x0-y,y0+x,state);    //����
			ui_write_point(x0-x,y0+y,state);    //����   
		}
		x++;
		if(di<0){
			di +=(x<<2)+6;	  
		}else{
			di+=10+((x-y)<<2);   
			y--;
		} 
	}
}
/*-------------------------------------------------------
UI�����Բ������
-------------------------------------------------------*/
void ui_fill_circle(u8 x0,u8 y0,u8 r,u8 opt,u8 state){
	s16 x,y,i;
	s16 di;
	x=0;
	y=r;	  
	di=3-(r<<1); 
	while(x<=y){            
		for(i=x;i<=y;i++){
			if((opt==1)||(opt==5)){
				ui_write_point(x0-x,y0-i,state);	//����
				ui_write_point(x0-i,y0-x,state);	//����
			}
			if((opt==2)||(opt==5)){
				ui_write_point(x0+x,y0-i,state);    //���� 
				ui_write_point(x0+i,y0-x,state);    //���� 
			}
			if((opt==3)||(opt==5)){
				ui_write_point(x0+x,y0+i,state);    //���� 
				ui_write_point(x0+i,y0+x,state);    //����
			}
			if((opt==4)||(opt==5)){
				ui_write_point(x0-i,y0+x,state);    //����
				ui_write_point(x0-x,y0+i,state);    //����   
			}
		}
		x++;
		if(di<0){
			di +=(x<<2)+6;  
		}else{
			di+=10+((x-y)<<2);     
			y--;
		} 
	}
}
/*-------------------------------------------------------
UI�����Բ�Ǿ��κ�����
-------------------------------------------------------*/
void ui_fill_roundframe(u8 x1,u8 y1,u8 x2,u8 y2,u8 r,u8 state){
	if((x2-x1)<(2*r)){	//���εĿ�һ��Ҫ���ڵ�������Բ�ǰ뾶��
		ui_error(x1,y1);//��Ȼ�ͱ���
		return;			//ͬʱ�˳�������
	}
	if((y2-y1)<(2*r)){	//���εĸߣ�Ҳһ��Ҫ���ڵ�������Բ�ǰ뾶��
		ui_error(x1,y1);//��Ȼ�ͱ���
		return;			//ͬʱ�˳�������
	}
	ui_fill_circle(x1+r,y1+r,r,1,state);//�������Բ�ǡ�
	ui_fill_circle(x2-r,y1+r,r,2,state);//�������Բ�ǡ�
	ui_fill_circle(x2-r,y2-r,r,3,state);//�������Բ�ǡ�
	ui_fill_circle(x1+r,y2-r,r,4,state);//�������Բ�ǡ�
	
	ui_fill_frame(x1+r,y1,  x2-r,y1+r,state);//����Ϸ����Ρ�
	ui_fill_frame(x1,  y1+r,x2,  y2-r,state);//����м���Ρ�
	ui_fill_frame(x1+r,y2-r,x2-r,y2,  state);//����·����Ρ�
}
/*-------------------------------------------------------
UI�Ļ�Բ�Ǿ��κ�����
-------------------------------------------------------*/
void ui_draw_roundframe(u8 x1,u8 y1,u8 x2,u8 y2,u8 r,u8 state){
	if((x2-x1)<(2*r)){	//���εĿ�һ��Ҫ���ڵ�������Բ�ǰ뾶��
		ui_error(x1,y1);//��Ȼ�ͱ���
		return;			//ͬʱ�˳�������
	}
	if((y2-y1)<(2*r)){	//���εĸߣ�Ҳһ��Ҫ���ڵ�������Բ�ǰ뾶��
		ui_error(x1,y1);//��Ȼ�ͱ���
		return;			//ͬʱ�˳�������
	}
	ui_draw_circle(x1+r,y1+r,r,1,state);//������Բ�ǡ�
	ui_draw_circle(x2-r,y1+r,r,2,state);//������Բ�ǡ�
	ui_draw_circle(x2-r,y2-r,r,3,state);//������Բ�ǡ�
	ui_draw_circle(x1+r,y2-r,r,4,state);//������Բ�ǡ�
	
	ui_draw_wline(x1+r,x2-r,y1,state);//���Ϻ��ߡ�
	ui_draw_wline(x1+r,x2-r,y2,state);//���º��ߡ�
	ui_draw_hline(x1,y1+r,y2-r,state);//�������ߡ�
	ui_draw_hline(x2,y1+r,y2-r,state);//�������ߡ�
}
/*-------------------------------------------------------
UI�������������
-------------------------------------------------------*/
void ui_fill_mesh(u8 x1,u8 y1,u8 x2,u8 y2,u8 mode){
	u8 x,y,m;
	if(x1>x2){			//�ж�X�������Ƿ���Ϲ��
		ui_error(x1,y1);//�����Ͼ���ʾerrͼ�ꡣ
		return;			//ͬʱ�˳�������
	}if(y1>y2){			//�ж�Y�������Ƿ���Ϲ��
		ui_error(x1,y1);//�����Ͼ���ʾerrͼ�ꡣ
		return;			//ͬʱ�˳�������
	}
	if(mode<2){			//����0�ͻ�������ѭ��������1�ͺ�frameһ���ˣ�
		m=2;			//����Ҫ������СֵΪ2��
	}else{
		m=mode;
	}
	for(x=x1;x<=x2;x+=m){//��mode��ֵΪ��϶ֵ����㡣
		for(y=y1;y<=y2;y+=m){
			ui_write_point(x,y,1);
		}
	}
//ԭ��������
//	if(mode<2){
//		for(x=x1;x<=x2;x++){
//			for(y=y1;y<=y2;y++){
//				if((x+y)%2==0)ui_write_point(x,y,1);
//			}
//		}
//	}else{
//		for(x=x1;x<=x2;x+=mode){
//			for(y=y1;y<=y2;y+=mode){
//				ui_write_point(x,y,1);
//			}
//		}
//	}		
}
/*-------------------------------------------------------
UI�Ļ�ͼƬ������
-------------------------------------------------------*/
void ui_draw_bmp(u8 x,u8 y,u8 w,u8 h,u8 bmp[],u8 mode){
	u8 xi,yi;
	for(yi=0;yi<=((h-1)/8);yi++){
		for(xi=0;xi<w;xi++){
			ui_write_byte(x+xi,yi*8+y,bmp[xi+w*yi],mode);
		}
	}
}
