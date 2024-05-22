#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"

int 
string_cmp (void *e1, void *e2)
{
	char *s1 = *((char **)e1) ;
	char *s2 = *((char **)e2);
	return strcmp(s1, s2) ;
}

int 
main ()
{
	char * inputs[7] = {"necessary", "correct", "absent", "type", "because", "further", 0x0} ;
	int i ;

	heap_t * h = heap_create(6, sizeof(char *), string_cmp) ;

	for (i = 0 ; inputs[i] != 0x0 ; i++) {
		heap_push(h, &(inputs[i])) ;
	}

	while (heap_size(h) > 0) {
		char * s = 0x0 ;
		heap_pop(h, &s) ;
		printf("%s\n", s) ;
	}

	return 0 ;
}
