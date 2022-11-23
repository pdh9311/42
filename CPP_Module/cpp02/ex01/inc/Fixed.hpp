#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
	int fixed_point_;
	static const int fractional_bits_ = 8;

public:
	Fixed();
	Fixed(const Fixed &fixed);
	Fixed(const int value);
	Fixed(const float value);
	~Fixed();

	Fixed& operator=(const Fixed& fixed);

	int getRawBits(void) const;
	void setRawBits(const int raw);

	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
