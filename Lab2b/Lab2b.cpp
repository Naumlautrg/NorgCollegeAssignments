// Michael Wright
// A00614564
//
// Calculates the monthly payment for a loan based on the borrowed amount, the interest rate and number of years of loan.

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double calculateLoan(double principal, double interestRate, int years)
{
	double actualInterestRate = interestRate / 12;
	double payment = principal * actualInterestRate
		/ (1 - (pow(1 + actualInterestRate, -(years * 12))));
	return payment;
}

int main()
{
	cout << fixed << setprecision(2);

	double principal, interestRate;
	int years;

	cout << "Input the principal, interest rate, and number of years of loan. ";
	cin >> principal >> interestRate >> years;

	cout << "\n";

	double monthlyPayment = calculateLoan(principal, interestRate, years);

	cout << "Original amount of loan: " << principal << "\n"
		<< "Monthly payment: " << monthlyPayment << "\n"
		<< "Amount paid over the term of the loan: " << monthlyPayment * (years * 12);

	return 0;
}