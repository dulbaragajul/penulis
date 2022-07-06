#ifndef _penulis_list_h_
#define _penulis_list_h_

#include <lib.h>

struct List_;

typedef struct Item_ {
    void *d;  // data
    struct List_ *l;
    struct Item_ *p;  // prev
    struct Item_ *n;  // next
} Item;  // Element of List

typedef struct List_ {
    void *p;  // parent or holder, can be anything
    unsigned int s;  // size
    Item *f;  // first
    Item *l;  // last
} List;

void listInit(List *l);
Item *listInsert(List *l, Item *prev, void *data);

#endif
