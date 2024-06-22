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
	memset(g->v, 0, n * sizeof(int)) ;

	g->adj = (int **) calloc(n, sizeof(int *)) ;
	for (int i = 0 ; i < n ; i++) {
		g->adj[i] = NULL ;
		//g->adj[i] = (int *) calloc(n, sizeof(int)) ;
		//memset(g->adj[i], 0, n * sizeof(int)) ;
	}
	return g ;
}

void 
graph_delete (graph_t * g) 
{
	for (int i = 0 ; i < g->max_vertices ; i++) {
		if (g->adj[i]) 
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

	g->n_adj[u]++ ;
	g->n_adj[v]++ ;

	g->adj[u] = realloc(g->adj[u], g->n_adj[u] * sizeof(int)) ;
	g->adj[v] = realloc(g->adj[v], g->n_adj[v] * sizeof(int)) ;

	g->adj[u][g->n_adj[u] - 1] = v ;
	g->adj[v][g->n_adj[v] - 1] = u ;

	return 1 ;
}

int	
graph_remove_edge (graph_t * g, int u, int v)
{
	if (g->v[u] == 0 || g->v[u] == 0) 
		return 0 ;

	int i, j ;
	for (i = 0 ; i < g->n_adj[u] ; i++) {
		if (g->adj[u][i] == v)
			break ;
	}
	if (i == g->n_adj[i]) {
		return 0 ;
	}

	g->n_adj[u]-- ;
	for (j = i ; j < g->n_adj[u] ; j++) {
		g->adj[u][i] = g->adj[u][i + 1] ;
	}

	g->n_adj[v]-- ;
	for (i = 0 ; i < g->n_adj[v] ; i++) {
		if (g->adj[u][i] == u)
			break ;
	}

	for (j = i ; j < g->n_adj[v] ; j++) {
		g->adj[v][i] = g->adj[v][i + 1] ;
	}

	g->adj[u] = realloc(g->adj[u], g->n_adj[u] * sizeof(int)) ;
	g->adj[v] = realloc(g->adj[v], g->n_adj[v] * sizeof(int)) ;

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
