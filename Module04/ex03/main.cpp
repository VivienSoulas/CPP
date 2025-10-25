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
std::cout << "\n";
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
std::cout << "\n";
	tmp = src->createMateria("cure");
	me->equip(tmp);
std::cout << "\n";
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(10, *bob);
std::cout << "\n";
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
std::cout << "\n";
	tmp = src->createMateria("cure");
	me->equip(tmp);
std::cout << "\n";
	me->unequip(1);
	me->unequip(10);
	delete bob;
	delete me;
	delete src;
	return 0;
}
