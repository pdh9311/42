#include "ShrubberyCreationForm.hpp"

ShrubberyCreationFrom::ShrubberyCreationFrom() : Form() {}

ShrubberyCreationFrom::ShrubberyCreationFrom(const std::string &target)
	: Form(S_NAME, S_SIGN, S_EXEC), target_(target) {}

ShrubberyCreationFrom::ShrubberyCreationFrom(const ShrubberyCreationFrom &s)
	: Form(s) {
	this->target_ = s.getTarget();
}

ShrubberyCreationFrom::~ShrubberyCreationFrom() {}

ShrubberyCreationFrom& ShrubberyCreationFrom::operator=(const ShrubberyCreationFrom &s) {
	Form::operator=(s);
	this->target_ = s.getTarget();
	return (*this);
}

const std::string& ShrubberyCreationFrom::getTarget() const {
	return (this->target_);
}

void ShrubberyCreationFrom::execute(const Bureaucrat &executor) const {
	if (getIsSigned() == false)
		throw NotSignedException();
	if (executor.getGrade() > getExecuteGrade())
		throw GradeTooLowException();

	std::ofstream writeFile((this->target_ + "_shrubbery").c_str());
	if (!writeFile.is_open()) {
		throw std::ios_base::failure("Could not open file " + this->target_ + "_shrubbery");
	}
	std::string tree =
		"                                              .\n"
		"                                   .         ;\n"
		"      .              .              ;%     ;;\n"
		"        ,           ,                :;%  %;\n"
		"         :         ;                   :;%;'     .,\n"
		",.        %;     %;            ;        %;'    ,;\n"
		"  ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
		"   %;       %;%;      ,  ;       %;  ;%;   ,%;'\n"
		"    ;%;      %;        ;%;        % ;%;  ,%;'\n"
		"     `%;.     ;%;     %;'         `;%%;.%;'\n"
		"      `:;%.    ;%%. %@;        %; ;@%;%'\n"
		"         `:%;.  :;bd%;          %;@%;'\n"
		"           `@%:.  :;%.         ;@@%;'\n"
		"             `@%.  `;@%.      ;@@%;\n"
		"               `@%%. `@%%    ;@@%;\n"
		"                 ;@%. :@%%  %@@%;\n"
		"                   %@bd%%%bd%%:;\n"
		"                     #@%%%%%:;;\n"
		"                     %@@%%%::;\n"
		"                     %@@@%(o);  . '\n"
		"                     %@@@o%;:(.,'\n"
		"                 `.. %@@@o%::;\n"
		"                    `)@@@o%::;\n"
		"                     %@@(o)::;\n"
		"                    .%@@@@%::;\n"
		"                    ;%@@@@%::;.\n"
		"                   ;%@@@@%%:;;;.\n"
		"               ...;%@@@@@%%:;;;;,..   ";
	writeFile << tree << std::endl;
	writeFile.close();

	std::cout << C_GREEN << executor.getName() << " execute. and "
	<< this->target_ + "_shrubbery" << " created file." << C_NC << std::endl;
}

std::ostream& operator<<(std::ostream &os, const ShrubberyCreationFrom &s) {
	return (
		os << "name: " << s.getName()
		<< ", isSigned: " << std::boolalpha << s.getIsSigned()
		<< ", signGrade: " << s.getSigneGrade()
		<< ", executeGrade: " << s.getExecuteGrade()
		<< ", target: " << s.getTarget()
	);
}
