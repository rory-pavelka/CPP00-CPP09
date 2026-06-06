#include "Bureaucrat.hpp"

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

void ifExistsPrintElseError(Bureaucrat* b)
{
	if (b)
		std::cout << *b << std::endl;
	else
		std::cout << "Bureaucrat not created!" << std::endl;
}

Bureaucrat* tryIncrement(Bureaucrat* b)
{
	try
	{
		b->incrementGrade();
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

Bureaucrat* tryDecrement(Bureaucrat* b)
{
	try
	{
		b->decrementGrade();
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

int main()
{
	Bureaucrat* b1 = newBureaucrat("B1", 42);
	Bureaucrat* b2 = newBureaucrat("B2", 155);
	Bureaucrat* b3 = newBureaucrat("B3", -5);

	std::cout << std::endl;

	ifExistsPrintElseError(b1);
	ifExistsPrintElseError(b2);
	ifExistsPrintElseError(b3);

	delete b1;
	delete b2;
	delete b3;

	std::cout << std::endl;

	Bureaucrat* b4 = newBureaucrat("B4", 148);
	Bureaucrat* b5 = newBureaucrat("B5", 3);

	for (int i = 0; i < 4; i++)
	{
		b4 = tryDecrement(b4);
		ifExistsPrintElseError(b4);
		std::cout << std::endl;
	}
	for (int i = 0; i < 4; i++)
	{
		b5 = tryIncrement(b5);
		ifExistsPrintElseError(b5);
		std::cout << std::endl;
	}

	delete b4;
	delete b5;
}