#ifndef _penulis_input_h_
#define _penulis_input_h_

#include "lib.h"

typedef struct {
    unsigned int key[UCHAR_MAX];
} Key;

extern Key keyIns;

void inputInit(void);
void inputNull(void);
void inputTyping(void);
void inputProcess(XEvent *ev);

#endif
