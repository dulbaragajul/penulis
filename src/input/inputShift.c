#include "main.h"

InpShift inpShiftIns;

void inputShiftNull(void){
    InpShift *inp = &inpShiftIns;
    for (int i=0; i<MAX_KEY; i++) {
        inp->inp[i] = NULL;
    }
    inp->inp0 = NULL;
    inp->inp1 = NULL;
    inp->inp2 = NULL;
    inp->inp3 = NULL;
    inp->inp4 = NULL;
    inp->inp5 = NULL;
    inp->inp6 = NULL;
    inp->inp7 = NULL;
    inp->inp8 = NULL;
    inp->inp9 = NULL;

    inp->inpA = NULL;
}
void inputShiftTyping(){
    InpShift *inp = &inpShiftIns;
    for (uint8_t i='!'; i<='+'; i++) {
        inp->inp[i] = inputChar;
    }
    for (uint8_t i='0'; i<='9'; i++) {
        inp->inp[i] = inputChar;
    }
    for (uint8_t i='A'; i<='Z'; i++) {
        inp->inp[i] = inputChar;
    }
}
void inputShiftProcess(XEvent *ev){
    InpShift *inp = &inpShiftIns;
    unsigned int c = ev->xkey.keycode;


    uint8_t keyI;
    for (int i=0; i<MAX_KEY; i++) {
        if( ! inp->inp[i] ) continue;
        if(c != keyIns.key[i] ) continue;

        if('0'<=i && i<='9') keyI = charNumSh[i-'0'];
        else if('!'<=i && i<='+') keyI = charSymbolSh[i-'!'];
        else if('A'<=i && i<='Z') keyI = i;
        else keyI = 0;

        inp->inp[i](ev, keyI);
        break;
    }
}
