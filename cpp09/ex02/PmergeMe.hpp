#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <vector>
#include <limits>
#include <cerrno>
#include <cstdlib>

class PmergeMe
{
	public:
	PmergeMe(char **input, int argc);
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	template <typename T>
	void	merge_insertion(T &cont, size_t pair_elements)
	{
		if (pair_elements > half_size)
			return ;
		size_t i = 0;
		size_t j = 0;
		std::pair<std::vector<int>, size_t> tmp_pair;
		while (j < cont.first.size())
		{
			while (i < pair_elements && i < cont[j].first.size())
			{
				tmp_pair.first.push_back(cont[j].first[i]);
				i++;
			}
			tmp_pair.second = j;
			j++;
		}
		compare_and_sort(cont);
		merge_insertion(cont, pair_elements * 2);
	}
	
	void	print_containers();

	private:
	std::deque<std::pair<std::deque<int>, size_t> > deq;
	std::vector<std::pair<std::vector<int>, size_t> > vect;
	size_t	half_size;
	size_t	comparisons;

	PmergeMe();
	int	convert_input(char **argv, int argc);
	int	check_input(std::string input);

	template <typename T>
	void compare_and_sort(T &cont)
	{
		(void)cont;
	}
};

int	print_error(std::string message);

#endif