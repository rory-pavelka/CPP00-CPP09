#pragma once

#include "Bureaucrat.hpp"

#include <iostream>
#include <exception>
#include <string>

class Bureaucrat;

class AForm
{
private:
	std::string const	name;
	bool				isSigned;
	int const			signGrade;
	int const			execGrade;

public:
	AForm();
	AForm(std::string const _name);
	AForm(std::string const _name, int const _signGrade, int const _execGrade);
	AForm(const AForm & other);
	AForm & operator=(const AForm & other);
	virtual ~AForm();

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

	class BureaucratsGradeTooLowException : public std::exception
	{
	private:
		int value;
	public:
		BureaucratsGradeTooLowException(int val);
		virtual const char* what() const throw();
		int getValue() const;
	};

	class FormNotSignedException : public std::exception
	{
	private:
		bool isSigned;
	public:
		FormNotSignedException(bool _isSigned);
		virtual const char* what() const throw();
		bool getValue() const;
	};

	virtual void beSigned(Bureaucrat const & signer);
	virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& f);
