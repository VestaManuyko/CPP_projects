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

	template <typename T>
	void compare_and_sort(T &cont)
	{
		(void)cont;
	}
};

int	print_error(std::string message);

#endif