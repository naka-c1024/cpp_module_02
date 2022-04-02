#include "Fixed.hpp"
#include <iostream>
#include <string>
#include <cmath>

Fixed::Fixed() : _fixed_point(0){}

Fixed::~Fixed(){}

Fixed::Fixed(const Fixed &other)
{
	*this = other; // 代入演算子オーバーロード
}
Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->_fixed_point = other.getRawBits();
	return *this;
}

Fixed::Fixed(const int value)
{
	this->_fixed_point = value << this->_fractional_bits;
}

Fixed::Fixed(const float value)
{
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

bool	Fixed::operator == ( const Fixed& obj ) const
{
	return (this->_fixed_point == obj._fixed_point);
}
bool	Fixed::operator != ( const Fixed& obj ) const
{
	return (this->_fixed_point != obj._fixed_point);
}
bool	Fixed::operator < ( const Fixed& obj ) const
{
	return (this->_fixed_point < obj._fixed_point);
}
bool	Fixed::operator > ( const Fixed& obj ) const
{
	return (this->_fixed_point > obj._fixed_point);
}
bool	Fixed::operator <= ( const Fixed& obj ) const
{
	return (this->_fixed_point <= obj._fixed_point);
}
bool	Fixed::operator >= ( const Fixed& obj ) const
{
	return (this->_fixed_point >= obj._fixed_point);
}

const	Fixed Fixed::operator + ( const Fixed& obj ) const
{
	Fixed	rtn;
	rtn._fixed_point = this->_fixed_point + obj._fixed_point;
	return rtn;
}
const	Fixed Fixed::operator - ( const Fixed& obj ) const
{
	Fixed	rtn;
	rtn._fixed_point = this->_fixed_point - obj._fixed_point;
	return rtn;
}
const	Fixed Fixed::operator * ( const Fixed& obj ) const
{
	Fixed	rtn;
	rtn._fixed_point = (this->_fixed_point * obj._fixed_point) >> this->_fractional_bits;
	return rtn;
}
const	Fixed Fixed::operator / ( const Fixed& obj ) const
{
	Fixed	rtn;
	rtn._fixed_point = (this->_fixed_point << this->_fractional_bits) / obj._fixed_point;
	return rtn;
}

Fixed	Fixed::operator ++ (void)
{
	++(this->_fixed_point);
	return *this;
}
Fixed	Fixed::operator ++ (int n)
{
	(void)n;
	Fixed	after = *this;
	++(this->_fixed_point);
	return after;
}
Fixed	Fixed::operator -- (void)
{
	--(this->_fixed_point);
	return *this;
}
Fixed	Fixed::operator -- (int n)
{
	(void)n;
	Fixed	after = *this;
	--(this->_fixed_point);
	return after;
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a._fixed_point > b._fixed_point)
		return b;
	else
		return a;
}
const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a._fixed_point > b._fixed_point)
		return b;
	else
		return a;
}
Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a._fixed_point < b._fixed_point)
		return b;
	else
		return a;
}
const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a._fixed_point < b._fixed_point)
		return b;
	else
		return a;
}
