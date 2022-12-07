#include "Intern.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}
Intern::Intern(const Intern &intern) {
	*this = intern;
}
Intern::~Intern() {}

Intern& Intern::operator=(const Intern &intern) {
	(void)intern;
	return (*this);
}

// NEED: funtion pointer
Form* Intern::makeForm(const std::string &formName, const std::string &target) {
	const std::string forms[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	try {
		int form;
		for (form = 0; form < 3; form++) {
			if (forms[form] == formName)
				break ;
		}
		if (form == 3)
			throw UnknownForm();
		switch (form) {
			case 0:
				std::cout << "Intern creates " << forms[form] << std::endl;
				return (new ShrubberyCreationFrom(target));
			case 1:
				std::cout << "Intern creates " << forms[form] << std::endl;
				return (new RobotomyRequestForm(target));
			case 2:
				std::cout << "Intern creates " << forms[form] << std::endl;
				return (new PresidentialPardonForm(target));
		}
	} catch(const std::exception &e) {
		std::cerr << e.what() <<std::endl;
	}
	return (NULL);
}

const char* Intern::UnknownForm::what() const throw() {
	return ("Unknown Form");
}
