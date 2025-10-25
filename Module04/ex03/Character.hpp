#pragma once
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
	std::string name;
	AMateria *inventory[4];
	AMateria *dropped_items[100];

	public:
	Character( std::string input );
	Character( const Character &other );
	~Character();
	Character &operator=( const Character &other );
	std::string const & getName() const;
	
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif