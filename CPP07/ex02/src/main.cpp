#include <iostream>
#include "Array.hpp"
#include "Array.tpp"

int main(void)
{
	Array<int> a(5);

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Size of array 'a': " << a.size() << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Array 'a' after creation:" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << a[i] << std::endl;
	}

	a[0] = 42;
	a[1] = -42;
	a[2] = 100;
	a[3] = 0;
	a[4] = 99;

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Array 'a' after modification:" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << a[i] << std::endl;
	}

	Array<int> b(a);

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Size of array 'b': " << b.size() << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Array 'b' after creation by copying 'a':" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << b[i] << std::endl;
	}

	a[0] = 2;
	a[1] = 2;
	a[2] = 2;
	a[3] = 2;
	a[4] = 2;

	std::cout << "------------------------------------------" << std::endl;
	try
	{
		a[5] = 2;
	}
	catch (const Array<int>::OutOfBoundsException& e)
	{
		std::cerr << e.what() << std::endl;
		std::cerr << "Tried to access index " << e.getValue() << std::endl;
	}

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Array 'b' after modification of 'a':" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << b[i] << std::endl;
	}
	std::cout << "------------------------------------------" << std::endl;
}