#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
	Animal **AnimalArray = new Animal*[10];
	// Animal *Baboon = new Animal();

// Initialisation
	std::cout	<< "\nAssigning 5 Cat to the first half of the array:\n";
	for (int i = 0; i < 5; i++)
	{
		AnimalArray[i] = new Cat("Cat");
		AnimalArray[i]->setLoggerType(CatType);
	}
	std::cout	<< "\nAssigning 5 Dog to the second half of the array:\n";
	for (int i = 5; i < 10; i++)
	{
		AnimalArray[i] = new Dog("Dog");
		AnimalArray[i]->setLoggerType(DogType);
	}


// First cat and First dog
std::cout	<< "\nFirst AnimalArray should be a cat\n";
	AnimalArray[0]->whoAmI();
std::cout	<< "\nSixth AnimalArray should be a dog\n";
	AnimalArray[6]->whoAmI();

// changing ideas of cat
std::cout	<< "\nAssigning idea to first cat\n";
	AnimalArray[0]->setIdea("I want fish");
	AnimalArray[0]->whoAmI();
// changing idea of dog
std::cout	<< "\nAssigning idea to first Dog\n";
	AnimalArray[6]->setIdea("Squirel!");
	AnimalArray[6]->whoAmI();

// statement before deep copy
std::cout	<< "\n\nBefore the deep copy, First cat:\n";
	AnimalArray[0]->whoAmI();
std::cout	<< "Second cat\n";
	AnimalArray[1]->whoAmI();
std::cout	<< "\n";

// deep copy
	Animal *temp = AnimalArray[0]->clone();
	delete(AnimalArray[1]);
	AnimalArray[1] = temp;

// statement after deep copy
std::cout	<< "\nAfter the deep copy, First cat:\n";
	AnimalArray[0]->whoAmI();
std::cout	<< "Second cat\n";
	AnimalArray[1]->whoAmI();

// proof of deep copy
std::cout	<< "Changing idea of first cat\n";
	AnimalArray[0]->setIdea("I want Salmon");
std::cout	<< "First cat\n";
	AnimalArray[0]->whoAmI();
std::cout	<< "Second cat\n";
	AnimalArray[1]->whoAmI();
std::cout	<< "\n\n";

	for(int i = 0; i < 10; i++)
		delete(AnimalArray[i]);

	delete[](AnimalArray);
	return (0);
}