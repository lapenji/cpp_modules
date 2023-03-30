#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) {
	this->target = "unknown";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5) {
	this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &toCopy) : AForm(toCopy) {
	this->target = toCopy.target;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "destructor called on PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
	if (this != &rhs) {
		this->target = rhs.target;
	}
	return *this;
}

std::string	PresidentialPardonForm::getTarget() {
	return (this->target);
}

void	PresidentialPardonForm::execute() const {
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
