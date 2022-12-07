#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	a.setRawBits(5 << 8);
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << std::endl << "[ Test comparison operator ]" << std::endl;
	if (a > b)
		std::cout << a << " > " << b << " is True" << std::endl;
	else
		std::cout << a << " > " << b << " is False" << std::endl;

	if (a < b)
		std::cout << a << " < " << b << " is True" << std::endl;
	else
		std::cout << a << " < " << b << " is False" << std::endl;

	if (a >= b)
		std::cout << a << " >= " << b << " is True" << std::endl;
	else
		std::cout << a << " >= " << b << " is False" << std::endl;

	if (a <= b)
		std::cout << a << " <= " << b << " is True" << std::endl;
	else
		std::cout << a << " <= " << b << " is False" << std::endl;

	if (a == b)
		std::cout << a << " == " << b << " is True" << std::endl;
	else
		std::cout << a << " == " << b << " is False" << std::endl;

	if (a != b)
		std::cout << a << " != " << b << " is True" << std::endl;
	else
		std::cout << a << " != " << b << " is False" << std::endl;

	std::cout << std::endl << "[ Test arithmetic operator ]" << std::endl;
	std::cout << a << " + " << b << " = " << a + b << std::endl;
	std::cout << a << " - " << b << " = " << a - b << std::endl;
	std::cout << a << " * " << b << " = " << a * b << std::endl;
	std::cout << a << " / " << b << " = " << a / b << std::endl;

	std::cout << std::endl << "[ Test (pre || post) (increment || decrement) operator ] " << std::endl;
	std::cout << std::setw(5) << "a: " << a << std::endl;
	std::cout << std::setw(5) << "++a: " << ++a << std::endl;
	std::cout << std::setw(5) << "a: " << a << std::endl;
	std::cout << std::setw(5) << "a++: " << a++ << std::endl;
	std::cout << std::setw(5) << "a: " << a << std::endl;
	std::cout << std::setw(5) << "b: " << b << std::endl;
	// std::cout << ++b << std::endl;	// const 객체 이므로 변경 불가능

	std::cout << std::endl << "[ Test (min || max) operator ]" << std::endl;
	std::cout << "min: " << Fixed::min(a, b) << std::endl;
	std::cout << "max: " << Fixed::max(a, b) << std::endl;

	return (0);
}
