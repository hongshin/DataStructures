#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

int main ()
{
	graph_t * g = graph_create(10) ;

	int i ;
	for (i = 0 ; i < 10 ; i++) {
		graph_insert_vertex(g, i) ;
	}

	graph_insert_edge(g, 0, 1) ;
	graph_insert_edge(g, 1, 2) ;
	graph_insert_edge(g, 1, 3) ;
	graph_insert_edge(g, 2, 4) ;
	graph_insert_edge(g, 3, 4) ;
	graph_insert_edge(g, 3, 5) ;
	graph_insert_edge(g, 5, 6) ;
	graph_insert_edge(g, 5, 7) ;
	graph_insert_edge(g, 7, 8) ;
	graph_insert_edge(g, 7, 9) ;
	graph_insert_edge(g, 6, 7) ;

	graph_print(g) ;	

	/*
	printf("----\n") ;
	
	graph_dfs_print(g, 3) ;

	int visit[10] ;
	memset(visit, 0, sizeof(visit)) ;
	graph_dfs_order(g, 3, visit) ;

	for (i = 0 ; i < 10 ; i++) {
		printf("%d ", visit[i]) ;
	}

	graph_t * g_s ;
	g_s = graph_dfs_spanning_tree(g, 3) ;
	graph_print(g_s) ;

	graph_delete(g_s) ;
	*/
	graph_delete(g) ;

	return EXIT_SUCCESS ;
}
