#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

# define MIN_GRADE 150
# define MAX_GRADE 1

class Form;

class Bureaucrat {
private:
	std::string name_;
	int grade_;

public:
	Bureaucrat();
	Bureaucrat(const std::string &name, const int &grade);
	Bureaucrat(const Bureaucrat &b);
	~Bureaucrat();

	Bureaucrat& operator=(const Bureaucrat &b);

	const std::string& getName() const;
	const int& getGrade() const;

	void increaseGrade(int grade);
	void decreaseGrade(int grade);

	void signForm(Form *f);

	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat &b);

#endif
