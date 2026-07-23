#include "RPN.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Exactly one argument must be provided." << std::endl
		<< "Run ./RPN help to show usage." << std::endl;
		return 1;
	}

	if (std::string(argv[1]) == "help")
	{
		std::cerr
		<< "Run the program like this:" << std::endl
		<< "./RPN \"expression\"" << std::endl
		<< "where expression consists of numbers 0-9, +, -, *, /." << std::endl
		<< "The expression must be in \'Reverse Polish Notation\' format" << std::endl
		<< "and each token must be space-separated." << std::endl
		<< "Sample usage:" << std::endl
		<< "./RPN \"3 4 5 + -\"" << std::endl;
		return 0;
	}

	if (std::string(argv[1]) == "")
	{
		std::cerr << "Expression must not be an empty string." << std::endl;
		return 2;
	}

	try
	{
		runRPN(argv[1]);
	}
	catch (std::runtime_error & e)
	{
		std::cerr << e.what() << std::endl;
		return 3;
	}
	return 0;
}
