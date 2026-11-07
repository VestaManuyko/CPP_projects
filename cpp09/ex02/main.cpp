#include "PmergeMe.hpp"

int	check_input(std::string input)
{
	std::string::size_type i = 0;

	if (input.empty())
		return print_error("Error: input empty\n");
	while (input[i])
	{
		if (isdigit(input[i]) == 0)
			return (print_error("Error: invalid input\n"));
		i++;
	}
	return 0;
}

int main(int argc, char **argv)
{
	size_t	i = 1;

	if (argc < 2)
		return print_error("Error: no args\n");
	while (i < argc)
	{
		if (check_input(argv[i]) == 1)
			return 1;
		i++;
	}
	return 0;
}
