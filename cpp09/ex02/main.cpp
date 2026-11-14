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
	std::deque<int> deq_input;
	std::vector<int> vect_input;

	if (argc < 2)
		return print_error("Error: no args\n");
	while (i < argc)
	{
		if (check_input(argv[i]) == 1)
			return 1;
		i++;
	}
	if (convert_input(deq_input, vect_input, argv, argc) == 1)
		return 1;
	


	std::deque<std::pair<std::deque<int>, size_t>> deq;
	std::pair<std::deque<int>, size_t> deq_pair;
	deq_pair.first = deq_input;
	deq_pair.second = 0;
	deq.push_back(deq_pair);
	std::vector<std::pair<std::vector<int>, size_t>> vect;
	std::pair<std::vector<int>, size_t> vect_pair;
	vect_pair.first = vect_input;
	vect_pair.second = 0;
	vect.push_back(vect_pair);

	//start timer for deq
	//merge_insertion(deq);
	//make merge_insertion return the time used from start to finish?(look into if makes sense with recursion)
	//merge_insertion(vect);
	//print time output + before/after etc.
	return 0;
}
