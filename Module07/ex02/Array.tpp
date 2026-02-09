#include "Array.hpp"

template<typename T>
Array<T>::Array()
	: data(nullptr), data_size(0)
{}

template<typename T>
Array<T>::Array( unsigned int n )
	: data(new T[n]{}), data_size(n)
{}

template<typename T>
Array<T>::Array( const Array &other )
	: data(new T[other.data_size]{}), data_size(other.data_size)
{
	for (size_t i = 0; i < data_size; i++)
		data[i] = other.data[i];
}

template<typename T>
Array<T> &Array<T>::operator=( const Array &other )
{
	if (this != &other)
	{
		if (data)
			delete[] data;
		data = new T[other.data_size];
		data_size = other.data_size;
		for (size_t i = 0; i < data_size; i++)
			data[i] = other.data[i];
	}
	return (*this);
}

template<typename T>
T &Array<T>::operator[]( unsigned int index )
{
	if (index >= data_size)
		throw OutOfBound();
	return (data[index]);
}

template<typename T>
Array<T>::~Array()
{
	if (data)
		delete[] data;
}



template<typename T>
unsigned int Array<T>::size() const
{
	return (data_size);
}

template<typename T>
const char* Array<T>::OutOfBound::what() const noexcept
{
	return ("Out of Bound");
}