#include "ScavTrap.hpp"

ScavTrap::ScavTrap( std::string input )
{
	setName(input)
	hit_point(10)
	energy_point(10)
	attack_damage(0)
	std::cout	<< "ScavTrap constructor called\n";
}

ScavTrap::ScavTrap( const ScavTrap &other )
	: name(other.name), hit_point(other.hit_point), energy_point(other.energy_point), attack_damage(other.attack_damage)
{
	std::cout	<< "ScavTrap copy constructor called\n";
}

ScavTrap &ScavTrap::operator=( const ScavTrap &other )
{
	if (this != &other)
	{
		name = other.name;
		hit_point = other.hit_point;
		energy_point = other.energy_point;
		attack_damage = other.attack_damage;
		std::cout	<< "ScavTrap operator overload called\n";
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout	<< "ScavTrap destructor called\n";
}


void ScavTrap::attack(const std::string& target)
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
	std::cout	<< "ScavTrap "
				<< name
				<< " is now in Gate keeper mode\n";
}


std::string ScavTrap::getName()
{
	return (name);
}

int ClapTrap::getHitPoint()
{
	return (hit_point);
}

int ClapTrap::getEnergyPoint()
{
	return (energy_point);
}

int ClapTrap::getAttackDamage()
{
	return (attack_damage);
}
