#include <cstdlib>
#include <iostream>
#include <queue>
#include "bintree.h"

typedef int Elem ;

using namespace std ;

Node::Node (Elem e) 
{
	this->elem = e ;
	this->parent = NULL ;
	this->left = NULL ;
	this->right = NULL ;
}

Node::~Node ()
{
}

bool Node::addLeft (Node * n) 
{
	if (this->left != NULL)
		return false ;

	n->parent = this ;
	this->left = n ;
	return true ;
}

bool Node::addRight (Node * n) 
{
	if (this->right != NULL)
		return false ;

	n->parent = this ;
	this->right = n ;
	return true ;
}

bool Node::isAncestor (Node * n) 
{	
	return false ; //FIXME
}

bool Node::isDescendant (Node * n) 
{
	return false ; //FIXME
}

Tree::Tree (Node * n) 
{
	this->root = n ; 
}

Tree::~Tree () 
{
	queue<Node *> nodes ;

	nodes.push(this->root) ;

	while (nodes.size() > 0) {
		Node * n = nodes.front() ;
		nodes.pop() ;

		if (n->left)
			nodes.push(n->left) ;
		if (n->right)
			nodes.push(n->right) ;

		delete n ;
	}
}

bool Tree::isValid ()
{
	return false ; //FIXME
}

bool Tree::isProper ()
{
	return false ; //FIXME
}

bool Tree::isFull ()
{
	return false ; //FIXME
}

bool Tree::isComplete () 
{
	return false ; //FIXME
}

int Tree::height ()
{
	return 0 ; //FIXME
}

int Tree::numNodes () 
{
	return 0 ; //FIXME
}
