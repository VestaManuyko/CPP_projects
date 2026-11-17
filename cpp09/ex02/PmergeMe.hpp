#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <vector>
#include <limits>
#include <cerrno>
#include <cstdlib>

typedef std::vector<std::pair<std::vector<int>, size_t> > vect_of_pairs;
typedef std::deque<std::pair<std::deque<int>, size_t> > deq_of_pairs;

class PmergeMe
{
	public:
	PmergeMe(char **input, int argc);
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();
	
	void	merge_insertion();
	void	print_containers();

	private:
	deq_of_pairs _deq;
	vect_of_pairs _vect;
	size_t	_size;
	size_t	_comparisons;

	PmergeMe();
	int	convert_input(char **argv, int argc);
	int	check_input(std::string input);

	void	merge_insertion_vect(vect_of_pairs &cont, size_t pair_elements);
	void	merge_insertion_deq(deq_of_pairs &cont, size_t pair_elements);

	void	print_deq(deq_of_pairs deq);
	void	print_vect(vect_of_pairs vect);

	template <typename T, typename pair_type>
	T	split_pairs(T &cont, pair_type &extra, size_t pair_elements)
	{
		size_t i = 0;
		size_t j = 0;
		size_t	index = 0;
		T new_cont;
		while (j < cont.size())
		{
			i = 0;
			while (i < cont[j].first.size())
			{
				extra.first.push_back(cont[j].first[i]);
				if (extra.first.size() == pair_elements)
				{
					extra.second = index++;
					new_cont.push_back(extra);
					extra.first.clear();
				}
				i++;
			}
			j++;
		}
		if (extra.first.empty() == 0)
			extra.second = index;
		return new_cont;
	}

	template <typename T>
	void compare_and_sort(T &cont)
	{
		(void)cont;
	}
};

int	print_error(std::string message);

#endif