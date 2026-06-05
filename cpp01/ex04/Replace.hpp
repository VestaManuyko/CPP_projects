#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <new>

class Replace
{
	public:
    	Replace();
		~Replace();

	void	assignContent(std::string *newContent);
	int		createReplacedFile(std::string newExtension);
	void	replaceContent(std::string s1, std::string s2);
	void	deleteContent();

	private:
		std::string		*_content;
		std::ofstream	_replacedFile;
};

#endif
