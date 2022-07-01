#ifndef _penulis_x_h_
#define _penulis_x_h_

#include <lib.h>

typedef struct {
    unsigned long black,
    white,
    red,
    green,
    blue,

    bg
} Clr;

extern Display *displayIns;
extern int screenIns;
extern Window windowIns;
extern GC gcIns;
extern Clr clrIns;

void xInit(int argc, char **argv);
void xFree(void);

void xInitColor(Display *d, int s);
unsigned long xCreateColor(float r, float g, float b);

#endif
