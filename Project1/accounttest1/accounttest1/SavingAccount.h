#include<iostream>
using namespace std;

class SavingAccount :public Account
{ private: static  double AnnualInterestRate;
public: SavingAccount(double=0);//构造函数
	static 	void modifyInterestRate(double=0);//修改年利率的函数声明modifyInterestRate(double=0)
	static	 double calculateMonthlyInterest();//计算月利率函数calculateMonthlyInterest()

double getInAllBalance();//求当前算利息后余额的函数getBalance()
};

