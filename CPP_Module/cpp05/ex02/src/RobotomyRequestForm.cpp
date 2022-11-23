#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form() {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: Form(R_NAME, R_SIGN, R_EXEC), target_(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &r)
	: Form(r) {
	this->target_ = r.getTarget();
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &r) {
	Form::operator=(r);
	this->target_ = r.getTarget();
	return (*this);
}

const std::string& RobotomyRequestForm::getTarget() const {
	return (this->target_);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	if (getIsSigned() == false)
		throw NotSignedException();
	if (executor.getGrade() > getExecuteGrade())
		throw GradeTooLowException();

	if (std::rand() % 2 == 0)
		std::cout << C_BLUE << this->target_ << " has been robotomized successfully 50% of the time" << C_NC << std::endl;
	else
		std::cout << C_YELLOW << "It's a failure" << C_NC << std::endl;
}

std::ostream& operator<<(std::ostream &os, const RobotomyRequestForm &r) {
	return (
		os << "name: " << r.getName()
		<< ", isSigned: " << std::boolalpha << r.getIsSigned()
		<< ", signGrade: " << r.getSigneGrade()
		<< ", executeGrade: " << r.getExecuteGrade()
		<< ", target: " << r.getTarget()
	);
}
