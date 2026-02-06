#include "Deserializer.hpp"

Deserializer::Deserializer()
{}

Deserializer::~Deserializer()
{}



//It takes an unsigned integer parameter and converts it to a pointer to Data.
Data* Deserializer::deserialize(uintptr_t raw)
{
	std::cout << raw << "\n";
}