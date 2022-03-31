#ifndef FIXED_HPP
#define FIXED_HPP

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
	int					_value;
	static const int	_fractional_bits = 8;
};

std::ostream &operator<<(std::ostream &lhs, const Fixed &rhs);

#endif /* FIXED_HPP */
