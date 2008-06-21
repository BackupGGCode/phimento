#ifndef __STRING_H
#define __STRING_H

void memset(u8_t* _dest, u8_t _val, u32_t _len);
u32_t strcpy(u8_t *_dest, u8_t *_src);
u32_t strncpy(u8_t *_dest, u8_t *_src, u32_t _off, u32_t _len);

#endif /* __STRING_H */
