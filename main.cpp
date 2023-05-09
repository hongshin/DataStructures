#include <cstdlib>
#include <iostream>
#include "bintree.h"

int main ()
{
	Node * n1 = new Node(1) ;
	Node * n2 = new Node(2) ;
	Node * n3 = new Node(3) ;
	Node * n4 = new Node(4) ;
	Node * n5 = new Node(5) ;
	Node * n6 = new Node(6) ;
	Node * n7 = new Node(7) ;
	Node * n8 = new Node(8) ;

	n1->addLeft(n2) ;
	n1->addRight(n3) ;

	n2->addLeft(n4) ;
	n2->addRight(n5) ;
	n3->addLeft(n6) ;
	n3->addRight(n7) ;
	n4->addLeft(n8) ;

	Tree * t1 = new Tree(n1) ;

	delete t1 ;

	return 0 ;
}
