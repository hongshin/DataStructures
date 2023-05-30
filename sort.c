#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge_sort (int * a, int n_a)
{
	if (n_a < 2)
		return ;

	int * a1 ;
	int n_a1 ;
	int * a2 ;
	int n_a2 ;

	a1 = a ;
	n_a1 = n_a / 2 ;

	a2 = a + n_a1 ;
	n_a2 = n_a - n_a1 ;

	merge_sort(a1, n_a1) ;
	merge_sort(a2, n_a2) ;

	int * a_m = (int *) calloc(n_a, sizeof(int)) ;
	int i = 0 ;

	int top_a1 = 0 ; 
	int top_a2 = 0 ; 

	for (i = 0 ; i < n_a ; i++) {
		if (top_a2 >= n_a2) {
			a_m[i] = a1[top_a1] ;
			top_a1++ ;
		}
		else if (top_a1 >= n_a1) {
			a_m[i] = a2[top_a2] ;
			top_a2++ ;
		}
		else if (a1[top_a1] < a2[top_a2]) {
			a_m[i] = a1[top_a1] ;
			top_a1++ ;
		}
		else {
			a_m[i] = a2[top_a2] ;
			top_a2++ ;
		}
	}
	memcpy(a, a_m, n_a * sizeof(int)) ;
}


void quick_sort (int * a, int n_a)
{
	if (n_a < 2)
		return ;

	int pivot_value = a[n_a - 1] ;
	int pivot_index = 0 ;
	int less = n_a - 2 ;

	while (pivot_index < less) {
		while (pivot_index < n_a - 1 && a[pivot_index] < pivot_value)
			pivot_index++ ;

		while (0 <= less && pivot_value < a[less])
			less-- ;

		if (!(less < pivot_index)) {
			int t ;
			t = a[less] ;
			a[less] = a[pivot_index] ;
			a[pivot_index] = t ;
		}
	}

	printf("(debug) pivot value: %d, pivot index: %d\n", pivot_value, pivot_index) ;
		
	if (pivot_index == n_a - 1) {
		quick_sort(a, n_a - 1) ;
	}
	else {
		a[n_a - 1] = a[pivot_index] ;
		a[pivot_index] = pivot_value ;

		quick_sort(a, pivot_index) ;
		quick_sort(a + pivot_index + 1, n_a - pivot_index - 1) ;
	}
}



int main ()
{

	//int a[4] = {4, 3, 2, 1} ;
	//int n_a = 4 ;

	int a[16] = { 25, 14, 8, 72,  224, 82, 8, 2,
	 			  96, 82, 106, 98, 872, 11, 31, 47 } ;
	int n_a = 16 ;

	//merge_sort(a, n_a) ;

	quick_sort(a, n_a) ;

	for (int i = 0 ; i < n_a ; i++) 
		printf("%d ", a[i]) ;
}
