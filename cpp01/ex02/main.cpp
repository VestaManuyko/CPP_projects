#include <iostream>

int main(void)
{
	std::string str ="HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;


	std::cout << "The str memory address: "<< &str << std::endl;
	std::cout << "The stringPTR memory address: "<< stringPTR << std::endl;
	std::cout << "The stringREF memory address: "<< &stringREF << std::endl;

	std::cout << "The str value: "<< str << std::endl;
	std::cout << "The stringPTR value: "<< *stringPTR << std::endl;
	std::cout << "The stringREF value: "<< stringREF << std::endl;
}
