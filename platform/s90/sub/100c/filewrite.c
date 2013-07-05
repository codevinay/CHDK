#include "lolevel.h"
#include "platform.h"

typedef struct {
    unsigned int address;
    unsigned int length;
} cam_ptp_data_chunk; //camera specific structure

#define MAX_CHUNKS_FOR_JPEG 4 //model specific
/*
 * fwt_data_struct: defined here as it's camera dependent
 * unneeded members are designated with unkn
 * file_offset, full_size, seek_flag only needs to be defined for DryOS>=r50 generation cameras
 * pdc and name are always needed
 */
typedef struct
{
    int unkn1, unkn2, unkn3, unkn4, unkn5;
    cam_ptp_data_chunk pdc[MAX_CHUNKS_FOR_JPEG];
    int unkn6;
    char name[32];
} fwt_data_struct;

#include "../../../generic/filewrite.c"

// ************ filewritetask *************

void __attribute__((naked,noinline)) filewritetask () { //sub_FFA78FA0_my
asm volatile (
      "    STMFD   SP!, {R1-R5,LR} \n" 
      "    LDR     R4, =0xB414 \n" 
"loc_FFA78FA8:\n"
      "    LDR     R0, [R4, #0x10] \n" 
      "    MOV     R2, #0 \n" 
      "    ADD     R1, SP, #8 \n" 
      "    BL      sub_FF8382FC \n" 
      "    CMP     R0, #0 \n" 
      "    BNE     loc_FFA78FD8 \n" 
      "    LDR     R0, [SP, #8] \n" 
      "    LDR     R1, [R0] \n" 
      "    CMP     R1, #1 \n" 
      "    BNE     loc_FFA78FE0 \n" 
      "    LDR     R0, [R4, #8] \n" 
      "    BL      sub_FF8387E8 \n" 
"loc_FFA78FD8:\n"
      "    BL      sub_FF81E844 \n" 
      "    LDMFD   SP!, {R1-R5,PC} \n" 
"loc_FFA78FE0:\n"
      "    SUB     R1, R1, #2 \n" 
      "    CMP     R1, #6 \n" 
      "    ADDLS   PC, PC, R1, LSL #2 \n" 
      "    B       loc_FFA78FA8 \n" 
      "    B       loc_FFA7900C \n" 
      "    B       loc_FFA79070 \n" 
      "    B       loc_FFA79078 \n" 
      "    B       loc_FFA79078 \n" 
      "    B       loc_FFA79078 \n" 
      "    B       loc_FFA79078 \n" 
      "    B       loc_FFA79080 \n" 
"loc_FFA7900C:\n"
      "    MOV     R0, #0 \n" 
      "    STR     R0, [SP] \n" 
"loc_FFA79014:\n"
      "    LDR     R0, [R4, #0x10] \n" 
      "    MOV     R1, SP \n" 
      "    BL      sub_FF838540 \n" 
      "    LDR     R0, [SP] \n" 
      "    CMP     R0, #0 \n" 
      "    BEQ     loc_FFA79040 \n" 
      "    LDR     R0, [R4, #0x10] \n" 
      "    MOV     R2, #0 \n" 
      "    ADD     R1, SP, #4 \n" 
      "    BL      sub_FF8382FC \n" 
      "    B       loc_FFA79014 \n" 
"loc_FFA79040:\n"
      "    LDR     R0, [R4] \n" 
      "    CMN     R0, #1 \n" 
      "    BEQ     loc_FFA79064 \n" 
      "    BL      fwt_close\n"          // mod! sub_FF835414
      "    MVN     R0, #0 \n" 
      "    STR     R0, [R4] \n" 
      "    LDR     R0, =0xD1D1C \n" 
      "    BL      sub_FF86E540 \n" 
      "    BL      sub_FF86C924 \n" 
"loc_FFA79064:\n"
      "    LDR     R0, [R4, #0xC] \n" 
      "    BL      sub_FF8387E8 \n" 
      "    B       loc_FFA78FA8 \n" 
"loc_FFA79070:\n"
      "    BL      sub_FFA7928C_my \n" // -> open
      "    B       loc_FFA78FA8 \n" 
"loc_FFA79078:\n"
      "    BL      sub_FFA793C0_my \n" // -> write
      "    B       loc_FFA78FA8 \n" 
"loc_FFA79080:\n"
      "    BL      sub_FFA78E38_my \n" // -> close
      "    B       loc_FFA78FA8 \n" 
    );
}



