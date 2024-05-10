#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

tree_t * 
tree_create (char data) 
{
	node_t * root ;
	root = (node_t *) malloc(sizeof(node_t)) ;
	root->data = data ;
	root->down = NULL ;
	root->next = NULL ; 
	return root ;
}

tree_t *
tree_add_child (tree_t * parent, tree_t * child)
{
	/*TODO*/
	
}

tree_t *
tree_search (node_t * t, char key)
{
	/*TODO*/
	

int
tree_height(tree_t * t) 
{
	/*TODO*/
	tree_t * st;
	int max = 0;
	for(st->down;st!=null;st=st->next);
	int h;
	h = tree_height(st);
	if (max<h)
		max = h ;
}
return max + 1 ;

int tree_degree (tree_t * t)
{	
	int d = 0;
	tree_t * s;
	for(s->down;s!=null;s=s->next);{
	d++;
	}
	for(s->down;s!=null;s=s->next);{
	int s_d;
	}
	s_d = tree_degree(s);
	if (d<s_d) {
		d = s_d ;
	}
}
return d ;

void
tree_print (tree_t * t)
{
	printf("%c", t->data) ;
	if (t->down) {
		printf("(") ;
		tree_print(t->down) ;
		printf(")") ;
	}
	if (t->next) {
		printf("-") ;
		tree_print(t->next) ;
	}
}

void
tree_delete (tree_t * t)
{
	/*TODO*/
	
}
