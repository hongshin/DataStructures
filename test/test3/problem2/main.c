#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

int main ()
{
	bintree_t * t[9] ;

	t[0] = bintree_create(7) ;
	t[1] = bintree_create(2) ;
	t[2] = bintree_create(5) ;
	t[3] = bintree_create(6) ;
	t[4] = bintree_create(8) ;
	t[5] = bintree_create(1) ;
	t[6] = bintree_create(3) ;

	bintree_add_left(t[0], t[1]) ;
	bintree_add_left(t[1], t[2]) ;
	bintree_add_right(t[1], t[3]) ;
	printf("%d ", bintree_nodes(t[0])) ;
	if (bintree_is_full(t[0]))
		printf("true ") ;
	else
		printf("false ") ;

	bintree_add_right(t[4], t[5]) ;
	bintree_add_left(t[4], t[6]) ;
	bintree_add_right(t[0], t[4]) ;

	int max = 0 ;
	if (bintree_max(t[0], &max)) 
		printf("%d ", max) ;

	if (bintree_is_full(t[0]))
		printf("true ") ;
	else
		printf("false ") ;

	bintree_delete(t[0]) ;

	return EXIT_SUCCESS ;
}































