#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mergesort.h"

/*TODO: you can add new functions */

int intcmp (void *e1, void *e2)
{
	int v1, v2 ;

	v1 = *((int *) e1) ;
	v2 = *((int *) e2) ;

	return (v1 - v2) ;
}


int binary_search (int * a, int len, int v)
{
	/*TODO*/
}


int main ()
{
	int data [] = {
		26,  8, 81, 95,  7,  37,  63,  83,
		97, 98, 43, 76, 14,  81,  47,   5,
		 3,  8, 56, 59, 60, 100,  74,  91,
		97,  3, 98, 80, 82,  72,  84, 100,
		62, 35, 18, 54,  0,   8,   7,  15,
		57, 28,  2, 20, 46,  17,  75,  28,
		85, 55, 67,  9, 23,  38,  62,  59,
		90, 43, 98, 92, 81,  26,  21,  75
	} ;
	
	int n_data = sizeof(data) / sizeof(int) ;

	generic_merge_sort(data, n_data, sizeof(int), intcmp) ;

	printf("binary_search for 46: %d\n", binary_search(data, n_data, 46)) ;
	printf("binary_search for 66: %d\n", binary_search(data, n_data, 66)) ;

	return EXIT_SUCCESS ;
}
