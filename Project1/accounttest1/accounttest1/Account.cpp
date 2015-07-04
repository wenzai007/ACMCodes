#include<iostream>
using namespace std;



#include " Account"
 Account::Account(double a) //Account类的构造函数定义
{Balance=a; }
double Account::credit()//存钱函数，存钱后余额增多
  {double a;
  cout<<"please input the money account you want to add "<<endl;
  cin>>a;
  Balance=Balance+a;
  cout<< "now the Balance is"<<Balance<<endl;
  return Balance;
    
  }
double Account::debit()//取钱函数  ，取钱后余额减少
  {double a;
  cout<<"please input the money account you want to take away "<<endl;
  cin>>a;
  if (Blance<a) cout<<"there is not enough left for what you want "<<endl;
  else   { Balance=Balance-a;
  
  cout<< "now the Balance is"<<Balance<<endl;}
  return Balance;
}
