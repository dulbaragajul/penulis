#include "main.h"

void utilNotif(const char *str, ...){
    va_list vl;
    va_start(vl, str);

    char param[128];
    vsprintf( param, str, vl);
    char notif[180];
    sprintf(notif, "notify-send -t 2000 \"Info\" \"%s\"", param);
    system(notif);
}
