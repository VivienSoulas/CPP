#pragma once
#ifndef POINT_HPP
#define POINT_HPP

#define MISS 0
#define HIT 1

#include "Fixed.hpp"

class Tree
{
	public:
	Tree();
	Tree( const Tree &other );
	Tree &operator=( const Tree &other );
	~Tree();

	Tree( Point const point, const Tree *parent );
	void buildBSPtriangle( Point const a, Point const b, Point const c );
	bool checkPoint( Point const a, Point const b, Point const c, Point const point );

	int hit;
	int x;
	int y;
	Tree *left;
	Tree *right;
	Tree *parent;
};

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

bool bsp( Point const a, Point const b, Point const c, Point const point );

#endif