#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"
# include <fstream>

# define S_NAME "ShrubberyCreationForm"
# define S_SIGN 145
# define S_EXEC 137

class Bureaucrat;

class ShrubberyCreationFrom : public Form {
private:
	std::string target_;

	ShrubberyCreationFrom();

public:
	ShrubberyCreationFrom(const std::string &target);
	ShrubberyCreationFrom(const ShrubberyCreationFrom &s);
	~ShrubberyCreationFrom();

	ShrubberyCreationFrom& operator=(const ShrubberyCreationFrom &s);

	const std::string& getTarget() const;

	void execute(const Bureaucrat &executor) const;

};
std::ostream& operator<<(std::ostream &os, const ShrubberyCreationFrom &s);
#endif
