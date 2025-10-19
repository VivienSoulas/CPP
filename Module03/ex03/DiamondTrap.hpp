#pragma once
#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
	std::string name;

	public:
	DiamondTrap( std::string input );
	DiamondTrap( const DiamondTrap &other );
	DiamondTrap &operator=( const DiamondTrap &other );
	~DiamondTrap();

	void attack( const std::string &target );
	void whoAmI();
};

#endif