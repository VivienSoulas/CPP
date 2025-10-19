#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
std::cout <<	"CLAPTRAP\n";
	ClapTrap ClapTrap("Bev");
	ClapTrap.attack("IT");
	ClapTrap.takeDamage(9);
	ClapTrap.beRepaired(50);
std::cout << "\n";
std::cout <<	"SCAVTRAP\n";
	ScavTrap ScavTrap("Eddie");
	ScavTrap.attack("Eliot");
	ScavTrap.takeDamage(90);
	ScavTrap.beRepaired(90); // back to 100 HP
	ScavTrap.guardGate();
std::cout << "\n";
std::cout << "FRAGTRAP\n";
	FragTrap FragTrap("Billy");
	FragTrap.attack("Ricky");
	FragTrap.takeDamage(90);
	FragTrap.beRepaired(50);
	FragTrap.highFivesGuys();
std::cout << "\n";
std::cout <<	"DIAMONDTRAP\n";
	DiamondTrap DiamondTrap("Billy");
	DiamondTrap.attack("Ricky");
	DiamondTrap.takeDamage(90);
	DiamondTrap.beRepaired(50);
	DiamondTrap.whoAmI();
	DiamondTrap.highFivesGuys();
	DiamondTrap.guardGate();
std::cout << "\n";
}