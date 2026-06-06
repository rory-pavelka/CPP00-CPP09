#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include <iostream>
#include <exception>
#include <string>

#include <stdlib.h>
#include <time.h>

class RobotomyRequestForm : public AForm
{
private:
	std::string const	target;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string const _target);
	RobotomyRequestForm(RobotomyRequestForm & other);
	RobotomyRequestForm & operator=(RobotomyRequestForm & other);
	virtual ~RobotomyRequestForm();

	void execute(Bureaucrat const & executor) const;
};