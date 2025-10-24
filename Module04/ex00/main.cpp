#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
	Animal *Giraffe = new Animal("Zoo");
	Cat *Gismo = new Cat("Cat");
	Dog *Rex = new Dog("Dog");
	WrongAnimal *Milou = new WrongAnimal("Milou");
	WrongCat *Gadget = new WrongCat("Gadget");
	Cat Soba = *Gismo;

std::cout << "\n";
	std::cout	<< "Trying on animal sound: ";
	Giraffe->makeSound();
	std::cout	<< "Trying on Cat sound: ";
	Gismo->makeSound();
	std::cout	<< "Trying on Dog sound: ";
	Rex->makeSound();
	std::cout	<< "Trying on WrongCat sound: ";
	Gadget->makeSound();
	std::cout	<< "Trying on WrongAnimal sound: ";
	Milou->makeSound();
std::cout << "\n";
	std::cout	<< "getting Animal type: "
				<< Giraffe->getType()
				<< "\n";
	std::cout	<< "getting Cat type: "
				<< Gismo->type
				<< "\nCat parent animal type: "
				<< Gismo->getType()
				<< "\n";
	std::cout	<< "getting Dog type: "
				<< Rex->type
				<< "\nDog parent animal type: "
				<< Rex->getType()
				<< "\n";
	std::cout	<< "getting WrongCat type: "
				<< Gadget->type
				<< "\nWrongCat parent WrongAnimal type: "
				<< Gadget->getType()
				<< "\n";
	std::cout	<< "getting Soba type: "
				<< Soba.type
				<< "\nSoba parent animal type: "
				<< Soba.getType()
				<< "\n";
std::cout << "\n";



	delete(Giraffe);
	delete(Gismo);
	delete(Rex);
	delete(Gadget);
	delete(Milou);
	return (0);
}