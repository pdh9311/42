#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <cstdint>
# include <string>

class Data {
private:
	std::string data_;

public:
	Data();
	Data(const Data &data);
	~Data();

	Data& operator=(const Data &data);

	const std::string& getData() const;
};

uintptr_t serialize(Data *ptr);
Data* deserialize(uintptr_t raw);

#endif