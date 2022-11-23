#include "Bureaucrat.hpp"

int main(void)
{
	try {
		Bureaucrat b1("donaprk", 55);
		b1.increaseGrade(54);
		std::cout << b1 << std::endl;
		b1.increaseGrade(1);
		std::cout << b1 << std::endl;
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat b2("donaprk", 55);
		b2.decreaseGrade(95);
		std::cout << b2 << std::endl;
		b2.decreaseGrade(1);
		std::cout << b2 << std::endl;
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}