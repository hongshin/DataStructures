#include <stdio.h>
#include <stdlib.h>

#include "lalist.h"

void print_element (void * e)
{
	int * a ; 

	a = (int *) e ;

	printf("%d ", *a) ;
}

int main () 
{
	int data ;
	lalist_t * l ; 

	l = lalist_alloc(3, sizeof(int)) ;

	data = 1 ;
	lalist_insert_last(l, &data) ;

	data = 2 ;
	lalist_insert_last(l, &data) ; 

	data = 3 ;
	lalist_insert_last(l, &data) ; 

	data = 4 ;
	lalist_insert_first(l, &data) ; 

	data = 5 ;
	lalist_insert_last(l, &data) ; 

	data = 6 ;
	lalist_insert_at (l, 2, &data) ; 

	data = 7 ;
	lalist_insert_at(l, 3, &data) ; 

	data = 8 ;
	lalist_insert_last(l, &data) ; 

	lalist_apply(l, print_element) ; 
	printf("\n") ;

	lalist_info(l) ; 

	lalist_remove_first(l, &data) ; 
 
	lalist_remove_last(l, &data) ; 
 
	lalist_remove_last(l, &data) ; 
 

	lalist_apply(l, print_element) ; 
	printf("\n") ;
	lalist_info(l) ;

	data = 9 ;
	lalist_insert_at(l, 1, &data) ; 

	lalist_pack(l) ;
	lalist_apply(l, print_element) ; 
	printf("\n") ;
	lalist_info(l) ;

	lalist_free(l) ;

	return EXIT_SUCCESS ;
}
