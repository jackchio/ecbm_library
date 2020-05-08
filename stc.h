#ifndef __ECBM_H_
#define __ECBM_H_
//V2.1�汾
//������STC8F��STC8A��STC8G�ļĴ�����
/////////////////////////////////////////////////

//������ͷ�ļ���,���������ٰ���"REG51.H"



#define     TM2PS       (*(unsigned char volatile xdata *)0xFEA2)
#define     TM3PS       (*(unsigned char volatile xdata *)0xFEA3)
#define     TM4PS       (*(unsigned char volatile xdata *)0xFEA4)



//��ͻ�Ĳ���
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


/*--------------------------�ں����⹦�ܼĴ���--------------------------*/
sfr     ACC     =   0xe0;  //�ۼ���
sfr     B       =   0xf0;  //B�Ĵ���
sfr     PSW     =   0xd0;  //����״̬�ּĴ���
sbit    CY      =   PSW^7; //��λ��־λ
sbit    AC      =   PSW^6; //������λ��־λ
sbit    F0      =   PSW^5; //�����û��ı�־λ
sbit    RS1     =   PSW^4; //�����Ĵ���ѡ��λ����λ��
sbit    RS0     =   PSW^3; //�����Ĵ���ѡ��λ����λ��
sbit    OV      =   PSW^2; //�����־λ
sbit    P       =   PSW^0; //��żУ��λ
sfr     SP      =   0x81;  //��ջָ��
sfr     DPL     =   0x82;  //����ָ�루���ֽڣ�
sfr     DPH     =   0x83;  //����ָ�루���ֽڣ�
sfr     TA      =   0xae;  //DPTRʱ����ƼĴ���
sfr     DPS     =   0xe3;  //DPTRָ��ѡ����
sfr     DPL1    =   0xe4;  //�ڶ�������ָ�루���ֽڣ�
sfr     DPH1    =   0xe5;  //�ڶ�������ָ�루���ֽڣ�
/*-------------------------I/O�����⹦�ܼĴ���--------------------------*/
sfr     P0      =   0x80;  //P0�˿�
sbit    P00     =   P0^0;  //P0.0��
sbit    P01     =   P0^1;  //P0.1��
sbit    P02     =   P0^2;  //P0.2��
sbit    P03     =   P0^3;  //P0.3��
sbit    P04     =   P0^4;  //P0.4��
sbit    P05     =   P0^5;  //P0.5��
sbit    P06     =   P0^6;  //P0.6��
sbit    P07     =   P0^7;  //P0.7��
sfr     P0M0    =   0x94;  //P0�����üĴ���0
sfr     P0M1    =   0x93;  //P0�����üĴ���1
#define P0PU    (*(unsigned char volatile xdata *)0xfe10)//P0������������ƼĴ���
#define P0NCS   (*(unsigned char volatile xdata *)0xfe18)//P0��ʩ���ش������ƼĴ���


sfr     P1      =   0x90;  //P1�˿�
sbit    P10     =   P1^0;  //P1.0��
sbit    P11     =   P1^1;  //P1.1��
sbit    P12     =   P1^2;  //P1.2��
sbit    P13     =   P1^3;  //P1.3��
sbit    P14     =   P1^4;  //P1.4��
sbit    P15     =   P1^5;  //P1.5��
sbit    P16     =   P1^6;  //P1.6��
sbit    P17     =   P1^7;  //P1.7��
sfr     P1M0    =   0x92;  //P1�����üĴ���0
sfr     P1M1    =   0x91;  //P1�����üĴ���1
#define P1PU    (*(unsigned char volatile xdata *)0xfe11)//P1������������ƼĴ���
#define P1NCS   (*(unsigned char volatile xdata *)0xfe19)//P1��ʩ���ش������ƼĴ���


