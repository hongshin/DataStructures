#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lalist.h"

lalist_t * 
lalist_alloc (int arr_cap, int elem_size) 
{
	lalist_t * l = malloc(sizeof(lalist_t)) ;
	l->arr_cap = arr_cap ;
	l->elem_size = elem_size ;
	l->first = malloc(sizeof(lalist_node_t)) ;
	l->first->arr = calloc(elem_size, arr_cap) ;
	l->first->n_elem = 0 ;
	l->first->next = NULL ;

	return l ;
}

void
lalist_free (lalist_t * l)
{
	/* TODO */
}

int 
lalist_length (lalist_t * l)
{
	int n = 0 ;
	lalist_node_t * i ;
	for (i = l->first ; i != NULL ; i = i->next) {
		n += i->n_elem ;
	}
	return n ;
}

void
lalist_insert_first (lalist_t * l, void * e)
{
	/* TODO */
}

void
lalist_insert_last (lalist_t * l, void * e)
{
	/* TODO */
}

int
lalist_insert_at (lalist_t * l, int index, void * e)
{
	/* TODO */
}

int 
lalist_remove_first (lalist_t * l, void * e)
{
	/* TODO */
}

int
lalist_remove_last (lalist_t * l, void * e)
{
	/* TODO */
}

int
lalist_remove_at (lalist_t * l, int index, void * e)
{
	/* TODO */
}


void
lalist_apply (lalist_t * l, void (* func)(void * e)) 
{
	/* TODO */
}

void 
lalist_info (lalist_t * l)
{
	lalist_node_t * i ;
	int j = 0 ;
	printf("========\n") ;
	for (i = l->first, j = 0 ; i != NULL ; i = i->next, j++) {
		printf(" - node %d : %d elements\n", j, i->n_elem) ;
	}
	printf("========\n") ;
}

void
lalist_pack (lalist_t * l)
{
	/* TODO */
}
