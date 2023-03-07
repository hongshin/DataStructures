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

/* Lab 1 --*/

int gelist_remove(gelist * l, int i, gentry *e) ;

int gelist_search_by_name(gelist * l, char * name) ;

int gelist_remove_by_name(gelist * l, char * name, gentry * e) ;

gelist * gelist_merge(gelist *l1, gelist *l2) ;

/*-- Lab 1 */
