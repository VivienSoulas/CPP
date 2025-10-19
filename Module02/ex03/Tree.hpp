#pragma once
#ifndef TREE_HPP
#define TREE_HPP

#define LEFT 0
#define RIGHT 1

#include "Point.hpp"

class Tree
{
	public:
	Tree();
	Tree( const Tree &other );
	Tree &operator=( const Tree &other );
	~Tree();

	Tree( Point const &point, const Tree *parent );

	void buildBSPtriangle( Point const &a, Point const &b, Point const &c );
	bool isLeaf() const;
	bool checkPoint( Tree *node, Point const &point );
	int crossCheck( Point const &a, Point const &b, Point const &point );

	int x;
	int y;
	bool is_leaf;
	Tree *left;
	Tree *right;
	Point cur_point;
	const Tree *parent;
};

#endif