#include<iostream>


#include "checkingaccount.h"

using namespace std;


CheckingAccount::CheckingAccount(double a,double b):Account(a)
{Balance=a;fee=b;}//savingaccount类的构造函数定义
   

double  CheckingAccount::credit(double a)//存钱函数，存钱后余额增多,每次收取费用
  {
 if((Balance+a-fee)<0) cout<<"there is not enough left"<<endl;
  else Balance=Balance+a-fee;
  return Balance;
     }
double CheckingAccount::debit(double a)//取钱函数  ，取钱后余额减少，每次收取费用
  {
 
  if (Balance<(a+fee)) cout<<"there is not enough left for what you want "<<endl;
  else   Balance=Balance-a-fee;
  return Balance;
}
