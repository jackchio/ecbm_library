#include "ui.h"
/*--------------------------------------变量定义-----------------------------------*/
u8 xdata ui_system_buff[UI_SYSTEM_BUFF_SIZE];//通用画面缓存。
u8 code * ui_font_english;
u8 code * ui_font_chinese;
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
UI缓存清除函数。
-------------------------------------------------------*/
void ui_cls(void){
	u16 i;								//临时变量。
	for(i=0;i<UI_SYSTEM_BUFF_SIZE;i++){ //跳过信息区，循环到最尾。
		ui_system_buff[i]=0x00;			//清零。
	}
}
/*-------------------------------------------------------
UI的写点函数。
-------------------------------------------------------*/
void ui_write_point(u8 x,u8 y,u8 state){
	u8 y0,z;
	if((x<UI_WIDTH)&&(y<UI_HEIGHT)){	//有效范围判断。
		y0=y%8;							//取点位置。
		z=0x01<<y0;						//把点位置翻译成数据。
		y0=y/8;							//取页地址。
		switch(state){					//获取点的状态。
			case point_off:{			//关闭点的时候，
				z=~z;					//将数据反向，
				ui_system_buff[x+UI_WIDTH*y0]&=z;//接着与运算把对应位清零。
			}break;
			case point_on :{			//打开点的时候，
				ui_system_buff[x+UI_WIDTH*y0]|=z;//做或运算把对应位置一。
			}break;
			case point_tog:{			//翻转点的时候，
				ui_system_buff[x+UI_WIDTH*y0]^=z;//做异或运算把对应位取反。
			}break;
		}		
	}
}
/*-------------------------------------------------------
UI的读点函数。
-------------------------------------------------------*/
u8 ui_read_point(u8 x,u8 y){
	u8 y0,z;
	if((x<UI_WIDTH)&&(y<UI_HEIGHT)){		//有效范围判断。
		y0=y%8;								//取点位置。
		z=0x01<<y0;							//把点位置翻译成数据。
		y0=y/8;								//取页地址。
		if(ui_system_buff[x+UI_WIDTH*y0]&z){//从数组内取出元数据，和点数据相与之后就知道点的状态。
			return 1;						//归一化处理，把1~255都变成1。
		}									//这里的else return 0和下面的return 0合并。显得结构紧凑些。
	}
	return 0;								//由于带返回值的函数必须要有一个return，所以就和上面的合并了。
}
/*-------------------------------------------------------
UI的写字节函数。
-------------------------------------------------------*/
void ui_write_byte(u8 x,u8 y,u8 dat,u8 mode){
	u8 dat_back,out_mask,i,data_point=0x01,y_offset;
	if((mode&0x04)==0){			//如果没有使能输出控制，
		out_mask=0xff;			//那么就全输出。
	}else{						//如果使能了输出控制，就看看使能了哪种数据。
		if((mode&0x01)==0){		//如果使能了只输出0，
			out_mask=dat^0xff;	//通过翻转所有位，把数据0做成mask位。
		}else{					//如果使能了只输出1，
			out_mask=dat;		//那么原来的数据可以直接做成mask。
		}
	}
	if((mode&0x02)==0){			//如果没有使能翻转位，
		dat_back=dat;			//数据就按原样输出。
	}else{						//如果使能了翻转位，
		dat_back=dat^0xff;		//把数据全部取反。
	}
	y_offset=y;					//把y的偏移保存到临时变量。
	for(i=0;i<8;i++){			//一个字节有8位。
		if(out_mask&data_point){//对照输出允许位，允许输出的地方才能显示。
			if(dat_back&data_point){//对照数据，数据是1的话，
				ui_write_point(x,y_offset,1);//就点亮像素。
			}else{					//数据是0的话，
				ui_write_point(x,y_offset,0);//就熄灭像素。
			}
		}
		y_offset++;				//写完一位置，就要到下一个位置。
		data_point=data_point<<1;//写完一位数据就要到下一位数据，并且是从低位到高位。
	}
}
/*-------------------------------------------------------
UI的显示字符函数(英文)。
-------------------------------------------------------*/
void ui_char_e(u8 x,u8 y,u8 ch,u8 mode){
	u8 ht,ht_i,w_i,y0,w,h,char_point;
	u16 addr;
	w=ui_font_english[0];//获取字模的宽度。
	h=ui_font_english[1];//获取字模的高度。
	ht=(h-1)/8;  //获取一个字所占的页面数。//1-8:0      9-16:1     17-24:2
	char_point=ch-' ';			//跳过非显示区。
	for(ht_i=0;ht_i<=ht;ht_i++){//一个字占多少页面就循环多少次。
		y0=y+ht_i*8;			//因为通常都是一行8排像素，所以下一行要乘以8。
		addr=char_point*w*(ht+1)/*这个用于跳过目标字符之前的数据的，char_point是当前字符，w*(ht+1)是其中一个字模所占的字节数。*/\
			+ht_i*w/*这个用于多行字符的，由于wi的范围最大是字符的宽度，所以当字模由一行以上数据组成时，需要这个调到第二第三...行*/\
			+2;/*前两个字符存放着字符的宽高数据。*/
		for(w_i=0;w_i<w;w_i++){	//x轴偏移坐标就是从0到宽度。
			ui_write_byte(x+w_i,y0,ui_font_english[w_i/*这个是伴随X轴偏移的数据偏移，和for循环的动作挂钩。*/\
			+addr],mode);
			
		}
	}
}
/*-------------------------------------------------------
UI的显示字符函数(中文)。
-------------------------------------------------------*/
void ui_char_c(u8 x,u8 y,u8 ch1,u8 ch2,u8 mode){
	u8 ht,ht_i,w_i,y0,w,h,max,i;
	u16 addr;
	w=ui_font_chinese[0];//获取字模的宽度。
	h=ui_font_chinese[1];//获取字模的高度。
	max=ui_font_chinese[2];
	ht=(h-1)/8;  //获取一个字所占的页面数。//1-8:0      9-16:1     17-24:2
	for(i=1;i<=max;i++){
		if((ui_font_chinese[i*26]==ch1)&&(ui_font_chinese[i*26+1]==ch2)){
			addr=i*26+2;
			for(ht_i=0;ht_i<=ht;ht_i++){//一个字占多少页面就循环多少次。
				y0=y+ht_i*8;			//因为通常都是一行8排像素，所以下一行要乘以8。
				for(w_i=0;w_i<w;w_i++){	//x轴偏移坐标就是从0到宽度。
					ui_write_byte(x+w_i,y0,ui_font_chinese[addr++],mode);
				}
			}
			break;
		}
	}
	if(i>max){
		addr=2;
		for(ht_i=0;ht_i<=ht;ht_i++){//一个字占多少页面就循环多少次。
			y0=y+ht_i*8;			//因为通常都是一行8排像素，所以下一行要乘以8。
			for(w_i=0;w_i<w;w_i++){	//x轴偏移坐标就是从0到宽度。
				ui_write_byte(x+w_i,y0,ui_font_chinese[addr++],mode);
			}
		}
	}
}
/*-------------------------------------------------------
UI的printf函数。
-------------------------------------------------------*/
void ui_printf(u8 x,u8 y,u8 mode,const char * str,...){
	u8 xi,yi,w,h,c;
	u16 len,j;
	u8 buf[UI_PRINTF_BUFF_SIZE];	//printf需要的缓存。
	va_list vp;						//定义参数地址。
    va_start(vp, str);				//初始化参数地址。
    len=vsprintf(buf,str,vp);		//格式化字符串。
    va_end(vp);						//结束参数。
	xi=x;		//从参数得到初始X轴位置。
	yi=y;		//从参数得到初始Y轴位置。
	for(j=0;j<len;j++){//显示所有的字符。
		if(buf[j]<0x80){
			c=1;
			w=ui_font_english[0];//获取字模的宽度。
			h=ui_font_english[1];//获取字模的高度。
			if(((xi+w)>UI_WIDTH)||(buf[j]=='\n')){	//当字符超出画面或者遇到换行符时，
				xi=x;								//重置X轴坐标到初始位置。
				yi+=h;								//Y轴移动一个字模的高度。
				if(buf[j]=='\n'){					//如果是遇到换行符而换行的，
					j++;							//那么要加到下一位以便下面的ui_char语句来显示。
					if(j==len)break;				//如果下一位就结束了，就跳出循环。
					}
			}
			ui_char_e(xi,yi,buf[j],mode);			//显示字符。
			xi+=w;									//将光标移动一个字符的宽度，方便下一个字符显示。
		}else{
			if(c)xi++;
			c=0;
			w=ui_font_chinese[0];//获取字模的宽度。
			h=ui_font_chinese[1];//获取字模的高度。
			if((xi+w)>UI_WIDTH){
				xi=x;								//重置X轴坐标到初始位置。
				yi+=h;								//Y轴移动一个字模的高度。
			}
			ui_char_c(xi,yi,buf[j],buf[j+1],mode);	//显示字符。
			j++;
			xi+=w;									//将光标移动一个字符的宽度，方便下一个字符显示。
		}
	}
}
/*-------------------------------------------------------
UI的参数错误提示函数。
-------------------------------------------------------*/
void ui_error(u8 x,u8 y){
	u8 i;
	u8 code err_buff[]={0x18,0x24,0x42,0x81,0xAD,0x81,0x42,0x24,0x18,0x00,0xBE,0xAA,0xAA,0x80,0xB8,0x88,0x80,0xB8,0x88,0x80};
	for(i=0;i<20;i++){
		ui_write_byte(x+i,y,err_buff[i],0);//在指定位置显示err图标。
	}
}
/*-------------------------------------------------------
UI的填充矩形函数。
-------------------------------------------------------*/
 void ui_fill_frame(u8 x1,u8 y1,u8 x2,u8 y2,u8 state){
	u8 xi,yi,up,down,y1_page,y2_page,ud;
	if(x1>x2){			//判断X轴坐标是否符合规格。
		ui_error(x1,y1);//不符合就显示err图标。
		return;			//同时退出函数。
	}
	if(y1>y2){			//判断Y轴坐标是否符合规格。
		ui_error(x1,y1);//不符合就显示err图标。
		return;			//同时退出函数。
	}
	up=0xff<<(y1%8);	//计算顶部那几排的数据。
	down=0xff>>(7-y2%8);//计算底部那几排的数据。
	ud=up&down;			//如果顶部和底部在同一个页面，那么取中间公共的。
	y1_page=y1/8;		//起始页面。
	y2_page=y2/8;		//终止界面。
	if(y1_page==y2_page){//如果顶部和底部在同一个页面，
		switch(state){	//根据状态来具体操作。
			case 0:{	//这个代表熄灭点，
				ud=~ud;	//将源数据取反，
				for(xi=x1;xi<=x2;xi++){//从矩形左边到右边，
					ui_system_buff[xi+UI_WIDTH*y1_page]&=ud;//依次写入0。
				}
			}break;
			case 1:{	//这个代表点亮点，
				for(xi=x1;xi<=x2;xi++){//从矩形左边到右边，
					ui_system_buff[xi+UI_WIDTH*y1_page]|=ud;//依次写入1。
				}
			}break;
			case 2:{	//这个代表取反点，
				for(xi=x1;xi<=x2;xi++){//从矩形左边到右边，
					ui_system_buff[xi+UI_WIDTH*y1_page]^=ud;//依次取反。
				}
			}break;
		}
	}else{//如果顶部和底部不在同一个页面，而是多个页面。
		switch(state){	//根据状态来具体操作。
			case 0:{	//这个代表熄灭点，
				up=~up;	//将源数据取反，
				down=~down;//将源数据取反，
				for(xi=x1;xi<=x2;xi++){//输入顶部和底部的数据，在这里都是清零。
					ui_system_buff[xi+UI_WIDTH*y1_page]&=up;
					ui_system_buff[xi+UI_WIDTH*y2_page]&=down;
				}
				if((y2_page-y1_page)>1){//当顶部和底部之间还有数据的时候，
					for(yi=y1_page+1;yi<y2_page;yi++){
						for(xi=x1;xi<=x2;xi++){
							ui_system_buff[xi+UI_WIDTH*yi]=0x00;//将之间的所有行都清零。
						}
					}
				}
			}break;
			case 1:{//下面的操作和上面的差不多，只是因为代码多才看起来复杂，实际就是置一。
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
			case 2:{//下面的操作和上面的差不多，只是因为代码多才看起来复杂，实际就是取反。
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
//	旧程序保留对比
//	for(xi=x1;xi<=x2;xi++){
//		for(yi=y1;yi<=y2;yi++){
//			ui_write_point(xi,yi,state);
//		}
//	}	

}
/*-------------------------------------------------------
UI的画线函数。
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
UI的画横线函数。
-------------------------------------------------------*/
void ui_draw_wline(u8 x1,u8 x2,u8 y,u8 state){
	u8 x,yi,z;
	if(x1>x2){			//判断X轴坐标是否符合规格。
		ui_error(x1,y);	//不符合就显示err图标。
		return;			//同时退出函数。
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
//旧程序
//	for(x=x1;x<=x2;x++){
//		ui_write_point(x,y,state);		
//	}	
}
/*-------------------------------------------------------
UI的画竖线函数。
-------------------------------------------------------*/
void ui_draw_hline(u8 x,u8 y1,u8 y2,u8 state){
	u8 yi,up,down,y1_page,y2_page,ud;
	if(y1>y2){			//判断Y轴坐标是否符合规格。
		ui_error(x,y1);//不符合就显示err图标。
		return;			//同时退出函数。
	}
	up=0xff<<(y1%8);	//计算顶部那几排的数据。
	down=0xff>>(7-y2%8);//计算底部那几排的数据。
	ud=up&down;			//如果顶部和底部在同一个页面，那么取中间公共的。
	y1_page=y1/8;		//起始页面。
	y2_page=y2/8;		//终止界面。
	if(y1_page==y2_page){//如果顶部和底部在同一个页面，
		switch(state){	//根据状态来具体操作。
			case 0:{	//这个代表熄灭点，
				ud=~ud;	//将源数据取反，
				ui_system_buff[x+UI_WIDTH*y1_page]&=ud;//依次写入0。
			}break;
			case 1:{	//这个代表点亮点，
				ui_system_buff[x+UI_WIDTH*y1_page]|=ud;//依次写入1。
			}break;
			case 2:{	//这个代表取反点，
				ui_system_buff[x+UI_WIDTH*y1_page]^=ud;//依次取反。
			}break;
		}
	}else{//如果顶部和底部不在同一个页面，而是多个页面。
		switch(state){	//根据状态来具体操作。
			case 0:{	//这个代表熄灭点，
				up=~up;	//将源数据取反，
				down=~down;//将源数据取反，
				ui_system_buff[x+UI_WIDTH*y1_page]&=up;//输入顶部和底部的数据，在这里都是清零。
				ui_system_buff[x+UI_WIDTH*y2_page]&=down;
				if((y2_page-y1_page)>1){//当顶部和底部之间还有数据的时候，
					for(yi=y1_page+1;yi<y2_page;yi++){
						ui_system_buff[x+UI_WIDTH*yi]=0x00;//将之间的所有行都清零。
					}
				}
			}break;
			case 1:{//下面的操作和上面的差不多，只是因为代码多才看起来复杂，实际就是置一。
				ui_system_buff[x+UI_WIDTH*y1_page]|=up;
				ui_system_buff[x+UI_WIDTH*y2_page]|=down;
				if((y2_page-y1_page)>1){
					for(yi=y1_page+1;yi<y2_page;yi++){
						ui_system_buff[x+UI_WIDTH*yi]=0xff;
					}
				}
			}break;
			case 2:{//下面的操作和上面的差不多，只是因为代码多才看起来复杂，实际就是取反。
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
//	原程序，用于对比。
//	for(yi=y1;yi<=y2;yi++){
//		ui_write_point(x,yi,state);		
//	}
}
/*-------------------------------------------------------
UI的画矩形函数。
-------------------------------------------------------*/
void ui_draw_frame(u8 x1,u8 y1,u8 x2,u8 y2,u8 state){
	if(x1>x2){			//判断X轴坐标是否符合规格。
		ui_error(x1,y1);//不符合就显示err图标。
		return;			//同时退出函数。
	}
	if(y1>y2){			//判断Y轴坐标是否符合规格。
		ui_error(x1,y1);//不符合就显示err图标。
		return;			//同时退出函数。
	}
	ui_draw_wline(x1,x2,y1,state);//画上边横线。
	ui_draw_wline(x1,x2,y2,state);//画下边横线。
	ui_draw_hline(x1,y1,y2,state);//画左边竖线。
	ui_draw_hline(x2,y1,y2,state);//画左边竖线。
}
/*-------------------------------------------------------
UI的画圆函数。
-------------------------------------------------------*/
void ui_draw_circle(u8 x0,u8 y0,u8 r,u8 opt,u8 state){
	s16 x,y;
	s16 di;
	x=0;
	y=r;	  
	di=3-(r<<1); 
	while(x<=y){            
		if((opt==1)||(opt==5)){
			ui_write_point(x0-x,y0-y,state);	//左上
			ui_write_point(x0-y,y0-x,state);    //左上
		}
		if((opt==2)||(opt==5)){
			ui_write_point(x0+x,y0-y,state);    //右上 
			ui_write_point(x0+y,y0-x,state);    //右上 
		}
		if((opt==3)||(opt==5)){
			ui_write_point(x0+x,y0+y,state);    //右下 
			ui_write_point(x0+y,y0+x,state);    //右下
		}
		if((opt==4)||(opt==5)){
			ui_write_point(x0-y,y0+x,state);    //左下
			ui_write_point(x0-x,y0+y,state);    //左下   
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
UI的填充圆函数。
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
				ui_write_point(x0-x,y0-i,state);	//左上
				ui_write_point(x0-i,y0-x,state);	//左上
			}
			if((opt==2)||(opt==5)){
				ui_write_point(x0+x,y0-i,state);    //右上 
				ui_write_point(x0+i,y0-x,state);    //右上 
			}
			if((opt==3)||(opt==5)){
				ui_write_point(x0+x,y0+i,state);    //右下 
				ui_write_point(x0+i,y0+x,state);    //右下
			}
			if((opt==4)||(opt==5)){
				ui_write_point(x0-i,y0+x,state);    //左下
				ui_write_point(x0-x,y0+i,state);    //左下   
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
UI的填充圆角矩形函数。
-------------------------------------------------------*/
void ui_fill_roundframe(u8 x1,u8 y1,u8 x2,u8 y2,u8 r,u8 state){
	if((x2-x1)<(2*r)){	//矩形的宽，一定要大于等于两倍圆角半径。
		ui_error(x1,y1);//不然就报错。
		return;			//同时退出函数。
	}
	if((y2-y1)<(2*r)){	//矩形的高，也一定要大于等于两倍圆角半径。
		ui_error(x1,y1);//不然就报错。
		return;			//同时退出函数。
	}
	ui_fill_circle(x1+r,y1+r,r,1,state);//填充左上圆角。
	ui_fill_circle(x2-r,y1+r,r,2,state);//填充右上圆角。
	ui_fill_circle(x2-r,y2-r,r,3,state);//填充左下圆角。
	ui_fill_circle(x1+r,y2-r,r,4,state);//填充右下圆角。
	
	ui_fill_frame(x1+r,y1,  x2-r,y1+r,state);//填充上方矩形。
	ui_fill_frame(x1,  y1+r,x2,  y2-r,state);//填充中间矩形。
	ui_fill_frame(x1+r,y2-r,x2-r,y2,  state);//填充下方矩形。
}
/*-------------------------------------------------------
UI的画圆角矩形函数。
-------------------------------------------------------*/
void ui_draw_roundframe(u8 x1,u8 y1,u8 x2,u8 y2,u8 r,u8 state){
	if((x2-x1)<(2*r)){	//矩形的宽，一定要大于等于两倍圆角半径。
		ui_error(x1,y1);//不然就报错。
		return;			//同时退出函数。
	}
	if((y2-y1)<(2*r)){	//矩形的高，也一定要大于等于两倍圆角半径。
		ui_error(x1,y1);//不然就报错。
		return;			//同时退出函数。
	}
	ui_draw_circle(x1+r,y1+r,r,1,state);//画左上圆角。
	ui_draw_circle(x2-r,y1+r,r,2,state);//画右上圆角。
	ui_draw_circle(x2-r,y2-r,r,3,state);//画左下圆角。
	ui_draw_circle(x1+r,y2-r,r,4,state);//画右下圆角。
	
	ui_draw_wline(x1+r,x2-r,y1,state);//画上横线。
	ui_draw_wline(x1+r,x2-r,y2,state);//画下横线。
	ui_draw_hline(x1,y1+r,y2-r,state);//画左竖线。
	ui_draw_hline(x2,y1+r,y2-r,state);//画右竖线。
}
/*-------------------------------------------------------
UI的填充网格函数。
-------------------------------------------------------*/
void ui_fill_mesh(u8 x1,u8 y1,u8 x2,u8 y2,u8 mode){
	u8 x,y,m;
	if(x1>x2){			//判断X轴坐标是否符合规格。
		ui_error(x1,y1);//不符合就显示err图标。
		return;			//同时退出函数。
	}if(y1>y2){			//判断Y轴坐标是否符合规格。
		ui_error(x1,y1);//不符合就显示err图标。
		return;			//同时退出函数。
	}
	if(mode<2){			//等于0就会陷入死循环，等于1就和frame一样了，
		m=2;			//所以要限制最小值为2。
	}else{
		m=mode;
	}
	for(x=x1;x<=x2;x+=m){//按mode的值为间隙值，打点。
		for(y=y1;y<=y2;y+=m){
			ui_write_point(x,y,1);
		}
	}
//原程序留存
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
UI的画图片函数。
-------------------------------------------------------*/
void ui_draw_bmp(u8 x,u8 y,u8 w,u8 h,u8 bmp[],u8 mode){
	u8 xi,yi;
	for(yi=0;yi<=((h-1)/8);yi++){
		for(xi=0;xi<w;xi++){
			ui_write_byte(x+xi,yi*8+y,bmp[xi+w*yi],mode);
		}
	}
}
