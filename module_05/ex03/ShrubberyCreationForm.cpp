#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm() {
	std::cout << "Standard Shrubbery constructor called!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery", 145, 149) {
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &toCopy) : AForm(toCopy) {
	this->target = toCopy.target;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "Destructor called on Shrubbery" << std::endl;
}

std::string	ShrubberyCreationForm::getTarget() {
	return (this->target);
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
	if (this != &rhs) {
		this->target = rhs.target;
	}
	return (*this);
}

void	ShrubberyCreationForm::execute() const {
	std::string	fileName;

	fileName = this->target + "_shrubbery";
	std::ofstream output(fileName.c_str(), std::ios::out);
	output << "    .     .  .      +     .      .          .\n"
			  "     .       .      .     #       .           .\n"
			  "        .      .         ###            .      .      .\n"
			  "      .      .   \"#:. .:##\"##:. .:#\"  .      .\n"
			  "          .      . \"####\"###\"####\"  .\n"
			  "       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       .\n"
			  "  .             \"#########\"#########\"        .        .\n"
			  "        .    \"#:.  \"####\"###\"####\"  .:#\"   .       .\n"
			  "     .     .  \"#######\"\"##\"##\"\"#######\"                  .\n"
			  "                .\"##\"#####\"#####\"##\"           .      .\n"
			  "    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     .\n"
			  "      .     \"#######\"##\"#####\"##\"#######\"      .     .\n"
			  "    .    .     \"#####\"\"#######\"\"#####\"    .      .\n"
			  "            .     \"      000      \"    .     .\n"
			  "       .         .   .   000     .        .       .\n"
			  ".. .. ..................O000O." << std::endl;
	output.close();
	std::cout << "Shrubbery executed!" << std::endl;
}
