#pragma once

#include <exception>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <iostream>

template <typename T>
typename T::iterator easyfind(T container, int value)
{
	typename T::iterator found = std::find(container.begin(), container.end(), value);

	if (found == container.end())
		throw std::runtime_error("Didn't find any occurence of given int!");

	return (found);
}