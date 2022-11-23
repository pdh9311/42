#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: name_("c_default"), hitPoints_(CLAPTRAP_HP), energyPoints_(CLAPTRAP_EP), attackDamage_(CLAPTRAP_AD) {
	std::cout << C_AQUA << "ClapTrap[" << this->name_ << "] constructor called" << C_NC << std::endl;
}

ClapTrap::ClapTrap(const std::string &name)
	: name_(name), hitPoints_(CLAPTRAP_HP), energyPoints_(CLAPTRAP_EP), attackDamage_(CLAPTRAP_AD) {
	std::cout << C_AQUA << "ClapTrap[" << this->name_ << "] constructor called" << C_NC << std::endl;
}

ClapTrap::ClapTrap(const std::string &name, int hitPoints, int energyPoints, int attackDamage)
	: name_(name), hitPoints_(hitPoints), energyPoints_(energyPoints), attackDamage_(attackDamage) {
	std::cout << C_AQUA << "ClapTrap[" << this->name_ << "] constructor called" << C_NC << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap) {
	std::cout << C_AQUA << "ClapTrap Copy constructor called" << C_NC << std::endl;
	*this = clapTrap;
}

ClapTrap::~ClapTrap() {
	std::cout << C_RED << "ClapTrap[" << this->name_ << "] Destructor called" << C_NC << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &clapTrap) {
	this->name_ = clapTrap.getName();
	this->hitPoints_ = clapTrap.getHitPoints();
	this->energyPoints_ = clapTrap.getEnergyPoints();
	this->attackDamage_ = clapTrap.getAttackDamage();
	return (*this);
}

std::string ClapTrap::getName(void) const {
	return (this->name_);
}
void ClapTrap::getName(const std::string &name) {
	this->name_ = name;
}

unsigned int ClapTrap::getHitPoints(void) const {
	return (this->hitPoints_);
}
void ClapTrap::setHitPoints(unsigned int hitPoints) {
	this->hitPoints_ = hitPoints;
}

unsigned int ClapTrap::getEnergyPoints(void) const {
	return (this->energyPoints_);
}
void ClapTrap::setEnergyPoints(unsigned int energyPoints) {
	this->energyPoints_ = energyPoints;
}

unsigned int ClapTrap::getAttackDamage(void) const {
	return (this->attackDamage_);
}
void ClapTrap::setAttackDamage(unsigned int attackDamage) {
	this->attackDamage_ = attackDamage;
}

void ClapTrap::attack(const std::string &target) {
	std::cout << C_PURPLE << "ClapTrap[" << this->name_ << "] attacks [" << target
		<< "], causing "	<< this->attackDamage_ << " points of damage!" << C_NC << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	int remainHP = this->hitPoints_ - amount;

	if (remainHP <= 0) {
		this->hitPoints_ = 0;
		std::cout << C_YELLOW << "ClapTrap[" << this->name_ << "] damaged(" << amount << ") and died" << C_NC << std::endl;
	} else {
		this->hitPoints_ = remainHP;
		std::cout << C_YELLOW << "ClapTrap[" << this->name_ << "] damaged(" << amount << ")" << C_NC << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	int remainHP = this->hitPoints_ + amount;

	if (this->hitPoints_ == 0) {
		if (remainHP >= CLAPTRAP_HP) {
			this->hitPoints_ = CLAPTRAP_HP;
			std::cout << C_GREEN << "ClapTrap[" << this->name_ << "] reparied("<< amount << ") and revived full HP !!" << C_NC << std::endl;
		} else {
			this->hitPoints_ = remainHP;
			std::cout << C_GREEN << "ClapTrap[" << this->name_ << "] reparied("<< amount << ") and revived" << C_NC << std::endl;
		}
	} else if (remainHP >= CLAPTRAP_HP) {
		this->hitPoints_ = CLAPTRAP_HP;
		std::cout << C_GREEN << "ClapTrap[" << this->name_ << "] repaired("<< amount << ") full HP !!" << C_NC << std::endl;
	} else {
		this->hitPoints_ = remainHP;
		std::cout << C_GREEN << "ClapTrap[" << this->name_ << "] repaired("<< amount << ")" << C_NC << std::endl;
	}
}

void ClapTrap::toString(void) {
	std::cout << std::setfill(' ') << std::setw(8) << "name: " << this->name_ << std::endl;
	std::cout << std::setfill(' ') << std::setw(8) << "HP: " << this->hitPoints_ << std::endl;
	std::cout << std::setfill(' ') << std::setw(8) << "EP: " << this->energyPoints_ << std::endl;
	std::cout << std::setfill(' ') << std::setw(8) << "Damage: " << this->attackDamage_ << std::endl;
	std::cout << std::setfill('-') << std::setw(60) << "(ClapTrap)\n" << std::endl;
}