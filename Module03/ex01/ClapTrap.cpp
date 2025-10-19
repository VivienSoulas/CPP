#include "ScavTrap.hpp"

ClapTrap::ClapTrap( std::string input )
	: name(input), hit_point(100), energy_point(50), attack_damage(20)
{
	std::cout	<< "ClapTrap constructor called\n";
}

ClapTrap::ClapTrap( const ClapTrap &other )
	: name(other.name), hit_point(other.hit_point), energy_point(other.energy_point), attack_damage(other.attack_damage)
{
	std::cout	<< "ClapTrap copy constructor called\n";
}

ClapTrap &ClapTrap::operator=( const ClapTrap &other )
{
	if (this != &other)
	{
		name = other.name;
		hit_point = other.hit_point;
		energy_point = other.energy_point;
		attack_damage = other.attack_damage;
		std::cout	<< "ClapTrap operator overload called\n";
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout	<< "ClapTrap destructor called\n";
}


/*========================================================================*/

void ClapTrap::attack(const std::string& target)
{
	if (hit_point > 0)
	{
		if (energy_point >= 1)
		{
			std::cout	<< "ClapTrap "
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

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hit_point > 0)
	{
		std::cout	<< "ClapTrap "
				<< name
				<< " takes "
				<< amount
				<< " points of damages\n";
		hit_point -= amount;
	}
	else
		std::cout	<< "ClapTrap "
					<< name
					<< " is already low in hit point\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hit_point > 0)
	{
		if (energy_point >= 1)
		{
			std::cout	<< "ClapTrap "
						<< name
						<< " repairs "
						<< amount
						<< " points of damages\n";
			hit_point += amount;
			energy_point--;
		}
		else
			emptyEnergy();
	}
	else
		emptyHitPoint();
}

void ClapTrap::emptyEnergy()
{
	std::cout	<< "Not enought energy\n";
}

void ClapTrap::emptyHitPoint()
{
	std::cout	<< "Not enought hit point\n";
}

std::string ClapTrap::getName()
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