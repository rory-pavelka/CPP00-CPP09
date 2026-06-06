#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

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

int main()
{
	srand(time(NULL));

	Bureaucrat* b = newBureaucrat("Bureaucrat", 30);

	AForm* f = newShrubberyCreationForm("Subject");
	b->signForm(*f);
	std::cout << std::endl;
	b->executeForm(*f);
	std::cout << std::endl;

	AForm* f1 = newRobotomyRequestForm("Subject1");
	AForm* f2 = newRobotomyRequestForm("Subject2");
	AForm* f3 = newRobotomyRequestForm("Subject3");
	AForm* f4 = newRobotomyRequestForm("Subject4");

	b->signForm(*f1);
	std::cout << std::endl;
	b->executeForm(*f1);
	std::cout << std::endl;
	b->signForm(*f2);
	std::cout << std::endl;
	b->executeForm(*f2);
	std::cout << std::endl;
	b->signForm(*f3);
	std::cout << std::endl;
	b->executeForm(*f3);
	std::cout << std::endl;
	b->signForm(*f4);
	std::cout << std::endl;
	b->executeForm(*f4);
	std::cout << std::endl;

	delete b;
	delete f;
	delete f1;
	delete f2;
	delete f3;
	delete f4;

	Bureaucrat* b0 = newBureaucrat("Bureaucrat0", 30);
	Bureaucrat* b1 = newBureaucrat("Bureaucrat1", 20);
	Bureaucrat* b2 = newBureaucrat("Bureaucrat2", 3);
	AForm* f5 = newPresidentialPardonForm("Subject");

	b0->signForm(*f5);
	std::cout << std::endl;
	b1->signForm(*f5);
	std::cout << std::endl;
	b1->executeForm(*f5);
	std::cout << std::endl;
	b2->executeForm(*f5);
	std::cout << std::endl;

	delete b0;
	delete b1;
	delete b2;
	delete f5;
}
