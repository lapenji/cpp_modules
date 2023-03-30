#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
	std::cout << "new WrongCat created!" << std::endl;
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat destructor called!" << std::endl;
}

void	WrongCat::makeSound() const {
	std::cout << "WrongCat meows!" << std::endl;
}

WrongCat::WrongCat(const WrongCat &toCopy) : WrongAnimal("cat") {
	*this = toCopy;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs) {
	if (this != &rhs) {
		this->type = rhs.type;
	}
	return (*this);
}
