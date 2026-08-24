#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include "A.cpp"
#include "B.hpp"
#include "C.hpp"

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
		return new A;
		break;
	}
	case 1:
	{
		return new B;
		break;
	}
	case 2:
	{
		return new C;
		break;
	}
	}
	return new A;
}

void identify(Base* p)
{

}

void identify(Base& p)
{

}
