#include<iostream>


#include "checkingaccount.h"

using namespace std;


CheckingAccount::CheckingAccount(double a,double b):Account(a)
{Balance=a;fee=b;}//savingaccount��Ĺ��캯������
   

double  CheckingAccount::credit(double a)//��Ǯ��������Ǯ���������,ÿ����ȡ����
  {
 if((Balance+a-fee)<0) cout<<"there is not enough left"<<endl;
  else Balance=Balance+a-fee;
  return Balance;
     }
double CheckingAccount::debit(double a)//ȡǮ����  ��ȡǮ�������٣�ÿ����ȡ����
  {
 
  if (Balance<(a+fee)) cout<<"there is not enough left for what you want "<<endl;
  else   Balance=Balance-a-fee;
  return Balance;
}
