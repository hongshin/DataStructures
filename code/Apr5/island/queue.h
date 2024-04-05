typedef 
	struct {
		void * buffer ;
		int unit ;

		int front ;
		int rear ;

		int capacity ;
		int size ;
	} 
	gqueue_t ;

gqueue_t * 
create_queue (int capacity, int unit) ;

void
delete_queue (gqueue_t * queue) ;

int 
enqueue (gqueue_t * queue, void * elem) ;

int
dequeue (gqueue_t * queue, void * elem) ;

int
front (gqueue_t * queue, void * elem) ;

int 
is_empty (gqueue_t * queue) ;

int 
is_full (gqueue_t * queue) ;

int
get_size (gqueue_t * queue) ;

int 
get_elem (gqueue_t * queue, int i, void * elem) ;
