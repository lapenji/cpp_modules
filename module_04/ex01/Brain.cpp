#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain created!" << std::endl;
}

Brain::~Brain() {
	std::cout << "Brain destroyed!" << std::endl;
}

Brain::Brain(const Brain &toCopy) {
	std::cout << "Brain copied!" << std::endl;
	*this = toCopy;
}

Brain &Brain::operator=(const Brain &rhs) {
	if (this != &rhs) {
		for (int i = 0; i < 100; i++){
			this->ideas[i] = rhs.ideas[i];
		}
	}
	return (*this);
}
