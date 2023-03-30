#pragma once
#include <iostream>

class WrongAnimal {
	protected:
	std::string type;
	public:
	WrongAnimal(void);
	WrongAnimal(std::string type);
	~WrongAnimal(void);
	WrongAnimal(const WrongAnimal &toCopy);
	WrongAnimal &operator=(const WrongAnimal &rhs);
	std::string getType();
	void	makeSound() const;
};
