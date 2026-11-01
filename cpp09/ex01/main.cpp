#include <iostream>
#include "rpn.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			return print_error("Error: not correct amount of args\n");
		return rpn(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
