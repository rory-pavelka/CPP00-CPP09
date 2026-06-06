#include "Span.hpp"

#include <vector>
#include <deque>
#include <list>
#include <bits/stdc++.h>

#include <fstream>

int32_t getRandom()
{
	static std::ifstream urandom("/dev/urandom", std::ios::in | std::ios::binary);
	int32_t num;
	urandom.read(reinterpret_cast<char*>(&num), sizeof(num));
	return num;
}

int main()
{
	std::cout << "------------------------------------------" << std::endl;
	/* TEST WITH 5 NUMBERS */

	Span s1 = Span(5);
	try
	{
		std::cout << s1.shortestSpan() << std::endl; // Not enough numbers in vector!
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << s1.longestSpan() << std::endl; // Not enough numbers in vector!
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		s1.addNumber(6);
		s1.addNumber(3);
		s1.addNumber(17);
		s1.addNumber(9);
		s1.addNumber(11);
		s1.addNumber(1); // Vector is full!
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << s1.shortestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << s1.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "------------------------------------------" << std::endl;
	/* TEST WITH 10 MILION NUMBERS */

	Span s2(10000000);
	for (int i = 0; i < 10000000; i++)
	{
		s2.addNumber(getRandom());
	}

	try
	{
		std::cout << s2.shortestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << s2.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "------------------------------------------" << std::endl;
	/* TEST WITH 10 THOUSAND NUMBERS */

	Span s3(10000);
	for (int i = 0; i < 10000; i++)
	{
		s3.addNumber(getRandom());
	}

	try
	{
		std::cout << s3.shortestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << s3.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "------------------------------------------" << std::endl;
}






