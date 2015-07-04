#include<iostream>
using namespace std;



#include "SavingAccount.h"
 double SavingAccount::AnnualInterestRate=0;// 定义静态数据成员AnnualInterestRate并赋初值
  SavingAccount::SavingAccount(double a,double b):Account(a) //savingaccount类的构造函数定义
    {Balance=a;AnnualInterestRate=b; }
void  SavingAccount::modifyInterestRate(double r)//修改年利率的函数modifyInterestRate(double)的定义
  {   AnnualInterestRate=r;}

double  SavingAccount::calculateInterest()//计算月利率的成员函数
 {double m; m=AnnualInterestRate/12;return m;}//此处月利率用年利率除以求得
 
double SavingAccount::getInAllBalance()//求当前余额
  {double b; b=Balance*(1+calculateInterest());return b;

}//下一月余额= 之前余额*（+月利率）

