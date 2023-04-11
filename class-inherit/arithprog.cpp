#include <cstdlib>
#include <iostream>
#include "progress.h"
#include "arithprog.h"

ArithProgression::ArithProgression (long i) : Progression(), inc(i) 
{ 
}

long ArithProgression::nextValue ()
{
	cur += inc ;
	return cur ;
}
