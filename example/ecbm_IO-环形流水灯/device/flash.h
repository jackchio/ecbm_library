		    
#include "ecbm.h"

//Mini STM32������
//W25X16 �������� 
//����ԭ��@ALIENTEK
//2010/6/13
//V1.0

#define Set_SPI_FLASH_CS  P12=1
#define Clr_SPI_FLASH_CS  P12=0	 
////////////////////////////////////////////////////////////////////////////
//W25X16��д
#define FLASH_ID 0XEF14
//ָ���
#define W25X_WriteEnable		0x06 
#define W25X_WriteDisable		0x04 
#define W25X_ReadStatusReg		0x05 
#define W25X_WriteStatusReg		0x01 
#define W25X_ReadData			0x03 
#define W25X_FastReadData		0x0B 
#define W25X_FastReadDual		0x3B 
#define W25X_PageProgram		0x02 
#define W25X_BlockErase			0xD8 
#define W25X_SectorErase		0x20 
#define W25X_ChipErase			0xC7 
#define W25X_PowerDown			0xB9 
#define W25X_ReleasePowerDown	0xAB 
#define W25X_DeviceID			0xAB 
#define W25X_ManufactDeviceID	0x90 
#define W25X_JedecDeviceID		0x9F 
extern u8 SPI_FLASH_BUF[4096];
u16  SPI_Flash_ReadID(void);  	    //��ȡFLASH ID
u8	 SPI_Flash_ReadSR(void);        //��ȡ״̬�Ĵ��� 
void SPI_FLASH_Write_SR(u8 sr);  	//д״̬�Ĵ���
void SPI_FLASH_Write_Enable(void);  //дʹ�� 
void SPI_FLASH_Write_Disable(void);	//д����
void SPI_Flash_Write_Page(u8 * pBuffer,u32 WriteAddr,u16 NumByteToWrite);
void SPI_Flash_Read(u8* pBuffer,u32 ReadAddr,u16 NumByteToRead);   //��ȡflash
void SPI_Flash_Write_NoCheck(u8 * pBuffer,u32 WriteAddr,u16 NumByteToWrite);   
void SPI_Flash_Write(u8* pBuffer,u32 WriteAddr,u16 NumByteToWrite);//д��flash
void SPI_Flash_Erase_Chip(void);    	  //��Ƭ����
void SPI_Flash_Erase_Sector(u32 Dst_Addr);//��������
void SPI_Flash_Wait_Busy(void);           //�ȴ�����
void SPI_Flash_PowerDown(void);           //�������ģʽ
void SPI_Flash_WAKEUP(void);			  //����


//4KbytesΪһ��Sector
//16������Ϊ1��Block
//W25X16
//����Ϊ2M�ֽ�,����32��Block,512��Sector 


//��ȡSPI_FLASH��״̬�Ĵ���
//BIT7  6   5   4   3   2   1   0
//SPR   RV  TB BP2 BP1 BP0 WEL BUSY
//SPR:Ĭ��0,״̬�Ĵ�������λ,���WPʹ��
//TB,BP2,BP1,BP0:FLASH����д��������
//WEL:дʹ������
//BUSY:æ���λ(1,æ;0,����)
//Ĭ��:0x00

u8 soft_spi(u8 buf){
	unsigned char i,rx=0;
	for(i=0;i<8;i++){ //����һ����λ���� 
		if((buf<<i)&0x80){
			P13=1;
		}else{
			P13=0;
		}
		P15=1;
		delay_us(5);
		rx<<=1;
		if(P14)
			rx|=0x01;
		else
			rx&=0xfe;
		P15=0;
		
		delay_us(5);
	}
	return rx;
}
u8 SPIx_ReadWriteByte(u8 dat){
	u8 rx;
	rx=soft_spi(dat);
	//rx=spi_send(dat);
	return rx;
}

