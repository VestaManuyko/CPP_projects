#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

Base::~Base()
{
	return ;
}

Base * generate(void)
{
	srand(time(0));
	int number = rand() % 3;
	switch(number)
	{
	case 0:
	{
		std::cout << "generated A\n";
		return new A;
	}
	case 1:
	{
		std::cout << "generated B\n";
		return new B;
	}
	case 2:
	{
		std::cout << "generated C\n";
		return new C;
	}
	}
	return new A;
}

void identify(Base* p)
{
	if (p == NULL)
		return ;

	A *a = dynamic_cast<A*>(p);
	if (a != 0)
		std::cout << "The type of p is A" << std::endl;
	B *b = dynamic_cast<B*>(p);
	if (b != 0)
		std::cout << "The type of p is B" << std::endl;
	C *c = dynamic_cast<C*>(p);
	if (c != 0)
		std::cout << "The type of p is C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "The type of p is A" << std::endl;
	}
	catch(const std::exception& e) {} ;
	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "The type of p is B" << std::endl;
	}
	catch(const std::exception& e) {} ;
	try
	{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "The type of p is C" << std::endl;
	}
	catch(const std::exception& e) {} ;
}
