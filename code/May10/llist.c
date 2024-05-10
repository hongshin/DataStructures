#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "llist.h"

llist_t * llist_create () 
{
	llist_t * l = (llist_t *) malloc(sizeof(llist_t)) ;
	l->first = NULL ;
	return l ; 
}

int llist_insert (llist_t * l, char c)
{
	llist_node_t * n = (llist_node_t *) malloc(sizeof(llist_node_t)) ;
	n->data = c ;
	n->next = NULL ;
	
	if (l->first == NULL) {
		l->first = n ;
		return 1 ;
	}
	
	llist_node_t * last = l->first ;
	while (!(last->next == NULL)) {
		last = last->next ;
	}
	last->next = n ;

	return 1 ;
}

int llist_remove_first (llist_t * l, char * p) 
{
	if (llist->first == NULL)
		return 0 ;

	*p = llist->first->data ;

	llist_node_t * n = llist->first ;
	llist->first = llist->first->next ;
	free(n) ;

	return 1 ;
}

void llist_free (llist_t * l)
{
	llist_node_t * i ;
	for (i = l->first ; i != NULL ; ) {
		llist_node_t * current = i ;
		i = i->next ;
		free(current) ;
	}
	free(l) ;
}
