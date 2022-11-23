#include "Zombie.hpp"

Zombie::Zombie(const std::string name) : name_(name) {
	announce();
}

Zombie::~Zombie() {
	std::cout << name_ << " died !" << std::endl;
}

void	Zombie::announce(void) const {
	std::cout << name_ << " BraiiiiiiinnnzzzZ..." << std::endl;
}
