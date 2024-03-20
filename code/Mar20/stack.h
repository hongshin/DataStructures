typedef 
	struct {
		int * buffer ;
		int capacity ;
		int top ;
	} 
	stack_t ;

stack_t * 
create_stack (int capacity) ;

void
delete_stack (stack_t * stack) ;

int 
push (stack_t * stack, int elem) ;

int
pop (stack_t * stack, int * elem) ;

int 
is_empty (stack_t * stack) ;

int 
is_full (stack_t * stack) ;

int
get_size (stack_t * stack) ;


