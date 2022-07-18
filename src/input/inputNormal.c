#include "main.h"

InpNormal inpNormalIns;

void inputNormalNull(void){
    InpNormal *inp = &inpNormalIns;
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
void inputNormalTyping(){
    InpNormal *inp = &inpNormalIns;
    for (int i='!'; i<MAX_KEY; i++) {
        inp->inp[i] = inputChar;
    }
//    inp->inp0 = inputChar;
//    inp->inp1 = inputChar;
//    inp->inp2 = inputChar;
//    inp->inp3 = inputChar;
//    inp->inp4 = inputChar;
//    inp->inp5 = inputChar;
//    inp->inp6 = inputChar;
//    inp->inp7 = inputChar;
//    inp->inp8 = inputChar;
//    inp->inp9 = inputChar;

//    inp->inpA = inputChar;
}
void inputNormalProcess(XEvent *ev){
    InpNormal *inp = &inpNormalIns;
    unsigned int c = ev->xkey.keycode;

    uint8_t keyI;
    for (int i=0; i<MAX_KEY; i++) {
        if( ! inp->inp[i] ) continue;
        if('A'<=i && i<='Z') keyI = i + 32;
        else keyI = i;
        if(c != keyIns.key[keyI] ) continue;
        inp->inp[i](ev, keyI);
        break;
    }

//    if(c == keyIns.key['0'] && inp->inp0){
//        inp->inp0('0');
//    }else if(c == keyIns.key['1'] && inp->inp1){
//        inp->inp1('1');
//    }else if(c == keyIns.key['2'] && inp->inp2){
//        inp->inp2('2');
//    }else if(c == keyIns.key['3'] && inp->inp3){
//        inp->inp3('3');
//    }else if(c == keyIns.key['4'] && inp->inp4){
//        inp->inp4('4');
//    }

//    else if(c == keyIns.key['a'] && inp->inpA){
//        inp->inpA('a');
//    }
}
