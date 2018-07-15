// HW7 12.10 Account Inheritance Hierarchy
// derived class SavingsAccount function definition.
// SavingsAccount.cpp

#include "SavingsAccount.h"

SavingsAccount::SavingsAccount( double a, double b )
{
	balance = a;
	interestRate = b;
}

double SavingsAccount::calculateInterest()
{
	return balance * interestRate;
}
