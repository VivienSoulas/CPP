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
	std::cout	<< name
				<< " attacks with their "
				<< weapon->getType()
				<< std::endl;
}

void HumanB::setWeapon( Weapon& type )
{
	weapon = &type;
}