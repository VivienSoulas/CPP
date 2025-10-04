#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie* Zombie_horde = new Zombie[N];
	
	std::cout << std::endl;

	for (int i = 0; i < N; i++)
	{
		Zombie_horde[i].setName(name);
	}
	return (Zombie_horde);
}