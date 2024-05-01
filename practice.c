#include <stdio.h>
#include <stdlib.h>
#include "Apr24/dlist.h"

dlist_t * 
dlist_alloc (int unit){
    dlist_t* l = (dlist_t*)malloc(sizeof(dlist_t));
    l->right = l;
    l->left = l;
    l->element = malloc(sizeof(int));
    int* u = (int *)(l->element);
    *u = unit;

    return l;
}


void
dlist_insert (node_t * left, void * e, int unit){
    node_t* new = (node_t*)malloc(sizeof(node_t));
    new->element = malloc(unit);
    memcpy(new->element, e, unit);

    node_t* right = left->right;

    new->left = left;
    new->right = right;

    left->right = new;
    right->left = new;
}

void 
dlist_insert_first (dlist_t* l, void* e){
    dlist_insert(l, e, *((int*)(l->element)));
}

void 
dlist_insert_last (dlist_t* l, void* e){
    dlist_insert(l->left, e, *((int*)(l->element)));
}

