#include "PmergeMe.hpp"

int	print_error(std::string message)
{
	std::cerr << message;
	return 1;
}

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

int	PmergeMe::convert_input(char **argv, int argc)
{
	long 	nbr = 0;
	size_t	i = 1;
	std::deque<int> deq_input;
	std::vector<int> vect_input;
	errno = 0;

	while (i < argc)
	{
		nbr = std::strtol(argv[i], NULL, 10);
		if (errno == ERANGE || nbr < 0 || nbr > std::numeric_limits<int>::max())
			return print_error("Error: input overflowed\n");
		deq_input.push_back(static_cast<int>(nbr));
		vect_input.push_back(static_cast<int>(nbr));
		i++;
	}
	std::pair<std::deque<int>, size_t> deq_pair;
	deq_pair.first = deq_input;
	deq_pair.second = 0;
	deq.push_back(deq_pair);
	std::pair<std::vector<int>, size_t> vect_pair;
	vect_pair.first = vect_input;
	vect_pair.second = 0;
	vect.push_back(vect_pair);
}

PmergeMe::PmergeMe(char **input, int argc)
{
	size_t	i = 0;

	while (i < argc)
	{
		if (check_input(input[i]) == 1)
			throw std::exception();
		i++;
	}
	if (convert_input(input, argc) == 1)
		throw std::exception();
	half_size = argc - 1 / 2;
	comparisons = 0;
}
