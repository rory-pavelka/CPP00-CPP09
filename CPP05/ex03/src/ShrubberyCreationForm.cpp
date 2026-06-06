#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
AForm("ShrubberyCreationForm", 145, 137),
target("Default")
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const _target) :
AForm("ShrubberyCreationForm", 145, 137),
target(_target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm & other) :
AForm(other.target, 145, 137),
target(other.target)
{}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm & other)
{
	if (this == &other)
		return *this;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() <= 137 && getIsSigned())
	{
		std::ofstream file;
		file.open((target + "_shrubbery").c_str());
		file
		<< "ex00\n"
		<< "├── include\n"
		<< "│   └── Bureaucrat.hpp\n"
		<< "├── Makefile\n"
		<< "└── src\n"
		<< "    ├── Bureaucrat.cpp\n"
		<< "    └── main.cpp\n";
		file.close();
		std::cout
		<< executor.getName()
		<< " executed "
		<< this->getName()
		<< std::endl;
	}
	else if (getIsSigned())
		throw AForm::BureaucratsGradeTooLowException(executor.getGrade());
	else
		throw AForm::FormNotSignedException(getIsSigned());
}
