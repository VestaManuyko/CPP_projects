#include "Replace.hpp"

int readFile(std::ifstream &file, Replace &newFile)
{
	std::ostringstream readFile;
	std::string 		*content;

	readFile << file.rdbuf();
	if (file.bad() || file.fail())
	{
		std::cerr << "Error reading provided file" << std::endl;
		return 1;
	}
	content = new std::string;
	*content = readFile.str();
	newFile.assignContent(content);
	return 0;
} 

int openReadFile(Replace &newFile, char **argv)
{
	std::ifstream file(argv[1]);

	if (!file.is_open())
	{
		std::cerr << "Error opening provided file" << std::endl;
    	return 1;
	}
	if (readFile(file, newFile) == 1)
		return 1;
	return 0;
}

int makeNewFile(Replace &newFile, char **argv)
{
	std::string newExtension;
	size_t		pos;

	newExtension = argv[1];
	pos = newExtension.rfind('.');
	if (pos != newExtension.npos)
	{
		newExtension.erase(pos + 1);
		newExtension += "replace";
	}
	else
		newExtension += ".replace";
	if (newFile.createReplacedFile(newExtension) == 1)
		return 1;
	newFile.replaceContent(argv[2], argv[3]);
	return 0;
}

int main(int argc, char **argv)
{
	Replace newFile;

	if (argc != 4)
	{
		std::cerr << "Incorrect number of arguments" << std::endl;
		return 1;
	}
	if (openReadFile(newFile, argv) == 1)
		return 1;
	if (makeNewFile(newFile, argv) == 1)
		return 1;
	newFile.deleteContent();
}
