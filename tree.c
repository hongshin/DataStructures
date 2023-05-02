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
}

void tree_free (tree_node * t) 
{
	if (t->next)
		tree_free(t->next) ;

	if (t->child)
		tree_free(t->child) ;

	free(t->elem) ;
	free(t) ;
}

tree_node * tree_child_add (tree_node * parent, tree_node * child) 
{
	if (parent->child == NULL) {
		parent->child = child ;
	}
	else {
		tree_node * t = parent->child ;
		while (t->next != NULL) {
			t = t->next ;
		}
		t->next = child ; 
	}
	child->parent = parent ;

	return parent ; 
}

int tree_node_degree (tree_node * t) 
{
	int d = 0 ;
	tree_node * i = t->child ;
	while (i != NULL) {
		d++ ;
		i = i->next ;
	}
	return d ;
}

int tree_degree (tree_node * t)
{
	int max, d ;

	max = tree_node_degree(t) ;

	if (t->next) {
		d = tree_degree(t->next) ;
		if (d > max)
			max =d ;
	}
	if (t->child) {
		d = tree_degree(t->child) ;
		if (d > max)
			max = d ;
	}
	return max ;
}

int tree_node_depth (tree_node * t) 
{
	int depth = 0 ;
	tree_node * a ; 
	a = t->parent ;
	while (a != NULL) {
		depth++ ;
		a = a->parent ;
	}
	return depth ;
}

int tree_height (tree_node * t) 
{
	if (t->child == NULL)
		return 1 ;
	
	int max = 0 ;
	for (tree_node * i = t->child ; i != NULL ; i = i->next) {
		int h = tree_height(i) ;
		if (h > max)
			max = h ;
	}
	return max + 1 ;
}

int tree_contains (tree_node * t, char * s)
{
	if (strcmp(t->elem, s) == 0)
		return 1 ;

	if (t->child) {
		for (tree_node * i = t->child ; i != NULL ; i = i->next) {
			if (tree_contains(i, s))
				return 1 ;
		}
	}

	return 0 ;
}

void tree_visit_preorder (tree_node * t, void (* node_op)(tree_node * n))
{
	node_op(t) ;

	if (t->child) {
		for (tree_node * i = t->child ; i != NULL ; i = i->next) {
			tree_visit_preorder(i, node_op) ;
		}
	}
}


void tree_print (tree_node * t) 
{
	printf("%s", t->elem) ;
	
	if (t->child == NULL)
		return ;

	printf("(") ;
	for (tree_node * i = t->child ; i != NULL ; i = i->next) {
		tree_print(i) ;
		if (i->next != NULL)
			printf(", ") ;
	}
	printf(")") ;
}

