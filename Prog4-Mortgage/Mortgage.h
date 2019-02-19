#pragma once
// header file for Mortgage class

class Mortgage
{
private:
	float loan;
	float rate; // yearly rate
	int years;
	float term;
	float payment;
	float totalPaid;
public:
	Mortgage();
	Mortgage(float loan, float rate, int years);
	float getTermLength();
	float getMonthlyPymt();
	float getTotalAmtPaid();
};