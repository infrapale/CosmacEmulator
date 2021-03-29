#include <stdio.h>
#include <string.h>
#include "assembler.h"


const instr_category_et codes[] = 
{ 
//  0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F     
    IDL, LDN, LDN, LDN, LDN, LDN, LDN, LDN, LDN, LDN, LDN, LDN, LDN, LDN, LDN, LDN,  //0X00
    INC, INC, INC, INC, INC, INC, INC, INC, INC, INC, INC, INC, INC, INC, INC, INC, 
    DECn,DECn,DECn,DECn,DECn,DECn,DECn,DECn,DECn,DECn,DECn,DECn,DECn,DECn,DECn,DECn,
    BR,  BQ,  BZ,  BDF, B1_, B2_, B3_, B4_, SKP, BNQ, BNZ, BNF, BN1, BN2, BN3, BN4,
    LDA, LDA, LDA, LDA, LDA, LDA, LDA, LDA, LDA, LDA, LDA, LDA, LDA, LDA, LDA, LDA,  //0X40
    STR, STR, STR, STR, STR, STR, STR, STR, STR, STR, STR, STR, STR, STR, STR, STR, 
    IRX, OUT, OUT, OUT, OUT, OUT, OUT, OUT, NA_, INP, INP, INP, INP, INP, INP, INP, 
    RET, DIS, LDXA,STXD,ADC, SDB, SHRC,SMB, SAV, MARK,REQ, SEQ, ADCI,SDBI,SHLC,SMBI,
    GLO, GLO, GLO, GLO, GLO, GLO, GLO, GLO, GLO, GLO, GLO, GLO, GLO, GLO, GLO, GLO,  //0X80
    GHI, GHI, GHI, GHI, GHI, GHI, GHI, GHI, GHI, GHI, GHI, GHI, GHI, GHI, GHI, GHI, 
    PLO, PLO, PLO, PLO, PLO, PLO, PLO, PLO, PLO, PLO, PLO, PLO, PLO, PLO, PLO, PLO, 
    PHI, PHI, PHI, PHI, PHI, PHI, PHI, PHI, PHI, PHI, PHI, PHI, PHI, PHI, PHI, PHI, 
    LBR, LBQ, LBZ, LBDF,NOP, LSNQ,LSNZ,LSNF,LSKP,LBNQ,LBNZ,LBNF,LSIE,LSQ, LSZ, LSDF,  //0XC0
    SEP, SEP, SEP, SEP, SEP, SEP, SEP, SEP, SEP, SEP, SEP, SEP, SEP, SEP, SEP, SEP, 
    SEX, SEX, SEX, SEX, SEX, SEX, SEX, SEX, SEX, SEX, SEX, SEX, SEX, SEX, SEX, SEX, 
    LDX, OR,  AND, XOR, ADD, SD_, SHR, SM,  LDI, ORI, ANI, XRI, ADI, SDI, SHL, SMI

};

instr_code_st instr_set[] =
{
  { IDL,"IDL", 0x00, 0, NULL},
  { LDN,"LDN", 0xF0, 0, NULL},
  { LDN,"INC", 0xF0, 0, NULL}
  
};



//instr_code_t cdp1802_instr[10];

void instr_idl(void)
{

}

void instr_ldn(void)
{

}



void emulate_initialize(void){
    instr_set[IDL].cbFunction = &instr_idl;
    instr_set[LDN].cbFunction = &instr_ldn;


}
