#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <cstdlib>

int	load_db(void)
{
	std::map<std::string, float> db;
	std::ifstream file("data.csv");

	if (!file.is_open())
	{
		std::cerr << "Error: could not open database\n";
    	return -1;
	}
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::size_t pos = line.find(',');
		if (pos == std::string::npos)
		{
			std::cerr << "Error: invalid database, not correct format\n";
    		return -1;
		}
		if (line[pos + 1] == '\0')
		{
			std::cerr << "Error: invalid database, not correct format\n";
    		return -1;
		}
		std::cout << "inserting to db:" << line.substr(0, pos) << " = " << std::strtof(line.substr(pos+1).c_str(), NULL) << "\n";
		db[line.substr(0, pos)] = std::strtof(line.substr(pos+1).c_str(), NULL);
	}
	std::map<std::string, float>::iterator it;
	it = db.begin();
	std::cout << "Few values from the db:\n" << it->first << " = " << it->second << "\n";
	return 0;
}

int convert_bitcoin(std::ifstream &file)
{
	(void)file;
	 return 0;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: usage of only 1 database as input is allowed\n";
		return 1;
	}
	std::ifstream file(argv[1]);
	if (!file.is_open())
	{
		std::cerr << "Error: could not open provided file\n";
    	return 1;
	}
	if (load_db() == -1)
		return 1;
	if (convert_bitcoin(file) == -1)
		return 1;
	return 0;
}
