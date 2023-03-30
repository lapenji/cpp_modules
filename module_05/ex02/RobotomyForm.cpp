#include "RobotomyForm.hpp"

RobotomyForm::RobotomyForm() : AForm("RobotomyForm", 72, 45) {
	this->target = "unknown";
}

RobotomyForm::RobotomyForm(std::string target) : AForm("RobotomyForm", 72, 45) {
	this->target = target;
}

RobotomyForm::RobotomyForm(const RobotomyForm &toCopy) : AForm(toCopy) {
	this->target = toCopy.target;
}

RobotomyForm::~RobotomyForm() {
	std::cout << "destructor called on RobotomyForm" << std::endl;
}

RobotomyForm	&RobotomyForm::operator=(const RobotomyForm &rhs) {
	if (this != &rhs) {
		this->target = rhs.target;
	}
	return *this;
}

std::string	RobotomyForm::getTarget() {
	return (this->target);
}

void	RobotomyForm::execute() const {
	std::cout << "BZZZ BZZZ BZZZ" << std::endl;
	static int n;
	if (n % 2 == 0) {
		std::cout << this->target << " has been robotomized successfully!" << std::endl;
	}
	else {
		std::cout << this->target << " robotomy failed ):" << std::endl;
	}
	n++;
}
