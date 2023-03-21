#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "glist.h"

glist * glist_alloc (size_t s) 
{
	glist * l = (glist *) malloc(sizeof(glist)) ;
	l->head = 0x0 ;
	l->size = s ;
	return l ;
}

void glist_free (glist * l) 
{
	while (l->head != 0x0) {
		glist_remove_first(l, 0x0) ;
	}
}

int glist_search (glist * l, int (* elem_cond)(void *)) 
{
	// TODO
}

int glist_add_first (glist * l, void * s) 
{
	glist_node * n = (glist_node *) malloc(sizeof(glist_node)) ;
	n->elem = malloc(l->size) ;
	memcpy(n->elem, s, l->size) ;
	n->next = l->head ;	
	l->head = n ;
}

int glist_add_last (glist * l, void * s)
{
	// TODO
}

int glist_remove (glist * l, int i, void * s)
{
	// TODO
}


int glist_remove_first (glist * l, void * s) 
{
	if (l->head == 0x0)
		return 0 ;
	
	glist_node * n = l->head ;
	l->head = n->next ;
	if (s != 0x0) {
		memcpy(s, n->elem, l->size) ;
	}
	free(n->elem) ;
	free(n) ;
	return 1 ;
}

void glist_print (glist * l, void (* elem_print)(void *)) 
{
	glist_node * i ;
	for (i = l->head ; i != 0x0 ; i = i->next) {
		elem_print(i->elem) ;
		printf(" ") ;
	}
	printf("\n") ;
}
