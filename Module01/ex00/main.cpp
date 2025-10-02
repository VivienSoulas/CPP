#include "Zombie.h"

// Now, what is the actual point of the exercise? You have to determine in which case
// it is better to allocate zombies on the stack or the heap.
int main()
{
	// Stack allocation
	Zombie z("BOB");
	z.announce();

	// Stack allocation
	randomChump("randomChump");
	// this should fail as randmChump has been destroyed
	//randomChump.announce();


	// Heap allocation
	Zombie* new_zombie = newZombie("new_Zombie");
	std::cout	<< "calling on new_zombie announce outside of it's creation function: ";
	new_zombie->announce();

	delete new_zombie;
	// this should fail as new_zombie is now destroyed
	//std::cout	<< "calling on new_zombie announce: ";
	//new_zombie->announce();

	
	z.announce();
	return (0);
}