u8 SPI_Flash_ReadSR(void)   
{  
	u8 byte=0;   
	Clr_SPI_FLASH_CS;                            //ʹ������  
	SPIx_ReadWriteByte(W25X_ReadStatusReg);    //���Ͷ�ȡ״̬�Ĵ�������    
	byte=SPIx_ReadWriteByte(0Xff);             //��ȡһ���ֽ�  
	Set_SPI_FLASH_CS;                            //ȡ��Ƭѡ     
	return byte;   
} 
//дSPI_FLASH״̬�Ĵ���
//ֻ��SPR,TB,BP2,BP1,BP0(bit 7,5,4,3,2)����д!!!
void SPI_FLASH_Write_SR(u8 sr)   
{   
	Clr_SPI_FLASH_CS;                            //ʹ������   
	SPIx_ReadWriteByte(W25X_WriteStatusReg);   //����дȡ״̬�Ĵ�������    
	SPIx_ReadWriteByte(sr);               //д��һ���ֽ�  
	Set_SPI_FLASH_CS;                            //ȡ��Ƭѡ     	      
}   
//SPI_FLASHдʹ��	
//��WEL��λ   
void SPI_FLASH_Write_Enable(void)   
{
	Clr_SPI_FLASH_CS;                            //ʹ������   
    SPIx_ReadWriteByte(W25X_WriteEnable);      //����дʹ��  
	Set_SPI_FLASH_CS;                            //ȡ��Ƭѡ     	      
} 
//SPI_FLASHд��ֹ	
//��WEL����  
void SPI_FLASH_Write_Disable(void)   
{  
	Clr_SPI_FLASH_CS;                            //ʹ������   
    SPIx_ReadWriteByte(W25X_WriteDisable);     //����д��ָֹ��    
	Set_SPI_FLASH_CS;                            //ȡ��Ƭѡ     	      
} 			    
//��ȡоƬID W25X16��ID:0XEF14
u16 SPI_Flash_ReadID(void)
{
	u16 Temp = 0;	  
	Clr_SPI_FLASH_CS;				    
	SPIx_ReadWriteByte(0x90);//���Ͷ�ȡID����	    
	SPIx_ReadWriteByte(0x00); 	    
	SPIx_ReadWriteByte(0x00); 	    
	SPIx_ReadWriteByte(0x00); 	 			   
	Temp|=SPIx_ReadWriteByte(0xFF)<<8;  
	Temp|=SPIx_ReadWriteByte(0xFF);	 
	Set_SPI_FLASH_CS;				    
	return Temp;
}   		    
//��ȡSPI FLASH  
//��ָ����ַ��ʼ��ȡָ�����ȵ�����
//pBuffer:���ݴ洢��
//ReadAddr:��ʼ��ȡ�ĵ�ַ(24bit)
//NumByteToRead:Ҫ��ȡ���ֽ���(���65535)
void SPI_Flash_Read(u8 * pBuffer,u32 ReadAddr,u16 NumByteToRead)   
{ 
 	u16 i;    	
SPI_FLASH_Write_Enable(); 	
	Clr_SPI_FLASH_CS;                            //ʹ������   
    SPIx_ReadWriteByte(W25X_ReadData);         //���Ͷ�ȡ����   
    SPIx_ReadWriteByte((u8)((ReadAddr)>>16));  //����24bit��ַ    
    SPIx_ReadWriteByte((u8)((ReadAddr)>>8));   
    SPIx_ReadWriteByte((u8)ReadAddr);   
    for(i=0;i<NumByteToRead;i++)
	{ 
        pBuffer[i]=SPIx_ReadWriteByte(0XFF);   //ѭ������  
    }
	Set_SPI_FLASH_CS;                            //ȡ��Ƭѡ     	      
}  
//SPI��һҳ(0~65535)��д������256���ֽڵ�����
//��ָ����ַ��ʼд�����256�ֽڵ�����
//pBuffer:���ݴ洢��
//WriteAddr:��ʼд��ĵ�ַ(24bit)
//NumByteToWrite:Ҫд����ֽ���(���256),������Ӧ�ó�����ҳ��ʣ���ֽ���!!!	 
void SPI_Flash_Write_Page(u8 * pBuffer,u32 WriteAddr,u16 NumByteToWrite)
{
 	u16 i;  
    SPI_FLASH_Write_Enable();                  //SET WEL 
	Clr_SPI_FLASH_CS;                            //ʹ������   
    SPIx_ReadWriteByte(W25X_PageProgram);      //����дҳ����   
    SPIx_ReadWriteByte((u8)((WriteAddr)>>16)); //����24bit��ַ    
    SPIx_ReadWriteByte((u8)((WriteAddr)>>8));   
    SPIx_ReadWriteByte((u8)WriteAddr);   
    for(i=0;i<NumByteToWrite;i++){
		SPIx_ReadWriteByte(pBuffer[i]);//ѭ��д��  
	}
	Set_SPI_FLASH_CS;                            //ȡ��Ƭѡ 
	SPI_Flash_Wait_Busy();					   //�ȴ�д�����
} 
//�޼���дSPI FLASH 
//����ȷ����д�ĵ�ַ��Χ�ڵ�����ȫ��Ϊ0XFF,�����ڷ�0XFF��д������ݽ�ʧ��!
//�����Զ���ҳ���� 
//��ָ����ַ��ʼд��ָ�����ȵ�����,����Ҫȷ����ַ��Խ��!
//pBuffer:���ݴ洢��
//WriteAddr:��ʼд��ĵ�ַ(24bit)
//NumByteToWrite:Ҫд����ֽ���(���65535)
//CHECK OK
void SPI_Flash_Write_NoCheck(u8 * pBuffer,u32 WriteAddr,u16 NumByteToWrite)   
{ 			 		 
	u16 pageremain;	   
	pageremain=256-WriteAddr%256; //��ҳʣ����ֽ���		 	    
	if(NumByteToWrite<=pageremain)pageremain=NumByteToWrite;//������256���ֽ�
	while(1)
	{	   
		SPI_Flash_Write_Page(pBuffer,WriteAddr,pageremain);
		if(NumByteToWrite==pageremain)break;//д�������
	 	else //NumByteToWrite>pageremain
		{
			pBuffer+=pageremain;
			WriteAddr+=pageremain;	

			NumByteToWrite-=pageremain;			  //��ȥ�Ѿ�д���˵��ֽ���
			if(NumByteToWrite>256)pageremain=256; //һ�ο���д��256���ֽ�
			else pageremain=NumByteToWrite; 	  //����256���ֽ���
		}
	};	    
} 
//дSPI FLASH  
//��ָ����ַ��ʼд��ָ�����ȵ�����
//�ú�������������!
//pBuffer:���ݴ洢��
//WriteAddr:��ʼд��ĵ�ַ(24bit)
//NumByteToWrite:Ҫд����ֽ���(���65535)  		   
u8 xdata SPI_FLASH_BUF[4096];
void SPI_Flash_Write(u8* pBuffer,u32 WriteAddr,u16 NumByteToWrite)   
{ 
	u32 secpos;
	u16 secoff;
	u16 secremain;	   
 	u16 i;    

	secpos=WriteAddr/4096;//������ַ 0~511 for w25x16
	secoff=WriteAddr%4096;//�������ڵ�ƫ��
	secremain=4096-secoff;//����ʣ��ռ��С   

	if(NumByteToWrite<=secremain)secremain=NumByteToWrite;//������4096���ֽ�
	while(1) 
	{	
		SPI_Flash_Read(SPI_FLASH_BUF,secpos*4096,4096);//������������������
		for(i=0;i<secremain;i++)//У������
		{
			if(SPI_FLASH_BUF[secoff+i]!=0XFF)break;//��Ҫ����  	  
		}
		if(i<secremain)//��Ҫ����
		{
			SPI_Flash_Erase_Sector(secpos);//�����������
			for(i=0;i<secremain;i++)	   //����
			{
				SPI_FLASH_BUF[i+secoff]=pBuffer[i];	  
			}
			SPI_Flash_Write_NoCheck(SPI_FLASH_BUF,secpos*4096,4096);//д����������  

		}else SPI_Flash_Write_NoCheck(pBuffer,WriteAddr,secremain);//д�Ѿ������˵�,ֱ��д������ʣ������. 				   
		if(NumByteToWrite==secremain)break;//д�������
		else//д��δ����
		{
			secpos++;//������ַ��1
			secoff=0;//ƫ��λ��Ϊ0 	 

		   	pBuffer+=secremain;  //ָ��ƫ��
			WriteAddr+=secremain;//д��ַƫ��	   
		   	NumByteToWrite-=secremain;				//�ֽ����ݼ�
			if(NumByteToWrite>4096)secremain=4096;	//��һ����������д����
			else secremain=NumByteToWrite;			//��һ����������д����
		}	 
	};	 	 
}
//��������оƬ
//��Ƭ����ʱ��:
//W25X16:25s 
//W25X32:40s 
//W25X64:40s 
//�ȴ�ʱ�䳬��...
void SPI_Flash_Erase_Chip(void)   
{                                             
    SPI_FLASH_Write_Enable();                  //SET WEL 
    SPI_Flash_Wait_Busy();   
  	Clr_SPI_FLASH_CS;                            //ʹ������   
    SPIx_ReadWriteByte(W25X_ChipErase);        //����Ƭ��������  
	Set_SPI_FLASH_CS;                            //ȡ��Ƭѡ     	      
	SPI_Flash_Wait_Busy();   				   //�ȴ�оƬ��������
}   
//����һ������
//Dst_Addr:������ַ 0~511 for w25x16
//����һ��ɽ��������ʱ��:150ms
void SPI_Flash_Erase_Sector(u32 Dst_Addr)   
{   
	Dst_Addr*=4096;
    SPI_FLASH_Write_Enable();                  //SET WEL 	 
    SPI_Flash_Wait_Busy();   
  	Clr_SPI_FLASH_CS;                            //ʹ������   
    SPIx_ReadWriteByte(W25X_SectorErase);      //������������ָ�� 
    SPIx_ReadWriteByte((u8)((Dst_Addr)>>16));  //����24bit��ַ    
    SPIx_ReadWriteByte((u8)((Dst_Addr)>>8));   
    SPIx_ReadWriteByte((u8)Dst_Addr);  
	Set_SPI_FLASH_CS;                            //ȡ��Ƭѡ     	      
    SPI_Flash_Wait_Busy();   				   //�ȴ��������
}  
//�ȴ�����
void SPI_Flash_Wait_Busy(void)   
{   
	while ((SPI_Flash_ReadSR()&0x01)==0x01);   // �ȴ�BUSYλ���
}  
void s_delay_us(u16 i){
	u8 t;
	while(i--){
		t=50;
		while(t--);
	}
}
//�������ģʽ
void SPI_Flash_PowerDown(void)   
{ 
  	Clr_SPI_FLASH_CS;                            //ʹ������   
    SPIx_ReadWriteByte(W25X_PowerDown);        //���͵�������  
	Set_SPI_FLASH_CS;                            //ȡ��Ƭѡ     	      
    s_delay_us(3);                               //�ȴ�TPD  
}   
//����
void SPI_Flash_WAKEUP(void)   
{  
  	Clr_SPI_FLASH_CS;                            //ʹ������   
    SPIx_ReadWriteByte(W25X_ReleasePowerDown);   //  send W25X_PowerDown command 0xAB    
	Set_SPI_FLASH_CS;                            //ȡ��Ƭѡ     	      
    s_delay_us(3);                               //�ȴ�TRES1
}














