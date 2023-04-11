#include <cstdlib>
#include <iostream>
#include "progress.h"

long Progression::firstValue () 
{
	cur = first ; 
	return cur ;
}

long Progression::nextValue ()
{
	return ++cur ;
}

void Progression::printProgression (int n)
{
	for (int i = 0 ; i < n ; i++) 
		std::cout << nextValue() << ' ' ;
	std::cout << std::endl ;
}
