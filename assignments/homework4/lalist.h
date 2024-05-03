typedef 
	struct _lalist_node {
		void * arr ;
		int n_elem ;
		struct _lalist_node * next ;
	} 
	lalist_node_t ;

typedef 
	struct {
		int arr_cap ;
		int elem_size ;
		lalist_node_t * first ;
	} 
	lalist_t ;

lalist_t *
lalist_alloc (int arr_cap, int elem_size)  ;

void
lalist_free (lalist_t * l) ;

int 
lalist_length (lalist_t * l) ;

void
lalist_insert_first (lalist_t * l, void * e) ;

void
lalist_insert_last (lalist_t * l, void * e) ;

int
lalist_insert_at (lalist_t * l, int idx, void * e) ;

int
lalist_remove_first (lalist_t * l, void * e) ;

int
lalist_remove_last (lalist_t * l, void * e) ;

int
lalist_remove_at (lalist_t * l, int idx, void * e) ;

void
lalist_apply (lalist_t * l1, void (* f)(void * e)) ;

void 
lalist_info (lalist_t * l) ;

void
lalist_pack (lalist_t * l) ;
