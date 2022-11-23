#include "PhoneBook.hpp"

int PhoneBook::idx_ = 0;

void PhoneBook::Add(void) {
	Contact contact;

	std::cout << C_BLUE << "first name? " << C_NC;
	std::getline(std::cin, contact.GetFirstName());
	if (std::cin.eof())	return ;

	std::cout << C_BLUE << "last name? " << C_NC;
	std::getline(std::cin, contact.GetLastName());
	if (std::cin.eof())	return ;

	std::cout << C_BLUE << "nickname? " << C_NC;
	std::getline(std::cin, contact.GetNickName());
	if (std::cin.eof())	return ;

	std::cout << C_BLUE << "phone number? " << C_NC;
	std::getline(std::cin, contact.GetPhoneNumber());
	if (std::cin.eof())	return ;

	std::cout << C_BLUE << "darkest secret? " << C_NC;
	std::getline(std::cin, contact.GetDarkestSecret());
	if (std::cin.eof())	return ;

	contact.SetIndex(idx_ + 1);
	phonebook_[idx_ % 8] = contact;
	idx_++;
}

void PhoneBook::Search(void) {
	int range;

	range = idx_ > 8 ? 8 : idx_;
	std::cout << C_GREEN <<'|' << std::setw(10) << "index" << '|'
					<< std::setw(10) << "first name" << '|'
					<< std::setw(10) << "last name" << '|'
					<< std::setw(10) << "nickname" << '|' << C_NC << std::endl;
	for (int i = 0; i < range; i++) {
		std::cout << '|' << std::setw(10) << phonebook_[i].GetIndex() << '|'
						<< std::setw(10) << TenString(phonebook_[i].GetFirstName()) << '|'
						<< std::setw(10) << TenString(phonebook_[i].GetLastName()) << '|'
						<< std::setw(10) << TenString(phonebook_[i].GetNickName()) << '|' << std::endl;
	}

	while (true) {
		std::string search;
		int search_idx;

		std::cout << C_PURPLE << "search index? " << C_NC;
		std::getline(std::cin, search);
		if (std::cin.eof())	return ;
		search_idx = std::atoi(search.c_str());
		if (search.compare("exit") == 0) {
			break ;
		} else if (search_idx > 0) {
			Search(search_idx);
		} else {
			std::cout << C_YELLOW << "index는 0 보다 큰 양수만 가능합니다!" << C_NC << std::endl;
		}
	}
}

void PhoneBook::Search(int search) {
	int be;
	int range;

	be = false;
	range = idx_ > 8 ? 8 : idx_;
	for (int i = 0; i < range; i++) {
		if (phonebook_[i].GetIndex() == search)
			be = true;
	}
	if (be == false) {
		std::cout << C_YELLOW << search << " 는 오래되어 삭제되었거나 없는 index 값 입니다." << C_NC <<std::endl;
		return ;
	}
	std::cout << C_GREEN <<'|' << std::setw(10) << "index" << '|'
					<< std::setw(10) << "first name" << '|'
					<< std::setw(10) << "last name" << '|'
					<< std::setw(10) << "nickname" << '|' << C_NC << std::endl;

	std::cout << '|' << std::setw(10) << phonebook_[(search - 1) % 8].GetIndex() << '|'
			<< std::setw(10) << TenString(phonebook_[(search - 1) % 8].GetFirstName()) << '|'
			<< std::setw(10) << TenString(phonebook_[(search - 1) % 8].GetLastName()) << '|'
			<< std::setw(10) << TenString(phonebook_[(search - 1) % 8].GetNickName()) << '|' << std::endl;
}

std::string	PhoneBook::TenString(std::string str) {
	int	len;

	len = str.length();
	if (len > 10)
		return (str.replace(str.begin() + 9, str.end(), "."));
	return (str);
}
