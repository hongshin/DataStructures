#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int * merge (int * a, int n_a, int * b, int n_b)
{
		int i ;
		printf("merge: ") ;
		for (i = 0 ; i < n_a ; i++) {
			printf("%d ", a[i]) ;
		}
		printf("; ") ;
		for (i = 0 ; i < n_b ; i++) {
			printf("%d ", b[i]) ;
		}
		printf("\n") ;

		int * c = malloc((n_a + n_b) * sizeof(int)) ;

		int n_c = n_a + n_b ;
		
		int top_a = 0 ;
		int top_b = 0 ;

		for (i = 0 ; i < n_c ; i++) {
			if (top_b == n_b || (top_a < n_a && a[top_a] < b[top_b])) {
				c[i] = a[top_a] ;
				top_a++ ;
			}
			else /* b[top_b] < a[top_a] */ {
				c[i] = b[top_b] ;
				top_b++ ;
			}
		}


		return c ;
}

void sort (int * a, int n_a)
{
	// split a into two sublists
	// sort each sublist recursively
	// merge the resulting sorted sublists
	int i ;

	printf("sort: ") ;
	for (i = 0 ; i < n_a ; i++) {
		printf("%d ", a[i]) ;
	}
	printf("\n") ;


	if (n_a == 0 || n_a == 1)
		return ;

	int * a1 ;
	int n_a1 ;
	int * a2 ;
	int n_a2 ;

	a1 = a ;
	n_a1 = n_a / 2 ;
	
	a2 = a + n_a1 ;
	n_a2 = n_a - n_a1 ;

	sort(a1, n_a1) ;
	sort(a2, n_a2) ;

	int * a_sorted ;
	a_sorted = merge(a1, n_a1, a2, n_a2) ;

	printf("sorted : ") ;
	for (i = 0 ; i < n_a ; i++) {
		printf("%d ", a_sorted[i]) ;
	}
	printf("\n") ;

	memcpy(a, a_sorted, n_a * sizeof(int)) ;
	free(a_sorted) ;
}


int main ()
{
	int data [] = {
		26,  8, 81, 95,  7,  37,  63,  83,
		97, 98, 43, 76, 14,  81,  47,   5 
	} ;
	/*
		,
		 3,  8, 56, 59, 60, 100,  74,  91,
		97,  3, 98, 80, 82,  72,  84, 100,
		62, 35, 18, 54,  0,   8,   7,  15,
		57, 28,  2, 20, 46,  17,  75,  28,
		85, 55, 67,  9, 23,  38,  62,  59,
		90, 43, 98, 92, 81,  26,  21,  75
	} ;
	*/
	
	int n_data = sizeof(data) / sizeof(int) ;

	sort(data, n_data) ;

	for (int i = 0 ; i < n_data ; i++) {
		printf("%3d ", data[i]) ;
		if (i % 8 == 7) {
			printf("\n") ;
		}
	}

	return EXIT_SUCCESS ;
}
