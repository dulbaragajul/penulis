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
        XK_5,

//    #define XK_space                         0x0020  /* U+0020 SPACE */
//    #define XK_exclam                        0x0021  /* U+0021 EXCLAMATION MARK */
//    #define XK_quotedbl                      0x0022  /* U+0022 QUOTATION MARK */
//    #define XK_numbersign                    0x0023  /* U+0023 NUMBER SIGN */
//    #define XK_dollar                        0x0024  /* U+0024 DOLLAR SIGN */
//    #define XK_percent                       0x0025  /* U+0025 PERCENT SIGN */
//    #define XK_ampersand                     0x0026  /* U+0026 AMPERSAND */
//    #define XK_apostrophe                    0x0027  /* U+0027 APOSTROPHE */
//    #define XK_quoteright                    0x0027  /* deprecated */
//    #define XK_parenleft                     0x0028  /* U+0028 LEFT PARENTHESIS */
//    #define XK_parenright                    0x0029  /* U+0029 RIGHT PARENTHESIS */
//    #define XK_asterisk                      0x002a  /* U+002A ASTERISK */
//    #define XK_plus                          0x002b  /* U+002B PLUS SIGN */
//    #define XK_comma                         0x002c  /* U+002C COMMA */
//    #define XK_minus                         0x002d  /* U+002D HYPHEN-MINUS */
        XK_period,
        XK_backslash,

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

        // 97
        XK_a, XK_b, XK_c, XK_d, XK_e,
        XK_f, XK_g, XK_h, XK_i, XK_j,
        XK_k, XK_l, XK_m, XK_n, XK_o,
        XK_p, XK_q, XK_r, XK_s, XK_t,
        XK_u, XK_v, XK_w, XK_x, XK_y, XK_z,

        //
        XK_equal,
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
        if(i>='a' && i<='z'){
            keyIns.key[i] = XKeysymToKeycode(displayIns, ks[i]);
        }
    }
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
