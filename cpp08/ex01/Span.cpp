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
	return _numbers[i];
}

std::size_t	Span::getSize(void) const
{
	return _numbers.size();
}

std::ostream &operator<<(std::ostream &stream, const Span &span)
{
	for (unsigned int i = 0; i < span.getSize(); i++)
		stream << span.getNumber(i) << "\n";
	return stream;
}