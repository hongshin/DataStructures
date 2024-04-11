#include <stdlib.h>
#include <string.h>
#include "queue.h"

gqueue_t * 
create_queue (int capacity, int unit) 
{
	gqueue_t* queue = (gqueue_t*)malloc(sizeof(gqueue_t));
	queue->capacity = capacity;
	queue->front = 0;
	queue->rear = 0;
	queue->size = 0;
	queue->unit = unit;
	queue->buffer = calloc(capacity,unit);
	return queue;
}

void
delete_queue (gqueue_t * queue) 
{
	if (queue->buffer) {
		free(queue->buffer);
	}
	free(queue);
}

int 
enqueue (gqueue_t * queue, void * elem)
{
	if (is_full(queue) == 1) {
		return 0;
	}
	memcpy(queue->buffer+(queue->rear*queue->unit),elem,queue->unit);
	queue->size += 1;
	queue->rear = (queue->rear + 1) % queue->capacity; 
	//queue가 capacity가 4인데 한칸 남아서 넣으면 rear가 4가되어야하는데 이 위치가 0자리임. 
	return 1;
}

int
dequeue (gqueue_t * queue, void * elem)
{
	if (is_empty(queue) == 1){
		return 0;
	}
	memcpy(elem,queue->buffer+(queue->front*queue->unit),queue->unit);
	queue->size -=1;
	queue->front = (queue->front + 1) % queue->capacity;
	//마찬가지로 queue의 capactiy가 4일때 꽉채웠다가 dequeue를 다하면 front는 4가 되야하지만 이 위치가 0자리임.
	return 1;
}

int 
front (gqueue_t * queue, void * elem)
{
	if(is_empty(queue) == 1){
		return 0;
	}
	memcpy(elem, queue->buffer+(queue->front*queue->unit),queue->unit);
	return 1;
}

int 
is_empty (gqueue_t * queue) 
{
	if(queue->size == 0){
		return 1;
	}
	return 0;
}
int 
is_full (gqueue_t * queue) 
{	
	if(queue->size == queue->capacity){
		return 1;
	}
	return 0;
}
int
get_size (gqueue_t * queue) 
{
	return queue->size;
}
int
get_elem (gqueue_t * queue, int i, void * elem)
{
	if (i < 0)
		return 0;
	if (i >= queue->size) {
		return 0;
	}
	memcpy(queue->buffer+((queue->front+i)*queue->unit),elem,queue->unit);
	return 1;
}







