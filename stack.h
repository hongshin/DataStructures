typedef 
    struct _stack {
        list * list ;
    }
    stack ;

stack * stack_alloc (size_t elem_size) ;

void stack_free (stack * s) ;

int stack_push (stack * s, void * elem) ;

int stack_pop (stack * s, void * dest) ;

int stack_top (stack * s, void * dest) ;

int stack_size (stack * s) ;

int stack_empty (stack * s) ;
