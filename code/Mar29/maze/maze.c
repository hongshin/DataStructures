#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

typedef 
	enum { 
		UP, DOWN, LEFT, RIGHT, DONE 
	} 
	dir ;

enum cell {
	EMPTY, WALL, PATH
} ;


int X, Y ;
int m[20][20] ;

void
print_map ()
{
	int i, j ;

	for (i = 0 ; i < X + 2 ; i++)
		printf("XX") ;
	printf("\n") ;
	for (i = 0 ; i < Y ; i++) {
		printf("XX") ;
		for (j = 0 ; j < X ; j++) {
			if (m[i][j] == WALL) 
				printf("XX") ;
			else if (m[i][j] == PATH) 
				printf("::") ;
			else 
				printf("  ") ;
		}
		printf("XX\n") ;
	}
	for (i = 0 ; i < X + 2 ; i++)
		printf("XX") ;
	printf("\n") ;
}

void load_map(char * filename) 
{
	FILE * fp = fopen(filename, "r") ;
	fscanf(fp, "%d %d", &X, &Y) ;
	for (int i = 0 ; i < Y ; i++) {
		for (int j = 0 ; j < X ; j++) {
			fscanf(fp, "%d", &(m[i][j])) ;
		}
	}
	fclose(fp) ;
}

int is_in_path(stack_t * xs, stack_t * ys, int nx, int ny)
{
	int i ;
	for (i = 0 ; i < get_size(xs) ; i++) {
		int x, y ;
		get_elem(xs, i, &x) ; get_elem(ys, i, &y) ;
		if (x == nx && y == ny) 
			return 1 ;
	}

	return 0 ;
}

void search ()
{
	stack_t * xs = create_stack(400) ;
	stack_t * ys = create_stack(400) ;
	stack_t * ds = create_stack(400) ;

	push(xs, 0) ;
	push(ys, 0) ;
	push(ds, UP) ;

	while (is_empty(xs) == 0) {
		int x, y, d ;
		pop(xs, &x) ; pop(ys, &y) ; pop(ds, &d) ;

		if (x == X - 1 && y == Y - 1) {
			for (int i = 0 ; i < get_size(xs) ; i++) {
				int x, y ;
				get_elem(xs, i, &x) ; get_elem(ys, i, &y) ;
				printf("(%d,%d) ", y, x) ;
			}
			printf("\n") ;
			return ;
		}

		if (d == 4) {
			continue ;
		}

		int nx, ny ;
		switch (d) {
			case UP: {
				nx = x ;
				ny = y - 1 ;
				break ;
			}
			case DOWN: {
				nx = x ;
				ny = y + 1 ;
				break ; 
			}
			case LEFT: {
				nx = x - 1 ;
				ny = y ;
				break ; 
			}
			case RIGHT: {
				nx = x + 1 ;
				ny = y ;
				break ;
			}
		}
		push(xs, x) ; push(ys, y) ; push(ds, d + 1) ;

		if (0 <= nx && nx < X && 0 <= ny && ny < Y) {
			if (m[ny][nx] == 0) {
				if (is_in_path(xs, ys, nx, ny) == 0) {
					push(xs, nx) ; push(ys, ny) ; push(ds, 0) ;
				}
			}
		}
	}
}


int main ()
{
	load_map("maze2.txt") ;
	print_map() ;

	search() ;

	return EXIT_SUCCESS ;
}
