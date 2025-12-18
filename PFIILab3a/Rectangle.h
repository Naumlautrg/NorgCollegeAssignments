#pragma once
class Rectangle
{
public:
	void setLength(double length);
	void setWidth(double width);

	double getLength();
	double getWidth();

	Rectangle();
	Rectangle(double length, double width);

	double calculateArea();
	double calculatePerimeter();

private:
	double length;
	double width;
};

