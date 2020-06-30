#include "pch.h"
#include <iostream>
#include <string>
#include <array>
#include <typeinfo>
#include <iomanip>

using namespace std;
//Create the BankBranch Class
class BankBranch
{
private:
	int BSBNumber;
	string address;
	int postcode;

public:
	BankBranch();
	BankBranch(int, string, int);
	int getBSBNumber();
	void setBSBNumber(int);
	string getAddress();
	void setAddress(string);
	int getPostcode();
	void setPostcode(int);
	void display();
};

//Create the BankAccount Class
class BankAccount
{
private:
	int accountNumber;
	double accountBalance;
	BankBranch homeBranch;

public:
	BankAccount();
	BankAccount(int, double, int, string, int);
	void setAccountNumber(int);
	int getAccountNumber();
	void setAccountBalance(double);
	double getAccountBalance();
	BankBranch getHomeBranch();
	void display();
};

//Create the SavingsAccount Class
class SavingsAccount: public BankAccount
{
private:
	double interestRate = 0.03;
public:
	SavingsAccount();
	SavingsAccount(double, int, double, int, string, int);
	double getInterestRate();
	void setInterestRate(double);
	void display();
};

//Create the Checking Account Class
class CheckingAccount: public BankAccount
{
private:
	double monthlyFee;
	int numberOfCheckingAccounts;

public:
	CheckingAccount();
	CheckingAccount(double, int, int, double, int, string, int);
	double getMonthlyFee();
	void setMonthlyFee(double);
	int getNumberOfCheckingAccounts();
	void setNumberOfCheckingAccounts(int);
	void display() ;
};

const int NUMBER_OF_ACCOUNTS = 10;

int numberOfSavingsAccounts = 0;
int numberOfChekingAccounts = 0;
int numberOfCheckingAccountsWithInterest = 0;

//Create the CheckingAccountWithInterest Class
class CheckingAccountWithInterest : public virtual SavingsAccount, public virtual CheckingAccount
{
private:
	double interestRate = 0.02;

public:
	CheckingAccountWithInterest();
	CheckingAccountWithInterest(int, double, int, string, int, double, int, double);
	double getInterestRate();
	void setInterestRate(double);
	void display();
	int getAccountNumber();
};

BankAccount::BankAccount()
{

}

BankAccount::BankAccount(int accountNum, double accBalance, int bsbNum, string address, int postCode): homeBranch(bsbNum, address, postCode)
{
	this->accountNumber = accountNum;
	this->accountBalance = accBalance;
}

int BankAccount::getAccountNumber()
{
	return this->accountNumber;
}

void BankAccount::setAccountNumber(int accountNum)
{
	this->accountNumber = accountNum;
}

double BankAccount::getAccountBalance()
{
	return accountBalance;
}

void BankAccount::setAccountBalance(double balance)
{
	this->accountBalance = balance;
}

BankBranch BankAccount::getHomeBranch()
{
	return homeBranch;
}


void BankAccount::display()
{
	cout << " " << this->accountNumber << endl;
	cout << " " << this->accountBalance << endl;
	getHomeBranch().display();
}

BankBranch::BankBranch()
{

}

BankBranch::BankBranch(int bsb, string address, int postCode)
{
	this->BSBNumber = bsb;
	this->address = address;
	this->postcode = postCode;
}

int BankBranch::getBSBNumber()
{
	return BSBNumber;
}

void BankBranch::setBSBNumber(int bsb)
{
	this->BSBNumber = bsb;
}

string BankBranch::getAddress()
{
	return address;
}

void BankBranch::setAddress(string address)
{
	this->address = address;
}

int BankBranch::getPostcode()
{
	return postcode;
}

void BankBranch::setPostcode(int postCode)
{
	this->postcode = postCode;
}

void BankBranch::display()
{
	cout << "			 " << this->BSBNumber << fixed << "	          " << this->address << fixed << "		  " << this->postcode << fixed;
	cout << endl;
}

SavingsAccount::SavingsAccount()
{

}

SavingsAccount::SavingsAccount(double interest, int accNumber, double balance, int bsbNum, string address, int postCode): BankAccount(accNumber, balance, bsbNum, address, postCode)
{
	this->interestRate = interest;
}

double SavingsAccount::getInterestRate()
{
	return interestRate;
}

void SavingsAccount::setInterestRate(double interest)
{
	this->interestRate = interest;
}

