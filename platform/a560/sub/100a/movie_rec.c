#include "conf.h"

int *video_quality = &conf.video_quality;
int *video_mode    = &conf.video_mode;

long def_table1[9]={0x2000,0x38D,0x788,0x5800,0x9C5,0x14B8,0x10000,0x1C6A,0x3C45};
long def_table2[9]={0x1CCD,-0x2E1,-0x579,0x4F33,-0x7EB,-0xF0C,0xE666,-0x170A,-0x2BC6};

long table1[9], table2[9];

void change_video_tables(int a, int b){
 int i;
 for (i=0;i<9;i++) {table1[i]=(def_table1[i]*a)/b; table2[i]=(def_table2[i]*a)/b;}
}

long CompressionRateTable[]={0x60, 0x5D, 0x5A, 0x57, 0x54, 0x51, 0x4D, 0x48, 0x42, 0x3B, 0x32, 0x29, 0x22, 0x1D, 0x17, 0x14, 0x10, 0xE, 0xB, 9, 7, 6, 5, 4, 3, 2, 1};

void __attribute__((naked,noinline)) movie_record_task(){
 asm volatile(
                 "STMFD   SP!, {R4,R5,LR}\n"
                 "SUB     SP, SP, #4\n"
                 "MOV     R5, SP\n"
                 "MOV     R4, #0\n"
 "loc_FFF11A20:\n"
                 "LDR     R3, =0xA2648\n"
                 "MOV     R2, #0\n"
                 "LDR     R0, [R3]\n"
                 "MOV     R1, R5\n"
                 "BL      sub_FFEA8524\n"
                 "LDR     R3, =0xA2768\n"
                 "LDR     R2, [R3]\n"
                 "CMP     R2, #0\n"
                 "BNE     loc_FFF11ACC\n"
                 "LDR     R1, [SP]\n"
                 "LDR     R3, [R1]\n"
                 "SUB     R3, R3, #2\n"
                 "MOV     R0, R1\n"
                 "CMP     R3, #9\n"
                 "LDRLS   PC, [PC,R3,LSL#2]\n"
                 "B       loc_FFF11AD0\n"
                 ".long loc_FFF11A90\n"
                 ".long loc_FFF11AA8\n"
                 ".long loc_FFF11AB0\n"
                 ".long loc_FFF11AB8\n"
                 ".long loc_FFF11A98\n"
                 ".long loc_FFF11AC0\n"
                 ".long loc_FFF11AA0\n"
                 ".long loc_FFF11AD0\n"
                 ".long loc_FFF11AC8\n"
                 ".long loc_FFF11A88\n"
 "loc_FFF11A88:\n"
                 "BL      sub_FFF11B3C\n"
                 "B       loc_FFF11ACC\n"
 "loc_FFF11A90:\n"
                 "BL      unlock_optical_zoom\n"
                 "BL      sub_FFF11D44\n"
                 "B       loc_FFF11ACC\n"
 "loc_FFF11A98:\n"
                 "BL      sub_FFF120C0_my\n"  //--------------->
                 "B       loc_FFF11ACC\n"
 "loc_FFF11AA0:\n"
                 "BL      sub_FFF128E8\n"
                 "B       loc_FFF11ACC\n"
 "loc_FFF11AA8:\n"
                 "BL      sub_FFF1239C\n"
                 "B       loc_FFF11ACC\n"
 "loc_FFF11AB0:\n"
                 "BL      sub_FFF12A84\n"
                 "B       loc_FFF11ACC\n"
 "loc_FFF11AB8:\n"
                 "BL      sub_FFF12C64\n"
                 "B       loc_FFF11ACC\n"
 "loc_FFF11AC0:\n"
                 "BL      sub_FFF12970\n"
                 "B       loc_FFF11ACC\n"
 "loc_FFF11AC8:\n"
                 "BL      sub_FFF123EC\n"
 "loc_FFF11ACC:\n"
                 "LDR     R1, [SP]\n"
 "loc_FFF11AD0:\n"
                 "LDR     R3, =0xA264C\n"
                 "STR     R4, [R1]\n"
                 "LDR     R0, [R3]\n"
                 "MOV     R2, R4\n"
                 "BL      sub_FFEA893C\n"
                 "B       loc_FFF11A20\n"

 );
}

