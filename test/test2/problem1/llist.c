#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef 
	struct _llist_node_t {
		char * data ;
		struct _llist_node_t * next ;
	} 
	llist_node_t ;

typedef 
	struct {
		llist_node_t * first ;
		int size ;
	}
	llist_t ;


llist_t * create_llist () 
{
	llist_t * l = (llist_t *) malloc(sizeof(llist_t)) ;
	l->first = NULL ;
	l->size = 0 ;
	return l ; 
}

int insert_llist (llist_t * l, char * s)
{
	llist_node_t * n = (llist_node_t *) malloc(sizeof(llist_node_t)) ;
	n->data = s ;
	n->next = NULL ;
	
	if (l->first == NULL) {
		l->first = n ;
		l->size = 1 ;
		return 1 ;
	}

	llist_node_t * last = l->first ;
	while (!(last->next == NULL)) {
		last = last->next ;
	}
	last->next = n ;
	l->size++ ;

	return 1 ;
}

char * delete_llist (llist_t * l, char * s) 
{
	llist_node_t * i ;
	llist_node_t * prev = NULL ; 
	for (i = l->first ; i != NULL ; i = i->next){
		if (strcmp(i->data, s) == 0) {
			break ;
		}
		prev = i ;
	}
	if (i == NULL)
		return NULL ;

	char * r ;
	r = i->data ;
	if (i == l->first) {
		l->first = i->next ;
	}
	else {
		prev->next = i->next ;
	}
	free(i) ;

	return r ;
}

void reverse_llist (llist_t * l)
{
	/*TODO*/
}


void print_llist (llist_t * l)
{
	llist_node_t * i ;
	for (i = l->first ; i != NULL ; i = i->next) {
		printf("%s ", i->data) ;
	}
	printf("\n") ;
}

void free_llist (llist_t * l)
{
	llist_node_t * i ;
	for (i = l->first ; i != NULL ; ) {
		llist_node_t * current = i ;
		i = i->next ;
		free(current) ;
	}
	free(l) ;
}

/*****/

int main ()
{
	llist_t * l = create_llist() ;

	insert_llist(l, "BAT") ;
	insert_llist(l, "CAT") ;
	insert_llist(l, "EAT") ;
	insert_llist(l, "FAT") ;
	insert_llist(l, "GAT") ;
	insert_llist(l, "HAT") ;
	insert_llist(l, "VAT") ;
	insert_llist(l, "WAT") ;
	delete_llist(l, "FAT") ;
	delete_llist(l, "VAT") ;
	print_llist(l) ;

	reverse_llist(l) ;
	print_llist(l) ;

	free_llist(l) ;

	return EXIT_SUCCESS ;
}
