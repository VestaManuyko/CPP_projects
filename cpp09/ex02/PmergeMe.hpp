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
	size_t	get_comparisons();

	private:
	deq_of_pairs _deq;
	vect_of_pairs _vect;
	size_t	_comparisons;

	PmergeMe();
	int	convert_input(char **argv, int argc);
	int	check_input(std::string input);
	std::vector<size_t> jacobstahl_sequence(size_t pend_size);

	template <typename T, typename pair_type>
	void	split_pairs(const T &cont, T &merged_cont, pair_type &extra)
	{
		size_t i = 0;
		pair_type merged;
		while (i + 1 < cont.size())
		{
			merged = cont[i];
			merged.first.insert(merged.first.end(), cont[i + 1].first.begin(), cont[i + 1].first.end());
			merged_cont.push_back(merged);
			i += 2;
		}
		if (i < cont.size())
			extra = cont[i];
	}

	template <typename T>
	bool compare_pairs(const T& a, const T& b)
	{
		_comparisons++;
		return a.back() > b.back();
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
		pair_type	a;
		pair_type	b;
		size_t	i = 0;
		size_t	half = 0;

		while (i < cont.size())
		{
			half = cont[i].first.size() / 2;
			b.first.assign(cont[i].first.begin(), cont[i].first.begin() + half);
			a.first.assign(cont[i].first.begin() + half, cont[i].first.end());
			b.second = i;
			a.second = i;
			if (b.second == 0)
				main.push_back(b);
			else
				pend.push_back(b);
			main.push_back(a);
			i++;
		}
		if (extra.first.empty() == 0)
		{
			extra.second = i;
			pend.push_back(extra);
		}
		i = 0;
		std::vector<size_t> order = jacobstahl_sequence(pend.size() + 1);
		while (i < order.size())
		{
			size_t	idx = order[i] - 2;
			partner = find_partner(main, pend[idx].second);
			it = binary_search(main, partner, pend[idx].first.back());
			main.insert(it, pend[idx]);
			i++;
		}
		cont = main;
	}

	template <typename T>
	void print_cont(const T &cont)
	{
		size_t i = 0;
		size_t j = 0;
		while (i < cont.size())
		{
			std::cout << "Pair " << i << ": ";
			j = 0;
			while (j < cont[i].first.size())
			{
				std::cout << cont[i].first[j] << " ";
				j++;
			}
			std::cout << "index: " << cont[i].second << std::endl;
			i++;
		}
	}

	template <typename T>
	void	merge_insertion_template(T &cont)
	{
		if (cont.size() < 2)
			return ;
		T	merged_cont;
		typename T::value_type extra;
		compare_and_sort(cont);
		split_pairs(cont, merged_cont, extra);
		merge_insertion_template(merged_cont);
		insertion(merged_cont, extra);
		cont = merged_cont;
	}
};

int	print_error(std::string message);

#endif