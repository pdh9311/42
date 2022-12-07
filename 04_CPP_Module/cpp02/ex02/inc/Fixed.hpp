#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>
# include <iomanip>

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

	Fixed& operator++();
	Fixed& operator--();
	Fixed operator++(int);
	Fixed operator--(int);

	int getRawBits(void) const;
	void setRawBits(const int raw);

	float toFloat(void) const;
	int toInt(void) const;

	static const Fixed& min(const Fixed& f1, const Fixed& f2);
	static const Fixed& max(const Fixed& f1, const Fixed& f2);
};

bool operator>(const Fixed& f1, const Fixed& f2);
bool operator<(const Fixed& f1, const Fixed& f2);
bool operator>=(const Fixed& f1, const Fixed& f2);
bool operator<=(const Fixed& f1, const Fixed& f2);
bool operator==(const Fixed& f1, const Fixed& f2);
bool operator!=(const Fixed& f1, const Fixed& f2);
Fixed operator+(const Fixed& f1, const Fixed& f2);
Fixed operator-(const Fixed& f1, const Fixed& f2);
Fixed operator*(const Fixed& f1, const Fixed& f2);
Fixed operator/(const Fixed& f1, const Fixed& f2);

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);


#endif
