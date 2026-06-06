#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	if (argc != 4) return 1;

	std::string fileName = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::fstream oldFile(fileName);
	if (!oldFile.is_open()) return 2;
	std::ofstream newFile(fileName.append(".replace"));

	std::string originalLine;
	std::string newLine;

	size_t pos;
	size_t index;

	while (std::getline(oldFile, originalLine))
	{
		pos = 0;
		while ((index = originalLine.find(s1, pos)) != std::string::npos)
		{
			newLine.append(originalLine, pos, index - pos);
			newLine.append(s2);
			pos = index + s1.length();
		}
		newLine.append(originalLine.substr(pos));
		newFile << newLine << '\n';
		newLine.clear();
		originalLine.clear();
	}
	oldFile.close();
	newFile.close();
	return 0;
}

/*

tests:

./sedIsForLosers tests/test1 'i' 'I'

./sedIsForLosers tests/test1 '-' '-->'

./sedIsForLosers tests/test1 'tion' 'TION'

./sedIsForLosers tests/test2 'i' 'I'

./sedIsForLosers tests/test2 ' ' '_'

./sedIsForLosers tests/test2 '.' '!!!'

*/