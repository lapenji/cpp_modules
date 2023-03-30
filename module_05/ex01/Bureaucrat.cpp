#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("ciccio"), grade(15) {
	std::cout << "Basic constructor called!" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade) {
	if (this->grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	else if (this->grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	else
		std::cout << "Named constructor called, name: " << this->name << "grade: " << this->grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &toCopy) : name(toCopy.name), grade(toCopy.grade) {
	std::cout << "Copy constructor called!" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Destructor called!" << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &rhs) {
	if (this != &rhs) {
		this->grade = rhs.getGrade();
	}
	return (*this);
}

int	Bureaucrat::getGrade() const{
	return this->grade;
}

const std::string	Bureaucrat::getName() const {
	return this->name;
}

void	Bureaucrat::decrement() {
	if (this->grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	else
		this->grade--;
}

void	Bureaucrat::increment() {
	if (this->grade > 149) {
		throw Bureaucrat::GradeTooLowException();
	}
	else
		this->grade++;
}

const char * Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Bur: Grade too high!");
}

const char * Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Bur: Grade too low!");
}

void	Bureaucrat::signForm(Form &toSign) {
	if (this->getGrade() <= toSign.getGradeToSign()) {
		toSign.setSigned();
		std::cout << this->getName() << " signed " << toSign.getName() << std::endl;
	}
	else {
		std::cout << this->getName() << " could not sign " << toSign.getName() << " because " << std::endl;
		throw Bureaucrat::GradeTooLowException();
	}
}

std::ostream	&operator<<(std::ostream &ost, Bureaucrat const &toPrint ) {
	ost << toPrint.getName() << " Bureaucrat with grade " << toPrint.getGrade();
	return (ost);
}
