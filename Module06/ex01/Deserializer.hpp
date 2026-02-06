#pragma once

#include <iostream>
#include "Data.hpp"
#include <cstdint>

class Deserializer
{
	private:

	public:
	Deserializer();
	Deserializer( const Deserializer &other ) = delete;
	Deserializer &operator=( const Deserializer &other ) = delete;
	virtual ~Deserializer();

	static Data* deserialize(uintptr_t raw);
};