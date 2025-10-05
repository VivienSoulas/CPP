#pragma once
#ifndef HUMAN_B
#define HUMAN_B

#include <iostream>
#include "Weapon.hpp"

// non-owning pointer to the Weapon class, changes when the classe changes
// can be changed after construction unlike reference
class HumanB
{
	private:
		std::string name;
		Weapon* weapon;

	public:
	HumanB( std::string input );
	~HumanB();
	void attack();
	void setWeapon( Weapon& type );
};

#endif