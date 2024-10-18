#include "Checking.h"
#include "Savings.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

// Mutator functions
void Checking::setCheckWithdrawal()
{
	double amount;

	cout << "Enter the check amount: $";
	cin >> amount;
	cin.ignore();

	// Validates for 0 or negative numbers
	while (amount < 1)
	{
		cout << "Please enter an amount greater than 0: ";
		cin >> amount;
		cin.ignore();
	}

	// Subtract amount from balance
	if (amount > 0)
		this->balance -= amount;

	// Validates if there is enough money in the account
	if (balance < 0)
	{
		cout << "**INVALID. Not enough money in acount. Account will be charged $15 for bounced check.\n";
		this->numBounced++;;
		this->balance -= 15.00;
	}
	// Each check costs $0.10 each
	if (numChecks >= 1 && balance > 0)
	{
		this->numChecks++;
		this->balance -= 0.10;
		cout << "There is a $0.10 charge for all written checks.\n\n";
	}
	// First check is free
	else if (numChecks == 0 && balance > 0)
	{
		this->numChecks++;
		cout << "Your first check is free of charge!\n\n";
	}
}

// Virtual functions
double Checking::getDividend()
{
	this->dividend = this->balance * 0.025;
	return dividend;
}
