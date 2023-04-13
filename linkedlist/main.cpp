#include <cstdlib>
#include <iostream>
#include <string>

#include "linkedlist.h"

using namespace std ;

int main ()
{
	string s1("Dropbox") ;
	string s2("Hisnet") ;
	string s3("Google Drive") ;

	LinkedList<string> * l = new LinkedList<string>() ;

	l->addLast(&s1) ;
	l->addLast(&s2) ;
	l->addLast(&s3) ;

	l->print() ;

	string s ;
	l->removeFirst(&s) ;
	cout << s << " was removed." << endl ;

	l->print() ;

	return 0 ;
}
