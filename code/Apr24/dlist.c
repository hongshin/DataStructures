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
	//header랑 바로 앞에 node사이에 끼어넣는 로직임
	node_t * _new = (node_t *) malloc(sizeof(node_t)) ;
	_new->element = malloc(unit) ;
	memcpy(_new->element, e, unit) ;

	node_t * right = left->right ; //원래 헤더 바로 앞에 있던얘

	_new->left = left ;
	_new->right = right ;

	left->right = _new ;
	right->left = _new ;
}

void
dlist_insert_first (dlist_t * l, void * e) //맨앞에 새로운 노드 삽입
{
	dlist_insert(l, e, *((int *)(l->element))) ;
	//l->element가 가리키는 메모리를 int로 해석하여 그 값을 가져오는 것입니다. 
}

void
dlist_insert_last (dlist_t * l, void * e)
{
	dlist_insert(l->left, e, *((int *)(l->element))) ; //제일 끝의 노드를 줌

	// node_t * right = left->right ;  //llist를 가리킴 
	// _new->left = left ;	//새로운노드의 왼쪽은 원래리스트의 맨끝을 가리킴
	// _new->right = right ; //새노드의 오른쪽은 llist를 가리킴

	// left->right = _new ; 
	// right->left = _new ;
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
	return 1;
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
dlist_get (dlist_t * l, int index, void * e)
/* 
 * copies the data at the given index ``index``, if exists, to ``e``, and returns 1.
 * if not exists, return 0.
 */
{
	if (index < 0)
		return 0 ;

	node_t * n = l->right ;
	int i = 0 ; 

	for (i = 0 ; i < index ; i++) {
		n = n->right ;
		if (n == l) {
			return 0 ;
		}
	}
	
	memcpy(e, n->element, *((int *) l->element)) ;
	return 1 ;
}

int 
dlist_remove_at (dlist_t * l, int index)
/*
 * removes the node at the given index ``index``, if exists, and returns 1.
 * if not exists, return 0.
 */
{
	if (index < 0)
		return 0 ;

	node_t * n = l->right ;
	int i = 0 ; 

	for (i = 0 ; i < index ; i++) {
		n = n->right ;
		if (n == l) {
			return 0 ;
		}
	}

	n->left->right = n->right ;
	n->right->left = n->left ;
	free(n->element) ;
	free(n) ;
	return 1 ;
}

int 
dlist_append (dlist_t * l1, dlist_t * l2)
/*
 * add all elements in ``l2`` to ``l1``, in their order in ``l2``.
 * return the number of added elements.
 */

{
	node_t * i2 ;
	for (i2 = l2->right ; i2 != l2 ; i2 = i2->right) {
		
		node_t * _new = malloc(sizeof(node_t)) ; //노드하나 만들고
		_new->element = malloc(sizeof(*((int *)(l2->element)))) ;
		memcpy(_new->element, i2->element, *((int *)l2->element)) ; //거기에 i2 element 복사

		//l1이랑 연결
		_new->left = l1->left ; 
		_new->right = l1 ;

		l1->left->right = _new ;
		l1->left = _new ;

	}

}










