#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intstack.h"

stack_t * 
create_stack (int capacity) 
{
	stack_t * st = malloc(sizeof(stack_t)) ;
	st->capacity = capacity ;
	st->size = 0 ;
	st->buffer = calloc(capacity, sizeof(int)) ;
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
push (stack_t * st, int elem)
{
	if (is_full(st))
		return 0 ;

	st->buffer[st->size] = elem ;
	st->size += 1 ;
	return 1 ;
}

int
pop (stack_t * st, int * elem)
{
	if (is_empty(st)) 
		return 0 ;

	*elem = st->buffer[st->size - 1] ;
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
get_element (stack_t * st, int index, int * elem)
{
	if (st->size <= index)
		return 1 ;

	*elem = st->buffer[index] ;
	return 1 ;
}


void
print_stack (stack_t * st)
{
	printf("[") ;
	for (int i = 0 ; i < st->size ; i++) {
		int num ;
		get_element(st, i, &num) ;
		printf("%d%s", num, i < st->size - 1 ? ", " : "") ;
	}
	printf("]\n") ;
}

