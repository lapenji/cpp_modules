#pragma once
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat {
	private:
	const std::string	name;
	int					grade;
	public:
	Bureaucrat();
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat &toCopy);
	~Bureaucrat();
	Bureaucrat	&operator=(const Bureaucrat &rhs);
	const std::string	getName() const;
	int					getGrade() const;
	void				decrement();
	void				increment();
	void				signForm(Form &toSign);
	class GradeTooHighException : public std::exception {
		public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
		virtual const char* what() const throw();
	};
};

std::ostream	&operator<<( std::ostream &ost, Bureaucrat const &toPrint);
