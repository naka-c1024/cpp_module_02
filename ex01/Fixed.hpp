#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	Fixed();
	~Fixed();
	Fixed(Fixed const &other);
	Fixed &operator=(Fixed const &other);

	Fixed(const int);
	Fixed(const float);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;

private:
	int					_fixed_point; // 固定小数点数(内部値)
	static const int	_fractional_bits = 8; // 少数部のシフトするbit数
};

std::ostream &operator<<(std::ostream &lhs, const Fixed &rhs);

#endif /* FIXED_HPP */
