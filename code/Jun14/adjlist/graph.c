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

	g->n_adj = (int *) calloc(n, sizeof(int)) ;
	g->adj = (int **) calloc(n, sizeof(int *)) ;
	for (int i = 0 ; i < n ; i++) {
		g->adj[i] = (int *) calloc(n, sizeof(int)) ;
		memset(g->adj[i], 0, n * sizeof(int)) ;
	}
	return g ;
}

void 
graph_delete (graph_t * g) 
{
	for (int i = 0 ; i < g->max_vertices ; i++) {
		free(g->adj[i]) ;
	}
	free(g->adj) ;
	free(g->n_adj) ;
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
	if (g->v[u] == 0 || g->v[u] == 0) 
		return 0 ;

	int i ;
	for (i = 0 ; i < g->n_adj[i] ; i++) {
		if (g->adj[u][i] == v)
			return 0 ;
	}

	g->adj[u][g->n_adj[u]] = v ;
	g->adj[v][g->n_adj[v]] = u ;

	g->n_adj[u]++ ;
	g->n_adj[v]++ ;

	return 1 ;
}

void 
graph_print (graph_t * g) 
{
	int v ;
	for (v = 0 ; v < g->max_vertices ; v++) {
		if (g->v[v]) {
			printf("Vertex %d\'s adjacency: ", v) ;
			for (int i = 0 ; i < g->n_adj[v] ; i++) {
				printf("%d ", g->adj[v][i]) ;
			}
			printf("\n") ;
		}
	}
}
