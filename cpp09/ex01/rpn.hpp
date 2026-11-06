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

int	rpn(std::string input)
{
	std::list<int> numbers;
	std::list<int>::reverse_iterator it;
	int result = 0;
	int last_element = 0;
	int first_element = 0;

	if (input.empty())
		return print_error("Error:input string empty\n");
	std::string::size_type i = 0;
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
			if (numbers.empty() | (numbers.size() == 1))
				return print_error("Error: not enough characters to perform operation\n");
			it = numbers.rbegin();
			switch(input[i])
			{
				case '+':
				{
					last_element = *it;
					first_element = *(++it);
					if (last_element >= 0 && (std::numeric_limits<int>::max() - last_element) < first_element)
						return print_error("Error: calculations would overflow+\n");
					if (last_element < 0 && (std::numeric_limits<int>::min() - last_element) > first_element)
						return print_error("Error: calculations would overflow+\n");
					result = first_element + last_element;
					numbers.pop_back();
					numbers.pop_back();
					numbers.push_back(result);
					i++;
					continue;
				}
				case '-':
				{
					last_element = *it;
					first_element = *(++it);
					if (last_element >= 0 && (std::numeric_limits<int>::min() + last_element) > first_element)
						return print_error("Error: calculations would overflow-\n");
					if (last_element < 0 && (std::numeric_limits<int>::max() + last_element) < first_element)
   						return print_error("Error: calculations would overflow-\n");
					result = first_element - last_element;
					numbers.pop_back();
					numbers.pop_back();
					numbers.push_back(result);
					i++;
					continue;
				}
				case '*':
				{
					last_element = *it;
					first_element = *(++it);
					if ((std::numeric_limits<int>::max() / first_element) < last_element)
						return print_error("Error: calculations would overflow*\n");
					result =  first_element * last_element;
					numbers.pop_back();
					numbers.pop_back();
					numbers.push_back(result);
					i++;
					continue;
				}
				case '/':
				{
					last_element = *it;
					first_element = *(++it);
					if (last_element == 0)
						return print_error("Error: division by zero is not allowed\n");
					result =  first_element / last_element;
					numbers.pop_back();
					numbers.pop_back();
					numbers.push_back(result);
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