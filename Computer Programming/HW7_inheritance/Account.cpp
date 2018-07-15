// HW7 12.10 Account Inheritance Hierarchy
// base class Account function definitions.
// Account.cpp

#include <iostream>
#include "Account.h"

using namespace std;

Account::Account( double x )
{
	if ( x >= 0.0 )
		balance = x;
	else
	{
		balance = 0.0;
		cout << "Error: The initial balance is invalid, therefore set to 0.0" << endl;
	}
}

bool Account::credit( double a )
{
	if ( a > 0.0 )
	{
		balance += a;
		return true;
	}	
	else
	{
		cout << "Invalid attempt." << endl;
		return false;
	}
}

bool Account::debit( double b )
{
	if ( b <= balance )
	{
		balance -= b;
		return true;
	}
	else
	{
		cout << "Debit amount exceeded account balance." << endl;
		return false;
	}
}

double Account::getBalance( )
{
	return balance;
}