void SavingsAccount::display() //Display the Savings Account Report. 
{
	cout << endl << endl << "								-----Savings Account Details-----";
	cout << endl << endl << "		--------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "		Account Number		Account Balance		Interest Rate		BSB Number			Address			Postcode" << endl;
	cout << "		--------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "		" << fixed << setprecision(1) << this->getAccountNumber();
	cout << "			    "  << fixed << setprecision(2) << this->getAccountBalance();
	cout << "		   "<< fixed << this->interestRate;
	getHomeBranch().display();
	cout << "		--------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
}

CheckingAccount ::CheckingAccount()
{

}

CheckingAccount::CheckingAccount(double monthlyFee, int numberOfCheckingAccounts, int accountNum, double balance, int bsbNumber, string address, int postCode) : BankAccount(accountNum, balance, bsbNumber, address, postCode)
{
	this->monthlyFee = monthlyFee;
	this->numberOfCheckingAccounts = numberOfCheckingAccounts;
}

double CheckingAccount::getMonthlyFee()
{
	return monthlyFee;
}

void CheckingAccount::setMonthlyFee(double monthlyFee)
{
	this->monthlyFee = monthlyFee;
}

int CheckingAccount::getNumberOfCheckingAccounts()
{
	return numberOfCheckingAccounts;
}

void CheckingAccount::setNumberOfCheckingAccounts(int numberOfCheckingAccounts)
{
	this->numberOfCheckingAccounts = numberOfCheckingAccounts;
}

void CheckingAccount::display() //Display the Checking Account Report
{
	cout << "								-----Checking Account Details-----" << endl;

	cout << endl << "	-------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "	Account Number	 Account Balance	 Monthly Fee	 No. of Checks Per Month		  BSB Number		 Address		Postcode" << endl;
	cout << "	-------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "	" << this->getAccountNumber();
	cout << "		  "  << fixed << setprecision(2) << this->getAccountBalance();
	cout << "		  " << fixed << setprecision(2) << this->getMonthlyFee();
	cout << "			" << this->getNumberOfCheckingAccounts();
	getHomeBranch().display();
	cout << "	-------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
}

CheckingAccountWithInterest::CheckingAccountWithInterest()
{

}

CheckingAccountWithInterest::CheckingAccountWithInterest( int account, double balance, int bsbNumber, string address, int postCode, double monthlyFee, int numberOfCheckings, double interestRate = 0.02) : SavingsAccount::SavingsAccount(interestRate, account, balance, bsbNumber, address, postCode)
{
	this->setMonthlyFee(monthlyFee);
	this->setNumberOfCheckingAccounts(numberOfCheckings);
}

void CheckingAccountWithInterest::display() //Display the Checking Accounts with Interet Report
{
	cout << endl << endl << "							-----Checking Account with Interest Details-----" << endl;

	cout << endl << "	-------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "	Account Number	 Account Balance	 Monthly Fee	 No. of Checks Per Month	 BSB Number		 Address		Postcode" << endl;
	cout << "	-------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	
	cout << "	 " << this->getAccountNumber();
	cout << "		 " << fixed << setprecision(2) << this->SavingsAccount::getAccountBalance();
	cout << "		 " << this->getMonthlyFee();
	cout << "			 " << this->getNumberOfCheckingAccounts();
	SavingsAccount::getHomeBranch().display();
	cout << "	-------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
}

int CheckingAccountWithInterest::getAccountNumber()
{
	return SavingsAccount::getAccountNumber();
}


// Create a template class for produce report.
template <class T>

void produceReport(T accounts , string message)
{
	cout << message << endl;

	for (int i = 0; i < 10; i++)
	{
		if (accounts[i].getAccountNumber() < 9999 && accounts[i].getAccountNumber() > 1000)
		{
			accounts[i].display();
		}
	}

	cout << "								----END OF THE REPORT----" << endl;
}

// Get account balance.
double getBalance()
{
	double accountBalance;

	do
	{
		cout << endl << "							Enter the account balance: $"; //Get the account balance for each account
		cin >> accountBalance;

		if (accountBalance > 100000) // Check if the account balance is greater than 100 000.00. 
		{
			cout << endl << "								ACCOUNT BALANCE CANNOT EXCEED MORE THAN $100 000.00.   ..TRY AGAIN.." << endl;
		}

		if (accountBalance <= 0.00) // Check if the account balance is less than or equal to zero. 
		{
			cout << endl << "								ACCOUNT BALANCE CANNOT BE ZERO OR LESS THAN ZERO.   ..TRY AGAIN.." << endl;
		}

	} while (accountBalance > 100000 || accountBalance <= 0); // prompt the customer to enter the balance till the balance is greater than 100 000.00 and less than equal to zero. 

	return accountBalance;
}

