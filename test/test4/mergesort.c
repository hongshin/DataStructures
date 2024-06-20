#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mergesort.h"

void * merge_lists (void * a, int n_a, void * b, int n_b, int unit, int (* cmp)(void *e1, void * e2))
{
	void * m = malloc((n_a + n_b) * unit) ; // m is the array to hold the merge result.

	/*TODO*/

	return m ; // m will be freed at generic_merge_sort
}


void generic_merge_sort (void * a, int n_a, int unit, int (* cmp)(void * e1, void * e2)) 
{
	if (n_a == 0 || n_a == 1)
		return ;

	void * a1 ;
	int n_a1 ;

	void * a2 ;
	int n_a2 ;

	a1 = a ;
	n_a1 = n_a / 2 ;
	
	a2 = a + unit * n_a1 ;
	n_a2 = n_a - n_a1 ;

	generic_merge_sort(a1, n_a1, unit, cmp) ;
	generic_merge_sort(a2, n_a2, unit, cmp) ;

	void * a_sorted = merge_lists (a1, n_a1, a2, n_a2, unit, cmp) ;

	memcpy(a, a_sorted, n_a * unit) ;
	free(a_sorted) ;
}
