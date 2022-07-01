#ifndef _penulis_file_h_
#define _penulis_file_h_

#include <lib.h>

typedef struct {
    uint8_t *data;
    uint64_t size;
} File;

void fileInit(File *f);

#endif
