#include "HumanB.hpp"

HumanB::HumanB( std::string input )
	: name(input), weapon(NULL)
{
}

HumanB::~HumanB()
{
}

// could check for if (weapon)
void HumanB::attack()
{
	if (weapon)
	{
		std::cout	<< name
					<< " attacks with their "
					<< weapon->getType()
					<< std::endl;
	}
	else
		std::cout	<< name
					<< " attacks bare handed\n";
}

void HumanB::setWeapon( Weapon& type )
{
	weapon = &type;
}