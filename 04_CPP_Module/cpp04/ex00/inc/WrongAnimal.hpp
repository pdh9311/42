#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include "Color.hpp"
# include <iostream>
# include <string>
# include <iomanip>

class WrongAnimal {
protected:
	std::string type_;

public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &wAnimal);
	virtual ~WrongAnimal();

	WrongAnimal& operator=(const WrongAnimal &wAnimal);

	std::string getType() const;
	void setType(const std::string &type);

	void makeSound() const;
};

std::ostream& operator<<(std::ostream &os, const WrongAnimal &wAnimal);

#endif