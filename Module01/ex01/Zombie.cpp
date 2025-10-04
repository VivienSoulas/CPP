#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "constructor for zombie called" << std::endl;
}

Zombie::~Zombie()
{
	std::cout	<< name
				<< " has been destroyed !"
				<< std::endl;
}

void Zombie::announce()
{
	std::cout	<< name
				<< ": BrainnnnnZZZzzz !"
				<< std::endl;
}

void Zombie::setName( std::string input )
{
	name = input;
	std::cout << "name \"" << input << "\" given to zombie" << std::endl;
}