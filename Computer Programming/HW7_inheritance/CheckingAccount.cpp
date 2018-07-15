// HW7 12.10 Account Inheritance Hierarchy
// derived class CheckingAccount function definition.
// CheckingAccount.cpp

#include <iostream>
#include "CheckingAccount.h"

CheckingAccount::CheckingAccount( double a, double b )
{
	balance = a;
	fee = b;
}

void CheckingAccount::credit( double a )
{
	if ( a > 0.0 )
		balance += ( a - fee );
}

void CheckingAccount::debit( double b )
{
	if ( balance >= ( b + fee ) )
		balance -= ( b + fee );	
}


