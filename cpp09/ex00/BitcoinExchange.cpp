#include "BitcoinExchange.hpp"

int	print_error(std::string message)
{
	std::cerr << message;
	return -1;
}

int	is_date_only_digit(std::string values[3])
{
	std::string::size_type i = 0;
	int j = 0;
	while (j < 3)
	{
		while (i < values[j].size())
		{
			if (isdigit(values[j][i]) == 0)
				return -1;
			i++;
		}
		j++;
	}
	return 0;
}

bool	check_leap_year(int year)
{
	if (year % 400 == 0)
		return true;
	if (year % 100 == 0)
		return false;
	return year % 4 == 0;
}

int	validate_date(std::string year, std::string month, std::string date)
{
	bool long_month = false;
	std::string values[3] ={year, month, date};
	if (is_date_only_digit(values) == -1)
		return -1;
	if (std::atoi(year.c_str()) < 2009)
		return -1;
	int month_nbr = std::atoi(month.c_str());
	if (month_nbr < 1 || month_nbr > 12)
		return -1;
	if (month_nbr <= 7)
	{
		if (month_nbr % 2 != 0)
			long_month = true;
		if (month_nbr == 2)
		{
			if (check_leap_year(std::atoi(year.c_str())) == true)
				long_month = true;
		}
	}
	else
	{
		if (month_nbr % 2 == 0)
			long_month = true;
	}
	int date_nbr = std::atoi(date.c_str());
	if (date_nbr < 1 || (long_month == true && date_nbr > 31) || (long_month == false && date_nbr > 30))
		return -1;
	if (month_nbr == 2)
	{
		if (long_month == true && date_nbr > 29)
			return -1;
		if (long_month == false && date_nbr > 28)
			return -1;
	}
	return 0;
}

int	check_key(std::string key)
{
	if (key.empty())
		return print_error("Error: no date\n");
	if (key.size() != 10)
		return print_error("Error: date format not valid, expected valid Year-Month-Date\n");
	size_t pos = key.find('-');
	if (pos == std::string::npos)
		return print_error("Error: date format not valid, expected 'Year-Month-Date'\n");
	std::string year = key.substr(0, pos);
	std::string month = key.substr(pos + 1);
	pos = month.find('-');
	if (pos == std::string::npos)
		return print_error("Error: date format not valid, expected Year-Month-Date\n");
	std::string date = month.substr(pos + 1);
	month = month.substr(0, pos);
	if (validate_date(year, month, date) == -1)
		return print_error("Error: date invalid, excpected a valid date between 2009-2026\n");
	return 0;
}

int	check_value(std::string value)
{
	std::string::size_type i = 0;
	int dot_amount = 0;
	errno = 0;
	if (value.empty())
		return print_error("Error: empty value\n");
	while (i < value.size())
	{
		if (isdigit(value[i]) == 0 && value[i] != '.')
			return print_error("Error: wrong value detected, expected: int/float from 0 to 1000\n");
		if (value[i] == '.')
			dot_amount++;
		i++;
	}
	if (dot_amount > 1)
		return print_error("Error: wrong value detected, too many '.'\n");
	float	float_val = std::strtof(value.c_str(), NULL);
	if (errno == ERANGE)
		return print_error("Error: overflow detected\n");
	if (float_val > 1000)
		return print_error("Error: wrong value detected, value too large\n");
	return 0;
}

size_t	check_line(std::string line)
{
	if (line.empty())
		return print_error("Error: empty line\n");
	std::size_t pos = line.find(" | ");
	if (pos == std::string::npos)
		return print_error("Error: format is wrong\n");
	std::string key = line.substr(0, pos);
	std::string value = line.substr(pos + 3);
	if (check_key(key) == -1 || check_value(value) == -1)
		return std::string::npos;
	return pos;
}

void	convert_bitcoin(std::ifstream &file, std::map<std::string, float> db)
{
	std::string line;
	float result = 0;
	while (std::getline(file, line))
	{
		size_t	pos = check_line(line);
		if (pos != std::string::npos)
		{
			std::string key = line.substr(0, pos);
			float value = std::strtof(line.substr(pos + 3).c_str(), NULL);
			std::map<std::string, float>::iterator it = db.lower_bound(key);
			if (it == db.end())
			{
				it--;
				result = it->second * value;
				std::cout << key << " => " << result << "\n";
			}
			else if (it == db.begin())
				std::cerr << "Error: date is too early\n";
			else if (it->first == key)
			{
				result = it->second * value;
				std::cout << key << " => " << result << "\n";
			}
			else if (it->first != key)
			{
				it--;
				result = it->second * value;
				std::cout << key << " => " << result << "\n";
			}
		}
	}
}
