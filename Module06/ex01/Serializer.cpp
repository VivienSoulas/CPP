#include "Serializer.hpp"

Serializer::Serializer()
{}

Serializer::~Serializer()
{}



//It takes a pointer and converts it to the unsigned integer type uintptr_t
uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t i;
	i = reinterpret_cast<uintptr_t>(ptr);
	return (i);
}

//It takes an unsigned integer parameter and converts it to a pointer to Data.
Data* Serializer::deserialize(uintptr_t raw)
{
	Data *data;
	data = reinterpret_cast<Data*>(raw);
	return (data);
}

