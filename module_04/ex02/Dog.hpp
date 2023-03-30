#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal {
	private:
	Brain	*cervello;
	public:
	Dog(void);
	~Dog(void);
	Dog(const Dog &toCopy);
	Dog &operator=(const Dog &rhs);

	void makeSound() const;
};
