typedef 
	struct _node_t {
		char data ;
		struct _node_t * left ;
		struct _node_t * right ;
	} 
	node_t ;

typedef struct _node_t bintree_t ;
//typedef node_t bintree_t ;

bintree_t * 
bintree_create (char data) ;

bintree_t *
bintree_add_left (bintree_t * parent, bintree_t * child) ;

bintree_t *
bintree_add_right (bintree_t * parent, bintree_t * right) ;

int
bintree_height(bintree_t * t) ;

bintree_t *
bintree_search (bintree_t * t, char key) ;

void
bintree_delete (bintree_t *) ;

void
bintree_print (bintree_t * t) ;
