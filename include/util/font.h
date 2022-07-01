#ifndef _penulis_font_h_
#define _penulis_font_h_

#include <lib.h>

typedef struct {
    Pixmap charNormal;
} FontProvider;

extern FontProvider fontProviderIns;

void fontInit(void);
void fontFree(void);

#endif
