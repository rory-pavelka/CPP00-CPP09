#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
AForm("PresidentialPardonForm", 25, 5),
target("Default")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string const _target) :
AForm("PresidentialPardonForm", 25, 5),
target(_target)
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm & other) :
AForm(other.target, 25, 5),
target(other.target)
{}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm & other)
{
	if (this == &other)
		return *this;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() <= 5 && getIsSigned())
	{
		std::cout
		<< executor.getName()
		<< " executed "
		<< this->getName()
		<< ".\n"
		<< this->target
		<< " has been pardoned by Zaphod Beeblebrox."
		<< std::endl;
	}
	else if (getIsSigned())
		throw AForm::BureaucratsGradeTooLowException(executor.getGrade());
	else
		throw AForm::FormNotSignedException(getIsSigned());
}
