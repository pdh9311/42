#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon) 
: name_(name), weapon_(weapon) {}

void HumanA::attack(void) {
	std::cout << name_ << " attacks with his " << weapon_.getType() << std::endl;
}