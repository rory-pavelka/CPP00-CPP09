#include "BitcoinExchange.hpp"

/* copy constructor and copy assignment opearator are private to prevent copying */
BitcoinExchange::BitcoinExchange(const BitcoinExchange & other) { (void)other; }
BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange & other) { (void)other; return *this; }

/* default constructor and destructor */
BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

/* function to make throwing an exception simpler in the code */
void BitcoinExchange::incorrectInput(int i, std::string reason, std::string where)
{
	std::stringstream ss;
	ss << i;
	throw std::runtime_error(where + " on line " + ss.str() + ". Reason: " + reason);
}

/* function called in searchDatabase that parses a line of input to int-float pair where int is YYYYMMDD date and float is value */
std::pair<int, float> BitcoinExchange::parseInputLine(std::string line, int lineNum)
{
	std::stringstream ss(line);

	int year, month, day;
	float value;

	char dash1 = 0, dash2 = 0, pipe = 0, leftover = 0;

	if (!(ss >> year >> dash1 >> month >> dash2 >> day >> pipe >> value))
		incorrectInput(lineNum, "Part of line missing or wrong format", "input check");

	if (ss >> leftover)
		incorrectInput(lineNum, "Characters after value", "input check");

	if (dash1 != '-')
		incorrectInput(lineNum, "Dash between year and month missing", "input check");

	if (dash2 != '-')
		incorrectInput(lineNum, "Dash between month and day missing", "input check");

	if (pipe != '|')
		incorrectInput(lineNum, "Pipe between day and value missing", "input check");

	if (year < 2009 || year > 2099)
		incorrectInput(lineNum, "Invalid year", "input check");

	if (month < 1 || month > 12)
		incorrectInput(lineNum, "Invalid month", "input check");

	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		if (day < 1 || day > 31)
			incorrectInput(lineNum, "Invalid day (this month has 31 days)", "input check");
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day < 1 || day > 30)
			incorrectInput(lineNum, "Invalid day (this month has 30 days)", "input check");
	}
	else if (month == 2)
	{
		if (year % 4 == 0)
		{
			if (day < 1 || day > 29)
				incorrectInput(lineNum, "Invalid day (this month has 29 days)", "input check");
		}
		else
		{
			if (day < 1 || day > 28)
				incorrectInput(lineNum, "Invalid day (this month has 28 days)", "input check");
		}
	}

	if (value < 0 || value > 1000)
		incorrectInput(lineNum, "Invalid value", "input check");

	int date = 10000 * year;
	date += 100 * month;
	date += day;

	return std::pair<int, float>(date, value);
}

/* function that parses a line of database to int-float pair where int is YYYYMMDD date and float is value and saves the pair to a map */
void BitcoinExchange::parseDatabaseLine(std::string line, int lineNum)
{
	std::stringstream ss(line);

	int year, month, day;
	float value;

	char dash1 = 0, dash2 = 0, colon = 0, leftover = 0;

	if (!(ss >> year >> dash1 >> month >> dash2 >> day >> colon >> value))
		incorrectInput(lineNum, "Part of line missing or wrong format", "database check");

	if (ss >> leftover)
		incorrectInput(lineNum, "Characters after value", "input check");

	if (dash1 != '-')
		incorrectInput(lineNum, "Dash between year and month missing", "database check");

	if (dash2 != '-')
		incorrectInput(lineNum, "Dash between month and day missing", "database check");

	if (colon != ',')
		incorrectInput(lineNum, "Colon between day and value missing", "database check");

	if (year < 2000 || year > 3000)
		incorrectInput(lineNum, "Invalid year", "database check");

	if (month < 1 || month > 12)
		incorrectInput(lineNum, "Invalid month", "database check");

	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		if (day < 1 || day > 31)
			incorrectInput(lineNum, "Invalid day (this month has 31 days)", "database check");
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day < 1 || day > 30)
			incorrectInput(lineNum, "Invalid day (this month has 30 days)", "database check");
	}
	else if (month == 2)
	{
		if (year % 4 == 0)
		{
			if (day < 1 || day > 29)
				incorrectInput(lineNum, "Invalid day (this month has 29 days)", "database check");
		}
		else
		{
			if (day < 1 || day > 28)
				incorrectInput(lineNum, "Invalid day (this month has 28 days)", "database check");
		}
	}

	if (value < 0)
		incorrectInput(lineNum, "Invalid value", "database check");

	int date = 10000 * year;
	date += 100 * month;
	date += day;

	database.insert(std::pair<int, float>(date, value));
}

/* function that searches for each value it's corresponding database record and calculates the price of given amount at the given day */
void BitcoinExchange::searchDatabase(std::string s, int i)
{
	std::map<int, float>::iterator it_database;
	std::pair<int, float> input = parseInputLine(s, i);

	it_database = database.lower_bound(input.first);

	if (it_database != database.end() &&
		it_database->first == input.first)
	{
		std::cout <<
		input.first << " => " <<
		input.second << " = " <<
		input.second * it_database->second << std::endl;
	}
	else
	{
		if (it_database != database.begin())
			--it_database;

		std::cout <<
		input.first << " => " <<
		input.second << " = " <<
		input.second * it_database->second << std::endl;
	}
}
