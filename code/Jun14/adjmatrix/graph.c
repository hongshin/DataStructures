#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

graph_t * 
graph_create (int n) 
{
	graph_t * g = malloc(sizeof(graph_t)) ;

	g->max_vertices = n ;

	g->v = (int *) calloc(n, sizeof(int)) ;
	memset(g->v, 0, n * sizeof(int)) ;

	g->e = (int **) calloc(n, sizeof(int *)) ;
	for (int i = 0 ; i < n ; i++) {
		g->e[i] = (int *) calloc(n, sizeof(int)) ;
		memset(g->e[i], 0, n * sizeof(int)) ;
	}

	return g ;
}

void 
graph_delete (graph_t * g) 
{
	for (int i = 0 ; i < g->max_vertices ; i++) {
		free(g->e[i]) ;
	}
	free(g->e) ;
	free(g->v) ;
	free(g) ;
}

int	
graph_insert_vertex (graph_t * g, int u) 
{
	if (g->v[u] == 1)
		return 0 ;

	g->v[u] = 1 ;
	return 1 ;
}

int	
graph_insert_edge (graph_t * g, int u, int v)
{
	if (g->v[u] == 0 || g->v[v] == 0) 
		return 0 ;

	if (g->e[u][v] == 1)
		return 0 ;

	g->e[u][v] = 1 ;
	g->e[v][u] = 1 ;
	return 1 ;
}

int
graph_remove_edge (graph_t * g, int u, int v)
{
	if (g->v[u] == 0 || g->v[v] == 0) 
		return 0 ;

	if (g->e[u][v] == 0)
		return 0 ;

	g->e[u][v] = 0 ;
	g->e[v][u] = 0 ;
	return 1 ;

}

int
graph_remove_vertex (graph_t * g, int u)
{
	if (g->v[u] == 0)
		return 0 ;

	int i ;
	for (i = 0 ; i < g->max_vertices ; i++) {
		g->e[u][i] = 0 ;
		g->e[i][u] = 0 ;
	}

	g->v[u] = 0 ;

	return 1 ;
}



void 
graph_print (graph_t * g) 
{
	int v ;
	for (v = 0 ; v < g->max_vertices ; v++) {
		if (g->v[v]) {
			printf("Vertex %d\'s adjacency: ", v) ;
			for (int u = 0 ; u < g->max_vertices ; u++) {
				if (g->e[v][u]) 
					printf("%d ", u) ;
			}
			printf("\n") ;
		}
	}
}

void
_graph_dfs_print (graph_t * g, int u, int * reached) 
{
	if (reached[u] == 1)
		return ;

	printf("%d ", u) ;
	reached[u] = 1 ;

	for (int v = 0 ; v < g->max_vertices ; v++) {
		if (g->v[v] == 1 && reached[v] == 0) {
			if (g->e[u][v] == 1) 
				_graph_dfs_print(g, v, reached) ;
		}
	}
}

int 
graph_dfs_print (graph_t * g, int u) 
{
	if (g->v[u] == 0)
		return 0 ;

	int * reached = (int *) calloc(g->max_vertices, sizeof(int)) ;
	memset(reached, 0, g->max_vertices * sizeof(int)) ;

	_graph_dfs_print(g, u, reached) ;
	printf("\n") ;

	free(reached) ;
	return 1 ;
}

void
_graph_dfs_spanning_tree (graph_t * g, int u, int * reached, graph_t * t) 
{
	if (reached[u] == 1)
		return ;

	reached[u] = 1 ;

	for (int v = 0 ; v < g->max_vertices ; v++) {
		if (g->v[v] == 1 && reached[v] == 0) {
			if (g->e[u][v] == 1 && reached[v] == 0) {
				graph_insert_vertex(t, v) ;
				graph_insert_edge(t, u, v) ;
				_graph_dfs_spanning_tree(g, v, reached, t) ;
			}
		}
	}
}

graph_t * 
graph_dfs_spanning_tree (graph_t * g, int u) 
{
	if (g->v[u] == 0)
		return NULL ;

	int * reached = (int *) calloc(g->max_vertices, sizeof(int)) ;
	memset(reached, 0, g->max_vertices * sizeof(int)) ;

	graph_t * t = graph_create(g->max_vertices) ;
	_graph_dfs_spanning_tree(g, u, reached, t) ;

	free(reached) ;
	return t ;
}

	
int 
graph_dfs_order(graph_t * g, int u, int * order) 
{
}
