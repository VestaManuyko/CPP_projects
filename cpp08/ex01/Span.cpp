#include "Span.hpp"
#include <iostream>
#include <algorithm>

Span::Span() : _max(0){};

Span::Span(unsigned int n) : _max(n){};

Span::Span(const Span& other) : _max(other._max), _numbers(other._numbers){};

Span& Span::operator=(const Span& other)
{
	_numbers = other._numbers;
	_max = _max;
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
