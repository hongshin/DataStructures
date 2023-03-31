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
	ll->head = 0x0 ;
    ll->length = 0 ;

    l->get = llist_get ;
	l->free = llist_free ;
	l->add = llist_add ;
	l->remove = llist_remove ;
    l->size = llist_size ;
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

int llist_remove (list * l, int index, void * s) 
{
	llist * ll = (llist *) l->d ;

	if (ll->head == 0x0)
		return 0 ;
	
	llist_node * n = ll->head ;
	llist_node * prec = 0x0 ;
	int i = 0 ;
    while (n != 0x0 && i < index) {
        prec = n ;
        n = n->next ;
        i++ ;
    }
	if (n == 0x0)
		return 0 ;

	memcpy(s, n->elem, l->elem_size) ;

	if (prec != 0x0) 
		prec->next = n->next ;
	else 
		ll->head = n->next ;

	free(n->elem) ;
	free(n) ;
	ll->length-- ;
	return 1 ;
}

int llist_get (list * l, int index, void * s)
{
    llist * ll = (llist *) l->d ;

    llist_node * n = ll->head ;
    int i = 0 ;
    while (n != 0x0 && i < index) {
        i++ ;
        n = n->next ;
    }
    if (n == 0x0 || i != index)
        return 0;
    
    memcpy(s, n->elem, l->elem_size) ;
    return 1 ;
}

int llist_size (list * l) 
{
    llist * ll = (llist *) l->d ;
    return ll->length ;
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
