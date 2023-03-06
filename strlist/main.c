#include <stdio.h>
#include "strlist.h"

int main ()
{
	strlist * l ;

	l = strlist_alloc() ;

	char *s1 = "Rob", *s2 = "Jack", *s3="Mike", *s4="Paul" ;

	strlist_add_first(l, s1) ;
	strlist_add_first(l, s2) ;
	strlist_add_first(l, s3) ;
	strlist_add_first(l, s4) ;

	strlist_print(l) ;

	char * s ; 
	strlist_remove_first(l, &s) ;
	strlist_print(l) ;

	strlist_free(l) ;

	return 0 ;
}
