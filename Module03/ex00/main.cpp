#include "ClapTrap.hpp"

// negative numbers will behave unexpetidly
int main()
{
	ClapTrap ClapTrap("Vivien");

std::cout << "\n";
	ClapTrap.attack("Eliot");
	ClapTrap.takeDamage(5);
	ClapTrap.beRepaired(5); // back to 10 HP
std::cout << "\n";
	ClapTrap.takeDamage(9); // down to 1 HP
std::cout << "\n";
	ClapTrap.attack("Eliot");
	ClapTrap.beRepaired(5); // nack to 6 HP
std::cout << "\n";
	ClapTrap.attack("Eliot");
	ClapTrap.attack("Eliot");
	ClapTrap.attack("Eliot");
	ClapTrap.attack("Eliot");
	ClapTrap.attack("Eliot");
	// ClapTrap.takeDamage(6);
	ClapTrap.attack("Eliot");
std::cout << "\n";
	ClapTrap.beRepaired(5);
	ClapTrap.attack("Eliot");
std::cout << "\n";
}