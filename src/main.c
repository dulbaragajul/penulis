#include <main.h>

void scaleDrawable(Display *dis, Window win, GC gc, int x, int y){
    XWindowAttributes attr;
    Status s = XGetWindowAttributes(dis, win, &attr);
    Pixmap pm = XCreatePixmap(dis, win, attr.width, attr.height, attr.depth);
    for(int i=0; i<attr.height/y; i++){
        for(int j=0; j<attr.width/x; j++){
            XCopyArea(dis, win, pm, gc, j, i, x, y, j*x, i*y);
        }
    }
    XCopyArea(dis, pm, win, gc, 0, 0, attr.width, attr.height, 0, 0);
    XFreePixmap(dis, pm);
}

int main(int argc, char **argv)
{
    char hello[] = "Hello World!";
    char hi[] = "hi!";

    Display *mydisplay;
    Window  mywindow;

    GC      mygc;

    XEvent myevent;
    KeySym mykey;

    XSizeHints myhint;

    int myscreen;
    unsigned long myforeground, mybackground;
    int i;
    char text[10];
    int done;

    xInit(argc, argv);

    /* setup display/screen */
    //    mydisplay = XOpenDisplay("");
    mydisplay = displayIns;

    //    myscreen = DefaultScreen(mydisplay);
    myscreen = screenIns;

    /* drawing contexts for an window */
    //    myforeground = BlackPixel(mydisplay, myscreen);
    //    mybackground = WhitePixel(mydisplay, myscreen);
    mybackground = BlackPixel(mydisplay, myscreen);
    myforeground = WhitePixel(mydisplay, myscreen);
    myhint.x = 10;
    myhint.y = 10;
    myhint.width = 350;
    myhint.height = 250;
    myhint.flags = PPosition|PSize;

    mywindow = windowIns;
    mygc = gcIns;

    /* allow receiving mouse events */
    XSelectInput(mydisplay,mywindow,
                 ButtonPressMask|KeyPressMask|ExposureMask);

    /* show up window */
    XMapRaised(mydisplay, mywindow);

    // solve error when click window close button
    Atom WM_DELETE_WINDOW = XInternAtom(mydisplay, "WM_DELETE_WINDOW", True);
    XSetWMProtocols(mydisplay, mywindow, &WM_DELETE_WINDOW, 1);

    fontInit();

    /* event loop */
    done = 0;
    while(done==0){

        /* fetch event */
        XNextEvent(mydisplay, &myevent);

        switch(myevent.type){

        case Expose:
            /* Window was showed. */
            if(myevent.xexpose.count==0){
                XDrawImageString(myevent.xexpose.display,
                                 myevent.xexpose.window,
                                 mygc,
                                 200, 200,
                                 hello, strlen(hello));
            }
            break;
        case MappingNotify:
            /* Modifier key was up/down. */
            XRefreshKeyboardMapping(&myevent);
            break;
        case ButtonPress:
            /* Mouse button was pressed. */

            XDrawString(myevent.xbutton.display,
                        myevent.xbutton.window,
                        mygc,
                        myevent.xbutton.x, myevent.xbutton.y,
                        hi, strlen(hi));
            break;
        case KeyPress:
            /* Key input. */
            i = XLookupString(&myevent, text, 10, &mykey, 0);
            if(i==1 && text[0]=='q') done = 1;
            else if(i == 1 && text[0]=='c'){

            }else if(i == 1 && text[0]=='s'){
                scaleDrawable(mydisplay, mywindow, mygc, 2, 2);
            }
            break;
        case ClientMessage:
            done = 1;
            break;
        }  // switch
    }  // while

    fontFree();
    xFree();

    return 0;
}
