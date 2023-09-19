


class Fixed
{
private:
	
	int	fixed_point;
	static const int fractional_bits;
	
public:

	Fixed();
	Fixed(const Fixed &src);
	~Fixed();

	Fixed	&operator=(Fixed const &rhs);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	
};

