#include <stdio.h>
#include "gentry.h"
#include "list.h"
#include "llist.h"
#include "alist.h"


void gentry_print (void * p)
{
	gentry * e = (gentry *) p ;
	printf("(%s, %d) ", e->name, e->score) ;
}


int main ()
{
	list * l ;

	//l = llist_alloc(sizeof(gentry)) ;
	l = alist_alloc(sizeof(gentry)) ;

	gentry e1 = {"Rob", 750}, e2 = {"Jack", 510}, e3 = {"Mike", 1105}, e4 = {"Paul", 720} ;

	l->add(l, &e1) ;
	l->add(l, &e2) ;
	l->add(l, &e3) ;
	l->add(l, &e4) ;

	l->print(l, gentry_print) ;

	gentry e ; 
	l->remove(l, 2, &e) ;	
	l->print(l, gentry_print) ;

	l->free(l) ;

	return 0 ;
}