sfr     P2      =   0xa0;  //P2�˿�
sbit    P20     =   P2^0;  //P2.0��
sbit    P21     =   P2^1;  //P2.1��
sbit    P22     =   P2^2;  //P2.2��
sbit    P23     =   P2^3;  //P2.3��
sbit    P24     =   P2^4;  //P2.4��
sbit    P25     =   P2^5;  //P2.5��
sbit    P26     =   P2^6;  //P2.6��
sbit    P27     =   P2^7;  //P2.7��
sfr     P2M0    =   0x96;  //P2�����üĴ���0
sfr     P2M1    =   0x95;  //P2�����üĴ���1
#define P2PU    (*(unsigned char volatile xdata *)0xfe12)//P2������������ƼĴ���
#define P2NCS   (*(unsigned char volatile xdata *)0xfe1a)//P2��ʩ���ش������ƼĴ���


sfr     P3      =   0xb0;  //P3�˿�
sbit    P30     =   P3^0;  //P3.0��
sbit    P31     =   P3^1;  //P3.1��
sbit    P32     =   P3^2;  //P3.2��
sbit    P33     =   P3^3;  //P3.3��
sbit    P34     =   P3^4;  //P3.4��
sbit    P35     =   P3^5;  //P3.5��
sbit    P36     =   P3^6;  //P3.6��
sbit    P37     =   P3^7;  //P3.7��
sfr     P3M0    =   0xb2;  //P3�����üĴ���0
sfr     P3M1    =   0xb1;  //P3�����üĴ���1
#define P3PU    (*(unsigned char volatile xdata *)0xfe13)//P3������������ƼĴ���
#define P3NCS   (*(unsigned char volatile xdata *)0xfe1b)//P3��ʩ���ش������ƼĴ���

sfr     P4      =   0xc0;  //P4�˿�
sbit    P40     =   P4^0;  //P4.0��
sbit    P41     =   P4^1;  //P4.1��
sbit    P42     =   P4^2;  //P4.2��
sbit    P43     =   P4^3;  //P4.3��
sbit    P44     =   P4^4;  //P4.4��
sbit    P45     =   P4^5;  //P4.5��
sbit    P46     =   P4^6;  //P4.6��
sbit    P47     =   P4^7;  //P4.7��
sfr     P4M0    =   0xb4;  //P4�����üĴ���0
sfr     P4M1    =   0xb3;  //P4�����üĴ���1
#define P4PU    (*(unsigned char volatile xdata *)0xfe14)//P4������������ƼĴ���
#define P4NCS   (*(unsigned char volatile xdata *)0xfe1c)//P4��ʩ���ش������ƼĴ���

sfr     P5      =   0xc8;  //P5�˿�
sbit    P50     =   P5^0;  //P5.0��
sbit    P51     =   P5^1;  //P5.1��
sbit    P52     =   P5^2;  //P5.2��
sbit    P53     =   P5^3;  //P5.3��
sbit    P54     =   P5^4;  //P5.4��
sbit    P55     =   P5^5;  //P5.5��
sbit    P56     =   P5^6;  //P5.6��
sbit    P57     =   P5^7;  //P5.7��
sfr     P5M0    =   0xca;  //P5�����üĴ���0
sfr     P5M1    =   0xc9;  //P5�����üĴ���1
#define P5PU    (*(unsigned char volatile xdata *)0xfe15)//P5������������ƼĴ���
#define P5NCS   (*(unsigned char volatile xdata *)0xfe1d)//P5��ʩ���ش������ƼĴ���

sfr     P6      =   0xe8;  //P6�˿�
sbit    P60     =   P6^0;  //P6.0��
sbit    P61     =   P6^1;  //P6.1��
sbit    P62     =   P6^2;  //P6.2��
sbit    P63     =   P6^3;  //P6.3��
sbit    P64     =   P6^4;  //P6.4��
sbit    P65     =   P6^5;  //P6.5��
sbit    P66     =   P6^6;  //P6.6��
sbit    P67     =   P6^7;  //P6.7��
sfr     P6M0    =   0xcc;  //P6�����üĴ���0
sfr     P6M1    =   0xcb;  //P6�����üĴ���1
#define P6PU    (*(unsigned char volatile xdata *)0xfe16)//P6������������ƼĴ���
#define P6NCS   (*(unsigned char volatile xdata *)0xfe1e)//P6��ʩ���ش������ƼĴ���

