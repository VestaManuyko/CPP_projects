#include <cctype>
#include <iostream>

int	main(int argc, char **argv)
{
	int	i;		
	std::size_t j;
	std::string str;

	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		i = 1;
		while (argv[i])
		{
			str = argv[i];
			j = 0;
			while (j < str.length())
			{
				str[j] = std::toupper(str[j]);
				j++;
			}
			std::cout << str;
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}
