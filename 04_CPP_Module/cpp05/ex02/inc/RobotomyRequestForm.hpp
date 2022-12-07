#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"
# include <cstdlib>
# include <ctime>

# define R_NAME "RobotomyRequestForm"
# define R_SIGN 72
# define R_EXEC 45

class RobotomyRequestForm : public Form {
private:
	std::string target_;

	RobotomyRequestForm();

public:
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &s);
	~RobotomyRequestForm();

	RobotomyRequestForm& operator=(const RobotomyRequestForm &s);

	const std::string& getTarget() const;

	void execute(const Bureaucrat &executor) const;
};

std::ostream& operator<<(std::ostream &os, const RobotomyRequestForm &r);

#endif
