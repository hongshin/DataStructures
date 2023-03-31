#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "llist.h"
#include "stack.h"

stack * stack_alloc (size_t elem_size)
{
    stack * s ;
    s = (stack *) malloc(sizeof(stack)) ;
    s->list = llist_alloc(elem_size) ;
    return s ;
}

void stack_free (stack * s)
{
    llist_free(s->list) ;
    free(s) ;
}

int stack_push (stack * s, void * elem)
{
    return s->list->add(s->list, elem) ;
}

int stack_pop (stack * s, void * dest) 
{
    return s->list->remove(s->list, 0, dest) ;
}

int stack_top (stack * s, void * dest) 
{
    return s->list->get(s->list, 0, dest) ;
}

int stack_empty (stack * s)
{
    return (s->list->size(s->list) == 0) ;
}

int stack_size (stack * s)
{
    return s->list->size(s->list) ;
}
