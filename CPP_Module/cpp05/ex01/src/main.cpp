#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try {
		Form f3("form", 50, 151);
	} catch(std::exception &e) {
		std::cerr << C_RED << e.what() << C_NC << std::endl << std::endl;
	}

	try {
		Form f3("form", 0, 150);
	} catch(std::exception &e) {
		std::cerr << C_RED << e.what() << C_NC << std::endl << std::endl;
	}

	try {
		Bureaucrat b("bureaucrat", 55);
		std::cout << b << std::endl << std::endl;

		Form f1("form", 60, 150);
		std::cout << f1 << std::endl;
		b.signForm(&f1);
		std::cout << f1 << std::endl << std::endl;

		Form f2("form", 50, 150);
		std::cout << f2 << std::endl;
		b.signForm(&f2);
		std::cout << f2 << std::endl << std::endl;


	} catch (std::exception &e) {
		std::cerr << C_RED << e.what() << C_NC << std::endl;
	}

	return (0);
}
