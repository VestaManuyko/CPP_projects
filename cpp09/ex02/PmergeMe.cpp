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
	std::pair<std::deque<int>, size_t> deq_pair;
	std::pair<std::vector<int>, size_t> vect_pair;
	errno = 0;

	while (i < argc)
	{
		nbr = std::strtol(argv[i], NULL, 10);
		if (errno == ERANGE || nbr < 0 || nbr > std::numeric_limits<int>::max())
			return print_error("Error: input overflowed\n");
		deq_input.push_back(static_cast<int>(nbr));
		deq_pair.first = deq_input;
		deq_pair.second = i - 1;
		_deq.push_back(deq_pair);
		deq_input.clear();
		vect_input.push_back(static_cast<int>(nbr));
		vect_pair.first = vect_input;
		vect_pair.second = i - 1;
		_vect.push_back(vect_pair);
		vect_input.clear();
		i++;
	}
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
	_comparisons = 0;
}
PmergeMe::PmergeMe(const PmergeMe& other): _deq(other._deq), _vect(other._vect), _comparisons(other._comparisons){};
PmergeMe &PmergeMe::operator=(const PmergeMe& other)
{
	if (&other != this)
	{
		_deq = other._deq;
		_vect = other._vect;
		_comparisons = other._comparisons;
	}
	return *this;
}
PmergeMe::~PmergeMe(){};

void	PmergeMe::print_containers()
{
	std::cout << "Printing vector:\n";
	print_cont(_vect);
	std::cout << "Printing deque:\n";
	print_cont(_deq);
}

void	PmergeMe::merge_insertion_vect(vect_of_pairs &cont, size_t pair_elements)
{
	if (cont.size() < 2)
		return ;
	std::pair<std::vector<int>, size_t> extra;
	compare_and_sort(cont);
	vect_of_pairs new_cont = split_pairs(cont, extra, pair_elements);
	merge_insertion_vect(new_cont, pair_elements * 2);
	insertion(new_cont, extra);
	cont = new_cont;
}

void	PmergeMe::merge_insertion_deq(deq_of_pairs &cont, size_t pair_elements)
{
	if (cont.size() < 2)
		return ;
	std::pair<std::deque<int>, size_t> extra;
	compare_and_sort(cont);
	deq_of_pairs new_cont = split_pairs(cont, extra, pair_elements);
	merge_insertion_deq(new_cont, pair_elements * 2);
	insertion(new_cont, extra);
	cont = new_cont;
}

void	PmergeMe::merge_insertion()
{
	merge_insertion_vect(_vect, 2);
	merge_insertion_deq(_deq, 2);
}
