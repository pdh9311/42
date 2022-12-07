#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <limits>
#include <cstring>

class Convert {
private:
	double value_;

	bool error_;

	char c_;
	int i_;
	float f_;
	double d_;

	Convert();
public:
	Convert(const char *str);
	Convert(const Convert &convert);
	~Convert();

	Convert& operator=(const Convert &convert);

	const double& getValue() const;
	const bool& getError() const;
	const char& getC() const;
	const int& getI() const;
	const float& getF() const;
	const double& getD() const;

	void printChar();
	void printInt();
	void printFloat();
	void printDouble();

	void printCovert();
};

#endif
