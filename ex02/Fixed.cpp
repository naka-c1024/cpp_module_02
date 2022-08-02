#include "Fixed.hpp"
#include <iostream>
#include <string>
#include <cmath>

Fixed::Fixed() : _raw_bits(0){}

Fixed::~Fixed(){}

Fixed::Fixed(const Fixed &other)
{
	*this = other; // 代入演算子オーバーロード
}
Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->_raw_bits = other.getRawBits();
	return *this;
}

Fixed::Fixed(const int value)
{
	this->_raw_bits = value << this->_fractional_bits;
}

Fixed::Fixed(const float value)
{
	this->_raw_bits = (int)(roundf(value * (1 << this->_fractional_bits)));
}

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

int	Fixed::toInt(void) const
{
	return (this->_raw_bits >> this->_fractional_bits);
}

std::ostream &operator<<(std::ostream &lhs, const Fixed &rhs)
{
	lhs << rhs.toFloat();
	return lhs;
}

bool	Fixed::operator == ( const Fixed& obj ) const
{
	return (this->_raw_bits == obj._raw_bits);
}
bool	Fixed::operator != ( const Fixed& obj ) const
{
	return (this->_raw_bits != obj._raw_bits);
}
bool	Fixed::operator < ( const Fixed& obj ) const
{
	return (this->_raw_bits < obj._raw_bits);
}
bool	Fixed::operator > ( const Fixed& obj ) const
{
	return (this->_raw_bits > obj._raw_bits);
}
bool	Fixed::operator <= ( const Fixed& obj ) const
{
	return (this->_raw_bits <= obj._raw_bits);
}
bool	Fixed::operator >= ( const Fixed& obj ) const
{
	return (this->_raw_bits >= obj._raw_bits);
}

const	Fixed Fixed::operator + ( const Fixed& obj ) const
{
	Fixed	rtn;
	rtn._raw_bits = this->_raw_bits + obj._raw_bits;
	return rtn;
}
const	Fixed Fixed::operator - ( const Fixed& obj ) const
{
	Fixed	rtn;
	rtn._raw_bits = this->_raw_bits - obj._raw_bits;
	return rtn;
}
const	Fixed Fixed::operator * ( const Fixed& obj ) const
{
	Fixed	rtn;
	rtn._raw_bits = (this->_raw_bits * obj._raw_bits) >> this->_fractional_bits;
	return rtn;
}
const	Fixed Fixed::operator / ( const Fixed& obj ) const
{
	Fixed	rtn;
	rtn._raw_bits = (this->_raw_bits << this->_fractional_bits) / obj._raw_bits;
	return rtn;
}

Fixed	Fixed::operator ++ (void)
{
	++(this->_raw_bits);
	return *this;
}
Fixed	Fixed::operator ++ (int n)
{
	(void)n;
	Fixed	after = *this;
	++(this->_raw_bits);
	return after;
}
Fixed	Fixed::operator -- (void)
{
	--(this->_raw_bits);
	return *this;
}
Fixed	Fixed::operator -- (int n)
{
	(void)n;
	Fixed	after = *this;
	--(this->_raw_bits);
	return after;
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a._raw_bits > b._raw_bits)
		return b;
	else
		return a;
}
const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a._raw_bits > b._raw_bits)
		return b;
	else
		return a;
}
Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a._raw_bits < b._raw_bits)
		return b;
	else
		return a;
}
const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a._raw_bits < b._raw_bits)
		return b;
	else
		return a;
}
