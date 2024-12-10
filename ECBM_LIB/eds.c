#include "ecbm_core.h"  //ͳһ���غ���ͷ�ļ�
#if (ECBM_EDS_LIB_EN)   //��鱾����û�б�ʹ��
/*--------------------------------------������-----------------------------------*/
/*-------------------------------------------------------
eds��麯����
-------------------------------------------------------*/
u8 eds_check(u16 addr){
    u8 dat_u8,_dat_u8;
    dat_u8=eeprom_read(addr+0);         //������һ���ֽڵ���Ϣ��
    if(dat_u8!='E')return EDS_ERR_NULL; //��һ���ֽڲ���E,˵������EDS��
    dat_u8=eeprom_read(addr+1);         //��һ���ֽ���ȷ�Ļ��������ڶ����ֽڵ���Ϣ��
    if(dat_u8!='D')return EDS_ERR_NULL; //�ڶ����ֽ��ǲ���D,����D˵������EDS��
    dat_u8=eeprom_read(addr+2);         //�ڶ����ֽ���ȷ�Ļ��������������ֽڵ���Ϣ��
    if(dat_u8!='S')return EDS_ERR_NULL; //�������ֽ��ǲ���S,����S˵������EDS��
    dat_u8 =eeprom_read(addr+3);        //����ID��
    _dat_u8=eeprom_read(addr+4);        //����ID���롣
    if((dat_u8==(~_dat_u8))&&(dat_u8==(u8)(addr/512))){//ID��ʽҲ��ȷ�Ļ��������һ���ϸ��EDS��
        return EDS_OK;  //����OK��
    }
    return EDS_ERR_ID;  //�ߵ����˵��������ID��֤��ͨ��������ID����
}
/*-------------------------------------------------------
eds����������
-------------------------------------------------------*/
void eds_erase(u8 sector_start,u8 sector_szie){
    u8 i_u8;
    for(i_u8=0;i_u8<sector_szie;i_u8++){        //��ʼ����ʱ�򣬾�Ҫ�����õ��������ˡ�
        eeprom_erase((u16)(sector_start+i_u8)*512);//�����ַ���������õ�ַ��
    }
}
/*-------------------------------------------------------
eds��ʼ��������
-------------------------------------------------------*/
u8 eds_init(u8 sector_start,u8 sector_szie,u16 pack_len){
    u16 addr_u16;
    if(sector_start>128)return EDS_ERR_SECTOR; //����������ʼ��ַ��Ҫ����128����Ϊ��ַ������128*512=65536��
    if(sector_szie >128)return EDS_ERR_SECTOR; //����������Ҫ����128��������������128*512=65536��
    if(sector_szie ==0 )return EDS_ERR_SECTOR; //��������Ҳ������0��
    addr_u16=sector_start*512;      //��ȡ��ʼ��ַ��
    if(eds_check(addr_u16)!=EDS_OK){//���õ�ַ�Ƿ���EDS��
        eds_erase(sector_start,sector_szie);    //û�оͲ�����
        eeprom_write(addr_u16+0,'E');           //д���ʶ����
        eeprom_write(addr_u16+1,'D');
        eeprom_write(addr_u16+2,'S');
        eeprom_write(addr_u16+3, sector_start); //д�����ID��
        eeprom_write(addr_u16+4,~sector_start); //д��ID�ķ��롣
        eeprom_write(addr_u16+5,sector_szie);   //д����������������
        eeprom_write(addr_u16+6,(u8)(pack_len>>8));//д����ĳ��ȡ�
        eeprom_write(addr_u16+7,(u8)(pack_len   ));
        return EDS_DATA_VOID;                   //������֮�󣬴�ʱEDS�������ݡ�
    }
    return EDS_OK;
}
/*-------------------------------------------------------
eds���ݶԱȺ�����
-------------------------------------------------------*/
u8 eds_compare(u16 addr,u8 * buf,u16 len){
    u16 i_u16,data_sum_u16,read_addr_u16,data_sum_check_u16;
    u8  res_u8,err_count_u8;
    data_sum_u16=0; //У��������㡣
    err_count_u8=0; //����ͳ�Ʊ������㡣
    read_addr_u16=addr;//�Լӱ�������ֵ�ϵ�ַ��ֵ��
    for(i_u16=0;i_u16<len;i_u16++){//���len�����ݡ�
        res_u8=eeprom_read(read_addr_u16++);//�������ݡ�
        if(buf[i_u16]!=res_u8){
            err_count_u8++;//���ݺ�д��Ĳ�һ�£���ͳ�Ʋ�һ�µĸ�����
        }
        data_sum_u16+=res_u8;//����У��͡�
    }
    data_sum_check_u16 =(u16)(eeprom_read(read_addr_u16++));//��ȡ��ŵ�У��͡�
    data_sum_check_u16|=(u16)(eeprom_read(read_addr_u16)<<8);
    if(err_count_u8){//������ݴ��������Ϊ�㣬
        return EDS_ERR_DATA;//�������ݳ���
    }else{//����˵����������ȷ�ġ�
        if(data_sum_u16!=data_sum_check_u16){//��ʱ�ж�У��Բ��ԣ�
            return EDS_ERR_SUM;//У�鲻�Ծͷ���У��ʹ���
        }else{//���У����ȷ��
            return EDS_OK;//��������OK��
        }
    }
}
/*-------------------------------------------------------
eds��ʶ�����Һ�����
-------------------------------------------------------*/
u16 eds_mark_find(u16 addr){
    u8 i_u8,j_u8,k_u8,res_u8;
    u16 i_u16,count_u16;
    i_u16=addr+8;
    count_u16=0;
    for(i_u8=0;i_u8<56;i_u8++){//������������ݡ�
        res_u8=eeprom_read(i_u16++);//��һ���ֽڡ�
        k_u8=res_u8;
        for(j_u8=0;j_u8<8;j_u8++){
            if((k_u8&0x80)==0)count_u16++;
            k_u8<<=1;
        }
        if(res_u8!=0x00)break;
    }
    return count_u16;
}
/*-------------------------------------------------------
edsд������
-------------------------------------------------------*/
u8 eds_write(u8 sector_start,u8 * buf){
    u16 start_addr_u16; //��ʼ��ַ��
    u16 limit_addr_u16; //���Ƶ�ַ��
    u16 data_len_u16;   //�������ݰ��ĳ��ȡ�
    u16 count_u16;      //���ݰ��ĸ�����
    u16 write_addr_u16; //д���ַ��
    u16 mark_addr_u16;  //��ǵ�ַ��
    u16 data_sum_u16;   //��ǰ���ݰ��ĺ͡�
    u8  read_buf_u8a[8];//��Ϣ�����档
    u8  res_u8,i_u8;//һЩ��ʱ������
    u8  mark_data_u8;   //������ݡ�
    u8 code list2list[8]={0x7F,0x3F,0x1F,0x0F,0x07,0x03,0x01,0x00};
    start_addr_u16=(u16)(sector_start)*512; //�������ʼ��ַ��
    res_u8=eds_check(start_addr_u16);       //���EDS��
    if(res_u8!=EDS_OK){                     //�����������
        return res_u8;                      //���ش����롣
    }                                       //�����������ߡ�
    for(i_u8=0;i_u8<8;i_u8++){              //Ҫ����Ϣ��������
        read_buf_u8a[i_u8]=eeprom_read(start_addr_u16+(u16)(i_u8));
    }
    limit_addr_u16=start_addr_u16+(u16)(read_buf_u8a[5])*512;//�ϳ����Ƶ�ַ��
    data_len_u16=(u16)(read_buf_u8a[6])*256+(u16)(read_buf_u8a[7]);//�ϳɰ����ȡ�

    count_u16    =eds_mark_find(start_addr_u16);
    mark_addr_u16=start_addr_u16+8+(count_u16/8);
    mark_data_u8 =list2list[count_u16%8];

    if(count_u16){//��ǰ�����ݵ�ʱ�򣬲���Ҫ�Ƚϡ�
        if(eds_compare(start_addr_u16+64+(count_u16-1)*(data_len_u16+2),buf,data_len_u16)==EDS_OK){//������ݱȶԳɹ���
            return EDS_DATA_EXISTS;//���������Ѵ�������ȡ�����Ĳ���Ҳû��Ҫ�����ˡ�
        }
    }
    write_addr_u16=start_addr_u16+64+count_u16*(data_len_u16+2);//ƴ�ӳ�д���ַ������У�飩��
    if((write_addr_u16>=limit_addr_u16)||((limit_addr_u16-write_addr_u16)<data_len_u16)){  
    //���д���ַ���������ˣ�����ʣ��Ŀռ䲻��д��
        eds_erase(read_buf_u8a[3],read_buf_u8a[5]); //���Ƭ����
        for(i_u8=0;i_u8<8;i_u8++){                  //��ԭ��Ϣ����
            eeprom_write(start_addr_u16+(u16)(i_u8),read_buf_u8a[i_u8]);
        }
        eeprom_write(start_addr_u16+8,0x7F);        //���ϵ�һ�����ݵı�ǡ�
        write_addr_u16=start_addr_u16+64;           //����д���ַ��
    }else{//�����ַ��ȷ���ռ�Ҳ�㹻��
        eeprom_write(mark_addr_u16,mark_data_u8);   //�������д�������ݡ�
    }

    data_sum_u16=0;//����У��ͱ�����
    for(count_u16=0;count_u16<data_len_u16;count_u16++){    //д�����ݡ�
        eeprom_write(write_addr_u16+count_u16,buf[count_u16]);
        data_sum_u16+=buf[count_u16];
    }
    eeprom_write(write_addr_u16+count_u16+0,(u8)(data_sum_u16));//д��У�顣
    eeprom_write(write_addr_u16+count_u16+1,(u8)(data_sum_u16>>8));

    return eds_compare(write_addr_u16,buf,data_len_u16);//�Ա�д������ݣ����ؽ����
}
/*-------------------------------------------------------
eds��������
-------------------------------------------------------*/
u8 eds_read(u8 sector_start,u8 * buf){
    u16 start_addr_u16; //��ʼ��ַ��
    u16 limit_addr_u16; //���Ƶ�ַ��
    u16 data_len_u16;   //���ݰ��ĳ��ȡ�
    u16 count_u16;      //ͳ�Ƹ�����
    u16 read_addr_u16;  //��ȡ��ַ��
    u16 data_sum_u16;//���㻺���У��͡�
    u16 data_sum_check_u16;//�洢��У��͡�
    u16 i_u16;          //��ʱ������
    u8  read_buf_u8a[8];//��Ϣ�����档
    u8  res_u8,i_u8;//һЩ��ʱ������
    start_addr_u16=(u16)(sector_start)*512; //�������ʼ��ַ��
    res_u8=eds_check(start_addr_u16);       //���EDS��
    if(res_u8!=EDS_OK){                     //�����������
        return res_u8;                      //���ش����롣
    }                                       //�����������ߡ�
    for(i_u8=0;i_u8<8;i_u8++){              //Ҫ����Ϣ��������
        read_buf_u8a[i_u8]=eeprom_read(start_addr_u16+(u16)(i_u8));
    }
    limit_addr_u16=start_addr_u16+(u16)(read_buf_u8a[5])*512;//�ϳ����Ƶ�ַ��
    data_len_u16  =(u16)(read_buf_u8a[6])*256+(u16)(read_buf_u8a[7]);//�ϳɰ����ȡ�
    count_u16     =eds_mark_find(start_addr_u16);
    for(i_u8=0;i_u8<EDS_ERROR_SUM_HANDLING;i_u8++){//���5�εĳ���
        if(count_u16==0)return EDS_DATA_VOID;//�����������ѭ��֮�����ͳ��ֵ����0����˵��û�����ݡ�
        read_addr_u16=start_addr_u16+64+(count_u16-1)*(data_len_u16+2);//ƴ�ӳ���ȡ��ַ��
        data_sum_u16=0;
        for(i_u16=0;i_u16<data_len_u16;i_u16++){//�������ݡ�
            buf[i_u16]=eeprom_read(read_addr_u16++);
            data_sum_u16+=buf[i_u16];
        }
        data_sum_check_u16 =(u16)(eeprom_read(read_addr_u16++));
        data_sum_check_u16|=(u16)(eeprom_read(read_addr_u16)<<8);
        if(data_sum_u16==data_sum_check_u16){
            if(i_u8==0){//����ǵ�һ�ζ�ȡ��
                return EDS_OK;  //���ض�ȡ�ɹ���
            }else{//������ǵ�һ�ζ�ȡ��
                return EDS_WAR_DATA;  //���ض�ȡ�ɹ�,��ʾ���ݲ������°档
            }
        }
        count_u16--;//���������Ĳ�����û���˳�������˵��Ŀǰ����������Ҫ�ع����ݡ�
    }//5�γ��Թ���������ݻ�����ȷ��
    return EDS_ERR_SUM;//����ʾУ��Ͳ�ƥ�䡣    
}
#endif  //���������#ifndef��ϳ�һ������Ρ�
        //��һ������Ϊ��β��