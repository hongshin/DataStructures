#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"

char * node (heap_t * h, int index) {
	return h->arr + h->usize * index ;
}

int cmp (heap_t * h, int i1, int i2)
{
	return h->cmp(node(h, i1), node(h, i2)) ;
}

void swap (heap_t * h, int i1, int i2)
{
	char * tmp = (char *) malloc(h->usize) ;
	memcpy(tmp, node(h, i1), h->usize) ;
	memcpy(node(h, i1), node(h, i2), h->usize) ;
	memcpy(node(h, i2), tmp, h->usize) ;
}



int parent (int i) 
{ 
	return i/2;
}

int left (int i) 
{ 
	return i*2 ;
}

int right (int i) 
{
	return (i*2 + 1) ;
}


heap_t * heap_alloc (int capacity, size_t usize, int (* cmp)(void *e1, void *e2)) 
{
	heap_t * h = malloc(sizeof(heap_t)) ;

	h->arr = calloc(capacity + 1, usize) ;
	h->capacity = capacity ;
	h->size = 0 ;
	h->usize = usize ;

	h->cmp = cmp ;
	
	return h ;
}

void heap_free (heap_t * h) 
{
	free(h->arr) ;
	free(h) ;
}

int heap_size (heap_t * h)
{
	return h->size ;
}

int heap_min (heap_t * h, void * buf)
{
	if (h->size == 0)
		return 0 ;

	memcpy(buf, node(h, 1) ,h->usize);
	return 1 ;
}

int heap_insert (heap_t * h, void * buf) 
{
	if (h->size == h->capacity)
		return 0 ;

	(h->size)++ ;
	memcpy(node(h, h->size), buf, h->usize);
	
	int curr = h->size ;

	while (curr != 1 && 0 < cmp(h, parent(curr), curr)) {
		swap(h, parent(curr), curr) ;
		curr = parent(curr) ;
	}
	return 1 ;
}

int heap_remove (heap_t * h, void * buf)
{
	/*TODO*/
}

int heap_delete (heap_t * h, void * e)
{
	/*TODO*/
}
