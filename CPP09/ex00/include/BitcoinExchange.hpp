#pragma once

#include <map>
#include <string>
#include <iostream>

#include <fstream>
#include <stdlib.h>
#include <sstream>

#include <utility>

class BitcoinExchange
{
private:
	std::map<int, float> database;

	BitcoinExchange(const BitcoinExchange & other);
	BitcoinExchange & operator=(const BitcoinExchange & other);

public:
	BitcoinExchange();
	~BitcoinExchange();

	void incorrectInput(int i, std::string reason, std::string where);
	std::pair<int, float> parseInputLine(std::string line, int lineNum);
	void parseDatabaseLine(std::string line, int lineNum);
	void searchDatabase(std::string s, int i);
};