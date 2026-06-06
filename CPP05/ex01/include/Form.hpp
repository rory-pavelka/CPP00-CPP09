#pragma once

#include "Bureaucrat.hpp"

#include <iostream>
#include <exception>
#include <string>

class Bureaucrat;

class Form
{
private:
	std::string const	name;
	bool				isSigned;
	int const			signGrade;
	int const			execGrade;

public:
	Form();
	Form(std::string const _name, int const _signGrade, int const _execGrade);
	Form(const Form & other);
	Form & operator=(const Form & other);
	~Form();

	std::string const	getName() const;
	bool				getIsSigned() const;
	int					getSignGrade() const;
	int					getExecGrade() const;

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

	void beSigned(Bureaucrat & signer);
};

std::ostream& operator<<(std::ostream& os, const Form& f);
