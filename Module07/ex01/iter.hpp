#pragma once

#include <iostream>
#include <array>
#include <vector>

// constant reference function
template<typename T>
void printConst( const T &element )
{
	std::cout << element << ", ";
}

// reference only function
template<typename T>
void increment( T &element )
{
	std::cout << ++element << ", ";
}

template<typename T, typename Func>
void iter( T *arr, size_t const &length, Func func)
{
	for (size_t i = 0; i < length; i++)
		func(arr[i]);
	std::cout << "\n";
}