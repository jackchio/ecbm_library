#include "ecbm_core.h"
#if ECBM_EEPROM_EN
/*--------------------------------------��������-----------------------------------*/
u8 eeprom_wait;//EEPROM�ĵȴ�ʱ�䡣
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
eeprom��ʼ��������
-------------------------------------------------------*/
void eeprom_init(void){
	#if  ((ECBM_MCU_MAIN_RAM == 0)||(ECBM_MCU_MAIN_RAM == 1))
	u32 pro,cls;
//7
	pro=ecbm_sys_clk/7;
	cls=ecbm_sys_clk/5000;
//	debug("s=%lu,p=%lu,c=%lu\r\n",ecbm_sys_clk,pro,cls);
	if((pro<166666)&&(pro>90909)&&(cls>111)&&(cls<250)){
		eeprom_wait=7;
		goto eep_end;
	}
//6
	pro=ecbm_sys_clk/14;
	cls=ecbm_sys_clk/10000;
//	debug("s=%lu,p=%lu,c=%lu\r\n",ecbm_sys_clk,pro,cls);
	if((pro<166666)&&(pro>90909)&&(cls>111)&&(cls<250)){
		eeprom_wait=6;
		goto eep_end;
	}
//5
	pro=ecbm_sys_clk/21;
	cls=ecbm_sys_clk/15000;
//	debug("s=%lu,p=%lu,c=%lu\r\n",ecbm_sys_clk,pro,cls);
	if((pro<166666)&&(pro>90909)&&(cls>111)&&(cls<250)){
		eeprom_wait=5;
		goto eep_end;
	}	
//4
	pro=ecbm_sys_clk/42;
	cls=ecbm_sys_clk/30000;
//	debug("s=%lu,p=%lu,c=%lu\r\n",ecbm_sys_clk,pro,cls);
	if((pro<166666)&&(pro>90909)&&(cls>111)&&(cls<250)){
		eeprom_wait=4;
		goto eep_end;
	}	
//3
	pro=ecbm_sys_clk/84;
	cls=ecbm_sys_clk/60000;
//	debug("s=%lu,p=%lu,c=%lu\r\n",ecbm_sys_clk,pro,cls);
	if((pro<166666)&&(pro>90909)&&(cls>111)&&(cls<250)){
		eeprom_wait=3;
		goto eep_end;
	}
//2
	pro=ecbm_sys_clk/140;
	cls=ecbm_sys_clk/100000;
//	debug("s=%lu,p=%lu,c=%lu\r\n",ecbm_sys_clk,pro,cls);
	if((pro<166666)&&(pro>90909)&&(cls>111)&&(cls<250)){
		eeprom_wait=2;
		goto eep_end;
	}	
//1
	pro=ecbm_sys_clk/168;
	cls=ecbm_sys_clk/120000;
//	debug("s=%lu,p=%lu,c=%lu\r\n",ecbm_sys_clk,pro,cls);
	if((pro<166666)&&(pro>90909)&&(cls>111)&&(cls<250)){
		eeprom_wait=1;
		goto eep_end;
	}
//0
	pro=ecbm_sys_clk/301;
	cls=ecbm_sys_clk/215000;
//	debug("s=%lu,p=%lu,c=%lu\r\n",ecbm_sys_clk,pro,cls);
	if((pro<166666)&&(pro>90909)&&(cls>111)&&(cls<250)){
		eeprom_wait=0;
		goto eep_end;
	}	
	eep_end:
	pro=0;
	cls=0;
//	debug("wait=%u\r\n",(u16)eeprom_wait);
	#elif ECBM_MCU_MAIN_RAM == 2
	eeprom_wait=ecbm_sys_clk/1000000;
	IAP_TPS=eeprom_wait;
	eeprom_wait=0;
	#endif
}
/*-------------------------------------------------------
eeprom�رպ�����
-------------------------------------------------------*/
void eeprom_off(){
    IAP_CONTR = 0;   //�ر�IAP����
    IAP_CMD   = 0;   //�������Ĵ���
    IAP_TRIG  = 0;   //��������Ĵ���
    IAP_ADDRH = 0xff;//����ַ���õ���IAP����
    IAP_ADDRL = 0xff;//����ַ���õ���IAP����
}
/*-------------------------------------------------------
eeprom����������
-------------------------------------------------------*/
void eeprom_erase(u16 addr){
	if(addr<ECBM_EEPROM_SIZE){		 //��ַ�ڷ�Χ�ڲŻ����
		IAP_CONTR = eeprom_wait|0x80;//ʹ��IAP
		IAP_CMD   = 3;               //����IAP��������
		IAP_ADDRL = addr;            //����IAP�͵�ַ
		IAP_ADDRH = addr >> 8;       //����IAP�ߵ�ַ
		IAP_TRIG  = 0x5a;            //д��������(0x5a)
		IAP_TRIG  = 0xa5;            //д��������(0xa5)
		_nop_();                     //���Եȴ�һ��
		eeprom_off();                //�ر�IAP����
	}
}
/*-------------------------------------------------------
eepromд������
-------------------------------------------------------*/
void eeprom_write(u16 addr,u8 dat){
	if(addr<ECBM_EEPROM_SIZE){		 //��ַ�ڷ�Χ�ڲŻ�д��
		IAP_CONTR = eeprom_wait|0x80;//ʹ��IAP
		IAP_CMD   = 2;               //����IAPд����
		IAP_ADDRL = addr;            //����IAP�͵�ַ
		IAP_ADDRH = addr >> 8;       //����IAP�ߵ�ַ
		IAP_DATA  = dat;             //дIAP����
		IAP_TRIG  = 0x5a;            //д��������(0x5a)
		IAP_TRIG  = 0xa5;            //д��������(0xa5)
		_nop_();                     //���Եȴ�һ��
		eeprom_off();                //�ر�IAP����
	}
}
/*-------------------------------------------------------
eeprom��������
-------------------------------------------------------*/
u8 eeprom_read(u16 addr){
    u8 dat;
	if(addr>=ECBM_EEPROM_SIZE)return 0xff;//��ַ����֮�󣬷���FF
    IAP_CONTR = eeprom_wait|0x80;    //ʹ��IAP
    IAP_CMD   = 1;                   //����IAP������
    IAP_ADDRL = addr;                //����IAP�͵�ַ
    IAP_ADDRH = addr >> 8;           //����IAP�ߵ�ַ
    IAP_TRIG  = 0x5a;                //д��������(0x5a)
    IAP_TRIG  = 0xa5;                //д��������(0xa5)
    _nop_();                         //���Եȴ�һ��
    dat       = IAP_DATA;            //��IAP����
    eeprom_off();                    //�ر�IAP����
    return dat;
}
#if ECBM_EEPROM_EX_EN
/*-------------------------------------------------------
eeprom�����������(extension)��
-------------------------------------------------------*/
void eeprom_read_ex(u16 addr,u8 * dat,u16 num){
	u16 i;
	for(i=0;i<num;i++){
		dat[i]=eeprom_read(addr+i);
	}
}
/*-------------------------------------------------------
eepromд���������(extension)��
-------------------------------------------------------*/

