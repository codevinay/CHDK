/*
 * capt_seq.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"
#include "core.h"

#define USE_STUBS_NRFLAG 1          // see stubs_entry.S
#define NR_AUTO (0)                 // have to explictly reset value back to 0 to enable auto
#define PAUSE_FOR_FILE_COUNTER 300  // Enable delay in capt_seq_hook_raw_here to ensure file counter is updated

#include "../../../generic/capt_seq.c"

/*************************************************************/
//** capt_seq_task @ 0xFF884680 - 0xFF884980, length=193
void __attribute__((naked,noinline)) capt_seq_task() {
asm volatile (
"    STMFD   SP!, {R3-R9,LR} \n"
"    LDR     R4, =0x3A180 \n"
"    LDR     R7, =0x34C0 \n"
"    MOV     R6, #0 \n"

"loc_FF884690:\n"
"    LDR     R0, [R7, #4] \n"
"    MOV     R2, #0 \n"
"    MOV     R1, SP \n"
"    BL      sub_004372A4 /*_ReceiveMessageQueue*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF8846BC \n"
"    LDR     R1, =0x491 \n"
"    LDR     R0, =0xFF88407C \n"
"    BL      _DebugAssert \n"
"    BL      _ExitTask \n"
"    LDMFD   SP!, {R3-R9,PC} \n"

"loc_FF8846BC:\n"
"    LDR     R0, [SP] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x24 \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FF884948 \n"
"    B       loc_FF884760 \n"
"    B       loc_FF884778 \n"
"    B       loc_FF8847DC \n"
"    B       loc_FF8847F0 \n"
"    B       loc_FF8847E8 \n"
"    B       loc_FF8847FC \n"
"    B       loc_FF884804 \n"
"    B       loc_FF88480C \n"
"    B       loc_FF884828 \n"
"    B       loc_FF884854 \n"
"    B       loc_FF884834 \n"
"    B       loc_FF884840 \n"
"    B       loc_FF884848 \n"
"    B       loc_FF88485C \n"
"    B       loc_FF884864 \n"
"    B       loc_FF88486C \n"
"    B       loc_FF884874 \n"
"    B       loc_FF88487C \n"
"    B       loc_FF884884 \n"
"    B       loc_FF88488C \n"
"    B       loc_FF884894 \n"
"    B       loc_FF88489C \n"
"    B       loc_FF8848A4 \n"
"    B       loc_FF8848B0 \n"
"    B       loc_FF8848B8 \n"
"    B       loc_FF8848C4 \n"
"    B       loc_FF8848CC \n"
"    B       loc_FF8848D4 \n"
"    B       loc_FF8848DC \n"
"    B       loc_FF8848E4 \n"
"    B       loc_FF8848EC \n"
"    B       loc_FF8848F4 \n"
"    B       loc_FF884900 \n"
"    B       loc_FF884908 \n"
"    B       loc_FF884914 \n"
"    B       loc_FF884954 \n"

"loc_FF884760:\n"
"    BL      shooting_expo_iso_override\n"      // added
"    BL      sub_FF884EB8 \n"
"    BL      shooting_expo_param_override\n"    // added
"    BL      sub_FF8821E8 \n"
"    MOV     R0, #0\n"                          // added
"    STR     R0, [R4,#0x28]\n"                  // added, fixes overrides behavior at short shutter press (from S95)
//"  LDR     R0, [R4, #0x28] \n"  // above patch makes these three lines redundant
//"  CMP     R0, #0 \n"
//"  BLNE    _sub_FF995974 \n"
"    B       loc_FF884954 \n"

"loc_FF884778:\n"
"    LDR     R5, [R0, #0x10] \n"
"    LDR     R0, [R4, #0x28] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF8847B4 \n"
"    BL      sub_FF885F88 \n"
"    MOV     R1, R5 \n"
"    BL      sub_FF885FE0 \n"
"    LDR     R0, =0x10F \n"
"    MOV     R2, #4 \n"
"    ADD     R1, R5, #0x24 \n"
"    BL      _SetPropertyCase \n"
"    MOV     R2, #4 \n"
"    ADD     R1, R5, #0x28 \n"
"    MOV     R0, #0x2C \n"
"    BL      _SetPropertyCase \n"

"loc_FF8847B4:\n"
"    MOV     R0, R5 \n"
"    BL      sub_FF9958B8_my \n"  // --> Patched. Old value = 0xFF9958B8.
"    BL      capt_seq_hook_raw_here \n"         // added
"    MOV     R8, R0 \n"
"    MOV     R2, R5 \n"
"    MOV     R1, #1 \n"
"    BL      sub_FF8826B4 \n"
"    TST     R8, #1 \n"
"    MOVEQ   R0, R5 \n"
"    BLEQ    sub_FF995218 \n"
"    B       loc_FF884954 \n"

"loc_FF8847DC:\n"
"    MOV     R0, #1 \n"
"    BL      sub_FF8851C0 \n"
"    B       loc_FF884954 \n"

"loc_FF8847E8:\n"
"    BL      sub_FF884BA4 \n"
"    B       loc_FF8847F4 \n"

"loc_FF8847F0:\n"
"    BL      sub_FF884E98 \n"

"loc_FF8847F4:\n"
"    STR     R6, [R4, #0x28] \n"
"    B       loc_FF884954 \n"

"loc_FF8847FC:\n"
"    BL      sub_FF884EA0 \n"
"    B       loc_FF884954 \n"

"loc_FF884804:\n"
"    BL      sub_FF88509C \n"
"    B       loc_FF88482C \n"

"loc_FF88480C:\n"
"    LDR     R5, [R0, #0x10] \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF995A0C \n"
"    MOV     R2, R5 \n"
"    MOV     R1, #9 \n"
"    BL      sub_FF8826B4 \n"
"    B       loc_FF884954 \n"

"loc_FF884828:\n"
"    BL      sub_FF88512C \n"

"loc_FF88482C:\n"
"    BL      sub_FF8821E8 \n"
"    B       loc_FF884954 \n"

"loc_FF884834:\n"
"    LDR     R0, [R4, #0x58] \n"
"    BL      sub_FF8857BC \n"
"    B       loc_FF884954 \n"

"loc_FF884840:\n"
"    BL      sub_FF885C04 \n"
"    B       loc_FF884954 \n"

"loc_FF884848:\n"
"    MOV     R0, #0 \n"
"    BL      sub_FF885C68 \n"
"    B       loc_FF884954 \n"

"loc_FF884854:\n"
"    BL      sub_FF884E98 \n"
"    B       loc_FF884954 \n"

"loc_FF88485C:\n"
"    BL      sub_FF9944D8 \n"
"    B       loc_FF884954 \n"

"loc_FF884864:\n"
"    BL      sub_FF994704 \n"
"    B       loc_FF884954 \n"

"loc_FF88486C:\n"
"    BL      sub_FF9947BC \n"
"    B       loc_FF884954 \n"

"loc_FF884874:\n"
"    BL      sub_FF994870 \n"
"    B       loc_FF884954 \n"

"loc_FF88487C:\n"
"    BL      sub_FF994948 \n"
"    B       loc_FF884954 \n"

"loc_FF884884:\n"
"    MOV     R0, #0 \n"
"    B       loc_FF8848A8 \n"

"loc_FF88488C:\n"
"    BL      sub_FF994D6C \n"
"    B       loc_FF884954 \n"

"loc_FF884894:\n"
"    BL      sub_FF994E00 \n"
"    B       loc_FF884954 \n"

"loc_FF88489C:\n"
"    BL      sub_FF994EA8 \n"
"    B       loc_FF884954 \n"

"loc_FF8848A4:\n"
"    MOV     R0, #1 \n"

"loc_FF8848A8:\n"
"    BL      sub_FF994C08 \n"
"    B       loc_FF884954 \n"

"loc_FF8848B0:\n"
"    BL      sub_FF885360 \n"
"    B       loc_FF884954 \n"

"loc_FF8848B8:\n"
"    BL      sub_FF88538C \n"
"    BL      sub_FF99663C \n"
"    B       loc_FF884954 \n"

"loc_FF8848C4:\n"
"    BL      sub_FF994AD8 \n"
"    B       loc_FF884954 \n"

"loc_FF8848CC:\n"
"    BL      sub_FF994B70 \n"
"    B       loc_FF884954 \n"

"loc_FF8848D4:\n"
"    BL      sub_FF9966F0 \n"
"    B       loc_FF884954 \n"

"loc_FF8848DC:\n"
"    BL      sub_FF82C780 \n"
"    B       loc_FF884954 \n"

"loc_FF8848E4:\n"
"    BL      sub_FF88747C \n"
"    B       loc_FF884954 \n"

"loc_FF8848EC:\n"
"    BL      sub_FF887568 \n"
"    B       loc_FF884954 \n"

"loc_FF8848F4:\n"
"    LDR     R0, [R0, #0xC] \n"
"    BL      sub_FF994FB0 \n"
"    B       loc_FF884954 \n"

"loc_FF884900:\n"
"    BL      sub_FF995020 \n"
"    B       loc_FF884954 \n"

"loc_FF884908:\n"
"    BL      sub_FF8876F4 \n"
"    BL      sub_FF8875C0 \n"
"    B       loc_FF884954 \n"

"loc_FF884914:\n"
"    MOV     R0, #1 \n"
"    BL      sub_FF996150 \n"
"    MOV     R0, #1 \n"
"    BL      sub_FF996278 \n"
"    LDRH    R0, [R4, #0xA4] \n"
"    CMP     R0, #4 \n"
"    LDRNEH  R0, [R4] \n"
"    SUBNE   R1, R0, #0x8200 \n"
"    SUBNES  R1, R1, #0x2E \n"
"    BNE     loc_FF884954 \n"
"    BL      sub_FF887568 \n"
"    BL      sub_FF887B64 \n"
"    B       loc_FF884954 \n"

"loc_FF884948:\n"
"    LDR     R1, =0x5F2 \n"
"    LDR     R0, =0xFF88407C \n"
"    BL      _DebugAssert \n"

"loc_FF884954:\n"
"    LDR     R0, [SP] \n"
"    LDR     R1, [R0, #4] \n"
"    LDR     R0, [R7] \n"
"    BL      sub_0043ACF8 /*_SetEventFlag*/ \n"
"    LDR     R5, [SP] \n"
"    LDR     R0, [R5, #8] \n"
"    CMP     R0, #0 \n"
"    LDREQ   R1, =0x117 \n"
"    LDREQ   R0, =0xFF88407C \n"
"    BLEQ    _DebugAssert \n"
"    STR     R6, [R5, #8] \n"
"    B       loc_FF884690 \n"
);
}

