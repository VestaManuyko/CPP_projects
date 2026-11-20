#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <vector>
#include <limits>
#include <cerrno>
#include <cstdlib>
#include <algorithm>

typedef std::vector<std::pair<std::vector<int>, size_t> > vect_of_pairs;
typedef std::deque<std::pair<std::deque<int>, size_t> > deq_of_pairs;

template <typename T>
struct compare_pair_value
{
	size_t	*_comparisons;
	compare_pair_value(size_t *comparisons): _comparisons(comparisons){};
	bool operator()(const T& pair, int value) const
	{
		++(*_comparisons);
		return pair.first.back() < value;
	}
};

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
	bool compare_pairs(const T& a, const T& b)
	{
		_comparisons++;
		return a[a.size() - 1] > b[b.size() - 1];
	}

	template <typename T>
	void compare_and_sort(T &cont)
	{
		size_t	i = 1;
		while (i < cont.size())
		{
			if (compare_pairs(cont[i - 1].first, cont[i].first))
				std::swap(cont[i - 1], cont[i]);
			i +=2;
		}
	}

	template <typename T, typename Iterator>
	Iterator	binary_search(T& main, Iterator partner, int value)
	{
		Iterator it;
		it = std::lower_bound(main.begin(), partner, value, compare_pair_value<typename T::value_type>(&_comparisons));
		return it;
	}

	template <typename T>
	typename T::iterator find_partner(T& main, size_t partner_id)
	{
		typename T::iterator it = main.begin();
		while (it < main.end())
		{
			if (it->second == partner_id)
				return it;
			it++;
		}
		return it;
	}

	template <typename T, typename pair_type>
	void	insertion(T& cont, pair_type extra)
	{
		T pend;
		T main;
		typename T::iterator partner;
		typename T::iterator it;
		size_t	i = 1;
		while (i < cont.size() && i % 2 == 0)
		{
			pend.push_back(cont[i]);
			i++;
		}
		if (extra.first.empty() == 0)
			pend.push_back(extra);
		i = 0;
		main.push_back(cont[0]);
		while (i < cont.size() && i % 2 != 0)
		{
			main.push_back(cont[i]);
			i++;
		}
		i = 0;
		while (i < pend.size())
		{
			partner = find_partner(main, pend[i].second + 1);
			it = binary_search(main, partner, pend[i].first.back());
			main.insert(it, pend[i]);
		}
		cont = main;
	}
};

int	print_error(std::string message);

#endif