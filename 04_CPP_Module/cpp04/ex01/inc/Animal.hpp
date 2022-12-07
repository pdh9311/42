#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include "Color.hpp"
# include <iostream>
# include <string>

class Animal {
protected:
	std::string type_;

public:
	Animal();
	Animal(const Animal &animal);
	virtual ~Animal();

	Animal& operator=(const Animal &animal);

	std::string getType() const;
	void setType(const std::string &type);

	virtual void makeSound() const;
};

std::ostream& operator<<(std::ostream &os, const Animal &animal);

#endif