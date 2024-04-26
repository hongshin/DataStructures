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
		llist_node_t * last ;
	}
	llist_t ;


llist_t * create_llist () 
{
	llist_t * l = (llist_t *) malloc(sizeof(llist_t)) ;
	l->last = NULL ;
	return l ; 
}

int insert_llist (llist_t * l, char * s)
{
	llist_node_t * n = (llist_node_t *) malloc(sizeof(llist_node_t)) ;
	n->data = s ;
	n->next = NULL ;
	
	if (l->last == NULL) {
		l->last = n ;
		n->next = n ;
		return 1 ;
	}

	n->next = l->last->next ;
	l->last->next = n ;
	l->last = n ;

	return 1 ;
}

char * delete_llist (llist_t * l, char * s) 
{
	llist_node_t * i ;
	llist_node_t * prev ; 

	if (l->last == NULL)
		return NULL ;

	int found = 0 ;
	prev = l->last ;
	i = l->last->next ;
	do {
		if (strcmp(i->data, s) == 0) {
			found = 1 ;
			break ;
		}
		prev = i ;
		i = i->next ;
	} while (i != l->last->next) ;

	if (found == 0)
		return NULL ;

	char * r ;
	r = i->data ;

	if (i == l->last) {
		if (l->last == l->last->next) {
			l->last = NULL ;
		}
		else {
			prev->next = l->last->next ;
			l->last = prev ;
		}
	}
	else {
		prev->next = i->next ;
	}
	free(i) ;

	return r ;
}

void print_llist (llist_t * l)
{
	if (l->last == NULL)
		return ;

	llist_node_t * i ;

	i = l->last->next ;
	do {
		printf("%s ", i->data) ;

		i = i->next ;
	} while (i == l->last->next) ;
	printf("\n") ;

}

void free_llist (llist_t * l)
{
	/*TODO*/
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

	free_llist(l) ;

	return EXIT_SUCCESS ;
}
