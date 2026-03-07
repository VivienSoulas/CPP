#pragma once

#include <iostream>
#include <vector>
#include <array>
#include <exception>
#include <algorithm>

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
	auto it = std::find(data.begin(), data.end(), x);
	if (it != data.end())
		return (std::distance(data.begin(), it));
	throw NotFoundException();
	return (-1);
}