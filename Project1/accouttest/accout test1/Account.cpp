#include<iostream>
#include "Account.h"

using namespace std;




 Account::Account(double a) //Account��Ĺ��캯������
{Balance=a; }

  double   Account:: getBalance()
 {cout<<"the Balance now is"<<endl;
  return Balance;}//��ǰ���ĺ���getBalance()

double Account::credit(double a)//��Ǯ��������Ǯ���������
  {Balance=Balance+a;
 return Balance;
    }
double Account::debit(double a)//ȡǮ����  ��ȡǮ��������
  {
  if (Balance<a) cout<<"there is not enough left for what you want "<<endl;
  else   Balance=Balance-a;
   return Balance;
}