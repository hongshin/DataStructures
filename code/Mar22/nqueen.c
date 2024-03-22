#include <stdio.h>
#include <stdlib.h>
#include "stack.h" 

int row (int cell)
{
	return cell / 8 ;
}

int col (int cell)
{
	return cell % 8 ;
}

int is_feasible (stack_t * queens) 
{
	int board[8][8] ;
	int c, r ;

	for (r = 0 ; r < 8 ; r++) {
		for (c = 0 ; c < 8 ; c++) {
			board[r][c] = 0 ;
		}
	}

	for (int i = 0 ; i < get_size(queens) ; i++) {
		int cell ;
		get_elem(queens, i, &cell) ;
		
		int r = row(cell) ;
		int c = col(cell) ;
	
		if (board[r][c] != 0) {
			return 0 ;
		}

		int x, y ;
		for (y = 0 ; y < 8 ; y++) {
			board[y][c] = 1 ;
		}
		for (x = 0 ; x < 8 ; x++) {
			board[r][x] = 1 ;
		}

		y = r + 1 ; x = c + 1 ;
		while (0 <= y && y < 8 && 0 <= x && x < 8) {
			board[y][x] = 1 ;
			y += 1 ; x += 1 ;
		}

		y = r + 1 ; x = c - 1 ;
		while (0 <= y && y < 8 && 0 <= x && x < 8) {
			board[y][x] = 1 ;
			y += 1 ; x -= 1 ;
		}

		y = r - 1 ; x = c + 1 ;
		while (0 <= y && y < 8 && 0 <= x && x < 8) {
			board[y][x] = 1 ;
			y -= 1 ; x += 1 ;
		}

		y = r - 1 ; x = c - 1 ;
		while (0 <= y && y < 8 && 0 <= x && x < 8) {
			board[y][x] = 1 ;
			y -= 1 ; x -= 1 ;
		}

	}

	return 1;
}


int main ()
{
	stack_t * queens = create_stack(8) ;

	push(queens, 0) ;
	while (!is_empty(queens)) {
		int latest_queen ;
		top(queens, &latest_queen) ;

		if (latest_queen == 64) {
			pop(queens, &latest_queen) ;
			if (!is_empty(queens)) {
				pop(queens, &latest_queen) ;
				push(queens, latest_queen + 1) ;
			}
			else {
				break ;
			}
			continue ;
		}

		if (is_feasible(queens)) {
			if (get_size(queens) == 8) {
				for (int i = 0 ; i < 8 ; i++) {	
					int queen ;
					get_elem(queens, i, &queen) ;
					printf("%d ", queen) ;
				}
				printf("\n") ;
				//return 0 ;

				int lastest_queen ;
				pop(queens, &latest_queen) ;
				push(queens, latest_queen + 1) ;
			}
			else {
				int latest_queen ;
				top(queens, &latest_queen) ;
				push(queens, latest_queen + 1) ;
			}
		}
		else {
			int lastest_queen ;
			pop(queens, &latest_queen) ;
			push(queens, latest_queen + 1) ;
		}

	}
	delete_stack(queens) ;

	return EXIT_FAILURE ;
}
