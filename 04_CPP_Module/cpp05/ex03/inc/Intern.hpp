#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <string>

class Form;

class Intern {
public:
	Intern();
	Intern(const Intern &intern);
	~Intern();

	Intern& operator=(const Intern &intern);

	Form* makeForm(const std::string &formName, const std::string &target);

	class UnknownForm : public std::exception {
		const char* what() const throw();
	};
};

#endif
