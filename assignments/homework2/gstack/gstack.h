typedef 
	struct {
		void * buffer ;
		int unit ;
		int capacity ;
		int size ;
	} 
	gstack_t ;

gstack_t * 
create_stack (int capacity, int unit) ;

void
delete_stack (gstack_t * stack) ;

int 
push (gstack_t * stack, void * elem) ;

int
pop (gstack_t * stack, void * elem) ;

int 
is_empty (gstack_t * stack) ;

int 
is_full (gstack_t * stack) ;

int
get_size (gstack_t * stack) ;

int
get_element (gstack_t * stack, int index, void * elem) ;
