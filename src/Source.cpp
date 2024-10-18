/* 
Virtual Bank

Design and implement a hierarchy inheritance system of banking, which 
includes Savings and Checking Accounts of a customer. Inheritance and
virtual funtions must be used and applied, otherwise there is no credit.

The following features must be incorporated:
	1. The account must have an ID and customer's full name and his/her
	social security number.
	2. General types of banking transactions for both accounts, Checking
	and Savings: 
		- withdraw
		- deposit
		- calculate interest (based on the current balance, and if it was
		not modified, there will be no new interest)
		- figure out the balance
		- transfer funds (between the two accounts, from Checking to 
		Savings and vice versa).
	3. Savings restrictions:
		- Become inactive if balance falls below $25 and, under such 
		situation, no more withdrawals may be allowed.
		- A $1 charge for each transfer fund (to Checking account), with
		the first transfer being free.
		- The monthly interest rate is 3.75%.
	4. Checking restrictions:
		- A monthly service charge is $5 (automatically charged when
		Checking account was opened).
		- A $0.10 charge for each written check, with the first check free.
		- A $15 charge for each bounced check (not enough funds).
		- The monthly interest rate is 2.5%.
*/


#include "Person.h"
#include "Checking.h"
#include "Savings.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function prototype
void displayDividend(Account &);

