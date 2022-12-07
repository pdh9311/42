#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
private:
	std::string name_;
	Weapon *weapon_;

public:
	HumanB(const std::string &name);
	HumanB(const std::string &name, Weapon *weapon);

	void setWeapon(Weapon *weapon);

	void attack(void);
};

#endif