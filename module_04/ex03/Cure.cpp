#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	std::cout << "Cure constructor called!" << std::endl;
}

Cure::~Cure() {
	std::cout << "Cure destructor called!" << std::endl;
}

Cure::Cure(Cure const &toCopy) : AMateria("cure") {
	*this = toCopy;
}

Cure	&Cure::operator=(Cure const &rhs) {
	if (this != &rhs) {
		this->type = rhs.type;
	}
	return (*this);
}

AMateria*	Cure::clone() const {
	return (new Cure());
}

void	Cure::use(ICharacter &target) const{
	std::cout << " * heals " << target.getName() << " wounds *" << std::endl;
}
