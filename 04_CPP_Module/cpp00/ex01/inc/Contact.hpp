#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>	// getline(), compare(), length(), begin(), end(), replace()

class Contact
{
private:
	int index_;
	std::string first_name_;
	std::string last_name_;
	std::string nickname_;
	std::string phone_number_;
	std::string darkest_secret_;

public:
	int GetIndex(void);
	void SetIndex(int idx);
	std::string& GetFirstName(void);
	std::string& GetLastName(void);
	std::string& GetNickName(void);
	std::string& GetPhoneNumber(void);
	std::string& GetDarkestSecret(void);
};

#endif
