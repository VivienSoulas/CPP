#include "Zombie.hpp"

int main()
{
	int		N = 5;
	Zombie* Zombie_horde;

	Zombie_horde = zombieHorde(N, "Bob");
	std::cout << std::endl;

	for (int i = 0; i < N; i++)
	{
		Zombie_horde[i].announce();
	}
	std::cout << std::endl;

	Zombie_horde[2].setName("Vivien");
	std::cout << std::endl;
	
	for (int i = 0; i < N; i++)
	{
		Zombie_horde[i].announce();
	}

	std::cout << std::endl;
	delete[] Zombie_horde;
	return (0);
}