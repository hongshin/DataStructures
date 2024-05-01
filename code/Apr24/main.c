#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

void test1 () 
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
	printf("%d\n", data) ;

	dlist_get(l, 2, &data) ;
	printf("%d\n", data) ;

	while (dlist_length(l) > 0) {
		dlist_remove_first(l, &data) ;
		printf("%d ", data) ;
	}
	printf("\n") ;

	dlist_free(l) ;
}

void test2 ()
{
	int data ;

	dlist_t * l1 = dlist_alloc(sizeof(int)) ;
	dlist_t * l2 = dlist_alloc(sizeof(int)) ;

	data = 1 ;
	dlist_insert_last(l1, &data) ;

	data = 2 ;
	dlist_insert_first(l1, &data) ;

	data =3 ;
	dlist_insert_last(l1, &data) ;

	data = 4 ;
	dlist_insert_last(l2, &data) ;

	data = 5 ;
	dlist_insert_first(l2, &data) ;

	dlist_append(l1, l2) ;

	int n = dlist_length(l1) ;
	for (int i = 0 ; i < n ; i++) {
		int data ;
		dlist_get(l1, i, &data) ;
		printf("%d ", data) ;
	}
	printf("\n") ;

	dlist_free(l1) ;
	dlist_free(l2) ;
}


int main ()
{
	test1() ;
	test2() ;

	return EXIT_SUCCESS ;
}
