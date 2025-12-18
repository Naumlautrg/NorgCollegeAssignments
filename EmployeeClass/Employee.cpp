#include "Employee.h"

Employee::Employee()
{
	employeeId = 0;
}

Employee::Employee(int pEmployeeId)
{
	employeeId = pEmployeeId;
}

int Employee::getEmployeeId()
{
	return employeeId;
}

FullTime::FullTime()
{
	employeeId = 0;
	bonus = 0.0;
	salary = 0.0;
}

FullTime::FullTime(int pEmployeeId, double pBonus, double pSalary)
{
	employeeId = pEmployeeId;
	bonus = pBonus;
	salary = pSalary;
}

double FullTime::calculatePay()
{
	return bonus + salary;
}

void FullTime::print()
{
	std::cout << "Full-Time Employee ID: " << getEmployeeId() << "\n"
		<< "Annual pay is: $" << calculatePay() << "\n\n";
}

PartTime::PartTime()
{
	employeeId = 0;
	hours = 0;
	rate = 0.0;
}

PartTime::PartTime(int pEmployeeId, double pHours, double pRate)
{
	employeeId = pEmployeeId;
	hours = pHours;
	rate = pRate;
}

double PartTime::calculatePay()
{
	return hours * rate;
}

void PartTime::print()
{
	std::cout << "Part-Time Employee ID: " << getEmployeeId() << "\n"
		<< "Weekly pay is: $" << calculatePay() << "\n\n";
}