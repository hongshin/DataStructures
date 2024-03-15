#include <stdio.h>
#include <stdlib.h>

struct term_t {
	int exp ;
	double coef ;
} ;

struct poly_t {
	int degree ;
	term_t * terms ;
} ;

poly_t * poly_zero () 
{
}

int poly_degree (poly_t * p)
{
}

double poly_coef (poly_t * p)
{
}

poly_t poly_attach (poly_t * p)
{
}

poly_t poly_remove (poly_t * p)
{
}

void poly_show (poly_t * p)
{
}

int main ()
{
	return EXIT_SUCCESS ;
}
