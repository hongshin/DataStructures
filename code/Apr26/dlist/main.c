#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

void print_element (void * e)
{
	int * a ; 

	a = (int *) e ;

	printf("%d ", *a) ;
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

	dlist_remove_last(l, &data) ;

	dlist_apply(l, print_element) ;
	printf("\n") ;

	dlist_free(l) ;

	return EXIT_SUCCESS ;
}
