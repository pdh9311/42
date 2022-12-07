#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>

class ICharacter;

class AMateria {
protected:
	std::string type_;
	bool isEquipped_;

public:
	AMateria();
	AMateria(const std::string &type);
	AMateria(const std::string &type, bool isEquipped);
	AMateria(const AMateria &amateria);
	virtual ~AMateria();

	AMateria& operator=(const AMateria &amateria);

	const std::string& getType() const;
	const bool& getIsEquipped() const;
	void setIsEquipped(bool is);

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif
