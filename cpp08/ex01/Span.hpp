#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <iostream>

class Span
{
	private:
		std::vector<int>	_numbers;
		unsigned int		_max;
	public:
    	Span();
		Span(unsigned int n);
		Span(const Span& other); 
		Span& operator=(const Span& other);
		~Span();

	int				shortestSpan();
	int				longestSpan();
	void			addNumber(int value);
	int 			getNumber(unsigned int i) const;
	std::size_t		getSize(void) const;

	template <typename T>
	void	addNumber(T start, T end)
	{
		typename std::iterator_traits<T>::difference_type range = std::distance(start, end);
		long newRange = range < 0 ? -range : range;
		if (static_cast<std::size_t>(newRange) > _max - _numbers.size())
			throw std::out_of_range("Reached max capacity.");
		if (range < 0)
		{
			std::reverse_iterator<T> rstart(start);
			std::reverse_iterator<T> rend(end);
			std::copy(rstart, rend, back_inserter(_numbers));
		}
		else
			std::copy(start, end, back_inserter(_numbers));
	}

	class noSpan : public std::exception
	{
		public:
			const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &stream, const Span &span);

#endif
