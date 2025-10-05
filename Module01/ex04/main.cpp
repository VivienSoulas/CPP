#include "losers.hpp"

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		Text text(av[1], av[2], av[3]);
	// open file to read
		std::ifstream file_in(av[1]);
		if (!file_in.is_open())
		{
			text.Error(av[1]);
			return (1);
		}
	// open file to write output
		std::string new_out = text.getNewFileName();
		std::ofstream file_out(new_out.c_str());
		if (!file_out.is_open())
		{
			text.Error(new_out);
			return (1);
		}
	// reads from the in file and replace
		std::string read;
		while ( getline(file_in, read) )
		{
			std::string replaced;
			replaced = text.replacementFunction(read);
			file_out << replaced << std::endl;
		}
	// close open files
		file_in.close();
		file_out.close();
	}
	else
	{
		std::cerr << "wrong number of arguments" << std::endl;
		return (1);
	}
	return (0);
}