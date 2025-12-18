#include "Point.h"
#include <cmath>

Point::Point()
{
	x1 = 0;
	y1 = 0;
}

Point::Point(int x, int y)
{
	x1 = x;
	y1 = y;
}

void Point::setX1(int x)
{
	x1 = x;
}

void Point::setY1(int y)
{
	y1 = y;
}

int Point::getX1()
{
	return x1;
}

int Point::getY1()
{
	return y1;
}

double Point::calculateDistanceFromOrigin()
{
	return sqrt(pow(x1, 2) + pow(y1, 2));
}