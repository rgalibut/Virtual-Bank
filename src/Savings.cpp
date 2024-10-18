#include "Savings.h"
#include "Checking.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


// Accessor functions
bool Savings::validateBalance()
{
	// Return false if balance is below $25
	if (this->balance < 25)
		return 0;
	// Return true if balance is about $25
	else
		return 1;
}

// Virtual functions
double Savings::getDividend()
{
	this->dividend = this->balance * 0.0375;
	return dividend;
}
