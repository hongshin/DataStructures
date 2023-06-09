#include <cstdlib>
#include <iostream>
#include <queue>
#include <string>
#include "avltree.h"

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

AVLTree::~AVLTree () 
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

Value AVLTree::find (Key k) 
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


void AVLTree::restructure (Node * z, Node * a, Node * b, Node * c, Node * T0, Node * T1, Node * T2, Node * T3) 
{
	Node * parent = z->parent ;
	Node ** p_z = NULL ;

	if (parent != NULL) {
		if (parent->left == z)
			p_z = &(parent->left) ;
		else
			p_z = &(parent->right) ;
	}
	else {
		p_z = &(this->root) ;
	}

	//FIXME
}


bool AVLTree::insert (Key k, const Value v)
{
	if (this->root == NULL) {
		this->root = new Node(k, v) ;
		this->root->height = 1 ;
		this->root->addLeft(new Node()) ;
		this->root->addRight(new Node()) ;
	}
	else {
		Node * w = this->root ;
		while (w->isInternal()) {
			if (w->k == k)
				return false ;
			if (k < w->k) 
				w = w->left ;
			else 
				w = w->right ;
		}
		w->k = k ;
		w->v = v ;
		w->height = 1 ;
		w->addLeft(new Node()) ;
		w->addRight(new Node()) ;
		

		Node * z, * y, * x ;

		z = w->parent ;
		y = w ;
		x = NULL ;
		do {
			if (z->left->height > z->right->height) {
				z->height = z->left->height + 1 ;
			}
			else {
				z->height = z->right->height + 1 ;
			}

			if (z->left->height - z->right->height == 2 || 
				z->right->height - z->left->height == 2)
				break ;
		
			x = y ;
			y = z ;
			z = z->parent ;
		} while (z != NULL) ;
	
		if (z != NULL) {
			if (z->k < y->k && y->k < x->k) {
				Node * T0, * T1, * T2, * T3 ;

				T0 = z->left ;
				T1 = y->left ;
				T2 = x->left ;
				T3 = x->right ;
				
				restructure(z, z, y, x, T0, T1, T2, T3) ;

			}
			else if (x->k < y->k && y->k < z->k) {
				Node * T0, * T1, * T2, * T3 ;

				T0 = x->left ;
				T1 = x->right ;
				T2 = y->right ;
				T3 = z->right ;

				restructure(z, x, y, z, T0, T1, T2, T3) ;
				
			}
			else if (z->k < x->k && x->k < y->k) {
				Node * T0, * T1, * T2, * T3 ;

				T0 = z->left ;
				T1 = x->left ;
				T2 = x->right ;
				T3 = y->right ;

				restructure(z, z, x, y, T0, T1, T2, T3) ;

			}
			else {
				Node * T0, * T1, * T2, * T3 ;

				T0 = y->left ;
				T1 = x->left ;
				T2 = x->right ;
				T3 = z->right ;

				restructure(z, y, x, z, T0, T1, T2, T3) ;
				
			}
	
		}
	}
	return true ;
}

bool AVLTree::erase (Key k)
{
	//FIXME
	return false ;
}

void AVLTree::print ()
{
	if (this->root != NULL) 
		this->root->print(0) ;
	else
		cout << "(empty)" << endl ;
}
