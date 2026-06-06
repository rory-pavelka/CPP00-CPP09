#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <cstdlib>

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

Form* newForm(std::string name, int signGrade, int execGrade)
{
	Form* f = NULL;

	try
	{
		f = new Form(name, signGrade, execGrade);
	}
	catch (Form::GradeTooHighException& e)
	{
		std::cout
		<< "Exception caught: "
		<< e.what()
		<< " Value = "
		<< e.getValue()
		<< std::endl;
	}
	catch (Form::GradeTooLowException& e)
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
	Bureaucrat* b = newBureaucrat("B1", 150);
	Form* f = newForm("F1", 40, 20);
	b->signForm(*f);

	delete b;
	delete f;

	std::cout << std::endl;

	Bureaucrat* b2 = newBureaucrat("B2", 1);
	Form* f2 = newForm("F2", 40, 20);
	b2->signForm(*f2);

	delete b2;
	delete f2;

	return 0;
}
