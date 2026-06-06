#include "easyfind.hpp"

#include <vector>
#include <deque>
#include <list>
#include <bits/stdc++.h>

int main()
{
	int array[] = {1,2,3,4,5,6,7,8,9};
	const std::size_t size = sizeof(array) / sizeof(array[0]);
	std::vector<int> vector(array, array + size);
	std::deque<int> deque(array, array + size);
	std::list<int> list(array, array + size);

	try
	{
		easyfind(vector, 5);
		std::cout << "Vector ok" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		easyfind(deque, 9);
		std::cout << "Deque ok" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		easyfind(list, 1);
		std::cout << "List ok" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		easyfind(vector, 0);
		std::cout << "Vector ok" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		easyfind(deque, 99);
		std::cout << "Deque ok" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		easyfind(list, 10);
		std::cout << "List ok" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}