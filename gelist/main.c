#include <stdio.h>
#include "gelist.h"

int main ()
{
	gelist * l ;

	l = gelist_alloc(5) ;


	gentry e1 = {"Rob", 750}, e2 = {"Jack", 510}, e3 = {"Mike", 1105}, e4 = {"Paul", 720} ;

	gelist_add(l, e1) ;
	gelist_add(l, e2) ;
	gelist_add(l, e3) ;
	gelist_add(l, e4) ;

	gelist_print(l) ;

	gelist_free(l) ;

	return 0 ;
}
