#include<iostream>
using namespace std;

class SavingAccount :public Account
{ private: static  double AnnualInterestRate;
public: SavingAccount(double=0);//���캯��
	static 	void modifyInterestRate(double=0);//�޸������ʵĺ�������modifyInterestRate(double=0)
	static	 double calculateMonthlyInterest();//���������ʺ���calculateMonthlyInterest()

double getInAllBalance();//��ǰ����Ϣ�����ĺ���getBalance()
};

