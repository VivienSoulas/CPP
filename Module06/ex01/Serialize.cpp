#include "Serialize.hpp"

Serialize::Serialize()
{}

Serialize::~Serialize()
{}



//It takes a pointer and converts it to the unsigned integer type uintptr_t
uintptr_t Serialize::serialize(Data* ptr)
{
	std::cout << ptr << "\n";
}