#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void)
{
	std::string	cmd;
	PhoneBook	pb;

	std::cout << C_GREEN  << "[ command: ADD, SEARCH, EXIT ]" << C_NC << std::endl;
	while (true)
	{
		std::cout << C_AQUA << "input command > " << C_NC;
		std::getline(std::cin, cmd);
		if (std::cin.eof())	return (0);
		if (cmd.compare("EXIT") == 0) {
			return (0);
		} else if (cmd.compare("ADD") == 0) {
			pb.Add();
		} else if (cmd.compare("SEARCH") == 0) {
			pb.Search();
		} else {
			std::cout << C_YELLOW << "This command does not exist." << C_NC << std::endl;
		}
	}
	return (0);
}
