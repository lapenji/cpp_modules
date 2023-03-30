#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
	std::cout << "new Dog created!" << std::endl;
}

Dog::~Dog(void) {
	std::cout << "Cat destructor called!" << std::endl;
}

Dog::Dog(const Dog &toCopy) : Animal("Dog") {
	*this = toCopy;
}

Dog &Dog::operator=(const Dog &rhs) {
	if (this != &rhs) {
		this->type = rhs.type;
	}
	return (*this);
}
void	Dog::makeSound() const {
	std::cout << "Dog barks!" << std::endl;
}
