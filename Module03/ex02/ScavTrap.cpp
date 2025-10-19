#include "ScavTrap.hpp"

ScavTrap::ScavTrap( std::string input ) : ClapTrap(input)
{
	hit_point = 100;
	energy_point = 50;
	attack_damage = 20;
	std::cout	<< "ScavTrap constructor called\n";
}

ScavTrap::ScavTrap( const ScavTrap &other ) : ClapTrap(other)
{
	std::cout	<< "ScavTrap copy constructor called\n";
}

ScavTrap &ScavTrap::operator=( const ScavTrap &other )
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		std::cout	<< "ScavTrap operator overload called\n";
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout	<< "ScavTrap destructor called\n";
}


void ScavTrap::attack( const std::string& target )
{
	if (hit_point > 0)
	{
		if (energy_point >= 1)
		{
			std::cout	<< "ScavTrap "
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

void ScavTrap::guardGate()
{
	if (hit_point > 0)
	{
		std::cout	<< "ScavTrap "
					<< name
					<< " is now in Gate keeper mode\n";
	}
	else
		emptyHitPoint();
}
