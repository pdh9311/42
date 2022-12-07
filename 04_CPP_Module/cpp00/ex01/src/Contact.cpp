#include "Contact.hpp"

int Contact::GetIndex(void) {
	return (this->index_);
}

void Contact::SetIndex(int idx) {
	this->index_ = idx;
}

std::string& Contact::GetFirstName(void) {
	return (this->first_name_);
}

std::string& Contact::GetLastName(void) {
	return (this->last_name_);
}

std::string& Contact::GetNickName(void) {
	return (this->nickname_);
}

std::string& Contact::GetPhoneNumber(void) {
	return (this->phone_number_);
}

std::string& Contact::GetDarkestSecret(void) {
	return (this->darkest_secret_);
}
