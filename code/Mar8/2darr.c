#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int a[3][5] ;

	printf("a         : %p\n", a) ;
	printf("a[0]      : %p\n", a[0]) ;
	printf("a[1]      : %p\n", a[1]) ;
	printf("&(a[0])   : %p\n", &(a[0])) ;
	printf("&(a[1])   : %p\n", &(a[1])) ;
	printf("&(a[0][0]): %p\n", &(a[0][0])) ;
	printf("&(a[1][0]): %p\n", &(a[1][0])) ;


	int ** b ;
	b = (int **) calloc(3, sizeof(int *)) ;
	b[0] = (int *) calloc(5, sizeof(int)) ;
	b[1] = (int *) calloc(5, sizeof(int)) ;
	b[2] = (int *) calloc(5, sizeof(int)) ;

	printf("b         : %p\n", b) ;
	printf("b[0]      : %p\n", b[0]) ;
	printf("b[1]      : %p\n", b[1]) ;
	printf("&(b[0])   : %p\n", &(b[0])) ;
	printf("&(b[1])   : %p\n", &(b[1])) ;
	printf("&(b[0][0]): %p\n", &(b[0][0])) ;
	printf("&(b[1][0]): %p\n", &(b[1][0])) ;

	/*
	int * c[3] ;
	c[0] = (int *) calloc(5, sizeof(int)) ;
	c[1] = (int *) calloc(5, sizeof(int)) ;
	c[2] = (int *) calloc(5, sizeof(int)) ;
	printf("c         : %p\n", c) ;
	printf("c[0]      : %p\n", c[0]) ;
	printf("c[1]      : %p\n", c[1]) ;
	printf("&(c[0])   : %p\n", &(c[0])) ;
	printf("&(c[1])   : %p\n", &(c[1])) ;
	printf("&(c[0][0]): %p\n", &(c[0][0])) ;
	printf("&(c[1][0]): %p\n", &(c[1][0])) ;

	int (*d)[5] ;
	d = malloc(15 * sizeof(int)) ;
	printf("d         : %p\n", d) ;
	printf("d[0]      : %p\n", d[0]) ;
	printf("d[1]      : %p\n", d[1]) ;
	printf("&(d[0])   : %p\n", &(d[0])) ;
	printf("&(d[1])   : %p\n", &(d[1])) ;
	printf("&(d[0][0]): %p\n", &(d[0][0])) ;
	printf("&(d[1][0]): %p\n", &(d[1][0])) ;
	*/

	return EXIT_SUCCESS ;
}
