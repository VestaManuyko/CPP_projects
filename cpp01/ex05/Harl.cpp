#include "Harl.hpp"

Harl::Harl()
{
	return;
}

Harl::~Harl()
{
	return ;
}

void Harl::complain(std::string level)
{
	int	i = 0;

	if (level.empty())
		return ;
	void (Harl::*funcs[4])() = {&Harl::debug, &Harl::info,
    	&Harl::warning, &Harl::error};
	if (level.size() == 1 && isdigit(level[0]))
	{
		std::istringstream(level) >> i;
		i--;
	}
	else
	{
		std::string levels[5] = {"DEBUG", "INFO", "WARNING", "ERROR", "UNKNOWN"};
		while (i < 4 && levels[i] != level)
			i++;
	}
	if (i > 3 || i < 0)
		return ;
	(this->*funcs[i])();
}

void Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}
void Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didnt put enough bacon in my burger! If you did, I wouldnt be asking for more!" << std::endl;
}

void Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
