#include "Fixed.hpp"
#include <iostream>

int main( void ) {

	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f ); // floatコンストラクタによってaが書き変わるためデストラクタが呼ばれる
	// 1234(10)->100 1101 0010(2)
	// 0.4321(10)->0.0110 1110(2)(循環小数なので8桁で切り捨て)->0.4296875(10)
	std::cout << "a is " << a << std::endl; // <<演算子のオーバーロード
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return 0;
}
