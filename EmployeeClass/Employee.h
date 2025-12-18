#pragma once

#include <iostream>

class Employee
{
public:
	Employee();
	Employee(int pEmployeeId);
	virtual double calculatePay() = 0;
	int getEmployeeId();
	virtual void print() = 0;
protected:
	int employeeId;
};

class FullTime : public Employee
{
public:
	FullTime();
	FullTime(int pEmployeeId, double pBonus, double pSalary);
	double calculatePay();
	void print();
private:
	double bonus;
	double salary;
};

class PartTime : public Employee
{
public:
	PartTime();
	PartTime(int pEmployeeId, double pHours, double pRate);
	double calculatePay();
	void print();
private:
	int hours;
	double rate;
};