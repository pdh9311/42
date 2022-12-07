#include "Zombie.hpp"

Zombie::Zombie() {
	std::cout << "zombie: default 생성자로 생성" << std::endl;
}

Zombie::~Zombie() {
	std::cout << name_ << " 소멸 !" << std::endl;
}

void Zombie::announce(void) const {
	std::cout << name_ << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string name)
{
	name_ = name;
	announce();
}