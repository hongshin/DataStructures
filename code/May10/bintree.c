#include <stdlib.h>
#include <stdio.h>
#include "bintree.h"

bintree_t * 
bintree_create (char data) 
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
	/*TODO*/
	parent->left = child;
	return parent;
}

bintree_t *
bintree_add_right (bintree_t * parent, bintree_t * child)
{
	/*TODO*/
	parent->right = child;
	return parent;
}

bintree_t *
bintree_search (bintree_t * t, char key)
{
	/*TODO*/
	if(t->data == key){
		return t;
	}
	bintree_t* curr;
	curr = bintree_search(t->left,key);
	if(curr != NULL)
		return curr;
	curr = bintree_search(t->right,key);
	if(curr != NULL)
		return curr;
	return NULL;
}

int
bintree_is_ancestor (bintree_t * parent, bintree_t * child)
{
	/*TODO*/
	if(parent->left == child || parent->right == child){
		return 1;
	}
	if(parent->left){
		if(bintree_is_ancestor(parent->left, child))
			return 1;
	}
	if(parent->right){
		if(bintree_is_ancestor(parent->right, child))
			return 1;
	}
	return 0;
}

void
bintree_delete (bintree_t * t)
{
	/*TODO*/
	if(t->left)
		bintree_delete(t->left);
	if(t->right)
		bintree_delete(t->right);
	free(t); 
}


int
bintree_height(bintree_t * t) 
{
	/*TODO*/
	int max_height = 0;
	if(t->left){
		int height;
		height = bintree_height(t->left);
		if(max_height < height){
			max_height = height;
		}
	}
	if(t->right){
		int height;
		height = bintree_height(t->right);
		if(max_height < height){
			max_height = height;
		}
	}
	return max_height+1;
}


void
bintree_print (bintree_t * t)
{
	/*TODO*/
	//VLR 
	printf("%c", t->data);
	printf("(");
	if(t->left){
		bintree_print(t->left);
	}
	printf(",");
	if(t->right){
		bintree_print(t->right);
	}
	printf(")");
	//LVR
	// printf("(");
	// if(t->left){
	// 	bintree_print(t->left);
	// }
	// printf(",");
	// printf("%c", t->data);
	// printf(",");
	// if(t->right){
	// 	bintree_print(t->right);
	// }
	// printf(")");
}

