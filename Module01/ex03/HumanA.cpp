#include "HumanA.hpp"

// new way of assigning data in constructor
HumanA::HumanA( std::string input, Weapon& type )
	: name(input), weapon(type)
{
}

HumanA::~HumanA()
{
}

void HumanA::attack()
{
	std::cout	<< name
				<< " attacks with their "
				<< weapon.getType()
				<< std::endl;
}