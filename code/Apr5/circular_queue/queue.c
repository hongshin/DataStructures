#include <stdlib.h>
#include <string.h>
#include "queue.h"

gqueue_t * 
create_queue (int capacity, int unit) 
{
	gqueue_t * queue = (gqueue_t *) malloc(sizeof(gqueue_t)) ;
	queue->capacity = capacity ;
	queue->unit = unit;
	queue->front = 0 ;
	queue->rear = 0 ;
	queue->size = 0 ;
	queue->buffer = calloc(capacity, unit) ;
	return queue ; 
}

void
delete_queue (gqueue_t * queue) 
{
	if (queue->buffer) {
		free(queue->buffer) ;
	}
	free(queue) ;
}

int 
enqueue (gqueue_t * queue, void * elem)
{
	if (is_full(queue))
		return 0 ;
	//gqueue

	// for(int i = 0; i < queue->unit; i++){
	// 	*(queue->buffer + queue->rear * queue->unit + i) = *(elem +i);
	// }

	//=>
	memcpy(queue->buffer + (queue->rear * queue->unit), elem, queue->unit);


	//when just circular( not gqueue)
	//queue->buffer[queue->rear] = elem ;
	//queue->rear += 1 ;
	// if (queue->rear == queue->capacity) {
	// 	queue->rear = 0 ;
	// }
	queue->rear = (queue->rear + 1) % queue->capacity ;
	queue->size += 1 ;
	return 1 ;
}

int
dequeue (gqueue_t * queue, void * elem)
{
	if (is_empty(queue)) 
		return 0 ;
	memcpy(elem , queue->buffer + (queue->front * queue->unit), queue->unit);
	//*elem = queue->buffer[queue->front] ;
	queue->front = (queue->front +1) % queue->capacity;

	queue->size -= 1 ;
	return 1;
}

int 
front (gqueue_t * queue, void * elem)
{
	if (is_empty(queue)) 
		return 0 ;
	
	//*elem = queue->buffer[queue->front] ;
	return 1;
}

int 
is_empty (gqueue_t * queue) 
{
	return (queue->size == 0) ;
}

int 
is_full (gqueue_t * queue) 
{
	return (queue->size == queue->capacity) ;
}

int
get_size (gqueue_t * queue) 
{
	return queue->size ;
}

int
get_elem (gqueue_t * queue, int i, void * elem)
{
	if (i < 0)
		return 0 ;
	if (queue->size <= i)
		return 0 ;

	int index  = (queue->front + i) % queue->capacity;


	memcpy(elem, queue->buffer+(index * queue->unit)+i, queue->unit);

	//*elem = queue->buffer[(queue->front + i) % queue->capacity] ;
	return 1 ;
}