// Generate random account number.
int getRandomNumber(SavingsAccount sAccounts[], CheckingAccount cAccounts[], CheckingAccountWithInterest ciAccounts[])
{
	bool correctNum = false;
	int randomNumber;

	do
	{
		randomNumber = rand() % 5840;

		//check if the random number is in savings accounts
		for (int i = 0; i < numberOfSavingsAccounts; i++)
		{
			if (randomNumber == sAccounts[i].getAccountNumber())
			{
				correctNum = false;
				break;
			}

		}

		//check if the random number is in checking accounts
		for (int i = 0; i < numberOfChekingAccounts; i++)
		{
			if (randomNumber == cAccounts[i].getAccountNumber())
			{
				correctNum = false;
				break;
			}

		}

		//check if the random number is in check with interest accounts
		for (int i = 0; i < numberOfCheckingAccountsWithInterest; i++)
		{
			if (randomNumber == ciAccounts[i].getAccountNumber())
			{
				correctNum = false;
				break;
			}
			else
			{
				correctNum = true;
			}
		}

		correctNum = true;

	} while (correctNum == false || randomNumber > 9999 || randomNumber < 1000);	// Account number between 1000 to 9999.

	return randomNumber;

}

void generateReports(SavingsAccount customerAccounts[], CheckingAccount customerCAccounts[], CheckingAccountWithInterest CustomerAccounts[])
{
	cout << endl;
	produceReport(customerAccounts, "								-----SAVINGS ACCOUNTS REPORT-----");
	cout << endl;
	produceReport(customerCAccounts, "								-----CHECKING ACCOUNT REPORT-----\n");
	cout << endl;
	produceReport(CustomerAccounts, "							-----CHECKING ACCOUNT WITH INTEREST REPORT-----");
}

void createSavingsAccounts(SavingsAccount customerAccounts[], CheckingAccount customerCAccounts[], CheckingAccountWithInterest CustomerAccounts[])
{
	cout << endl << "						----------------------Create Savings Accounts----------------------" << endl;

	int accountNumber = getRandomNumber(customerAccounts, customerCAccounts, CustomerAccounts);
	bool validValue = true;

	double accountBalance = getBalance();

	int BSBNum, postcode;
	string address;

	cout << "							Enter BSB Number: ";
	cin >> BSBNum;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(10, '\n');
		cout << endl << "								--INVALID INPUT--" << endl << endl;
		cout << "							Enter BSB Number: ";
		cin >> BSBNum;
	}

	cin.ignore();
	cout << "							Enter Bank Address: ";
	getline(cin, address);

	cout << "							Enter Postcode: ";
	cin >> postcode;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(10, '\n');
		cout << endl << "								--INVALID INPUT--" << endl << endl;
		cout << "							Enter Postcode: ";
		cin >> postcode;
	}

	SavingsAccount account = SavingsAccount(0.03, accountNumber, accountBalance, BSBNum, address, postcode);
	account.display();
	customerAccounts[numberOfSavingsAccounts++] = account;
}

void createCheckingAccounts(SavingsAccount customerAccounts[], CheckingAccount customerCAccounts[], CheckingAccountWithInterest CustomerAccounts[])
{
	cout << endl << "						---------------------Create Checking Accounts---------------------" << endl;

	int accountNumber = getRandomNumber(customerAccounts, customerCAccounts, CustomerAccounts);
	bool validValue = true;

	double accountBalance = getBalance();

	int BSBNum, postcode, numberOfCheckingAccounts;;
	double monthlyFee;
	string address;

	cout << "							Enter BSB Number: ";
	cin >> BSBNum;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(10, '\n');
		cout << endl << "								--INVALID INPUT--" << endl << endl;
		cout << "							Enter BSB Number: ";
		cin >> BSBNum;
	}

	cin.ignore();
	cout << "							Enter Bank Address: ";
	getline(cin, address);

	cout << "							Enter Postcode: ";
	cin >> postcode;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(10, '\n');
		cout << endl << "								--INVALID INPUT--" << endl << endl;
		cout << "							Enter Postcode: ";
		cin >> postcode;
	}

	do {
		cout << "							Enter Monthly Fee: $";
		cin >> monthlyFee;

		if (monthlyFee > 100000.00)
		{
			cout << endl << "								MONTHLY FEE CANNOT EXCEED MORE THAN $100 000.00.   ..TRY AGAIN.." << endl << endl;
		}

		if (monthlyFee <= 0.00)
		{
			cout << endl << "								MONTHLY FEE CANNOT BE ZERO OR LESS THAN ZERO.   ..TRY AGAIN.." << endl << endl;
		}

	} while (monthlyFee > 100000 || monthlyFee <= 0);
	
	cout << "							Enter Number of Checks Per Month: ";
	cin >> numberOfCheckingAccounts;
	cout << endl;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(10, '\n');
		cout << endl << "								--INVALID INPUT--" << endl << endl;
		cout << "							Enter Number of Checks Per Month: ";
		cin >> postcode;
	}

	CheckingAccount account = CheckingAccount(monthlyFee, numberOfCheckingAccounts, accountNumber, accountBalance, BSBNum, address, postcode);
	account.display();
	customerCAccounts[numberOfChekingAccounts++] = account;
}