/*************************************************************/
//** sub_FF9958B8_my @ 0xFF9958B8 - 0xFF995970, length=47
void __attribute__((naked,noinline)) sub_FF9958B8_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    LDR     R5, =0x3A180 \n"
"    MOV     R6, R0 \n"
"    LDR     R0, [R5, #0x28] \n"
"    MOV     R4, #0 \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF9958E8 \n"
"    MOV     R0, #0xC \n"
"    BL      sub_FF889590 \n"
"    TST     R0, #1 \n"
"    MOVNE   R0, #1 \n"
"    LDMNEFD SP!, {R4-R6,PC} \n"

"loc_FF9958E8:\n"
"    MOV     R0, R6 \n"
"    BL      sub_FF996764 \n"
"    BL      sub_FF884EA8 \n"
"    LDR     R0, [R5, #0x28] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF995958 \n"
"    MOV     R0, R6 \n"
"    BL      sub_FF995110 \n"
"    TST     R0, #1 \n"
"    LDMNEFD SP!, {R4-R6,PC} \n"
"    MOV     R0, R6 \n"
"    BL      sub_FF995560 \n"
"    BL      sub_FF995F30 \n"
"    LDRH    R0, [R5, #0xA2] \n"
"    CMP     R0, #3 \n"
"    LDRNE   R0, [R6, #8] \n"
"    CMPNE   R0, #1 \n"
"    MOVLS   R0, #4 \n"
"    BLLS    sub_FF908CBC \n"
"    BL      wait_until_remote_button_is_released\n" // added
"    BL      capt_seq_hook_set_nr\n"                 // added
"    MOV     R0, #2 \n"
"    BL      sub_FF88ACB8 \n"
"    LDR     R0, [R5, #0x94] \n"
"    TST     R0, #0x10 \n"
"    BNE     loc_FF995968 \n"
"    MOV     R0, R6 \n"
"    BL      sub_FFAE2044 \n"
"    MOV     R4, R0 \n"
"    B       loc_FF99596C \n"

