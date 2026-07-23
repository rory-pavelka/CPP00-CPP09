#include "PmergeMe.hpp"

size_t comparisons;

long JacobsthalNumber(long n)
{
	return round((pow(2, n + 1) + pow(-1, n)) / 3);
}

size_t getNanoTime()
{
	struct timespec now;
	clock_gettime(CLOCK_REALTIME, &now);
	return ((now.tv_sec * 1000 * 1000 * 1000) + now.tv_nsec);
}

template <typename T>
void FordJohnson(T & container, int multiplier);

void sort(std::deque<int> & deque)
{
	FordJohnson(deque, 1);
}

void sort(std::vector<int> & vector)
{
	FordJohnson(vector, 1);
}
