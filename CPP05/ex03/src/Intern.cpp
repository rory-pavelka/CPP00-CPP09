#include "Intern.hpp"

Intern::Intern()
{}

Intern::Intern(Intern & other)
{
	(void)other;
}

Intern Intern::operator=(Intern & other)
{
	(void)other;
	return *this;
}

Intern::~Intern()
{}

AForm * Intern::makeForm(std::string formName, std::string formTarget)
{
	AForm * result;
	if (formName == "PresidentialPardonForm")
	{
		result = new PresidentialPardonForm(formTarget);
		return (result);
	}
	else if (formName == "RobotomyRequestForm")
	{
		result = new RobotomyRequestForm(formTarget);
		return (result);
	}
	else if (formName == "ShrubberyCreationForm")
	{
		result = new ShrubberyCreationForm(formTarget);
		return (result);
	}
	else
	{
		throw AForm::FormNameDoesNotExistException(formName);
	}
}