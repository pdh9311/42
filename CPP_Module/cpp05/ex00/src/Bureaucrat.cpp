#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name_(""), grade_(MIN_GRADE) {}

Bureaucrat::Bureaucrat(const std::string &name, const int &grade) : name_(name) {
	if (grade < MAX_GRADE)
		throw GradeTooHighException();
	else if (grade > MIN_GRADE)
		throw GradeTooLowException();
	this->grade_ = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &b) {
	*this = b;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &b) {
	this->name_ = b.getName();
	this->grade_ = b.getGrade();
	return (*this);
}

const std::string& Bureaucrat::getName() const {
	return (this->name_);
}

const int& Bureaucrat::getGrade() const {
	return (this->grade_);
}

void Bureaucrat::increaseGrade(int grade) {
	int tmp = this->grade_ - grade;
	if (tmp < 1)
		throw GradeTooHighException();
	this->grade_ -= grade;
}

void Bureaucrat::decreaseGrade(int grade) {
	int tmp = this->grade_ + grade;
	if (tmp > 150)
		throw GradeTooLowException();
	this->grade_ += grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade Too High!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade Too Low!");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat &b) {
	return (os << "name: " << b.getName() << ", grade: " << b.getGrade());
}
