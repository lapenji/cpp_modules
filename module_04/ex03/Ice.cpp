#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << "Ice constructor called!" << std::endl;
}

Ice::~Ice() {
	std::cout << "Ice destructor called!" << std::endl;
}

Ice::Ice(Ice const &toCopy) : AMateria("ice") {
	*this = toCopy;
}

Ice	&Ice::operator=(Ice const &rhs) {
	if (this != &rhs) {
		this->type = rhs.type;
	}
	return (*this);
}

AMateria*	Ice::clone() const {
	return (new Ice());
}

void	Ice::use(ICharacter &target) const{
	std::cout << " * shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