"loc_FF995958:\n"
"    LDR     R0, =0x7988 \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF99596C \n"

"loc_FF995968:\n"
"    MOV     R4, #0x1D \n"

"loc_FF99596C:\n"
"    MOV     R0, R4 \n"
"    LDMFD   SP!, {R4-R6,PC} \n"
);
}

/*************************************************************/
//** exp_drv_task @ 0xFF8C276C - 0xFF8C2DFC, length=421
void __attribute__((naked,noinline)) exp_drv_task() {
asm volatile (
"    STMFD   SP!, {R4-R9,LR} \n"
"    SUB     SP, SP, #0x2C \n"
"    LDR     R6, =0x4884 \n"
"    LDR     R7, =0xBB8 \n"
"    LDR     R4, =0x575F8 \n"
"    MOV     R0, #0 \n"
"    ADD     R5, SP, #0x1C \n"
"    STR     R0, [SP, #0xC] \n"

"loc_FF8C278C:\n"
"    LDR     R0, [R6, #0x20] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #0x28 \n"
"    BL      sub_004372A4 /*_ReceiveMessageQueue*/ \n"
"    LDR     R0, [SP, #0xC] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF8C27D8 \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #0x14 \n"
"    CMPNE   R0, #0x15 \n"
"    CMPNE   R0, #0x16 \n"
"    CMPNE   R0, #0x17 \n"
"    BEQ     loc_FF8C2938 \n"
"    CMP     R0, #0x2A \n"
"    BEQ     loc_FF8C28C0 \n"
"    ADD     R1, SP, #0xC \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF8C271C \n"

"loc_FF8C27D8:\n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x30 \n"
"    BNE     loc_FF8C2804 \n"
"    BL      sub_FF8C3C9C \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #1 \n"
"    BL      sub_0043ACF8 /*_SetEventFlag*/ \n"
"    BL      _ExitTask \n"
"    ADD     SP, SP, #0x2C \n"
"    LDMFD   SP!, {R4-R9,PC} \n"

"loc_FF8C2804:\n"
"    CMP     R1, #0x2F \n"
"    BNE     loc_FF8C2820 \n"
"    LDR     R2, [R0, #0x8C]! \n"
"    LDR     R1, [R0, #4] \n"
"    MOV     R0, R1 \n"
"    BLX     R2 \n"
"    B       loc_FF8C2DF4 \n"

"loc_FF8C2820:\n"
"    CMP     R1, #0x28 \n"
"    BNE     loc_FF8C2870 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_0043AD2C /*_ClearEventFlag*/ \n"
"    LDR     R0, =0xFF8BDFD4 \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_FF9862D4 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R2, R7 \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_0043AC38 /*_WaitForAllEventFlag*/ \n"
"    TST     R0, #1 \n"
"    LDRNE   R1, =0x1643 \n"
"    BNE     loc_FF8C292C \n"

"loc_FF8C285C:\n"
"    LDR     R1, [SP, #0x28] \n"
"    LDR     R0, [R1, #0x90] \n"
"    LDR     R1, [R1, #0x8C] \n"
"    BLX     R1 \n"
"    B       loc_FF8C2DF4 \n"

"loc_FF8C2870:\n"
"    CMP     R1, #0x29 \n"
"    BNE     loc_FF8C28B8 \n"
"    ADD     R1, SP, #0xC \n"
"    BL      sub_FF8C271C \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_0043AD2C /*_ClearEventFlag*/ \n"
"    LDR     R0, =0xFF8BDFE4 \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_FF987088 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R2, R7 \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_0043AC38 /*_WaitForAllEventFlag*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF8C285C \n"
"    LDR     R1, =0x164D \n"
"    B       loc_FF8C292C \n"

"loc_FF8C28B8:\n"
"    CMP     R1, #0x2A \n"
"    BNE     loc_FF8C28D0 \n"

"loc_FF8C28C0:\n"
"    LDR     R0, [SP, #0x28] \n"
"    ADD     R1, SP, #0xC \n"
"    BL      sub_FF8C271C \n"
"    B       loc_FF8C285C \n"

"loc_FF8C28D0:\n"
"    CMP     R1, #0x2D \n"
"    BNE     loc_FF8C28E8 \n"
"    BL      sub_FF8AE6B8 \n"
"    BL      sub_FF8AF4A8 \n"
"    BL      sub_FF8AEFB8 \n"
"    B       loc_FF8C285C \n"

"loc_FF8C28E8:\n"
"    CMP     R1, #0x2E \n"
"    BNE     loc_FF8C2938 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #4 \n"
"    BL      sub_0043AD2C /*_ClearEventFlag*/ \n"
"    LDR     R1, =0xFF8BE004 \n"
"    LDR     R0, =0xFFFFF400 \n"
"    MOV     R2, #4 \n"
"    BL      sub_FF8AE108 \n"
"    BL      sub_FF8AE398 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R2, R7 \n"
"    MOV     R1, #4 \n"
"    BL      sub_0043AB54 /*_WaitForAnyEventFlag*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF8C285C \n"
"    LDR     R1, =0x1675 \n"

"loc_FF8C292C:\n"
"    LDR     R0, =0xFF8BE714 \n"
"    BL      _DebugAssert \n"
"    B       loc_FF8C285C \n"

"loc_FF8C2938:\n"
"    LDR     R0, [SP, #0x28] \n"
"    MOV     R8, #1 \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x12 \n"
"    CMPNE   R1, #0x13 \n"
"    BNE     loc_FF8C29A0 \n"
"    LDR     R1, [R0, #0x7C] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R1, R0, R1, LSL#2 \n"
"    SUB     R1, R1, #8 \n"
"    LDMIA   R1, {R2,R3,R9} \n"
"    STMIA   R5, {R2,R3,R9} \n"
"    BL      sub_FF8C0C20 \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R3, [R0, #0x8C] \n"
"    LDR     R2, [R0, #0x90] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"
"    LDR     R0, [SP, #0x28] \n"
"    BL      sub_FF8C40A8 \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R2, [R0, #0x98] \n"
"    LDR     R3, [R0, #0x94] \n"
"    B       loc_FF8C2CB8 \n"

"loc_FF8C29A0:\n"
"    CMP     R1, #0x14 \n"
"    CMPNE   R1, #0x15 \n"
"    CMPNE   R1, #0x16 \n"
"    CMPNE   R1, #0x17 \n"
"    BNE     loc_FF8C2A58 \n"
"    ADD     R3, SP, #0xC \n"
"    MOV     R2, SP \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_FF8C0E80 \n"
"    CMP     R0, #1 \n"
"    MOV     R9, R0 \n"
"    CMPNE   R9, #5 \n"
"    BNE     loc_FF8C29F4 \n"
"    LDR     R0, [SP, #0x28] \n"
"    MOV     R2, R9 \n"
"    LDR     R1, [R0, #0x7C]! \n"
"    LDR     R12, [R0, #0x10]! \n"
"    LDR     R3, [R0, #4] \n"
"    MOV     R0, SP \n"
"    BLX     R12 \n"
"    B       loc_FF8C2A2C \n"

"loc_FF8C29F4:\n"
"    LDR     R0, [SP, #0x28] \n"
"    CMP     R9, #2 \n"
"    LDR     R3, [R0, #0x90] \n"
"    CMPNE   R9, #6 \n"
"    BNE     loc_FF8C2A40 \n"
"    LDR     R12, [R0, #0x8C] \n"
"    MOV     R2, R9 \n"
"    MOV     R1, #1 \n"
"    MOV     R0, SP \n"
"    BLX     R12 \n"
"    LDR     R0, [SP, #0x28] \n"
"    MOV     R2, SP \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_FF8C2408 \n"

"loc_FF8C2A2C:\n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R2, [SP, #0xC] \n"
"    MOV     R1, R9 \n"
"    BL      sub_FF8C26BC \n"
"    B       loc_FF8C2CC0 \n"

"loc_FF8C2A40:\n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R12, [R0, #0x8C] \n"
"    MOV     R2, R9 \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R12 \n"
"    B       loc_FF8C2CC0 \n"

"loc_FF8C2A58:\n"
"    CMP     R1, #0x24 \n"
"    CMPNE   R1, #0x25 \n"
"    BNE     loc_FF8C2AA4 \n"
"    LDR     R1, [R0, #0x7C] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R1, R0, R1, LSL#2 \n"
"    SUB     R1, R1, #8 \n"
"    LDMIA   R1, {R2,R3,R9} \n"
"    STMIA   R5, {R2,R3,R9} \n"
"    BL      sub_FF8BFBFC \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R3, [R0, #0x8C] \n"
"    LDR     R2, [R0, #0x90] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"
"    LDR     R0, [SP, #0x28] \n"
"    BL      sub_FF8C0054 \n"
"    B       loc_FF8C2CC0 \n"

"loc_FF8C2AA4:\n"
"    ADD     R1, R0, #4 \n"
"    LDMIA   R1, {R2,R3,R9} \n"
"    STMIA   R5, {R2,R3,R9} \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x28 \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FF8C2CA8 \n"
"    B       loc_FF8C2B60 \n"
"    B       loc_FF8C2B60 \n"
"    B       loc_FF8C2B68 \n"
"    B       loc_FF8C2B70 \n"
"    B       loc_FF8C2B70 \n"
"    B       loc_FF8C2B70 \n"
"    B       loc_FF8C2B60 \n"
"    B       loc_FF8C2B68 \n"
"    B       loc_FF8C2B70 \n"
"    B       loc_FF8C2B70 \n"
"    B       loc_FF8C2B88 \n"
"    B       loc_FF8C2B88 \n"
"    B       loc_FF8C2C94 \n"
"    B       loc_FF8C2C9C \n"
"    B       loc_FF8C2C9C \n"
"    B       loc_FF8C2C9C \n"
"    B       loc_FF8C2C9C \n"
"    B       loc_FF8C2CA4 \n"
"    B       loc_FF8C2CA8 \n"
"    B       loc_FF8C2CA8 \n"
"    B       loc_FF8C2CA8 \n"
"    B       loc_FF8C2CA8 \n"
"    B       loc_FF8C2CA8 \n"
"    B       loc_FF8C2CA8 \n"
"    B       loc_FF8C2B78 \n"
"    B       loc_FF8C2B80 \n"
"    B       loc_FF8C2B80 \n"
"    B       loc_FF8C2B80 \n"
"    B       loc_FF8C2B94 \n"
"    B       loc_FF8C2B94 \n"
"    B       loc_FF8C2B9C \n"
"    B       loc_FF8C2BD4 \n"
"    B       loc_FF8C2C0C \n"
"    B       loc_FF8C2C44 \n"
"    B       loc_FF8C2C7C \n"
"    B       loc_FF8C2C7C \n"
"    B       loc_FF8C2CA8 \n"
"    B       loc_FF8C2CA8 \n"
"    B       loc_FF8C2C84 \n"
"    B       loc_FF8C2C8C \n"

"loc_FF8C2B60:\n"
"    BL      sub_FF8BE598 \n"
"    B       loc_FF8C2CA8 \n"

"loc_FF8C2B68:\n"
"    BL      sub_FF8BE850 \n"
"    B       loc_FF8C2CA8 \n"

"loc_FF8C2B70:\n"
"    BL      sub_FF8BEA78 \n"
"    B       loc_FF8C2CA8 \n"

"loc_FF8C2B78:\n"
"    BL      sub_FF8BED9C \n"
"    B       loc_FF8C2CA8 \n"

"loc_FF8C2B80:\n"
"    BL      sub_FF8BEFB4 \n"
"    B       loc_FF8C2CA8 \n"

"loc_FF8C2B88:\n"
"    BL      sub_FF8BF370_my \n"  // --> Patched. Old value = 0xFF8BF370.
"    MOV     R8, #0 \n"
"    B       loc_FF8C2CA8 \n"

"loc_FF8C2B94:\n"
"    BL      sub_FF8BF4B0 \n"
"    B       loc_FF8C2CA8 \n"

"loc_FF8C2B9C:\n"
"    LDRH    R1, [R0, #4] \n"
"    STRH    R1, [SP, #0x1C] \n"
"    LDRH    R1, [R4, #2] \n"
"    STRH    R1, [SP, #0x1E] \n"
"    LDRH    R1, [R4, #4] \n"
"    STRH    R1, [SP, #0x20] \n"
"    LDRH    R1, [R4, #6] \n"
"    STRH    R1, [SP, #0x22] \n"
"    LDRH    R1, [R0, #0xC] \n"
"    STRH    R1, [SP, #0x24] \n"
"    LDRH    R1, [R4, #0xA] \n"
"    STRH    R1, [SP, #0x26] \n"
"    BL      sub_FF8C3D30 \n"
"    B       loc_FF8C2CA8 \n"

"loc_FF8C2BD4:\n"
"    LDRH    R1, [R0, #4] \n"
"    STRH    R1, [SP, #0x1C] \n"
"    LDRH    R1, [R4, #2] \n"
"    STRH    R1, [SP, #0x1E] \n"
"    LDRH    R1, [R4, #4] \n"
"    STRH    R1, [SP, #0x20] \n"
"    LDRH    R1, [R4, #6] \n"
"    STRH    R1, [SP, #0x22] \n"
"    LDRH    R1, [R4, #8] \n"
"    STRH    R1, [SP, #0x24] \n"
"    LDRH    R1, [R4, #0xA] \n"
"    STRH    R1, [SP, #0x26] \n"
"    BL      sub_FF8C3EA8 \n"
"    B       loc_FF8C2CA8 \n"

"loc_FF8C2C0C:\n"
"    LDRH    R1, [R4] \n"
"    STRH    R1, [SP, #0x1C] \n"
"    LDRH    R1, [R0, #6] \n"
"    STRH    R1, [SP, #0x1E] \n"
"    LDRH    R1, [R4, #4] \n"
"    STRH    R1, [SP, #0x20] \n"
"    LDRH    R1, [R4, #6] \n"
"    STRH    R1, [SP, #0x22] \n"
"    LDRH    R1, [R4, #8] \n"
"    STRH    R1, [SP, #0x24] \n"
"    LDRH    R1, [R4, #0xA] \n"
"    STRH    R1, [SP, #0x26] \n"
"    BL      sub_FF8C3F5C \n"
"    B       loc_FF8C2CA8 \n"

"loc_FF8C2C44:\n"
"    LDRH    R1, [R4] \n"
"    STRH    R1, [SP, #0x1C] \n"
"    LDRH    R1, [R4, #2] \n"
"    STRH    R1, [SP, #0x1E] \n"
"    LDRH    R1, [R4, #4] \n"
"    STRH    R1, [SP, #0x20] \n"
"    LDRH    R1, [R4, #6] \n"
"    STRH    R1, [SP, #0x22] \n"
"    LDRH    R1, [R0, #0xC] \n"
"    STRH    R1, [SP, #0x24] \n"
"    LDRH    R1, [R4, #0xA] \n"
"    STRH    R1, [SP, #0x26] \n"
"    BL      sub_FF8C4004 \n"
"    B       loc_FF8C2CA8 \n"

"loc_FF8C2C7C:\n"
"    BL      sub_FF8BF994 \n"
"    B       loc_FF8C2CA8 \n"

"loc_FF8C2C84:\n"
"    BL      sub_FF8C0158 \n"
"    B       loc_FF8C2CA8 \n"

"loc_FF8C2C8C:\n"
"    BL      sub_FF8C043C \n"
"    B       loc_FF8C2CA8 \n"

"loc_FF8C2C94:\n"
"    BL      sub_FF8C06F4 \n"
"    B       loc_FF8C2CA8 \n"

"loc_FF8C2C9C:\n"
"    BL      sub_FF8C08B0 \n"
"    B       loc_FF8C2CA8 \n"

"loc_FF8C2CA4:\n"
"    BL      sub_FF8C0A18 \n"

"loc_FF8C2CA8:\n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0, #0x7C] \n"
"    LDR     R2, [R0, #0x90] \n"
"    LDR     R3, [R0, #0x8C] \n"

"loc_FF8C2CB8:\n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"

"loc_FF8C2CC0:\n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #0x10 \n"
"    BEQ     loc_FF8C2CF8 \n"
"    BGT     loc_FF8C2CE8 \n"
"    CMP     R0, #1 \n"
"    CMPNE   R0, #4 \n"
"    CMPNE   R0, #0xE \n"
"    BNE     loc_FF8C2D2C \n"
"    B       loc_FF8C2CF8 \n"

"loc_FF8C2CE8:\n"
"    CMP     R0, #0x13 \n"
"    CMPNE   R0, #0x17 \n"
"    CMPNE   R0, #0x1A \n"
"    BNE     loc_FF8C2D2C \n"

"loc_FF8C2CF8:\n"
"    LDRSH   R0, [R4] \n"
"    CMN     R0, #0xC00 \n"
"    LDRNESH R1, [R4, #8] \n"
"    CMNNE   R1, #0xC00 \n"
"    STRNEH  R0, [SP, #0x1C] \n"
"    STRNEH  R1, [SP, #0x24] \n"
"    BNE     loc_FF8C2D2C \n"
"    ADD     R0, SP, #0x10 \n"
"    BL      sub_FF8C42A8 \n"
"    LDRH    R0, [SP, #0x10] \n"
"    STRH    R0, [SP, #0x1C] \n"
"    LDRH    R0, [SP, #0x18] \n"
"    STRH    R0, [SP, #0x24] \n"

"loc_FF8C2D2C:\n"
"    LDR     R0, [SP, #0x28] \n"
"    CMP     R8, #1 \n"
"    BNE     loc_FF8C2D7C \n"
"    LDR     R1, [R0, #0x7C] \n"
"    MOV     R2, #0xC \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R0, R0, R1, LSL#2 \n"
"    SUB     R8, R0, #8 \n"
"    LDR     R0, =0x575F8 \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_0043C0D4 \n"
"    LDR     R0, =0x57604 \n"
"    MOV     R2, #0xC \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_0043C0D4 \n"
"    LDR     R0, =0x57610 \n"
"    MOV     R2, #0xC \n"
"    MOV     R1, R8 \n"
"    BL      sub_0043C0D4 \n"
"    B       loc_FF8C2DF4 \n"

"loc_FF8C2D7C:\n"
"    LDR     R0, [R0] \n"
"    MOV     R3, #1 \n"
"    CMP     R0, #0xB \n"
"    BNE     loc_FF8C2DC0 \n"
"    MOV     R2, #0 \n"
"    STRD    R2, [SP] \n"
"    MOV     R2, R3 \n"
"    MOV     R1, R3 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF8BE36C \n"
"    MOV     R3, #1 \n"
"    MOV     R2, #0 \n"
"    STRD    R2, [SP] \n"
"    MOV     R2, R3 \n"
"    MOV     R1, R3 \n"
"    MOV     R0, #0 \n"
"    B       loc_FF8C2DF0 \n"

"loc_FF8C2DC0:\n"
"    MOV     R2, #1 \n"
"    STRD    R2, [SP] \n"
"    MOV     R3, R2 \n"
"    MOV     R1, R2 \n"
"    MOV     R0, R2 \n"
"    BL      sub_FF8BE36C \n"
"    MOV     R3, #1 \n"
"    MOV     R2, R3 \n"
"    MOV     R1, R3 \n"
"    MOV     R0, R3 \n"
"    STR     R3, [SP] \n"
"    STR     R3, [SP, #4] \n"

"loc_FF8C2DF0:\n"
"    BL      sub_FF8BE4E4 \n"

"loc_FF8C2DF4:\n"
"    LDR     R0, [SP, #0x28] \n"
"    BL      sub_FF8C3C9C \n"
"    B       loc_FF8C278C \n"
);
}

