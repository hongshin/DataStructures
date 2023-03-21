typedef struct _glist_node {
	void * elem ;
	struct _glist_node * next ;
} glist_node ; 

typedef struct {
	glist_node * head ;
	size_t size ;
} glist ;

glist * glist_alloc (size_t s) ;

void glist_free (glist * l) ;

int glist_search (glist * l, int (* elem_cond)(void *)) ;

int glist_add_first (glist * l, void * s) ;

int glist_add_last (glist * l, void * s) ;

int glist_remove (glist * l, int i, void * s) ;

int glist_remove_first (glist * l, void * s) ;

void glist_print (glist * l, void (* elem_print)(void *)) ;

