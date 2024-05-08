#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

char s[256] = "A(B(C(D-E)-F)-G(H)-I(J(K)-L-M))" ;

tree_t *
read_a_tree (char *s)
{
	char * begin, * end, * sub ;
	int n ;
	int data ;	

	data = s[0] ;
	node_t * t = tree_create(data) ;

	begin = s + 1 ;

	if (*begin == ')' || *begin == '-' || *begin == '\0') 
		return t ;
	// *begin == '('
	sub = begin + 1 ;
	for (end = begin + 1, n = 0 ; n > 0 || *end != ')' ; end++) {
		if (*end == '(') {
			n++ ;
		}
		if (*end == ')') {
			n-- ;
		}
		if (n == 0 && *end == '-') {
			tree_add_child(t, read_a_tree(sub)) ;
			sub = end + 1 ;
		}
	}
	tree_add_child(t, read_a_tree(sub)) ;

	return t ;
}

int
main ()
{
	//char newline ;
	//scanf("%255[^\n]", s, &newline) ;

	tree_t * t ;
	t = read_a_tree(s) ;

	tree_print(t) ;
	printf("\n") ;
	printf("height: %d\n", tree_height(t)) ;

	tree_print(tree_search(t, 'C')) ;
	printf("\n") ;

	return 0 ;
}
