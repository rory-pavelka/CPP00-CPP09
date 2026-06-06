#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
AForm("RobotomyRequestForm", 72, 45),
target("Default")
{}

RobotomyRequestForm::RobotomyRequestForm(std::string const _target) :
AForm("RobotomyRequestForm", 72, 45),
target(_target)
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm & other) :
AForm(other.target, 72, 45),
target(other.target)
{}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm & other)
{
	if (this == &other)
		return *this;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() <= 45 && getIsSigned())
	{
		std::cout
		<< executor.getName()
		<< " executed "
		<< this->getName()
		<< std::endl
		<< "* Drilling noises *"
		<< std::endl;
		if (rand() % 2 == 0)
		{
			std::cout
			<< this->target
			<< " has been robotomized successfully."
			<< std::endl;
		}
		else
		{
			std::cout
			<< this->target
			<< "'s robotomy failed."
			<< std::endl;
		}
	}
	else if (getIsSigned())
		throw AForm::BureaucratsGradeTooLowException(executor.getGrade());
	else
		throw AForm::FormNotSignedException(getIsSigned());
}
