#include "AMateria.hpp"

AMateria::AMateria() {
	std::cout << "AMateria standard constructor called!" << std::endl;
}

AMateria::AMateria(std::string const &type) : type(type) {
	std::cout << "AMateria constructor called with " << this->type << std::endl;
}

AMateria::AMateria(const AMateria &toCopy) {
	*this = toCopy;
}

AMateria::~AMateria(void) {
	std::cout << "AMateria destructor called!" << std::endl;
}

AMateria	&AMateria::operator=(const AMateria & rhs) {
	if (this != &rhs) {
		this->type = rhs.type;
	}
	return (*this);
}

std::string const &AMateria::getType() const {
	return (this->type);
}

void	AMateria::use(ICharacter &target) const {
	std::cout << "Amateria " << this->type << " used on " << target.getName() << std::endl;
}
