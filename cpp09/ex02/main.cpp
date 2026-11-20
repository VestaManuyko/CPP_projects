#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc < 2)
			return print_error("Error: no args\n");
		PmergeMe a(argv, argc);
		a.merge_insertion();
		//a.print_containers();
	}
	catch(const std::exception& e)
	{
		return 1;
	}
	//start timer for deq
	//merge_insertion(deq);
	//make merge_insertion return the time used from start to finish?(look into if makes sense with recursion)
	//merge_insertion(vect);
	//print time output + before/after etc.
	return 0;
}