int main()
{
	// Variables
	string name, title, ssn, accountID;
	int firstChoice, transferChoice;							// Menu choices
	int transfers;												// # of transfers between accounts
	char secondChoice;											// Sub menu choice
	char yesorno;												// Yes or no
	bool torf;													// True or false

	// Create Person object with constructor #1 (default)
	Person user;
	user.setName(name);
	user.setTitle(title);
	user.setSSN(ssn);
	user.setAccountID(accountID);

	// Formatting
	cout << setw(20) << "=============================\n";
	cout << setw(30) << "Welcome to your Virtual Bank\n";
	cout << setw(20) << "=============================\n";
	cout << "\n* Registration is required! *\n\n";
	cout << left << "Please enter your full name: ";
	getline(cin, name);
	user.capitalize(name);
	// Get & validate title
	cout << "Please enter your title (Mr., Mrs., Ms., Dr.): ";
	getline(cin, title);
	user.setTitle(title);
	// Get & validate SSN
	ssn = user.validateSSN(ssn);
	cout << left << "Please enter your account number (ex: 123456789): ";
	getline(cin, accountID);
	
	cout << endl;

	// TO-DO: overload << operator
	cout << "How are you today, ";
	cout <<	user.getTitle();
	cout << " ";
	cout << user.getName();
	cout << "?\n\n";
	cout << "Press <Enter> to continue to banking services ...";
	cin.ignore();
	system("cls");

	Checking checkObj(-5.00, 15, 0.025);							// Checking object
	Savings savObj(25.00, 0.0375);									// Savings object

	// Bank services menu
	mainMenu:
		cout << "Virtual Bank Services Menu\n";
		cout << "--------------------------\n";
		cout << "1) Checking Account\n";
		cout << "2) Savings Account\n";
		cout << "3) End of services\n";
		cout << "Enter your choice from the above menu: ";
		cin >> firstChoice;
	
	switch (firstChoice)
	{
		case 1:
			cout << "\nOpen/manage your Checking account? (y/n): ";
			cin >> yesorno;
			system("cls");

			switch (yesorno)
			{
				case 'y':
				case 'Y':
				checkingMenu:
					// Checking menu
					cout << "Checking\n";
					cout << "========\n";
					cout << "a) ---Deposit---\n";
					cout << "b) ---Withdraw--\n";
					cout << "c) ---Transfer----\n";
					cout << "d) ---Balance---\n";
					cout << "e) Personal Check\n";
					cout << "f) ---Interest---\n";
					cout << "g) ---Statement---\n";
					cout << "h) -----Done-----\n";
					cout << "Please choose an option from above: ";
					cin >> secondChoice;
					cin.ignore();

				switch (secondChoice)
				{				
					case 'a':
					case 'A':
						cout << "\n*** DEPOSIT ***" << endl;
						checkObj.depositMoney();
						cout << "\n\nPress <Enter> to continue...";
						cin.ignore();
						system("cls");
						goto checkingMenu;

					case 'b':
					case 'B':
						cout << "\n*** WITHDRAW ***" << endl;
						checkObj.withdrawMoney();
						cout << "\n\nPress <Enter> to continue...";
						cin.ignore();
						system("cls");
						goto checkingMenu;

					case 'c':
					case 'C':
						cout << "\n*** TRANSFER ***" << endl;
						cout << "1. From Checking to Savings" << endl;
						cout << "2. From Savings to Checking" << endl;
						cout << "\nPlease choose an option from above: ";
						cin >> transferChoice;
						cin.ignore();

						switch (transferChoice)
						{
							case 1:
								checkObj.transfer(savObj);
								cout << "\n\nPress <Enter> to continue...";
								cin.ignore();
								system("cls");
								goto checkingMenu;
								break;
							case 2:
								savObj.transfer(checkObj);
								transfers = savObj.getNumTransfers();
								if (transfers == 1)
									savObj.chargeFee(1);
								else
								{
									checkObj.chargeFee(1);
									cout << "Each transfer from Savings charges a $1.00 transfer fee from Checking.";
								}
								cout << "\n\nPress <Enter> to continue...";
								cin.ignore();
								system("cls");
								goto checkingMenu;
								break;
							default:
								cout << "**INVALID: Please choose an option from above: ";
								cin >> transferChoice;
								system("cls");
								goto checkingMenu;
						}
						system("cls");
						goto checkingMenu;

					case 'd':
					case 'D':
						cout << "\n*** BALANCE ***" << endl;
						cout << "Checking balance: $";
						checkObj.printBalance();										
						cout <<  "\n\nPress <Enter> to continue...";
						cin.ignore();
						system("cls");
						goto checkingMenu;

					case 'e':
					case 'E':
						cout << "\n*** PERSONAL CHECK ***" << endl;
						checkObj.setCheckWithdrawal();
						cout << "\n\nPress <Enter> to continue...";
						cin.ignore();
						system("cls");
						goto checkingMenu;

					case 'f':
					case 'F':
						cout << "\n*** INTEREST ***\n" << endl;
						cout << "Checking dividend: $";
						displayDividend(checkObj);									
						cout << endl;
						cout << "Checking balance: $";
						checkObj.printBalance();
						cout << "\n\nPress <Enter to continue...";
						cin.ignore();
						system("cls");
						goto checkingMenu;
						
					case 'g':
					case 'G':
						cout << "\n*** STATEMENT ***\n\n";
						cout << "Customer name: ";
						cout << user.getTitle() << user.getName();
						cout << "\nSocial Security Number: ";
						cout << user.getSSN();
						cout << "\nCustomer number: ";
						cout << user.getAccountID();
						cout << "\nChecks written: ";
						cout << checkObj.getNumChecks();
						cout << "\nChecks bounced: ";
						cout << checkObj.getBounced();
						cout << "\n\nPress <Enter> to continue...";
						cin.ignore();
						system("cls");
						goto checkingMenu;
					case 'h':
					case 'H':
						system("cls");
						goto mainMenu;
						break;
					default:
						cout << "\n**INVALID. Please choose a different answer.";
						cout << "\n\nPress <Enter> to continue...";
						cin.ignore();
						system("cls");
						goto checkingMenu;
						break;
				}

				case 'n':
				case 'N':
					system("cls");
					goto mainMenu;
			}	
			
		case 2:
			cout << "\nOpen/manage your Savings account? (y/n): ";
			cin >> yesorno;
			system("cls");

			switch (yesorno)
			{
				case 'y':
				case 'Y':
				savingsMenu:
					// Savings menu
					cout << "Savings\n";
					cout << "=======\n";
					cout << "a) ---Deposit---\n";
					cout << "b) ---Withdraw---\n";
					cout << "c) --Transfer---\n";
					cout << "d) ---Balance---\n";
					cout << "e) ---Interest---\n";
					cout << "f) ---Statement---\n";
					cout << "g) -----Done-----\n";
					cout << "Please choose an option from above: ";
					cin >> secondChoice;
					cin.ignore();

				switch (secondChoice)
				{
					case 'a':
					case 'A':
						cout << "\n*** DEPOSIT ***" << endl;
						savObj.depositMoney();
						cout << "\n\nPress <Enter> to continue...";
						cin.ignore();
						system("cls");
						goto savingsMenu;

					case 'b':
					case 'B':
						cout << "\n*** WITHDRAW ***" << endl;
						torf = savObj.validateBalance();
						if (torf == true)
							savObj.withdrawMoney();
						else
						{
							cout << "Account balance has fallen below $25 and has been closed.\n";
							cout << "No more withdrawals may be made from this account.";
						}
						cout << "\n\nPress <Enter> to continue...";
						cin.ignore();
						system("cls");
						goto savingsMenu;

					case 'c':
					case 'C':
						cout << "\n*** TRANSFER ***" << endl;
						cout << "1. From Checking to Savings" << endl;
						cout << "2. From Savings to Checking" << endl;
						cout << "\nPlease choose an option from above: ";
						cin >> transferChoice;
						cin.ignore();

						switch (transferChoice)
						{
						case 1:
							checkObj.transfer(savObj);
							cout << "\n\nPress <Enter> to continue...";
							cin.ignore();
							system("cls");
							goto savingsMenu;
							break;
						case 2:
							savObj.transfer(checkObj);
							transfers = savObj.getNumTransfers();
							if (transfers == 1)
								savObj.chargeFee(1);
							else
							{
								checkObj.chargeFee(1);
								cout << "Each transfer from Savings charges a $1.00 transfer fee from Checking.";
							}
							cout << "\n\nPress <Enter> to continue...";
							cin.ignore();
							system("cls");
							goto savingsMenu;
							break;
						default:
							cout << "**INVALID: Please choose an option from above: ";
							cin >> transferChoice;
							system("cls");
							goto savingsMenu;
						}
						system("cls");
						goto savingsMenu;

					case 'd':
					case 'D':
						cout << "\n*** BALANCE ***" << endl;
						torf = savObj.validateBalance();
						if (torf == true)
						{
							cout << "Savings balance: $";
							savObj.printBalance();
						}
						else
						{
							cout << "Account balance has fallen below $25 and has been closed.\n";
							cout << "No more withdrawals may be made from this account.";
						}
						cout << "\n\nPress <Enter> to continue...";
						cin.ignore();
						system("cls");
						goto savingsMenu;

					case 'e':
					case 'E':
						cout << "\n*** INTEREST ***\n" << endl;
						cout << "Savings dividend: $";
						displayDividend(savObj);									
						cout << endl;
						cout << "Savings balance: $";
						savObj.printBalance();
						cout << "\n\nPress <Enter to continue...";
						cin.ignore();
						system("cls");
						goto savingsMenu;

					case 'f':
					case 'F':
						cout << "\n*** STATEMENT ***\n\n";
						cout << "Customer name: ";
						cout << user.getTitle() << user.getName();
						cout << "\nSocial Security Number: ";
						cout << user.getSSN();
						cout << "\nCustomer number: ";
						cout << user.getAccountID();
						cout << "\nChecks written: "; 
						cout << savObj.getNumChecks();
						cout << "\nChecks bounced: "; 
						cout << savObj.getBounced();	
						cout << "\n\nPress <Enter to continue...";
						cin.ignore();
						system("cls");
						goto savingsMenu;
						break;
					case 'g':
					case 'G':
						system("cls");
						goto mainMenu;
						break;
					default:
						cout << "\n**INVALID. Please choose a different answer.";
						cout << "\n\nPress <Enter> to continue...";
						cin.ignore();
						system("cls");
						goto savingsMenu;
						break;
					}

				case 'n':
				case 'N':
					system("cls");
					goto mainMenu;
			}		

		case 3:
			// End of services menu
			cout << "\nThank you for visiting your Virtual Bank, " << user.getTitle() << " " << user.getName() << ".\n";
			cout << "We hope you are satisfied with our service.\n";
			cout << "Is there anything else you would like assistance with today? (y/n): ";
			cin >> yesorno;
			cin.ignore();

			if (yesorno == 'y' || yesorno == 'Y')
			{
				system("cls");
				goto mainMenu;
			}
			else
			{
				cout << "\nThank you. Have a wonderful day!";
				cout << "\nPress <Enter> to log off...";
				cin.ignore();
				system("EXIT");
			}
			break;

		default:
			cout << "INVALD: Please choose an option from above: ";
			cin >> firstChoice;
			break;
	}
	cout << endl;
	return 0;
}

/*---------------------------------------------------
					VOID FUNCTIONS					|
----------------------------------------------------*/

void displayDividend(Account &account)
{
	cout << setprecision(2) << account.getDividend();
}
