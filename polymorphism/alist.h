typedef struct {
	size_t capacity ;
	size_t length ;
	void * arr ;
} alist ;

list * alist_alloc (size_t s) ;

void alist_free (list * l) ;

int alist_add (list * l, void * s) ;

int alist_remove (list * l, int i, void * s) ;

void alist_print (list * l, void (* elem_print)(void *)) ;
