#include "Form.hpp"

Form::Form() : name_(""), isSigned_(false), signGrade_(MAX_GRADE), executeGrade_(MIN_GRADE) {}

Form::Form(const std::string &name, const int &signGrade, const int &executeGrade)
	: name_(name), isSigned_(false), signGrade_(signGrade), executeGrade_(executeGrade) {
	if (this->signGrade_ < MAX_GRADE || this->executeGrade_ < MAX_GRADE)
		throw GradeTooHighException();
	else if (this->signGrade_ > MIN_GRADE || this->executeGrade_ > MIN_GRADE)
		throw GradeTooLowException();
}

Form::Form(const Form &f) {
	*this = f;
}

Form::~Form() {}

Form& Form::operator=(const Form &f) {
	this->name_ = f.getName();
	this->isSigned_ = f.getIsSigned();
	this->signGrade_ = f.getSigneGrade();
	this->executeGrade_ = f.getExecuteGrade();
	return (*this);
}

const std::string& Form::getName() const {
	return (this->name_);
}
const bool& Form::getIsSigned() const {
	return (this->isSigned_);
}
const int& Form::getSigneGrade() const {
	return (this->signGrade_);
}
const int& Form::getExecuteGrade() const {
	return (this->executeGrade_);
}

void Form::beSinged(Bureaucrat *b) {
	if (this->signGrade_ < b->getGrade())	// Form 서명에 필요한 등급보다 작으면
		throw GradeTooLowException();
	this->isSigned_ = true;
	std::cout << C_GREEN << b->getName() << " sign." << C_NC << std::endl;
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Grade Too High!!");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Grade Too Low!!");
}

const char* Form::NotSignedException::what() const throw() {
	return ("Not Signed!!");
}

std::ostream& operator<<(std::ostream &os, const Form &form) {
	return (
		os << "name: " << form.getName()
		<< ", isSigned: " << std::boolalpha << form.getIsSigned()
		<< ", signGrade: " << form.getSigneGrade()
		<< ", executeGrade: " << form.getExecuteGrade()
	);
}
