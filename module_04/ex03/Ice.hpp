#pragma once
#include "AMateria.hpp"

class Ice : public AMateria {
	public:
	Ice();
	~Ice();
	Ice(Ice const &toCopy);
	Ice&operator=(Ice const &rhs);
	AMateria *clone() const;
	void	use(ICharacter &target) const;
};
