#include<iostream>
using namespace std;

class savingaccount
{private: double Balance;
   static  double  AnnualInterestRate;

public: savingaccount(double=0);
	static 	void modifyInterestRate(double=0);
	static	 double calculateMonthlyInterest();
  double getBalance();

};
 