sfr     P7      =   0xf8;  //P7�˿�
sbit    P70     =   P7^0;  //P7.0��
sbit    P71     =   P7^1;  //P7.1��
sbit    P72     =   P7^2;  //P7.2��
sbit    P73     =   P7^3;  //P7.3��
sbit    P74     =   P7^4;  //P7.4��
sbit    P75     =   P7^5;  //P7.5��
sbit    P76     =   P7^6;  //P7.6��
sbit    P77     =   P7^7;  //P7.7��
sfr     P7M0    =   0xe2;  //P7�����üĴ���0
sfr     P7M1    =   0xe1;  //P7�����üĴ���7
#define P7PU    (*(unsigned char volatile xdata *)0xfe17)//P7������������ƼĴ���
#define P7NCS   (*(unsigned char volatile xdata *)0xfe1f)//P7��ʩ���ش������ƼĴ���

/*-----------------------ϵͳ�������⹦�ܼĴ���--------------------------*/
sfr     PCON    =   0x87;  //��Դ���ƼĴ���
#define SMOD        0x80   //����1�����ʿ���λ
#define SMOD0       0x40   //֡���������λ
#define LVDF        0x20   //��ѹ����ж������־
#define POF         0x10   //�ϵ��־λ
#define GF1         0x08   //�û�ר�ñ�־λ
#define GF0         0x04   //�û�ר�ñ�־λ
#define PD          0x02   //����ģʽ����λ
#define IDL         0x01   //����ģʽ����λ
sfr     AUXR    =   0x8e;  //�����Ĵ���1
#define T0x12       0x80   //��ʱ��0�ٶȿ���λ 
#define T1x12       0x40   //��ʱ��1�ٶȿ���λ
#define UART_M0x6   0x20   //����1ģʽ0��ͨѶ�ٶȿ���λ
#define T2R         0x10   //��ʱ��2���п���λ
#define T2_CT       0x08   //��ʱ��2��������λ
#define T2x12       0x04   //��ʱ��2�ٶȿ���λ
#define EXTRAM      0x02   //��չRAM���ʿ���λ
#define S1ST2       0x01   //����1�����ʷ�����ѡ��Ϊλ
sfr     AUXR2   =   0x97;  //�����Ĵ���2
#define TXLNRX      0x10   
sfr BUS_SPEED   =   0xa1;  //�����ٶȿ��ƼĴ���
sfr     P_SW1   =   0xa2;  //����˿��л��Ĵ���1
sfr     P_SW2   =   0xba;  //����˿��л��Ĵ���2
#define EAXFR       0x80
sfr     VOCTRL  =   0xbb;  //��ѹ���ƼĴ���
sfr     RSTCFG  =   0xff;  //��λ���üĴ���
/*-----------------------ʱ�ӹ������⹦�ܼĴ���--------------------------*/
#define CKSEL       (*(unsigned char volatile xdata *)0xfe00)//ʱ��ѡ��Ĵ���
#define CLKDIV      (*(unsigned char volatile xdata *)0xfe01)//ʱ�ӷ�Ƶ�Ĵ���
#define HIRCCR      (*(unsigned char volatile xdata *)0xfe02)//�ڲ������������ƼĴ���
#define XOSCCR      (*(unsigned char volatile xdata *)0xfe03)//�ⲿ������ƼĴ���
#define IRC32KCR    (*(unsigned char volatile xdata *)0xfe04)//�ڲ�32K�������ƼĴ���
#define MCLKOCR     (*(unsigned char volatile xdata *)0xFE05)//��ʱ��������ƼĴ���
#define IRCDB       (*(unsigned char volatile xdata *)0xFE06)//�ڲ���������ȥ�����ƼĴ���
sfr     IRTRIM  =   0x9F;  //�ڲ��߾���IRCƵ�ʵ����Ĵ���
sfr     LIRTRIM =   0x9E;  //�ڲ��߾���IRCƵ��΢���Ĵ���
sfr     IRCBAND =   0x9D;  //IRCƵ��ѡ��Ĵ���
/*-------------------------�ж����⹦�ܼĴ���----------------------------*/
sfr     IE      =   0xa8;  //�ж�����Ĵ���
sbit    EA      =   IE^7;  //���ж��������λ
sbit    ELVD    =   IE^6;  //��ѹ����ж�����λ
sbit    EADC    =   IE^5;  //A/Dת���ж�����λ
sbit    ES      =   IE^4;  //����1�ж�����λ
sbit    ET1     =   IE^3;  //��ʱ��1�ж�����λ
sbit    EX1     =   IE^2;  //�ⲿ�ж�1����λ
sbit    ET0     =   IE^1;  //��ʱ��0�ж�����λ
sbit    EX0     =   IE^0;  //�ⲿ�ж�0����λ
sfr     IE2     =   0xaf;  //�ж�����Ĵ���2
#define ETKSUI      0x80   //���������ж�����λ
#define ET4         0x40   //��ʱ��4�ж�����λ
#define ET3         0x20   //��ʱ��3�ж�����λ
#define ES4         0x10   //����4�ж�����λ
#define ES3         0x08   //����3�ж�����λ
#define ET2         0x04   //��ʱ��2�ж�����λ
#define ESPI        0x02   //SPI�ж�����λ
#define ES2         0x01   //����2�ж�����λ
sfr     IP      =   0xb8;  //�ж����ȼ����ƼĴ���
sbit    PPCA    =   IP^7;  //PCA�ж����ȼ�����λ���ͣ�
sbit    PLVD    =   IP^6;  //��ѹ����ж����ȼ�����λ���ͣ�
sbit    PADC    =   IP^5;  //ADC�ж����ȼ�����λ���ͣ�
sbit    PS      =   IP^4;  //����1�ж����ȼ�����λ���ͣ�
sbit    PT1     =   IP^3;  //��ʱ��1�ж����ȼ�����λ���ͣ�
sbit    PX1     =   IP^2;  //�ⲿ�ж�1�ж����ȼ�����λ���ͣ�
sbit    PT0     =   IP^1;  //��ʱ��0�ж����ȼ�����λ���ͣ�
sbit    PX0     =   IP^0;  //�ⲿ�ж�0�ж����ȼ�����λ���ͣ�
sfr     IP2     =   0xb5;  //�ж����ȼ����ƼĴ���2
#define PI2C        0x40   //IIC�ж����ȼ�����λ���ͣ�
#define PCMP        0x20   //�Ƚ����ж����ȼ�����λ���ͣ�
#define PX4         0x10   //�ⲿ�ж�4�ж����ȼ�����λ���ͣ�
#define PPWMFD      0x08
#define PPWM        0x04
#define PSPI        0x02   //SPI�ж����ȼ�����λ���ͣ�
#define PS2         0x01   //����2�ж����ȼ�����λ���ͣ�
sfr     IPH     =   0xb7;  //���ж����ȼ����ƼĴ���
#define PPCAH       0x80   //PCA�ж����ȼ�����λ���ߣ�
#define PLVDH       0x40   //��ѹ����ж����ȼ�����λ���ߣ�
#define PADCH       0x20   //ADC�ж����ȼ�����λ���ߣ�
#define PSH         0x10   //����1�ж����ȼ�����λ���ߣ�
#define PT1H        0x08   //��ʱ��1�ж����ȼ�����λ���ߣ�
#define PX1H        0x04   //�ⲿ�ж�1�ж����ȼ�����λ���ߣ�
#define PT0H        0x02   //��ʱ��0�ж����ȼ�����λ���ߣ�
#define PX0H        0x01   //�ⲿ�ж�0�ж����ȼ�����λ���ߣ�
sfr     IP2H    =   0xb6;  //���ж����ȼ����ƼĴ���2
#define PI2CH       0x40   //IIC�ж����ȼ�����λ���ߣ�
#define PCMPH       0x20   //�Ƚ����ж����ȼ�����λ���ߣ�
#define PX4H        0x10   //�ⲿ�ж�4�ж����ȼ�����λ���ߣ�
#define PPWMFDH     0x08
#define PPWMH       0x04
#define PSPIH       0x02   //SPI�ж����ȼ�����λ���ߣ�
#define PS2H        0x01   //����2�ж����ȼ�����λ���ߣ�
sfr     IP3     =   0xDF;
sfr     IP3H    =   0xEE;
sfr     INTCLKO =   0x8f;  //�ⲿ�ж���ʱ��������ƼĴ���
#define EX4         0x40   //�ⲿ�ж�4�ж�����λ
#define EX3         0x20   //�ⲿ�ж�3�ж�����λ
#define EX2         0x10   //�ⲿ�ж�2�ж�����λ
#define T2CLKO      0x04   //��ʱ��2ʱ���������
#define T1CLKO      0x02   //��ʱ��1ʱ���������
#define T0CLKO      0x01   //��ʱ��0ʱ���������
sfr     AUXINTIF=   0xef;
#define INT4IF      0x40
#define INT3IF      0x20
#define INT2IF      0x10
#define T4IF        0x04
#define T3IF        0x02
#define T2IF        0x01
/*------------------------��ʱ�����⹦�ܼĴ���---------------------------*/
sfr     TCON    =   0x88;  //��ʱ�����ƼĴ���
sbit    TF1     =   TCON^7;//��ʱ��1����жϱ�־λ
sbit    TR1     =   TCON^6;//��ʱ��1���п���λ
sbit    TF0     =   TCON^5;//��ʱ��0����жϱ�־λ
sbit    TR0     =   TCON^4;//��ʱ��0���п���λ
sbit    IE1     =   TCON^3;//�ⲿ�ж�1�����־λ
sbit    IT1     =   TCON^2;//�ⲿ�ж�1��������λ
sbit    IE0     =   TCON^1;//�ⲿ�ж�0�����־λ
sbit    IT0     =   TCON^0;//�ⲿ�ж�0��������λ
sfr     TMOD    =   0x89;  //��ʱ��0/1ģʽ�Ĵ���
#define T1_GATE     0x80   //��ʱ��1�ſ�λ
#define T1_CT       0x40   //��ʱ��1��������λ
#define T1_M1       0x20   //��ʱ��1ģʽѡ��λ1
#define T1_M0       0x10   //��ʱ��1ģʽѡ��λ0
#define T0_GATE     0x08   //��ʱ��0�ſ�λ
#define T0_CT       0x04   //��ʱ��0��������λ
#define T0_M1       0x02   //��ʱ��0ģʽѡ��λ1
#define T0_M0       0x01   //��ʱ��0ģʽѡ��λ0
sfr     TL0     =   0x8a;  //��ʱ��0�����Ĵ�������8λ��
sfr     TL1     =   0x8b;  //��ʱ��1�����Ĵ�������8λ��
sfr     TH0     =   0x8c;  //��ʱ��0�����Ĵ�������8λ��
sfr     TH1     =   0x8d;  //��ʱ��1�����Ĵ�������8λ��
sfr     T4T3M   =   0xd1;  //��ʱ��4/3���ƼĴ���
#define T4R         0x80   //��ʱ��4�������λ
#define T4_CT       0x40   //��ʱ��4��������λ
#define T4x12       0x20   //��ʱ��4�ٶȿ���λ
#define T4CLKO      0x10   //��ʱ��4ʱ���������
#define T3R         0x08   //��ʱ��3�������λ
#define T3_CT       0x04   //��ʱ��3��������λ
#define T3x12       0x02   //��ʱ��3�ٶȿ���λ
#define T3CLKO      0x01   //��ʱ��3ʱ���������
sfr     T4H     =   0xd2;  //��ʱ��4�����Ĵ�������8λ��
sfr     T4L     =   0xd3;  //��ʱ��4�����Ĵ�������8λ��
sfr     T3H     =   0xd4;  //��ʱ��3�����Ĵ�������8λ��
sfr     T3L     =   0xd5;  //��ʱ��3�����Ĵ�������8λ��
sfr     T2H     =   0xd6;  //��ʱ��2�����Ĵ�������8λ��
sfr     T2L     =   0xd7;  //��ʱ��2�����Ĵ�������8λ��
sfr     WKTCL   =   0xaa;  //���绽�Ѷ�ʱ������8λ��
sfr     WKTCH   =   0xab;  //���绽�Ѷ�ʱ������8λ��
#define WKTEN       0x80   //���绽��ʹ��
/*------------------------���Ź����⹦�ܼĴ���---------------------------*/
sfr WDT_CONTR   =   0xc1;  //���Ź����ƼĴ���
#define WDT_FLAG    0x80   //���Ź������־λ
#define EN_WDT      0x20   //���Ź�ʹ��λ
#define CLR_WDT     0x10   //���Ź���ʱ������
#define IDL_WDT     0x08   //����ģʽ�¿��Ź�����λ
/*-------------------------�������⹦�ܼĴ���----------------------------*/
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
/*-------------------------ADC���⹦�ܼĴ���----------------------------*/
sfr ADC_CONTR   =   0xbc;  //ADC���ƼĴ���
#define ADC_POWER   0x80   //ADC��Դ����λ
#define ADC_START   0x40   //ADCת����������λ
#define ADC_FLAG    0x20   //ADCת��������־λ
sfr ADC_RES     =   0xbd;  //ADCת������Ĵ������ߣ�
sfr ADC_RESL    =   0xbe;  //ADCת������Ĵ������ͣ�
sfr ADCCFG      =   0xde;  //ADC���üĴ���
#define ADC_RESFMT  0x20   //ADCת�������ʽ����λ
#define ADCTIM      (*(unsigned char volatile xdata *)0xFEA8)//ADCʱ����ƼĴ���
/*-------------------------SPI���⹦�ܼĴ���----------------------------*/
sfr     SPSTAT  =   0xcd;  //SPI״̬�Ĵ���
#define SPIF        0x80   //SPI�жϱ�־λ
#define WCOL        0x40   //SPIд��ͻ��־λ
sfr     SPCTL   =   0xce;  //SPI���ƼĴ���
#define SSIG        0x80   //SS���Ź��ܿ���λ
#define SPEN        0x40   //SPIʹ�ܿ���λ
#define DORD        0x20   //SPI����λ����/����˳��λ
#define MSTR        0x10   //������/��ģʽѡ��λ
#define CPOL        0x08   //SPIʱ�Ӽ��Կ���
#define CPHA        0x04   //SPIʱ����λ����
sfr     SPDAT   =   0xcf;  //SPI���ݼĴ���
/*----------------------IAP/ISP���⹦�ܼĴ���---------------------------*/
sfr IAP_DATA    =   0xc2;  //IAP���ݼĴ���
sfr IAP_ADDRH   =   0xc3;  //IAP�ߵ�ַ�Ĵ���
sfr IAP_ADDRL   =   0xc4;  //IAP�͵�ַ�Ĵ���
sfr IAP_CMD     =   0xc5;  //IAP����Ĵ���
#define IAP_IDL     0x00
#define IAP_READ    0x01
#define IAP_WRITE   0x02
#define IAP_ERASE   0x03
sfr IAP_TRIG    =   0xc6;  //IAP�����Ĵ���
sfr IAP_CONTR   =   0xc7;  //IAP���ƼĴ���
sfr IAP_TPS     =   0xf5;  //EEPROM�����ȴ�ʱ����ƼĴ���
#define IAPEN       0x80   //EEPROM����ʹ�ܿ���λ
#define SWBS        0x40   //�����λѡ�����λ
#define SWRST       0x20   //�����λ����
#define CMD_FAIL    0x10   //EEPROM����ʧ��״̬λ
sfr ISP_DATA    =   0xc2;  //ISP���ݼĴ���
sfr ISP_ADDRH   =   0xc3;  //ISP�ߵ�ַ�Ĵ���
sfr ISP_ADDRL   =   0xc4;  //ISP�͵�ַ�Ĵ���
sfr ISP_CMD     =   0xc5;  //ISP����Ĵ���
sfr ISP_TRIG    =   0xc6;  //ISP�����Ĵ���
sfr ISP_CONTR   =   0xc7;  //ISP���ƼĴ���
/*------------------------�Ƚ������⹦�ܼĴ���---------------------------*/
sfr     CMPCR1  =   0xe6;  //�Ƚ������ƼĴ���1
#define CMPEN       0x80   //�Ƚ���ʹ��λ
#define CMPIF       0x40   //�Ƚ����жϱ�־λ
#define PIE         0x20   //�Ƚ����������ж�ʹ��λ
#define NIE         0x10   //�Ƚ����½����ж�ʹ��λ
#define PIS         0x08   //�Ƚ�������ѡ��λ
#define NIS         0x04   //�Ƚ�������ѡ��λ
#define CMPOE       0x02   //�Ƚ�������������λ
#define CMPRES      0x01   //�Ƚ������
sfr     CMPCR2  =   0xe7;  //�Ƚ������ƼĴ���2
#define INVCMPO     0x80   //�Ƚ�������������
#define DISFLT      0x40   //ģ���˲����ܿ���

