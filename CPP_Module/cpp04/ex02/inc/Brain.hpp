#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "Color.hpp"
# include <iostream>
# include <string>
# include <ctime>
# include <cstdlib>

# define IDEA_SIZE 100

class Brain {
private:
	std::string ideas_[IDEA_SIZE];

	std::string randomIdea();
public:
	Brain();
	Brain(const Brain& brain);
	~Brain();

	Brain& operator=(const Brain& brain);

	const std::string* getIdeas() const;
	std::string getIdeasIdx(int index) const;
	void setIdeasIdx(std::string idea, int index);

};

#endif
