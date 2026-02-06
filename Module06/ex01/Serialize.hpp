#pragma once

#include "Serializer.hpp"

class Serialize : public Serializer
{
	private:

	public:
	Serialize();
	Serialize( const Serialize &other ) = delete;
	Serialize &operator=(const Serialize &other ) = delete;
	~Serialize();

	uintptr_t serialize(Data* ptr);
};