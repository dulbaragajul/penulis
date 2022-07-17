#ifndef _penulis_input_h_
#define _penulis_input_h_

#include "lib.h"

/* calculate key
 * num  10
 * alpha  36
 * F1-12  48
 * `-= Backspace Delete Insert  54
 * shift ctrl alt (left/right)  60
 * []\;',./  68
 * left right up down  72
 * Esc Tab Space Enter  76
 * CapsLock NumLock  78
*/
#define MAX_KEY 'a'

typedef struct {
    unsigned int key[UCHAR_MAX];
} Key;

extern Key keyIns;

void inputInit(void);
void inputNull(void);
void inputTyping(void);
void inputProcess(XEvent *ev);

#endif
