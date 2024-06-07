typedef 
	struct _node_t {
		int data ;
		struct _node_t * left ;
		struct _node_t * right ;
	} 
	node_t ;

typedef struct _node_t bintree_t ;

bintree_t * 
bintree_create (int data) ;

bintree_t *
bintree_add_left (bintree_t * parent, bintree_t * child) ;

bintree_t *
bintree_add_right (bintree_t * parent, bintree_t * right) ;

int
bintree_height(bintree_t * t) ;

int 
bintree_nodes (bintree_t * t) ;

int
bintree_max (bintree_t * t, int * max) ;

int 
bintree_is_full (bintree_t * t) ;


bintree_t *
bintree_search (bintree_t * t, char key) ;

void
bintree_delete (bintree_t *) ;
