#include "Span.hpp"
#include <iostream>
#include <algorithm>

Span::Span() : _max(0){};

Span::Span(unsigned int n) : _max(n){};

Span::Span(const Span& other) : _numbers(other._numbers), _max(other._max) {};

Span& Span::operator=(const Span& other)
{
	_numbers = other._numbers;
	_max = other._max;
	return (*this);
}

Span::~Span() {};

const char *Span::noSpan::what() const throw()
{
	return ("No span.");
}

void	Span::addNumber(int value)
{
	if (_numbers.size() == _max)
		throw std::out_of_range("Reached max capacity.");
	_numbers.push_back(value);
}

int Span::getNumber(unsigned int i) const
{
	if (i >= getSize() || i < 0)
		return 0;
	return _numbers[i];
}

std::size_t	Span::getSize(void) const
{
	return _numbers.size();
}

int	Span::longestSpan()
{
	if (_numbers.size() < 2)
		throw noSpan();
	std::vector<int>::iterator min = std::min_element(_numbers.begin(), _numbers.end());
	std::vector<int>::iterator max = std::max_element(_numbers.begin(), _numbers.end());
	return *max - *min;
}

int	Span::shortestSpan()
{
	int diff = 2147483647;
	int tmp_diff = 0;
	if (_numbers.size() < 2)
		throw noSpan();
	std::vector<int> tmp(_numbers);
	std::sort(tmp.begin(), tmp.end());
	for (unsigned i = 1; i < tmp.size(); i++)
	{
		tmp_diff = diff;
		diff = tmp[i] - tmp[i - 1];
		if (diff > tmp_diff)
			return tmp_diff;
	}
	return tmp_diff;
}

std::ostream &operator<<(std::ostream &stream, const Span &span)
{
	for (unsigned int i = 0; i < span.getSize(); i++)
		stream << span.getNumber(i) << "\n";
	return stream;
}