#include <stdlib.h>
#include "chstack.h"

stack_t * 
create_stack (int capacity) 
{
	stack_t * stack = (stack_t *) malloc(sizeof(stack_t)) ;
	stack->capacity = capacity ;
	stack->size = 0 ;
	stack->buffer = (char *) calloc(capacity, sizeof(char)) ;
	return stack ; 
}

void
delete_stack (stack_t * stack) 
{
	free(stack->buffer) ;
	free(stack) ;
}

int 
push (stack_t * stack, char elem)
{
	if (is_full(stack))
		return 0 ;
	
	stack->buffer[stack->size] = elem ;
	stack->size += 1 ;
	return 1 ;
}

int
pop (stack_t * stack, char * elem)
{
	if (is_empty(stack)) 
		return 0 ;
	
	*elem = stack->buffer[stack->size - 1] ;
	stack->size -= 1 ;
	return 1;
}

int
top (stack_t * stack, char * elem)
{
	if (is_empty(stack)) 
		return 0 ;
	
	*elem = stack->buffer[stack->size - 1] ;
	return 1;
}

int 
is_empty (stack_t * stack) 
{
	return (stack->size == 0) ;
}

int 
is_full (stack_t * stack) 
{
	return (stack->size == stack->capacity) ;
}

int
get_size (stack_t * stack) 
{
	return stack->size ;
}

int
get_elem (stack_t * stack, int index, char * elem)
{
	if (index < 0)
		return 0 ;
	if (stack->size <= index)
		return 0 ;

	*elem = stack->buffer[index] ;
	return 1 ;
}
