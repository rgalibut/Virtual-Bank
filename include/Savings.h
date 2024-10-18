#ifndef SAVINGS_H
#define SAVINGS_H
#include "Account.h"

class Savings : public Account
{
public:
	// Default constructor
	Savings()
	{
		interestRate = 0.00;
		balance = 0.00;
	}

	// Constructor
	Savings(double bal, double intRate)
	{
		balance = bal;
		interestRate = intRate;
	}

	// Accessor functions
	bool validateBalance();

	// Virtual functions
	virtual double getDividend();
};

#endif
