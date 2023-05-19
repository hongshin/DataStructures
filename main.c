#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"

typedef 
	struct {
		int month ;
		int day ;
		char * name ;
	}
	person_t ;

int person_cmp (void *e1, void *e2)
{
	person_t * p1 = (person_t *) e1 ;
	person_t * p2 = (person_t *) e2 ;

	if (p1->month != p2->month)
		return p1->month - p2->month ;

	return p1->day - p2->day ;
}

int main ()
{
	person_t persons[8] = {
		{7, 3, "Tim"},
		{4, 20, "Ken"},
		{5, 6, "Ali"},
		{12, 3, "Chen"},
		{4, 10, "John"},
		{2, 20, "Tom"},
		{7, 1, "Chris"},
		{5, 16, "Tina"} 
	} ;

	heap_t * h = heap_alloc(8, sizeof(person_t), person_cmp) ;

	for (int i = 0 ; i < 8 ; i++) {
		heap_insert(h, &(persons[i])) ;
	}

	while (heap_size(h) > 0) {
		person_t p ;

		heap_remove(h, &p) ;
		printf("%s\n", p.name) ;
	}

	return 0 ;
}
