#ifndef _penulis_inputShift_h_
#define _penulis_inputShift_h_

#include "input.h"

typedef struct {
    void (*inp[MAX_KEY]) (XEvent*, uint8_t);

    void (*inp0)(uint8_t);
    void (*inp1)(uint8_t);
    void (*inp2)(uint8_t);
    void (*inp3)(uint8_t);
    void (*inp4)(uint8_t);
    void (*inp5)(uint8_t);
    void (*inp6)(uint8_t);
    void (*inp7)(uint8_t);
    void (*inp8)(uint8_t);
    void (*inp9)(uint8_t);

    void (*inpA)(uint8_t);
 } InpShift;

extern InpShift inpShiftIns;

void inputShiftNull(void);
void inputShiftTyping(void);
void inputShiftProcess(XEvent *ev);

#endif
