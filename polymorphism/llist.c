#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "llist.h"

list * llist_alloc (size_t s) 
{
	list * l = (list *) malloc(sizeof(list)) ;

	l->elem_size = s ;

	l->d = malloc(sizeof(llist)) ;
	llist * ll = (llist *) l->d ;
	ll = (llist *) malloc(sizeof(llist)) ;
	ll->head = 0x0 ;

	l->free = llist_free ;
	l->add = llist_add ;
	l->remove = llist_remove ;
	l->print = llist_print ;
	
	return l ;
}

void llist_free (list * l) 
{
	llist * ll = (llist *) l->d ; 

	while (ll->head != 0x0) {
		llist_remove(l, 0, 0x0) ;
	}

	free(ll) ;
	free(l) ;
}

int llist_add (list * l, void * s) 
{
	llist * ll = (llist *) l->d ;


	llist_node * n = (llist_node *) malloc(sizeof(llist_node)) ;
	n->elem = malloc(l->elem_size) ;
	memcpy(n->elem, s, l->elem_size) ;
	n->next = ll->head ;	
	ll->head = n ;
	ll->length++ ;
	return 1 ;
}

int llist_remove (list * l, int i, void * s) 
{
	llist * ll = (llist *) l->d ;

	if (ll->head == 0x0)
		return 0 ;
	
	llist_node * n = ll->head ;
	llist_node * prec = 0x0 ;
	int j = 0 ;

	for (j = 0 ; j < i ; j++) {
		if (n == 0x0)
			return 0 ;

		prec = n ;
		n = n->next ;
	}
	if (n == 0x0)
		return 0 ;

	if (s != 0x0) {
		memcpy(s, n->elem, l->elem_size) ;
	}

	if (prec != 0x0) {
		prec->next = n->next ;
	}
	else {
		ll->head = n->next ;
	}

	free(n->elem) ;
	free(n) ;
	ll->length-- ;

	return 1 ;
}

void llist_print (list * l, void (* elem_print)(void *)) 
{
	llist * ll = (llist *) l->d ; 	
	llist_node * i ;
	for (i = ll->head ; i != 0x0 ; i = i->next) {
		elem_print(i->elem) ;
		printf(" ") ;
	}
	printf("\n") ;
}
