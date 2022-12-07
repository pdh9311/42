#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include <iomanip>
# include "Color.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
	std::string name_;
	bool isSigned_;
	int signGrade_;
	int executeGrade_;

public:
	Form();
	Form(const std::string &name, const int &signGrade, const int &executeGrade);
	Form(const Form &f);
	virtual ~Form();

	Form& operator=(const Form &f);

	const std::string& getName() const;
	const bool& getIsSigned() const;
	const int& getSigneGrade() const;
	const int& getExecuteGrade() const;

	void beSinged(Bureaucrat *b);

	virtual void execute(const Bureaucrat &executor) const = 0;

	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};

	class NotSignedException : public std::exception {
	public:
		const char* what() const throw();
	};

};

std::ostream& operator<<(std::ostream &os, const Form &form);

#endif
