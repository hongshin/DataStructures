typedef 
	struct _node_t {
		char data ;
		struct _node_t * down ; // left, child
		struct _node_t * next ; // sibling, right
	} 
	node_t ;

typedef struct _node_t tree_t ;
//typedef node_t tree_t ;

tree_t * 
tree_create (char data) ;

tree_t *
tree_add_child (tree_t * parent, tree_t * child) ;

int
tree_height (tree_t * t) ;

int
tree_degree (tree_t * t) ;

int
tree_degree(tree_t * t) ;

tree_t *
tree_search (tree_t * t, char key) ;

void
tree_delete (tree_t *) ;

void
tree_print (tree_t * t) ;
