#ifndef CHECKING_H
#define CHECKING_H
#include "Account.h"

class Checking : public Account
{				
private:
	int monthlyFee;

public:
	// Default constructor
	Checking()
	{
		interestRate = 0.00;
		balance = 0.00;
		monthlyFee = 0;
	}

	// Constructor
	Checking(double bal, int fee, double intRate)
	{
		balance = bal;
		monthlyFee = fee;
		interestRate = intRate;
	}

	// Mutator functions
	void setCheckWithdrawal();

	// Virtual functions
	virtual double getDividend();
};

#endif
