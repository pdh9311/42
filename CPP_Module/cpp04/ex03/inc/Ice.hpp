#ifndef ICE_HPP
# define ICE_HPP

# include "ICharacter.hpp"

class Ice : public AMateria {

public:
	Ice();
	Ice(const Ice &cure);
	~Ice();

	Ice& operator=(const Ice &cure);

	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif
