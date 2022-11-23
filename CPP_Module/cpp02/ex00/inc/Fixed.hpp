#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
	int fixed_point_;
	static const int fractional_bits_ = 8;

public:
	Fixed();
	Fixed(const Fixed &fixed);
	~Fixed();

	Fixed& operator=(const Fixed& fixed);

	int getRawBits(void) const;
	void setRawBits(const int raw);
};

#endif