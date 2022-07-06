#ifndef _penulis_inputNormal_h_
#define _penulis_inputNormal_h_

#include "lib.h"

typedef struct {
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
 } InpNormal;

extern InpNormal inpNormalIns;

void inputNormalNull(void);
void inputNormalTyping();
void inputNormalProcess(XEvent *ev);

#endif
