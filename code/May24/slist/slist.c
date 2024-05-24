#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "slist.h"

slist_t *
slist_create (int capacity, size_t usize, int (* cmp)(void *e1, void *e2)) 
{
	slist_t * h = malloc(sizeof(slist_t)) ;
	h->arr = calloc(capacity, usize) ;
	h->capacity = capacity ;
	h->size = 0 ;
	h->usize = usize ;
	h->cmp = cmp ;
	return h ;
}

void
slist_free (slist_t * h) 
{
	free(h->arr) ;
	free(h) ;
}

int
slist_size (slist_t * h)
{
	return h->size ;
}

int
cmp (slist_t * h, int a, int b)
{
	return h->cmp(h->arr + a * h->usize, h->arr + b * h->usize) ;
}

int
slist_top (slist_t * h, void * buf)
{
	if (h->size == 0)
		return 0 ;
	memcpy(buf, h->arr, h->usize) ;
	return 1 ;
}

int
slist_pop (slist_t * h, void * buf)
{
	if (h->size == 0)
		return 0 ;

	/* TODO */

	return 1 ;
}

int
slist_push (slist_t * h, void * buf) 
{
	if (h->size == h->capacity) 
		return 0 ;

	
	int p = 0 ;
	for (p = 0 ; p < h->size ; p++) {
		if (0 < h->cmp(h->arr + p * h->usize, buf)) {
			break ;
		}
	}

	/* TODO */
	return 1 ;
}
