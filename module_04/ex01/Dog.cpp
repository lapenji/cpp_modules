#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
	std::cout << "new Dog created!" << std::endl;
	this->cervello = new Brain();
}

Dog::~Dog(void) {
	std::cout << "Cat destructor called!" << std::endl;
	delete this->cervello;

}

void	Dog::makeSound() const {
	std::cout << "Dog barks!" << std::endl;
}

Dog::Dog(const Dog &toCopy) : Animal("Dog") {
	*this = toCopy;
}

Dog &Dog::operator=(const Dog &rhs) {
	if (this != &rhs) {
		this->type = rhs.type;
		this->cervello = rhs.cervello;
	}
	return (*this);
}
