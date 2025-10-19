#include "FragTrap.hpp"

FragTrap::FragTrap( std::string input ) : ClapTrap(input)
{
	hit_point = 100;
	energy_point = 100;
	attack_damage = 30;
	std::cout	<< "FragTrap constructor called\n";
}

FragTrap::FragTrap( const FragTrap &other ) : ClapTrap(other)
{
	std::cout	<< "FragTrap copy constructor called\n";
}

FragTrap &FragTrap::operator=( const FragTrap &other )
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		std::cout	<< "FragTrap operator overload called\n";
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout	<< "FragTrap destructor called\n";
}


void FragTrap::attack( const std::string& target )
{
	if (hit_point > 0)
	{
		if (energy_point >= 1)
		{
			std::cout	<< "FragTrap "
						<< name
						<< " attacks "
						<< target
						<< ", causing "
						<< attack_damage
						<< " points of damages\n";
			energy_point--;
		}
		else
			emptyEnergy();
	}
	else
		emptyHitPoint();
}

void FragTrap::highFivesGuys()
{
	if (hit_point > 0)
	{
		std::cout	<< "FragTrap "
					<< name
					<< " is giving High Fives to everyone!\n";
	}
	else
		emptyHitPoint();
}

