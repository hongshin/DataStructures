#include <cstdlib>
#include <iostream>
#include "progress.h"
#include "arithprog.h"
#include "fibonacci.h"

int main ()
{
	ArithProgression * a = new ArithProgression(1) ;
	a->printProgression(5) ;

	FibonacciProgression * f = new FibonacciProgression(2, 3) ;
	f->printProgression(5) ;

	Progression * p = new FibonacciProgression(2, 3) ;
	p->printProgression(5) ;

	return 0 ;
}
