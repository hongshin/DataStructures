#include <cstdlib>
#include <iostream>
#include <string>

template <typename T>
T genericMin (T a, T b) 
{
	return (a < b) ? a : b ;
}

int main ()
{
	int i0 = 4, i1 = 2 ;
	double r0 = 1.5, r1 = 6.3 ;
	std::string s0("abc"), s1("def") ;

	std::cout << genericMin(i0, i1) << std::endl ;
	std::cout << genericMin(r0, r1) << std::endl ;
	std::cout << genericMin(s0, s1) << std::endl ;

	return 0 ;
}
