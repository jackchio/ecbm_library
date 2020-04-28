#ifndef __ECBM_H_
#define __ECBM_H_
//V2.1版本
//集成了STC8F、STC8A、STC8G的寄存器。
/////////////////////////////////////////////////

//包含本头文件后,不用另外再包含"REG51.H"



#define     TM2PS       (*(unsigned char volatile xdata *)0xFEA2)
#define     TM3PS       (*(unsigned char volatile xdata *)0xFEA3)
#define     TM4PS       (*(unsigned char volatile xdata *)0xFEA4)



//冲突的部分
sfr         PWMSET      =           0xF1;
sfr         PWMCFG01    =           0xF6;
sfr         PWMCFG23    =           0xF7;
sfr         PWMCFG45    =           0xFE;




#define     P0SR        (*(unsigned char volatile xdata *)0xFE20)
#define     P1SR        (*(unsigned char volatile xdata *)0xFE21)
#define     P2SR        (*(unsigned char volatile xdata *)0xFE22)
#define     P3SR        (*(unsigned char volatile xdata *)0xFE23)
#define     P4SR        (*(unsigned char volatile xdata *)0xFE24)
#define     P5SR        (*(unsigned char volatile xdata *)0xFE25)

#define     P0DR        (*(unsigned char volatile xdata *)0xFE28)
#define     P1DR        (*(unsigned char volatile xdata *)0xFE29)
#define     P2DR        (*(unsigned char volatile xdata *)0xFE2A)
#define     P3DR        (*(unsigned char volatile xdata *)0xFE2B)
#define     P4DR        (*(unsigned char volatile xdata *)0xFE2C)
#define     P5DR        (*(unsigned char volatile xdata *)0xFE2D)



#define     P0IE        (*(unsigned char volatile xdata *)0xFE30)
#define     P1IE        (*(unsigned char volatile xdata *)0xFE31)
#define     P3IE        (*(unsigned char volatile xdata *)0xFE33)




#define     PWM0C       (*(unsigned int  volatile xdata *)0xFF00)
#define     PWM0CH      (*(unsigned char volatile xdata *)0xFF00)
#define     PWM0CL      (*(unsigned char volatile xdata *)0xFF01)
#define     PWM0CKS     (*(unsigned char volatile xdata *)0xFF02)
#define     PWM0TADCH   (*(unsigned char volatile xdata *)0xFF03)
#define     PWM0TADCL   (*(unsigned char volatile xdata *)0xFF04)
#define     PWM0IF      (*(unsigned char volatile xdata *)0xFF05)
#define     PWM0FDCR    (*(unsigned char volatile xdata *)0xFF06)

#define     PWM00T1     (*(unsigned int  volatile xdata *)0xFF10)
#define     PWM00T1H    (*(unsigned char volatile xdata *)0xFF10)
#define     PWM00T1L    (*(unsigned char volatile xdata *)0xFF11)
#define     PWM00T2     (*(unsigned int  volatile xdata *)0xFF12)
#define     PWM00T2H    (*(unsigned char volatile xdata *)0xFF12)
#define     PWM00T2L    (*(unsigned char volatile xdata *)0xFF13)
#define     PWM00CR     (*(unsigned char volatile xdata *)0xFF14)
#define     PWM00HLD    (*(unsigned char volatile xdata *)0xFF15)

#define     PWM01T1     (*(unsigned int  volatile xdata *)0xFF18)
#define     PWM01T1H    (*(unsigned char volatile xdata *)0xFF18)
#define     PWM01T1L    (*(unsigned char volatile xdata *)0xFF19)
#define     PWM01T2     (*(unsigned int  volatile xdata *)0xFF1A)
#define     PWM01T2H    (*(unsigned char volatile xdata *)0xFF1A)
#define     PWM01T2L    (*(unsigned char volatile xdata *)0xFF1B)
#define     PWM01CR     (*(unsigned char volatile xdata *)0xFF1C)
#define     PWM01HLD    (*(unsigned char volatile xdata *)0xFF1D)

#define     PWM02T1     (*(unsigned int  volatile xdata *)0xFF20)
#define     PWM02T1H    (*(unsigned char volatile xdata *)0xFF20)
#define     PWM02T1L    (*(unsigned char volatile xdata *)0xFF21)
#define     PWM02T2     (*(unsigned int volatile xdata *)0xFF22)
#define     PWM02T2H    (*(unsigned char volatile xdata *)0xFF22)
#define     PWM02T2L    (*(unsigned char volatile xdata *)0xFF23)
#define     PWM02CR     (*(unsigned char volatile xdata *)0xFF24)
#define     PWM02HLD    (*(unsigned char volatile xdata *)0xFF25)

#define     PWM03T1     (*(unsigned int  volatile xdata *)0xFF28)
#define     PWM03T1H    (*(unsigned char volatile xdata *)0xFF28)
#define     PWM03T1L    (*(unsigned char volatile xdata *)0xFF29)
#define     PWM03T2     (*(unsigned int  volatile xdata *)0xFF2A)
#define     PWM03T2H    (*(unsigned char volatile xdata *)0xFF2A)
#define     PWM03T2L    (*(unsigned char volatile xdata *)0xFF2B)
#define     PWM03CR     (*(unsigned char volatile xdata *)0xFF2C)
#define     PWM03HLD    (*(unsigned char volatile xdata *)0xFF2D)

#define     PWM04T1     (*(unsigned int  volatile xdata *)0xFF30)
#define     PWM04T1H    (*(unsigned char volatile xdata *)0xFF30)
#define     PWM04T1L    (*(unsigned char volatile xdata *)0xFF31)
#define     PWM04T2     (*(unsigned int  volatile xdata *)0xFF32)
#define     PWM04T2H    (*(unsigned char volatile xdata *)0xFF32)
#define     PWM04T2L    (*(unsigned char volatile xdata *)0xFF33)
#define     PWM04CR     (*(unsigned char volatile xdata *)0xFF34)
#define     PWM04HLD    (*(unsigned char volatile xdata *)0xFF35)

#define     PWM05T1     (*(unsigned int  volatile xdata *)0xFF38)
#define     PWM05T1H    (*(unsigned char volatile xdata *)0xFF38)
#define     PWM05T1L    (*(unsigned char volatile xdata *)0xFF39)
#define     PWM05T2     (*(unsigned int  volatile xdata *)0xFF3A)
#define     PWM05T2H    (*(unsigned char volatile xdata *)0xFF3A)
#define     PWM05T2L    (*(unsigned char volatile xdata *)0xFF3B)
#define     PWM05CR     (*(unsigned char volatile xdata *)0xFF3C)
#define     PWM05HLD    (*(unsigned char volatile xdata *)0xFF3D)

#define     PWM06T1     (*(unsigned int  volatile xdata *)0xFF40)
#define     PWM06T1H    (*(unsigned char volatile xdata *)0xFF40)
#define     PWM06T1L    (*(unsigned char volatile xdata *)0xFF41)
#define     PWM06T2     (*(unsigned int  volatile xdata *)0xFF42)
#define     PWM06T2H    (*(unsigned char volatile xdata *)0xFF42)
#define     PWM06T2L    (*(unsigned char volatile xdata *)0xFF43)
#define     PWM06CR     (*(unsigned char volatile xdata *)0xFF44)
#define     PWM06HLD    (*(unsigned char volatile xdata *)0xFF45)

#define     PWM07T1     (*(unsigned int  volatile xdata *)0xFF48)
#define     PWM07T1H    (*(unsigned char volatile xdata *)0xFF48)
#define     PWM07T1L    (*(unsigned char volatile xdata *)0xFF49)
#define     PWM07T2     (*(unsigned int  volatile xdata *)0xFF4A)
#define     PWM07T2H    (*(unsigned char volatile xdata *)0xFF4A)
#define     PWM07T2L    (*(unsigned char volatile xdata *)0xFF4B)
#define     PWM07CR     (*(unsigned char volatile xdata *)0xFF4C)
#define     PWM07HLD    (*(unsigned char volatile xdata *)0xFF4D)

#define     PWM1C       (*(unsigned int  volatile xdata *)0xFF50)
#define     PWM1CH      (*(unsigned char volatile xdata *)0xFF50)
#define     PWM1CL      (*(unsigned char volatile xdata *)0xFF51)
#define     PWM1CKS     (*(unsigned char volatile xdata *)0xFF52)
#define     PWM1IF      (*(unsigned char volatile xdata *)0xFF55)
#define     PWM1FDCR    (*(unsigned char volatile xdata *)0xFF56)

#define     PWM10T1     (*(unsigned int  volatile xdata *)0xFF60)
#define     PWM10T1H    (*(unsigned char volatile xdata *)0xFF60)
#define     PWM10T1L    (*(unsigned char volatile xdata *)0xFF61)
#define     PWM10T2     (*(unsigned int  volatile xdata *)0xFF62)
#define     PWM10T2H    (*(unsigned char volatile xdata *)0xFF62)
#define     PWM10T2L    (*(unsigned char volatile xdata *)0xFF63)
#define     PWM10CR     (*(unsigned char volatile xdata *)0xFF64)
#define     PWM10HLD    (*(unsigned char volatile xdata *)0xFF65)

