#ifndef _penulis_list_h_
#define _penulis_list_h_

#include <lib.h>

typedef struct List_ List;

typedef struct Item_ {
    void *d;  // data
    List *l;  // parent List
    struct Item_ *p;  // prev
    struct Item_ *n;  // next
} Item;  // Element

typedef struct List_ {
    void *p;  // parent or holder, can be anything
    unsigned int c;  // count
    Item *f;  // first
    Item *l;  // last
} List;

void listInit(List *l);
Item *listInsert(List *l, Item *prev, void *data);

#endif
