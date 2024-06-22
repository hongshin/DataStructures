typedef 
	struct {
		int max_vertices ;
		int * v ;
		int ** e ;		
	}
	graph_t ;


graph_t * 
graph_create (int n) ;

void 
graph_delete (graph_t * g) ;

int	
graph_insert_vertex (graph_t * g, int u) ;

int	
graph_insert_edge (graph_t * g, int u, int v) ;

int
graph_remove_vertext (graph_t * g, int u) ;

int
graph_remove_edge (graph_t * g, int u, int v) ;

void 
graph_print (graph_t * g) ;


int 
graph_dfs_print (graph_t * g, int u) ;
	
int 
graph_dfs_order(graph_t * g, int u, int * visit) ;

graph_t * 
graph_dfs_spanning_tree (graph_t *, int u) ;