#define     PWM11T1     (*(unsigned int  volatile xdata *)0xFF68)
#define     PWM11T1H    (*(unsigned char volatile xdata *)0xFF68)
#define     PWM11T1L    (*(unsigned char volatile xdata *)0xFF69)
#define     PWM11T2     (*(unsigned int  volatile xdata *)0xFF6A)
#define     PWM11T2H    (*(unsigned char volatile xdata *)0xFF6A)
#define     PWM11T2L    (*(unsigned char volatile xdata *)0xFF6B)
#define     PWM11CR     (*(unsigned char volatile xdata *)0xFF6C)
#define     PWM11HLD    (*(unsigned char volatile xdata *)0xFF6D)

#define     PWM12T1     (*(unsigned int  volatile xdata *)0xFF70)
#define     PWM12T1H    (*(unsigned char volatile xdata *)0xFF70)
#define     PWM12T1L    (*(unsigned char volatile xdata *)0xFF71)
#define     PWM12T2     (*(unsigned int  volatile xdata *)0xFF72)
#define     PWM12T2H    (*(unsigned char volatile xdata *)0xFF72)
#define     PWM12T2L    (*(unsigned char volatile xdata *)0xFF73)
#define     PWM12CR     (*(unsigned char volatile xdata *)0xFF74)
#define     PWM12HLD    (*(unsigned char volatile xdata *)0xFF75)

#define     PWM13T1     (*(unsigned int  volatile xdata *)0xFF78)
#define     PWM13T1H    (*(unsigned char volatile xdata *)0xFF78)
#define     PWM13T1L    (*(unsigned char volatile xdata *)0xFF79)
#define     PWM13T2     (*(unsigned int  volatile xdata *)0xFF7A)
#define     PWM13T2H    (*(unsigned char volatile xdata *)0xFF7A)
#define     PWM13T2L    (*(unsigned char volatile xdata *)0xFF7B)
#define     PWM13CR     (*(unsigned char volatile xdata *)0xFF7C)
#define     PWM13HLD    (*(unsigned char volatile xdata *)0xFF7D)

#define     PWM14T1     (*(unsigned int  volatile xdata *)0xFF80)
#define     PWM14T1H    (*(unsigned char volatile xdata *)0xFF80)
#define     PWM14T1L    (*(unsigned char volatile xdata *)0xFF81)
#define     PWM14T2     (*(unsigned int  volatile xdata *)0xFF82)
#define     PWM14T2H    (*(unsigned char volatile xdata *)0xFF82)
#define     PWM14T2L    (*(unsigned char volatile xdata *)0xFF83)
#define     PWM14CR     (*(unsigned char volatile xdata *)0xFF84)
#define     PWM14HLD    (*(unsigned char volatile xdata *)0xFF85)

#define     PWM15T1     (*(unsigned int  volatile xdata *)0xFF88)
#define     PWM15T1H    (*(unsigned char volatile xdata *)0xFF88)
#define     PWM15T1L    (*(unsigned char volatile xdata *)0xFF89)
#define     PWM15T2     (*(unsigned int  volatile xdata *)0xFF8A)
#define     PWM15T2H    (*(unsigned char volatile xdata *)0xFF8A)
#define     PWM15T2L    (*(unsigned char volatile xdata *)0xFF8B)
#define     PWM15CR     (*(unsigned char volatile xdata *)0xFF8C)
#define     PWM15HLD    (*(unsigned char volatile xdata *)0xFF8D)

#define     PWM16T1     (*(unsigned int  volatile xdata *)0xFF90)
#define     PWM16T1H    (*(unsigned char volatile xdata *)0xFF90)
#define     PWM16T1L    (*(unsigned char volatile xdata *)0xFF91)
#define     PWM16T2     (*(unsigned int  volatile xdata *)0xFF92)
#define     PWM16T2H    (*(unsigned char volatile xdata *)0xFF92)
#define     PWM16T2L    (*(unsigned char volatile xdata *)0xFF93)
#define     PWM16CR     (*(unsigned char volatile xdata *)0xFF94)
#define     PWM16HLD    (*(unsigned char volatile xdata *)0xFF95)

#define     PWM17T1     (*(unsigned int  volatile xdata *)0xFF98)
#define     PWM17T1H    (*(unsigned char volatile xdata *)0xFF98)
#define     PWM17T1L    (*(unsigned char volatile xdata *)0xFF99)
#define     PWM17T2     (*(unsigned int  volatile xdata *)0xFF9A)
#define     PWM17T2H    (*(unsigned char volatile xdata *)0xFF9A)
#define     PWM17T2L    (*(unsigned char volatile xdata *)0xFF9B)
#define     PWM17CR     (*(unsigned char volatile xdata *)0xFF9C)
#define     PWM17HLD    (*(unsigned char volatile xdata *)0xFF9D)

#define     PWM2C       (*(unsigned int  volatile xdata *)0xFFA0)
#define     PWM2CH      (*(unsigned char volatile xdata *)0xFFA0)
#define     PWM2CL      (*(unsigned char volatile xdata *)0xFFA1)
#define     PWM2CKS     (*(unsigned char volatile xdata *)0xFFA2)
#define     PWM2TADCH   (*(unsigned char volatile xdata *)0xFFA3)
#define     PWM2TADCL   (*(unsigned char volatile xdata *)0xFFA4)
#define     PWM2IF      (*(unsigned char volatile xdata *)0xFFA5)
#define     PWM2FDCR    (*(unsigned char volatile xdata *)0xFFA6)

#define     PWM20T1     (*(unsigned int  volatile xdata *)0xFFB0)
#define     PWM20T1H    (*(unsigned char volatile xdata *)0xFFB0)
#define     PWM20T1L    (*(unsigned char volatile xdata *)0xFFB1)
#define     PWM20T2     (*(unsigned int  volatile xdata *)0xFFB2)
#define     PWM20T2H    (*(unsigned char volatile xdata *)0xFFB2)
#define     PWM20T2L    (*(unsigned char volatile xdata *)0xFFB3)
#define     PWM20CR     (*(unsigned char volatile xdata *)0xFFB4)
#define     PWM20HLD    (*(unsigned char volatile xdata *)0xFFB5)

#define     PWM21T1     (*(unsigned int  volatile xdata *)0xFFB8)
#define     PWM21T1H    (*(unsigned char volatile xdata *)0xFFB8)
#define     PWM21T1L    (*(unsigned char volatile xdata *)0xFFB9)
#define     PWM21T2     (*(unsigned int  volatile xdata *)0xFFBA)
#define     PWM21T2H    (*(unsigned char volatile xdata *)0xFFBA)
#define     PWM21T2L    (*(unsigned char volatile xdata *)0xFFBB)
#define     PWM21CR     (*(unsigned char volatile xdata *)0xFFBC)
#define     PWM21HLD    (*(unsigned char volatile xdata *)0xFFBD)

#define     PWM22T1     (*(unsigned int  volatile xdata *)0xFFC0)
#define     PWM22T1H    (*(unsigned char volatile xdata *)0xFFC0)
#define     PWM22T1L    (*(unsigned char volatile xdata *)0xFFC1)
#define     PWM22T2     (*(unsigned int  volatile xdata *)0xFFC2)
#define     PWM22T2H    (*(unsigned char volatile xdata *)0xFFC2)
#define     PWM22T2L    (*(unsigned char volatile xdata *)0xFFC3)
#define     PWM22CR     (*(unsigned char volatile xdata *)0xFFC4)
#define     PWM22HLD    (*(unsigned char volatile xdata *)0xFFC5)

#define     PWM23T1     (*(unsigned int  volatile xdata *)0xFFC8)
#define     PWM23T1H    (*(unsigned char volatile xdata *)0xFFC8)
#define     PWM23T1L    (*(unsigned char volatile xdata *)0xFFC9)
#define     PWM23T2     (*(unsigned int  volatile xdata *)0xFFCA)
#define     PWM23T2H    (*(unsigned char volatile xdata *)0xFFCA)
#define     PWM23T2L    (*(unsigned char volatile xdata *)0xFFCB)
#define     PWM23CR     (*(unsigned char volatile xdata *)0xFFCC)
#define     PWM23HLD    (*(unsigned char volatile xdata *)0xFFCD)

#define     PWM24T1     (*(unsigned int  volatile xdata *)0xFFD0)
#define     PWM24T1H    (*(unsigned char volatile xdata *)0xFFD0)
#define     PWM24T1L    (*(unsigned char volatile xdata *)0xFFD1)
#define     PWM24T2     (*(unsigned int  volatile xdata *)0xFFD2)
#define     PWM24T2H    (*(unsigned char volatile xdata *)0xFFD2)
#define     PWM24T2L    (*(unsigned char volatile xdata *)0xFFD3)
#define     PWM24CR     (*(unsigned char volatile xdata *)0xFFD4)
#define     PWM24HLD    (*(unsigned char volatile xdata *)0xFFD5)

