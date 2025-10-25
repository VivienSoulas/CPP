#include "ICharacter.hpp"

std::string const &ICharacter::getName() const
{
	static const std::string empty = "";
	return (empty);
}

void ICharacter::equip(AMateria* m)
{
	(void)m;
}

void ICharacter::unequip(int idx)
{
	(void)idx;
}

void ICharacter::use(int idx, ICharacter& target)
{
	(void)idx;
	(void)target;
}

std::ostream &operator<<( std::ostream &os, const ICharacter &other )
{
	os << other.getName();
	return (os);
}