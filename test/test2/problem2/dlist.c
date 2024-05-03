#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dlist.h"

dlist_t * 
dlist_alloc (int unit) 
{
	dlist_t * l = (dlist_t *) malloc(sizeof(dlist_t)) ;
	l->left = l  ;	
	l->right = l ;
	l->element = malloc(sizeof(int)) ;
	int * u = (int *) l->element ;
	*u = unit ;

	return l ;
}

void
dlist_free (dlist_t * l)
{
	node_t * curr ;
	node_t * next ;

	curr = l->right ;
	while (curr != l) {
		next = curr->right ;
		free(curr->element) ;
		free(curr) ;
		curr = next ;
	}
	free(l->element) ;
	free(l) ;
}

int 
dlist_length (dlist_t * l)
{
	int len = 0 ;

	node_t * curr = l->right ;
	while (curr != l) {
		len += 1 ;
		curr = curr->right ; 
	}
	return len ; 
}

void 
dlist_insert (node_t * left, void * e, int unit)
{
	node_t * _new = (node_t *) malloc(sizeof(node_t)) ;
	_new->element = malloc(unit) ;
	memcpy(_new->element, e, unit) ;

	node_t * right = left->right ;

	_new->left = left ;
	_new->right = right ;

	left->right = _new ;
	right->left = _new ;
}

void
dlist_insert_first (dlist_t * l, void * e)
{
	dlist_insert(l, e, *((int *)(l->element))) ;
}

void
dlist_insert_last (dlist_t * l, void * e)
{
	dlist_insert(l->left, e, *((int *)(l->element))) ;
}

int
dlist_insert_at (dlist_t * l, int index, void * e)
{
	/* TODO */
	if(index < 0){
		return 0;
	}
	node_t* curr=l->right;
	int i = 0;
	for(i = 0; i < index; i++){
		curr = curr->right;
	}

	node_t* new = (node_t*)malloc(sizeof(node_t));
	new->element = malloc(sizeof(*(int*)l->element));
	memcpy(new->element, e, *(int*)l->element);
	new->left = curr->left->right;
	new->right = curr;

	curr->left->right = new;
	curr->left = new;
	
	return 1;
}

int
dlist_remove (dlist_t * l, node_t * n)
{
	if (l->left == l)
		return 0 ;

	n->left->right = n->right ;
	n->right->left = n->left ;

	free(n->element) ;
	free(n) ;
	return 1 ;
}

int 
dlist_remove_first (dlist_t * l, void * e)
{
	if (l->right == l)
		return 0 ;

	memcpy(e, l->right->element, *((int *)(l->element))) ;
	dlist_remove(l, l->right) ;
	return 0 ;
}

int
dlist_remove_last (dlist_t * l, void * e)
{
	if (l->left == l)
		return 1 ;

	memcpy(e, l->left->element, *((int *)(l->element))) ;
	dlist_remove(l, l->left) ;
	return 1 ;
}

int
dlist_remove_at (dlist_t * l, int index, void * e)
{
	/* TODO */
	if(index < 0){
		return 0;
	}
	node_t* curr=l->right;
	int i = 0;
	for(i = 0; i < index; i++){
		curr = curr->right;
	}
	memcpy(e, curr->element, (*(int*)l->element));
	curr->left->right = curr->right;
	curr->right->left = curr->left;
	free(curr->element);
	free(curr);
	return 1;
}


void
dlist_apply (dlist_t * l, void (* func)(void * e)) 
{
	node_t * i ;

	for (i = l->right ; i != l ; i = i->right) {
		func(i->element) ;
	}
}
