#pragma once

#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <math.h>
#include <limits>
#include <sstream>

#define PRECISION 10

enum types
{
	ERROR = 0,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	SPECIAL
};

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter & other);
	ScalarConverter & operator=(const ScalarConverter & other);
	~ScalarConverter();
public:
	static void convert(std::string input);
};
