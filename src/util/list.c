#include "main.h"

void listInit(List *l){
    l->s = 0;
    l->f = NULL;
    l->l = NULL;
}
Item *listInsert(List *l, Item *prev, void *data){
    Item *item = NEW(Item);
    item->d = data;
    item->l = l;
    if(l->s){
        Item *n;
        if(prev){
            n = prev->n;
            prev->n = item;
            item->p = prev;
            if(n) n->p = item;
            else l->l = item;
            item->n = n;
        }else{
            n = l->f;
            l->f = item;
            item->p = NULL;
            item->n = n;
            n->p = item;
        }
    }else{
        item->p = NULL;
        item->n = NULL;
        l->f = item;
        l->l = item;
    }

    l->s++;

    return item;
}
