#include <stdio.h>
#include <stdlib.h>

typedef 
	struct {
		int exp ;
		double coef ;
	} 
	term_t ;

typedef 
	struct {
		int degree ;
		int n_terms ;
		term_t * terms ; // a list of attached terms 
	} 
	poly_t ;

poly_t * poly_zero () 
{
	poly_t * p = (poly_t *) malloc(sizeof(poly_t)) ;
	
	p->degree = 0 ;
	p->n_terms = 0 ;
	p->terms = NULL ;
	return p ; 
}

int poly_degree (poly_t * p)
{
	return p->degree ;
}

double poly_coef (poly_t * p, int exp)
{
	if (exp < 0)
		return 0.0 ;
	if (p->degree < exp)
		return 0.0 ;

	int i ;
	for (i = 0 ; i < p->n_terms ; i++) {
		if ((p->terms[i]).exp == exp) {
			return (p->terms[i]).coef ;
		}
	}
	return 0.0 ;
}	

poly_t * poly_attach (poly_t * p, double coef, int exp)
{
	if (exp < 0)
		return NULL ;
	if (coef == 0.0)
		return NULL ;
	if (poly_coef(p, exp) != 0.0)
		return NULL ;

	if (p->degree < exp) {
		p->degree = exp ;
	}
	p->terms = realloc(p->terms, sizeof(term_t) * (p->n_terms + 1)) ; 
	(p->terms[p->n_terms]).coef = coef ;
	(p->terms[p->n_terms]).exp = exp ;
	p->n_terms += 1 ;

	return p ;
}

poly_t * poly_remove (poly_t * p, int exp)
{
	if (exp < 0)
		return NULL ;
	if (p->degree < exp)
		return NULL ;
	if (poly_coef(p, exp) == 0.0)
		return NULL ;

	int i = 0 ;
	while (p->terms[i].exp != exp) {
		i++ ;
	}
	// assert p->terms[i].exp == exp

	for ( ; i < p->n_terms - 1 ; i++) {
		p->terms[i] = p->terms[i + 1] ;
	}
	p->terms = realloc(p->terms, (p->n_terms - 1) * sizeof(term_t)) ;
	p->n_terms -= 1 ;

	int j ;
	p->degree = 0 ;
	for (j = 0 ; j < p->n_terms ; j++) {
		if (p->degree < p->terms[j].exp) {
			p->degree = p->terms[j].exp ;
		}
	}

	return p ;
}


void poly_delete (poly_t * p)
{
	if (p->terms != NULL) {
		free(p->terms) ;
	}
	free(p) ;
}

poly_t * poly_scale (poly_t * p, double s)
{
	/* TODO */
}

poly_t * poly_add (poly_t * p1, poly_t * p2)
{
	/* TODO */
}

poly_t * poly_sub (poly_t * p1, poly_t * p2)
{
	/* TODO */
}

poly_t * poly_mult (poly_t * p1, poly_t * p2)
{
	/* TODO */
}


double poly_eval (poly_t * p, double x)
{
	/* TODO */
}



void poly_show (poly_t * p)
{
	int i ;
	for (i = 0 ; i < p->n_terms ; i++) {
		printf("%lf", p->terms[i].coef) ;
		if (p->terms[i].exp != 0) {
			printf("x^%d", p->terms[i].exp) ;
		}
		if (i != p->n_terms - 1) {
			if (p->terms[i + 1].coef >= 0.0) {
				printf("+") ;
			}
		}
	}
	printf("\n") ;
}

int main ()
{
	//1.0x^2 + 2.0x+ 1.0 
	poly_t * p = poly_zero() ;
	printf("%d\n", p == poly_attach(p, 1.0, 2)) ;
	printf("%d\n", p == poly_attach(p, -2.0, 1)) ;
	printf("%d\n", p == poly_attach(p, -1.0, 0)) ;
	printf("%d\n", p == poly_attach(p, 2.0, 2)) ;
	poly_show(p) ;

	printf("%d\n", p == poly_remove(p, 1)) ;
	poly_show(p) ;

	poly_delete(p) ;

	/* TODO */

	return EXIT_SUCCESS ;
}
