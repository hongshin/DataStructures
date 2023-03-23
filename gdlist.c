#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gdlist.h"

gdlist * gdlist_alloc (size_t elem_size, int (* compare)(void * e1, void * e2)) 
{
}

void gdlist_free (gdlist * l)
{
}

int gdlist_length (gdlist * l)
{
}

int gdlist_search (gdlist * l, int (* elem_cond)(void * e))
{
}

int gdlist_add (gdlist * l, void * e)
{
}

int gdlist_remove (gdlist * l, int i, void * e)
{
}

void gdlist_print (gdlist * l, void (* elem_print)(void * e))
{
}

gdlist * gdlist_merge(gdlist * l1, gdlist * l2)
{
}

