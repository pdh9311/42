#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
private:

public:
	WrongCat();
	WrongCat(const WrongCat &wCat);
	~WrongCat();

	WrongCat& operator=(const WrongCat &wCat);

	void makeSound() const;
};

#endif