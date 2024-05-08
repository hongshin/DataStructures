#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main ()
{
	tree_t * t ;

	t = tree_create('A') ;
	tree_add_child(t, tree_create('B')) ;
	tree_add_child(t, tree_create('C')) ;
	tree_add_child(t, tree_create('D')) ;
	tree_add_child(tree_search(t, 'B'), tree_create('E')) ;
	tree_add_child(tree_search(t, 'B'), tree_create('F')) ;
	tree_add_child(tree_search(t, 'E'), tree_create('K')) ;
	tree_add_child(tree_search(t, 'E'), tree_create('L')) ;
	tree_add_child(tree_search(t, 'C'), tree_create('G')) ;

	tree_add_child(tree_search(t, 'D'), tree_create('H')) ;
	tree_add_child(tree_search(t, 'D'), tree_create('I')) ;
	tree_add_child(tree_search(t, 'D'), tree_create('J')) ;
	tree_add_child(tree_search(t, 'H'), tree_create('M')) ;

	tree_print(t) ;
	printf("\n") ;

	printf("height: %d\n", tree_height(t)) ;
	tree_delete(t) ;

	return 0 ;
}
