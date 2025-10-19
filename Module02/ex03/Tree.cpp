#include "Tree.hpp"

/*=======================================================================================*/

Tree::Tree()
	: x(0),
	y(0),
	is_leaf(false),
	left(NULL),
	right(NULL),
	cur_point(),
	parent(NULL)
{
}

Tree::~Tree()
{
	delete (this->right);
	delete (this->left);
	this->left = NULL;
	this->right = NULL;
}

Tree::Tree( const Tree &other )
	: x(other.x),
	y(other.y),
	is_leaf(other.is_leaf),
	left(other.left),
	right(other.right),
	cur_point(other.cur_point),
	parent(other.parent)
{
}

// can't call cur_point = other.cur_point because it is a object and not a pointer
Tree &Tree::operator=( const Tree &other )
{
	if (this != &other)
	{
		x = other.x;
		y = other.y;
		is_leaf = other.is_leaf;
		right = other.right;
		left = other.left;
		parent = other.parent;
	}
	return (*this);
}

/*=====================================================================================*/

Tree::Tree( Point const &point, const Tree *parent )
	: x(point.getX()),
	y(point.getY()),
	is_leaf(false),
	left(NULL),
	right(NULL),
	cur_point(point),
	parent(parent)
{
}
