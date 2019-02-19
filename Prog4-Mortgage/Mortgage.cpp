#include <iostream>
#include "Mortgage.h"

using namespace std;

// constructor initializing all values to 0
Mortgage::Mortgage()
{
	loan = 0;
	rate = 0;
	years = 0;
	term = 0;
	payment = 0;
	totalPaid = 0;
}

// set the mortgage loan amt, interest rate, and num of years
Mortgage::Mortgage(float l, float iR, int yr)
{
	loan = l;
	rate = iR;
	years = yr;
}

// function returing the length of the term of the loan
float Mortgage::getTermLength()
{
	term = pow((1 + (rate / 12)), (12 * years));
	return term;
}

// function returning the monthly payment amount
float Mortgage::getMonthlyPymt()
{
	payment = (loan * (rate / 12) * term) / (term - 1);
	return payment;
}

// function returning the total amount paid to 
// the bank at the end of the loan period
float Mortgage::getTotalAmtPaid()
{
	totalPaid = payment * years * 12;
	return totalPaid;
}
