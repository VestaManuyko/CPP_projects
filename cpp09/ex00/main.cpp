#include "BitcoinExchange.hpp"
#include <iostream>

int	load_db(std::map<std::string, float> &db)
{
	std::ifstream file("data.csv");
	if (!file.is_open())
		return print_error("Error: could not open database\n");
	std::string line;
	std::getline(file, line);
	if (line.empty())
		return print_error("Error: db empty\n");
	while (std::getline(file, line))
	{
		std::size_t pos = line.find(',');
		if (pos == std::string::npos)
			return print_error("Error: invalid database, not correct format\n");
		if (line[pos + 1] == '\0')
			return print_error("Error: invalid database, not correct format\n");
		db[line.substr(0, pos)] = std::strtof(line.substr(pos+1).c_str(), NULL);
	}
	return 0;
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return print_error("Error: usage of 1 database as input is expected\n");
	try
	{
		std::ifstream file(argv[1]);
		if (!file.is_open())
			return print_error("Error: could not open provided file\n");
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
