#include "main.h"

Key keyIns;

void inputInit(){
    KeySym ks[] = {
        // 0
        XK_Delete, XK_KP_Delete,

        // 2
        XK_Home, XK_End,
        XK_Left, XK_Up, XK_Right, XK_Down,

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

        // 16, dummy
        XK_5,

        // 17
        XK_Control_L, XK_Control_R,
        XK_Alt_L, XK_Alt_R,

        // 21, dummy
        XK_1, XK_2, XK_3, XK_4,
        XK_5, XK_6,

        // 27
        XK_Escape,

        // 28, dummy
        XK_1, XK_2, XK_3, XK_4,

        // 32
        XK_space,
        XK_exclam,
        XK_quotedbl,
        XK_numbersign,
        XK_dollar,
        XK_percent,
        XK_ampersand,
        XK_apostrophe,
        XK_parenleft,
        XK_parenright,
        XK_asterisk,
        XK_plus,
        XK_comma,
        XK_minus,
        XK_period,
        XK_slash,

        // 48
        XK_0, XK_1, XK_2, XK_3, XK_4,
        XK_5, XK_6, XK_7, XK_8, XK_9,

        // 58
        XK_semicolon,  // XK_colon
        XK_semicolon,
        XK_less, XK_equal, XK_greater, XK_question, XK_at,

        // 65
        XK_A, XK_B, XK_C, XK_D, XK_E,
        XK_F, XK_G, XK_H, XK_I, XK_J,
        XK_K, XK_L, XK_M, XK_N, XK_O,
        XK_P, XK_Q, XK_R, XK_S, XK_T,
        XK_U, XK_V, XK_W, XK_X, XK_Y, XK_Z,

        // 91
        XK_bracketleft, XK_backslash, XK_bracketright,
        XK_6,  // caret
        XK_minus,  // underscore
        XK_grave,

        // 97, XK_a
        XK_F1, XK_F2, XK_F3, XK_F4, XK_F5, XK_F6,
        XK_F7, XK_F8, XK_F9, XK_F10, XK_F11, XK_F12,

        //
        XK_equal,
        XK_semicolon, XK_apostrophe,
        XK_comma, XK_period, XK_slash,

        //





    };
    for (uint8_t i=0; i<ARR_LEN(ks); i++) {
        keyIns.key[i] = XKeysymToKeycode(displayIns, ks[i]);
    }


//    printf("compare keycode %d %d %d",
//           XKeysymToKeycode(displayIns, XK_Return),
//           XKeysymToKeycode(displayIns, XK_ISO_Enter),
//           XKeysymToKeycode(displayIns, XK_KP_Enter));
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
