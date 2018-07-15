// HW7 12.10 Account Inheritance Hierarchy
// derived class CheckingsAccount definition.
// CheckingAccount.h

#ifndef CHECK_H
#define CHECK_H

#include "Account.h"

class CheckingAccount : public Account
{
public:
	CheckingAccount( double, double );
	void credit( double );
	void debit( double );
	
private:
	double fee;
};

#endif

