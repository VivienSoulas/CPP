#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Zombie
{
	private:
	std::string name;
	int			index;
	int			count;

	public:
	Zombie();
	~Zombie();
	announce();
};

#endif