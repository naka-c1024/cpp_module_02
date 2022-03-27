#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
public:
	Fixed();
	~Fixed();
	Fixed(Fixed const &other);
	Fixed &operator=(Fixed const &other);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

private:
	int					_value;
	static const int	_fractional_bits = 8;
};

#endif /* FIXED_HPP */
