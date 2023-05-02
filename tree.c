/*
typedef 
	struct _tree_node {
		char * elem ;
		struct _tree_node * parent ;
		struct _tree_node * next ; // sibling
		struct _tree_node * child ; // head of the children linked list
	} 
	tree_node ;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

tree_node * tree_alloc (char * s) 
{
	tree_node * t = (tree_node *) malloc(sizeof(tree_node)) ;

	t->elem = strdup(s) ;
	t->parent = NULL ;
	t->next = NULL ;
	t->child = NULL ;

	return t ;
}

void tree_free (tree_node * t)
{
	free(t->elem) ;

	for (tree_node * i = t->child ; i != NULL ; i = i->next) {
		tree_free(i) ;
	}
	free(t) ;
}

tree_node * tree_child_add (tree_node * parent, tree_node * child)
{
	if (child->next != NULL) 
		return NULL ;

	if (parent->child == NULL) {
		parent->child = child ;
		child->parent = parent ;
	}
	else {
		tree_node * last ;
		last = parent->child ;
		while (last->next != NULL) {
			last = last->next ;
		}
		// last->next == NULL
		last->next = child ;
		child->parent = parent ;
	}
	return parent ; 
}

int tree_node_degree (tree_node * t) 
{
	int degree = 0 ;
	
	for (tree_node * i = t->child ; i != NULL ; i = i->next) {
		degree++ ;
	}
	return degree ; 
}

int tree_degree (tree_node * t) 
{
	int max ;

	max = tree_node_degree(t) ;

	for (tree_node * i = t->child ; i != NULL ; i = i->next) {
		int d ;
		d = tree_degree(i) ;
		if (max < d)
			max = d ;
	}
	return max ;  
}

int tree_node_depth (tree_node * t)
{
	int depth = 0 ;

	for (tree_node * i = t ; i->parent != NULL ; i = i->parent) {
		depth++ ;
	}

	return depth ;
}

int tree_height (tree_node * t) 
{
	if (t->child == NULL)
		return 1 ;

	int max = 0 ;
	for (tree_node * i = t->child ; i != NULL ; i = i->next) {
		int height ;
		height = tree_height(i) ;
		if (max < height)
			max = height ;
	}
	return max + 1 ;
}

int tree_contains (tree_node * t, char * s)
{
	if (strcmp(t->elem, s) == 0)
		return 1 ;

	for (tree_node * i = t->child ; i != NULL ; i = i->next) {
		if (tree_contains(i, s)) 
			return 1 ;
	}
	return 0 ; 
}

void tree_travel_preorder (tree_node * t, void (* node_op)(tree_node * n)) 
{
	node_op(t) ;

	for (tree_node * i = t->child ; i != NULL ; i = i->next) {
		tree_travel_preorder(i, node_op) ;
	}
}

void tree_travel_postorder (tree_node * t, void (* node_op)(tree_node * n))
{
	for(tree_node * i = t->child; i != NULL; i = i->next) {

		tree_travel_postorder(i, node_op);
	}

	node_op(t);
}

void tree_print (tree_node * t) 
{
	printf("%s ", t->elem);
	for(tree_node * i = t->child ; i != NULL; i = i->next) {
		tree_print(i);
	}

}
