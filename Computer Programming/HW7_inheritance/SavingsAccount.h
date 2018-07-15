// HW7 12.10 Account Inheritance Hierarchy
// derived class SavingsAccount definition.
// SavingsAccount.h

#ifndef SAVE_H
#define SAVE_H

#include "Account.h"

class SavingsAccount : public Account
{
public:
	SavingsAccount ( double, double ); // constructor to initialize balance (validate)
	
	double calculateInterest ();
	
protected:
	double interestRate;
};

#endif
