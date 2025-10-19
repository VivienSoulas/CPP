#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( std::string input )
	: ClapTrap(input + "_clap_name"), FragTrap(input), ScavTrap(input), name(input)
{
	hit_point = 100;
	energy_point = 50;
	attack_damage = 30;
	std::cout	<< "DiamondTrap constructor called\n";
}

DiamondTrap::DiamondTrap( const DiamondTrap &other )
	: ClapTrap(other), FragTrap(other), ScavTrap(other), name(other.name)
{
	std::cout	<< "DiamondTrap copy constructor called\n";
}

DiamondTrap &DiamondTrap::operator=( const DiamondTrap &other )
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		std::cout	<< "DiamondTrap operator overload called\n";
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout	<< "DiamondTrap destructor called\n";
}

void DiamondTrap::attack( const std::string &target )
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout	<< "DiamondTrap My name is "
				<< name
				<< " My ClapTrap name is "
				<< ClapTrap::name
				<< "\n";
}