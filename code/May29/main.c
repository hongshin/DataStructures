#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"

typedef struct {
	int key ;
	char data[64] ;
} entry ;

int
_cmp (void * p1, void * p2)
{
	entry * e1, * e2 ;

	e1 = (entry *) p1 ;
	e2 = (entry *) p2 ;
	return e1->key - e2->key ;
}

void
_print (void * p)
{
	entry * e = (entry *) p ;
	printf("[%d,%s]", e->key, e->data) ;
}

int
main ()
{
	int i ;

	entry d[10] = {{5, "Hello"}, {2, "Problem"}, {8, "Book"}, {9, "University"}, {4, "Reason"},
		{1, "Intelligence"}, {7, "Brain"}, {6, "Beginning"}, {3, "List"}, {10, "Market"}} ;

	bst_t * t = bst_create(sizeof(entry), _cmp) ;

	for (i = 0 ; i < 10 ; i++) {
		bst_insert(t, &(d[i])) ;
	}	
	bst_print(t, _print) ;

	entry query ;
	query.key = 9 ;

	if (bst_search(t, &query)) {
		printf("%s\n", query.data) ;
	}
	else {
		printf("no such element exists.\n") ;
	}

	
	for (i = 0 ; i < 11 ; i++) {
		bst_remove(t, &i) ;
		bst_print(t, _print) ;
	}
	
	bst_free(t) ;

	return EXIT_SUCCESS ;
}