/*************************************************************/
//** sub_FF8BF370_my @ 0xFF8BF370 - 0xFF8BF430, length=49
void __attribute__((naked,noinline)) sub_FF8BF370_my() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    LDR     R7, =0x4884 \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R1, #0x3E \n"
"    BL      sub_0043AD2C /*_ClearEventFlag*/ \n"
"    MOV     R2, #0 \n"
"    LDRSH   R0, [R4, #4] \n"
"    MOV     R1, R2 \n"
"    BL      sub_FF8BE06C \n"
"    MOV     R6, R0 \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_FF8BE1CC \n"
"    LDRSH   R0, [R4, #8] \n"
"    BL      sub_FF8BE224 \n"
"    LDRSH   R0, [R4, #0xA] \n"
"    BL      sub_FF8BE27C \n"
"    LDRSH   R0, [R4, #0xC] \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF8BE2D4 \n"
"    MOV     R5, R0 \n"
"    LDR     R0, [R4] \n"
"    LDR     R8, =0x57610 \n"
"    CMP     R0, #0xB \n"
"    MOVEQ   R6, #0 \n"
"    MOVEQ   R5, R6 \n"
"    BEQ     loc_FF8BF404 \n"
"    CMP     R6, #1 \n"
"    BNE     loc_FF8BF404 \n"
"    LDRSH   R0, [R4, #4] \n"
"    LDR     R1, =0xFF8BDFC4 \n"
"    MOV     R2, #2 \n"
"    BL      sub_FF9865F4 \n"
"    STRH    R0, [R4, #4] \n"
"    MOV     R0, #0 \n"
"    STR     R0, [R7, #0x28] \n"
"    B       loc_FF8BF40C \n"

