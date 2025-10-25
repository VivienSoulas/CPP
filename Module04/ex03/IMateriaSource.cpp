#include "IMateriaSource.hpp"

void IMateriaSource::learnMateria(AMateria*)
{}
AMateria* IMateriaSource::createMateria(std::string const & type)
{
	(void)type;
	return (NULL);
}