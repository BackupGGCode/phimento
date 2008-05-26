#ifndef __TEXT_H
#define __TEXT_H

#define COLOR_BLACK			0x00
#define COLOR_BLUE 			0x01
#define COLOR_GREEN 		0x02
#define COLOR_CYAN 			0x03
#define COLOR_RED 			0x04
#define COLOR_MAGENTA 		0x05
#define COLOR_BROWN 		0x06
#define COLOR_LIGHT_GREY	0x07
#define COLOR_DARK_GREY		0x08
#define COLOR_LIGHT_BLUE	0x09
#define COLOR_WHITE			0x0F

void init_video();
void clear();
void move_csr();
void putc(u8_t _ch);
void puts(u8_t* _text);
void scroll();
void set_text_color(u8_t _backcolor, u8_t _forecolor);
s32_t get_xpos();
s32_t get_ypos();
void set_xpos(s32_t _x);
void set_ypos(s32_t _y);

#endif /* __TEXT_H */
