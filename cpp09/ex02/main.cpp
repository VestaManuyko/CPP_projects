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

int	convert_input(std::deque<int> &deq, std::vector<int> &vect, char **argv, int argc)
{
	long 	nbr = 0;
	size_t	i = 1;
	errno = 0;
	while (i < argc)
	{
		nbr = std::strtol(argv[i], NULL, 10);
		if (errno == ERANGE || nbr < 0 || nbr > std::numeric_limits<int>::max())
			return print_error("Error: input overflowed\n");
		deq.push_back(static_cast<int>(nbr));
		vect.push_back(static_cast<int>(nbr));
		i++;
	}
}

int main(int argc, char **argv)
{
	size_t	i = 1;
	std::deque<int> deq;
	std::vector<int> vect;

	if (argc < 2)
		return print_error("Error: no args\n");
	while (i < argc)
	{
		if (check_input(argv[i]) == 1)
			return 1;
		i++;
	}
	if (convert_input(deq, vect, argv, argc) == 1)
		return 1;
	return 0;
}
