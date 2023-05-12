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
	Node* temp = this;

	while (temp != NULL)
	{
		if (temp->parent == n)
			return true;

		temp = temp->parent;
	}

	return false;

}

/*
bool Node::isDescendant (Node * n)
{
	if (this->left == n || this->right == n) 
		return true;
	if (this->left && this->left->isDescendant(n)){
		return true;
	}
	if (this->right && this->right->isDescendant(n)){
		return true;
	}
	return false ;
}
*/

bool Node::isDescendant (Node * n) // Ver 2
{
	for(Node * node = n; n != NULL; n = n->parent) {
		if(n == this)
			return true;
	}
	return false;
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
	queue<Node*> nodes;

	if (this->root == NULL)
		return true ;

	nodes.push(this->root);
	while(nodes.size()>0){
		Node * n = nodes.front() ;
		nodes.pop() ;

		if (n->left)
			nodes.push(n->left) ;
		if (n->right)
			nodes.push(n->right) ;

		if(n->left && n->left->parent != n )
			return false;
		if(n->right && n->right->parent != n)
			return false;

	}
	return false ; //FIXME
}

bool Tree::isProper ()
{
	queue<Node*> nodes;
	nodes.push(this->root);

	while(nodes.size() > 0) {
		Nodes * n = nodes.front();
		nodes.pop();

		if((n->left == NULL && n->right != NULL) ||
		   (n->left != NULL && n->right == NULL))
			return false;

		if(n->left)
			nodes.push(n->left);

		if(n->right)
			nodes.push(n->right); 
	}
	return true ; //FIXME
}

bool Tree::isFull ()
{
	return false ;
}

bool Tree::isComplete () 
{
	queue<Node*> nodes;
	nodes.push(this->root);

	int state = 2 ;

	while(nodes.size() > 0) {
		Nodes * n = nodes.front();
		nodes.pop();

		if(n->left)
			nodes.push(n->left);
		if(n->right)
			nodes.push(n->right); 
		
		int n_degree = 0 ;
		if (n->left) 
			n_degree++ ;
		if(n->right)
			n_degree++ ;

		if (n->left == NULL && n->right != NULL)
			return false ;

		if (state == 2) {
			state = n_degree ;
		}
		else if (state == 1) {
			if (n_degree == 2) {
				return false ;
			}
			else if (n_degree == 1) {
				return false ;
			}
			else { /* n_degree == 0 */
				state = 0 ;
			}
		}
		else { /* state == 0 */
			if (n_degree == 2 || n_degree == 1) {
				return false ;
			}
			else {
				state = 0 ; 
			}
		}
	}

	return true ;
}


/*
bool Tree::isComplete ()
{
	queue<Node *> nodes ;
	queue<Node *> ids ;

	
	nodes.push(this->root) ;
	ids.push(1) ;

	int last_id = 0 ;
	while (nodes.size() > 0) {
		Node * n = nodes.front() ;
		nodes.pop() ;

		int n_id = ids.front() ;
		ids.pop() ;

		if (last_id != n_id - 1)
			return false ;

		if (n->left) {
			nodes.push(n->left) ;
			ids.push(n_id * 2) ;
		}
		if (n->right) {
			nodes.push(n->right) ;
			ids.push(n_ids * 2 + 1) ;
		}
	}
	return true ;
}
*/



int Tree::numNodes () 
{
	if(this->root == 0x0)
		return 0 ; 

	queue<Node *> nodes ;

	int num = 0; 

	nodes.push(this->root) ; num++ ;

	while (nodes.size() > 0) {
		Node * n = nodes.front() ;
		nodes.pop() ;

		if(n->left){
			nodes.push(n->left) ; 
			num++ ;
		}
		if(n->right){
			nodes.push(n->right) ;
			num++ ;
		}
	}

	return num ;
}

/*
int Tree::height ()
{
	queue<Node *> nodes ;
	queue<Node *> heights ;

	int maxHeight = 1;
	
	nodes.push(this->root) ;
	heights.push(1) ;

	while (nodes.size() > 0) {
		Node * n = nodes.front() ;
		nodes.pop() ;
		int n_height = heights.front() ; height.pop() ;

		if (! (n_height < maxHeight))
			maxHeight = n_height ;

		if (n->left) {
			nodes.push(n->left) ;
			heights.push(n_height + 1) ;
		}
		if (n->right) {
			nodes.push(n->right) ;
			heights.push(n_height + 1) ;
		}
	}
	return maxHeight ;
}
*/

int Tree::height () // Version 2
{
	queue<Node *> nodes ;

	if (this->root == NULL)
		return 0 ;

	Node * last ;

	nodes.push(this->root) ;
	while (nodes.size() > 0) {
		Node * n = nodes.front() ;
		nodes.pop() ;

		if (n->left) {
			nodes.push(n->left) ;
			heights.push(n_height + 1) ;
		}
		if (n->right) {
			nodes.push(n->right) ;
			heights.push(n_height + 1) ;
		}
		last = n ;
	}

	int height = 1 ;
	for ( ; last != 0x0 ; last = last->parent) {
		height++ ;
	}

	return maxHeight ;
}
