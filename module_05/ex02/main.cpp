#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyForm.hpp"
#include <time.h>

void	sartel(Bureaucrat &br, AForm &af)
{
	std::cout << br.getName() << " and " << af.getName() << "." << std::endl;
	try
	{
		std::cout << "Signing " << br.getName() << "." << std::endl;
		br.signForm(af);
		std::cout << "Executing " << br.getName() << "." << std::endl;
		br.executeForm(af);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

int	main(void)
{
	Bureaucrat	*buro = new Bureaucrat("Malenia", 120);
	Bureaucrat	*buro1 = new Bureaucrat("Godrick", 50);
	Bureaucrat	*buro2 = new Bureaucrat("Margit", 146);

	AForm	*shrubbery = new ShrubberyCreationForm("cali");
	AForm	*robotomy = new RobotomyForm("Robot");
	AForm	*president = new PresidentialPardonForm("Başkanlik");

	sartel(*buro, *shrubbery);
	sartel(*buro, *robotomy);
	sartel(*buro, *president);

	sartel(*buro1, *shrubbery);
	sartel(*buro1, *robotomy);
	sartel(*buro1, *president);

	sartel(*buro2, *shrubbery);
	sartel(*buro2, *robotomy);
	sartel(*buro2, *president);
	delete buro1;
	delete buro2;
	delete shrubbery;
	delete robotomy;
	delete president;
	delete buro;
}
