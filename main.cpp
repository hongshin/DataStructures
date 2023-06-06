#include <cstdlib>
#include <iostream>
#include <string>
#include "bst.h"

int main ()
{

	char values[12][4] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L"} ;


	BST * t = new BST() ;

	t->insert(44, values[0]) ;
	t->insert(17, values[1]) ;
	t->insert(88, values[2]) ;
	t->insert(32, values[3]) ;
	t->insert(28, values[4]) ;
	t->insert(65, values[5]) ;
	t->insert(97, values[6]) ;
	t->insert(29, values[7]) ;
	t->insert(54, values[8]) ;
	t->insert(82, values[9]) ;
	t->insert(76, values[10]) ;
	t->insert(80, values[11]) ;

	t->print() ;


	//FIXME

	delete t ;

	return 0 ;
}
