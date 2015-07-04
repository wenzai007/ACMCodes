#include<iostream>
using namespace std;

class savingaccount       //类savingaccount的定义
{private: double Balance;  //定义数据成员Balance 即余额 
   static  double  AnnualInterestRate; //数据成员，即年利率


   //成员函数的声明
public: savingaccount(double=0);//构造函数
	static 	void modifyInterestRate(double=0);//修改年利率的函数声明modifyInterestRate(double=0)
	static	 double calculateMonthlyInterest();//计算月利率函数calculateMonthlyInterest()
  double getBalance();//求当前余额的函数getBalance()


  //附加的函数功能，
   
int getanymonthBlance();//此函数可以查看以后任意个月后的余额为多少，方便用户查看
double plusbalance();
double lowerbalance();

};

 