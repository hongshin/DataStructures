#include <stdlib.h>
#include <string.h>
#include "gstack.h"

gstack_t * 
create_stack (int capacity, int unit) 
{
	gstack_t * st = malloc(sizeof(gstack_t)) ;
	st->capacity = capacity ;
	st->unit = unit ;
	st->size = 0 ;
	st->buffer = calloc(capacity, unit) ;
	return st ;
}

void
delete_stack (gstack_t * st) 
{
	if (st->buffer != 0x0)
		free(st->buffer) ;
	free(st) ;
}

int 
push (gstack_t * st, void * elem)
{
	if (is_full(st))
		return 0 ;

	memcpy(st->buffer + ((st->size) * (st->unit)), elem, st->unit) ;
	st->size += 1 ;
	return 1 ;
}

int
pop (gstack_t * st, void * elem)
{
	if (is_empty(st)) 
		return 0 ;

	memcpy(elem, st->buffer + (st->size - 1) * st->unit, st->unit) ;
	st->size -= 1 ;
	return 1 ;
}

int 
is_empty (gstack_t * st) 
{
	return (st->size == 0) ;
}

int 
is_full (gstack_t * st) 
{
	return (st->size == st->capacity) ;
}

int
get_size (gstack_t * st) 
{
	return st->size ;
}

int
get_element (gstack_t * st, int index, void * elem)
{
	if (st->size <= index)
		return 0 ;

	memcpy(elem, st->buffer + index * st->unit, st->unit) ;
	return 1 ;
}
