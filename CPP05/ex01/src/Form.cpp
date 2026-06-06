#include "Form.hpp"

Form::Form() :
name("Default"),
isSigned(false),
signGrade(1),
execGrade(1)
{}

static int validateGrade(int grade)
{
	if (grade < 1)
		throw Form::GradeTooHighException(grade);
	else if (grade > 150)
		throw Form::GradeTooLowException(grade);
	return grade;
}

Form::Form(std::string const _name, int const _signGrade, int const _execGrade) :
name(_name),
isSigned(false),
signGrade(validateGrade(_signGrade)),
execGrade(validateGrade(_execGrade))
{

}

Form::Form(const Form & other) :
name(other.name),
isSigned(false),
signGrade(validateGrade(other.signGrade)),
execGrade(validateGrade(other.execGrade))
{}

Form & Form::operator=(const Form & other)
{
	if (this == &other)
		return *this;
	return *this;
}

Form::~Form()
{}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	if (f.getIsSigned())
		os << "Form " << f.getName() << ", already signed";
	else
	{
		os << "Form "
		<< f.getName()
		<< ", not yet signed, sign grade is "
		<< f.getSignGrade()
		<< " and execution grade is "
		<< f.getExecGrade()
		<< ".";
	}
	return os;
}

std::string const Form::getName() const
{
	return name;
}

bool Form::getIsSigned() const
{
	return isSigned;
}

int Form::getSignGrade() const
{
	return signGrade;
}

int Form::getExecGrade() const
{
	return execGrade;
}


Form::GradeTooHighException::GradeTooHighException(int val) :
value(val)
{}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Requested grade is too high.";
}

int Form::GradeTooHighException::getValue() const
{
	return value;
}

Form::GradeTooLowException::GradeTooLowException(int val) :
value(val)
{}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Requested grade is too low.";
}

int Form::GradeTooLowException::getValue() const
{
	return value;
}

void Form::beSigned(Bureaucrat & signer)
{
	if (signer.getGrade() <= this->signGrade)
	{
		this->isSigned = true;
		std::cout
		<< signer.getName()
		<< " signed "
		<< this->getName()
		<< std::endl;
	}
	else
		throw Form::GradeTooLowException(signer.getGrade());
}
