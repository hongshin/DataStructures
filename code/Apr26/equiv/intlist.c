#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intlist.h"

intlist_t * intlist_create () 
{
	intlist_t * l = (intlist_t *) malloc(sizeof(intlist_t)) ;
	l->last = NULL ;
	return l ; 
}

int intlist_len (intlist_t * l)
{
	if (l->last == NULL)
		return 0 ;

	intlist_node_t * i = l->last->next ;
	int n = 0 ;
	do {
		i = i->next ;
		n++ ;
	} while (i != l->last->next) ;
	return n ;
}

int intlist_add (intlist_t * l, int e)
{
	intlist_node_t * n = (intlist_node_t *) malloc(sizeof(intlist_node_t)) ;
	n->element = e ;
	n->next = NULL ;
	
	if (l->last == NULL) {
		l->last = n ;
		n->next = n ;
		return 1 ;
	}

	n->next = l->last->next ;
	l->last->next = n ;
	l->last = n ;

	return 1 ;
}

int intlist_get (intlist_t * l, int index, int * e) 
{
	if (l->last == NULL)
		return 0 ;
	
	int i ;
	intlist_node_t * n ; 
	n = l->last->next ;

	for (i = 0 ; i < index ; i++) {
		n = n->next ;
		if (n == l->last->next)
			return 0 ;
	}

	*e = n->element ;

	return 1 ;
}

void intlist_free (intlist_t * l)
{
	/*TODO*/
}
