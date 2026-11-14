#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <vector>
#include <limits>

class PmergeMe
{
	public:
	PmergeMe(char **input, int argc);

	//initialise containers internally in the class for later use in merge_insertion?
	//validate input as class creation stage and throw exeptions if wrong, for better main and clearer structure
	//these 2 in progress

	//Orthodox form
	PmergeMe(const PmergeMe& other) {};
	PmergeMe& operator=(const PmergeMe& other) {};
	~PmergeMe() {};

	template <typename T>
	void	merge_insertion(T &cont, size_t pair_elements)
	{
		if (cont[0].first.size() > half_size)
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
		merge_insertion(cont);
	}
	
	private:
	size_t	half_size;
	size_t	comparisons;
	std::deque<std::pair<std::deque<int>, size_t>> deq;
	std::vector<std::pair<std::vector<int>, size_t>> vect;
	PmergeMe();
	int	convert_input(char **argv, int argc);
	int	check_input(std::string input);

	template <typename T>
	void compare_and_sort(T &cont)
	{

	}
};

int	print_error(std::string message);

#endif