//PCA/PWM ���⹦�ܼĴ���
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

//��ǿ��PWM���η��������⹦�ܼĴ���
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

//�������⹦�ܼĴ���λ����չRAM����
//������Щ�Ĵ���,���Ƚ�P_SW2��BIT7����Ϊ1,�ſ�������д
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
/*-------------------------IIC���⹦�ܼĴ���-----------------------------*/
#define I2CCFG      (*(unsigned char volatile xdata *)0xfe80)//IIC���üĴ���
#define ENI2C       0x80//IIC����ʹ�ܿ���λ
#define MSSL        0x40//IIC����ģʽѡ��λ
#define I2CMSCR     (*(unsigned char volatile xdata *)0xfe81)//IIC�������ƼĴ���
#define EMSI        0x80//����ģʽ�ж�ʹ�ܿ���λ
#define I2CMSST     (*(unsigned char volatile xdata *)0xfe82)//IIC����״̬�Ĵ���
#define MSBUSY      0x80//����ģʽʱIIC������״̬λ
#define MSIF        0x40//����ģʽʱ���ж�����λ
#define MSACKI      0x02//����ģʽʱ�����յ���ACK
#define MSACKO      0x01//����ģʽʱ��Ҫ���͵�ACK
#define I2CSLCR     (*(unsigned char volatile xdata *)0xfe83)//IIC�ӻ����ƼĴ���
#define ESTAI       0x40//�ӻ�ģʽʱ����START�ź��ж�����λ
#define ERXI        0x20//�ӻ�ģʽʱ���յ�1�ֽ����ݺ��ж�����λ
#define ETXI        0x10//�ӻ�ģʽʱ������1�ֽ����ݺ��ж�����λ
#define ESTOI       0x08//�ӻ�ģʽʱ����STOP�ź��ж�����λ
#define SLRST       0x01//��λ�ӻ�ģʽ
#define I2CSLST     (*(unsigned char volatile xdata *)0xfe84)//IIC�ӻ�״̬�Ĵ���
#define SLBUSY      0x80//�ӻ�ģʽʱIIC������״̬λ
#define STAIF       0x40//�ӻ�ģʽʱ����START�ź��ж�����λ
#define RXIF        0x20//�ӻ�ģʽʱ���յ�1�ֽ����ݺ��ж�����λ
#define TXIF        0x10//�ӻ�ģʽʱ������1�ֽ����ݺ��ж�����λ
#define STOIF       0x08//�ӻ�ģʽʱ����STOP�ź��ж�����λ
#define TXING       0x04
#define SLACKI      0x02//�ӻ�ģʽʱ���յ���ACK
#define SLACKO      0x01//�ӻ�ģʽʱ����Ҫ���͵�ACK
#define I2CSLADR    (*(unsigned char volatile xdata *)0xfe85)//IIC�ӻ���ַ�Ĵ���
#define I2CTXD      (*(unsigned char volatile xdata *)0xfe86)//IIC�������ݼĴ���
#define I2CRXD      (*(unsigned char volatile xdata *)0xfe87)//IIC�������ݼĴ���
#define I2CMSAUX    (*(unsigned char volatile xdata *)0xfe88)//IIC�����������ƼĴ���
#endif
