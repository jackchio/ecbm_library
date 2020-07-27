#include "at24cxx.h"
/*--------------------------------------��������-----------------------------------*/
u8 xdata at24_model=0;
/*--------------------------------------������-----------------------------------*/
/*�������۵�ר��*************************ͨ��ģ��*******************************/#if 1
/*-------------------------------------------------------
���ù���״̬��������һ����������Ϊ����״̬��
-------------------------------------------------------*/
void at24_set_work(at24_def * dev){
	soft_iic_set_pin_linkage(dev->id,dev->scl,dev->sda);//�ѵ�ǰ������Ϣ�л���IIC�ĵ�ǰ���á�	
	at24_model=dev->model;								//�ѵ�ǰ�����ͺ��л���AT24�ĵ�ǰ���á�
}
/*-------------------------------------------------------
AT24CXXϵ�еĳ�ʼ��������
-------------------------------------------------------*/
void at24_init(at24_def * dev,u8 model,u8 scl,u8 sda){
	dev->scl=scl;							//��SCL���ű��档
	dev->sda=sda;							//��SDA���ű��档
	dev->model=model;					    //���ͺ���Ϣ���档
	dev->id=soft_iic_init_linkage(scl,sda);	//��ʼ�����š�
	at24_set_work(dev);						//�л�����������ǰ������
}
/*-------------------------------------------------------
AT24ϵ�е�д������֧�ֶ������д�롣
-------------------------------------------------------*/
u8 at24_write(u16 addr,u8 dat[],u16 num){
	u32 i;			//forѭ��ר�á�
	u32 addr_max;	//��ַ�����ֵ��
	u32 num_max;	//��д���������
	
	u16 sector_old;	//��һ�ε�������
	u8 sector_size; //�����Ĵ�С
	u8 iic_addr;	//IIC�ĵ�ַ��
	
	switch(at24_model&0xF0){//ͨ���ͺű������жϵ�ַ���ֵ��
		case AT24CXX :{
			return AT24_ERROR_INIT;//���ش�����-��ʼ������
		}break;
		case AT24C01 :{
			addr_max=128;//AT24C01�����128���ֽڵĿռ䡣
			iic_addr=AT24_ADDR+(at24_model&0x07);
			sector_size=8;
		}break;
		case AT24C02 :{
			addr_max=256;//AT24C02�����256���ֽڵĿռ䡣
			iic_addr=AT24_ADDR+(at24_model&0x07);
			sector_size=16;
		}break;
		case AT24C04 :{
			addr_max=512;//AT24C04�����512���ֽڵĿռ䡣
			iic_addr=AT24_ADDR+(at24_model&0x06)+(u8)(addr>>8);
			sector_size=16;
		}break;
		case AT24C08 :{
			addr_max=1024;//AT24C08�����1024���ֽڵĿռ䡣
			iic_addr=AT24_ADDR+(at24_model&0x04)+(u8)(addr>>8);
			sector_size=16;
		}break;
		case AT24C16 :{
			addr_max=2048;//AT24C16�����2048���ֽڵĿռ䡣
			iic_addr=AT24_ADDR+(u8)(addr>>8);
			sector_size=16;
		}break;
		case AT24C32 :{
			addr_max=4096;//AT24C16�����2048���ֽڵĿռ䡣
			iic_addr=AT24_ADDR+(at24_model&0x07);
			sector_size=32;
		}break;
		case AT24C64 :{
			addr_max=8192;//AT24C16�����2048���ֽڵĿռ䡣
			iic_addr=AT24_ADDR+(at24_model&0x07);
			sector_size=32;
		}break;
		case AT24C128:{
			addr_max=16384;//AT24C16�����2048���ֽڵĿռ䡣
			iic_addr=AT24_ADDR+(at24_model&0x07);
			sector_size=32;
		}break;
		case AT24C256:{
			addr_max=32768;//AT24C16�����2048���ֽڵĿռ䡣
			iic_addr=AT24_ADDR+(at24_model&0x07);
			sector_size=32;
		}break;
		case AT24C512:{
			addr_max=65536;//AT24C16�����65536���ֽڵĿռ䡣
			iic_addr=AT24_ADDR+(at24_model&0x07);
			sector_size=32;
		}break;
	}
	if(addr>addr_max){			//�����ʼ��ַ�ͳ��������ֵ��
		return AT24_ERROR_ADDR;	//���ش�����-��ַ����
	}
	if(((u32)addr+(u32)num)>addr_max){	//����ǵ�ַ�����
		num_max=addr_max-(u32)addr;	//����д�����ݣ���ֹ�����
	}else{
		num_max=(u32)num;			//û�����ȫд��ȥ��
	}
	sector_old=addr/sector_size;		//����������
//	debug("W=%02X\r\n",(u16)(iic_addr<<1));//�����á�
	soft_iic_start();			//IIC��ʼ��
	soft_iic_write(iic_addr<<1);	//��дIIC������ַ��
	if(soft_iic_read_ack()!=0){	//��ACK��
		soft_iic_stop();		//IICֹͣ��
		return AT24_ERROR_NOACK;//���û��ACK��˵�����������ڡ����ش�����-�޻�Ӧ����
	}
	if(sector_size==32){
		soft_iic_write(addr/256);	//��дEEPROM�ڴ��ַ��
		if(soft_iic_read_ack()!=0){	//��ACK��
			soft_iic_stop();		//IICֹͣ��
			return AT24_ERROR_NOACK;//���û��ACK��˵�����������ڡ����ش�����-�޻�Ӧ����
		}
	}
	soft_iic_write(addr%256);	//��дEEPROM�ڴ��ַ��
	if(soft_iic_read_ack()!=0){	//��ACK��
		soft_iic_stop();		//IICֹͣ��
		return AT24_ERROR_NOACK;//���û��ACK��˵�����������ڡ����ش�����-�޻�Ӧ����
	}
	for(i=0;i<num_max;i++){		//��ʼ�������ݡ�
		if(sector_old!=(((u32)addr+i)/sector_size)){	//�����������ˣ�
			sector_old=(((u32)addr+i)/sector_size);	//����������Ϣ��
			soft_iic_stop();	//IICֹͣ��
			
			switch(at24_model&0xF0){//���¼����ַ��
				case AT24C01 :{
					iic_addr=AT24_ADDR+(at24_model&0x07);
				}break;
				case AT24C02 :{
					iic_addr=AT24_ADDR+(at24_model&0x07);
				}break;
				case AT24C04 :{
					iic_addr=AT24_ADDR+(at24_model&0x06)+(u8)((addr+i)>>8);
				}break;
				case AT24C08 :{
					iic_addr=AT24_ADDR+(at24_model&0x04)+(u8)((addr+i)>>8);
				}break;
				case AT24C16 :{
					iic_addr=AT24_ADDR+(u8)((addr+i)>>8);
				}break;
				case AT24C32 :{
					iic_addr=AT24_ADDR+(at24_model&0x07);
				}break;
				case AT24C64 :{
					iic_addr=AT24_ADDR+(at24_model&0x07);
				}break;
				case AT24C128:{
					iic_addr=AT24_ADDR+(at24_model&0x07);
				}break;
				case AT24C256:{
					iic_addr=AT24_ADDR+(at24_model&0x07);
				}break;
				case AT24C512:{
					iic_addr=AT24_ADDR+(at24_model&0x07);
				}break;
			}
//			debug("W=%02X-%02X(%02d)\r\n",(u16)iic_addr,(addr+i)%256,sector);//�����á�
			delay_ms(10);		//�ֲ��ϵĻ���д��ʱ�䣨���ֵ����
			soft_iic_start();	//IIC��ʼ��
			soft_iic_write(iic_addr<<1);//��дIIC������ַ��
			if(soft_iic_read_ack()!=0){	//��ACK��
				soft_iic_stop();		//IICֹͣ��
				return AT24_ERROR_NOACK;//���û��ACK��˵�����������ڡ����ش�����-�޻�Ӧ����
			}
			if(sector_size==32){
				soft_iic_write((addr+i)/256);	//��дEEPROM�ڴ��ַ��
				if(soft_iic_read_ack()!=0){	//��ACK��
					soft_iic_stop();		//IICֹͣ��
					return AT24_ERROR_NOACK;//���û��ACK��˵�����������ڡ����ش�����-�޻�Ӧ����
				}
			}
			soft_iic_write((addr+i)%256);
			if(soft_iic_read_ack()!=0){	//��ACK��
				soft_iic_stop();		//IICֹͣ��
				return AT24_ERROR_NOACK;//���û��ACK��˵�����������ڡ����ش�����-�޻�Ӧ����
			}
		}
		soft_iic_write(dat[i]);	//д�����ݡ�
		if(soft_iic_read_ack()!=0){	//��ACK��
			soft_iic_stop();		//IICֹͣ��
			return AT24_ERROR_SEND;//���û��ACK��˵��ͨ�ų������⡣���ش�����-���ʹ���
		}
	}	
	soft_iic_stop();//IICֹͣ��
	if(((u32)addr+(u32)num)>addr_max){	 //�����ַ������ķ��գ�
		return AT24_ERROR_NUMBER;//���ش�����-��������
	}
	return AT24_OK;//ɶ��û�оͷ���������
}
/*-------------------------------------------------------
AT24ϵ�еĶ�������֧�ֶ�����ݶ�ȡ��
-------------------------------------------------------*/
u8 at24_read(u16 addr,u8 dat[],u16 num){
    u32 i;			//forѭ��ר�á�
	u32 addr_max;	//��ַ�����ֵ��
	u32 num_max;	//��д���������
	u8 iic_addr;	//IIC�ĵ�ַ��
	switch(at24_model&0xF0){//ͨ���ͺű������жϵ�ַ���ֵ��
		case AT24CXX :{
			return AT24_ERROR_INIT;//���ش�����-��ʼ������
		}break;
		case AT24C01 :{
			addr_max=128;//AT24C01�����128���ֽڵĿռ䡣
			iic_addr=AT24_ADDR+(at24_model&0x07);
		}break;
		case AT24C02 :{
			addr_max=256;//AT24C02�����256���ֽڵĿռ䡣
			iic_addr=AT24_ADDR+(at24_model&0x07);
		}break;
		case AT24C04 :{
			addr_max=512;//AT24C04�����512���ֽڵĿռ䡣
			iic_addr=AT24_ADDR+(at24_model&0x06)+(u8)(addr>>8);
		}break;
		case AT24C08 :{
			addr_max=1024;//AT24C08�����1024���ֽڵĿռ䡣
			iic_addr=AT24_ADDR+(at24_model&0x04)+(u8)(addr>>8);
		}break;
		case AT24C16 :{
			addr_max=2048;//AT24C16�����2048���ֽڵĿռ䡣
			iic_addr=AT24_ADDR+(u8)(addr>>8);
		}break;
		case AT24C32 :{
			addr_max=4096;//AT24C16�����2048���ֽڵĿռ䡣
			iic_addr=AT24_ADDR+(at24_model&0x07);
		}break;
		case AT24C64 :{
			addr_max=8192;//AT24C16�����2048���ֽڵĿռ䡣
			iic_addr=AT24_ADDR+(at24_model&0x07);
		}break;
		case AT24C128:{
			addr_max=16384;//AT24C16�����2048���ֽڵĿռ䡣
			iic_addr=AT24_ADDR+(at24_model&0x07);
		}break;
		case AT24C256:{
			addr_max=32768;//AT24C16�����2048���ֽڵĿռ䡣
			iic_addr=AT24_ADDR+(at24_model&0x07);
		}break;
		case AT24C512:{
			addr_max=65536;//AT24C16�����65536���ֽڵĿռ䡣
			iic_addr=AT24_ADDR+(at24_model&0x07);
		}break;
	}
	if(addr>addr_max){			//�����ʼ��ַ�ͳ��������ֵ��
		return AT24_ERROR_ADDR;	//���ش�����-��ַ����
	}
	if(((u32)addr+(u32)num)>addr_max){	//����ǵ�ַ�����
		num_max=addr_max-(u32)addr;	//����д�����ݣ���ֹ�����
	}else{
		num_max=(u32)num;			//û�����ȫд��ȥ��
	}
//	debug("R=%02X-%02X\r\n",(u16)iic_addr,addr%256);//�����á�
 	soft_iic_start();			//IIC��ʼ��
	soft_iic_write(iic_addr<<1);	//��дIIC������ַ��
	if(soft_iic_read_ack()!=0){	//��ACK��
		soft_iic_stop();		//IICֹͣ��
		return AT24_ERROR_NOACK;//���û��ACK��˵�����������ڡ����ش�����-�޻�Ӧ����
	}
	if(addr_max>2048){
		soft_iic_write(addr/256);	//��дEEPROM�ڴ��ַ��
		if(soft_iic_read_ack()!=0){	//��ACK��
			soft_iic_stop();		//IICֹͣ��
			return AT24_ERROR_NOACK;//���û��ACK��˵�����������ڡ����ش�����-�޻�Ӧ����
		}
	}
	soft_iic_write(addr%256);
	if(soft_iic_read_ack()!=0){	//��ACK��
		soft_iic_stop();		//IICֹͣ��
		return AT24_ERROR_NOACK;//���û��ACK��˵�����������ڡ����ش�����-�޻�Ӧ����
	}
	soft_iic_start();			//IIC���¿�ʼ�����Ƕ�����������
	soft_iic_write((iic_addr<<1)+1);	//дIIC������ַ�������ö�ȡλ��
	for(i=0;i<num_max;i++){		//��ʼ��ȡ���ݡ�
		soft_iic_write_ack();	//����һ��ACK����ʾ��������
		dat[i]=soft_iic_read();	//��ȡ���ݡ�
	}
	soft_iic_write_nack();//ֹͣ��ȡ�˾ͷ���NOACK��
	soft_iic_stop();//IICֹͣ��
	if((addr+num)>addr_max){	 //�����ַ������ķ��գ�
		return AT24_ERROR_NUMBER;//���ش�����-��������
	}
	return AT24_OK;//ɶ��û�оͷ���������
}
/*�������۵�ר��**************************************************************/#endif
/*�������۵�ר��*************************ȫдģ��***********/#if AT24CXX_WRITE_ALL_EN
/*-------------------------------------------------------
AT24ϵ�е�ȫд������
-------------------------------------------------------*/
void at24_write_all(void){
	u16 max;//ѭ�����ֵ��
	u16 i,j;//����forѭ������ʱ������
	u8 re;      //����������档
	u8 buf[128];//�������档
	switch(at24_model&0xF0){//�����ͺ���ѡ��
		default      :max= 0 ;debug("model=unkonw\r\n" ) ;break;//δ֪�ͺš�
		case AT24C01 :max= 1 ;debug("model=AT24C01\r\n") ;break;//AT24C01�� ������1  *128=128  �ֽڡ�
		case AT24C02 :max= 2 ;debug("model=AT24C02\r\n") ;break;//AT24C02�� ������2  *128=256  �ֽڡ�
		case AT24C04 :max= 4 ;debug("model=AT24C04\r\n") ;break;//AT24C04�� ������4  *128=512  �ֽڡ�
		case AT24C08 :max= 8 ;debug("model=AT24C08\r\n") ;break;//AT24C08�� ������8  *128=1024 �ֽڡ�
		case AT24C16 :max=16 ;debug("model=AT24C16\r\n") ;break;//AT24C16�� ������16 *128=2048 �ֽڡ�
		case AT24C32 :max=32 ;debug("model=AT24C32\r\n") ;break;//AT24C32�� ������32 *128=4096 �ֽڡ�
		case AT24C64 :max=64 ;debug("model=AT24C64\r\n") ;break;//AT24C64�� ������64 *128=8192 �ֽڡ�
		case AT24C128:max=128;debug("model=AT24C128\r\n");break;//AT24C128��������128*128=16384�ֽڡ�
		case AT24C256:max=256;debug("model=AT24C256\r\n");break;//AT24C256��������256*128=32768�ֽڡ�
		case AT24C512:max=512;debug("model=AT24C512\r\n");break;//AT24C512��������512*128=65536�ֽڡ�
	}
	for(i=0;i<max;i++){//ѭ��д��eepromоƬ��
		for(j=0;j<128;j++){//���ڿռ�Ƚϴ���128�ֽ�Ϊһ����д�롣
			buf[j]=i;//ÿ���ֵ�ɵ�ǰ��i��������
		}
		delay_ms(10);//д����д��֮�䶼Ҫ������10ms����ʱ��
		re=at24_write(i*128,buf,128);//д�����ݡ�
		switch(re){//���ݷ��صĽ��������д��Ľ����
			case AT24_OK          :debug("%03u-Ok!\r\n",          i);break;//д��ɹ���
			case AT24_ERROR_INIT  :debug("%03u-Init error!\r\n",  i);break;//��ʼ������
			case AT24_ERROR_NOACK :debug("%03u-Noack error!\r\n", i);break;//����δ�ظ���
			case AT24_ERROR_SEND  :debug("%03u-Send error!\r\n",  i);break;//����ʧ�ܡ�
			case AT24_ERROR_ADDR  :debug("%03u-Addr error!\r\n",  i);break;//��ַ����
			case AT24_ERROR_NUMBER:debug("%03u-Number error!\r\n",i);break;//������������
		}
	}
}
/*�������۵�ר��**************************************************************/#endif
/*�������۵�ר��*************************ȫ��ģ��************/#if AT24CXX_READ_ALL_EN
/*-------------------------------------------------------
AT24ϵ�е�ȫ��������
-------------------------------------------------------*/
void at24_read_all(void){
	u16 max;//ѭ�����ֵ��
	u16 i,j,k;//����forѭ������ʱ������
	u8 buf[128];//�������档
	switch(at24_model&0xF0){//�����ͺ���ѡ��
		default      :max= 0 ;debug("model=unkonw\r\n" ) ;break;//δ֪�ͺš�
		case AT24C01 :max= 1 ;debug("model=AT24C01\r\n") ;break;//AT24C01�� ������1  *128=128  �ֽڡ�
		case AT24C02 :max= 2 ;debug("model=AT24C02\r\n") ;break;//AT24C02�� ������2  *128=256  �ֽڡ�
		case AT24C04 :max= 4 ;debug("model=AT24C04\r\n") ;break;//AT24C04�� ������4  *128=512  �ֽڡ�
		case AT24C08 :max= 8 ;debug("model=AT24C08\r\n") ;break;//AT24C08�� ������8  *128=1024 �ֽڡ�
		case AT24C16 :max=16 ;debug("model=AT24C16\r\n") ;break;//AT24C16�� ������16 *128=2048 �ֽڡ�
		case AT24C32 :max=32 ;debug("model=AT24C32\r\n") ;break;//AT24C32�� ������32 *128=4096 �ֽڡ�
		case AT24C64 :max=64 ;debug("model=AT24C64\r\n") ;break;//AT24C64�� ������64 *128=8192 �ֽڡ�
		case AT24C128:max=128;debug("model=AT24C128\r\n");break;//AT24C128��������128*128=16384�ֽڡ�
		case AT24C256:max=256;debug("model=AT24C256\r\n");break;//AT24C256��������256*128=32768�ֽڡ�
		case AT24C512:max=512;debug("model=AT24C512\r\n");break;//AT24C512��������512*128=65536�ֽڡ�
	}
	if(max){//�����δ֪�ͺţ��Ͳ����ٶ�ȡ�ˡ�
		debug("      00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F\r\n");  //���һ�����
		debug("-------------------------------------------------------\r\n");//���ķָ��ߡ�
		for(k=0;k<max;k++){//ѭ����ȡоƬ��
			for(i=0;i<128;i++){
				buf[i]=0;//�建�档
			}
			at24_read(k*128,buf,128);//��ȡ128�ֽڵ����ݣ���д�뻺���������Ӧ��
			for(i=0;i<8;i++){//����Ϊ�˺�д���Ӧ���128�ֽڻ��棬��16�ֽ�һ�У�128�ֽھ���8�С�
				debug("%04X: ",k*128+(i<<4));//ÿ���Ե�ַ��ͷ��
				for(j=0;j<16;j++){//һ����ʾ16�ֽڵ����ݡ�
					debug("%02X ",(u16)buf[i*16+j]);//��HEX��ʽ��ʾ��
				}
				debug("|");//�ָ�����
				for(j=0;j<16;j++){//��ASCII����ʽ����ʾһ�顣
					if((buf[i*16+j]>=32)&&(buf[i*16+j]<=127)){//ֻ��������ʾ��ASCII�롣
						debug("%c",buf[i*16+j]);
					}else{//������ʾ��ASCII�붼���ո�
						debug(" ");
					}
				}
				debug("\r\n");
			}
		}
		debug("-------------------------------------------------------\r\n");//���ĵ��ߡ�
		debug("total:%lu\r\n",((u32)k*128));//��ȡ����ͳ�ơ�
	}
}
/*�������۵�ר��**************************************************************/#endif
/*�������۵�ר��***********************�Զ���ʼ��ģ��********/#if AT24CXX_AUTO_INIT_EN
/*-------------------------------------------------------
AT24ϵ�е��ֽڵ�ַ�ͺŵ�д������ֻΪ��check�������ڡ�
-------------------------------------------------------*/
u8 at24_write_char(u8 iic,u8 addr,u8 dat){
	soft_iic_start();			//IIC��ʼ��
	soft_iic_write(iic);	//��дIIC������ַ��
	if(soft_iic_read_ack()!=0){	//��ACK��
		soft_iic_stop();		//IICֹͣ��
		return AT24_ERROR_NOACK;//���û��ACK��˵�����������ڡ����ش�����-�޻�Ӧ����
	}
	soft_iic_write(addr);	//��дEEPROM�ڴ��ַ��
	if(soft_iic_read_ack()!=0){	//��ACK��
		soft_iic_stop();		//IICֹͣ��
		return AT24_ERROR_NOACK;//���û��ACK��˵�����������ڡ����ش�����-�޻�Ӧ����
	}
	soft_iic_write(dat);	//д�����ݡ�
	if(soft_iic_read_ack()!=0){	//��ACK��
		soft_iic_stop();		//IICֹͣ��
		return AT24_ERROR_SEND;//���û��ACK��˵��ͨ�ų������⡣���ش�����-���ʹ���
	}	
	soft_iic_stop();//IICֹͣ��
	return AT24_OK;//ɶ��û�оͷ���������
}
/*-------------------------------------------------------
AT24ϵ�е��ֽڵ�ַ�ͺŵĶ�������ֻΪ��check�������ڡ�
-------------------------------------------------------*/
u8 at24_read_char(u8 iic,u8 addr,u8 * dat){
 	soft_iic_start();			//IIC��ʼ��
	soft_iic_write(iic);	//��дIIC������ַ��
	if(soft_iic_read_ack()!=0){	//��ACK��
		soft_iic_stop();		//IICֹͣ��
		return AT24_ERROR_NOACK;//���û��ACK��˵�����������ڡ����ش�����-�޻�Ӧ����
	}
	soft_iic_write(addr);
	if(soft_iic_read_ack()!=0){	//��ACK��
		soft_iic_stop();		//IICֹͣ��
		return AT24_ERROR_NOACK;//���û��ACK��˵�����������ڡ����ش�����-�޻�Ӧ����
	}
	soft_iic_start();			//IIC���¿�ʼ�����Ƕ�����������
	soft_iic_write(iic+1);	//дIIC������ַ�������ö�ȡλ��
	if(soft_iic_read_ack()!=0){	//��ACK��
		soft_iic_stop();		//IICֹͣ��
		return AT24_ERROR_NOACK;//���û��ACK��˵�����������ڡ����ش�����-�޻�Ӧ����
	}
	*dat=soft_iic_read();	//��ȡ���ݡ�
	soft_iic_write_nack();//ֹͣ��ȡ�˾ͷ���NOACK��
	soft_iic_stop();//IICֹͣ��
	return AT24_OK;//ɶ��û�оͷ���������
}
/*-------------------------------------------------------
AT24ϵ��˫�ֽڵ�ַ�ͺŵ�д������ֻΪ��check�������ڡ�
-------------------------------------------------------*/
u8 at24_write_int(u8 iic,u16 addr,u8 dat){
	soft_iic_start();			//IIC��ʼ��
	soft_iic_write(iic);	//��дIIC������ַ��
	if(soft_iic_read_ack()!=0){	//��ACK��
		soft_iic_stop();		//IICֹͣ��
		return AT24_ERROR_NOACK;//���û��ACK��˵�����������ڡ����ش�����-�޻�Ӧ����
	}
	soft_iic_write(addr/256);	//��дEEPROM�ڴ��ַ��
	if(soft_iic_read_ack()!=0){	//��ACK��
		soft_iic_stop();		//IICֹͣ��
		return AT24_ERROR_NOACK;//���û��ACK��˵�����������ڡ����ش�����-�޻�Ӧ����
	}
	soft_iic_write(addr%256);	//��дEEPROM�ڴ��ַ��
	if(soft_iic_read_ack()!=0){	//��ACK��
		soft_iic_stop();		//IICֹͣ��
		return AT24_ERROR_NOACK;//���û��ACK��˵�����������ڡ����ش�����-�޻�Ӧ����
	}
	soft_iic_write(dat);	//д�����ݡ�
	if(soft_iic_read_ack()!=0){	//��ACK��
		soft_iic_stop();		//IICֹͣ��
		return AT24_ERROR_SEND;//���û��ACK��˵��ͨ�ų������⡣���ش�����-���ʹ���
	}	
	soft_iic_stop();//IICֹͣ��
	return AT24_OK;//ɶ��û�оͷ���������
}
/*-------------------------------------------------------
AT24ϵ��˫�ֽڵ�ַ�ͺŵĶ�������ֻΪ��check�������ڡ�
-------------------------------------------------------*/
u8 at24_read_int(u8 iic,u16 addr,u8 * dat){
 	soft_iic_start();			//IIC��ʼ��
	soft_iic_write(iic);	//��дIIC������ַ��
	if(soft_iic_read_ack()!=0){	//��ACK��
		soft_iic_stop();		//IICֹͣ��
		return AT24_ERROR_NOACK;//���û��ACK��˵�����������ڡ����ش�����-�޻�Ӧ����
	}
	soft_iic_write(addr/256);
	if(soft_iic_read_ack()!=0){	//��ACK��
		soft_iic_stop();		//IICֹͣ��
		return AT24_ERROR_NOACK;//���û��ACK��˵�����������ڡ����ش�����-�޻�Ӧ����
	}
	soft_iic_write(addr%256);
	if(soft_iic_read_ack()!=0){	//��ACK��
		soft_iic_stop();		//IICֹͣ��
		return AT24_ERROR_NOACK;//���û��ACK��˵�����������ڡ����ش�����-�޻�Ӧ����
	}
	soft_iic_start();			//IIC���¿�ʼ�����Ƕ�����������
	soft_iic_write(iic+1);	//дIIC������ַ�������ö�ȡλ��
	if(soft_iic_read_ack()!=0){	//��ACK��
		soft_iic_stop();		//IICֹͣ��
		return AT24_ERROR_NOACK;//���û��ACK��˵�����������ڡ����ش�����-�޻�Ӧ����
	}
	*dat=soft_iic_read();	//��ȡ���ݡ�
	soft_iic_write_nack();//ֹͣ��ȡ�˾ͷ���NOACK��
	soft_iic_stop();//IICֹͣ��
	return AT24_OK;//ɶ��û�оͷ���������
}
/*-------------------------------------------------------
AT24ϵ���ж��ͺź�����ֻΪ��auto_init�������ڡ�
-------------------------------------------------------*/
u8 at24_addr_check(void){
	u8 i,count,addr,save[8];//һ����ʱ������
	count=0;                //ͳ��ֵ���㡣
	for(i=0;i<8;i++){       //eeprom�����8����ַ��
		soft_iic_start();   //��ʼIIC��
		soft_iic_write((i<<1)+0xA0);//����д��8����ַ��
		if(soft_iic_read_ack()==0){ //�ж���û�лظ���
			if(count==0){           //ֻ��ȡ��һ�λظ��ĵ�ַ��
				addr=(i<<1)+0xA0;   //�ѵ�ַ����������
			}
			count++;                //ͳ���ܵ���Ӧ�ĵ�ַ������
		}
		soft_iic_stop();            //ֹͣIIC��
	}
	if(count==8){       //�����8����ַ�Ļ���
		return AT24C16; //˵����AT24C16��
	}
	if(count==4){       //�����4����ַ�Ļ���
		return AT24C08+((addr>>1)&0x04);//˵����AT24C08��ͬʱ��ʣ�µĵ�ַ��������ַ��ȥ��
	}
	if(count==2){       //�����2����ַ�Ļ���
		return AT24C04+((addr>>1)&0x06);//˵����AT24C04��ͬʱ��ʣ�µĵ�ַ��������ַ��ȥ��
	}
	if(count==1){      //���ֻ��1����ַ����ô����Ͷ��ˡ���Ҫ��ϸ�б�
		at24_read_char (addr,127,&save[0]);                 //�ȶ���ַ127��
		at24_read_char (addr,255,&save[1]);                 //�ȶ���ַ255��
		at24_write_char(addr,127,(save[0]+1));delay_ms(10); //Ϊ�˱�֤���ظ�����ԭ��+1��д��ȥ��
		at24_write_char(addr,255,(save[1]+2));delay_ms(10); //Ϊ�˱�֤���ظ�����ԭ��+2��д��ȥ��
		at24_read_char (addr,127,&save[2]);                 //�ٶ���ַ127��
		at24_read_char (addr,255,&save[3]);                 //�ٶ���ַ255��
		if((save[2]==save[3])&&(save[3]==(u8)(save[1]+2))){ //��������127�����ݺ�255��һ�����Һ�255������һ����
			at24_write_char(addr,127,save[0]);delay_ms(10); //˵��255��ַ����Ч�ģ�255�����ݸ�����127����ô��127��ԭ���ݻ�ԭ��
			return AT24C01+((addr>>1)&0x07);                //˵����AT24C01��ͬʱ��ʣ�µĵ�ַ��������ַ��ȥ��
		}else if((save[2]==(u8)(save[0]+1))&&(save[3]==(u8)(save[1]+2))){//������ζ�д�Ķ���һ�����Ҷ���дһ�¡�
			at24_write_char(addr,127,save[0]);delay_ms(10); //˵��������ַ����д���Ҳ��ظ�����ô�Ͱ�ԭ�������ݶ���ԭ��
			at24_write_char(addr,255,save[1]);delay_ms(10); //��ԭ���ݡ�
			return AT24C02+((addr>>1)&0x07);                //˵����AT24C02��ͬʱ��ʣ�µĵ�ַ��������ַ��ȥ��
		}else{//���Ͼ��жϳ��˵��ֽڵ�ַ�������ͺţ����濪ʼ�ж�˫�ֽڵ��ͺš�
			at24_read_int (addr,4095, &i);       //�Ȱ�ԭ��������������
			at24_read_int (addr,8191, &save[0]); //һ����Ϊ�˱���ԭ���ݣ�
			at24_read_int (addr,16383,&save[1]); //��һ����Ҳ��Ϊ��д�����ݵĲ��ظ���
			at24_read_int (addr,32767,&save[2]); //
			at24_read_int (addr,65535,&save[3]); //
			at24_write_int(addr,8191, (save[0]+1));delay_ms(10);//�������������ݣ�
			at24_write_int(addr,16383,(save[1]+2));delay_ms(10);//����һ����ͬ������
			at24_write_int(addr,32767,(save[2]+3));delay_ms(10);//��д��ȥ��
			at24_write_int(addr,65535,(save[3]+4));delay_ms(10);//�Դ�����֤���ظ���	
			at24_read_int (addr,4095,&count);    //Ȼ���ٶ�һ�飬
			at24_read_int (addr,8191,&save[4]);  //���ڱȶ����ݣ�
			at24_read_int (addr,16383,&save[5]); //ͨ���ȶԽ�����ж��ͺš�
			at24_read_int (addr,32767,&save[6]); //
			at24_read_int (addr,65535,&save[7]); //

			//debug("[%02X]-[%02X]-[%02X]-[%02X]-[%02X]\r\n",(u16)i,
			//(u16)(save[0]+1),(u16)(save[1]+2),(u16)(save[2]+3),(u16)(save[3]+4));
			//debug("[%02X]-[%02X]-[%02X]-[%02X]-[%02X]\r\n",(u16)count,
			//(u16)save[4],(u16)save[5],(u16)save[6],(u16)save[7]);
			if((count==save[4])&&(count==(u8)(save[3]+4))){ //���4095�����ݺ�8191��ȣ��ҵ���65535��ֵ��
				at24_write_int(addr,4095,i);delay_ms(10);   //˵��ֻ��4095��ַ��Ч���������������ˡ���ô�Ͱ�4095��ԭ���ݴ��ȥ��
				return AT24C32+((addr>>1)&0x07);            //�����ͺ�AT24C32��ͬʱ����������ַ��
			}else{//���4095�����ݺ�8191�����ݲ���ȣ���ô���������жϡ�
				if((save[4]==save[5])&&(save[4]==(u8)(save[3]+4))){//���8191��16383��������ȣ��ҵ���65535��ֵ��
					at24_write_int(addr,4095,i);delay_ms(10);      //��Ч��ַ��8191�������ı������ˡ���ô�Ͱ�4095��ԭ���ݴ��ȥ��
					at24_write_int(addr,8191,save[0]);delay_ms(10);//8191��ԭ����Ҳ���ȥ��
					return AT24C64+((addr>>1)&0x07);               //�����ͺ�AT24C64��ͬʱ����������ַ��
				}else{//���4095�����ݺ�8191�����ݲ���ȣ�8191��16383������Ҳ����ȣ���ô���������жϡ�
					if((save[5]==save[6])&&(save[5]==(u8)(save[3]+4))){ //���16383��32767��������ȣ��ҵ���65535��ֵ��
						at24_write_int(addr,4095,i);delay_ms(10);       //��Ч��ַ��16383�������ı������ˡ���ô�Ͱ�4095��ԭ���ݴ��ȥ��
						at24_write_int(addr,8191,save[0]);delay_ms(10); //8191��ԭ����Ҳ���ȥ��
						at24_write_int(addr,16383,save[1]);delay_ms(10);//16383��ԭ����Ҳ���ȥ��
						return AT24C128+((addr>>1)&0x07);               //�����ͺ�AT24C128��ͬʱ����������ַ��
					}else{//���4095��8191��16383�������ݻ�����ȣ���ô���������жϡ�
						if((save[6]==save[7])&&(save[6]==(u8)(save[3]+4))){ //���32767��65535��������ȡ�
							at24_write_int(addr,4095,i);delay_ms(10);       //��Ч��ַ��32767�������ı������ˡ���ô�Ͱ�4095��ԭ���ݴ��ȥ��
							at24_write_int(addr,8191,save[0]);delay_ms(10); //8191��ԭ����Ҳ���ȥ��
							at24_write_int(addr,16383,save[1]);delay_ms(10);//16383��ԭ����Ҳ���ȥ��
							at24_write_int(addr,32767,save[2]);delay_ms(10);//32767��ԭ����Ҳ���ȥ��
							return AT24C256+((addr>>1)&0x07);               //�����ͺ�AT24C256��ͬʱ����������ַ��
						}else{//���д������ݶ�������ͬ����ô���е�ַ����Ч����оƬ��AT24C512��
							at24_write_int(addr,4095,i);delay_ms(10);       //4095��ԭ���ݴ��ȥ��
							at24_write_int(addr,8191,save[0]);delay_ms(10); //8191��ԭ����Ҳ���ȥ��
							at24_write_int(addr,16383,save[1]);delay_ms(10);//16383��ԭ����Ҳ���ȥ��
							at24_write_int(addr,32767,save[2]);delay_ms(10);//32767��ԭ����Ҳ���ȥ��
							at24_write_int(addr,65535,save[3]);delay_ms(10);//65535��ԭ����Ҳ���ȥ��
							return AT24C512+((addr>>1)&0x07);               //�����ͺ�AT24C512��ͬʱ����������ַ��
						}
					}
				}
			}
		}
	}
	return AT24CXX;
}
/*-------------------------------------------------------
AT24ϵ�е��Զ���ʼ��������
-------------------------------------------------------*/
void at24_auto_init(at24_def * dev,u8 scl,u8 sda){
	dev->scl=scl;							//��SCL���ű��档
	dev->sda=sda;							//��SDA���ű��档				
	dev->id=soft_iic_init_linkage(scl,sda);	//��ʼ�����š�
	dev->model=at24_addr_check();           //����ͺ���Ϣ�����档
	at24_set_work(dev);						//�л�����������ǰ������
}
/*�������۵�ר��**************************************************************/#endif
