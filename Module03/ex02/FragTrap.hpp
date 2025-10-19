#pragma once
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
	FragTrap( std::string input );
	FragTrap( const FragTrap &other );
	FragTrap &operator=( const FragTrap &other );
	~FragTrap();

	void attack( const std::string& target );
	void highFivesGuys( void );
};

#endif