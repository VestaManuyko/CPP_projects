#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

static void title(const std::string &s)
{
	std::cout << std::endl;
    std::cout << "=== " << s << " ===" << std::endl;
}

int main()
{
	{
	title("Vector");
	std::cout << "Testing an int container with 1 2 3 2, trying to find 2:\n";
	std::vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(2);

	std::vector<int>::iterator it;
	try
	{
		it = easyfind<std::vector<int> >(a, 2);
		std::cout << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << "Cheking that the returned pointer is the first occurence:\n";
	std::cout << static_cast<void*>(&(*it)) << "=" << static_cast<void*>(&a[1]) << std::endl;
	std::cout << "Modifying returned value to 4 and trying to search 2 again...\n";
	*it = 4;
	try
	{
		it = easyfind<std::vector<int> >(a, 2);
		std::cout << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	}
	{
	title("List");
	std::cout << "Testing an int container with 1 2 3, trying to find 2:\n";
	std::list<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	std::list<int>::iterator it;
	try
	{
		it = easyfind<std::list<int> >(a, 2);
		std::cout << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << "Modifying returned value to 4 and trying to search 2 again...\n";
	*it = 4;
	try
	{
		it = easyfind<std::list<int> >(a, 2);
		std::cout << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	}
	{
	title("Deque");
	std::cout << "Testing an int container with 1 2 3, trying to find 2:\n";
	std::deque<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	std::deque<int>::iterator it;
	try
	{
		it = easyfind<std::deque<int> >(a, 2);
		std::cout << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << "Modifying returned value to 4 and trying to search 2 again...\n";
	*it = 4;
	try
	{
		it = easyfind<std::deque<int> >(a, 2);
		std::cout << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	}
}
