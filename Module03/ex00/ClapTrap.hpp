#pragma once
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	private:
	std::string name;
	int hit_point;
	int energy_point;
	int attack_damage;

	public:
	ClapTrap( std::string input );
	ClapTrap( const ClapTrap &other );
	ClapTrap &operator=( const ClapTrap &other );
	~ClapTrap();

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void emptyEnergy();
	void emptyHitPoint();
};

#endif