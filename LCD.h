#ifndef __LCD_H__
#define __LCD_H__
#define  time  500
void LCD_Init              (void);
void LCD_command           (unsigned int);
void LCD_data              (unsigned char);
void LCD_printInt          (int);
void LCD_printFloat        (float);
void LCD_printString       (char*);
void LCD_errormsg          (void);
void LCD_setcursorRowCol   (unsigned int, unsigned int);
void displayTime           (int, int, int, int);
void loading               (void);
#endif
