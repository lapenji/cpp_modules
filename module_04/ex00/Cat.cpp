#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") {
	std::cout << "new Cat created!" << std::endl;
}

Cat::~Cat(void) {
	std::cout << "Cat destructor called!" << std::endl;
}

Cat::Cat(const Cat &toCopy) : Animal("cat") {
	*this = toCopy;
}

Cat &Cat::operator=(const Cat &rhs) {
	if (this != &rhs) {
		this->type = rhs.type;
	}
	return (*this);
}

void	Cat::makeSound() const {
	std::cout << "Cat meows!" << std::endl;
}
