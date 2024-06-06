#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort (int * a, int left, int right, int level)
{
	if (!(left < right))
		return ;

	for (int i = 0 ; i < level ; i++) {
		printf("  ") ;
	}
	printf("sort [%d, %d]\n", left, right) ;

	int p = left ;
	int l = left + 1 ;
	int r = right ;

	while (l < r) {
		while (a[l] <= a[p] && l <= right) {
			l++ ;
		}
		while (a[p] < a[r] && left + 1 <= r) {
			r-- ;
		}
		if (l < r) {
			int tmp = a[l] ;
			a[l] = a[r] ;
			a[r] = tmp ;
			l++ ;
			r-- ;
		}
	}
	int tmp = a[p] ;
	a[p] = a[r] ;
	a[r] = tmp ;

	sort(a, left, r - 1, level + 1) ;
	sort(a, r + 1, right, level + 1) ;
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

	sort(data, 0, n_data - 1, 0) ;

	for (int i = 0 ; i < n_data ; i++) {
		printf("%3d ", data[i]) ;
		if (i % 8 == 7) {
			printf("\n") ;
		}
	}

	return EXIT_SUCCESS ;
}
