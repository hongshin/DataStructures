#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"

int
_cmp (void * p1, void * p2)
{
	double * d1, * d2 ;

	d1 = (double *) p1 ;
	d2 = (double *) p2 ;

	if (*d1 < *d2)
		return -1 ;
	if (*d1 > *d2)
		return 1 ;

	return 0 ;
}


int
main ()
{
	double d[10] = { 5.9, 10.5, 7.3, 2.9, 10.2, 3.1, 15.3, 1.1, 5.8, 20.6 } ;

	bst_t * t = bst_create(sizeof(double), _cmp) ;

	int i ;
	for (i = 0 ; i < 10 ; i++) {
		bst_insert(t, &(d[i])) ;
	}

	double a[10] ;

	bst_to_array(t, (void *) a, sizeof(double) * 10) ;
	for (i = 0 ; i < 10 ; i++) {
		printf("%.1lf  ", a[i]) ;
	}
	printf("\n") ;
	
	bst_free(t) ;

	return EXIT_SUCCESS ;
}
