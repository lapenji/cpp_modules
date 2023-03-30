#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("generic"){
	std::cout << "WrongAnimal default constructor called!" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type){
	std::cout << "WrongAnimal type constructor called with " << this->type << std::endl;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "Wrong animal destructor called!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &toCopy) {
	std::cout << "WrongAnimal copy constructor called!" << std::endl;
	*this = toCopy;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs) {
	if (this != &rhs) {
		this->type = rhs.type;
	}
	return (*this);
}

void	WrongAnimal::makeSound(void) const{
	std::cout << "WrongAnimal sound called" << std::endl;
}
