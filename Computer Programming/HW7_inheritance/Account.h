// HW7 12.10 Account Inheritance Hierarchy
// base class Account definition.

#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
public:
	Account( double ); // constructor to initialize balance (validate)
	
	// set functions
	bool credit ( double ); // add an amount to current balance
	bool debit ( double ); // withdraw money (validate)
	
	// get functions
	double getBalance ( );
	
protected:
	double balance;
};

#endif
