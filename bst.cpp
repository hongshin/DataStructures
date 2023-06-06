#include <cstdlib>
#include <iostream>
#include <queue>
#include <string>
#include "bst.h"

using namespace std ;

typedef int Key ;
typedef char * Value ;


Node::Node (Key k, Value v) 
{
	this->k = k ;
	this->v = v ;
	this->parent = NULL ;
	this->left = NULL ;
	this->right = NULL ;
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

bool Node::isInternal () 
{	
	if (this->left != NULL && this->right != NULL)
		return true ;
	return false;
}

void Node::print (int indent)
{
	if (this->left == NULL && this->right == NULL)
		return ;

	int i ;
	for (i = 0 ; i < indent ; i++) 
		cout << "    " ; 
	cout << "(" << this->k << ", " << this->v << ") {" << endl ;

	this->left->print(indent + 1) ;
	this->right->print(indent + 1) ;

	for (i = 0 ; i < indent ; i++) 
		cout << "    " ;
	cout << "}" << endl ;
}

BST::~BST () 
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

Value BST::find (Key k) 
{
	Node * i = this->root ;

	while (i->isInternal()) {
		if (i->k == k) {
			return i->v ;
			
		}
		if (k < i->k) {
			i = i->left ;
		}
		else {
			i = i->right ;
		}
	}
	return NULL ;
}

bool BST::erase (Key k)
{
	//FIXME
	return false ;
}

bool BST::insert (Key k, const Value v)
{
	if (this->root == NULL) {
		this->root = new Node(k, v) ;
		this->root->addLeft(new Node()) ;
		this->root->addRight(new Node()) ;
		this->nNodes = 3 ;
	}
	else {
		Node * i = this->root ;

		while (i->isInternal()) {
			if (i->k == k)
				return false ;
			if (k < i->k) 
				i = i->left ;
			else 
				i = i->right ;
		}

		i->k = k ;
		i->v = v ;
		i->addLeft(new Node()) ;
		i->addRight(new Node()) ;
		this->nNodes += 2 ;
	}

	this->nNodes++ ;

	return true ;
}

void BST::print ()
{
	if (this->root != NULL) 
		this->root->print(0) ;
}
