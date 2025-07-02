#ifndef HLCD_Interface_H
#define HLCD_Interface_H

void HLCD_void_Init(void);
void HLCD_voidLcdWriteCmd(u8 Copy_u8Cmd);
void HLCD_voidWriteChar(u8 Copy_u8Char);
u8 HLCD_SetCursor(u8 Copy_LineNb,u8 Copy_CharNb);
void HLCD_WriteStirng(const u8 *Copy_u8PtrString);
void HLCD_CLEAR(void);
void HLCD_voidWriteNumbers(u16 Copy_u16Number);
void HLCD_voidLcdWriteNumber(u16 Copy_u16Number);
#define HLCD_Line1     1
#define HLCD_Line2     2
#define HLCD_Clear     0x01
#endif
