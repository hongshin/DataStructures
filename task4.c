#include <stdio.h>
#include <stdlib.h>

void print_result (int * a, int a_length, int k) 
{
	int last_l = a_length ;
	int first_ge = 0 ;
	int i ;

	for (i = a_length - 1 ; i >= 0 ; i--) {
		if (a[i] < k) {
			last_l = i ;
			break ;
		}
	}
	for (i = 0 ; i < a_length ; i++) {
		if (a[i] >= k) {
			first_ge = i ;
			break ;
		}
	}
	if (first_ge < last_l) {
		printf("Wrong answer\n") ;
		exit(1) ;
	}

	for (int i = 0 ; i < a_length ; i++)
		printf("%d ", a[i]) ;
	printf("\n") ;
}

int main ()
{
	int a [] = {13,	92,	90,	94,	48,	21,	76,	51,	56,	79,	
				51,	77,	97,	14,	80,	15,	10, 20, 70, 32} ;

	int a_length = 20 ;

	int k = 40 ;

	//TODO

	print_result(a, a_length, k) ;
	return 0 ;
}
