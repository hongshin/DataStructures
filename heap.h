typedef struct {
	char * arr ;
	int capacity ;
	int size ;
	size_t usize ;

	int (* cmp)(void *e1, void *e2) ;
} heap_t ;

heap_t * heap_alloc (int capacity, size_t usize, int (* cmp)(void *e1, void *e2)) ;
void heap_free (heap_t * heap) ;

int heap_size (heap_t * heap) ;

int heap_min (heap_t * heap, void * buf) ;
int heap_remove (heap_t * heap, void * buf) ;
int heap_insert (heap_t * heap, void * buf) ;

int heap_delete (heap_t * h, void * e) ;
void heap_print (heap_t * h, char * (* elem_print)(void * e)) ;

