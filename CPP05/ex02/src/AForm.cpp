#include "AForm.hpp"

AForm::AForm() :
name("Default"),
isSigned(false),
signGrade(1),
execGrade(1)
{}

static int validateGrade(int grade)
{
	if (grade < 1)
		throw AForm::GradeTooHighException(grade);
	else if (grade > 150)
		throw AForm::GradeTooLowException(grade);
	return grade;
}

AForm::AForm(std::string const _name) :
name(_name),
isSigned(false),
signGrade(validateGrade(0)),
execGrade(validateGrade(0))
{

}

AForm::AForm(std::string const _name, int const _signGrade, int const _execGrade) :
name(_name),
isSigned(false),
signGrade(validateGrade(_signGrade)),
execGrade(validateGrade(_execGrade))
{

}

AForm::AForm(const AForm & other) :
name(other.name),
isSigned(false),
signGrade(validateGrade(other.signGrade)),
execGrade(validateGrade(other.execGrade))
{}

AForm & AForm::operator=(const AForm & other)
{
	if (this == &other)
		return *this;
	return *this;
}

AForm::~AForm()
{}

std::ostream& operator<<(std::ostream& os, const AForm& f)
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

std::string const AForm::getName() const
{
	return name;
}

bool AForm::getIsSigned() const
{
	return isSigned;
}

int AForm::getSignGrade() const
{
	return signGrade;
}

int AForm::getExecGrade() const
{
	return execGrade;
}

AForm::GradeTooHighException::GradeTooHighException(int val) :
value(val)
{}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Requested grade is too high.";
}

int AForm::GradeTooHighException::getValue() const
{
	return value;
}

AForm::GradeTooLowException::GradeTooLowException(int val) :
value(val)
{}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Requested grade is too low.";
}

int AForm::GradeTooLowException::getValue() const
{
	return value;
}

AForm::BureaucratsGradeTooLowException::BureaucratsGradeTooLowException(int val) :
value(val)
{}

const char* AForm::BureaucratsGradeTooLowException::what() const throw()
{
	return "Grade of the Bureaucrat is too low.";
}

int AForm::BureaucratsGradeTooLowException::getValue() const
{
	return value;
}

AForm::FormNotSignedException::FormNotSignedException(bool _isSigned) :
isSigned(_isSigned)
{}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "The form is not yet signed.";
}

bool AForm::FormNotSignedException::getValue() const
{
	return isSigned;
}

void AForm::beSigned(Bureaucrat const & signer)
{
	if (signer.getGrade() <= this->signGrade)
	{
		this->isSigned = true;
		std::cout
		<< signer.getName()
		<< " signed "
		<< this->getName()
		<< "."
		<< std::endl;
	}
	else
		throw AForm::BureaucratsGradeTooLowException(signer.getGrade());
}
