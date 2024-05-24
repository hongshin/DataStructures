typedef struct {
	char * arr ;
	int capacity ;
	int size ;
	size_t usize ;

	int (* cmp)(void *e1, void *e2) ;

} heap_t ;

heap_t *
heap_create (int capacity, size_t usize, int (* cmp)(void *e1, void *e2)) ;

void
heap_free (heap_t * heap) ;

int
heap_size (heap_t * heap) ;

int
heap_top (heap_t * heap, void * buf) ;

int
heap_pop (heap_t * heap, void * buf) ;

int
heap_push (heap_t * heap, void * buf) ;
