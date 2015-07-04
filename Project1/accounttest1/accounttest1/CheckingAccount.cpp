#include<iostream>
using namespace std;
#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(double a)：Account(a) //savingaccount类的构造函数定义
    {Balance=a; }

double CheckingAccount::credit()//存钱函数，存钱后余额增多
  {double a;
  cout<<"please input the money account you want to add "<<endl;
  cin>>a;
  Balance=Balance+a-a*0.05;
  cout<< "now the Balance is"<<Balance<<endl;
  return Balance;
    
  }
double CheckingAccount::debit()//取钱函数  ，取钱后余额减少
  {double a;
  cout<<"please input the money account you want to take away "<<endl;
  cin>>a;
  if (Blance<1.05*a) cout<<"there is not enough left for what you want "<<endl;
  else   { Balance=Balance-a-0.05*a;
  
  cout<< "now the Balance is"<<Balance<<endl;}
  return Balance;
}
