#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

Character::Character( std::string input )
	: name(input)
{
	for (int i = 0; i< 4; i++)
		inventory[i] = NULL;
	for (int i = 0; i< 100; i++)
		dropped_items[i] = NULL;
}

Character::Character( const Character &other )
	: name(other.name)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i] != NULL)
		{
			if (inventory[i])
				delete(inventory[i]);
			inventory[i] = other.inventory[i]->clone();
		}
		else
			inventory[i] = NULL;
	}
	for (int i = 0; i< 100; i++)
		dropped_items[i] = NULL;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
			delete(inventory[i]);
	}
	for (int i = 0; i< 100; i++)
	{
		if (dropped_items[i])
			delete(dropped_items[i]);
	}
}

Character &Character::operator=( const Character &other )
{
	if (this != &other)
	{
		name = other.name;
		for (int i = 0; i < 4; i++)
		{
			if (inventory[i])
				delete(inventory[i]);
			if (other.inventory[i])
				inventory[i] = other.inventory[i]->clone();
			else
				inventory[i] = NULL;
		}
		for (int i = 0; i< 100; i++)
		{
			if (other.dropped_items[i])
				dropped_items[i] = other.dropped_items[i]->clone();
			else
				dropped_items[i] = NULL;
		}
	}
	return (*this);
}

std::string const &Character::getName() const
{
	return (name);
}

void Character::equip(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
			std::cout << getName() << " equiped with " << m->getType() << "\n";
			return ;
		}
	}
	delete(m);
	std::cout << "No empty inventory slot left\n";
}

void Character::unequip(int idx)
{
	if (idx > 4)
	{
		std::cout << "Invalid index\n";
		return ;
	}
	if (inventory[idx])
	{
		std::cout	<< this->getName()
					<< " dropped "
					<< inventory[idx]->getType()
					<< " on the floor\n";
		for (int i = 0; i < 100; i++)
		{
			if (dropped_items[i] == NULL)
			{
				dropped_items[i] = inventory[idx];
				inventory[idx] = NULL;
				return ;
			}
		}
	}
	else
		std::cout << "Empty inventory slot\n";
}

void Character::use(int idx, ICharacter& target)
{
	if (idx > 4 || idx < 0)
	{
		std::cout << "Invalid index\n";
		return ;
	}
	if (inventory[idx])
		inventory[idx]->use(target);
	else
		std::cout << "Empty inventory slot\n";
}
