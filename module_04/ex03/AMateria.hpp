#pragma once
#include <iostream>
#include "ICharacter.hpp"

class AMateria {
	protected:
	std::string	type;
	public:
	AMateria();
	AMateria(std::string const & type);
	AMateria( const AMateria &toCopy);
	virtual ~AMateria(void);
	AMateria &operator=(const AMateria &rhs);
	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target) const;
};
