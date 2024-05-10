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
	if (parent->down == NULL) {
		parent->down =child ;
		return parent ;
	}

	tree_t * last ;
	
	for (last = parent->down ; 
		 last->next != NULL ;
		 last = last->next) ;
	// assert last->next == NULL 
	last->next = child ;

	return parent ;
}

tree_t *
tree_search (tree_t * t, char key)
{
	if (t->data == key) {
		return t ;
	}

	tree_t * i ;
	for (i = t->down ; i != NULL ; i = i->next) {
		tree_t * r ;
		r = tree_search(i, key) ;
		if (r)
			return r ;
	}
	return NULL ;
}

void
tree_delete (tree_t * t)
{
	if (t->down)
		tree_delete(t->down)  ;
	if (t->next)
		tree_delete(t->next) ;
	free(t) ;
}


int
tree_height(tree_t * t) 
{
	/*TODO*/
	int max_height = 0;

	tree_t* sub_t;
	for(sub_t = t->down; sub_t != NULL; sub_t = sub_t->next){
		int height = tree_height(sub_t);
		if(max_height < height){
			max_height = height;
		}
	}
	return max_height + 1;
}

int
tree_degree (tree_t* t){
	int d = 0;

	tree_t* sub_t;
	for(sub_t = t->down; sub_t != NULL; sub_t = sub_t->next){
		d++;
	}
	for(sub_t = t->down; sub_t != NULL; sub_t = sub_t->next){
		int s_d = tree_degree(sub_t);
		if(d < s_d){
			d = s_d;
		}
	}

	return d;
}


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

