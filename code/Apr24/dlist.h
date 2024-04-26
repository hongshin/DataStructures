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

int
dlist_remove_at (dlist_t * l, int index) ;

int
dlist_append (dlist_t * l1, dlist_t * l2) ;
