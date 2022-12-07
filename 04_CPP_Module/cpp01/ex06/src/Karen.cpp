#include "Karen.hpp"

const std::string Karen::COMMENTS[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

void Karen::debug(void) {
	std::cout << C_PURPLE << "[ DEBUG ]" << C_NC << std::endl;
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. "
		<< std::endl << "I just love it!" << std::endl << std::endl;
}

void Karen::info(void) {
	std::cout << C_GREEN << "[ INFO ]" << C_NC << std::endl;
	std::cout << "I cannot believe adding extra bacon cost more money. "
		<< std::endl << "You don’t put enough! "
		<< std::endl << "If you did I would not have to ask for it!" << std::endl << std::endl;
}

void Karen::warning(void) {
	std::cout << C_YELLOW << "[ WARNING ]" << C_NC << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. "
		<< std::endl << "I’ve been coming here for years and you just started working here last month." << std::endl << std::endl;
}

void Karen::error(void) {
	std::cout << C_RED << "[ ERROR ]" << C_NC << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl << std::endl;
}

void Karen::complain(const std::string &level) {
	void (Karen::*fn[4])() = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error};
	for (int i = 0; i < 4; i++) {
		if (level == COMMENTS[i])
			(this->*fn[i])();
	}
}

void Karen::filter(const std::string &level) {
	void (Karen::*fn[4])() = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error};
	int i;
	int is_comment = false;

	for (i = 0; i < 4; i++) {
		if (level == COMMENTS[i]) {
			for (; i < 4; i++) {
				(this->*fn[i])();
			}
			is_comment = true;
			break ;
		}
	}
	if (is_comment == false)
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
