#include "Form.hpp"

Form::Form() : name("innominato"), _signed(false), gradeToSign(150), gradeToExec(150) {
	std::cout << "Basic form created!" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExec) : name(name), _signed(false), gradeToSign(gradeToSign), gradeToExec(gradeToExec) {
	if (this->gradeToExec > 150 || this->gradeToSign > 150) {
		throw Form::GradeTooLowException();
	}
	else if (this->gradeToExec < 1 || this->gradeToSign < 1) {
		throw Form::GradeTooHighException();
	}
	std::cout << "Form created! with name: " << this->name << std::endl;
}

Form::Form(const Form &toCopy) : name(toCopy.name), _signed(toCopy._signed), gradeToSign(toCopy.gradeToSign) , gradeToExec(toCopy.gradeToExec){
	std::cout << "Copy constructor called!" << std::endl;
}

Form::~Form() {
	std::cout << "Destructor called on Form" << std::endl;
}

Form	&Form::operator=(const Form &rhs) {
	if (this != &rhs) {
		this->_signed = rhs._signed;
	}
	return (*this);
}

std::string	Form::getName() const {
	return (this->name);
}

bool		Form::getSigned() const {
	return (this->_signed);
}

int			Form::getGradeToSign() const {
	return (this->gradeToSign);
}

int		Form::getGradeToExec() const {
	return (this->gradeToExec);
}

void	Form::setSigned() {
	this->_signed = true;
}

void	Form::beSigned(const Bureaucrat &bur) {
	if (bur.getGrade() > this->getGradeToSign()) {
		throw Form::GradeTooHighException();
	}
	else {
		this->setSigned();
		std::cout << this->getName() << " signed by " << bur.getName() << std::endl;
	}
}

const char * Form::GradeTooLowException::what() const throw() {
	return ("Form: grade too low!");
}

const char * Form::GradeTooHighException::what() const throw() {
	return ("Form: grade too high!");
}

std::ostream	&operator<<( std::ostream &ost, Form const &toPrint) {
	ost << toPrint.getName() << "form, signed: " << toPrint.getSigned() << " grade to sign: " << toPrint.getGradeToSign() << " grade to exec: " << toPrint.getGradeToExec() << std::endl;
	return (ost);
}
