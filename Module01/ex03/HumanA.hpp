#pragma once
#ifndef HUMAN_A
#define HUMAN_A

#include <iostream>
#include "Weapon.hpp"

// Stores a reference to an existing Weapon so HumanA sees updates to that Weapon.
class HumanA
{
	private:
		std::string name;
		Weapon&		weapon;

	public:
	HumanA( std::string input, Weapon& type );
	~HumanA();
	void attack();
};

#endif