#define     PWM25T1     (*(unsigned int  volatile xdata *)0xFFD8)
#define     PWM25T1H    (*(unsigned char volatile xdata *)0xFFD8)
#define     PWM25T1L    (*(unsigned char volatile xdata *)0xFFD9)
#define     PWM25T2     (*(unsigned int  volatile xdata *)0xFFDA)
#define     PWM25T2H    (*(unsigned char volatile xdata *)0xFFDA)
#define     PWM25T2L    (*(unsigned char volatile xdata *)0xFFDB)
#define     PWM25CR     (*(unsigned char volatile xdata *)0xFFDC)
#define     PWM25HLD    (*(unsigned char volatile xdata *)0xFFDD)

#define     PWM26T1     (*(unsigned int  volatile xdata *)0xFFE0)
#define     PWM26T1H    (*(unsigned char volatile xdata *)0xFFE0)
#define     PWM26T1L    (*(unsigned char volatile xdata *)0xFFE1)
#define     PWM26T2     (*(unsigned int  volatile xdata *)0xFFE2)
#define     PWM26T2H    (*(unsigned char volatile xdata *)0xFFE2)
#define     PWM26T2L    (*(unsigned char volatile xdata *)0xFFE3)
#define     PWM26CR     (*(unsigned char volatile xdata *)0xFFE4)
#define     PWM26HLD    (*(unsigned char volatile xdata *)0xFFE5)

#define     PWM27T1     (*(unsigned int  volatile xdata *)0xFFE8)
#define     PWM27T1H    (*(unsigned char volatile xdata *)0xFFE8)
#define     PWM27T1L    (*(unsigned char volatile xdata *)0xFFE9)
#define     PWM27T2     (*(unsigned int  volatile xdata *)0xFFEA)
#define     PWM27T2H    (*(unsigned char volatile xdata *)0xFFEA)
#define     PWM27T2L    (*(unsigned char volatile xdata *)0xFFEB)
#define     PWM27CR     (*(unsigned char volatile xdata *)0xFFEC)
#define     PWM27HLD    (*(unsigned char volatile xdata *)0xFFED)

#define     PWM3C       (*(unsigned int  volatile xdata *)0xFC00)
#define     PWM3CH      (*(unsigned char volatile xdata *)0xFC00)
#define     PWM3CL      (*(unsigned char volatile xdata *)0xFC01)
#define     PWM3CKS     (*(unsigned char volatile xdata *)0xFC02)
#define     PWM3IF      (*(unsigned char volatile xdata *)0xFC05)
#define     PWM3FDCR    (*(unsigned char volatile xdata *)0xFC06)

#define     PWM30T1     (*(unsigned int  volatile xdata *)0xFC10)
#define     PWM30T1H    (*(unsigned char volatile xdata *)0xFC10)
#define     PWM30T1L    (*(unsigned char volatile xdata *)0xFC11)
#define     PWM30T2     (*(unsigned int  volatile xdata *)0xFC12)
#define     PWM30T2H    (*(unsigned char volatile xdata *)0xFC12)
#define     PWM30T2L    (*(unsigned char volatile xdata *)0xFC13)
#define     PWM30CR     (*(unsigned char volatile xdata *)0xFC14)
#define     PWM30HLD    (*(unsigned char volatile xdata *)0xFC15)

#define     PWM31T1     (*(unsigned int  volatile xdata *)0xFC18)
#define     PWM31T1H    (*(unsigned char volatile xdata *)0xFC18)
#define     PWM31T1L    (*(unsigned char volatile xdata *)0xFC19)
#define     PWM31T2     (*(unsigned int  volatile xdata *)0xFC1A)
#define     PWM31T2H    (*(unsigned char volatile xdata *)0xFC1A)
#define     PWM31T2L    (*(unsigned char volatile xdata *)0xFC1B)
#define     PWM31CR     (*(unsigned char volatile xdata *)0xFC1C)
#define     PWM31HLD    (*(unsigned char volatile xdata *)0xFC1D)

#define     PWM32T1     (*(unsigned int  volatile xdata *)0xFC20)
#define     PWM32T1H    (*(unsigned char volatile xdata *)0xFC20)
#define     PWM32T1L    (*(unsigned char volatile xdata *)0xFC21)
#define     PWM32T2     (*(unsigned int  volatile xdata *)0xFC22)
#define     PWM32T2H    (*(unsigned char volatile xdata *)0xFC22)
#define     PWM32T2L    (*(unsigned char volatile xdata *)0xFC23)
#define     PWM32CR     (*(unsigned char volatile xdata *)0xFC24)
#define     PWM32HLD    (*(unsigned char volatile xdata *)0xFC25)

#define     PWM33T1     (*(unsigned int  volatile xdata *)0xFC28)
#define     PWM33T1H    (*(unsigned char volatile xdata *)0xFC28)
#define     PWM33T1L    (*(unsigned char volatile xdata *)0xFC29)
#define     PWM33T2     (*(unsigned int  volatile xdata *)0xFC2A)
#define     PWM33T2H    (*(unsigned char volatile xdata *)0xFC2A)
#define     PWM33T2L    (*(unsigned char volatile xdata *)0xFC2B)
#define     PWM33CR     (*(unsigned char volatile xdata *)0xFC2C)
#define     PWM33HLD    (*(unsigned char volatile xdata *)0xFC2D)

#define     PWM34T1     (*(unsigned int  volatile xdata *)0xFC30)
#define     PWM34T1H    (*(unsigned char volatile xdata *)0xFC30)
#define     PWM34T1L    (*(unsigned char volatile xdata *)0xFC31)
#define     PWM34T2     (*(unsigned int  volatile xdata *)0xFC32)
#define     PWM34T2H    (*(unsigned char volatile xdata *)0xFC32)
#define     PWM34T2L    (*(unsigned char volatile xdata *)0xFC33)
#define     PWM34CR     (*(unsigned char volatile xdata *)0xFC34)
#define     PWM34HLD    (*(unsigned char volatile xdata *)0xFC35)

#define     PWM35T1     (*(unsigned int  volatile xdata *)0xFC38)
#define     PWM35T1H    (*(unsigned char volatile xdata *)0xFC38)
#define     PWM35T1L    (*(unsigned char volatile xdata *)0xFC39)
#define     PWM35T2     (*(unsigned int  volatile xdata *)0xFC3A)
#define     PWM35T2H    (*(unsigned char volatile xdata *)0xFC3A)
#define     PWM35T2L    (*(unsigned char volatile xdata *)0xFC3B)
#define     PWM35CR     (*(unsigned char volatile xdata *)0xFC3C)
#define     PWM35HLD    (*(unsigned char volatile xdata *)0xFC3D)

#define     PWM36T1     (*(unsigned int  volatile xdata *)0xFC40)
#define     PWM36T1H    (*(unsigned char volatile xdata *)0xFC40)
#define     PWM36T1L    (*(unsigned char volatile xdata *)0xFC41)
#define     PWM36T2     (*(unsigned int  volatile xdata *)0xFC42)
#define     PWM36T2H    (*(unsigned char volatile xdata *)0xFC42)
#define     PWM36T2L    (*(unsigned char volatile xdata *)0xFC43)
#define     PWM36CR     (*(unsigned char volatile xdata *)0xFC44)
#define     PWM36HLD    (*(unsigned char volatile xdata *)0xFC45)

#define     PWM37T1     (*(unsigned int  volatile xdata *)0xFC48)
#define     PWM37T1H    (*(unsigned char volatile xdata *)0xFC48)
#define     PWM37T1L    (*(unsigned char volatile xdata *)0xFC49)
#define     PWM37T2     (*(unsigned int  volatile xdata *)0xFC4A)
#define     PWM37T2H    (*(unsigned char volatile xdata *)0xFC4A)
#define     PWM37T2L    (*(unsigned char volatile xdata *)0xFC4B)
#define     PWM37CR     (*(unsigned char volatile xdata *)0xFC4C)
#define     PWM37HLD    (*(unsigned char volatile xdata *)0xFC4D)

#define     PWM4C       (*(unsigned int  volatile xdata *)0xFC50)
#define     PWM4CH      (*(unsigned char volatile xdata *)0xFC50)
#define     PWM4CL      (*(unsigned char volatile xdata *)0xFC51)
#define     PWM4CKS     (*(unsigned char volatile xdata *)0xFC52)
#define     PWM4TADCH   (*(unsigned char volatile xdata *)0xFC53)
#define     PWM4TADCL   (*(unsigned char volatile xdata *)0xFC54)
#define     PWM4IF      (*(unsigned char volatile xdata *)0xFC55)
#define     PWM4FDCR    (*(unsigned char volatile xdata *)0xFC56)

#define     PWM40T1     (*(unsigned int  volatile xdata *)0xFC60)
#define     PWM40T1H    (*(unsigned char volatile xdata *)0xFC60)
#define     PWM40T1L    (*(unsigned char volatile xdata *)0xFC61)
#define     PWM40T2     (*(unsigned int  volatile xdata *)0xFC62)
#define     PWM40T2H    (*(unsigned char volatile xdata *)0xFC62)
#define     PWM40T2L    (*(unsigned char volatile xdata *)0xFC63)
#define     PWM40CR     (*(unsigned char volatile xdata *)0xFC64)
#define     PWM40HLD    (*(unsigned char volatile xdata *)0xFC65)

