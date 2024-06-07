#include <stdlib.h>
#include <stdio.h>
#include "bintree.h"

bintree_t * 
bintree_create (int data) 
{
	node_t * root ;
	root = (node_t *) malloc(sizeof(node_t)) ;
	root->data = data ;
	root->left= NULL ;
	root->right = NULL ; 
	return root ;
}

bintree_t *
bintree_add_left (bintree_t * parent, bintree_t * child)
{
	parent->left = child ;
}

bintree_t *
bintree_add_right (bintree_t * parent, bintree_t * child)
{
	parent->right = child ;
}

bintree_t *
bintree_search (bintree_t * t, char key)
{
	if (t->data == key)
		return t ;

	bintree_t * r ;
	r = bintree_search(t->left, key) ;
	if (r != NULL)
		return r ;
	r = bintree_search(t->right, key) ;
	if (r != NULL)
		return r ;
	return NULL ;
}

int
bintree_is_ancestor (bintree_t * t1 /*parent*/, bintree_t * t2/*child*/)
{
	if (t1->left == t2 || t1->right == t2)
		return 1 ;

	if (t1->left) {
		if (bintree_is_ancestor(t1->left, t2))
			return 1 ;
	}
	if (t1->right) {
		if (bintree_is_ancestor(t1->right, t2))
			return 1 ;
	}

	return 0 ;
}

void
bintree_delete (bintree_t * t)
{
	if (t->left) 
		bintree_delete(t->left) ;
	if (t->right)
		bintree_delete(t->right) ;
	free(t) ;
}


int
bintree_height(bintree_t * t) 
{	
	int max_height = 0;

	if (t->left) {
		int height ;
		height = bintree_height(t->left) ;
		if (max_height < height)
			max_height = height ;
	}
	if (t->right) {
		int height ;
		height = bintree_height(t->right) ;
		if (max_height < height)
			max_height = height ;
	}
		
	return max_height + 1 ;
}

int 
bintree_nodes (bintree_t * t) 
{
	/*TODO*/
}

int
bintree_max (bintree_t * t, int * max)
{
	/*TODO*/
}

int 
bintree_is_full (bintree_t * t)
{
	/*TODO*/
}
