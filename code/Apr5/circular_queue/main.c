#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main ()
{
	gqueue_t * q ;

	int n = 0;
	printf("How many soldiers? :");
	scanf("%d", &n);

	int m = 0;
	printf("input m: ");
	scanf("%d", &m);

	q = create_queue(n, sizeof(int));
	
	for(int i = 1; i <= n; i++){
		enqueue(q, &i);
	}

	int turn = 0;
	while(get_size(q) > 1){
		int curr;
		dequeue(q, &curr);
		if(turn < m - 1){
			enqueue(q, &curr);
			turn +=1;
		}
		else{
			turn = 0;
		}
	}
	int answer;
	dequeue(q, &answer);
	printf("%d\n", answer);

	return EXIT_SUCCESS ;
}