"loc_FF8BF404:\n"
"    LDRH    R0, [R8] \n"
"    STRH    R0, [R4, #4] \n"

"loc_FF8BF40C:\n"
"    CMP     R5, #1 \n"
"    LDRNEH  R0, [R8, #8] \n"
"    BNE     loc_FF8BF428 \n"
"    LDRSH   R0, [R4, #0xC] \n"
"    LDR     R1, =0xFF8BE048 \n"
"    MOV     R2, #0x20 \n"
"    BL      sub_FF8C3CEC \n"

"loc_FF8BF428:\n"
"    STRH    R0, [R4, #0xC] \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_FF8AE404_my \n"  // --> Patched. Old value = 0xFF8AE404.
"    LDR     PC, =0xFF8BF434 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF8AE404_my @ 0xFF8AE404 - 0xFF8AE46C, length=27
void __attribute__((naked,noinline)) sub_FF8AE404_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    LDR     R5, =0x450C \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R5, #4] \n"
"    CMP     R0, #1 \n"
"    LDRNE   R1, =0x14D \n"
"    LDRNE   R0, =0xFF8AE23C \n"
"    BLNE    _DebugAssert \n"
"    CMN     R4, #0xC00 \n"
"    LDREQSH R4, [R5, #2] \n"
"    CMN     R4, #0xC00 \n"
"    LDREQ   R1, =0x153 \n"
"    LDREQ   R0, =0xFF8AE23C \n"
"    STRH    R4, [R5, #2] \n"
"    BLEQ    _DebugAssert \n"
"    MOV     R0, R4 \n"
"    BL      apex2us \n"  // --> Patched. Old value = _apex2us. _apex2us
"    MOV     R4, R0 \n"
//"  BL      _sub_FF908468 \n"  // --> Nullsub call removed.
"    MOV     R0, R4 \n"
"    BL      sub_FF90FF1C \n"
"    TST     R0, #1 \n"
"    LDMEQFD SP!, {R4-R6,PC} \n"
"    LDMFD   SP!, {R4-R6,LR} \n"
"    MOV     R1, #0x158 \n"
"    LDR     R0, =0xFF8AE23C \n"
"    B       _DebugAssert \n"
);
}