#define     PWM41T1     (*(unsigned int  volatile xdata *)0xFC68)
#define     PWM41T1H    (*(unsigned char volatile xdata *)0xFC68)
#define     PWM41T1L    (*(unsigned char volatile xdata *)0xFC69)
#define     PWM41T2     (*(unsigned int  volatile xdata *)0xFC6A)
#define     PWM41T2H    (*(unsigned char volatile xdata *)0xFC6A)
#define     PWM41T2L    (*(unsigned char volatile xdata *)0xFC6B)
#define     PWM41CR     (*(unsigned char volatile xdata *)0xFC6C)
#define     PWM41HLD    (*(unsigned char volatile xdata *)0xFC6D)

#define     PWM42T1     (*(unsigned int  volatile xdata *)0xFC70)
#define     PWM42T1H    (*(unsigned char volatile xdata *)0xFC70)
#define     PWM42T1L    (*(unsigned char volatile xdata *)0xFC71)
#define     PWM42T2     (*(unsigned int  volatile xdata *)0xFC72)
#define     PWM42T2H    (*(unsigned char volatile xdata *)0xFC72)
#define     PWM42T2L    (*(unsigned char volatile xdata *)0xFC73)
#define     PWM42CR     (*(unsigned char volatile xdata *)0xFC74)
#define     PWM42HLD    (*(unsigned char volatile xdata *)0xFC75)

#define     PWM43T1     (*(unsigned int  volatile xdata *)0xFC78)
#define     PWM43T1H    (*(unsigned char volatile xdata *)0xFC78)
#define     PWM43T1L    (*(unsigned char volatile xdata *)0xFC79)
#define     PWM43T2     (*(unsigned int  volatile xdata *)0xFC7A)
#define     PWM43T2H    (*(unsigned char volatile xdata *)0xFC7A)
#define     PWM43T2L    (*(unsigned char volatile xdata *)0xFC7B)
#define     PWM43CR     (*(unsigned char volatile xdata *)0xFC7C)
#define     PWM43HLD    (*(unsigned char volatile xdata *)0xFC7D)

#define     PWM44T1     (*(unsigned int  volatile xdata *)0xFC80)
#define     PWM44T1H    (*(unsigned char volatile xdata *)0xFC80)
#define     PWM44T1L    (*(unsigned char volatile xdata *)0xFC81)
#define     PWM44T2     (*(unsigned int  volatile xdata *)0xFC82)
#define     PWM44T2H    (*(unsigned char volatile xdata *)0xFC82)
#define     PWM44T2L    (*(unsigned char volatile xdata *)0xFC83)
#define     PWM44CR     (*(unsigned char volatile xdata *)0xFC84)
#define     PWM44HLD    (*(unsigned char volatile xdata *)0xFC85)

#define     PWM45T1     (*(unsigned int  volatile xdata *)0xFC88)
#define     PWM45T1H    (*(unsigned char volatile xdata *)0xFC88)
#define     PWM45T1L    (*(unsigned char volatile xdata *)0xFC89)
#define     PWM45T2     (*(unsigned int  volatile xdata *)0xFC8A)
#define     PWM45T2H    (*(unsigned char volatile xdata *)0xFC8A)
#define     PWM45T2L    (*(unsigned char volatile xdata *)0xFC8B)
#define     PWM45CR     (*(unsigned char volatile xdata *)0xFC8C)
#define     PWM45HLD    (*(unsigned char volatile xdata *)0xFC8D)

#define     PWM46T1     (*(unsigned int  volatile xdata *)0xFC90)
#define     PWM46T1H    (*(unsigned char volatile xdata *)0xFC90)
#define     PWM46T1L    (*(unsigned char volatile xdata *)0xFC91)
#define     PWM46T2     (*(unsigned int  volatile xdata *)0xFC92)
#define     PWM46T2H    (*(unsigned char volatile xdata *)0xFC92)
#define     PWM46T2L    (*(unsigned char volatile xdata *)0xFC93)
#define     PWM46CR     (*(unsigned char volatile xdata *)0xFC94)
#define     PWM46HLD    (*(unsigned char volatile xdata *)0xFC95)

#define     PWM47T1     (*(unsigned int  volatile xdata *)0xFC98)
#define     PWM47T1H    (*(unsigned char volatile xdata *)0xFC98)
#define     PWM47T1L    (*(unsigned char volatile xdata *)0xFC99)
#define     PWM47T2     (*(unsigned int  volatile xdata *)0xFC9A)
#define     PWM47T2H    (*(unsigned char volatile xdata *)0xFC9A)
#define     PWM47T2L    (*(unsigned char volatile xdata *)0xFC9B)
#define     PWM47CR     (*(unsigned char volatile xdata *)0xFC9C)
#define     PWM47HLD    (*(unsigned char volatile xdata *)0xFC9D)

#define     PWM5C       (*(unsigned int  volatile xdata *)0xFCA0)
#define     PWM5CH      (*(unsigned char volatile xdata *)0xFCA0)
#define     PWM5CL      (*(unsigned char volatile xdata *)0xFCA1)
#define     PWM5CKS     (*(unsigned char volatile xdata *)0xFCA2)
#define     PWM5IF      (*(unsigned char volatile xdata *)0xFCA5)
#define     PWM5FDCR    (*(unsigned char volatile xdata *)0xFCA6)

#define     PWM50T1     (*(unsigned int  volatile xdata *)0xFCB0)
#define     PWM50T1H    (*(unsigned char volatile xdata *)0xFCB0)
#define     PWM50T1L    (*(unsigned char volatile xdata *)0xFCB1)
#define     PWM50T2     (*(unsigned int  volatile xdata *)0xFCB2)
#define     PWM50T2H    (*(unsigned char volatile xdata *)0xFCB2)
#define     PWM50T2L    (*(unsigned char volatile xdata *)0xFCB3)
#define     PWM50CR     (*(unsigned char volatile xdata *)0xFCB4)
#define     PWM50HLD    (*(unsigned char volatile xdata *)0xFCB5)

#define     PWM51T1     (*(unsigned int  volatile xdata *)0xFCB8)
#define     PWM51T1H    (*(unsigned char volatile xdata *)0xFCB8)
#define     PWM51T1L    (*(unsigned char volatile xdata *)0xFCB9)
#define     PWM51T2     (*(unsigned int  volatile xdata *)0xFCBA)
#define     PWM51T2H    (*(unsigned char volatile xdata *)0xFCBA)
#define     PWM51T2L    (*(unsigned char volatile xdata *)0xFCBB)
#define     PWM51CR     (*(unsigned char volatile xdata *)0xFCBC)
#define     PWM51HLD    (*(unsigned char volatile xdata *)0xFCBD)

#define     PWM52T1     (*(unsigned int  volatile xdata *)0xFCC0)
#define     PWM52T1H    (*(unsigned char volatile xdata *)0xFCC0)
#define     PWM52T1L    (*(unsigned char volatile xdata *)0xFCC1)
#define     PWM52T2     (*(unsigned int  volatile xdata *)0xFCC2)
#define     PWM52T2H    (*(unsigned char volatile xdata *)0xFCC2)
#define     PWM52T2L    (*(unsigned char volatile xdata *)0xFCC3)
#define     PWM52CR     (*(unsigned char volatile xdata *)0xFCC4)
#define     PWM52HLD    (*(unsigned char volatile xdata *)0xFCC5)

#define     PWM53T1     (*(unsigned int  volatile xdata *)0xFCC8)
#define     PWM53T1H    (*(unsigned char volatile xdata *)0xFCC8)
#define     PWM53T1L    (*(unsigned char volatile xdata *)0xFCC9)
#define     PWM53T2     (*(unsigned int  volatile xdata *)0xFCCA)
#define     PWM53T2H    (*(unsigned char volatile xdata *)0xFCCA)
#define     PWM53T2L    (*(unsigned char volatile xdata *)0xFCCB)
#define     PWM53CR     (*(unsigned char volatile xdata *)0xFCCC)
#define     PWM53HLD    (*(unsigned char volatile xdata *)0xFCCD)

#define     PWM54T1     (*(unsigned int  volatile xdata *)0xFCD0)
#define     PWM54T1H    (*(unsigned char volatile xdata *)0xFCD0)
#define     PWM54T1L    (*(unsigned char volatile xdata *)0xFCD1)
#define     PWM54T2     (*(unsigned int  volatile xdata *)0xFCD2)
#define     PWM54T2H    (*(unsigned char volatile xdata *)0xFCD2)
#define     PWM54T2L    (*(unsigned char volatile xdata *)0xFCD3)
#define     PWM54CR     (*(unsigned char volatile xdata *)0xFCD4)
#define     PWM54HLD    (*(unsigned char volatile xdata *)0xFCD5)

