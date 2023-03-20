#include <stdio.h>
#include "gentry.h"
#include "glist.h"


void gentry_print (void * p)
{
	gentry * e = (gentry *) p ;
	printf("(%s, %d) ", e->name, e->score) ;
}


int main ()
{
	glist * l ;

	l = glist_alloc(sizeof(gentry)) ;


	gentry e1 = {"Rob", 750}, e2 = {"Jack", 510}, e3 = {"Mike", 1105}, e4 = {"Paul", 720} ;

	glist_add_first(l, &e1) ;
	glist_add_first(l, &e2) ;
	glist_add_first(l, &e3) ;
	glist_add_first(l, &e4) ;

	glist_print(l, gentry_print) ;

	gentry e ; 
	glist_remove_first(l, &e) ;
	glist_print(l, gentry_print) ;

	glist_free(l) ;

	return 0 ;
}
