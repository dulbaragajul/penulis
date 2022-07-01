#include <main.h>

Display *displayIns;
int screenIns;
Window windowIns;
GC gcIns;
Clr clrIns;

void xInit(int argc, char **argv){
    displayIns = XOpenDisplay("");
    screenIns = DefaultScreen(displayIns);

    xInitColor(displayIns, screenIns);

    unsigned long myforeground, mybackground;
    mybackground = clrIns.bg;
    myforeground = clrIns.white;

    Window rootWin = DefaultRootWindow(displayIns);
    XWindowAttributes attr;
    XGetWindowAttributes(displayIns, rootWin, &attr);

    XSizeHints myhint;
    myhint.x = 0;
    myhint.y = 0;
    myhint.flags = PPosition|PSize;
    myhint.width = attr.width;
    myhint.height = attr.height;

    windowIns = XCreateSimpleWindow(displayIns, rootWin,
                                    myhint.x, myhint.y,
                                    myhint.width, myhint.height,
                                    0, myforeground, mybackground);

    /* window manager properties (yes, use of StdProp is obsolete) */
    XSetStandardProperties(displayIns, windowIns, "Penulis", "Penulis",
                           None, argv, argc, &myhint);

    gcIns = XCreateGC(displayIns, windowIns, 0, 0);

    //    int depth = XDefaultDepth(displayIns, screenIns);
    //    printf("depth %d", depth);  // depth 24

    //    int ldCount;
    //    int *ld = XListDepths(displayIns, screenIns, &ldCount);  // 24, 1, 4, 8, 15, 16, 32
    //    for(int i=0; i<ldCount; i++){
    //        printf("depth %d", *(ld+i) );
    //    }
    //    XFree(ld);
}

void xFree(){
    XFreeGC(displayIns, gcIns);
    XDestroyWindow(displayIns, windowIns);
    XCloseDisplay(displayIns);
}

void xInitColor(Display *d, int s){
    clrIns.black = BlackPixel(d, s);
    clrIns.white = WhitePixel(d, s);
    clrIns.red = xCreateColor(1, 0, 0);
    clrIns.green = xCreateColor(0, 1, 0);
    clrIns.blue = xCreateColor(0, 0, 1);
    clrIns.bg = clrIns.black;
}
unsigned long xCreateColor(float r, float g, float b){
    Colormap cm = DefaultColormap(displayIns, screenIns);
    XColor c;

    c.red = USHRT_MAX * r;
    c.green = USHRT_MAX * g;
    c.blue = USHRT_MAX * b;
    XAllocColor(displayIns, cm, &c);

    return c.pixel;
}
