#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	Fixed();
	~Fixed();
	Fixed(Fixed const &other);
	Fixed &operator = (Fixed const &other);

	Fixed(const int);
	Fixed(const float);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;

	bool	operator == ( const Fixed& obj ) const;
	bool	operator != ( const Fixed& obj ) const;
	bool	operator < ( const Fixed& obj ) const;
	bool	operator > ( const Fixed& obj ) const;
	bool	operator <= ( const Fixed& obj ) const;
	bool	operator >= ( const Fixed& obj ) const;

	const	Fixed operator + ( const Fixed& obj ) const;
	const	Fixed operator - ( const Fixed& obj ) const;
	const	Fixed operator * ( const Fixed& obj ) const;
	const	Fixed operator / ( const Fixed& obj ) const;

	Fixed	operator ++ (void); // 前置
	Fixed	operator ++ (int n); // 後置
	Fixed	operator -- (void);
	Fixed	operator -- (int n);

	static Fixed& min(Fixed &a, Fixed &b);
	const static Fixed& min(const Fixed &a, const Fixed &b);
	static Fixed& max(Fixed &a, Fixed &b);
	const static Fixed& max(const Fixed &a, const Fixed &b);

private:
	int					_fixed_point; // 固定小数点数(内部値)
	static const int	_fractional_bits = 8; // 少数部のシフトするbit数
};

std::ostream &operator<<(std::ostream &lhs, const Fixed &rhs);

#endif /* FIXED_HPP */
