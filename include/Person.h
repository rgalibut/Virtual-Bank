#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;

class Person
{
private:
	string name;						// To hold name
	string title;						// To hold title
	string ssn;							// To hold 9-digit SSN
	string accountID;					// To hold account ID

public:
	// Default constructor
	Person()
	{
		name = "";
		title = "";
		ssn = "";
		accountID = "";
	}

	// Constructor #1
	Person(string n, string t, string s, string a)
	{
		name = n;
		title = t;
		ssn = s;
		accountID = a;
	}

	// Mutator functions
	void setName(string n);
	void capitalize(string &n);
	void setTitle(string t);
	void setSSN(string s);
	void setAccountID(string a);

	// Accessor functions
	string getName() const;
	string getTitle() const;
	string getSSN() const;
	string validateSSN(string);
	string getAccountID() const;
};

#endif
