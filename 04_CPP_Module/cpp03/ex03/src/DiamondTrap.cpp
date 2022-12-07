#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {
	std::cout << C_AQUA << "DiamondTrap[" << this->name_ << "]constructor called" << C_NC << std::endl;
	this->name_ = "d_default";
	ClapTrap::name_ = this->name_ + "_clap_name";
	this->hitPoints_ = FRAGTRAP_HP;
	this->energyPoints_ = SCAVTRAP_EP;
	this->attackDamage_ = FRAGTRAP_AD;
}
DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(), ScavTrap(), FragTrap() {
	std::cout << C_AQUA << "DiamondTrap[" << this->name_ << "] constructor called" << C_NC << std::endl;
	this->name_ = name;
	ClapTrap::name_ = name + "_clap_name";
	this->hitPoints_ = FRAGTRAP_HP;
	this->energyPoints_ = SCAVTRAP_EP;
	this->attackDamage_ = FRAGTRAP_AD;
}
DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap) : ClapTrap(), ScavTrap(), FragTrap() {
	std::cout << C_AQUA << "DiamondTrap Copy constructor called" << C_NC << std::endl;
	*this = diamondTrap;
}
DiamondTrap::~DiamondTrap() {
	std::cout << C_RED << "DiamondTrap[" << this->name_ << "] Destructor called" << C_NC << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &diamondTrap) {
	this->name_ = diamondTrap.getName();
	this->hitPoints_ = diamondTrap.getHitPoints();
	this->energyPoints_ = diamondTrap.getEnergyPoints();
	this->attackDamage_ = diamondTrap.getAttackDamage();
	return (*this);
}

void DiamondTrap::whoAmI() {
	std::cout << "I'm " << this->name_ << ", clapTrap name: " << ClapTrap::name_ << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}

void DiamondTrap::takeDamage(unsigned int amount) {
	int remainHP = this->hitPoints_ - amount;

	if (remainHP <= 0) {
		this->hitPoints_ = 0;
		std::cout << C_YELLOW << "DiamondTrap[" << this->name_ << "] damaged(" << amount << ") and died" << C_NC << std::endl;
	} else {
		this->hitPoints_ = remainHP;
		std::cout << C_YELLOW << "DiamondTrap[" << this->name_ << "] damaged(" << amount << ")" << C_NC << std::endl;
	}
}
void DiamondTrap::beRepaired(unsigned int amount) {
	int remainHP = this->hitPoints_ + amount;
	int remainEP = this->energyPoints_ + amount;

	if (this->hitPoints_ == 0) {
		if (remainHP >= FRAGTRAP_HP) {
			this->hitPoints_ = FRAGTRAP_HP;
			std::cout << C_GREEN << "DiamondTrap[" << this->name_ << "] reparied("<< amount << ") and revived full HP !!" << C_NC << std::endl;
		} else {
			this->hitPoints_ = remainHP;
			std::cout << C_GREEN << "DiamondTrap[" << this->name_ << "] reparied("<< amount << ") and revived" << C_NC << std::endl;
		}
	} else if (remainHP >= FRAGTRAP_HP) {
		this->hitPoints_ = FRAGTRAP_HP;
		std::cout << C_GREEN << "DiamondTrap[" << this->name_ << "] repaired("<< amount << ") full HP !!" << C_NC << std::endl;
	} else {
		this->hitPoints_ = remainHP;
		std::cout << C_GREEN << "DiamondTrap[" << this->name_ << "] repaired("<< amount << ")" << C_NC << std::endl;
	}
	if (remainEP >= SCAVTRAP_EP)
		this->energyPoints_ = SCAVTRAP_EP;
	else
		this->energyPoints_ = remainEP;
}

void DiamondTrap::toString() {
	std::cout << std::setfill(' ') << std::setw(8) << "name: " << this->name_ << std::endl;
	std::cout << std::setfill(' ') << std::setw(8) << "HP: " << this->hitPoints_ << std::endl;
	std::cout << std::setfill(' ') << std::setw(8) << "EP: " << this->energyPoints_ << std::endl;
	std::cout << std::setfill(' ') << std::setw(8) << "Damage: " << this->attackDamage_ << std::endl;
	std::cout << std::setfill('-') << std::setw(60) << "(DiamondTrap)\n" << std::endl;
}