#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{
private:
	std::string	type_;

public:
	Weapon(const std::string &type);

	const std::string& getType(void) const;
	void setType(const std::string& type);
};

#endif