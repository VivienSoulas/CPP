#pragma once

#include <iostream>
#include <exception>

template<typename T>
class Array
{
	public:
	Array();
	Array( unsigned int n );
	Array( const Array &other );
	Array &operator=( const Array &other );
	T &operator[]( unsigned int index );
	~Array();
	
	unsigned int size() const;

	private:
	T *data;
	unsigned int data_size;

	protected:
	class OutOfBound : public std::exception
	{
		public:
		virtual const char* what() const noexcept override;
	};
};

#include "Array.tpp"