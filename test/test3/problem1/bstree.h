#include <stdlib.h>

struct _bst_node_t {
	char * data ;
	struct _bst_node_t * left ;
	struct _bst_node_t * right ;
	struct _bst_node_t * parent ;
} ;
typedef struct _bst_node_t bst_node_t ;

struct _bst_t {
	bst_node_t * root ;
	size_t usize ;
	int (* cmp)(void * e1, void * e2) ;
} ;
typedef struct _bst_t bst_t ;

bst_t * 
bst_create (size_t usize, int (* cmp)(void *e1, void *e2)) ;

int
bst_insert (bst_t * t, void * data) ;

int
bst_search (bst_t * t, void * data) ;

int
bst_to_array (bst_t * t, void * arr, int len) ;

int
bst_remove (bst_t * t, void * data) ;

void
bst_print (bst_t * t, void (* print)(void * data)) ;

void
bst_free (bst_t * t) ;
