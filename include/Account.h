#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "Person.h"

class Account : public Person
{
protected:
	double 
		deposit,									// Deposit money
		withdrawal,									// Withdraw money
		checkWithdrawal,							// Withdraw for check
		dividend,									// Displays total interest earned
		interestRate;								// Interest rate
	int numChecks = 0,								// Number of checks written
		numBounced = 0,								// Number of bounced checks
		numTransfers = 0;							// Number of tranfers between accounts
public:
	double balance;

	// Default constructor (set everything to 0)
	Account()
	{
		deposit = 0.00;
		withdrawal = 0.00;
		checkWithdrawal = 0.00;
	}

	// Mutator functions
	void depositMoney();
	void withdrawMoney();
	void transfer(Account &);
	void chargeFee(int);

	// Accessor functions
	void printBalance();
	int getNumChecks();
	int getBounced();
	int getNumTransfers();
	 
	// Virtual function
	virtual double getDividend();
};

#endif
