#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "slist.h"

int string_cmp (void *e1, void *e2)
{
	char *s1 = *((char **)e1) ;
	char *s2 = *((char **)e2);
	return strcmp(s1, s2) ;
}

int main ()
{
	char * inputs[7] = {"necessary", "correct", "absent", "type", "because", "further", 0x0} ;
	int i ;

	slist_t * l = slist_create(6, sizeof(char *), string_cmp) ;

	for (i = 0 ; inputs[i] != 0x0 ; i++) {
		slist_push(l, &(inputs[i])) ;
	}

	while (slist_size(l) > 0) {
		char * s = 0x0 ;
		slist_pop(l, &s) ;
		printf("%s\n", s) ;
	}

	slist_free(l) ;

	return 0 ;
}
