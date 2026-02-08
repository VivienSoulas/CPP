#pragma once

#include <iostream>

template <typename T>
void swap( T &A, T &B )
{
	T temp = B;
	B = A;
	A = temp;
}

template <typename T>
T const &min( T const &A, T const &B )
{
	return ((A < B) ? A : B);
}

template <typename T>
T const &max( T const &A, T const &B )
{
	return ((A > B) ? A : B);
}