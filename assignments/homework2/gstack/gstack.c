#include <stdlib.h>
#include <string.h>
#include "gstack.h"

stack_t * 
create_stack (int capacity, int unit) 
{
	stack_t * st = malloc(sizeof(stack_t)) ;
	st->capacity = capacity ;
	st->unit = unit ;
	st->size = 0 ;
	st->buffer = calloc(capacity, unit) ;
	return st ;
}

void
delete_stack (stack_t * st) 
{
	if (st->buffer != 0x0)
		free(st->buffer) ;
	free(st) ;
}

int 
push (stack_t * st, void * elem)
{
	if (is_full(st))
		return 0 ;

	memcpy(st->buffer + ((st->size) * (st->unit)), elem, st->unit) ;
	st->size += 1 ;
	return 1 ;
}

int
pop (stack_t * st, void * elem)
{
	if (is_empty(st)) 
		return 0 ;

	memcpy(elem, st->buffer + (st->size - 1) * st->unit, st->unit) ;
	st->size -= 1 ;
	return 1 ;
}

int 
is_empty (stack_t * st) 
{
	return (st->size == 0) ;
}

int 
is_full (stack_t * st) 
{
	return (st->size == st->capacity) ;
}

int
get_size (stack_t * st) 
{
	return st->size ;
}

int
get_element (stack_t * st, int index, void * elem)
{
	if (st->size <= index)
		return 0 ;

	memcpy(elem, st->buffer + index * st->unit, st->unit) ;
	return 1 ;
}
