#include "Animal.hpp"

Animal::Animal(void) : type("generic") {
	std::cout << "Called constructor on Animal class" << std::endl;
}

Animal::Animal(std::string type) : type(type){
	std::cout << "Called type constructor on Animal class" << std::endl;
}
Animal::~Animal() {
	std::cout << "Animal type " << this->type <<  " destroyed!" << std::endl;
}

Animal::Animal(const Animal &toCopy) {
	std::cout << "Animal copy constructor called!" << std::endl;
	*this = toCopy;
}

Animal &Animal::operator=(const Animal &rhs) {
	if (this != &rhs) {
		this->type = rhs.type;
	}
	return (*this);
}

std::string	Animal::getType() const{
	return (this->type);
}

void	Animal::makeSound() const {
	std::cout << "Generica animal made a sound" << std::endl;
}
