#define MAX_SIZE 100

#include <stdio.h>
#include <stdlib.h>

double sum (double list [], int n)
{
	int i ;
	double tempsum = 0.0 ;

	for (i = 0 ; i < n ; i++) {
		tempsum += list[i] ;
		list[i] = 0.0 ;
	}
	return tempsum ;
}

//double input[MAX_SIZE] ;

int main ()
{
	//double input[MAX_SIZE] ;
	double * input ;
	input = (double *) malloc(MAX_SIZE * sizeof(int)) ;

	int i ;
	for (i = 0 ; i < MAX_SIZE; i++) {
		input[i] = (double) i ; 
	}

	double ans = sum(input, MAX_SIZE) ;
	printf("%lf\n", ans) ;
	printf("%ls\n", input[1]) ;

	free(input) ;

	return EXIT_SUCCESS ;
}
