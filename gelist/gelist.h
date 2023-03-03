typedef struct {
	char * name ;
	int score ;
} gentry ;

typedef struct {
	int max_entries ;
	int num_entries ;
	gentry * entries ;
} gelist ;

gelist * gelist_alloc (int n) ;

void gelist_free(gelist * l) ;

int gelist_get (gelist * l, int i, gentry * e) ;

int gelist_add (gelist * l, gentry e) ;

int gelist_remove (gelist * l, int i, gentry * e) ;

void gelist_print (gelist * l) ;
