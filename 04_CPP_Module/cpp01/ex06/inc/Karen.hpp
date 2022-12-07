#ifndef KAREN_HPP
# define KAREN_HPP

# include <iostream>
# include <string>
# include "Color.hpp"

class Karen
{
private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

public:
	const static std::string COMMENTS[4];
	void complain(const std::string &level);
	void filter(const std::string &level);
};

#endif