#include "Fixed.hpp"
#include <iostream>
#include <string>
#include <cmath>

Fixed::Fixed() : _raw_bits(0)
{
	std::cout << "Default constructor called" << std::endl;
}
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other; // 代入演算子オーバーロード
}
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_raw_bits = other.getRawBits();
	}
	return *this;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_raw_bits = value << this->_fractional_bits;
}
// 左に8bitシフトするとは2^8=256かけることを意味する
// 0001を左に2シフトすると0100,つまり10進数で4=2^2になる

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_raw_bits = (int)(roundf(value * (1 << this->_fractional_bits)));
}
// (1 << this->_fractional_bits)=256
// 42.42f*256≒10859.5 -> これにroundfをかますと少数部がなくなり10895になる

int	Fixed::getRawBits( void ) const
{
	return (this->_raw_bits);
}
void	Fixed::setRawBits( int const raw )
{
	this->_raw_bits = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)(this->_raw_bits) / (1 << this->_fractional_bits));
}
// (1 << this->_fractional_bits)=256割ってる

int	Fixed::toInt(void) const
{
	return (this->_raw_bits >> this->_fractional_bits);
}
// 受け取った時に左シフト8やったからその逆で右シフト8している
// 最初2^8=256かけたから出力する時は2^8=256分割ってintにしてるだけ
// return (this->_raw_bits / 256); // これでもいい

std::ostream &operator<<(std::ostream &lhs, const Fixed &rhs)
{
	lhs << rhs.toFloat();
	return lhs;
}