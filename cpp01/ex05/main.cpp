#include "Harl.hpp"

int main()
{
	Harl guy;

	//with numbers
	std::cout << "DEBUG:" << std::endl;
	guy.complain("1");
	std::cout << "INFO:" << std::endl;
	guy.complain("2");
	std::cout << "WARNING:" << std::endl;
	guy.complain("3");
	std::cout << "ERROR:" << std::endl;
	guy.complain("4");
	//with strings
	std::cout << "DEBUG:" << std::endl;
	guy.complain("DEBUG");
	std::cout << "INFO:" << std::endl;
	guy.complain("INFO");
	std::cout << "WARNING:" << std::endl;
	guy.complain("WARNING");
	std::cout << "ERROR:" << std::endl;
	guy.complain("ERROR");
	//invalid numbers and strings
	std::cout << "Invalid inputs:" << std::endl;
	guy.complain("0");
	guy.complain("2147483648");
	guy.complain("warning");
	guy.complain("WARNINGG");
	guy.complain("");
	guy.complain(" ");
	guy.complain("lalla");
	guy.complain("ERROR ");
}
