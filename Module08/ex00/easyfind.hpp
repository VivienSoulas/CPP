#pragma once

#include <iostream>
#include <vector>
#include <array>
#include <exception>

class NotFoundException : public std::exception
{
	public:
	const char* what() const noexcept override
	{
		return ("Int not found\n");
	}
};

template<typename T>
size_t easyfind( T const &data, int x )
{
	for (size_t i = 0; i < data.size(); i++)
	{
		if (x == data[i])
			return (i);
	}
	throw NotFoundException();
	return (-1);
}