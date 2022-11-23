#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern someRandomIntern;
	Form *rrf = NULL;

	std::cout << "[unknown form Test]" << std::endl;
	rrf = someRandomIntern.makeForm("robotomy request1", "Bender");
	if (rrf != NULL)
		delete rrf;
	std::cout << std::setw(40) << std::setfill('-') << "\n";

	std::cout << "[known form Test]" << std::endl;
	rrf = someRandomIntern.makeForm("shrubbery creation", "Home");
	if (rrf != NULL)
		delete rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (rrf != NULL)
		delete rrf;
	rrf = someRandomIntern.makeForm("presidential pardon", "God");
	if (rrf != NULL)
		delete rrf;
	std::cout << std::setw(40) << std::setfill('-') << "\n";

	std::cout << "[Test]" << std::endl;
	std::srand(std::time(NULL));
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	Bureaucrat b("donpark", 3);
	b.signForm(rrf);
	b.executeForm(*rrf);
	if (rrf != NULL)
		delete rrf;

	return (0);
}
