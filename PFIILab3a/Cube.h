#pragma once
class Cube
{
public:
	void setEdgeLength(double edgeLength);
	
	double getEdgeLength();

	Cube();
	Cube(double edgeLength);

	double calculateSurfaceArea();
	double calculateVolume();

private:
	double edgeLength;
};

