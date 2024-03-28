typedef 
	struct {
		void * buffer ;
		int unit ;
		int capacity ;
		int top ;
	} 
	stack_t ;

stack_t * 
create_stack (int capacity, int unit) ;

void
delete_stack (stack_t * stack) ;

int 
push (stack_t * stack, void * elem) ;

int
pop (stack_t * stack, void * elem) ;

int 
is_empty (stack_t * stack) ;

int 
is_full (stack_t * stack) ;

int
get_size (stack_t * stack) ;

int
get_element (stack_t * stack, int index, void * elem) ;
