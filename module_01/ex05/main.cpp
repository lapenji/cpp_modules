#include "Harl.hpp"

int main( void ) {

	std::string	input;
	Harl		harl;

	while (input.compare("exit"))
	{
		std::cout << "Enter a level (DEBUG, INFO, WARNING, ERROR), or exit to quit: ";
		std::cin >> input;
		harl.complain(input);
	}

	return (0);
}
