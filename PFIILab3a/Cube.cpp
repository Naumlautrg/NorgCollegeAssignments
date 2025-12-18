#include "Cube.h"
#include <cmath>

Cube::Cube()
{
	edgeLength = 0.0;
}

Cube::Cube(double eL)
{
	edgeLength = eL;
}

void Cube::setEdgeLength(double eL)
{
	edgeLength = eL;
}

double Cube::getEdgeLength()
{
	return edgeLength;
}

double Cube::calculateSurfaceArea()
{
	return 6 * pow(edgeLength, 2);
}

double Cube::calculateVolume()
{
	return pow(edgeLength, 3);
}