void __attribute__((naked,noinline)) sub_FFA7928C_my(  ) { // open
asm volatile (
      "    STMFD   SP!, {R4-R8,LR} \n" 
      "    MOV     R4, R0 \n" 
      "    ADD     R0, R0, #0x38 \n" 
      "    SUB     SP, SP, #0x38 \n" 
      "    BL      sub_FF86E540 \n" 
      "    MOV     R1, #0 \n" 
      "    BL      sub_FF86C8D4 \n" 
      "    LDR     R0, [R4, #0xC] \n" 
      "    BL      sub_FF86B490 \n" 
      "    LDR     R7, [R4, #8] \n" 
      "    LDR     R8, =0x1B6 \n" 
      "    ADD     R6, R4, #0x38 \n" 
      "    LDR     R5, [R4, #0xC] \n" 
//place hook here
      "STMFD SP!, {R4-R12,LR}\n"
      "MOV R0, R4\n"
      "BL filewrite_main_hook\n"
      "LDMFD SP!, {R4-R12,LR}\n"
//hook end
      "    MOV     R0, R6 \n" 
      "    MOV     R1, R7 \n" 
      "    MOV     R2, R8 \n" 
      "    BL      fwt_open\n"          // mod! sub_FF8353BC
      "LDR PC, =0xffa792d0\n"           // continue in ROM
/*      "    CMN     R0, #1 \n" 
      "    BNE     loc_FFA79330 \n" 
      "    MOV     R0, R6 \n" 
      "    BL      sub_FF835780 \n" 
      "    MOV     R2, #0xF \n" 
      "    MOV     R1, R6 \n" 
      "    MOV     R0, SP \n" 
      "    BL      sub_FFB34BC8 \n" 
      "    LDR     R0, =0x41FF \n" 
      "    MOV     R1, #0 \n" 
      "    STRB    R1, [SP, #0xF] \n" 
      "    STR     R0, [SP, #0x20] \n" 
      "    MOV     R0, #0x10 \n" 
      "    ADD     R2, SP, #0x24 \n" 
      "    STMIA   R2, {R0,R1,R5} \n" 
      "    ADD     R1, SP, #0x20 \n" 
      "    MOV     R0, SP \n" 
      "    STR     R5, [SP, #0x30] \n" 
      "    STR     R5, [SP, #0x34] \n" 
      "    BL      sub_FF86C244 \n" 
      "    MOV     R2, R8 \n" 
      "    MOV     R1, R7 \n" 
      "    MOV     R0, R6 \n" 
      "    BL      sub_FF8353BC \n" 
"loc_FFA79330:\n"
      "    LDR     R5, =0xB414 \n" 
      "    CMN     R0, #1 \n" 
      "    STR     R0, [R5] \n" 
      "    BNE     loc_FFA79378 \n" 
      "    LDR     R0, [R5, #0x18] \n" 
      "    CMP     R0, #0 \n" 
      "    BLXNE   R0 \n" 
      "    ADD     R0, R4, #0x38 \n" 
      "    BL      sub_FF86E540 \n" 
      "    BL      sub_FF86C924 \n" 
      "    LDR     R1, [R5, #0x14] \n" 
      "    CMP     R1, #0 \n" 
      "    ADDNE   SP, SP, #0x38 \n" 
      "    LDMNEFD SP!, {R4-R8,LR} \n" 
      "    LDRNE   R0, =0x9200001 \n" 
      "    BXNE    R1 \n" 
"loc_FFA79370:\n"
      "    ADD     SP, SP, #0x38 \n" 
      "    LDMFD   SP!, {R4-R8,PC} \n" 
"loc_FFA79378:\n"
      "    LDR     R0, =0xD1D1C \n" 
      "    MOV     R2, #0x20 \n" 
      "    ADD     R1, R4, #0x38 \n" 
      "    BL      sub_FFB34D30 \n" 
      "    MOV     R1, R4 \n" 
      "    MOV     R0, #4 \n" 
      "    BL      sub_FFA78D78 \n" 
      "    B       loc_FFA79370 \n" */
    );
}



