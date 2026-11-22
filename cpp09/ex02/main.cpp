#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc < 2)
			return print_error("Error: no args\n");
		PmergeMe a(argv, argc);
		a.merge_insertion();
	}
	catch(const std::exception& e)
	{
		return 1;
	}
	return 0;
}
