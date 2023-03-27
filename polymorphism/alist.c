#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "alist.h"

list * alist_alloc (size_t s) 
{
	list * l = (list *) malloc(sizeof(list)) ;

	l->elem_size = s ;

	l->d = malloc(sizeof(alist)) ;
	alist * al = (alist *) l->d ;

	al->arr = calloc(16, l->elem_size) ;
	al->capacity = 16 ;
	al->length = 0 ;

	l->free = alist_free ;
	l->add = alist_add ;
	l->remove = alist_remove ;
	l->print = alist_print ;
	
	return l ;
}

void alist_free (list * l) 
{
	alist * al = (alist *) l->d ; 

	free(al->arr) ;
	free(al) ;
	free(l) ;
}

int alist_add (list * l, void * s) 
{
	alist * al = (alist *) l->d ;

	if (al->length == al->capacity) {
		al->arr = realloc(al->arr, al->capacity * 2) ;
		al->capacity = al->capacity * 2 ;
	}

	memcpy(al->arr + l->elem_size * al->length, s, l->elem_size) ;
	al->length++ ;
}

int alist_remove (list * l, int i, void * s) 
{
	alist * al = (alist *) l->d ;

	if (i < 0 || al->length <= i)
		return 0 ;

	memcpy(s, al->arr + l->elem_size * i, l->elem_size) ;
	

	for (int j = i ; i < al->length - 1 ; i++) {
		memcpy(al->arr + l->elem_size * j, al->arr + l->elem_size * (j + 1), l->elem_size) ;
	}
	al->length-- ;

	return 1 ;
}

void alist_print (list * l, void (* elem_print)(void *)) 
{
	alist * al = (alist *) l->d ;

	
	for (int i = 0 ; i < al->length ; i++) {
		elem_print(al->arr + l->elem_size * i) ;
		printf(" ") ;
	}
	printf("\n") ;
}
