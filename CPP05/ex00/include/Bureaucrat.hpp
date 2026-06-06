#pragma once

#include <iostream>
#include <exception>
#include <string>

class Bureaucrat
{
private:
	std::string const	name;
	int					grade;

public:
	Bureaucrat();
	Bureaucrat(std::string const _name, int _grade);
	Bureaucrat(const Bureaucrat & other);
	Bureaucrat & operator=(const Bureaucrat & other);
	~Bureaucrat();

	class GradeTooHighException : public std::exception
	{
	private:
		int value;
	public:
		GradeTooHighException(int val);
		virtual const char* what() const throw();
		int getValue() const;
	};

	class GradeTooLowException : public std::exception
	{
	private:
		int value;
	public:
		GradeTooLowException(int val);
		virtual const char* what() const throw();
		int getValue() const;
	};

	std::string const getName() const;
	int getGrade() const;
	void setGrade(int _grade);

	void incrementGrade();
	void decrementGrade();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
