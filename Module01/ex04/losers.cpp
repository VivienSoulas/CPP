#include "losers.hpp"

Text::Text( std::string filename, std::string string1, std::string string2 )
	:file_name(filename), string1(string1), string2(string2)
{
	new_file_name = file_name + ".replace";

}

Text::~Text()
{
}

std::string Text::getFileName()
{
	return (file_name);
}
std::string Text::getNewFileName()
{
	return (new_file_name.c_str());
}
std::string Text::getString1()
{
	return (string1);
}
std::string Text::getString2()
{
	return (string2);
}

std::string Text::replacementFunction( std::string original )
{
	size_t	found;
	size_t	pos = 0;
	std::string replaced;

	do
	{
		found = original.find(getString1(), pos);
		if (found)
		{
			replaced = original.substr(prev, found);
			replaced.append(getString2());
			prev = found;
		}
	} while (replaced.length() == original.length());
	return (replaced);
}