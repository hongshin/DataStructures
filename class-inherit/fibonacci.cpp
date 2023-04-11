#include <cstdlib>
#include <iostream>
#include "progress.h"
#include "fibonacci.h"

FibonacciProgression::FibonacciProgression (long f, long s)
	: Progression(f), second(s)
{
	prev = second - first ;
}

long FibonacciProgression::firstValue ()
{
	cur = first ;
	prev = second - first ;
	return cur ;
}

long FibonacciProgression::nextValue ()
{
	long _prev = prev ;
	long _cur = cur ;
	prev = cur ;
	cur += _prev ;
	return _cur ;
}

void FibonacciProgression::printProgression (int n)
{
	std::cout << "hello" << std::endl ;
}
