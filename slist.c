#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "slist.h"

slist * slist_alloc (size_t elem_size, int (* compare)(void * e1, void * e2)) 
{
	//TODO
}

void slist_free (slist * l)
{
	//TODO
}

int slist_length (slist * l)
{
	//TODO
}

int slist_search (slist * l, int (* elem_cond)(void * e))
{
	//TODO
}

int slist_add (slist * l, void * e)
{
	//TODO
}

int slist_remove (slist * l, int i, void * e)
{
	//TODO
}

void slist_print (slist * l, void (* elem_print)(void * e))
{
	//TODO
}

slist * slist_merge(slist * l1, slist * l2)
{
	//TODO
}

