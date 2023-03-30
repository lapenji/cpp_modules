#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++) {
		this->list[i] = NULL;
	}
	std::cout << "MateriaSource constructor called!" << std::endl;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (this->list[i])
			delete (list[i]);
	}
	std::cout << "Materia source destructor called!" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const & toCopy) {
	*this = toCopy;
}

MateriaSource &MateriaSource::operator=( MateriaSource const & rhs) {
	if (this != &rhs) {
		for (int i = 0; i < 4; i++) {
			if (this->list[i])
				delete (list[i]);
		}
		for (int i = 0; i < 4; i++) {
			this->list[i] = rhs.list[i];
		}
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *amat) {
	for (int i = 0; i < 4; i++) {
		if (this->list[i] == NULL) {
			this->list[i] = amat;
			std::cout << "MateriaSource learned!" << std::endl;
			return ;
		}
	}
	std::cout << "MateriaSource can not learn!" << std::endl;
}

AMateria	*MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; i++) {
		if (list[i] != NULL && list[i]->getType() == type) {
			return list[i]->clone();
		}
	}
	return (NULL);
}
