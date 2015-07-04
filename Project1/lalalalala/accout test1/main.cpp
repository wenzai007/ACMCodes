#include<iostream>
#include "Account.h"
#include"SavingAccount.h"
#include"CheckingAccount.h"

using namespace std;

int main()
{
	Account a = Account(100.00);
	SavingAccount sa = SavingAccount(1000.00, 0.03);
	CheckingAccount ca = CheckingAccount(3000.00, 100.00);

	Account *p=&ca;



	a.credit(100.00);
	cout<<a.getBalance()<<endl;
	a.debit(50.00);
	cout<<a.getBalance()<<endl;

	sa.credit(1000.00);
	cout<<sa.getBalance()<<endl;
	sa.calculateInterest();
	sa.debit(1000.00);
	cout<<sa.getBalance()<<endl;

	p->credit(10.00);
	cout<<ca.getBalance()<<endl;
	p->debit(1000.00);
	cout<<ca.getBalance()<<endl;

	return 0;
}

