#include "Rectangle.h"

Rectangle::Rectangle()
{
	length = 0.0;
	width = 0.0;
}

Rectangle::Rectangle(double l, double w)
{
	length = l;
	width = w;
}

void Rectangle::setLength(double l)
{
	length = l;
}

void Rectangle::setWidth(double w)
{
	width = w;
}

double Rectangle::getLength()
{
	return length;
}

double Rectangle::getWidth()
{
	return width;
}

double Rectangle::calculateArea()
{
	return length * width;
}

double Rectangle::calculatePerimeter()
{
	return 2* (length + width);
}
