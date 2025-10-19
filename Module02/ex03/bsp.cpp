#include "Tree.hpp"

bool Tree::isLeaf() const
{
	return (this->left == NULL && this->right == NULL);
}

void Tree::buildBSPtriangle( Point const &a, Point const &b, Point const &c )
{
	Tree *A = new Tree(a, this);
	Tree *B = new Tree(b, this);

	this->left = A;
	this->right = B;
	A->right = new Tree(c, A);
	B->left = new Tree(c, B);
}

int Tree::crossCheck( Point const &a, Point const &b, Point const &point )
{
	int cross = (b.getX() - a.getX()) * (point.getY() - a.getY())
				- (b.getY() - a.getY()) * (point.getX() - a.getX());
	return (cross);
}

bool Tree::checkPoint( Tree *node, Point const &point )
{
	Point *A;
	Point *B;

	if (node == NULL)
		return (false);
	if (node->isLeaf())
		return (true);

	if (node->left)
		A = &node->left->cur_point;
	else
		A = &node->cur_point;
	if (node->right)
		B = &node->right->cur_point;
	else
		B = &node->cur_point;

	int c = crossCheck(*A, *B, point);
	if (c > 0) // inside triangle, carry on to the left of the tree
	{
		if (node->left)
			return (checkPoint(node->left, point));
		return (false);
	}
	else if (c < 0) // outside of the triangle, carry on on the right of the tree
	{
		if (node->right)
			return (checkPoint(node->right, point));
		return (false);
	}
	else // on the edge of the trangle
		return (false);
}


bool bsp( Point const a, Point const b, Point const c, Point const point )
{
	Tree *root;

	root = new Tree();
	root->buildBSPtriangle(a, b, c);
	if (root->checkPoint(root, point))
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