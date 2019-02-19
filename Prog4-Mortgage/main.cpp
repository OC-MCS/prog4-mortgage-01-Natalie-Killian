//=====================================================
// Natalie Killian
// February 20th, 2019
// Programming Assignment #4
// Description: Mortgage
// Bugs: No known bugs
//=====================================================


#include <iostream>
#include <iomanip>
#include "Mortgage.h"
#include <string>

using namespace std;

// Function prototypes
bool parseFloat(string sval, float& val);
bool parseInt(string sval, int& val);

int main()
{
	string strLoan; 
	float lnAmt = -1;
	string strRate;
	float inRate = -1;
	string strYrs; 
	int numOfYears = -1;

	// Get loan amount as string to validate input
	while (lnAmt < 0)
	{
		cout << "\nPlease enter the amount of the loan.\n";
		cout << "*Positive numbers only*\n";
		getline(cin, strLoan);
		if (!parseFloat(strLoan, lnAmt))
		{
			cout << "***Invalid input! Please enter a positive number***\n";
		}
	}
	// Get interest rate as string to validate input
	while (inRate < 0)
	{
		cout << "\nPlease enter the ANNUAL interest rate as a decimal.\n";
		cout << "(For example, enter a 5% rate as 0.05)\n";
		cout << "*Positive numbers only*\n";
		getline(cin, strRate);
		if (!parseFloat(strRate, inRate))
		{
			cout << "***Invalid input! Please enter a positive number***\n";
		}
	}
	// Get number of years on the loan as string to validate input
	while (numOfYears < 0)
	{
		cout << "\nPlease enter the number of years on the loan.\n";
		cout << "*Positive numbers only*\n";
		getline(cin, strYrs);
		if (!parseInt(strYrs, numOfYears))
		{
			cout << "***Invalid input! Please enter a positive number***\n";
		}
	}
	
	// Define an instance of the Mortgage class
	Mortgage mortgage(lnAmt, inRate, numOfYears);
	mortgage.getTermLength();

	cout << fixed << showpoint << setprecision(2);
	cout << "\nMonthly Payment: $ " << mortgage.getMonthlyPymt() << endl;
	cout << "Total Amount Paid to bank: $ " << mortgage.getTotalAmtPaid() << endl;

	return 0;
}

// Input validation for int variables
bool parseInt(string sval, int& val)
{
	int num;
	bool success = true;
	try
	{
		num = stoi(sval);
		val = num;
	}
	catch (const std::exception&)
	{
		success = false;
	}
	return success;
}

// Input validation for float variables
bool parseFloat(string sval, float& val)
{
	float num;
	bool success = true;
	try
	{
		num = stof(sval); 
		val = num;
	}
	catch (const std::exception&)
	{
		success = false;
	}
	return success;
}
