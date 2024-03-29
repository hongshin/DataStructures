#include <stdlib.h>
#include "queue.h"

queue_t * 
create_queue (int capacity) 
{
	queue_t * queue = (queue_t *) malloc(sizeof(queue_t)) ;
	queue->capacity = capacity ;
	queue->size = 0 ;
	queue->buffer = (int *) calloc(capacity, sizeof(int)) ;
	return queue ; 
}

void
delete_queue (queue_t * queue) 
{
	if (queue->buffer) {
		free(queue->buffer) ;
	}
	free(queue) ;
}

int 
enqueue (queue_t * queue, int elem)
{
	if (is_full(queue))
		return 0 ;
	
	queue->buffer[queue->size] = elem ;
	queue->size += 1 ;
	return 1 ;
}

int
dequeue (queue_t * queue, int * elem)
{
	if (is_empty(queue)) 
		return 0 ;
	
	*elem = queue->buffer[0] ;
	
	for (int i = 0 ; i < queue->size - 1 ; i++) {
		queue->buffer[i] = queue->buffer[i + 1] ;
	}
	queue->size -= 1 ;
	return 1;
}

int 
front (queue_t * queue, int * elem)
{
	if (is_empty(queue)) 
		return 0 ;
	
	*elem = queue->buffer[0] ;
	return 1;
}

int 
is_empty (queue_t * queue) 
{
	return (queue->size == 0) ;
}

int 
is_full (queue_t * queue) 
{
	return (queue->size == queue->capacity) ;
}

int
get_size (queue_t * queue) 
{
	return queue->size ;
}

int
get_elem (queue_t * queue, int index, int * elem)
{
	if (index < 0)
		return 0 ;
	if (queue->size <= index)
		return 0 ;

	*elem = queue->buffer[index] ;
	return 1 ;
}
