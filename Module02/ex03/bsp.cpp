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


Tree::Tree( Point const point, const Tree *par )
{
	hit = 0;
	x = point.getX();
	y = point.getY();
	right = NULL;
	left = NULL;
	parent = par;
}

void Tree::buildBSPtriangle( Point const a, Point const b, Point const c )
{
	this->left = new Tree(a, this);
	this->right = new Tree(b, this);
	this->left->right = new Tree(c, this->left);
	this->right->left = new Tree(c, this->right);
}

bool Tree::checkPoint( Point const a, Point const b, Point const point )
{
	int Y = (a.getY() - b.getY());
	int X = (a.getY() - b.getY());
	int diff = ((a.getX() * b.getX()) - (a.getY() * b.getY()));
	int res = Y * point.getX() + X * point.getY() + diff;
// inside
	if (res < 0)
		std::cout << "here\n";
		//this->left->checkPoint();
// outside
	else
		std::cout << "not here\n";
		//this->right;
	return (true);
}

/*=====================================================================================*/

bool bsp( Point const a, Point const b, Point const c, Point const point )
{
	Tree *root;

	root = new Tree();
	root->buildBSPtriangle(a, b, c);

	if (root->checkPoint(a, b, point))
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