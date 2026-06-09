#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
    	Fixed();
		Fixed(const Fixed& other); 
		Fixed& operator=(const Fixed& other);
		~Fixed();

		int		getRawBits() const;
		void	setRawBits(const int raw);

	private:
		int					_fixed;
		static const int	_fractionalBits = 8;
};

#endif
