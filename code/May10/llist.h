typedef 
	struct _llist_node_t {
		char data ;
		struct _llist_node_t * next ;
	} 
	llist_node_t ;

typedef 
	struct {
		llist_node_t * first ;
	}
	llist_t ;


llist_t * llist_create () ;

int llist_insert (llist_t * l, char c) ;

int llist_remove_first (llist_t * l, char * p) ;

void llist_free (llist_t * l) ;

