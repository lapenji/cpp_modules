#include "Intern.hpp"

AForm	*Intern::makeForm(std::string name, std::string target) {

	int	i = 0;
	std::string	forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	while (i < 3) {
		if (forms[i] == name) {
			break;
		}
		i++;
	}
	switch (i) {
		case 0 :
			std::cout << "intern creates " << forms[0] << " module" << std::endl;
			return (new ShrubberyCreationForm(target));
			break;
		case 1 :
			std::cout << "intern creates " << forms[1] << " module" << std::endl;
			return (new RobotomyForm(target));
			break;
		case 2 :
			std::cout << "intern creates " << forms[2] << " module" << std::endl;
			return (new PresidentialPardonForm(target));
			break;
		default:
			std::cout << "intern can not find " << name << " form" << std::endl;
			return (NULL);
			break;
	}
}
