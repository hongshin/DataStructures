struct arraylist {
	int capacity ;
	int length ;
	int unit ;
	void * elements ;
} ;

typedef struct arraylist arraylist_t ;

arraylist_t * 
arraylist_alloc (int unit)  ;

void
arraylist_free (arraylist_t * l, void (* free_element)(void * e)) ;

int 
arraylist_length (arraylist_t * l) ;

void
arraylist_print (arraylist_t * l, void (* print_element)(void * e)) ;

void
arraylist_insert_first (arraylist_t * l, void * e) ;

void
arraylist_insert_last (arraylist_t * l, void * e) ;

int 
arraylist_remove_first (arraylist_t * l, void * e) ;

int 
arraylist_remove_last (arraylist_t * l, void * e) ;

int
arraylist_get (arraylist_t * l, int pos, void * e) ;

void
arraylist_sort (arraylist_t * l, int (* cmp_elements)(void * e1, void * e2)) ;

void
arraylist_qsort (arraylist_t * l, int (* cmp_elements)(void * e1, void * e2)) ;