void __attribute__((naked,noinline)) sub_FFF120C0_my(){
 asm volatile(
                 "STMFD   SP!, {R4-R11,LR}\n"
                 "LDR     R5, =0xA2780\n"
                 "SUB     SP, SP, #0x3C\n"
                 "LDR     R3, [R5]\n"
                 "MOV     R2, #0\n"
                 "CMP     R3, #3\n"
                 "STR     R2, [SP,#0x2C]\n"
                 "MOV     R4, R0\n"
                 "STR     R2, [SP,#0x34]\n"
                 "MOVEQ   R3, #4\n"
                 "STREQ   R3, [R5]\n"
                 "LDR     R3, =0xA282C\n"
                 "MOV     LR, PC\n"
                 "LDR     PC, [R3]\n"
                 "LDR     R2, [R5]\n"
                 "CMP     R2, #4\n"
                 "BNE     loc_FFF122C4\n"
                 "ADD     R0, SP, #0x38\n"
                 "ADD     R1, SP, #0x34\n"
                 "ADD     R2, SP, #0x30\n"
                 "ADD     R3, SP, #0x2C\n"
                 "BL      sub_FFF137E0\n"
                 "CMP     R0, #0\n"
                 "BNE     loc_FFF12148\n"
                 "LDR     R3, =0xA2770\n"
                 "LDR     R2, [R3]\n"
                 "CMP     R2, #1\n"
                 "BNE     loc_FFF1215C\n"
                 "LDR     R2, =0xA27AC\n"
                 "LDR     R1, =0xA2784\n"
                 "LDR     R12, [R2]\n"
                 "LDR     R3, [R1]\n"
                 "CMP     R12, R3\n"
                 "BCC     loc_FFF1215C\n"
 "loc_FFF12148:\n"
                 "BL      sub_FFF12314\n"
                 "BL      sub_FFF128A8\n"
                 "MOV     R3, #5\n"
                 "STR     R3, [R5]\n"
                 "B       loc_FFF122C4\n"
 "loc_FFF1215C:\n"
                 "LDR     R9, [SP,#0x34]\n"
                 "CMP     R9, #0\n"
                 "BEQ     loc_FFF12244\n"
                 "LDR     R7, =0xA27C8\n"
                 "LDR     R12, =0xA27B4\n"
                 "LDMIB   R4, {R0-R2}\n"
                 "LDR     R10, [R4,#0x18]\n"
                 "LDR     R6, [R7]\n"
                 "LDR     R7, [R4,#0x14]\n"
                 "LDR     R4, =0xA2774\n"
                 "LDR     R8, [R12]\n"
                 "ADD     R5, SP, #0x2C\n"
                 "LDMIA   R5, {R5,LR}\n"
                 "MOV     R11, #1\n"
                 "LDR     R3, [SP,#0x38]\n"
                 "ADD     R12, SP, #0x28\n"
                 "STR     R11, [R4]\n"
                 "ADD     R4, SP, #0x24\n"
                 "STMEA   SP, {R9,LR}\n"
                 "STR     R5, [SP,#8]\n"
                 "STR     R12, [SP,#0xC]\n"
                 "STR     R8, [SP,#0x10]\n"
                 "STR     R6, [SP,#0x14]\n"
                 "STR     R7, [SP,#0x18]\n"
                 "STR     R10, [SP,#0x1C]\n"
                 "STR     R4, [SP,#0x20]\n"
                 "BL      sub_FFF16870\n"
                 "LDR     R3, =0xA2640\n"
                 "MOV     R1, #0x3E8\n"
                 "LDR     R0, [R3]\n"
                 "BL      sub_FFEA90EC\n"
                 "CMP     R0, #9\n"
                 "BNE     loc_FFF121F0\n"
                 "BL      sub_FFF14070\n"
                 "LDR     R3, =0xA2780\n"
                 "LDR     R0, =0xFFF120A8\n"
                 "B       loc_FFF12208\n"
 "loc_FFF121F0:\n"
                 "LDR     R4, [SP,#0x24]\n"
                 "CMP     R4, #0\n"
                 "BEQ     loc_FFF12214\n"
                 "BL      sub_FFF14070\n"
                 "LDR     R3, =0xA2780\n"
                 "LDR     R0, =0xFFF120B4\n"
 "loc_FFF12208:\n"
                 "STR     R11, [R3]\n"
                 "BL      sub_FFECC238\n"
                 "B       loc_FFF122C4\n"
 "loc_FFF12214:\n"
                 "BL      sub_FFF169EC\n"
                 "LDR     R0, [SP,#0x38]\n"
                 "LDR     R1, [SP,#0x28]\n"
                 "BL      sub_FFF13CC8\n"
                 "LDR     R12, =0xA27A8\n"
                 "LDR     R3, [R12]\n"
                 "ADD     R3, R3, #1\n"
                 "LDR     R0, [SP,#0x28]\n"
                 "LDR     R1, =0xA27C8\n"
                 "MOV     R2, R4\n"
                 "STR     R3, [R12]\n"
                 "BL      sub_FFE85DB8_my\n"   //----------------->
 "loc_FFF12244:\n"
                 "LDR     R4, =0xA27AC\n"
                 "LDR     R2, =0xA27D4\n"
                 "LDR     R3, [R4]\n"
                 "LDR     R1, [R2]\n"
                 "LDR     R12, =0xA27D0\n"
                 "ADD     R3, R3, #1\n"
                 "MUL     R0, R1, R3\n"
                 "LDR     R1, [R12]\n"
                 "STR     R3, [R4]\n"
                 "BL      sub_FFCC5B00\n"
                 "LDR     R6, =0xA27CC\n"
                 "MOV     R4, R0\n"
                 "BL      sub_FFF140AC\n"
                 "LDR     R3, [R6]\n"
                 "CMP     R3, R4\n"
                 "BNE     loc_FFF12298\n"
                 "LDR     R5, =0xA2778\n"
                 "LDR     R3, [R5]\n"
                 "CMP     R3, #1\n"
                 "BNE     loc_FFF122B8\n"
                 "B       loc_FFF1229C\n"
 "loc_FFF12298:\n"
                 "LDR     R5, =0xA2778\n"
 "loc_FFF1229C:\n"
                 "LDR     R2, =0xA2810\n"
                 "MOV     R0, R4\n"
                 "MOV     LR, PC\n"
                 "LDR     PC, [R2]\n"
                 "MOV     R3, #0\n"
                 "STR     R3, [R5]\n"
                 "STR     R4, [R6]\n"
 "loc_FFF122B8:\n"
                 "LDR     R7, =0xA2774\n"
                 "MOV     R3, #0\n"
                 "STR     R3, [R7]\n"
 "loc_FFF122C4:\n"
                 "ADD     SP, SP, #0x3C\n"
                 "LDMFD   SP!, {R4-R11,PC}\n"
 );
}

