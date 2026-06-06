#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl guy;
	int i = 0;

	if (argc != 2)
		return 0;
	std::string arg = argv[1];
	if (arg.empty())
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return 0;
	}
	if (arg.size() == 1 && isdigit(arg[0]))
	{
		std::istringstream(arg) >> i;
	}
	else
	{
		std::string levels[5] = {"DEBUG", "INFO", "WARNING", "ERROR", "UNKNOWN"};
			while (i < 4 && levels[i] != argv[1])
				i++;
		i++;
	}
	switch (i)
	{
		case 1:
		{
			std::cout << "[ DEBUG ]" << std::endl;
			guy.complain("1");
			std::cout << std::endl;
		}
		case 2:
		{
			std::cout << "[ INFO ]" << std::endl;
			guy.complain("2");
			std::cout << std::endl;
		}
		case 3:
		{
			std::cout << "[ WARNING ]" << std::endl;
			guy.complain("3");
			std::cout << std::endl;
		}
		case 4:
		{
			std::cout << "[ ERROR ]" << std::endl;
			guy.complain("4");
			std::cout << std::endl;
			break ;
		}
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return 0;
}
