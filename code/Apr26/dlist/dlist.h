struct node {
	void * element ;
	struct node * left ; 
	struct node * right ;
} ;

typedef struct node node_t ;
typedef struct node dlist_t ;

dlist_t * 
dlist_alloc (int unit)  ;

void
dlist_free (dlist_t * l) ;

int 
dlist_length (dlist_t * l) ;

void
dlist_insert_first (dlist_t * l, void * e) ;

void
dlist_insert_last (dlist_t * l, void * e) ;

int
dlist_remove (dlist_t * l, node_t * n) ;

int
dlist_remove_first (dlist_t * l, void * e) ;

int
dlist_remove_last (dlist_t * l, void * e) ;

int
dlist_get (dlist_t * l, int index, void * e) ;

void
dlist_apply (dlist_t * l1, void (* f)(void * e)) ;
