#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef 
	struct {
		int y ;
		int x ; 
	}
	cell_t ;


int map[10][10] ;
int X, Y ;

int remove_an_island ()
{
	int y, x ;

	cell_t s ;
	int found = 0 ;
	/* TODO: find a land cell */

	if (found == 0) {
		return 0 ;
	}


	gqueue_t * to_erase = create_queue(X * Y, sizeof(cell_t)) ;

	/* TODO: from s, erase the cell and bring the connected cells to the to_erase queue */ 

	return 1 ;
}


int main ()
{

	FILE * fp = fopen("map.txt", "r") ;
	fscanf("%d %d", &X, &Y) ;
	for (int i = 0 ; i < Y ; i++) {
		for (int j = 0 ; j < X ; j++) {
			scanf("%d", &(map[i][j])) ;
		}
	}
	fclose(fp) ;


	while (remove_an_island()) {
		N++ ;
	}
	printf("%d\n", N) ;

	return EXIT_SUCCESS ;
}
