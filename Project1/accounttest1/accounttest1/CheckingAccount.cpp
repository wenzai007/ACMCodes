#include<iostream>
using namespace std;
#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(double a)��Account(a) //savingaccount��Ĺ��캯������
    {Balance=a; }

double CheckingAccount::credit()//��Ǯ��������Ǯ���������
  {double a;
  cout<<"please input the money account you want to add "<<endl;
  cin>>a;
  Balance=Balance+a-a*0.05;
  cout<< "now the Balance is"<<Balance<<endl;
  return Balance;
    
  }
double CheckingAccount::debit()//ȡǮ����  ��ȡǮ��������
  {double a;
  cout<<"please input the money account you want to take away "<<endl;
  cin>>a;
  if (Blance<1.05*a) cout<<"there is not enough left for what you want "<<endl;
  else   { Balance=Balance-a-0.05*a;
  
  cout<< "now the Balance is"<<Balance<<endl;}
  return Balance;
}
