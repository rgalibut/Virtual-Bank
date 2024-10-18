#include "Person.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

// Mutator functions
void Person::setName(string n)
{
	name = n;

}

void Person::capitalize(string &n)
{
	bool cap = true;

	for (unsigned int i = 0; i <= n.length(); i++)
	{
		if (isalpha(n[i]) && cap == true)
		{
			n[i] = toupper(n[i]);
			cap = false;
		}
		else if (isspace(n[i]))
		{
			cap = true;
		}
	}

	name = n;
}

void Person::setTitle(string t)
{
	if (t == "Mr." || t == "mr." || t == "mr" || t == "MR" || t == "MR.")
		title = "Mr.";
	if (t == "Mrs." || t == "mrs." || t == "mrs" || t == "MRS" || t == "MRS.")
		title = "Mrs.";
	if (t == "Ms." || t == "ms." || t == "ms" || t == "MS" || t == "MS.")
		title = "Ms.";
	if (t == "Dr." || t == "dr." || t == "dr" || t == "DR" || t == "DR.")
		title = "Dr.";
}

void Person::setSSN(string s)
{
	ssn = s;
}

void Person::setAccountID(string a)
{
	accountID = a;
}

// Accessor functions
string Person::getName() const
{ return name; }

string Person::getTitle() const
{ return title; }

string Person::getSSN() const
{ return ssn; }

string Person::validateSSN(string soc)
{
	bool check = false;

	while (!check)
	{
		check = false;

		cout << "Please enter your SSN (ex: 123-45-6789): ";
		cin >> soc;
		cin.ignore();

		if (soc.length() == 11)
		{
			if (soc[3] == '-' && soc[6] == '-')
			{
				soc = soc.replace(3, 1, "");
				soc = soc.replace(5, 1, "");

				for (int i = 0; i < 9; i++)
				{
					if (isdigit(soc[i]))
					{
						check = true;
					}
				}
			}
		}
		else
			check == false;

		if (check == false)
		{
			cout << "INVALID. Please enter your SSN in format 123-45-6789.\n";
		}
	}
	return soc;
}

string Person::getAccountID() const
{ return accountID; }
