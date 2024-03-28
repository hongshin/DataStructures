typedef 
	struct {
		int * buffer ;
		int capacity ;
		int size ;
	} 
	stack_t ;

stack_t * 
create_stack (int capacity) ;

void
delete_stack (stack_t * st) ;

int 
push (stack_t * st, int elem) ;

int
pop (stack_t * st, int * elem) ;

int 
is_empty (stack_t * st) ;

int 
is_full (stack_t * st) ;

int
get_size (stack_t * st) ;

int
get_element (stack_t * st, int index, int * elem) ;

void
print_stack (stack_t * st) ;
