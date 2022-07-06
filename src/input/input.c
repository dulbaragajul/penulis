#include "main.h"

Key keyIns;

void inputInit(){
    KeySym ks[] = {
        // dummy
        XK_0, XK_1, XK_2, XK_3, XK_4,
        XK_5, XK_6, XK_7, XK_8, XK_9,
        XK_0, XK_1, XK_2, XK_3, XK_4,
        XK_5, XK_6, XK_7, XK_8, XK_9,
        XK_0, XK_1, XK_2, XK_3, XK_4,
        XK_5, XK_6, XK_7, XK_8, XK_9,
        XK_0, XK_1, XK_2, XK_3, XK_4,
        XK_5, XK_6, XK_7, XK_8, XK_9,
        XK_0, XK_1, XK_2, XK_3, XK_4,
        XK_5, XK_6, XK_7,

        // 48
        XK_0, XK_1, XK_2, XK_3, XK_4,
        XK_5, XK_6, XK_7, XK_8, XK_9,

        // 58
        XK_semicolon,
        XK_semicolon,  // dummy
        XK_less, XK_equal, XK_greater, XK_question, XK_at,

        // 65
        XK_A, XK_B, XK_C, XK_D, XK_E,
        XK_F, XK_G, XK_H, XK_I, XK_J,
        XK_K, XK_L, XK_M, XK_N, XK_O,
        XK_P, XK_Q, XK_R, XK_S, XK_T,
        XK_U, XK_V, XK_W, XK_X, XK_Y, XK_Z,

        //
        XK_grave, XK_minus, XK_equal,
        XK_bracketleft, XK_bracketright, XK_backslash,
        XK_semicolon, XK_apostrophe,
        XK_comma, XK_period, XK_slash,
        XK_space,

        //
        XK_Tab, XK_Return,

        //
        XK_BackSpace, XK_Escape, XK_Delete,

        //
        XK_Home, XK_Left, XK_Up, XK_Right, XK_Down, XK_Page_Up, XK_Page_Down, XK_End,

        XK_F1, XK_F2, XK_F3, XK_F4, XK_F5, XK_F6,
        XK_F7, XK_F8, XK_F9, XK_F10, XK_F11, XK_F12,

    };
    for (uint8_t i=0; i<UCHAR_MAX; i++) {
        if(i>=1 && i<=12){

        }
        if(i>='0' && i<='9'){
            keyIns.key[i] = XKeysymToKeycode(displayIns, ks[i]);
        }
        if(i>='A' && i<='Z'){
            keyIns.key[i] = XKeysymToKeycode(displayIns, ks[i]);
        }
    }
}
void inputNull(void){
    inputNormalNull();
}
void inputTyping(void){
    inputNull();
    inputNormalTyping();
}
void inputProcess(XEvent *ev){
    if(ev->xkey.state & ControlMask){

        if(ev->xkey.state & ShiftMask){
            if(ev->xkey.state & AltMask){

            }else{

            }

        }else{
            if(ev->xkey.state & AltMask){

            }else{

            }

        }
    }else{

        if(ev->xkey.state & ShiftMask){
            if(ev->xkey.state & AltMask){

            }else{

            }
        }else{
            if(ev->xkey.state & AltMask){

            }else{
                inputNormalProcess(ev);
            }

        }
    }
}
