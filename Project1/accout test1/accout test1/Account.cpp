#include<iostream>
#include "Account.h"

using namespace std;




 Account::Account(double a) //Account类的构造函数定义
{Balance=a; }

  double   Account:: getBalance()
 {cout<<"the Balance now is"<<endl;
  return Balance;}//求当前余额的函数getBalance()

double Account::credit(double a)//存钱函数，存钱后余额增多
  {Balance=Balance+a;
 return Balance;
    }
double Account::debit(double a)//取钱函数  ，取钱后余额减少
  {
  if (Balance<a) cout<<"there is not enough left for what you want "<<endl;
  else   Balance=Balance-a;
   return Balance;
}