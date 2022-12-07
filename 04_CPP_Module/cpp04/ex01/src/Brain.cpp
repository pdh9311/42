#include "Brain.hpp"

Brain::Brain() {
	for (int i = 0; i < IDEA_SIZE; ++i) {
		this->ideas_[i] = randomIdea();
	}
	std::cout << C_BLUE <<  "Brain " << C_GREEN << "Default Constructor" << C_NC << std::endl;
}

Brain::Brain(const Brain& brain) {
	*this = brain;
	std::cout << C_BLUE <<  "Brain " << C_GREEN << "Copy Constructor" << C_NC << std::endl;
}

Brain::~Brain() {
	std::cout << C_BLUE <<  "Brain " << C_RED << "Destructor" << C_NC << std::endl;
}

Brain& Brain::operator=(const Brain &brain) {
	for (int i = 0; i < IDEA_SIZE; ++i) {
		this->ideas_[i] = brain.getIdeasIdx(i);
	}
	return (*this);
}

const std::string* Brain::getIdeas() const {
	return (this->ideas_);
}

std::string Brain::getIdeasIdx(int index) const {
	return (this->ideas_[index]);
}

void Brain::setIdeasIdx(std::string idea, int index) {
	this->ideas_[index] = idea;
}

std::string Brain::randomIdea() {
	const std::string alpabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz";
	const int ideaLen = std::rand() % 6 + 1;


	std::string randIdea(ideaLen, '\0');
	for (std::string::iterator itr = randIdea.begin(); itr != randIdea.end(); ++itr) {
		*itr = alpabet.at(std::rand() % alpabet.size());
	}
	return (randIdea);
}
