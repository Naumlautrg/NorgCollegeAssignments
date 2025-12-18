#include <iostream>
#include <iomanip>

#include "Cube.h"
#include "Point.h"
#include "Rectangle.h"

int main()
{
	std::cout << std::fixed << std::setprecision(2);

	// Create class objects
	Cube cubeA(3.145);
	Cube cubeB(2.34);

	Point pointA(3, 1);
	Point pointB(8, 4);

	Rectangle rectangleA;
	Rectangle rectangleB(3, 4.6);

	// Set rectangleA member variables using setter functions 
	rectangleA.setLength(1);
	rectangleA.setWidth(2.6);

	// Display values of all objects
	std::cout << "CubeA edge length = " << cubeA.getEdgeLength() << "\n";
	std::cout << "CubeB edge length = " << cubeB.getEdgeLength() << "\n\n";

	std::cout << "PointA = (" << pointA.getX1() << ", " << pointA.getY1() << ")" << "\n";
	std::cout << "PointB = (" << pointB.getX1() << ", " << pointB.getY1() << ")" << "\n\n";

	std::cout << "RectangleA: Length = " << rectangleA.getLength() << "  Width = " << rectangleA.getWidth() << "\n";
	std::cout << "RectangleB: Length = " << rectangleB.getLength() << "  Width = " << rectangleB.getWidth() << "\n\n";

	// Calculate with object values and display results
	std::cout << "CubeA: Surface area = " << cubeA.calculateSurfaceArea() << "  Volume = " << cubeA.calculateVolume() << "\n";
	std::cout << "CubeB: Surface area = " << cubeB.calculateSurfaceArea() << "  Volume = " << cubeB.calculateVolume() << "\n\n";

	std::cout << "PointA distance from origin = " << pointA.calculateDistanceFromOrigin() << "\n";
	std::cout << "PointB distance from origin = " << pointB.calculateDistanceFromOrigin() << "\n\n";

	std::cout << "RectangleA: Area = " << rectangleA.calculateArea() << "  Perimeter = " << rectangleA.calculatePerimeter() << "\n";
	std::cout << "RectangleB: Area = " << rectangleB.calculateArea() << "  Perimeter = " << rectangleB.calculatePerimeter() << "\n\n";


	return 0;
}