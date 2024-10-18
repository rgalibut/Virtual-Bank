#include "Account.h"
#include "Checking.h"
#include "Savings.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;

// Mutator functions
void Account::depositMoney()						// Deposit money into either account
{
	double amount;

	cout << "Enter the amount to deposit: $";
	cin >> amount;
	cin.ignore();
	this->balance += amount;
}

void Account::withdrawMoney()						// Withdraw money from either account
{
	double amount;

	cout << "Enter the amount to withdraw: $";
	cin >> amount;
	cin.ignore();
	this->balance -= amount;
}

void Account::transfer(Account & destination)		// Trasfer money from either account
{
	double amount;

	cout << "Enter the amount to transfer: $";
	cin >> amount;
	cin.ignore();
	this->balance -= amount;
	destination.balance += amount;
	this->numTransfers++;
}

// Mutator functions
void Account::chargeFee(int num)
{
	this->balance -= num;
}

// Accessor functions
void Account::printBalance()
{
	cout << setprecision(2) << fixed << this->balance;

}

int Account::getNumChecks()
{ return this->numChecks; }

int Account::getBounced()
{ return this->numBounced; }

int Account::getNumTransfers()
{
	return numTransfers;
}

// Virtual function
double Account::getDividend()
{
	this->dividend = this->balance * this->interestRate;
	return dividend;
}
