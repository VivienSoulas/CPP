#include "Zombie.hpp"

Zombie::Zombie( std::string input)
{
	name = input;
	announce();
}

Zombie::~Zombie()
{
	std::cout	<< name
				<< " has been destroyed !"
				<< std::endl;
}

void Zombie::announce( void )
{
	std::cout	<< name
				<< ": BraiiiiiiinnnzzzZ..."
				<< std::endl;
}
