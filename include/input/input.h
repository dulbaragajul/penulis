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
#define MAX_KEY 93

typedef struct {
    unsigned int key[MAX_KEY];
} Key;

extern const char charNumSh[];
extern const char charSymbol[];
extern const char charSymbolSh[];
extern Key keyIns;

void inputInit(void);
void inputNull(void);
void inputTyping(void);
void inputProcess(XEvent *ev);

#endif
