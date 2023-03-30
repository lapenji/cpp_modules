#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {

	private:
	Brain	*cervello;

	public:
	Cat(void);
	~Cat(void);
	Cat(const Cat &toCopy);
	Cat &operator=(const Cat &rhs);

	void makeSound() const;
};
