#pragma once

#include <vector>
#include <iostream>
#include <algorithm>

class Span
{
private:
	std::vector<int> vec;
	unsigned int capacity;
public:
	Span();
	Span(int N);
	Span(const Span & other);
	Span &operator=(const Span & other);
	~Span();

	void addNumber(int i);
	long long shortestSpan();
	long long longestSpan();
};
