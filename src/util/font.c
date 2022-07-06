#include <main.h>

FontProvider fontProviderIns;

//#define FONT_PATTERN_ALL "*"
//#define FONT_PATTERN_FIXED "*fixed*"
//#define FONT_PATTERN_FIXED_BOLD "*fixed-bold*"
//#define FONT_PATTERN_ISO "*iso*"
//#define FONT_PATTERN_COURIER "*courier*"

void fontInit(){
    FontProvider *fp = &fontProviderIns;

    //    const int maxListFont = 10;
    //    int nameCount;
    //    char **fontName = XListFonts(displayIns,
    //                                FONT_PATTERN_COURIER, maxListFont, &nameCount);
    //    for(int i=0; i<nameCount; i++){
    //        printf("font %d %s\n", i, fontName[i]);
    //    }
    //    XFreeFontNames(fontName);

    int fontW = 0;
    int fontH = 0;
    char fontName[] = "-misc-fixed-bold-r-normal--13-100-100-100-c-70-iso8859-1";
    XFontStruct *fontStruct = XLoadQueryFont(displayIns, fontName);
    if(fontStruct) {
        XSetFont(displayIns, gcIns, fontStruct->fid);
        fp->fontW = fontW = fontStruct->max_bounds.width;
        fp->fontH = fontH = fontStruct->max_bounds.ascent + fontStruct->max_bounds.descent;
    }else{
        printf("font struct null");
    }

    const int sheetCharMaxSize = 16;

    XWindowAttributes attr;
    XGetWindowAttributes(displayIns, windowIns, &attr);
    fontProviderIns.charNormal = XCreatePixmap(displayIns,
                                               windowIns,
                                               sheetCharMaxSize*fontW, sheetCharMaxSize*fontH,
                                               attr.depth);

    XSetBackground(displayIns, gcIns, clrIns.bg);
    XSetForeground(displayIns, gcIns, clrIns.white);

    unsigned char c = 0;
    char str[2];
    for(int i=0; i<sheetCharMaxSize; i++){
        for(int j=0; j<sheetCharMaxSize; j++){
            sprintf(str, "%c", c++);
            XDrawImageString(displayIns, fontProviderIns.charNormal,
                             gcIns, j*fontW, fontStruct->max_bounds.ascent +i*fontH, str, strlen(str));
        }
    }

//    XCopyArea(displayIns, fontProviderIns.charNormal,
//              windowIns, gcIns, 0, 0, attr.width, attr.height, 0, 0);

    XFreeFont(displayIns, fontStruct);
}
void fontSet(uint8_t c, int x, int y){
    FontProvider *fp = &fontProviderIns;
    const uint8_t sheetCharMaxSize = 16;
    XCopyArea(displayIns, fontProviderIns.charNormal,
              windowIns, gcIns,
              (c % sheetCharMaxSize) * fp->fontW,
              (c / sheetCharMaxSize) * fp->fontH,
              fp->fontW, fp->fontH, x, y);
}
void fontFree(){
    XFreePixmap(displayIns, fontProviderIns.charNormal);
}