u8 xdata eeprom_buf[512];//�����������ݵĻ���
void eeprom_write_ex(u16 addr,u8 * dat,u16 num){
	
	u16 num_yu;				//ʣ��Ҫд�����ݵ�������
	u16 area;				//����������
	u16 area_addr_yu;		//�������µĵ�ַ������
	u16 area_start_addr;	//������ʼ��ַ��
	u16 area_stop_addr;		//����������ַ��
	u16 addr_offset;		//��ַƫ�ơ�
	u16 dat_offset=0;		//����ƫ�ơ�
	u16 address;			//������ַ��
	u16 i;					//��ʱ������
	address=addr;			//����ַ������ֵ��������ַ��
	num_yu=num;				//������������ֵΪʣ��������
	do{
		area=address>>9;						//��ȡ������
		area_start_addr=(area<<9);				//��ȡ������ʼ�ĵ�ַ��
		area_stop_addr=(area<<9)+512;			//��ȡ����ĩβ�ĵ�ַ��
		area_addr_yu=area_stop_addr-address;	//ĩβ��ַ��������ַ���õ���ַʣ��������
		if(num_yu<=area_addr_yu){				//���Ҫд�������ڵ�ַʣ��������˵�����ÿ�������
			for(i=0;i<512;i++){					//��ԭ�������ݶ�������
				eeprom_buf[i]=eeprom_read(area_start_addr+i);
			}
			eeprom_erase(area_start_addr);		//���������
			addr_offset=address-area_start_addr;//��ȡ��ַƫ�ơ�
			for(i=0;i<num_yu;i++){				//�޸����ݡ�
				eeprom_buf[addr_offset+i]=dat[dat_offset+i];
			}
			for(i=0;i<512;i++){					//������д��ȥ��
				eeprom_write(area_start_addr+i,eeprom_buf[i]);
			}
			break;								//д�������ѭ����
		}else{									//���Ҫд�������ڵ�ַʣ������
			for(i=0;i<512;i++){					//��ԭ�������ݶ�������
				eeprom_buf[i]=eeprom_read(area_start_addr+i);
			}
			eeprom_erase(area_start_addr);		//���������
			addr_offset=address-area_start_addr;//��ȡ��ַƫ�ơ�
			for(i=0;i<area_addr_yu;i++){		//�޸����ݡ�
				eeprom_buf[addr_offset+i]=dat[dat_offset+i];
			}
			for(i=0;i<512;i++){					//������д��ȥ��
				eeprom_write(area_start_addr+i,eeprom_buf[i]);
			}
			address+=area_addr_yu;				//д�˶��٣���ַ�ͼӶ��١�
			num_yu -=area_addr_yu;				//ʣ��������Ҫ�����١�
			dat_offset+=area_addr_yu;			//�����ƫ�ƾͼӶ��١�
		}
	}while(1);	
}
#endif
#endif
