#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter & other)
{
	(void)(other);
}
ScalarConverter & ScalarConverter::operator=(const ScalarConverter & other)
{
	(void)(other);
	return (*this);
}
ScalarConverter::~ScalarConverter() {}

static int type(const char* str, std::string input)
{
	if (input == "-inff" || input == "+inff" || input == "nanf"
		|| input == "-inf" || input == "+inf" || input == "nan")
		return SPECIAL;
	int input_length = input.length();
	if (input_length == 0)
		return ERROR;
	if (str[0] == '\'' && str[2] == '\'' && input_length == 3)
		return CHAR;
	int i;
	for (i = 0; i < input_length; i++)
	{
		if (i == 0 && str[i] == '-')
			i++;
		if (!isdigit(str[i]))
		{
			if (!(str[i] == '.'))
				return ERROR;
			break;
		}
	}
	if (i == input_length)
	{
		if (input_length > 11
			|| atoll(input.c_str()) > std::numeric_limits<int>::max()
			|| atoll(input.c_str()) < std::numeric_limits<int>::min())
			return ERROR;
		else
			return INT;
	}
	int dot_count = 0;
	bool f_present = false;
	for (i = 0; i < input_length; i++)
	{
		if (i == 0 && str[i] == '-')
			i++;
		if (!isdigit(str[i]))
		{
			if (str[i] == '.')
				dot_count++;
			else if (i == (input_length - 1) && str[i] == 'f')
			{
				f_present = true;
				break;
			}
			else
				return ERROR;
		}
	}
	if (f_present && dot_count == 1)
		return FLOAT;
	if (dot_count == 1)
		return DOUBLE;
	return ERROR;
}

static void numToChar(int i)
{
	char c = 0;

	if (i < 0 || i > 127)
	{
		std::cout << "char   : the char is out of range";
	}
	else if (std::isprint(static_cast<unsigned char>(i)))
	{
		c = static_cast<char>(i);
		std::cout << "char   : '" << c << "'";
	}
	else
	{
		std::cout << "char   : the char is not printable";
	}
}

static void numToChar(float f)
{
	numToChar(static_cast<int>(f));
}

static void numToChar(double d)
{
	numToChar(static_cast<int>(d));
}

static void printInt(long long ll)
{
	if (ll > std::numeric_limits<int>::max()
			|| ll < std::numeric_limits<int>::min())
	{
		std::cout << "int    : the int is out of range" << std::endl;
	}
	else
	{
		std::cout << "int    : " << static_cast<int>(ll) << std::endl;
	}
}

static void printFloat(float f, bool str0, std::string point_zero)
{
	if (isinf(f))
	{
		if (str0)
			std::cout << "float  : -inff" << std::endl;
		else
			std::cout << "float  : inff" << std::endl;
	}
	else
	{
		std::cout
		<< "float  : " << std::setprecision(PRECISION) << f << point_zero << "f" << std::endl;
	}
}

static void printDouble(double d, bool str0, std::string point_zero)
{
	if (isinf(d))
	{
		if (str0)
			std::cout << "double : -inf" << std::endl;
		else
			std::cout << "double : inf" << std::endl;
	}
	else
	{
		std::cout
		<< "double : " << std::setprecision(PRECISION) << d << point_zero << std::endl;
	}
}

void ScalarConverter::convert(std::string input)
{
	const char* str = input.c_str();

	char	c;
	int		i;
	float	f;
	double	d;

	std::string point_zero_f = "";
	std::string point_zero_d = "";
	std::stringstream temp1;
	std::stringstream temp2;

	switch (type(str, input))
	{
	case ERROR:
		std::cout << "Invalid input" << std::endl;
		break;

	case CHAR:
		c = static_cast<char>(str[1]);
		std::cout
		<< "char   : \'" << c << "\'" << std::endl
		<< "int    : " << static_cast<int>(c) << std::endl
		<< "float  : " << static_cast<float>(c) << ".0f" << std::endl
		<< "double : " << static_cast<double>(c) << ".0" << std::endl
		<< std::endl;
		break;

	case INT:
		i = static_cast<int>(atoi(input.c_str()));
		numToChar(i);
		std::cout << std::endl
		<< "int    : " << i << std::endl
		<< "float  : " << std::setprecision(PRECISION) << static_cast<float>(i) << ".0" << "f" << std::endl
		<< "double : " << std::setprecision(PRECISION) << static_cast<double>(i) << ".0" << std::endl
		<< std::endl;
		break;

	case FLOAT:
		f = static_cast<float>(atof(input.substr(0, input.length() - 1).c_str()));

		temp1 << std::setprecision(PRECISION) << f;
		if (temp1.str().find('.') == std::string::npos)
			point_zero_f = ".0";

		temp2 << std::setprecision(PRECISION) << static_cast<double>(f);
		if (temp2.str().find('.') == std::string::npos)
			point_zero_d = ".0";

		numToChar(f);
		std::cout << std::endl;
		printInt(static_cast<long long>(f));
		printFloat(f, str[0] == '-', point_zero_f);
		printDouble(static_cast<double>(f), str[0] == '-', point_zero_d);
		std::cout << std::endl;
		break;

	case DOUBLE:
		d = static_cast<double>(strtod(input.c_str(), NULL));

		temp1 << std::setprecision(PRECISION) << static_cast<float>(d);
		if (temp1.str().find('.') == std::string::npos)
			point_zero_f = ".0";

		temp2 << std::setprecision(PRECISION) << d;
		if (temp2.str().find('.') == std::string::npos)
			point_zero_d = ".0";

		numToChar(d);
		std::cout << std::endl;
		printInt(static_cast<long long>(d));
		printFloat(static_cast<float>(d), str[0] == '-', point_zero_f);
		printDouble(d, str[0] == '-', point_zero_d);
		std::cout << std::endl;
		break;

	case SPECIAL:
		if (input == "-inf" || input == "-inff")
		{
			std::cout
			<< "char   : " << "impossible" << std::endl
			<< "int    : " << "impossible" << std::endl
			<< "float  : " << "-inff" << std::endl
			<< "double : " << "-inf" << std::endl
			<< std::endl;
		}
		else if (input == "+inf" || input == "+inff")
		{
			std::cout
			<< "char   : " << "impossible" << std::endl
			<< "int    : " << "impossible" << std::endl
			<< "float  : " << "+inff" << std::endl
			<< "double : " << "+inf" << std::endl
			<< std::endl;
		}
		else
		{
			std::cout
			<< "char   : " << "impossible" << std::endl
			<< "int    : " << "impossible" << std::endl
			<< "float  : " << "nanf" << std::endl
			<< "double : " << "nan" << std::endl
			<< std::endl;
		}
	}
}