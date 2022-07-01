#ifndef _penulis_project_h_
#define _penulis_project_h_

#include <list.h>

typedef struct {
    List fileList;
} Project;

extern Project projectIns;

void projectInit(void);


#endif
