#pragma once

#include <iostream>
#include "Data.hpp"
#include <cstdint>

class Serializer
{
	private:

	public:
	Serializer();
	Serializer( const Serializer &other ) = delete;
	Serializer &operator=( const Serializer &other ) = delete;
	virtual ~Serializer();

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};