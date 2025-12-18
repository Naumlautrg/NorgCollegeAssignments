#include <iostream>
#include <iomanip>

#include "Employee.h"

int main()
{
	std::cout << std::fixed << std::setprecision(2);

	PartTime* aPartTimeEmployee = new PartTime(8731, 16.0, 15.0);
	FullTime* aFullTimeEmployee = new FullTime(1571, 1000.0, 56000.0);

	aPartTimeEmployee->print();
	aFullTimeEmployee->print();

	return 0;
}