#ifndef SAVINGACCOUNT_H 
#define SAVINGACCOUNT_H  

#include<iostream>
#include"account.h"
#include "myexception.h"

using namespace std;

class SavingAccount :public Account
{ protected: static  double AnnualInterestRate;
public:  SavingAccount(double=0,double=0);//���캯��
	static 	void modifyInterestRate(double=0);//�޸������ʵĺ�������modifyInterestRate(double=0)
	   static	double calculateInterest();//���������ʺ���calculateMonthlyInterest()
	 
	


double getInAllBalance();//��ǰ����Ϣ�����ĺ���getBalance()
};

#endif 