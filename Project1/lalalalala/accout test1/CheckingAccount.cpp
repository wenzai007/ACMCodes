#include<iostream>


#include "CheckingAccount.h"

using namespace std;


CheckingAccount::CheckingAccount(double a,double b):Account(a)
{Balance=a;fee=b;}//savingaccount��Ĺ��캯������
   

double  CheckingAccount::credit(double a)//��Ǯ��������Ǯ���������
  {
 if((Balance+a-fee)<0) cout<<"there is not enough left"<<endl;
  else Balance=Balance+a-fee;
  return Balance;
     }
double CheckingAccount::debit(double a)//ȡǮ����  ��ȡǮ��������
  {
 
  if (Balance<(a+fee)) cout<<"there is not enough left for what you want "<<endl;
  else   Balance=Balance-a-fee;
  return Balance;
}
