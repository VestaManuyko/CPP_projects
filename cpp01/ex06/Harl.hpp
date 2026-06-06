#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <cctype>
# include <sstream>

class Harl
{
	public:
    	Harl();
		~Harl();

	void	complain(std::string level);

	private:
		void	debug();
		void 	info();
		void	warning();
		void	error();
};

#endif
