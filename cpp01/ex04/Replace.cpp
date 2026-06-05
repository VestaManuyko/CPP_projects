#include "Replace.hpp"

Replace::Replace()
{
	_content = NULL;
	return ;
}

Replace::~Replace()
{
	return ;
}

void Replace::assignContent(std::string *newContent)
{
	_content = newContent;
}
int Replace::createReplacedFile(std::string newExtension)
{
	_replacedFile.open((const char *)newExtension.c_str());
	if (!_replacedFile.is_open())
	{
		std::cerr << "Error opening replacement file" << std::endl;
    	return 1;
	}
	return 0;
}

void Replace::replaceContent(std::string s1, std::string s2)
{
	size_t	pos = 0;

	if (!s1.empty())
	{
		while ((pos = _content->find(s1, pos)) != _content->npos)
		{
			_content->insert(pos, s2);
			_content->erase(pos + s2.size(), s1.size());
			pos += s2.size();
		}
	}
	_replacedFile << *_content;
}

void Replace::deleteContent()
{
	if (_content != NULL)
		delete(_content);
}
