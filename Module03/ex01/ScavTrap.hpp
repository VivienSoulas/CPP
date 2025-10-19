#pragma once
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:

	public:
	ScavTrap( std::string input );
	ScavTrap( const ScavTrap &other );
	ScavTrap &operator=( const ScavTrap &other );
	~ScavTrap();

	void attack(const std::string& target);
	void guardGate();
	
	std::string getName();
	int getHitPoint();
	int getEnergyPoint();
	int getAttackDamage();
};

#endif