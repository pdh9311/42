#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

# define P_NAME "PresidentialPardonForm"
# define P_SIGN 25
# define P_EXEC 5

class PresidentialPardonForm : public Form {
private:
	std::string target_;

	PresidentialPardonForm();

public:
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &s);
	~PresidentialPardonForm();

	PresidentialPardonForm& operator=(const PresidentialPardonForm &s);

	const std::string& getTarget() const;

	void execute(const Bureaucrat &executor) const;
};

std::ostream& operator<<(std::ostream &os, const PresidentialPardonForm &p);

#endif

