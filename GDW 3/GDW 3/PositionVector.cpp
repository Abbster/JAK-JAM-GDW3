#include "PositionVector.h"

PositionVector::PositionVector()
{
}

PositionVector::PositionVector(int X, int Y)
{
	this->x = X;
	this->y = Y;

}

int& PositionVector::X()
{
	return this->x;
}

int& PositionVector::Y()
{
	return this->y;

}


