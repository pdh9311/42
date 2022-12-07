#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include "Color.hpp"
# include <iostream>
# include <string>
# include <iomanip>

# define CLAPTRAP_HP 10
# define CLAPTRAP_EP 10
# define CLAPTRAP_AD 0

class ClapTrap {
private:
	std::string name_;
	unsigned int hitPoints_;
	unsigned int energyPoints_;
	unsigned int attackDamage_;

public:
	ClapTrap();
	ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap &clapTrap);
	~ClapTrap();

	ClapTrap& operator=(const ClapTrap &clapTrap);

	std::string getName(void) const;
	void getName(const std::string &name);

	unsigned int getHitPoints(void) const;
	void setHitPoints(unsigned int hitPoints);

	unsigned int getEnergyPoints(void) const;
	void setEnergyPoints(unsigned int energyPoints);

	unsigned int getAttackDamage(void) const;
	void setAttackDamage(unsigned int attackDamage);

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	void toString(void);
};

#endif