#pragma once
#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
	const Fixed x;
	const Fixed y;

	public:
	Point();
	Point( const Point &other );
// ask about this
	// Point &operator=( const Point &other );
	~Point();

	Point( const float x, const float y );

	int getX( void ) const;
	int getY( void ) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif