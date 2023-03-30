
#pragma once
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	private:
	AMateria *	list[4];

	public:
	MateriaSource();
	~MateriaSource();
	MateriaSource(const MateriaSource &toCopy);
	MateriaSource &operator=(const MateriaSource &rhs);
	void	learnMateria(AMateria* amat);
	AMateria	*createMateria(std::string const &type);
};
