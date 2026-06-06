#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include <iostream>
#include <exception>
#include <string>

class PresidentialPardonForm : public AForm
{
private:
	std::string const	target;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string const _target);
	PresidentialPardonForm(PresidentialPardonForm & other);
	PresidentialPardonForm & operator=(PresidentialPardonForm & other);
	virtual ~PresidentialPardonForm();

	void execute(Bureaucrat const & executor) const;
};