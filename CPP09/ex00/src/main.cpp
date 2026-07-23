#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "You must provide exactly one argument: input_file." << std::endl;
		std::cerr << "Run \'./btc input.txt\'" << std::endl;
		return 1;
	}

	std::string inputFile(argv[1]);
	std::string databaseFile("data.csv");

	std::string s;

	/* load input file and skip first line */
	std::ifstream input;
	input.open(inputFile.c_str());
	if (!input)
	{
		std::cerr << "\'" << inputFile << "\' file not found." << std::endl;
		return 2;
	}
	std::getline(input, s);

	/* load database file and skip first line */
	std::ifstream database;
	database.open(databaseFile.c_str());
	if (!database)
	{
		std::cerr << "\'" << databaseFile << "\' file not found." << std::endl;
		return 3;
	}
	std::getline(database, s);

	BitcoinExchange program;

	/* parse all database lines to database map */
	for (int i = 2; std::getline(database, s); i++)
	{
		try
		{
			program.parseDatabaseLine(s, i);
		}
		catch (std::exception & e)
		{
			std::cerr << "Exception caught in " << e.what() << std::endl;
		}
	}

	/* search all input lines in database map */
	for (int i = 2; std::getline(input, s); i++)
	{
		try
		{
			program.searchDatabase(s, i);
		}
		catch (std::exception & e)
		{
			std::cerr << "Exception caught in " << e.what() << std::endl;
		}
	}

	return 0;
}