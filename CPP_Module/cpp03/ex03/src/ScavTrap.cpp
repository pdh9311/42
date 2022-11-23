#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("s_default", SCAVTRAP_HP, SCAVTRAP_EP, SCAVTRAP_AD) {
	std::cout << C_AQUA << "ScavTrap[" << this->name_ << "]constructor called" << C_NC << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name, SCAVTRAP_HP, SCAVTRAP_EP, SCAVTRAP_AD) {
	std::cout << C_AQUA << "ScavTrap[" << this->name_ << "] constructor called" << C_NC << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap) {
	std::cout << C_AQUA << "ScavTrap Copy constructor called" << C_NC << std::endl;
	*this = scavTrap;
}
ScavTrap::~ScavTrap() {
	std::cout << C_RED << "ScavTrap[" << this->name_ << "] Destructor called" << C_NC << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &scavTrap) {
	this->name_ = scavTrap.getName();
	this->hitPoints_ = scavTrap.getHitPoints();
	this->energyPoints_ = scavTrap.getEnergyPoints();
	this->attackDamage_ = scavTrap.getAttackDamage();
	return (*this);
}

void ScavTrap::guardGate() {
	std::cout << "Entered in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
	std::cout << C_PURPLE << "ScavTrap[" << this->name_ << "] attacks [" << target
		<< "], causing " << this->attackDamage_ << " points of damage!" << C_NC << std::endl;
	int remainEP = this->energyPoints_ - 5;
	if (remainEP < 0)
		this->energyPoints_ = 0;
	else
		this->energyPoints_ = remainEP;
}

void ScavTrap::takeDamage(unsigned int amount) {
	int remainHP = this->hitPoints_ - amount;

	if (remainHP <= 0) {
		this->hitPoints_ = 0;
		std::cout << C_YELLOW << "ScavTrap[" << this->name_ << "] damaged(" << amount << ") and died" << C_NC << std::endl;
	} else {
		this->hitPoints_ = remainHP;
		std::cout << C_YELLOW << "ScavTrap[" << this->name_ << "] damaged(" << amount << ")" << C_NC << std::endl;
	}
}

void ScavTrap::beRepaired(unsigned int amount) {
	int remainHP = this->hitPoints_ + amount;
	int remainEP = this->energyPoints_ + amount;

	if (this->hitPoints_ == 0) {
		if (remainHP >= SCAVTRAP_HP) {
			this->hitPoints_ = SCAVTRAP_HP;
			std::cout << C_GREEN << "ScavTrap[" << this->name_ << "] reparied("<< amount << ") and revived full HP !!" << C_NC << std::endl;
		} else {
			this->hitPoints_ = remainHP;
			std::cout << C_GREEN << "ScavTrap[" << this->name_ << "] reparied("<< amount << ") and revived" << C_NC << std::endl;
		}
	} else if (remainHP >= SCAVTRAP_HP) {
		this->hitPoints_ = SCAVTRAP_HP;
		std::cout << C_GREEN << "ScavTrap[" << this->name_ << "] repaired("<< amount << ") full HP !!" << C_NC << std::endl;
	} else {
		this->hitPoints_ = remainHP;
		std::cout << C_GREEN << "ScavTrap[" << this->name_ << "] repaired("<< amount << ")" << C_NC << std::endl;
	}
	if (remainEP >= SCAVTRAP_EP)
		this->energyPoints_ = SCAVTRAP_EP;
	else
		this->energyPoints_ = remainEP;
}

void ScavTrap::toString() {
	std::cout << std::setfill(' ') << std::setw(8) << "name: " << this->name_ << std::endl;
	std::cout << std::setfill(' ') << std::setw(8) << "HP: " << this->hitPoints_ << std::endl;
	std::cout << std::setfill(' ') << std::setw(8) << "EP: " << this->energyPoints_ << std::endl;
	std::cout << std::setfill(' ') << std::setw(8) << "Damage: " << this->attackDamage_ << std::endl;
	std::cout << std::setfill('-') << std::setw(60) << "(ScavTrap)\n" << std::endl;
}