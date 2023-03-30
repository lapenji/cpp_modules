#pragma once
#include "AForm.hpp"
#include <iostream>

class RobotomyForm : public AForm {
	private:
	std::string	target;
	public:
	RobotomyForm();
	RobotomyForm(std::string target);
	RobotomyForm(const RobotomyForm &toCopy);
	~RobotomyForm();
	RobotomyForm &operator=(const RobotomyForm &rhs);
	std::string	getTarget();
	void		execute() const;
};
