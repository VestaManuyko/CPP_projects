#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <cstdlib>
#include <cerrno>
#include <limits>

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

int	check_key(std::string key)
{
	if (key.empty())
	{
		std::cerr << "Error: empty key\n";
		return -1;
	}

	return 0;
}

int	check_value(std::string value)
{
	errno = 0;
	if (value.empty())
	{
		std::cerr << "Error: empty value\n";
		return -1;
	}
	float	float_val = std::strtof(value.c_str(), NULL);
	if (errno = ERANGE)
	{
		std::cerr << "Error: overflow detected\n";
		return -1;
	}
	if (float_val < 0 || float_val > 1000)
	{
		std::cerr << "Error: wrong value detected, expected: 0 to 1000\n";
		return -1;
	}
	return 0;
}

size_t	check_line(std::string line)
{
	if (line.empty())
	{
		std::cerr << "Error: empty line\n";
		return std::string::npos;
	}
	std::size_t pos = line.find(" | ");
	if (pos == std::string::npos)
	{
		std::cerr << "Error: format is wrong\n";
		return pos;
	}
	std::string key = line.substr(0, pos);
	std::string value = line.substr(pos + 3);
	if (check_key(key) == -1 || check_value(value) == -1)
		return std::string::npos;
	return pos;
}

void	convert_bitcoin(std::ifstream &file, std::map<std::string, float> db)
{
	std::string line;
	while (std::getline(file, line))
	{
		size_t	pos = check_line(line);
		if (pos != std::string::npos)
		{
			//convertion
		}
	}
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
