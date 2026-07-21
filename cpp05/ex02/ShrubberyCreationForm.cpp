#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreation", 145, 137)
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreation", 145, 137)
{
	_target = target;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other)
{
	return ;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	return ;
}

void	ShrubberyCreationForm::executeForm() const
{
	std::string filename = _target + "_shrubbery";
	std::ofstream newFile(filename);
	if (newFile.is_open() == false)
	{
		std::cerr << "Could not create file: " 
                  << filename << std::endl;
        return;
	}
	newFile << "       *\n      ***\n     *****\n    *******\n   *********\n      |||\n      |||";
	newFile.close();
}