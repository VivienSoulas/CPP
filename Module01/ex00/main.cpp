#include "Zombie.h"

// Now, what is the actual point of the exercise? You have to determine in which case
// it is better to allocate zombies on the stack or the heap.
int main()
{
	Zombie z("BOB");  // Stack allocation - no pointer needed
	z.announce();     // Use the zombie
	
	randomChump("randomChump");
	Zombie* new_zombie = newZombie("new_Zombie_name");

	std::cout	<< "calling on new_zombie announce outside of it's function's scope: ";
	new_zombie->announce();

	delete new_zombie;
	// this should fail as new_zombie is now destroyed
	std::cout	<< "calling on new_zombie announce: ";
	new_zombie->announce();

	return (0);
}