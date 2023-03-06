typedef struct _strlist_node {
	char * elem ;
	struct _strlist_node * next ;
} strlist_node ; 


typedef struct {
	strlist_node * head ;
} strlist ;

strlist * strlist_alloc () ;

void strlist_free (strlist * l) ;

int strlist_add_first (strlist * l, char * s) ;

int strlist_remove_first (strlist * l, char ** s) ;

void strlist_print (strlist * l) ;
