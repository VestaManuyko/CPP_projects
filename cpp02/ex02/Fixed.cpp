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
	return (_fixed / 256);
}

std::ostream & operator<<(std::ostream &stream, const Fixed &fixed)
{
	stream << fixed.toFloat();
	return (stream);
}

bool	Fixed::operator<(const Fixed &other) const
{
	return (_fixed < other.getRawBits());
}

bool	Fixed::operator>(const Fixed &other) const
{
	return (_fixed > other.getRawBits());
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (_fixed >= other.getRawBits());
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (_fixed <= other.getRawBits());
}

bool	Fixed::operator==(const Fixed &other) const
{
	return (_fixed == other.getRawBits());
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return (_fixed != other.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(_fixed + other.getRawBits());
	return (result);
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(_fixed - other.getRawBits());
	return (result);
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	result.setRawBits((_fixed * other.getRawBits()) / 256);
	return (result);
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	Fixed result;
	result.setRawBits((_fixed * 256) / other.getRawBits());
	return (result);
}

Fixed	&Fixed::operator++()
{
	_fixed += 1;
	return (*this);
}

Fixed	&Fixed::operator--()
{
	_fixed -= 1;
	return (*this);
}

Fixed	Fixed::operator++(int unused)
{
	(void)unused;
	Fixed	ret = *this;
	_fixed += 1;
	return (ret);
}

Fixed	Fixed::operator--(int unused)
{
	(void)unused;
	Fixed	ret = *this;
	_fixed -= 1;
	return (ret);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a._fixed < b._fixed)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a._fixed > b._fixed)
		return a;
	return b;
}

const Fixed &Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a._fixed < b._fixed)
		return a;
	return b;
}

const Fixed &Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a._fixed > b._fixed)
		return a;
	return b;
}
