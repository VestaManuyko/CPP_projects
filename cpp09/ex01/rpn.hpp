#ifndef RPN_HPP
# define RPN_HPP

#include <list>
#include <iostream>
#include <limits>

int	print_error(std::string message)
{
	std::cerr << message;
	return -1;
}

bool	is_sign(int c)
{
	return (c == '+' | c == '-' | c == '/' | c == '*');
}

int addition(int first_element, int last_element, std::list<int> &numbers)
{
	if (last_element >= 0 && (std::numeric_limits<int>::max() - last_element) < first_element)
		return print_error("Error: calculations would overflow+\n");
	if (last_element < 0 && (std::numeric_limits<int>::min() - last_element) > first_element)
		return print_error("Error: calculations would overflow+\n");
	numbers.pop_back();
	numbers.pop_back();
	numbers.push_back(first_element + last_element);
	return 0;
}

int substraction(int first_element, int last_element, std::list<int> &numbers)
{
	if (last_element >= 0 && (std::numeric_limits<int>::min() + last_element) > first_element)
		return print_error("Error: calculations would overflow-\n");
	if (last_element < 0 && (std::numeric_limits<int>::max() + last_element) < first_element)
		return print_error("Error: calculations would overflow-\n");
	numbers.pop_back();
	numbers.pop_back();
	numbers.push_back(first_element - last_element);
	return 0;
}

int	multiplication(int first_element, int last_element, std::list<int> &numbers)
{
	if (first_element == 0)
		return 0;
	if (first_element > 0)
	{
		if (last_element > 0 && (std::numeric_limits<int>::max() / last_element) < first_element)
			return print_error("Error: calculations would overflow*\n");
		if (last_element < 0 && (std::numeric_limits<int>::min() / last_element) > first_element)
			return print_error("Error: calculations would overflow*\n");
	}
	if (first_element < 0)
	{
		if (last_element > 0 && (std::numeric_limits<int>::min() / last_element) < first_element)
			return print_error("Error: calculations would overflow*\n");
		if (last_element < 0 && (std::numeric_limits<int>::max() / last_element) > first_element)
			return print_error("Error: calculations would overflow*\n");
	}
	if (first_element < 0 && (std::numeric_limits<int>::max() / first_element) > last_element)
		return print_error("Error: calculations would overflow*\n");
	numbers.pop_back();
	numbers.pop_back();
	numbers.push_back(first_element * last_element);
	return 0;
}

int	division(int first_element, int last_element, std::list<int> &numbers)
{
	if (last_element == 0)
		return print_error("Error: division by zero is not allowed\n");
	numbers.pop_back();
	numbers.pop_back();
	numbers.push_back(first_element / last_element);
	return 0;
}

int	rpn(std::string input)
{
	std::list<int> numbers;
	std::list<int>::reverse_iterator it;
	std::string::size_type i = 0;
	int last_element = 0;
	int first_element = 0;

	if (input.empty())
		return print_error("Error:input string empty\n");
	while (input[i])
	{
		if (input[i] == ' ')
		{
			i++;
			continue;
		}
		if (input[i] == '-' && isdigit(input[i + 1]))
		{
			numbers.push_back(-(input[i + 1] - '0'));
			i += 2;
			continue;
		}
		if (isdigit(input[i]))
			numbers.push_back(input[i] - '0');
		else if (is_sign(input[i]))
		{
			if (numbers.size() < 2)
				return print_error("Error: not enough characters to perform operation\n");
			it = numbers.rbegin();
			last_element = *it;
			first_element = *(++it);
			switch(input[i])
			{
				case '+':
				{
					if (addition(first_element, last_element, numbers) == -1)
						return -1;
					i++;
					continue;
				}
				case '-':
				{
					if (substraction(first_element, last_element, numbers) == -1)
						return -1;
					i++;
					continue;
				}
				case '*':
				{
					if (multiplication(first_element, last_element, numbers) == -1)
						return -1;
					i++;
					continue;
				}
				case '/':
				{
					if (division(first_element, last_element, numbers) == -1)
						return -1;
					i++;
					continue;
				}
			}
		}
		else
			return print_error("Error: weird characters in input\n");
		i++;
	}
	if (numbers.size() == 1)
		std::cout << *numbers.begin() << "\n";
	else
		return print_error("Error: extra input, couldnt process...\n");
	return 0;
}

#endif