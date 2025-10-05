#include "Weapon.hpp"

Weapon::Weapon( std::string name )
	: type(name)
{
}

Weapon::~Weapon()
{
}

const std::string& Weapon::getType()
{
	const std::string& ref_to_type = type;
	return (ref_to_type);
}

void Weapon::setType( std::string new_type )
{
	type = new_type;
}