void __attribute__((naked,noinline)) sub_FFE85DB8_my(){
 asm volatile(
                 "STMFD   SP!, {R4-R8,LR}\n"
                 "LDR     R12, =0x7E314\n"
                 "LDR     R4, [R12]\n"
                 "LDR     R3, =0x7E31C\n"
                 "CMP     R4, #0\n"
                 "MOV     R8, R1\n"
                 "MOV     R7, R0\n"
                 "LDR     R1, [R3]\n"
                 "BEQ     loc_FFE85DF0\n"
                 "LDR     R2, =0x7E320\n"
                 "LDR     R3, [R2]\n"
                 "CMP     R3, #1\n"
                 "BNE     loc_FFE85E04\n"
                 "B       loc_FFE85DF4\n"
 "loc_FFE85DF0:\n"
                 "LDR     R2, =0x7E320\n"
 "loc_FFE85DF4:\n"
                 "MOV     R3, #0\n"
                 "STR     R3, [R2]\n"
                 "STR     R7, [R12]\n"
                 "B       loc_FFE85EBC\n"
 "loc_FFE85E04:\n"
                 "LDR     R2, =0x7E318\n"
                 "LDR     R3, [R2]\n"
                 "LDR     R6, =table1\n"          // + 0xFFE85CBC
                 "ADD     R3, R3, R3,LSL#1\n"
                 "MOV     LR, R3,LSL#2\n"
                 "LDR     R2, [R6,LR]\n"
                 "LDR     R5, =table2\n"          // + 0xFFE85CE0
                 "RSB     R12, R2, R4\n"
                 "LDR     R3, [R5,LR]\n"
                 "CMP     R12, #0\n"
                 "RSB     R0, R3, R4\n"
                 "BLE     loc_FFE85E68\n"
                 "ADD     R3, R6, #4\n"
                 "LDR     R2, [R3,LR]\n"
                 "CMP     R2, R12\n"
                 "ADDGE   R1, R1, #1\n"
                 "BGE     loc_FFE85E5C\n"
                 "ADD     R3, R6, #8\n"
                 "LDR     R2, [R3,LR]\n"
                 "CMP     R2, R12\n"
                 "ADDGE   R1, R1, #2\n"
                 "ADDLT   R1, R1, #3\n"
 "loc_FFE85E5C:\n"
         //      "CMP     R1, #0x16\n"     // -
         //      "MOVGE   R1, #0x16\n"     // -
                 "CMP     R1, #0x1A\n"     // + 
                 "MOVGE   R1, #0x1A\n"     // + 

                 "B       loc_FFE85EA0\n"
 "loc_FFE85E68:\n"
                 "CMP     R0, #0\n"
                 "BGE     loc_FFE85EA0\n"
                 "ADD     R3, R5, #4\n"
                 "LDR     R2, [R3,LR]\n"
                 "CMP     R2, R0\n"
                 "SUBLE   R1, R1, #1\n"
                 "BLE     loc_FFE85E98\n"
                 "ADD     R3, R5, #8\n"
                 "LDR     R2, [R3,LR]\n"
                 "CMP     R2, R0\n"
                 "SUBLE   R1, R1, #2\n"
                 "SUBGT   R1, R1, #3\n"
 "loc_FFE85E98:\n"
                 "CMP     R1, #0\n"
                 "MOVLT   R1, #0\n"
 "loc_FFE85EA0:\n"
                 "LDR     R0, =0x7E31C\n"
                 "LDR     R3, [R0]\n"
                 "CMP     R1, R3\n"
                 "LDRNE   R2, =0x7E320\n"
                 "MOVNE   R3, #1\n"
                 "STRNE   R1, [R0]\n"
                 "STRNE   R3, [R2]\n"
 "loc_FFE85EBC:\n"
                 "LDR     R3, =0x7E31C\n"
                 "LDR     R2, =CompressionRateTable\n"
                 "LDR     R1, [R3]\n"
                 "LDR     R0, =0x7E314\n"
                 "LDR     R3, [R2,R1,LSL#2]\n"

                 "LDR     R1, =video_mode\n"      // +
                 "LDR     R1, [R1]\n"             // +
                 "LDR     R1, [R1]\n"             // +
                 "CMP     R1, #1\n"               // +
                 "LDREQ   R1, =video_quality\n"   // +     
                 "LDREQ   R1, [R1]\n"             // +     
                 "LDREQ   R3, [R1]\n"             // +     
       
                 "STR     R7, [R0]\n"
                 "STR     R3, [R8]\n"
                 "LDMFD   SP!, {R4-R8,PC}\n"
 );
}