void __attribute__((naked,noinline)) sub_FFA793C0_my(  ) { // write
asm volatile (
      "    STMFD   SP!, {R4-R10,LR} \n" 
      "    MOV     R4, R0 \n" 
      "    LDR     R0, [R0] \n" 
      "    CMP     R0, #4 \n" 
      "    LDREQ   R6, [R4, #0x18] \n" 
      "    LDREQ   R7, [R4, #0x14] \n" 
      "    BEQ     loc_FFA7940C \n" 
      "    CMP     R0, #5 \n" 
      "    LDREQ   R6, [R4, #0x20] \n" 
      "    LDREQ   R7, [R4, #0x1C] \n" 
      "    BEQ     loc_FFA7940C \n" 
      "    CMP     R0, #6 \n" 
      "    LDREQ   R6, [R4, #0x28] \n" 
      "    LDREQ   R7, [R4, #0x24] \n" 
      "    BEQ     loc_FFA7940C \n" 
      "    CMP     R0, #7 \n" 
      "    BNE     loc_FFA79420 \n" 
      "    LDR     R6, [R4, #0x30] \n" 
      "    LDR     R7, [R4, #0x2C] \n" 
"loc_FFA7940C:\n"
      "    CMP     R6, #0 \n" 
      "    BNE     loc_FFA79430 \n" 
"loc_FFA79414:\n"
      "    MOV     R1, R4 \n" 
      "    MOV     R0, #8 \n" 
      "    B       loc_FFA794C4 \n" 
"loc_FFA79420:\n"
      "    LDR     R1, =0x297 \n" 
      "    LDR     R0, =0xFFA79094 \n" 
      "    BL      sub_FF81E88C \n" 
      "    B       loc_FFA79414 \n" 
"loc_FFA79430:\n"
      "    LDR     R9, =0xB414 \n" 
      "    MOV     R5, R6 \n" 
"loc_FFA79438:\n"
      "    LDR     R0, [R4, #4] \n" 
      "    CMP     R5, #0x1000000 \n" 
      "    MOVLS   R8, R5 \n" 
      "    MOVHI   R8, #0x1000000 \n" 
      "    BIC     R1, R0, #0xFF000000 \n" 
      "    CMP     R1, #0 \n" 
      "    BICNE   R0, R0, #0xFF000000 \n" 
      "    RSBNE   R0, R0, #0x1000000 \n" 
      "    CMPNE   R8, R0 \n" 
      "    MOVHI   R8, R0 \n" 
      "    LDR     R0, [R9] \n" 
      "    MOV     R2, R8 \n" 
      "    MOV     R1, R7 \n" 
      "    BL      fwt_write\n"         // mod! sub_FF8354A4
      "    LDR     R1, [R4, #4] \n" 
      "    CMP     R8, R0 \n" 
      "    ADD     R1, R1, R0 \n" 
      "    STR     R1, [R4, #4] \n" 
      "    BEQ     loc_FFA79498 \n" 
      "    CMN     R0, #1 \n" 
      "    LDRNE   R0, =0x9200015 \n" 
      "    LDREQ   R0, =0x9200005 \n" 
      "    STR     R0, [R4, #0x10] \n" 
      "    B       loc_FFA79414 \n" 
"loc_FFA79498:\n"
      "    SUB     R5, R5, R0 \n" 
      "    CMP     R5, R6 \n" 
      "    ADD     R7, R7, R0 \n" 
      "    LDRCS   R0, =0xFFA79094 \n" 
      "    LDRCS   R1, =0x2C2 \n" 
      "    BLCS    sub_FF81E88C \n" 
      "    CMP     R5, #0 \n" 
      "    BNE     loc_FFA79438 \n" 
      "    LDR     R0, [R4] \n" 
      "    MOV     R1, R4 \n" 
      "    ADD     R0, R0, #1 \n" 
"loc_FFA794C4:\n"
      "    LDMFD   SP!, {R4-R10,LR} \n" 
      "    B       sub_FFA78D78 \n" 
    );
}



