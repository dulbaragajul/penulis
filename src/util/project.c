#include <main.h>

Project projectIns;

void projectInit(){
    listInit(&projectIns.fileList);

    listInsert(&projectIns.fileList, NULL, NEW(File));
}
