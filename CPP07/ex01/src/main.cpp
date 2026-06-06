#include "iter.hpp"

#include <iostream>
#include <string>

void addFive(int &i)
{
	i += 5;
}

void addPlus(std::string &s)
{
	s = s + "+";
}

void printString(std::string const &s)
{
	std::cout << s << std::endl;
}

int main()
{
	std::cout << "------------------------------------------" << std::endl;
	int intArray[] = {1,3,5,7,9};
	for (int i = 0; i < 5; i++)
		std::cout << intArray[i] << std::endl;

	std::cout << std::endl;

	::iter(intArray, 5, &addFive);
	for (int i = 0; i < 5; i++)
		std::cout << intArray[i] << std::endl;

	std::cout << "------------------------------------------" << std::endl;

	std::string stringArray[] = {"1","3","5","7","9"};
	for (int i = 0; i < 5; i++)
		std::cout << stringArray[i] << std::endl;

	std::cout << std::endl;

	::iter(stringArray, 5, &addPlus);
	for (int i = 0; i < 5; i++)
		std::cout << stringArray[i] << std::endl;

	std::cout << "------------------------------------------" << std::endl;

	std::string stringArray2[] = {"1","3","5","7","9"};
	for (int i = 0; i < 5; i++)
		std::cout << stringArray2[i] << std::endl;

	std::cout << std::endl;

	::iter(stringArray2, 5, &printString);
	std::cout << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << stringArray2[i] << std::endl;
	std::cout << "------------------------------------------" << std::endl;
}
