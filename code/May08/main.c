#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main ()
{
	tree_t * t[13] ;

	t[0] = tree_create('A') ;
	t[1] = tree_create('B') ;
	t[2] = tree_create('C') ;
	t[3] = tree_create('D') ;
	t[4] = tree_create('E') ;
	t[5] = tree_create('F') ;
	t[6] = tree_create('G') ;
	t[7] = tree_create('H') ;
	t[8] = tree_create('I') ;
	t[9] = tree_create('J') ;
	t[10] = tree_create('K') ;
	t[11] = tree_create('L') ;
	t[12] = tree_create('M') ;

	tree_add_child(t[0], t[1]) ;
	tree_add_child(t[0], t[2]) ;
	tree_add_child(t[0], t[3]) ;
	tree_add_child(t[1], t[4]) ;
	tree_add_child(t[1], t[5]) ;
	tree_add_child(t[4], t[10]) ;
	tree_add_child(t[4], t[11]) ;
	tree_add_child(t[2], t[6]) ;
	tree_add_child(t[3], t[7]) ;
	tree_add_child(t[3], t[8]) ;
	tree_add_child(t[3], t[9]) ;
	tree_add_child(t[7], t[12]) ;


	tree_print(t[0]) ;
	printf("\n") ;

	printf("height: %d\n", tree_height(t[0])) ;
	printf("degree: %d\n", tree_degree(t[0])) ;
	tree_delete(t[0]) ;

	return 0 ;
}
