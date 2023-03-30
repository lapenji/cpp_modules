#include "AForm.hpp"

AForm::AForm() : name("innominato"), _signed(false), gradeToSign(150), gradeToExec(150) {
	std::cout << "Basic AForm created!" << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExec) : name(name), _signed(false), gradeToSign(gradeToSign), gradeToExec(gradeToExec) {
	if (this->gradeToExec > 150 || this->gradeToSign > 150) {
		throw AForm::GradeTooLowException();
	}
	else if (this->gradeToExec < 1 || this->gradeToSign < 1) {
		throw AForm::GradeTooHighException();
	}
	std::cout << "AForm created! with name: " << this->name << std::endl;
}

AForm::AForm(const AForm &toCopy) : name(toCopy.name), _signed(toCopy._signed), gradeToSign(toCopy.gradeToSign) , gradeToExec(toCopy.gradeToExec){
	std::cout << "Copy constructor called!" << std::endl;
}

AForm::~AForm() {
	std::cout << "Destructor called on AForm" << std::endl;
}

AForm	&AForm::operator=(const AForm &rhs) {
	if (this != &rhs) {
		this->_signed = rhs._signed;
	}
	return (*this);
}

std::string	AForm::getName() const {
	return (this->name);
}

bool		AForm::getSigned() const {
	return (this->_signed);
}

int			AForm::getGradeToSign() const {
	return (this->gradeToSign);
}

int		AForm::getGradeToExec() const {
	return (this->gradeToExec);
}

void	AForm::setSigned() {
	this->_signed = true;
}

void	AForm::beSigned(const Bureaucrat &bur) {
	if (bur.getGrade() > this->getGradeToSign()) {
		throw AForm::GradeTooHighException();
	}
	else {
		this->setSigned();
		std::cout << this->getName() << " signed by " << bur.getName() << std::endl;
	}
}

bool	AForm::execute(Bureaucrat const & executor) const {
	std::cout << this->_signed << std::endl;
	if (this->_signed != true) {
		std::cout << "Cannot execute form because is not signed!" << std::endl;
		return (false);
	}
	if (executor.getGrade() > this->gradeToExec) {
		throw AForm::GradeTooLowException();
		return (false);
	}
	this->execute();
	return (true);
}


const char * AForm::GradeTooLowException::what() const throw() {
	return ("AForm: grade too low!");
}

const char * AForm::GradeTooHighException::what() const throw() {
	return ("AForm: grade too high!");
}

std::ostream	&operator<<( std::ostream &ost, AForm const &toPrint) {
	ost << toPrint.getName() << "AForm, signed: " << toPrint.getSigned() << " grade to sign: " << toPrint.getGradeToSign() << " grade to exec: " << toPrint.getGradeToExec() << std::endl;
	return (ost);
}
