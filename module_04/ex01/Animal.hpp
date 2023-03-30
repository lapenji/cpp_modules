#pragma once
#include <iostream>

class Animal {
	protected:
	std::string type;
	public:
	Animal(void);
	Animal(std::string type);
	virtual ~Animal(void);
	Animal(const Animal &toCopy);
	Animal &operator=(const Animal &rhs);
	std::string	getType() const;
	virtual void	makeSound() const;
};