void createCheckingAccountsWithInterest(SavingsAccount customerAccounts[], CheckingAccount customerCAccounts[], CheckingAccountWithInterest CustomerAccounts[])
{
	cout << endl << "						---------------Create Checking Accounts with Interest---------------" << endl;

	int accountNumber = getRandomNumber(customerAccounts, customerCAccounts, CustomerAccounts);
	bool validValue = true;
	double accountBalance = getBalance();
	int BSBNum, postcode, numberOfCheckingAccounts;;
	double monthlyFee;
	string address;

	cout << "							Enter BSB Number: ";
	cin >> BSBNum;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(10, '\n');
		cout << endl << "								--INVALID INPUT--" << endl << endl;
		cout << "							Enter BSB Number: ";
		cin >> postcode;
	}

	cin.ignore();
	cout << "							Enter Bank Address: ";
	getline(cin, address);

	cout << "							Enter Postcode: ";
	cin >> postcode;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(10, '\n');
		cout << endl << "								--INVALID INPUT--" << endl << endl;
		cout << "							Enter Postcode: ";
		cin >> postcode;
	}

	do {
		cout << "							Enter Monthly Fee: $";
		cin >> monthlyFee;

		if (monthlyFee <= 0.00){
			cout << endl << "								MONTHLY FEE CANNOT BE ZERO OR LESS THAN ZERO.   ..TRY AGAIN.." << endl << endl;
		}

		if (monthlyFee > 100000.00){
			cout << endl << "								MONTHLY FEE CANNOT EXCEED MORE THAN $100 000.00.   ..TRY AGAIN.." << endl << endl;
		}
	} while (monthlyFee > 100000 || monthlyFee <= 0);

	cout << "							Enter Number of Checks Per Month: ";
	cin >> numberOfCheckingAccounts;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(10, '\n');
		cout << endl << "								--INVALID INPUT--" << endl << endl;
		cout << "							Enter Number of Checks Per Month: ";
		cin >> postcode;
	}

	CheckingAccountWithInterest account = CheckingAccountWithInterest(accountNumber, accountBalance, BSBNum, address, postcode, monthlyFee , numberOfCheckingAccounts);
	account.display();
	CustomerAccounts[numberOfCheckingAccountsWithInterest++] = account;
}

void transaction(SavingsAccount accounts[])
{
	int depositIndex;
	int accountNumber;
	bool correctNumber = false;

	cout << endl << "						-------------------------Transfer Funds-------------------------" << endl << endl;

	do
	{
		cout << "							Enter the Deposit Account Number: ";
		cin >> accountNumber;

		for (int i = 0; i < numberOfSavingsAccounts; i++)
		{
			if (accounts[i].getAccountNumber() == accountNumber)
			{
				correctNumber = true;
				depositIndex = i;
				break;
			}
		}
		if (correctNumber == false)
		{
			cout << endl << "								INVALID ACCOUNT NUMBER. TRY AGAIN..." << endl << endl;
		}
	} while (correctNumber != true);

	int withdrawIndex;
	int withdrawNum;
	bool correctWithNumber = false;

	do
	{
		cout << endl << "							Enter the Withdraw Account Number: ";
		cin >> withdrawNum;

		for (int i = 0; i < numberOfSavingsAccounts; i++)
		{
			if (accounts[i].getAccountNumber() == withdrawNum)
			{
				correctWithNumber = true;
				withdrawIndex = i;
				break;
			}
		}
		if(correctWithNumber == false)
		{
			cout << endl << "								INVALID ACCOUNT NUMBER. TRY AGAIN..." << endl << endl;
		}

		if (withdrawNum == accountNumber)
		{
			cout << endl << "								BOTH THE ACCOUNT NUMBERS CANNOT BE SAME. TRY AGAIN..." << endl;
		}
	} while ((correctWithNumber == false) || (withdrawNum == accountNumber));
	
	double amount;

	do {
		cout << endl << "							Enter the amount to transfer: $";
		cin >> amount;

		//Check whether transfer amount is less than equal to zero. 
		if (amount <= 0.00) {
			cout << endl << "								TRANSFER AMOUNT CANNOT BE ZERO OR LESS THAN ZERO.   ..TRY AGAIN.." << endl << endl;
		}

		//Check whether transfer amount is greater than 100 000.00. 
		if (amount > 100000.00) {
			cout << endl << "								TRANSFER AMOUNT CANNOT EXCEED MORE THAN $100 000.00.   ..TRY AGAIN.." << endl << endl;
		}
	} while (amount > 100000 || amount <= 0);

	//make the transaction 
	accounts[withdrawIndex].setAccountBalance(accounts[withdrawIndex].getAccountBalance() - amount );

	accounts[depositIndex].setAccountBalance(accounts[depositIndex].getAccountBalance() + amount);
}

