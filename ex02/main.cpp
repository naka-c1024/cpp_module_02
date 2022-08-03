#include "Fixed.hpp"
#include <iostream>

void	my_tests(void)
{
	std::cout << "\n-- my tests --" << std::endl;
	Fixed	num1 = Fixed(6);
	Fixed	num2 = Fixed(3);

	std::cout << "num1: " << num1
		<< ", num2: " << num2 << std::endl;

	std::cout << "== : " << (num1 == num2) << std::endl;
	std::cout << "!= : " << (num1 != num2) << std::endl;
	std::cout << "< : " << (num1 < num2) << std::endl;
	std::cout << "> : " << (num1 > num2) << std::endl;
	std::cout << "<= : " << (num1 <= num2) << std::endl;
	std::cout << ">= : " << (num1 >= num2) << std::endl;

	std::cout << "+ : " << (num1 + num2) << std::endl;
	std::cout << "- : " << (num1 - num2) << std::endl;
	std::cout << "* : " << (num1 * num2) << std::endl;
	std::cout << "/ : " << (num1 / num2) << std::endl;

	std::cout << "num1++ : " << num1++ << std::endl;
	std::cout << "++num1 : " << ++num1 << std::endl;
	std::cout << "num1-- : " << num1-- << std::endl;
	std::cout << "--num1 : " << --num1 << std::endl;

	std::cout << "normal min : " << Fixed::min(num1, num2) << std::endl;
	std::cout << "normal max : " << Fixed::max(num1, num2) << std::endl;

	Fixed const num3( 42 );
	Fixed const num4( 24 );
	std::cout << "const min : " << Fixed::min(num3, num4) << std::endl;
	std::cout << "const max : " << Fixed::max(num3, num4) << std::endl;

	// Fixed	num5 = Fixed(0);
	// std::cout << "/ : " << (num1 / num5) << std::endl; // 0除算
}

int main( void ) {

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl; // staticだからインスタンス化せずに使える
	// bがconstだからconstなmaxが発火

	my_tests();

	return 0;
}
