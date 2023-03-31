typedef struct _list {
	size_t elem_size ;
	void * d ;

	void (* free)(struct _list * l) ;
	int (* add)(struct _list * l, void * s) ;
	int (* remove)(struct _list * l, int i, void * s) ;
    int (* get)(struct _list * l, int i, void * s) ;
    int (* size)(struct _list * l) ;
	void (* print)(struct _list * l, void (* elem_print)(void *s)) ;
} list ;
