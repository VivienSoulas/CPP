#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
std::cout << "\nCreating Ice from template && equip:\n";
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
std::cout << "\nCreating Cure from template && equip:\n";
	tmp = src->createMateria("cure");
	me->equip(tmp);
std::cout << "\nUsing inventories:\n";
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(10, *bob);
std::cout << "\nCreating more items:\n";
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
std::cout << "\nCreating && equip one item too many\n";
	tmp = src->createMateria("cure");
	me->equip(tmp);
std::cout << "\nDropping one item on the floor\n";
	me->unequip(1);
std::cout << "\nCreation, equipment and use of water should be impossible:\n";
	tmp = src->createMateria("water");
	me->equip(tmp);
std::cout << "\nDrop of invalid index:\n";
	me->unequip(10);
	delete bob;
	delete me;
	delete src;
	return 0;
}
