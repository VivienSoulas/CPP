#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		memory[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		delete(memory[i]);
}

MateriaSource::MateriaSource( const MateriaSource &other )
{
	for (int i = 0; i < 4; i++)
	{
		if (other.memory[i])
			memory[i] = other.memory[i]->clone();
		else
			memory[i] = NULL;
	}
}

MateriaSource &MateriaSource::operator=( const MateriaSource &other )
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (memory[i])
				delete(memory[i]);
			if (other.memory[i])
				memory[i] = other.memory[i]->clone();
			else
				memory[i] = NULL;
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (memory[i] == NULL)
		{
			memory[i] = m->clone();
			std::cout	<< "New Materia: "
						<< m->getType()
						<< " learnt\n";
			delete(m);
			return ;
		}
	}
	delete(m);
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (memory[i] && memory[i]->getType() == type)
		{
			std::cout << "Materia " << memory[i]->getType() << " created\n";
			return (memory[i]->clone());
		}
	}
	std::cout	<< "No matching Materia found\n";
	return (NULL);
}