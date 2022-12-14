#include <iostream>
#include <string>
#include <cctype>	// std::toupper

std::string	ToUpper(std::string	str) {
	for (std::string::size_type i = 0; i < str.length(); i++) {
		str[i] = std::toupper(str[i]);
	}
	return (str);
}

int	main(int argc, char *argv[]) {
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++) {
		std::cout << ToUpper(argv[i]);
	}
	std::cout << std::endl;
	return (0);
}
