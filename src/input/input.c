#include "main.h"

const char charNumSh[] = ")!@#$%^&*(";
const char charSymbol[]   = "`-=[]\\;',./";
const char charSymbolSh[] = "~_+{}|:\"<>?";
Key keyIns;

void inputInit(){
    KeySym ks[] = {
        // 0
        XK_Delete, XK_KP_Delete,

        // 2
        XK_Home, XK_End,
        XK_Up, XK_Right, XK_Down, XK_Left,

        // 8
        XK_BackSpace,
        XK_Tab,
        XK_Return,

        // 11, vertical tab (VT)
        XK_Page_Up, XK_Page_Down,

        // 13
        XK_KP_Enter,
        XK_Shift_L,
        XK_Shift_R,

        // 16
        XK_Pause,

        // 17
        XK_Control_L, XK_Control_R,
        XK_Alt_L, XK_Alt_R,

        // 21
        XK_Caps_Lock, XK_Num_Lock,
        XK_Insert, XK_KP_Insert,

        // 25
        XK_Super_L,  // win button
        XK_Menu,  // context menu button (right-click effect)

        // 27
        XK_Escape,

        // 28
        XK_KP_Up, XK_KP_Right, XK_KP_Down, XK_KP_Left,

        // 32
        XK_space,

        // 33
        XK_grave, XK_minus, XK_equal,
        XK_bracketleft, XK_bracketright, XK_backslash,
        XK_semicolon, XK_apostrophe,
        XK_comma, XK_period, XK_slash,

        // 44
        XK_F1, XK_F2, XK_F3, XK_F4,

        // 48
        XK_0, XK_1, XK_2, XK_3, XK_4,
        XK_5, XK_6, XK_7, XK_8, XK_9,

        // 58
        XK_F5, XK_F6, XK_F7,
        XK_F8, XK_F9, XK_F10, XK_F11,

        // 65
        XK_A, XK_B, XK_C, XK_D, XK_E,
        XK_F, XK_G, XK_H, XK_I, XK_J,
        XK_K, XK_L, XK_M, XK_N, XK_O,
        XK_P, XK_Q, XK_R, XK_S, XK_T,
        XK_U, XK_V, XK_W, XK_X, XK_Y, XK_Z,

        // 91
        XK_F12,
        XK_Scroll_Lock,

    };
//    printf("ks len %d\n", ARR_LEN(ks));  // @test
    for (uint8_t i=0; i<ARR_LEN(ks); i++) {

        // @test
//        if(ks[i] == XK_0) printf("keysym to keyCode 0 %d\n", i);
//        if(ks[i] == XK_A) printf("keysym to keyCode A %d\n", i);

        keyIns.key[i] = XKeysymToKeycode(displayIns, ks[i]);
    }

#if MAX_KEY != 93
#error MAX_KEY = ARR_LEN(ks)
#endif


    // @test
    //    printf("compare keycode %d %d %d\n",
    //           XKeysymToKeycode(displayIns, XK_Pause),
    //           XKeysymToKeycode(displayIns, XK_Break),
    //           XKeysymToKeycode(displayIns, XK_Menu));
}
void inputNull(void){
    inputNormalNull();
    inputShiftNull();
}
void inputTyping(void){
    inputNull();
    inputNormalTyping();
    inputShiftTyping();
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
                inputShiftProcess(ev);
            }
        }else{
            if(ev->xkey.state & AltMask){

            }else{
                inputNormalProcess(ev);
            }

        }
    }
}
