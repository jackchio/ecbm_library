#include "ecbm_core.h"  //统一加载核心头文件
#if (ECBM_EDS_LIB_EN)   //检查本库有没有被使能
/*--------------------------------------程序定义-----------------------------------*/
/*-------------------------------------------------------
eds检查函数。
-------------------------------------------------------*/
u8 eds_check(u16 addr){
    u8 dat_u8,_dat_u8;
    dat_u8=eeprom_read(addr+0);         //读出第一个字节的信息，
    if(dat_u8!='E')return EDS_ERR_NULL; //第一个字节不是E,说明不是EDS。
    dat_u8=eeprom_read(addr+1);         //第一个字节正确的话，读出第二个字节的信息。
    if(dat_u8!='D')return EDS_ERR_NULL; //第二个字节是不是D,不是D说明不是EDS。
    dat_u8=eeprom_read(addr+2);         //第二个字节正确的话，读出第三个字节的信息。
    if(dat_u8!='S')return EDS_ERR_NULL; //第三个字节是不是S,不是S说明不是EDS。
    dat_u8 =eeprom_read(addr+3);        //读出ID，
    _dat_u8=eeprom_read(addr+4);        //还有ID反码。
    if((dat_u8==(~_dat_u8))&&(dat_u8==(u8)(addr/512))){//ID格式也正确的话，这就是一个合格的EDS。
        return EDS_OK;  //返回OK。
    }
    return EDS_ERR_ID;  //走到这里，说明是最后的ID验证不通过，返回ID错误。
}
/*-------------------------------------------------------
eds擦除函数。
-------------------------------------------------------*/
void eds_erase(u8 sector_start,u8 sector_szie){
    u8 i_u8;
    for(i_u8=0;i_u8<sector_szie;i_u8++){        //初始化的时候，就要擦除用到的扇区了。
        eeprom_erase((u16)(sector_start+i_u8)*512);//计算地址，并擦除该地址。
    }
}
/*-------------------------------------------------------
eds初始化函数。
-------------------------------------------------------*/
u8 eds_init(u8 sector_start,u8 sector_szie,u16 pack_len){
    u16 addr_u16;
    if(sector_start>128)return EDS_ERR_SECTOR; //限制扇区起始地址不要超过128，因为地址不超过128*512=65536。
    if(sector_szie >128)return EDS_ERR_SECTOR; //限制数量不要超过128，即总数不超过128*512=65536。
    if(sector_szie ==0 )return EDS_ERR_SECTOR; //扇区数量也不能是0。
    addr_u16=sector_start*512;      //获取开始地址。
    if(eds_check(addr_u16)!=EDS_OK){//检查该地址是否有EDS。
        eds_erase(sector_start,sector_szie);    //没有就擦除。
        eeprom_write(addr_u16+0,'E');           //写入标识符。
        eeprom_write(addr_u16+1,'D');
        eeprom_write(addr_u16+2,'S');
        eeprom_write(addr_u16+3, sector_start); //写入管理ID。
        eeprom_write(addr_u16+4,~sector_start); //写入ID的反码。
        eeprom_write(addr_u16+5,sector_szie);   //写入管理的扇区数量。
        eeprom_write(addr_u16+6,(u8)(pack_len>>8));//写入包的长度。
        eeprom_write(addr_u16+7,(u8)(pack_len   ));
        return EDS_DATA_VOID;                   //重置了之后，此时EDS内无数据。
    }
    return EDS_OK;
}
/*-------------------------------------------------------
eds数据对比函数。
-------------------------------------------------------*/
u8 eds_compare(u16 addr,u8 * buf,u16 len){
    u16 i_u16,data_sum_u16,read_addr_u16,data_sum_check_u16;
    u8  res_u8,err_count_u8;
    data_sum_u16=0; //校验变量清零。
    err_count_u8=0; //错误统计变量清零。
    read_addr_u16=addr;//自加变量被赋值上地址的值。
    for(i_u16=0;i_u16<len;i_u16++){//检查len个数据。
        res_u8=eeprom_read(read_addr_u16++);//读出数据。
        if(buf[i_u16]!=res_u8){
            err_count_u8++;//数据和写入的不一致，就统计不一致的个数。
        }
        data_sum_u16+=res_u8;//计算校验和。
    }
    data_sum_check_u16 =(u16)(eeprom_read(read_addr_u16++));//读取存放的校验和。
    data_sum_check_u16|=(u16)(eeprom_read(read_addr_u16)<<8);
    if(err_count_u8){//如果数据错误计数不为零，
        return EDS_ERR_DATA;//返回数据出错。
    }else{//否则说明数据是正确的。
        if(data_sum_u16!=data_sum_check_u16){//此时判断校验对不对，
            return EDS_ERR_SUM;//校验不对就返回校验和错误。
        }else{//如果校验正确，
            return EDS_OK;//返回数据OK。
        }
    }
}
/*-------------------------------------------------------
eds标识区查找函数。
-------------------------------------------------------*/
u16 eds_mark_find(u16 addr){
    u8 i_u8,j_u8,k_u8,res_u8;
    u16 i_u16,count_u16;
    i_u16=addr+8;
    count_u16=0;
    for(i_u8=0;i_u8<56;i_u8++){//读标记区的数据。
        res_u8=eeprom_read(i_u16++);//读一个字节。
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
eds写函数。
-------------------------------------------------------*/
u8 eds_write(u8 sector_start,u8 * buf){
    u16 start_addr_u16; //开始地址。
    u16 limit_addr_u16; //限制地址。
    u16 data_len_u16;   //单个数据包的长度。
    u16 count_u16;      //数据包的个数。
    u16 write_addr_u16; //写入地址。
    u16 mark_addr_u16;  //标记地址。
    u16 data_sum_u16;   //当前数据包的和。
    u8  read_buf_u8a[8];//信息区缓存。
    u8  res_u8,i_u8;//一些临时变量。
    u8  mark_data_u8;   //标记数据。
    u8 code list2list[8]={0x7F,0x3F,0x1F,0x0F,0x07,0x03,0x01,0x00};
    start_addr_u16=(u16)(sector_start)*512; //计算出开始地址。
    res_u8=eds_check(start_addr_u16);       //检查EDS。
    if(res_u8!=EDS_OK){                     //如果不正常，
        return res_u8;                      //返回错误码。
    }                                       //正常就往下走。
    for(i_u8=0;i_u8<8;i_u8++){              //要读信息区出来。
        read_buf_u8a[i_u8]=eeprom_read(start_addr_u16+(u16)(i_u8));
    }
    limit_addr_u16=start_addr_u16+(u16)(read_buf_u8a[5])*512;//合成限制地址。
    data_len_u16=(u16)(read_buf_u8a[6])*256+(u16)(read_buf_u8a[7]);//合成包长度。

    count_u16    =eds_mark_find(start_addr_u16);
    mark_addr_u16=start_addr_u16+8+(count_u16/8);
    mark_data_u8 =list2list[count_u16%8];

    if(count_u16){//当前有数据的时候，才需要比较。
        if(eds_compare(start_addr_u16+64+(count_u16-1)*(data_len_u16+2),buf,data_len_u16)==EDS_OK){//如果数据比对成功，
            return EDS_DATA_EXISTS;//返回数据已存在且相等。下面的操作也没必要继续了。
        }
    }
    write_addr_u16=start_addr_u16+64+count_u16*(data_len_u16+2);//拼接出写入地址（加上校验）。
    if((write_addr_u16>=limit_addr_u16)||((limit_addr_u16-write_addr_u16)<data_len_u16)){  
    //如果写入地址超过限制了，或者剩余的空间不够写。
        eds_erase(read_buf_u8a[3],read_buf_u8a[5]); //清除片区。
        for(i_u8=0;i_u8<8;i_u8++){                  //还原信息区。
            eeprom_write(start_addr_u16+(u16)(i_u8),read_buf_u8a[i_u8]);
        }
        eeprom_write(start_addr_u16+8,0x7F);        //打上第一个数据的标记。
        write_addr_u16=start_addr_u16+64;           //重置写入地址。
    }else{//如果地址正确，空间也足够。
        eeprom_write(mark_addr_u16,mark_data_u8);   //往标记区写入标记数据。
    }

    data_sum_u16=0;//清零校验和变量。
    for(count_u16=0;count_u16<data_len_u16;count_u16++){    //写入数据。
        eeprom_write(write_addr_u16+count_u16,buf[count_u16]);
        data_sum_u16+=buf[count_u16];
    }
    eeprom_write(write_addr_u16+count_u16+0,(u8)(data_sum_u16));//写入校验。
    eeprom_write(write_addr_u16+count_u16+1,(u8)(data_sum_u16>>8));

    return eds_compare(write_addr_u16,buf,data_len_u16);//对比写入的数据，返回结果。
}
/*-------------------------------------------------------
eds读函数。
-------------------------------------------------------*/
u8 eds_read(u8 sector_start,u8 * buf){
    u16 start_addr_u16; //开始地址。
    u16 limit_addr_u16; //限制地址。
    u16 data_len_u16;   //数据包的长度。
    u16 count_u16;      //统计个数。
    u16 read_addr_u16;  //读取地址。
    u16 data_sum_u16;//计算缓存的校验和。
    u16 data_sum_check_u16;//存储的校验和。
    u16 i_u16;          //临时变量。
    u8  read_buf_u8a[8];//信息区缓存。
    u8  res_u8,i_u8;//一些临时变量。
    start_addr_u16=(u16)(sector_start)*512; //计算出开始地址。
    res_u8=eds_check(start_addr_u16);       //检查EDS。
    if(res_u8!=EDS_OK){                     //如果不正常，
        return res_u8;                      //返回错误码。
    }                                       //正常就往下走。
    for(i_u8=0;i_u8<8;i_u8++){              //要读信息区出来。
        read_buf_u8a[i_u8]=eeprom_read(start_addr_u16+(u16)(i_u8));
    }
    limit_addr_u16=start_addr_u16+(u16)(read_buf_u8a[5])*512;//合成限制地址。
    data_len_u16  =(u16)(read_buf_u8a[6])*256+(u16)(read_buf_u8a[7]);//合成包长度。
    count_u16     =eds_mark_find(start_addr_u16);
    for(i_u8=0;i_u8<EDS_ERROR_SUM_HANDLING;i_u8++){//最多5次的尝试
        if(count_u16==0)return EDS_DATA_VOID;//经过了上面的循环之后，如果统计值还是0，就说明没有数据。
        read_addr_u16=start_addr_u16+64+(count_u16-1)*(data_len_u16+2);//拼接出读取地址。
        data_sum_u16=0;
        for(i_u16=0;i_u16<data_len_u16;i_u16++){//读出数据。
            buf[i_u16]=eeprom_read(read_addr_u16++);
            data_sum_u16+=buf[i_u16];
        }
        data_sum_check_u16 =(u16)(eeprom_read(read_addr_u16++));
        data_sum_check_u16|=(u16)(eeprom_read(read_addr_u16)<<8);
        if(data_sum_u16==data_sum_check_u16){
            if(i_u8==0){//如果是第一次读取，
                return EDS_OK;  //返回读取成功。
            }else{//如果不是第一次读取，
                return EDS_WAR_DATA;  //返回读取成功,提示数据不是最新版。
            }
        }
        count_u16--;//如果在上面的操作里没有退出函数，说明目前数据有误需要回滚数据。
    }//5次尝试过后，如果数据还不正确，
    return EDS_ERR_SUM;//就提示校验和不匹配。    
}
#endif  //和最上面的#ifndef配合成一个程序段。
        //以一个空行为结尾。