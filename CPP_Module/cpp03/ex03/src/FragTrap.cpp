#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("s_default", FRAGTRAP_HP, FRAGTRAP_EP, FRAGTRAP_AD) {
	std::cout << C_AQUA << "FragTrap[" << this->name_ << "]constructor called" << C_NC << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name, FRAGTRAP_HP, FRAGTRAP_EP, FRAGTRAP_AD) {
	std::cout << C_AQUA << "FragTrap[" << this->name_ << "] constructor called" << C_NC << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragTrap) {
	std::cout << C_AQUA << "FragTrap Copy constructor called" << C_NC << std::endl;
	*this = fragTrap;
}
FragTrap::~FragTrap() {
	std::cout << C_RED << "FragTrap[" << this->name_ << "] Destructor called" << C_NC << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &fragTrap) {
	this->name_ = fragTrap.getName();
	this->hitPoints_ = fragTrap.getHitPoints();
	this->energyPoints_ = fragTrap.getEnergyPoints();
	this->attackDamage_ = fragTrap.getAttackDamage();
	return (*this);
}

void FragTrap::highFivesGuys(void) {
	std::cout << "high five ~~!" << std::endl;
}

void FragTrap::attack(const std::string &target) {
	std::cout << C_PURPLE << "FragTrap[" << this->name_ << "] attacks [" << target
		<< "], causing "	<< this->attackDamage_ << " points of damage!" << C_NC << std::endl;
	int remainEP = this->energyPoints_ - 5;
	if (remainEP < 0)
		this->energyPoints_ = 0;
	else
		this->energyPoints_ = remainEP;
}

void FragTrap::takeDamage(unsigned int amount) {
	int remainHP = this->hitPoints_ - amount;

	if (remainHP <= 0) {
		this->hitPoints_ = 0;
		std::cout << C_YELLOW << "FragTrap[" << this->name_ << "] damaged(" << amount << ") and died" << C_NC << std::endl;
	} else {
		this->hitPoints_ = remainHP;
		std::cout << C_YELLOW << "FragTrap[" << this->name_ << "] damaged(" << amount << ")" << C_NC << std::endl;
	}
}

void FragTrap::beRepaired(unsigned int amount) {
	int remainHP = this->hitPoints_ + amount;
	int remainEP = this->energyPoints_ + amount;

	if (this->hitPoints_ == 0) {
		if (remainHP >= FRAGTRAP_HP) {
			this->hitPoints_ = FRAGTRAP_HP;
			std::cout << C_GREEN << "FragTrap[" << this->name_ << "] reparied("<< amount << ") and revived full HP !!" << C_NC << std::endl;
		} else {
			this->hitPoints_ = remainHP;
			std::cout << C_GREEN << "FragTrap[" << this->name_ << "] reparied("<< amount << ") and revived" << C_NC << std::endl;
		}
	} else if (remainHP >= FRAGTRAP_HP) {
		this->hitPoints_ = FRAGTRAP_HP;
		std::cout << C_GREEN << "FragTrap[" << this->name_ << "] repaired("<< amount << ") full HP !!" << C_NC << std::endl;
	} else {
		this->hitPoints_ = remainHP;
		std::cout << C_GREEN << "FragTrap[" << this->name_ << "] repaired("<< amount << ")" << C_NC << std::endl;
	}
	if (remainEP >= FRAGTRAP_EP)
		this->energyPoints_ = FRAGTRAP_EP;
	else
		this->energyPoints_ = remainEP;
}

void FragTrap::toString() {
	std::cout << std::setfill(' ') << std::setw(8) << "name: " << this->name_ << std::endl;
	std::cout << std::setfill(' ') << std::setw(8) << "HP: " << this->hitPoints_ << std::endl;
	std::cout << std::setfill(' ') << std::setw(8) << "EP: " << this->energyPoints_ << std::endl;
	std::cout << std::setfill(' ') << std::setw(8) << "Damage: " << this->attackDamage_ << std::endl;
	std::cout << std::setfill('-') << std::setw(60) << "(FragTrap)\n" << std::endl;
}