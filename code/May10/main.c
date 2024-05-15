#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

int main ()
{
	bintree_t * t[9] ;

	t[0] = bintree_create('A') ;
	t[1] = bintree_create('B') ;
	t[2] = bintree_create('C') ;
	t[3] = bintree_create('D') ;
	t[4] = bintree_create('E') ;
	t[5] = bintree_create('F') ;
	t[6] = bintree_create('G') ;
	t[7] = bintree_create('H') ;
	t[8] = bintree_create('I') ;

	bintree_add_left(t[0], t[1]) ;
	bintree_add_left(t[1], t[2]) ;
	bintree_add_right(t[1], t[3]) ;
	bintree_add_left(t[2], t[4]) ;
	bintree_add_right(t[2], t[5]) ;
	bintree_add_right(t[3], t[6]) ;
	bintree_add_right(t[5], t[7]) ;
	bintree_add_left(t[7], t[8]) ;

	bintree_print(t[0]) ;
	printf("\n") ;

	printf("height: %d\n", bintree_height(t[0])) ;

	bintree_delete(t[0]) ;

	return 0 ;
}































