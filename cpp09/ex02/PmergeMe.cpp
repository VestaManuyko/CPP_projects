#include "PmergeMe.hpp"

int	print_error(std::string message)
{
	std::cerr << message;
	return 1;
}

int	PmergeMe::check_input(std::string input)
{
	std::string::size_type i = 0;

	if (input.empty())
		return print_error("Error: input empty\n");
	while (i < input.size())
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
	int	i = 1;
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
	return 0;
}

PmergeMe::PmergeMe(char **input, int argc)
{
	int	i = 1;

	while (i < argc)
	{
		if (check_input(input[i]) == 1)
			throw std::exception();
		i++;
	}
	if (convert_input(input, argc) == 1)
		throw std::exception();
	half_size = (argc - 1 )/ 2;
	comparisons = 0;
}
PmergeMe::PmergeMe(const PmergeMe& other): deq(other.deq), vect(other.vect), half_size(other.half_size), comparisons(other.comparisons){};
PmergeMe &PmergeMe::operator=(const PmergeMe& other)
{
	if (&other != this)
	{
		deq = other.deq;
		vect = other.vect;
		half_size = other.half_size;
		comparisons = other.comparisons;
	}
	return *this;
}
PmergeMe::~PmergeMe(){};

void	PmergeMe::print_containers()
{
	size_t i = 0;
	size_t j = 0;
	std::cout << "Printing container: vector\n";
	while (i < vect.size())
	{
		std::cout << "Pair " << i << ": ";
		while (j < vect[i].first.size())
		{
			std::cout << vect[i].first[j] << " ";
			j++;
		}
		std::cout << "index: " << vect[i].second << std::endl;
		i++;
	}
	std::cout << "Printing container: deque\n";
	i = 0;
	j = 0;
	while (i < deq.size())
	{
		std::cout << "Pair " << i << ": ";
		while (j < deq[i].first.size())
		{
			std::cout << deq[i].first[j] << " ";
			j++;
		}
		std::cout << "index: " << vect[i].second << std::endl;
		i++;
	}
}
