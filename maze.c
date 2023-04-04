#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "stack.h"

enum direction {
	Up, 
	Down, 
	Right,
	Left,
	Done
}

typedef struct {
	int x ;
	int y ;
	enum direction dir ;
} decision ;

int dx[4] = {0, 0, 1, -1} ;
int dy[4] = {-1, 1, 0, 0} ;

int nx, ny ;
int maze[16][16] ;

int issame (void * p1, void * p2)
{
	//TODO
}

void print_decision (void * p)
{
	//TODO
}


void find_path ()
{
	stack * decisions = stack_alloc(sizeof(decision)) ;

	decision start = {0, 0, Up} ;
	
	stack_push(decisions, &start) ;

	while (!stack_empty(decisions)) {
		decision d ;		
		stack_pop(decisions, &d) ;
		
		if (d.x == nx - 1 && d.y == ny - 1) {
			stack_print(decisions, print_decision) ;
			return ;
		}

		if (d.dir == Done) {
			continue ;
		}
		else {
			decision next ;
			next.x = d.x + dx[d.dir] ;
			next.y = d.y + dy[d.dir] ;
			next.dir = Up ;

			if ((0 <= next.x && next.x < nx) &&
				(0 <= next.y && next.y < ny) &&
				(maze[next.y][next.x] == 0) &&
				!stack_contains(decisions, &next, issame)) {
				d.dir++ ;
				stack_push(decisions, &d) ;
				stack_push(decisions, &next) ;				
			}
			else {
				d.dir++ ;
				stack_push(decisions, &d) ;
			}
		}
	}
}


int main ()
{

	scanf("%d %d", &nx, &ny) ;

	int x, y ;
	for (y = 0 ; y < ny ; y++) {
		for (x = 0 ; x < nx ; x++) {
			scanf("%d", &(maze[y][x])) ; 			
		}
	}

	for (y = 0 ; y < ny ; y++) {
		for (x = 0 ; x < nx ; x++) {
			printf("%d ", maze[y][x]) ;
		}
		printf("\n") ;
	}	

	find_path() ;
    return 0 ;
}

