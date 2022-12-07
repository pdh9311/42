#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form() {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: Form(P_NAME, P_SIGN, P_EXEC), target_(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &p)
	: Form(p) {
	this->target_ = p.getTarget();
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &p) {
	Form::operator=(p);
	this->target_ = p.getTarget();
	return (*this);
}

const std::string& PresidentialPardonForm::getTarget() const {
	return (this->target_);
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	if (getIsSigned() == false)
		throw NotSignedException();
	if (executor.getGrade() > getExecuteGrade())
		throw GradeTooLowException();

	std::cout << C_GREEN << this->target_ << " has been pardoned by Zafod Beeblebrox." << C_NC << std::endl;
}

std::ostream& operator<<(std::ostream &os, const PresidentialPardonForm &p) {
	return (
		os << "name: " << p.getName()
		<< ", isSigned: " << std::boolalpha << p.getIsSigned()
		<< ", signGrade: " << p.getSigneGrade()
		<< ", executeGrade: " << p.getExecuteGrade()
		<< ", target: " << p.getTarget()
	);
}