void __attribute__((naked,noinline)) sub_FFA78E38_my(  ) { // close
asm volatile (
      "    STMFD   SP!, {R4-R6,LR} \n" 
      "    LDR     R5, =0xB414 \n" 
      "    MOV     R4, R0 \n" 
      "    LDR     R0, [R5] \n" 
      "    SUB     SP, SP, #0x38 \n" 
      "    CMN     R0, #1 \n" 
//      "    BEQ     loc_FFA78E80 \n"   // -
      "LDREQ PC, =0xFFA78E80\n"         // +
      "    LDR     R1, [R4, #8] \n" 
      "    LDR     R6, =0x9200003 \n" 
      "    TST     R1, #0x8000 \n" 
      "    BEQ     loc_FFA78E6C \n" 
      "    BL      sub_FF86B984 \n" 
      "    B       loc_FFA78E70 \n" 
"loc_FFA78E6C:\n"
      "    BL      fwt_close\n"         // mod! sub_FF835414
"loc_FFA78E70:\n"
      "LDR PC, =0xffa78e70\n"           // continue in ROM
      /*"    CMP     R0, #0 \n" 
      "    MVN     R0, #0 \n" 
      "    STRNE   R6, [R4, #0x10] \n" 
      "    STR     R0, [R5] \n" 
"loc_FFA78E80:\n"
      "    LDR     R0, [R4, #0x10] \n" 
      "    TST     R0, #1 \n" 
      "    BNE     loc_FFA78F70 \n" 
      "    LDR     R0, [R4, #8] \n" 
      "    TST     R0, #8 \n" 
      "    BEQ     loc_FFA78EC8 \n" 
      "    ADD     R1, SP, #0x20 \n" 
      "    ADD     R0, R4, #0x38 \n" 
      "    BL      sub_FF86C090 \n" 
      "    CMP     R0, #0 \n" 
      "    MOVEQ   R1, #0x300 \n" 
      "    LDREQ   R0, =0xFFA79094 \n" 
      "    BLEQ    sub_FF81E88C \n" 
      "    LDR     R0, [SP, #0x28] \n" 
      "    LDR     R1, [R4, #4] \n" 
      "    ADD     R0, R0, R1 \n" 
      "    STR     R0, [SP, #0x28] \n" 
      "    B       loc_FFA78EF8 \n" 
"loc_FFA78EC8:\n"
      "    LDR     R0, =0x81FF \n" 
      "    STR     R0, [SP, #0x20] \n" 
      "    MOV     R0, #0x20 \n" 
      "    STR     R0, [SP, #0x24] \n" 
      "    LDR     R0, [R4, #4] \n" 
      "    STR     R0, [SP, #0x28] \n" 
      "    LDR     R0, [R4, #0xC] \n" 
      "    STR     R0, [SP, #0x2C] \n" 
      "    LDR     R0, [R4, #0xC] \n" 
      "    STR     R0, [SP, #0x30] \n" 
      "    LDR     R0, [R4, #0xC] \n" 
      "    STR     R0, [SP, #0x34] \n" 
"loc_FFA78EF8:\n"
      "    ADD     R1, SP, #0x20 \n" 
      "    ADD     R0, R4, #0x38 \n" 
      "    BL      sub_FF86C244 \n" 
      "    LDR     R0, [R4, #0x34] \n" 
      "    CMP     R0, #0 \n" 
      "    BEQ     loc_FFA78F70 \n" 
      "    MOV     R2, #0x20 \n" 
      "    ADD     R1, R4, #0x38 \n" 
      "    MOV     R0, SP \n" 
      "    BL      sub_FFB34D30 \n" 
      "    MOV     R0, SP \n" 
      "    BL      sub_FF81400C \n" 
      "    MOV     R2, #0x54 \n" 
      "    ADD     R0, SP, R0 \n" 
      "    MOV     R1, #0x4D \n" 
      "    STRB    R2, [R0, #-3] \n" 
      "    STRB    R1, [R0, #-2] \n" 
      "    MOV     R1, #0x50 \n" 
      "    STRB    R1, [R0, #-1] \n" 
      "    MOV     R1, SP \n" 
      "    ADD     R0, R4, #0x38 \n" 
      "    BL      sub_FF86B9A4 \n" 
      "    CMP     R0, #0 \n" 
      "    LDREQ   R1, =0x153 \n" 
      "    LDREQ   R0, =0xFFA79094 \n" 
      "    BLEQ    sub_FF81E88C \n" 
      "    MOV     R0, SP \n" 
      "    BL      sub_FF86C6A0 \n" 
      "    ADD     R0, R4, #0x38 \n" 
      "    BL      sub_FF86C6A0 \n" 
"loc_FFA78F70:\n"
      "    LDR     R0, [R5, #0x18] \n" 
      "    CMP     R0, #0 \n" 
      "    BLXNE   R0 \n" 
      "    ADD     R0, R4, #0x38 \n" 
      "    BL      sub_FF86E540 \n" 
      "    BL      sub_FF86C924 \n" 
      "    LDR     R1, [R5, #0x14] \n" 
      "    CMP     R1, #0 \n" 
      "    LDRNE   R0, [R4, #0x10] \n" 
      "    BLXNE   R1 \n" 
      "    ADD     SP, SP, #0x38 \n" 
      "    LDMFD   SP!, {R4-R6,PC} \n" */
    );
}
