#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gqueue.h"

typedef enum {
		closed, marked, open
	}
	cell_state ;

typedef struct {
		int mined ;
		int num ;
		cell_state state ; 
	}
	cell_t  ;


int M, N, K ;
cell_t board[16][16] = {{ {0, 0, 0} }} ;

void load_board (char * filename)
{
	FILE * fp ;
	if (!(fp = fopen(filename, "r"))) {
		fprintf(stderr, "Fail to open %s\n", filename) ;
		exit(EXIT_FAILURE) ;
	} 

	fscanf(fp, "%d %d %d", &M, &N, &K) ;

	/* TODO */

	fclose(fp) ;
}

int is_terminated ()
{
	/* TODO */
	return 0 ;
}

void draw_board ()
{
	int col, row ;
	for (row = 0 ; row < M ; row++) {
		for (col = 0 ; col < N ; col++) {
			printf("+ ") ;

		}
		printf("\n") ;
	}
	/* FIXME */
}

void read_execute_userinput ()
{	
	/* FIXME*/
	printf(">") ;

	char command[16] ;
	int col, row ;
	scanf("%15s %d %d", command, &row, &col) ;
}

int main (int argc, char ** argv)
{
	if (argc != 2) {
		fprintf(stderr, "Invalid command: give a filename of board arrangement.\n") ;
		return EXIT_FAILURE ;
	}

	load_board(argv[1]) ;

	while (!is_terminated()) {
		draw_board() ;
		read_execute_userinput() ;
	}

	return EXIT_SUCCESS ;
}
