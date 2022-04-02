#include "Fixed.hpp"
#include <iostream>
#include <string>
#include <cmath>

Fixed::Fixed() : _fixed_point(0)
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
		this->_fixed_point = other.getRawBits();
	}
	return *this;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixed_point = value << this->_fractional_bits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixed_point = (int)(roundf(value * (1 << this->_fractional_bits)));
}

int	Fixed::getRawBits( void ) const
{
	return (this->_fixed_point);
}
void	Fixed::setRawBits( int const raw )
{
	this->_fixed_point = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)(this->_fixed_point) / (1 << this->_fractional_bits));
}

int	Fixed::toInt(void) const
{
	return (this->_fixed_point >> this->_fractional_bits);
}

std::ostream &operator<<(std::ostream &lhs, const Fixed &rhs)
{
	lhs << rhs.toFloat();
	return lhs;
}