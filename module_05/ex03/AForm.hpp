#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
	const std::string	name;
	bool				_signed;
	const int			gradeToSign;
	const int			gradeToExec;
	public:
	AForm();
	AForm(std::string name, int gradeToSign, int gradeToExec);
	AForm(const AForm &toCopy);
	virtual ~AForm();
	AForm		&operator=(const AForm &rhs);
	std::string	getName() const;
	bool			getSigned() const;
	int				getGradeToSign() const;
	int				getGradeToExec() const;
	void			setSigned();
	void			setGradeToSign(int grade) const;
	void			setGradeToExec(int grade) const;
	void			setName(const std::string name) const;
	void			beSigned(const Bureaucrat &bur);
	virtual void	execute() const=0;
	virtual bool	execute(Bureaucrat const & executor) const;
	class GradeTooHighException : public std::exception {
		public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
		virtual const char* what() const throw();
	};
};

std::ostream	&operator<<( std::ostream &ost, AForm const &toPrint);
