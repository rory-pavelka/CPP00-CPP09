#include "PmergeMe.hpp"

/*

USAGE:

default:
./PmergeMe ~numbers_to_sort~

to check if sorted:
./PmergeMe sorted ~numbers_to_sort~

to check comparisons count:
./PmergeMe comparisons ~numbers_to_sort~

*/

int main(int int_argc, char** argv)
{
	size_t argc = static_cast<size_t>(int_argc);

	if (argc == 1)
	{
		std::cerr << "You must provide at least one argument. Run \'./PmergeMe help\' to show usage." << std::endl;
		return 1;
	}

	if (std::string(argv[1]) == "help")
	{
		std::cerr << std::endl << "Run \'./PmergeMe 1 2 3 9 8 7 6 5 4\' to use normally." << std::endl << std::endl;
		std::cerr << "Run \'./PmergeMe sorted 1 2 3 9 8 7 6 5 4\' to output sorted containers to files." << std::endl << std::endl;
		std::cerr << "Run \'./PmergeMe comparisons 1 2 3 9 8 7 6 5 4\' to check how many comparisons were used on n elements." << std::endl << std::endl;
		std::cerr << "Or run by using ./run.sh 30 | ./sorted.sh 30 | ./comparisons.sh 30" << std::endl << std::endl;
		return 0;
	}

	size_t start;
	size_t end;

	std::vector<int> before;

	for (size_t i = 1; i < argc; i++)
	{
		if (i == 1 && (std::string(argv[1]) == "sorted" || std::string(argv[1]) == "comparisons"))
		{
			if (argc == 2)
				std::cerr << "You must provide at least one integer argument after \'sorted\' or \'comparisons\'.\nRun \'./PmergeMe help\' to show usage." << std::endl;
			continue;
		}

		int element;

		std::stringstream ss(argv[i]);

		if (!(ss >> element))
		{
			std::cerr << "Encountered non-integer among arguments." << std::endl;
			return 3;
		}

		if (element < 0)
		{
			std::cerr << "Encountered negative number." << std::endl;
			return 3;
		}

		char remainder;

		if (ss >> remainder)
		{
			std::cerr << "Encountered non-integer among arguments." << std::endl;
			return 3;
		}

		before.push_back(element);
	}

	if (std::string(argv[1]) == "sorted")
	{
		std::deque<int> deque;
		std::vector<int> vector;

		std::ofstream vectorFile("sortedVector.txt");
		std::ofstream dequeFile("sortedDeque.txt");

		comparisons = 0;

		start = getNanoTime();

		for (size_t i = 0; i < before.size(); i++)
			vector.push_back(before[i]);

		sort(vector);

		end = getNanoTime();

		comparisons = 0;

		start = getNanoTime();

		for (size_t i = 0; i < before.size(); i++)
			deque.push_back(before[i]);

		sort(deque);

		end = getNanoTime();

		for (size_t i = 0; i < vector.size(); i++)
		{
			vectorFile << vector[i] << std::endl;
			dequeFile << deque[i] << std::endl;
		}

		return 0;
	}

	if (std::string(argv[1]) == "comparisons")
	{
		std::deque<int> deque;
		std::vector<int> vector;

		comparisons = 0;

		start = getNanoTime();

		for (size_t i = 0; i < before.size(); i++)
			vector.push_back(before[i]);

		sort(vector);

		end = getNanoTime();

		std::cout << comparisons << std::endl;

		comparisons = 0;

		start = getNanoTime();

		for (size_t i = 0; i < before.size(); i++)
			deque.push_back(before[i]);

		sort(deque);

		end = getNanoTime();

		std::cout << comparisons << std::endl;

		return 0;
	}

	std::deque<int> deque;
	std::vector<int> vector;

	std::cout << "Before: ";
	for (size_t i = 0; i < before.size(); i++)
	{
		std::cout << before[i];
		if (i < before.size() - 1)
			std::cout << ' ';
	}
	std::cout << std::endl;

	comparisons = 0;

	start = getNanoTime();

	for (size_t i = 0; i < before.size(); i++)
		vector.push_back(before[i]);

	sort(vector);

	end = getNanoTime();

	std::cout << "After:  ";
	for (size_t i = 0; i < vector.size(); i++)
	{
		std::cout << vector[i];
		if (i < vector.size() - 1)
			std::cout << ' ';
	}
	std::cout << std::endl;

	std::cout
	<< "Time to process a range of "
	<< vector.size()
	<< " elements with std::vector : "
	<< ((float)(end - start) / (float)1000)
	<< " us."
	<< std::endl;

	comparisons = 0;

	start = getNanoTime();

	for (size_t i = 0; i < before.size(); i++)
		deque.push_back(before[i]);

	sort(deque);

	end = getNanoTime();

	std::cout
	<< "Time to process a range of "
	<< deque.size()
	<< " elements with std::deque  : "
	<< ((float)(end - start) / (float)1000)
	<< " us."
	<< std::endl;

	return 0;
}
