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

	for (y = 0 ; y < Y && found == 0 ; y++) {
		for (x = 0 ; x < X ; x++) {
			if (map[y][x] == 1) {
				s.y = y ;
				s.x = x ;
				found = 1 ;
				break ;
			}
		}
	}
	if (found == 0) {
		return 0 ;
	}

	gqueue_t * cells_to_erase = create_queue(X * Y, sizeof(cell_t)) ;

	enqueue(cells_to_erase, &s) ;
	while (!is_empty(cells_to_erase)) {
	
		cell_t c ;
		dequeue(cells_to_erase, &c) ;
		map[c.y][c.x] = 0 ;


		int dx[4] = {0, 0, -1, 1} ;
		int dy[4] = {1, -1, 0, 0} ;

		for (int d = 0 ; d < 4 ; d++) {
			cell_t a ;

			a.y = c.y + dy[d] ;
			a.x = c.x + dx[d] ;

			if (0 <= a.y && a.y < Y && 0 <= a.x && a.x < X) {
				if (map[a.y][a.x] == 1) {
					enqueue(cells_to_erase, &a) ;
				}
			}
		}


		/*
		cell_t up, down, left, right ;

		up.y = c.y - 1 ;
		up.x = c.x ;

		down.y = c.y + 1 ;
		down.x = c.x ;

		left.y = c.y ;
		left.x = c.x - 1 ;

		right.y = c.y ;
		right.x = c.x + 1 ;

		if (0 <= up.y && up.y < Y && 0 <= up.x && up.x < X) {
			if (map[up.y][up.x] == 1) {
				enqueue(cells_to_erase, &up) ;
			}
		}
		...
		*/
	}

	/* TODO: from s, erase the cell and bring the connected cells to the to_erase queue */ 

	return 1 ;
}


int main ()
{

	FILE * fp = fopen("map.txt", "r") ;
	fscanf(fp, "%d %d", &X, &Y) ;
	for (int i = 0 ; i < Y ; i++) {
		for (int j = 0 ; j < X ; j++) {
			fscanf(fp, "%d", &(map[i][j])) ;
		}
	}
	fclose(fp) ;


	while (remove_an_island()) {
		N++ ;
	}
	printf("%d\n", N) ;

	return EXIT_SUCCESS ;
}
