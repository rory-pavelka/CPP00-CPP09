#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include <iostream>
#include <exception>
#include <string>

#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
	std::string const	target;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string const _target);
	ShrubberyCreationForm(ShrubberyCreationForm & other);
	ShrubberyCreationForm & operator=(ShrubberyCreationForm & other);
	virtual ~ShrubberyCreationForm();

	void execute(Bureaucrat const & executor) const;
};