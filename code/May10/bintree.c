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

}

bintree_t *
bintree_add_right (bintree_t * parent, bintree_t * child)
{

}

bintree_t *
bintree_search (bintree_t * t, char key)
{

}

int
bintree_is_ancestor (bintree_t * t1 /*parent*/, bintree_t * t2/*child*/)
{

}

void
bintree_delete (bintree_t * t)
{

}


int
bintree_height(bintree_t * t) 

}


void
bintree_print (bintree_t * t)
// L V R

{

}






