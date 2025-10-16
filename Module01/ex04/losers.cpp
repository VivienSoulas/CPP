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


void Text::Error( std::string string )
{
	std::cerr	<< "Error: failled to open "
				<< string
				<< std::endl;
}

// when found isnt found it return std::string::npos
std::string Text::replacementFunction( std::string original )
{
	size_t	found;
	size_t	pos = 0;
	std::string string1 = getString1();
	std::string string2 = getString2();
	std::string replaced;

	if (string1.empty())
		return original;
	while ( (found = original.find(string1, pos)) != std::string::npos )
	{
		replaced.append(original.substr(pos, found - pos));
		replaced.append(string2);
		pos = found + string1.length();
	}
	replaced.append(original.substr(pos));
	return (replaced);
}

// less readeable but the same as above
// std::string Text::replacementFunction( std::string original )
// {
// 	size_t	found;
// 	size_t	pos = 0;
// 	std::string replaced;

// 	while ( (found = original.find(getString1(), pos)) != std::string::npos )
// 	{
// 		replaced.append(original.substr(pos, found - pos));
// 		replaced.append(getString2());
// 		pos = found + getString1().length();
// 	}
// 	replaced.append(original.substr(pos));
// 	return (replaced);
// }