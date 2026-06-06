#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

Bureaucrat* newBureaucrat(std::string name, int grade)
{
	Bureaucrat* b = NULL;

	try
	{
		b = new Bureaucrat(name, grade);
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cout
		<< "Exception caught: "
		<< e.what()
		<< " Value = "
		<< e.getValue()
		<< std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cout
		<< "Exception caught: "
		<< e.what()
		<< " Value = "
		<< e.getValue()
		<< std::endl;
	}
	return b;
}

PresidentialPardonForm* newPresidentialPardonForm(std::string target)
{
	PresidentialPardonForm* f = NULL;

	try
	{
		f = new PresidentialPardonForm(target);
	}
	catch (AForm::GradeTooHighException& e)
	{
		std::cout
		<< "Exception caught: "
		<< e.what()
		<< " Value = "
		<< e.getValue()
		<< std::endl;
	}
	catch (AForm::GradeTooLowException& e)
	{
		std::cout
		<< "Exception caught: "
		<< e.what()
		<< " Value = "
		<< e.getValue()
		<< std::endl;
	}
	return f;
}

RobotomyRequestForm* newRobotomyRequestForm(std::string target)
{
	RobotomyRequestForm* f = NULL;

	try
	{
		f = new RobotomyRequestForm(target);
	}
	catch (AForm::GradeTooHighException& e)
	{
		std::cout
		<< "Exception caught: "
		<< e.what()
		<< " Value = "
		<< e.getValue()
		<< std::endl;
	}
	catch (AForm::GradeTooLowException& e)
	{
		std::cout
		<< "Exception caught: "
		<< e.what()
		<< " Value = "
		<< e.getValue()
		<< std::endl;
	}
	return f;
}

ShrubberyCreationForm* newShrubberyCreationForm(std::string target)
{
	ShrubberyCreationForm* f = NULL;

	try
	{
		f = new ShrubberyCreationForm(target);
	}
	catch (AForm::GradeTooHighException& e)
	{
		std::cout
		<< "Exception caught: "
		<< e.what()
		<< " Value = "
		<< e.getValue()
		<< std::endl;
	}
	catch (AForm::GradeTooLowException& e)
	{
		std::cout
		<< "Exception caught: "
		<< e.what()
		<< " Value = "
		<< e.getValue()
		<< std::endl;
	}
	return f;
}

AForm* internCreatedForm(Intern i, std::string formName, std::string formTarget)
{
	AForm* f = NULL;
	try
	{
		f = i.makeForm(formName, formTarget);
	}
	catch (AForm::FormNameDoesNotExistException &e)
	{
		std::cout
		<< "Exception caught: "
		<< e.what()
		<< "\nRequested form name \""
		<< e.getValue()
		<< "\" does not exist."
		<< std::endl;
	}
	return f;
}

int main()
{
	srand(time(NULL));

	Intern i;
	AForm* f1;
	AForm* f2;
	AForm* f3;
	AForm* f4;
	AForm* f5;

	f1 = internCreatedForm(i, "ShrubberyCreationForm", "target");
	f2 = internCreatedForm(i, "RobotomyRequestForm", "target");
	f3 = internCreatedForm(i, "PresidentialPardonForm", "target");
	f4 = internCreatedForm(i, "invalidName", "target");
	f5 = internCreatedForm(i, "", "target");

	Bureaucrat* b20 = newBureaucrat("Bureaucrat20", 20);
	Bureaucrat* b100 = newBureaucrat("Bureaucrat100", 100);
	Bureaucrat* root = newBureaucrat("root", 1);

	std::cout << std::endl;

	b100->executeForm(*f1);
	b100->signForm(*f1);
	b100->executeForm(*f1);

	std::cout << std::endl;

	b100->signForm(*f2);
	b20->signForm(*f2);
	b20->executeForm(*f2);

	std::cout << std::endl;

	b20->signForm(*f3);
	b20->executeForm(*f3);
	root->executeForm(*f3);

	delete f1;
	delete f2;
	delete f3;
	delete f4;
	delete f5;
	delete b100;
	delete b20;
	delete root;
}
