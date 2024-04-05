#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main ()
{
	gqueue_t * q ;

	q = create_queue(4, sizeof(double)) ;

	int i ;
	double d ;
	for (i = 0 ; i < 5 ; i++) {
		d = (double) i ;
		enqueue(q, &d) ;
	}

	dequeue(q, &d) ;
	dequeue(q, &d) ;

	for (i = 0 ; i < get_size(q) ; i++) {
		dequeue(q, &d) ;
		printf("%d\n", d) ;
	}


	return EXIT_SUCCESS ;
}
