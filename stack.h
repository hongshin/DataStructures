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

int stack_contains (stack * s, void * elem2, int (* equal)(void * p1, void * p2)) ;

void stack_print (stack * s, void (* print_elem)(void *p)) ;

int stack_size (stack * s) ;

int stack_empty (stack * s) ;
