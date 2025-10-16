#include "Point.hpp"

/*=======================================================================================*/

Tree::Tree()
{
	hit = MISS;
	x = 0;
	y = 0;
	right = NULL;
	left = NULL;
	parent = NULL;
}

Tree::~Tree()
{
	delete (this->right);
	delete (this->left);
	this->left = NULL;
	this->right = NULL;
}

Tree::Tree( const Tree &other )
{
	hit = other.hit;
	x = other.x;
	y = other.y;
	right = other.right;
	left = other.left;
	parent = other.parent;
}

Tree &Tree::operator=( const Tree &other )
{
	if (this != &other)
	{
		x = other.x;
		y = other.y;
		right = other.right;
		left = other.left;
		parent = other.parent;
	}
	return (*this);
}

/*=====================================================================================*/


Tree::Tree( Point const point, const Tree *parent )
{
	hit = 0;
	x = point.getX();
	y = point.getY();
	right = NULL;
	left = NULL;
	parent = parent;
}

void Tree::buildBSPtriangle( Point const a, Point const b, Point const c )
{
	this->left = new Tree(a, this);
	this->right = new Tree(b, this);
	this->left->right = new Tree(c, this->left);
	this->right->left = new Tree(c, this->right);
}

bool Tree::checkPoint( Point const a, Point const b, Point const c, Point const point )
{
	
}

/*=====================================================================================*/

bool bsp( Point const a, Point const b, Point const c, Point const point )
{
	Tree *root;

	root = new Tree();
	root->buildBSPtriangle(a, b, c);

	if (root->checkPoint(a, b, c, point))
	{
		delete(root);
		return (true);
	}
	else
	{
		delete(root);
		return (false);
	}
}