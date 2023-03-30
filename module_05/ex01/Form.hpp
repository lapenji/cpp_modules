#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
	const std::string	name;
	bool				_signed;
	const int			gradeToSign;
	const int			gradeToExec;
	public:
	Form();
	Form(std::string name, int gradeToSign, int gradeToExec);
	Form(const Form &toCopy);
	~Form();
	Form		&operator=(const Form &rhs);
	std::string	getName() const;
	bool		getSigned() const;
	int			getGradeToSign() const;
	int			getGradeToExec() const;
	void		setSigned();
	void		beSigned(const Bureaucrat &bur);
	class GradeTooHighException : public std::exception {
		public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
		virtual const char* what() const throw();
	};
};

std::ostream	&operator<<( std::ostream &ost, Form const &toPrint);