#define     PWM55T1     (*(unsigned int  volatile xdata *)0xFCD8)
#define     PWM55T1H    (*(unsigned char volatile xdata *)0xFCD8)
#define     PWM55T1L    (*(unsigned char volatile xdata *)0xFCD9)
#define     PWM55T2     (*(unsigned int  volatile xdata *)0xFCDA)
#define     PWM55T2H    (*(unsigned char volatile xdata *)0xFCDA)
#define     PWM55T2L    (*(unsigned char volatile xdata *)0xFCDB)
#define     PWM55CR     (*(unsigned char volatile xdata *)0xFCDC)
#define     PWM55HLD    (*(unsigned char volatile xdata *)0xFCDD)

#define     PWM56T1     (*(unsigned int  volatile xdata *)0xFCE0)
#define     PWM56T1H    (*(unsigned char volatile xdata *)0xFCE0)
#define     PWM56T1L    (*(unsigned char volatile xdata *)0xFCE1)
#define     PWM56T2     (*(unsigned int  volatile xdata *)0xFCE2)
#define     PWM56T2H    (*(unsigned char volatile xdata *)0xFCE2)
#define     PWM56T2L    (*(unsigned char volatile xdata *)0xFCE3)
#define     PWM56CR     (*(unsigned char volatile xdata *)0xFCE4)
#define     PWM56HLD    (*(unsigned char volatile xdata *)0xFCE5)

#define     PWM57T1     (*(unsigned int  volatile xdata *)0xFCE8)
#define     PWM57T1H    (*(unsigned char volatile xdata *)0xFCE8)
#define     PWM57T1L    (*(unsigned char volatile xdata *)0xFCE9)
#define     PWM57T2     (*(unsigned int  volatile xdata *)0xFCEA)
#define     PWM57T2H    (*(unsigned char volatile xdata *)0xFCEA)
#define     PWM57T2L    (*(unsigned char volatile xdata *)0xFCEB)
#define     PWM57CR     (*(unsigned char volatile xdata *)0xFCEC)
#define     PWM57HLD    (*(unsigned char volatile xdata *)0xFCED)


/*--------------------------内核特殊功能寄存器--------------------------*/
sfr     ACC     =   0xe0;  //累加器
sfr     B       =   0xf0;  //B寄存器
sfr     PSW     =   0xd0;  //程序状态字寄存器
sbit    CY      =   PSW^7; //进位标志位
sbit    AC      =   PSW^6; //辅助进位标志位
sbit    F0      =   PSW^5; //留给用户的标志位
sbit    RS1     =   PSW^4; //工作寄存器选择位（高位）
sbit    RS0     =   PSW^3; //工作寄存器选择位（低位）
sbit    OV      =   PSW^2; //溢出标志位
sbit    P       =   PSW^0; //奇偶校验位
sfr     SP      =   0x81;  //堆栈指针
sfr     DPL     =   0x82;  //数据指针（低字节）
sfr     DPH     =   0x83;  //数据指针（高字节）
sfr     TA      =   0xae;  //DPTR时序控制寄存器
sfr     DPS     =   0xe3;  //DPTR指针选择器
sfr     DPL1    =   0xe4;  //第二组数据指针（低字节）
sfr     DPH1    =   0xe5;  //第二组数据指针（高字节）
/*-------------------------I/O口特殊功能寄存器--------------------------*/
sfr     P0      =   0x80;  //P0端口
sbit    P00     =   P0^0;  //P0.0口
sbit    P01     =   P0^1;  //P0.1口
sbit    P02     =   P0^2;  //P0.2口
sbit    P03     =   P0^3;  //P0.3口
sbit    P04     =   P0^4;  //P0.4口
sbit    P05     =   P0^5;  //P0.5口
sbit    P06     =   P0^6;  //P0.6口
sbit    P07     =   P0^7;  //P0.7口
sfr     P0M0    =   0x94;  //P0口配置寄存器0
sfr     P0M1    =   0x93;  //P0口配置寄存器1
#define P0PU    (*(unsigned char volatile xdata *)0xfe10)//P0口上拉电阻控制寄存器
#define P0NCS   (*(unsigned char volatile xdata *)0xfe18)//P0口施密特触发控制寄存器


sfr     P1      =   0x90;  //P1端口
sbit    P10     =   P1^0;  //P1.0口
sbit    P11     =   P1^1;  //P1.1口
sbit    P12     =   P1^2;  //P1.2口
sbit    P13     =   P1^3;  //P1.3口
sbit    P14     =   P1^4;  //P1.4口
sbit    P15     =   P1^5;  //P1.5口
sbit    P16     =   P1^6;  //P1.6口
sbit    P17     =   P1^7;  //P1.7口
sfr     P1M0    =   0x92;  //P1口配置寄存器0
sfr     P1M1    =   0x91;  //P1口配置寄存器1
#define P1PU    (*(unsigned char volatile xdata *)0xfe11)//P1口上拉电阻控制寄存器
#define P1NCS   (*(unsigned char volatile xdata *)0xfe19)//P1口施密特触发控制寄存器


sfr     P2      =   0xa0;  //P2端口
sbit    P20     =   P2^0;  //P2.0口
sbit    P21     =   P2^1;  //P2.1口
sbit    P22     =   P2^2;  //P2.2口
sbit    P23     =   P2^3;  //P2.3口
sbit    P24     =   P2^4;  //P2.4口
sbit    P25     =   P2^5;  //P2.5口
sbit    P26     =   P2^6;  //P2.6口
sbit    P27     =   P2^7;  //P2.7口
sfr     P2M0    =   0x96;  //P2口配置寄存器0
sfr     P2M1    =   0x95;  //P2口配置寄存器1
#define P2PU    (*(unsigned char volatile xdata *)0xfe12)//P2口上拉电阻控制寄存器
#define P2NCS   (*(unsigned char volatile xdata *)0xfe1a)//P2口施密特触发控制寄存器


sfr     P3      =   0xb0;  //P3端口
sbit    P30     =   P3^0;  //P3.0口
sbit    P31     =   P3^1;  //P3.1口
sbit    P32     =   P3^2;  //P3.2口
sbit    P33     =   P3^3;  //P3.3口
sbit    P34     =   P3^4;  //P3.4口
sbit    P35     =   P3^5;  //P3.5口
sbit    P36     =   P3^6;  //P3.6口
sbit    P37     =   P3^7;  //P3.7口
sfr     P3M0    =   0xb2;  //P3口配置寄存器0
sfr     P3M1    =   0xb1;  //P3口配置寄存器1
#define P3PU    (*(unsigned char volatile xdata *)0xfe13)//P3口上拉电阻控制寄存器
#define P3NCS   (*(unsigned char volatile xdata *)0xfe1b)//P3口施密特触发控制寄存器

sfr     P4      =   0xc0;  //P4端口
sbit    P40     =   P4^0;  //P4.0口
sbit    P41     =   P4^1;  //P4.1口
sbit    P42     =   P4^2;  //P4.2口
sbit    P43     =   P4^3;  //P4.3口
sbit    P44     =   P4^4;  //P4.4口
sbit    P45     =   P4^5;  //P4.5口
sbit    P46     =   P4^6;  //P4.6口
sbit    P47     =   P4^7;  //P4.7口
sfr     P4M0    =   0xb4;  //P4口配置寄存器0
sfr     P4M1    =   0xb3;  //P4口配置寄存器1
#define P4PU    (*(unsigned char volatile xdata *)0xfe14)//P4口上拉电阻控制寄存器
#define P4NCS   (*(unsigned char volatile xdata *)0xfe1c)//P4口施密特触发控制寄存器

sfr     P5      =   0xc8;  //P5端口
sbit    P50     =   P5^0;  //P5.0口
sbit    P51     =   P5^1;  //P5.1口
sbit    P52     =   P5^2;  //P5.2口
sbit    P53     =   P5^3;  //P5.3口
sbit    P54     =   P5^4;  //P5.4口
sbit    P55     =   P5^5;  //P5.5口
sbit    P56     =   P5^6;  //P5.6口
sbit    P57     =   P5^7;  //P5.7口
sfr     P5M0    =   0xca;  //P5口配置寄存器0
sfr     P5M1    =   0xc9;  //P5口配置寄存器1
#define P5PU    (*(unsigned char volatile xdata *)0xfe15)//P5口上拉电阻控制寄存器
#define P5NCS   (*(unsigned char volatile xdata *)0xfe1d)//P5口施密特触发控制寄存器

sfr     P6      =   0xe8;  //P6端口
sbit    P60     =   P6^0;  //P6.0口
sbit    P61     =   P6^1;  //P6.1口
sbit    P62     =   P6^2;  //P6.2口
sbit    P63     =   P6^3;  //P6.3口
sbit    P64     =   P6^4;  //P6.4口
sbit    P65     =   P6^5;  //P6.5口
sbit    P66     =   P6^6;  //P6.6口
sbit    P67     =   P6^7;  //P6.7口
sfr     P6M0    =   0xcc;  //P6口配置寄存器0
sfr     P6M1    =   0xcb;  //P6口配置寄存器1
#define P6PU    (*(unsigned char volatile xdata *)0xfe16)//P6口上拉电阻控制寄存器
#define P6NCS   (*(unsigned char volatile xdata *)0xfe1e)//P6口施密特触发控制寄存器

