#pragma once

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyForm.hpp"

class Intern
{
	public:
	Intern() { };
	~Intern() { };
	Intern(Intern const &) { };
	Intern &operator=(Intern const &) { return *this; };

	AForm	*makeForm(std::string name, std::string target);
};
