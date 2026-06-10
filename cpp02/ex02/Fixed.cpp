#include "Fixed.hpp"

Fixed::Fixed()
{
	_fixed = 0;
}

Fixed::Fixed(const int value)
{
	if (value > INT_MAX / 256)
	{
		std::cout << "Value exceeds max, set to INT_MAX" << std::endl;
		_fixed = INT_MAX;
		return ;
	}
	if (value < INT_MIN / 256)
	{
		std::cout << "Value exceeds min, set to INT_MIN" << std::endl;
		_fixed = INT_MIN;
		return ;
	}
	_fixed = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
	if (value > (float)INT_MAX / 256.0f)
	{
		std::cout << "Value exceeds max, set to INT_MAX" << std::endl;
		_fixed = INT_MAX;
		return ;
	}
	if (value < (float)INT_MIN / 256.0f)
	{
		std::cout << "Value exceeds min, set to INT_MIN" << std::endl;
		_fixed = INT_MIN;
		return ;
	}
	_fixed = roundf(value * 256);
}

Fixed::~Fixed()
{
	return ;
}

Fixed::Fixed(const Fixed &other) : _fixed(other._fixed)
{
	return ;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	_fixed = other._fixed;
	return *this;
}

int	Fixed::getRawBits() const
{
	return _fixed;
}

void Fixed::setRawBits(const int raw)
{
	_fixed = raw;
}

float	Fixed::toFloat() const
{
	return (_fixed / 256.0f);
}

int	Fixed::toInt() const
{
	return (_fixed >> _fractionalBits);
}

std::ostream & operator<<(std::ostream &stream, const Fixed &fixed)
{
	stream << fixed.toFloat();
	return (stream);
}

bool	operator<(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return 1;
	return 0;
}