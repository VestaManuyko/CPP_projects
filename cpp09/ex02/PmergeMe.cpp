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
	_size = (argc - 1 );
	_comparisons = 0;
}
PmergeMe::PmergeMe(const PmergeMe& other): _deq(other._deq), _vect(other._vect), _size(other._size), _comparisons(other._comparisons){};
PmergeMe &PmergeMe::operator=(const PmergeMe& other)
{
	if (&other != this)
	{
		_deq = other._deq;
		_vect = other._vect;
		_size = other._size;
		_comparisons = other._comparisons;
	}
	return *this;
}
PmergeMe::~PmergeMe(){};

void	PmergeMe::print_containers()
{
	print_vect(_vect);
	print_deq(_deq);
}

void	PmergeMe::print_vect(vect_of_pairs vect)
{
	size_t i = 0;
	size_t j = 0;
	std::cout << "Printing container: vector\n";
	while (i < vect.size())
	{
		std::cout << "Pair " << i << ": ";
		j = 0;
		while (j < vect[i].first.size())
		{
			std::cout << vect[i].first[j] << " ";
			j++;
		}
		std::cout << "index: " << vect[i].second << std::endl;
		i++;
	}
}

void	PmergeMe::print_deq(deq_of_pairs deq)
{
	size_t i = 0;
	size_t j = 0;
	std::cout << "Printing container: deque\n";
	while (i < deq.size())
	{
		std::cout << "Pair " << i << ": ";
		j = 0;
		while (j < deq[i].first.size())
		{
			std::cout << deq[i].first[j] << " ";
			j++;
		}
		std::cout << "index: " << deq[i].second << std::endl;
		i++;
	}
}

void	PmergeMe::merge_insertion_vect(vect_of_pairs &cont, size_t pair_elements)
{
	if (cont[0].first.size() > _size / 2)
		return ;
	size_t i = 0;
	size_t j = 0;
	size_t	index = 0;
	vect_of_pairs new_cont;
	std::pair<std::vector<int>, size_t> tmp_pair;
	//this whole loop could be a template with cont and pair as a T
	while (j < _size / (pair_elements / 2))
	{
		i = 0;
		while (i < cont[j].first.size())
		{
			tmp_pair.first.push_back(cont[j].first[i]);
			if (tmp_pair.first.size() == pair_elements)
			{
				tmp_pair.second = index;
				index++;
				new_cont.push_back(tmp_pair);
				tmp_pair.first.clear();
			}
			i++;
		}
		j++;
	}
	//compare_and_sort(new_cont);
	print_vect(new_cont);
	merge_insertion_vect(new_cont, pair_elements * 2);
}

void	PmergeMe::merge_insertion_deq(deq_of_pairs &cont, size_t pair_elements)
{
	if (cont[0].first.size() > _size / 2)
		return ;
	size_t i = 0;
	size_t j = 0;
	size_t	index = 0;
	deq_of_pairs new_cont;
	std::pair<std::deque<int>, size_t> tmp_pair;
	//this whole loop could be a template with cont and pair as a T
	while (j < _size / (pair_elements / 2))
	{
		i = 0;
		while (i < cont[j].first.size())
		{
			tmp_pair.first.push_back(cont[j].first[i]);
			if (tmp_pair.first.size() == pair_elements)
			{
				tmp_pair.second = index;
				index++;
				new_cont.push_back(tmp_pair);
				tmp_pair.first.clear();
			}
			i++;
		}
		j++;
	}
	//compare_and_sort(new_cont);
	print_deq(new_cont);
	merge_insertion_deq(new_cont, pair_elements * 2);
}

void	PmergeMe::merge_insertion()
{
	merge_insertion_vect(_vect, 2);
	merge_insertion_deq(_deq, 2);
}
