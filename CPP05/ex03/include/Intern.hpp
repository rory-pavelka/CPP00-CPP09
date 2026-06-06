#pragma once

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iostream>
#include <exception>
#include <string>

class Intern
{
public:
	Intern();
	Intern(Intern & other);
	Intern operator=(Intern & other);
	~Intern();

	AForm * makeForm(std::string formName, std::string formTarget);
};