int main()
{
	string userName, password;
	int loginAttempts = 1;

	cout << endl << "						----------Welcome to the Interbanking Pty Banking System----------" << endl;
	cout << endl << "							        ----------Customer Login---------- " << endl << endl;

	//To get logged into the system assume that the userName is "testerName" and password is "testerPW". 
	do
	{
		cout << "								  Enter User Name: ";
		getline(cin, userName);
		cout << "								  Enter the Password: ";
		getline(cin, password);
		cout << endl;

		loginAttempts += 1;

		if (userName == "testerName" && password == "testerPW")
		{
			//delcare arrays for bankAccouts
			SavingsAccount savingsAccounts[NUMBER_OF_ACCOUNTS];
			CheckingAccount checkingAccounts[NUMBER_OF_ACCOUNTS];
			CheckingAccountWithInterest checkingWithInterestAccounts[NUMBER_OF_ACCOUNTS];

			int choice;

			do // Main meue of the banking system. 
			{
				cout << endl << "						----------------------------Main MENU----------------------------" << endl << endl;
				cout << "							1. Create Savings Accounts" << endl;
				cout << "							2. Create Checking Accounts" << endl;
				cout << "							3. Create Checking Acoounts with Interest" << endl;
				cout << "							4. Generate Reports" << endl;
				cout << "	 						5. Money Transfer" << endl;
				cout << "							6. Exit" << endl;

				//Get the choice of the customer to continue with the system. 
				cout << endl << "						Enter your Choice: ";
				cin >> choice;

				if (choice == 1) //Calls the createSavingAccount function to create the savings accounts.
				{
					createSavingsAccounts(savingsAccounts, checkingAccounts, checkingWithInterestAccounts);
				}

				else if (choice == 2) //Calls the createCheckingAccounts function to create the checking accounts.
				{
					createCheckingAccounts(savingsAccounts, checkingAccounts, checkingWithInterestAccounts);
				}

				else if (choice == 3) //Calls the createCheckingAccountsWithInterest function to create the checking account with interest accounts.
				{
					createCheckingAccountsWithInterest(savingsAccounts, checkingAccounts, checkingWithInterestAccounts);
				}

				else if (choice == 4) // Calls the generateReport function and it wil display all the accounts summary. 
				{
					generateReports(savingsAccounts, checkingAccounts, checkingWithInterestAccounts);
				}
				else if (choice == 5) // Calls the transaction function and will do the necessary transactions according to the customers desire. 
				{
					if (numberOfSavingsAccounts > 1)
					{
						transaction(savingsAccounts);
					}

					else
					{
						cout << endl << "				INSUFFICIENT NUMBER OF ACCOUNTS TO MAKE A TRANSACTION! THERE MUST BE A MINIMUM OF 2 ACCOUNTS" << endl;
						break;
					}
					
				}

			} while (choice != 6); //Main menu will display until the customer enters 6 to exit the system. 

			return 0;
		}

	} while((userName != " testerName" || password != "testerPW") && (loginAttempts <= 3)); //Customer login menu will run for three times and will check whether the given userName and password are valid or not. 

	if (loginAttempts > 3)// If the login attemps greater than 3, displays the error message. 
	{
		cout << "							Maximum Login Attempts Reached. Try Again Later." << endl;
	}
}