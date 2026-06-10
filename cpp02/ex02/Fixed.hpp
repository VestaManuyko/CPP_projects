#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>
# include <climits>
# include <fstream>

class Fixed
{
	public:
    	Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& other); 
		Fixed& operator=(const Fixed& other);
		~Fixed();

		int		getRawBits() const;
		void	setRawBits(const int raw);
		float	toFloat() const;
		int		toInt() const;

		bool	operator<(const Fixed &other) const;
		bool	operator>(const Fixed &other) const;
		bool	operator>=(const Fixed &other) const;
		bool	operator<=(const Fixed &other) const;
		bool	operator==(const Fixed &other) const;
		bool	operator!=(const Fixed &other) const;

		Fixed 	operator+(const Fixed& other) const;
		Fixed 	operator-(const Fixed& other) const;
		// Fixed 	operator*(const Fixed& other) const;
		// Fixed 	operator/(const Fixed& other) const;

		private:
		int					_fixed;
		static const int	_fractionalBits = 8;
	};
	
	std::ostream & operator<<(std::ostream &stream, const Fixed &fixed);

#endif
