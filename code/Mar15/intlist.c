#include <stdio.h>
#include <stdlib.h>

typedef 
	struct {
		int * items ; 
		// points to an array of n_items number of integers; has NULL if n_items is zero.
		int n_items ; 
		// zero or positive integer.
	} 
	intlist_t ;

intlist_t * 
intlist_create () 
{
	intlist_t * l ;
	l = (intlist_t *) malloc(sizeof(intlist_t)) ;
	l->items = NULL ;
	l->n_items = 0 ;

	return l ;
}

int 
intlist_size (intlist_t * l) 
{
	return l->n_items ;
}

int 
intlist_get (intlist_t * l, int i, int * r) 
{
	if (i < 0) {
		return 0 ;
	}
	if (l->n_items <= i) {
		return 0 ;
	}
	
	// assert that 0 <= i < l->n_items 
	*r = l->items[i] ;
	return 1 ;
}

int 
intlist_insert (intlist_t * l, int i, int v) 
{
	return 0 ;
}


int main ()
{
	intlist_t * l ;
	l = intlist_create() ;

	printf("1==%d\n", intlist_insert(l, 0, 1)) ;
	printf("1==%d\n", intlist_insert(l, 1, 2)) ;
	printf("1==%d\n", intlist_insert(l, 2, 3)) ;
	printf("0==%d\n", intlist_insert(l, 4, 4)) ;

	int i, n ;
	n = intlist_size(l) ;
	for (i = 0 ; i < n ; i++) {
		int ret ;
		int val ;
		ret = intlist_get(l, i, &val) ;
		printf("%d %d\n", ret, val) ;
	}

	return EXIT_SUCCESS ;
}
