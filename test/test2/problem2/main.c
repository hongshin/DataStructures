#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

void print_element (void * e)
{
	int * a ; 

	a = (int *) e ;

	printf("%d ", *a) ;
}

void double_element (void * e)
{
	/* TODO */
	int * a;
	a = (int *) e;
	*a += *a;
}


int main () 
{
	int data ;
	dlist_t * l ; 

	l = dlist_alloc(sizeof(int)) ;

	data = 1 ;
	dlist_insert_last(l, &data) ;

	data = 2 ;
	dlist_insert_last(l, &data) ;

	data = 3 ;
	dlist_insert_first(l, &data) ;

	data = 4 ;
	dlist_insert_first(l, &data) ; 

	data = 5 ;
	dlist_insert_at (l, 1, &data) ; 

	dlist_remove_at (l, 2, &data) ; 

	dlist_apply(l, double_element) ;

	dlist_apply(l, print_element) ; 
	printf("\n") ;

	dlist_free(l) ;

	return EXIT_SUCCESS ;
}
