#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include "Color.hpp"
# include <iomanip>	// std::setw()
# include <cstdlib>	// atoi

class PhoneBook
{
private:
	static int idx_;
	Contact phonebook_[8];

public:
	void Add(void);
	void Search(void);
	void Search(int idx);
	std::string TenString(std::string origin);
};
#endif
