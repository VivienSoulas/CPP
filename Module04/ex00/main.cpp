#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
	Animal *Animals = new Animal("Animals");
	Animal *Cats = new Cat("Cat");
	Animal *Dogs = new Dog("Dog");
	WrongAnimal *WrondAnimals = new WrongAnimal("WrondAnimals");
	WrongAnimal *WrongCats = new WrongCat("WrongCats");

std::cout << "\n";
	std::cout	<< "Trying on animal sound: ";
	Animals->makeSound();
	std::cout	<< "Trying on Cat sound: ";
	Cats->makeSound();
	std::cout	<< "Trying on Dog sound: ";
	Dogs->makeSound();
	std::cout	<< "Trying on WrongCat sound: ";
	WrongCats->makeSound();
	std::cout	<< "Trying on WrongAnimal sound: ";
	WrondAnimals->makeSound();
std::cout << "\n";
	std::cout	<< "getting Animal type: "
				<< Animals->getType()
				<< "\n";
	std::cout	<< "getting Cat type: "
				<< Cats->getType()
				<< "\nCat parent animal type: "
				<< Cats->getType()
				<< "\n";
	std::cout	<< "getting Dog type: "
				<< Dogs->getType()
				<< "\nDog parent animal type: "
				<< Dogs->getType()
				<< "\n";
	std::cout	<< "getting WrongCat type: "
				<< WrongCats->getType()
				<< "\nWrongCat parent WrongAnimal type: "
				<< WrongCats->getType()
				<< "\n";
std::cout << "\n";



	delete(Animals);
	delete(Cats);
	delete(Dogs);
	delete(WrongCats);
	delete(WrondAnimals);
	return (0);
}