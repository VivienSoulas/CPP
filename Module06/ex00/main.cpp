#include "ScalarConverter.hpp"
#include "char.hpp"
#include "int.hpp"
#include "float.hpp"
#include "double.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return (std::cout << "Not enought/too many arguments\n", 1);
	Char character;
	Int interger;
	Float fLoater;
	Double doubler;

	character.convert(av[1]);
	interger.convert(av[1]);
	fLoater.convert(av[1]);
	doubler.convert(av[1]);
	
	return (0);
}