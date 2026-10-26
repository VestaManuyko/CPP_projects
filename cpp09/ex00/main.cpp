#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>

int	load_db(std::map<std::string, float> &db)
{
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
		db[line.substr(0, pos)] = std::strtof(line.substr(pos+1).c_str(), NULL);
	}
	return 0;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: usage of 1 database as input is expected\n";
		return 1;
	}
	try
	{
		std::ifstream file(argv[1]);
		if (!file.is_open())
		{
			std::cerr << "Error: could not open provided file\n";
			return 1;
		}
		std::map<std::string, float> db;
		if (load_db(db) == -1)
			return 1;
		convert_bitcoin(file, db);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
