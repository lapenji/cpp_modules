#pragma once
#include <iostream>

class Animal {
	protected:
	std::string type;
	Animal(void);
	Animal(std::string type);
	virtual ~Animal(void);
	Animal(const Animal &toCopy);
	Animal &operator=(const Animal &rhs);
	public:
	std::string	getType() const;
	virtual void	makeSound() const;
};
