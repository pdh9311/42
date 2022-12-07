#include "HumanB.hpp"

HumanB::HumanB(const std::string &name)
: name_(name), weapon_(nullptr) {}

HumanB::HumanB(const std::string &name, Weapon *weapon)
: name_(name), weapon_(weapon) {}

void HumanB::setWeapon(Weapon *weapon) {
	weapon_ = weapon;
}

void HumanB::attack(void) {
	std::cout << name_ << " attacks with his " << weapon_->getType() << std::endl;
}
