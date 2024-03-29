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
	int					_raw_bits; // rawBitsとは変換前の固定小数点数(fixed point value)をint型にしたもの
	static const int	_fractional_bits = 8; // 少数部のシフトするbit数
};

// 整数部は、32bit(int型) - 8bit(fractional bit) - 1bit(符号) = 23bit
// 2^0始まりだから2^22まで整数部は表せる。
// 少数部はfractional bitが8だから2^-8まで表せる。

std::ostream &operator<<(std::ostream &lhs, const Fixed &rhs);

#endif /* FIXED_HPP */
