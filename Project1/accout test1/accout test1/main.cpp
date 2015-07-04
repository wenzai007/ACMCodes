#include<iostream>
#include "Account.h"
#include"SavingAccount.h"
#include"CheckingAccount.h"
#include"nextnaccount.h"

using namespace std;

int main()
{
	Account a = Account(100.00);//对象初始化
	SavingAccount sa = SavingAccount(1000.00, 0.03);
	CheckingAccount ca = CheckingAccount(3000.00, 100.00);

	Account *p=&ca;//指向基类的指针，用于实现动态联编



	a.credit(100.00);//调用基类函数
	cout<<a.getBalance()<<endl;
	a.debit(50.00);
	cout<<a.getBalance()<<endl;

	sa.credit(1000.00);//派生类SavingAccount 函数调用
	cout<<sa.getBalance()<<endl;
	sa.calculateInterest();
	sa.debit(1000.00);
	cout<<sa.getBalance()<<endl;
	cout<<"the month Interest in the class savingaccount is"<<
		sa.calculateInterest()<<endl;
	cout<<"now the Balance in total is "<<sa.getInAllBalance()<<endl;

	p->credit(10.00);//指向基类的指针p，调用checkingaccount和基类account时，分别调用各自的成员函数，
	//需用到指针P,实现动态联编！ 
	cout<<ca.getBalance()<<endl;
	p->debit(1000.00);
	cout<<ca.getBalance()<<endl;



	nextnaccount w=nextnaccount(5000.00,0.05);//附加派生类的成员函数调用，
	//求任意月之后的余额。
	w.getanymonthBlance();

	return 0;
}

