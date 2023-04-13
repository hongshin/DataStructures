#include <cstdlib>
#include <iostream>

#include "strlist.h"

int main ()
{
	StrList * l = new StrList() ;


	l->addFirst("Dropbox") ;
	l->addFirst("Hisnet") ;
	l->addLast("Google Drive") ;
	
	char * s ;
	l->removeFirst(s) ;
	std::cout << s << " is removed." << std::endl ;

	l->print() ;

	return 0 ;
}
