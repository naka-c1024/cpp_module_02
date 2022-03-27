#include "Fixed.hpp"
#include <iostream>

int main( void ) {

	Fixed a;
	Fixed b( a ); // Copy constructor, Fixed b = a;
	Fixed c;

	c = b; // Copy assignment operator

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}
