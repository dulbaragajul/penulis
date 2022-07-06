#ifndef _penulis_font_h_
#define _penulis_font_h_

#include "lib.h"

typedef struct {
    Pixmap charNormal;
    unsigned char fontW;
    unsigned char fontH;
} FontProvider;

extern FontProvider fontProviderIns;

void fontInit(void);
void fontSet(uint8_t c, int x, int y);
void fontFree(void);

#endif
