#include <iostream>
#include "MutantStack.hpp"
#include <list>

static void title(const std::string &s)
{
	std::cout << std::endl;
    std::cout << "=== " << s << " ===" << std::endl;
}

int main()
{

	title("Subject test");
	std::cout << "Mutant stack:\n";
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);

	std::cout << "List:\n";
	std::list<int> lstack;
	lstack.push_back(5);
	lstack.push_back(17);
	std::cout << lstack.back() << std::endl;
	lstack.pop_back();
	std::cout << lstack.size() << std::endl;
	lstack.push_back(3);
	lstack.push_back(5);
	lstack.push_back(737);
	lstack.push_back(0);
	std::list<int>::iterator lit = lstack.begin();
	std::list<int>::iterator lite = lstack.end();
	++lit;
	--lit;
	while (lit != lite)
	{
	std::cout << *lit << std::endl;
	++lit;
	}
	title("Default container type = std::list");
	MutantStack<std::string, std::list<std::string> > anotherStack;

	anotherStack.push("1string1");
	anotherStack.push("2string2");
	anotherStack.push("3string3");
	MutantStack<std::string, std::list<std::string> >::iterator iter = anotherStack.begin();
	MutantStack<std::string, std::list<std::string> >::iterator itere = anotherStack.end();
	++iter;
	--iter;
	while (iter != itere)
	{
	std::cout << *iter << std::endl;
	++iter;
	}
	title("Const iterator test");
	const MutantStack<int> constStack(mstack);
	MutantStack<int>::const_iterator iteree = constStack.begin();
	MutantStack<int>::const_iterator itereee = constStack.end();
	++iteree;
	--iteree;
	while (iteree != itereee)
	{
	std::cout << *iteree << std::endl;
	++iteree;
	}
	title("Reverse iterator test");
	MutantStack<int>::reverse_iterator jit = mstack.rbegin();
	MutantStack<int>::reverse_iterator jite = mstack.rend();
	++jit;
	--jit;
	while (jit != jite)
	{
	std::cout << *jit << std::endl;
	++jit;
	}
}
