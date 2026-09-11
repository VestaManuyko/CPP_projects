#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>

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

	int		shortestSpan();
	int		longestSpan();
	void	addNumber(int value);

	template <typename T>
	void	addNumber(typename T::iterator start, typename T::iterator end)
	{
		long space_left = _max - _numbers.size();
		std::iterator_traits<typename T::iterator>::difference_type range = std::distance(start, end);
		if (range > space_left)
			throw std::out_of_range("Reached max capacity.");
		std::copy(start, end, _numbers.end());
	}

	class noSpan : public std::exception
	{
		public:
			const char* what() const throw();
	};
};

#endif