sfr     P7      =   0xf8;  //P7端口
sbit    P70     =   P7^0;  //P7.0口
sbit    P71     =   P7^1;  //P7.1口
sbit    P72     =   P7^2;  //P7.2口
sbit    P73     =   P7^3;  //P7.3口
sbit    P74     =   P7^4;  //P7.4口
sbit    P75     =   P7^5;  //P7.5口
sbit    P76     =   P7^6;  //P7.6口
sbit    P77     =   P7^7;  //P7.7口
sfr     P7M0    =   0xe2;  //P7口配置寄存器0
sfr     P7M1    =   0xe1;  //P7口配置寄存器7
#define P7PU    (*(unsigned char volatile xdata *)0xfe17)//P7口上拉电阻控制寄存器
#define P7NCS   (*(unsigned char volatile xdata *)0xfe1f)//P7口施密特触发控制寄存器

/*-----------------------系统管理特殊功能寄存器--------------------------*/
sfr     PCON    =   0x87;  //电源控制寄存器
#define SMOD        0x80   //串口1波特率控制位
#define SMOD0       0x40   //帧错误检测控制位
#define LVDF        0x20   //低压检测中断请求标志
#define POF         0x10   //上电标志位
#define GF1         0x08   //用户专用标志位
#define GF0         0x04   //用户专用标志位
#define PD          0x02   //掉电模式控制位
#define IDL         0x01   //空闲模式控制位
sfr     AUXR    =   0x8e;  //辅助寄存器1
#define T0x12       0x80   //定时器0速度控制位 
#define T1x12       0x40   //定时器1速度控制位
#define UART_M0x6   0x20   //串口1模式0的通讯速度控制位
#define T2R         0x10   //定时器2运行控制位
#define T2_CT       0x08   //定时器2计数控制位
#define T2x12       0x04   //定时器2速度控制位
#define EXTRAM      0x02   //扩展RAM访问控制位
#define S1ST2       0x01   //串口1波特率发射器选择为位
sfr     AUXR2   =   0x97;  //辅助寄存器2
#define TXLNRX      0x10   
sfr BUS_SPEED   =   0xa1;  //总线速度控制寄存器
sfr     P_SW1   =   0xa2;  //外设端口切换寄存器1
sfr     P_SW2   =   0xba;  //外设端口切换寄存器2
#define EAXFR       0x80
sfr     VOCTRL  =   0xbb;  //电压控制寄存器
sfr     RSTCFG  =   0xff;  //复位配置寄存器
/*-----------------------时钟管理特殊功能寄存器--------------------------*/
#define CKSEL       (*(unsigned char volatile xdata *)0xfe00)//时钟选择寄存器
#define CLKDIV      (*(unsigned char volatile xdata *)0xfe01)//时钟分频寄存器
#define HIRCCR      (*(unsigned char volatile xdata *)0xfe02)//内部高速振荡器控制寄存器
#define XOSCCR      (*(unsigned char volatile xdata *)0xfe03)//外部晶振控制寄存器
#define IRC32KCR    (*(unsigned char volatile xdata *)0xfe04)//内部32K振荡器控制寄存器
#define MCLKOCR     (*(unsigned char volatile xdata *)0xFE05)//主时钟输出控制寄存器
#define IRCDB       (*(unsigned char volatile xdata *)0xFE06)//内部高速振荡器去抖控制寄存器
sfr     IRTRIM  =   0x9F;  //内部高精度IRC频率调整寄存器
sfr     LIRTRIM =   0x9E;  //内部高精度IRC频率微调寄存器
sfr     IRCBAND =   0x9D;  //IRC频段选择寄存器
/*-------------------------中断特殊功能寄存器----------------------------*/
sfr     IE      =   0xa8;  //中断允许寄存器
sbit    EA      =   IE^7;  //总中断允许控制位
sbit    ELVD    =   IE^6;  //低压检测中断允许位
sbit    EADC    =   IE^5;  //A/D转换中断允许位
sbit    ES      =   IE^4;  //串口1中断允许位
sbit    ET1     =   IE^3;  //定时器1中断允许位
sbit    EX1     =   IE^2;  //外部中断1允许位
sbit    ET0     =   IE^1;  //定时器0中断允许位
sbit    EX0     =   IE^0;  //外部中断0允许位
sfr     IE2     =   0xaf;  //中断允许寄存器2
#define ETKSUI      0x80   //触摸按键中断允许位
#define ET4         0x40   //定时器4中断允许位
#define ET3         0x20   //定时器3中断允许位
#define ES4         0x10   //串口4中断允许位
#define ES3         0x08   //串口3中断允许位
#define ET2         0x04   //定时器2中断允许位
#define ESPI        0x02   //SPI中断允许位
#define ES2         0x01   //串口2中断允许位
sfr     IP      =   0xb8;  //中断优先级控制寄存器
sbit    PPCA    =   IP^7;  //PCA中断优先级控制位（低）
sbit    PLVD    =   IP^6;  //低压检测中断优先级控制位（低）
sbit    PADC    =   IP^5;  //ADC中断优先级控制位（低）
sbit    PS      =   IP^4;  //串口1中断优先级控制位（低）
sbit    PT1     =   IP^3;  //定时器1中断优先级控制位（低）
sbit    PX1     =   IP^2;  //外部中断1中断优先级控制位（低）
sbit    PT0     =   IP^1;  //定时器0中断优先级控制位（低）
sbit    PX0     =   IP^0;  //外部中断0中断优先级控制位（低）
sfr     IP2     =   0xb5;  //中断优先级控制寄存器2
#define PI2C        0x40   //IIC中断优先级控制位（低）
#define PCMP        0x20   //比较器中断优先级控制位（低）
#define PX4         0x10   //外部中断4中断优先级控制位（低）
#define PPWMFD      0x08
#define PPWM        0x04
#define PSPI        0x02   //SPI中断优先级控制位（低）
#define PS2         0x01   //串口2中断优先级控制位（低）
sfr     IPH     =   0xb7;  //高中断优先级控制寄存器
#define PPCAH       0x80   //PCA中断优先级控制位（高）
#define PLVDH       0x40   //低压检测中断优先级控制位（高）
#define PADCH       0x20   //ADC中断优先级控制位（高）
#define PSH         0x10   //串口1中断优先级控制位（高）
#define PT1H        0x08   //定时器1中断优先级控制位（高）
#define PX1H        0x04   //外部中断1中断优先级控制位（高）
#define PT0H        0x02   //定时器0中断优先级控制位（高）
#define PX0H        0x01   //外部中断0中断优先级控制位（高）
sfr     IP2H    =   0xb6;  //高中断优先级控制寄存器2
#define PI2CH       0x40   //IIC中断优先级控制位（高）
#define PCMPH       0x20   //比较器中断优先级控制位（高）
#define PX4H        0x10   //外部中断4中断优先级控制位（高）
#define PPWMFDH     0x08
#define PPWMH       0x04
#define PSPIH       0x02   //SPI中断优先级控制位（高）
#define PS2H        0x01   //串口2中断优先级控制位（高）
sfr     IP3     =   0xDF;
sfr     IP3H    =   0xEE;
sfr     INTCLKO =   0x8f;  //外部中断与时钟输出控制寄存器
#define EX4         0x40   //外部中断4中断允许位
#define EX3         0x20   //外部中断3中断允许位
#define EX2         0x10   //外部中断2中断允许位
#define T2CLKO      0x04   //定时器2时钟输出控制
#define T1CLKO      0x02   //定时器1时钟输出控制
#define T0CLKO      0x01   //定时器0时钟输出控制
sfr     AUXINTIF=   0xef;
#define INT4IF      0x40
#define INT3IF      0x20
#define INT2IF      0x10
#define T4IF        0x04
#define T3IF        0x02
#define T2IF        0x01
/*------------------------定时器特殊功能寄存器---------------------------*/
sfr     TCON    =   0x88;  //定时器控制寄存器
sbit    TF1     =   TCON^7;//定时器1溢出中断标志位
sbit    TR1     =   TCON^6;//定时器1运行控制位
sbit    TF0     =   TCON^5;//定时器0溢出中断标志位
sbit    TR0     =   TCON^4;//定时器0运行控制位
sbit    IE1     =   TCON^3;//外部中断1请求标志位
sbit    IT1     =   TCON^2;//外部中断1触发控制位
sbit    IE0     =   TCON^1;//外部中断0请求标志位
sbit    IT0     =   TCON^0;//外部中断0触发控制位
sfr     TMOD    =   0x89;  //定时器0/1模式寄存器
#define T1_GATE     0x80   //定时器1门控位
#define T1_CT       0x40   //定时器1计数控制位
#define T1_M1       0x20   //定时器1模式选择位1
#define T1_M0       0x10   //定时器1模式选择位0
#define T0_GATE     0x08   //定时器0门控位
#define T0_CT       0x04   //定时器0计数控制位
#define T0_M1       0x02   //定时器0模式选择位1
#define T0_M0       0x01   //定时器0模式选择位0
sfr     TL0     =   0x8a;  //定时器0计数寄存器（低8位）
sfr     TL1     =   0x8b;  //定时器1计数寄存器（低8位）
sfr     TH0     =   0x8c;  //定时器0计数寄存器（高8位）
sfr     TH1     =   0x8d;  //定时器1计数寄存器（高8位）
sfr     T4T3M   =   0xd1;  //定时器4/3控制寄存器
#define T4R         0x80   //定时器4允许控制位
#define T4_CT       0x40   //定时器4计数控制位
#define T4x12       0x20   //定时器4速度控制位
#define T4CLKO      0x10   //定时器4时钟输出控制
#define T3R         0x08   //定时器3允许控制位
#define T3_CT       0x04   //定时器3计数控制位
#define T3x12       0x02   //定时器3速度控制位
#define T3CLKO      0x01   //定时器3时钟输出控制
sfr     T4H     =   0xd2;  //定时器4计数寄存器（高8位）
sfr     T4L     =   0xd3;  //定时器4计数寄存器（低8位）
sfr     T3H     =   0xd4;  //定时器3计数寄存器（高8位）
sfr     T3L     =   0xd5;  //定时器3计数寄存器（低8位）
sfr     T2H     =   0xd6;  //定时器2计数寄存器（高8位）
sfr     T2L     =   0xd7;  //定时器2计数寄存器（低8位）
sfr     WKTCL   =   0xaa;  //掉电唤醒定时器（低8位）
sfr     WKTCH   =   0xab;  //掉电唤醒定时器（高8位）
#define WKTEN       0x80   //掉电唤醒使能
/*------------------------看门狗特殊功能寄存器---------------------------*/
sfr WDT_CONTR   =   0xc1;  //看门狗控制寄存器
#define WDT_FLAG    0x80   //看门狗溢出标志位
#define EN_WDT      0x20   //看门狗使能位
#define CLR_WDT     0x10   //看门狗定时器清零
#define IDL_WDT     0x08   //空闲模式下看门狗控制位
/*-------------------------串口特殊功能寄存器----------------------------*/
sfr SCON        =   0x98;
sbit SM0        =   SCON^7;
sbit SM1        =   SCON^6;
sbit SM2        =   SCON^5;
sbit REN        =   SCON^4;
sbit TB8        =   SCON^3;
sbit RB8        =   SCON^2;
sbit TI         =   SCON^1;
sbit RI         =   SCON^0;
sfr SBUF        =   0x99;
sfr S2CON       =   0x9a;
#define S2SM0       0x80
#define S2ST4       0x40
#define S2SM2       0x20
#define S2REN       0x10
#define S2TB8       0x08
#define S2RB8       0x04
#define S2TI        0x02
#define S2RI        0x01
sfr S2BUF       =   0x9b;
sfr S3CON       =   0xac;
#define S3SM0       0x80
#define S3ST4       0x40
#define S3SM2       0x20
#define S3REN       0x10
#define S3TB8       0x08
#define S3RB8       0x04
#define S3TI        0x02
#define S3RI        0x01
sfr S3BUF       =   0xad;
sfr S4CON       =   0x84;
#define S4SM0       0x80
#define S4ST4       0x40
#define S4SM2       0x20
#define S4REN       0x10
#define S4TB8       0x08
#define S4RB8       0x04
#define S4TI        0x02
#define S4RI        0x01
sfr S4BUF       =   0x85;
sfr SADDR       =   0xa9;
sfr SADEN       =   0xb9;
/*-------------------------ADC特殊功能寄存器----------------------------*/
sfr ADC_CONTR   =   0xbc;  //ADC控制寄存器
#define ADC_POWER   0x80   //ADC电源控制位
#define ADC_START   0x40   //ADC转换启动控制位
#define ADC_FLAG    0x20   //ADC转换结束标志位
sfr ADC_RES     =   0xbd;  //ADC转换结果寄存器（高）
sfr ADC_RESL    =   0xbe;  //ADC转换结果寄存器（低）
sfr ADCCFG      =   0xde;  //ADC配置寄存器
#define ADC_RESFMT  0x20   //ADC转换结果格式控制位
#define ADCTIM      (*(unsigned char volatile xdata *)0xFEA8)//ADC时序控制寄存器
/*-------------------------SPI特殊功能寄存器----------------------------*/
sfr     SPSTAT  =   0xcd;  //SPI状态寄存器
#define SPIF        0x80   //SPI中断标志位
#define WCOL        0x40   //SPI写冲突标志位
sfr     SPCTL   =   0xce;  //SPI控制寄存器
#define SSIG        0x80   //SS引脚功能控制位
#define SPEN        0x40   //SPI使能控制位
#define DORD        0x20   //SPI数据位发送/接收顺序位
#define MSTR        0x10   //器件主/从模式选择位
#define CPOL        0x08   //SPI时钟极性控制
#define CPHA        0x04   //SPI时钟相位控制
sfr     SPDAT   =   0xcf;  //SPI数据寄存器
/*----------------------IAP/ISP特殊功能寄存器---------------------------*/
sfr IAP_DATA    =   0xc2;  //IAP数据寄存器
sfr IAP_ADDRH   =   0xc3;  //IAP高地址寄存器
sfr IAP_ADDRL   =   0xc4;  //IAP低地址寄存器
sfr IAP_CMD     =   0xc5;  //IAP命令寄存器
#define IAP_IDL     0x00
#define IAP_READ    0x01
#define IAP_WRITE   0x02
#define IAP_ERASE   0x03
sfr IAP_TRIG    =   0xc6;  //IAP触发寄存器
sfr IAP_CONTR   =   0xc7;  //IAP控制寄存器
sfr IAP_TPS     =   0xf5;  //EEPROM擦除等待时间控制寄存器
#define IAPEN       0x80   //EEPROM操作使能控制位
#define SWBS        0x40   //软件复位选择控制位
#define SWRST       0x20   //软件复位操作
#define CMD_FAIL    0x10   //EEPROM操作失败状态位
sfr ISP_DATA    =   0xc2;  //ISP数据寄存器
sfr ISP_ADDRH   =   0xc3;  //ISP高地址寄存器
sfr ISP_ADDRL   =   0xc4;  //ISP低地址寄存器
sfr ISP_CMD     =   0xc5;  //ISP命令寄存器
sfr ISP_TRIG    =   0xc6;  //ISP触发寄存器
sfr ISP_CONTR   =   0xc7;  //ISP控制寄存器
/*------------------------比较器特殊功能寄存器---------------------------*/
sfr     CMPCR1  =   0xe6;  //比较器控制寄存器1
#define CMPEN       0x80   //比较器使能位
#define CMPIF       0x40   //比较器中断标志位
#define PIE         0x20   //比较器上升沿中断使能位
#define NIE         0x10   //比较器下降沿中断使能位
#define PIS         0x08   //比较器正极选择位
#define NIS         0x04   //比较器负极选择位
#define CMPOE       0x02   //比较器结果输出控制位
#define CMPRES      0x01   //比较器结果
sfr     CMPCR2  =   0xe7;  //比较器控制寄存器2
#define INVCMPO     0x80   //比较器结果输出控制
#define DISFLT      0x40   //模拟滤波功能控制

