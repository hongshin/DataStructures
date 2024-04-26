typedef 
	struct _intlist_node_t {
		int element ;
		struct _intlist_node_t * next ;
	}
	intlist_node_t ;

typedef 
	struct {
		intlist_node_t * last ;
	}
	intlist_t ;


intlist_t * intlist_create () ;

int intlist_len (intlist_t * l) ;

int intlist_add (intlist_t * l, int e) ;

int intlist_get (intlist_t * l, int index, int * e)  ;

void intlist_free (intlist_t * l) ;

