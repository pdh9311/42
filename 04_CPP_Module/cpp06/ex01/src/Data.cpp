#include "Data.hpp"

Data::Data() : data_("test") {}

Data::Data(const Data &data) {
	*this = data;
}

Data::~Data() {}

Data& Data::operator=(const Data &data) {
	data_ = data.getData();
	return (*this);
}

const std::string& Data::getData() const {
	return (data_);
}

uintptr_t serialize(Data *ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}