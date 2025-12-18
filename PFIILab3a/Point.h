#pragma once
class Point
{
public:
	void setX1(int x);
	void setY1(int y);

	int getX1();
	int getY1();

	Point();
	Point(int x, int y);

	double calculateDistanceFromOrigin();

private:
	int x1;
	int y1;
};

