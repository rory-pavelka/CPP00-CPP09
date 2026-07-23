#pragma once

#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

#include <deque>
#include <vector>

#include <cmath>
#include <time.h>

/*
	- global variable is used here

	- the project as is doesn't use it for anything,
	  but it is useful during evaluation to check
	  if the algorithm doesn't exceed maximum comparisons
*/
extern size_t comparisons;

long JacobsthalNumber(long n);
size_t getNanoTime();

/* Ford-Johnson: */

template <typename Iterator>
bool compare(Iterator left, Iterator right)
{
	comparisons++;
	return *left < *right;
}

template <typename Iterator>
void swapPair(Iterator it, int multiplier)
{
	Iterator start = it - multiplier + 1;
	Iterator end = start + multiplier;
	while (start != end)
	{
		std::iter_swap(start, start + multiplier);
		start++;
	}
}

template <typename T>
void FordJohnson(T & container, int multiplier)
{
	typedef typename T::iterator Iterator;
	typedef typename std::vector<Iterator>::iterator Iterator2;

	int pairCount = container.size() / multiplier;
	if (pairCount < 2)
		return;

	bool isOdd = pairCount % 2 == 1;

	Iterator start = container.begin();
	Iterator last = container.begin() + (multiplier * pairCount);
	Iterator end = last - (isOdd * multiplier);

	for (Iterator it = start; it != end; std::advance(it, 2 * multiplier))
	{
		Iterator thisPair = it + multiplier - 1;
		Iterator nextPair = it + (multiplier * 2) - 1;
		if (compare(nextPair, thisPair))
		{
			swapPair(thisPair, multiplier);
		}
	}
	
	FordJohnson(container, multiplier * 2);

	std::vector<Iterator> main;
	std::vector<Iterator> pend;

	main.insert(main.end(), container.begin() + multiplier - 1);
	main.insert(main.end(), container.begin() + (multiplier * 2) - 1);

	for (int i = 4; i <= pairCount; i += 2)
	{
		pend.insert(pend.end(), container.begin() + (multiplier * (i - 1)) - 1);
		main.insert(main.end(), container.begin() + (multiplier * i) - 1);
	}

	if (isOdd)
	{
		pend.insert(pend.end(), end + multiplier - 1);
	}

	int prevJacobsthal = JacobsthalNumber(1);
	int insertedNumbers = 0;

	for (int k = 2;; k++)
	{
		int currJacobsthal = JacobsthalNumber(k);
		int JacobsthalDiff = currJacobsthal - prevJacobsthal;
		int offset = 0;

		if (JacobsthalDiff > static_cast<int>(pend.size()))
			break;

		int iterCount = JacobsthalDiff;
		Iterator2 pendIt = pend.begin() + JacobsthalDiff - 1;
		Iterator2 boundIt = main.begin() + currJacobsthal + insertedNumbers;

		while (iterCount)
		{
			Iterator2 idx = std::upper_bound(main.begin(), boundIt, *pendIt, static_cast<bool (*)(Iterator, Iterator)>(compare));
			Iterator2 inserted = main.insert(idx, *pendIt);
			iterCount--;
			pendIt = pend.erase(pendIt);
			std::advance(pendIt, -1);

			offset += (inserted - main.begin()) == currJacobsthal + insertedNumbers;
			boundIt = main.begin() + currJacobsthal + insertedNumbers - offset;
		}

		prevJacobsthal = currJacobsthal;
		insertedNumbers += JacobsthalDiff;
		offset = 0;
	}

	for (ssize_t i = pend.size() - 1; i >= 0; i--)
	{
		Iterator2 currPend = pend.begin() + i;
		Iterator2 currBound = main.begin() + main.size() - pend.size() + i + isOdd;
		Iterator2 idx = std::upper_bound(main.begin(), currBound, *currPend, static_cast<bool (*)(Iterator, Iterator)>(compare));
		main.insert(idx, *currPend);
	}

	std::vector<int> copy;
	copy.reserve(container.size());

	for (Iterator2 it = main.begin(); it != main.end(); it++)
	{
		for (int i = 0; i < multiplier; i++)
		{
			Iterator pairStart = *it;
			std::advance(pairStart, -multiplier + i + 1);
			copy.insert(copy.end(), *pairStart);
		}
	}

	Iterator containerIt = container.begin();
	std::vector<int>::iterator copyIt = copy.begin();

	while (copyIt != copy.end())
	{
		*containerIt = *copyIt;
		containerIt++;
		copyIt++;
	}
}

void sort(std::deque<int> & deque);
void sort(std::vector<int> & vector);
