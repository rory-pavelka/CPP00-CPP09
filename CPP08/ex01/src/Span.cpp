#include "Span.hpp"

Span::Span() :
capacity(0)
{}

Span::Span(int N) :
capacity(N)
{}

Span::Span(const Span & other) :
vec(other.vec),
capacity(other.capacity)
{}

Span & Span::operator=(const Span & other)
{
	vec = other.vec;
	capacity = other.capacity;
	return *this;
}

Span::~Span()
{}

void Span::addNumber(int i)
{
	if (vec.size() < capacity)
		vec.push_back(i);
	else
		throw std::runtime_error("Vector is full!");
}

long long Span::shortestSpan()
{
	if (vec.size() < 2)
		throw std::runtime_error("Not enough numbers in vector!");
	std::vector<int> temp(vec);
	std::sort(temp.begin(), temp.end());
	long long shortest = (long long)temp[1] - temp[0];
	for (size_t i = 1; i < temp.size() - 1; i++)
	{
		if (temp[i + 1] - temp[i] < shortest)
		{
			shortest = (long long)temp[i + 1] - temp[i];
		}
	}
	return shortest;
}

long long Span::longestSpan()
{
	if (vec.size() < 2)
		throw std::runtime_error("Not enough numbers in vector!");
	std::vector<int> temp(vec);
	std::sort(temp.begin(), temp.end());
	long long longest = (long long)*(--temp.end()) - *(temp.begin());
	return longest;
}