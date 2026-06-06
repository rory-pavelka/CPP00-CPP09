#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() :
name("Default"),
grade(150)
{}

Bureaucrat::Bureaucrat(std::string const _name, int _grade) :
name(_name)
{
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException(_grade);
	else if (_grade > 150)
		throw Bureaucrat::GradeTooLowException(_grade);
	else
		grade = _grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat & other) :
name(other.name)
{
	if (other.grade < 1)
		throw Bureaucrat::GradeTooHighException(other.grade);
	else if (other.grade > 150)
		throw Bureaucrat::GradeTooLowException(other.grade);
	else
		grade = other.grade;
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat & other)
{
	if (this == &other)
		return *this;

	if (other.grade < 1)
		throw Bureaucrat::GradeTooHighException(other.grade);
	else if (other.grade > 150)
		throw Bureaucrat::GradeTooLowException(other.grade);
	else
		grade = other.grade;

	return *this;
}

Bureaucrat::~Bureaucrat()
{}

std::string const Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

void Bureaucrat::setGrade(int _grade)
{
	grade = _grade;
}

void Bureaucrat::incrementGrade()
{
	if (grade < 2)
		throw Bureaucrat::GradeTooHighException(grade - 1);
	else
		grade--;
}

void Bureaucrat::decrementGrade()
{
	if (grade > 149)
		throw Bureaucrat::GradeTooLowException(grade + 1);
	else
		grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(int val) :
value(val)
{}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Requested grade is too high.";
}

int Bureaucrat::GradeTooHighException::getValue() const
{
	return value;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(int val) :
value(val)
{}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Requested grade is too low.";
}

int Bureaucrat::GradeTooLowException::getValue() const
{
	return value;
}
