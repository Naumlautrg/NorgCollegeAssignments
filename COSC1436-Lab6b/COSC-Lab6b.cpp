/*
*
*
*	Calculates the monthly payment for a loan based on the borrowed amount, the interest rate and number of years of loan.
*	Afterwards, prints an amortization schedule.
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double calculateLoan(double principal, double interestRate, int years);
double calculateIPMT(double principal, double monthlyInterestRate); // Interest Payment
double calculatePPMT(double monthlyPayment, double interestPayment); // Principal Payment

int main()
{
	cout << fixed << setprecision(2);

	double principal = 0.0, interestRate = 0.0;
	int years = 0;

	cout << "Input the loan amount: $";
	cin >> principal;
	cout << "Input the interest rate (as decimal): ";
	cin >> interestRate;
	cout << "Input the number of years: ";
	cin >> years;

	cout << "\n";

	double monthlyPayment = calculateLoan(principal, interestRate, years);

	cout << "Original amount of loan: " << principal << "\n"
		<< "Monthly payment: " << monthlyPayment << "\n"
		<< "Amount paid over the term of the loan: " << monthlyPayment * (years * 12);

	// Amortization Schedule
	cout << "\n\nAmortization Schedule\n\n";
	cout << "PMT # Interest Principal   Total      YTD     Ending    \n";
	cout << "        Paid     Payment   Payment    Paid    Balance";
	cout << "\n=====================================================\n\n";

	double totalInterestPaid = 0.0;
	double totalPrinciplePaid = 0.0;
	double totalAllPaid = 0.0;
	double ytdPaid = 0.0;
	double endingBalance = principal;
	for (int i = 1; i <= years * 12; ++i)
	{
		double interestPaid = calculateIPMT(endingBalance, interestRate / 12);
		double principalPayment = calculatePPMT(monthlyPayment, interestPaid);
		double totalPayment = interestPaid + principalPayment;
		ytdPaid += totalPayment;
		endingBalance -= principalPayment;
		totalInterestPaid += interestPaid;
		totalPrinciplePaid += principalPayment;
		totalAllPaid += totalPayment;
		cout << setw(3) << i;
		cout << setw(10) << interestPaid;
		cout << setw(10) << principalPayment;
		cout << setw(10) << totalPayment;
		cout << setw(10) << ytdPaid;
		cout << setw(10) << ((abs(endingBalance) < 0.0099) ? 0.00 : endingBalance);
		cout << "\n";
	}
	cout << "\n--------------------------------------------------------\n";
	cout << setw(13) << totalInterestPaid << setw(10) << totalPrinciplePaid << setw(31) << totalAllPaid;

	return 0;
}

double calculateLoan(double principal, double interestRate, int years)
{
	double actualInterestRate = interestRate / 12;
	double payment = (principal * actualInterestRate)
		/ (1 - (pow(1 + actualInterestRate, -(years * 12))));
	return payment;
}

double calculateIPMT(double principal, double monthlyInterestRate)
{
	return principal * monthlyInterestRate;
}

double calculatePPMT(double monthlyPayment, double interestPayment)
{
	return monthlyPayment - interestPayment;
}