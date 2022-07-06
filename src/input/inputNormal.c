#include "main.h"

InpNormal inpNormalIns;

void inputNormalNull(void){
    InpNormal *inp = &inpNormalIns;
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
    inp->inp0 = inputChar;
    inp->inp1 = inputChar;
    inp->inp2 = inputChar;
    inp->inp3 = inputChar;
    inp->inp4 = inputChar;
    inp->inp5 = inputChar;
    inp->inp6 = inputChar;
    inp->inp7 = inputChar;
    inp->inp8 = inputChar;
    inp->inp9 = inputChar;

    inp->inpA = inputChar;
}
void inputNormalProcess(XEvent *ev){
    InpNormal *inp = &inpNormalIns;
    unsigned int c = ev->xkey.keycode;
    if(c == keyIns.key['0'] && inp->inp0){
        inp->inp0('0');
    }else if(c == keyIns.key['1'] && inp->inp1){
        inp->inp1('1');
    }else if(c == keyIns.key['2'] && inp->inp2){
        inp->inp2('2');
    }else if(c == keyIns.key['3'] && inp->inp3){
        inp->inp3('3');
    }else if(c == keyIns.key['4'] && inp->inp4){
        inp->inp4('4');
    }

    else if(c == keyIns.key['A'] && inp->inpA){
        inp->inpA('a');
    }
}
