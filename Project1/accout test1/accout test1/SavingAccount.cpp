#include<iostream>
using namespace std;



#include "SavingAccount.h"
 double SavingAccount::AnnualInterestRate=0;// ���徲̬���ݳ�ԱAnnualInterestRate������ֵ
  SavingAccount::SavingAccount(double a,double b):Account(a) //savingaccount��Ĺ��캯������
    {Balance=a;AnnualInterestRate=b; }
void  SavingAccount::modifyInterestRate(double r)//�޸������ʵĺ���modifyInterestRate(double)�Ķ���
  {   AnnualInterestRate=r;}

double  SavingAccount::calculateInterest()//���������ʵĳ�Ա����
 {double m; m=AnnualInterestRate/12;return m;}//�˴��������������ʳ������
 
double SavingAccount::getInAllBalance()//��ǰ���
  {double b; b=Balance*(1+calculateInterest());return b;

}//��һ�����= ֮ǰ���*��+�����ʣ�

