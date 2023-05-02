#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main ()
{
	tree_node * a = tree_alloc("A") ;
	tree_node * b = tree_alloc("B") ;
	tree_node * c = tree_alloc("C") ;
	tree_node * d = tree_alloc("D") ;
	tree_node * e = tree_alloc("E") ;
	tree_node * f = tree_alloc("F") ;
	tree_node * g = tree_alloc("G") ;
	tree_node * h = tree_alloc("H") ;
	tree_node * i = tree_alloc("I") ;
	tree_node * j = tree_alloc("J") ;
	tree_node * k = tree_alloc("K") ;
	tree_node * l = tree_alloc("L") ;
	tree_node * m = tree_alloc("M") ;


	tree_child_add(e, k) ;
	tree_child_add(e, l) ;
	tree_child_add(b, e) ;
	tree_child_add(b, f) ;
	tree_child_add(a, b) ;

	tree_child_add(c, g) ;
	tree_child_add(a, c) ;

	tree_child_add(h, m) ;
	tree_child_add(d, h) ;
	tree_child_add(d, i) ;
	tree_child_add(d, j) ;
	tree_child_add(a, d) ;
	
	tree_print(a) ; printf("\n") ;

	tree_free(a) ;
}