//PCA/PWM 特殊功能寄存器
sfr CCON        =   0xd8;
sbit CF         =   CCON^7;
sbit CR         =   CCON^6;
sbit CCF3       =   CCON^3;
sbit CCF2       =   CCON^2;
sbit CCF1       =   CCON^1;
sbit CCF0       =   CCON^0;
sfr CMOD        =   0xd9;
#define CIDL        0x80
#define ECF         0x01
sfr CL          =   0xe9;
sfr CH          =   0xf9;
sfr CCAPM0      =   0xda;
#define ECOM0       0x40
#define CCAPP0      0x20
#define CCAPN0      0x10
#define MAT0        0x08
#define TOG0        0x04
#define PWM0        0x02
#define ECCF0       0x01
sfr CCAPM1      =   0xdb;
#define ECOM1       0x40
#define CCAPP1      0x20
#define CCAPN1      0x10
#define MAT1        0x08
#define TOG1        0x04
#define PWM1        0x02
#define ECCF1       0x01
sfr CCAPM2      =   0xdc;
#define ECOM2       0x40
#define CCAPP2      0x20
#define CCAPN2      0x10
#define MAT2        0x08
#define TOG2        0x04
#define PWM2        0x02
#define ECCF2       0x01
sfr CCAPM3      =   0xdd;
#define ECOM3       0x40
#define CCAPP3      0x20
#define CCAPN3      0x10
#define MAT3        0x08
#define TOG3        0x04
#define PWM3        0x02
#define ECCF3       0x01
sfr CCAP0L      =   0xea;
sfr CCAP1L      =   0xeb;
sfr CCAP2L      =   0xec;
sfr CCAP3L      =   0xed;
sfr CCAP0H      =   0xfa;
sfr CCAP1H      =   0xfb;
sfr CCAP2H      =   0xfc;
sfr CCAP3H      =   0xfd;
sfr PCA_PWM0    =   0xf2;
sfr PCA_PWM1    =   0xf3;
sfr PCA_PWM2    =   0xf4;
sfr PCA_PWM3    =   0xf5;

//增强型PWM波形发生器特殊功能寄存器
sfr PWMCFG      =   0xf1;
#define CBIF        0x80
#define ETADC       0x40
sfr PWMIF       =   0xf6;
#define C7IF        0x80
#define C6IF        0x40
#define C5IF        0x20
#define C4IF        0x10
#define C3IF        0x08
#define C2IF        0x04
#define C1IF        0x02
#define C0IF        0x01
sfr PWMFDCR     =   0xf7;
#define INVCMP      0x80
#define INVIO       0x40
#define ENFD        0x20
#define FLTFLIO     0x10
#define EFDI        0x08
#define FDCMP       0x04
#define FDIO        0x02
#define FDIF        0x01
sfr PWMCR       =   0xfe;
#define ENPWM       0x80
#define ECBI        0x40

//如下特殊功能寄存器位于扩展RAM区域
//访问这些寄存器,需先将P_SW2的BIT7设置为1,才可正常读写
#define PWMC        (*(unsigned int  volatile xdata *)0xfff0)
#define PWMCH       (*(unsigned char volatile xdata *)0xfff0)
#define PWMCL       (*(unsigned char volatile xdata *)0xfff1)
#define PWMCKS      (*(unsigned char volatile xdata *)0xfff2)
#define TADCP       (*(unsigned char volatile xdata *)0xfff3)
#define TADCPH      (*(unsigned char volatile xdata *)0xfff3)
#define TADCPL      (*(unsigned char volatile xdata *)0xfff4)


#define PWM0T1      (*(unsigned int  volatile xdata *)0xff00)
#define PWM0T1H     (*(unsigned char volatile xdata *)0xff00)
#define PWM0T1L     (*(unsigned char volatile xdata *)0xff01)
#define PWM0T2      (*(unsigned int  volatile xdata *)0xff02)
#define PWM0T2H     (*(unsigned char volatile xdata *)0xff02)
#define PWM0T2L     (*(unsigned char volatile xdata *)0xff03)
#define PWM0CR      (*(unsigned char volatile xdata *)0xff04)
#define PWM0HLD     (*(unsigned char volatile xdata *)0xff05)

#define PWM1T1      (*(unsigned int  volatile xdata *)0xff10)
#define PWM1T1H     (*(unsigned char volatile xdata *)0xff10)
#define PWM1T1L     (*(unsigned char volatile xdata *)0xff11)
#define PWM1T2      (*(unsigned int  volatile xdata *)0xff12)
#define PWM1T2H     (*(unsigned char volatile xdata *)0xff12)
#define PWM1T2L     (*(unsigned char volatile xdata *)0xff13)
#define PWM1CR      (*(unsigned char volatile xdata *)0xff14)
#define PWM1HLD     (*(unsigned char volatile xdata *)0xff15)

#define PWM2T1      (*(unsigned int  volatile xdata *)0xff20)
#define PWM2T1H     (*(unsigned char volatile xdata *)0xff20)
#define PWM2T1L     (*(unsigned char volatile xdata *)0xff21)
#define PWM2T2      (*(unsigned int  volatile xdata *)0xff22)
#define PWM2T2H     (*(unsigned char volatile xdata *)0xff22)
#define PWM2T2L     (*(unsigned char volatile xdata *)0xff23)
#define PWM2CR      (*(unsigned char volatile xdata *)0xff24)
#define PWM2HLD     (*(unsigned char volatile xdata *)0xff25)

#define PWM3T1      (*(unsigned int  volatile xdata *)0xff30)
#define PWM3T1H     (*(unsigned char volatile xdata *)0xff30)
#define PWM3T1L     (*(unsigned char volatile xdata *)0xff31)
#define PWM3T2      (*(unsigned int  volatile xdata *)0xff32)
#define PWM3T2H     (*(unsigned char volatile xdata *)0xff32)
#define PWM3T2L     (*(unsigned char volatile xdata *)0xff33)
#define PWM3CR      (*(unsigned char volatile xdata *)0xff34)
#define PWM3HLD     (*(unsigned char volatile xdata *)0xff35)

#define PWM4T1      (*(unsigned int  volatile xdata *)0xff40)
#define PWM4T1H     (*(unsigned char volatile xdata *)0xff40)
#define PWM4T1L     (*(unsigned char volatile xdata *)0xff41)
#define PWM4T2      (*(unsigned int  volatile xdata *)0xff42)
#define PWM4T2H     (*(unsigned char volatile xdata *)0xff42)
#define PWM4T2L     (*(unsigned char volatile xdata *)0xff43)
#define PWM4CR      (*(unsigned char volatile xdata *)0xff44)
#define PWM4HLD     (*(unsigned char volatile xdata *)0xff45)

#define PWM5T1      (*(unsigned int  volatile xdata *)0xff50)
#define PWM5T1H     (*(unsigned char volatile xdata *)0xff50)
#define PWM5T1L     (*(unsigned char volatile xdata *)0xff51)
#define PWM5T2      (*(unsigned int  volatile xdata *)0xff52)
#define PWM5T2H     (*(unsigned char volatile xdata *)0xff52)
#define PWM5T2L     (*(unsigned char volatile xdata *)0xff53)
#define PWM5CR      (*(unsigned char volatile xdata *)0xff54)
#define PWM5HLD     (*(unsigned char volatile xdata *)0xff55)

#define PWM6T1      (*(unsigned int  volatile xdata *)0xff60)
#define PWM6T1H     (*(unsigned char volatile xdata *)0xff60)
#define PWM6T1L     (*(unsigned char volatile xdata *)0xff61)
#define PWM6T2      (*(unsigned int  volatile xdata *)0xff62)
#define PWM6T2H     (*(unsigned char volatile xdata *)0xff62)
#define PWM6T2L     (*(unsigned char volatile xdata *)0xff63)
#define PWM6CR      (*(unsigned char volatile xdata *)0xff64)
#define PWM6HLD     (*(unsigned char volatile xdata *)0xff65)

#define PWM7T1      (*(unsigned int  volatile xdata *)0xff70)
#define PWM7T1H     (*(unsigned char volatile xdata *)0xff70)
#define PWM7T1L     (*(unsigned char volatile xdata *)0xff71)
#define PWM7T2      (*(unsigned int  volatile xdata *)0xff72)
#define PWM7T2H     (*(unsigned char volatile xdata *)0xff72)
#define PWM7T2L     (*(unsigned char volatile xdata *)0xff73)
#define PWM7CR      (*(unsigned char volatile xdata *)0xff74)
#define PWM7HLD     (*(unsigned char volatile xdata *)0xff75)
/*-------------------------IIC特殊功能寄存器-----------------------------*/
#define I2CCFG      (*(unsigned char volatile xdata *)0xfe80)//IIC配置寄存器
#define ENI2C       0x80//IIC功能使能控制位
#define MSSL        0x40//IIC工作模式选择位
#define I2CMSCR     (*(unsigned char volatile xdata *)0xfe81)//IIC主机控制寄存器
#define EMSI        0x80//主机模式中断使能控制位
#define I2CMSST     (*(unsigned char volatile xdata *)0xfe82)//IIC主机状态寄存器
#define MSBUSY      0x80//主机模式时IIC控制器状态位
#define MSIF        0x40//主机模式时的中断请求位
#define MSACKI      0x02//主机模式时，接收到的ACK
#define MSACKO      0x01//主机模式时，要发送的ACK
#define I2CSLCR     (*(unsigned char volatile xdata *)0xfe83)//IIC从机控制寄存器
#define ESTAI       0x40//从机模式时接收START信号中断允许位
#define ERXI        0x20//从机模式时接收到1字节数据后中断允许位
#define ETXI        0x10//从机模式时发送完1字节数据后中断允许位
#define ESTOI       0x08//从机模式时接收STOP信号中断允许位
#define SLRST       0x01//复位从机模式
#define I2CSLST     (*(unsigned char volatile xdata *)0xfe84)//IIC从机状态寄存器
#define SLBUSY      0x80//从机模式时IIC控制器状态位
#define STAIF       0x40//从机模式时接收START信号中断请求位
#define RXIF        0x20//从机模式时接收到1字节数据后中断请求位
#define TXIF        0x10//从机模式时发送完1字节数据后中断请求位
#define STOIF       0x08//从机模式时接收STOP信号中断请求位
#define TXING       0x04
#define SLACKI      0x02//从机模式时接收到的ACK
#define SLACKO      0x01//从机模式时，将要发送的ACK
#define I2CSLADR    (*(unsigned char volatile xdata *)0xfe85)//IIC从机地址寄存器
#define I2CTXD      (*(unsigned char volatile xdata *)0xfe86)//IIC发送数据寄存器
#define I2CRXD      (*(unsigned char volatile xdata *)0xfe87)//IIC接收数据寄存器
#define I2CMSAUX    (*(unsigned char volatile xdata *)0xfe88)//IIC主机辅助控制寄存器
#endif
