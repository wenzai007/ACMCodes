#include<iostream>
using namespace std;



#include "SavingAccount.h"
 double SavingAccount::AnnualInterestRate=0;// ���徲̬���ݳ�ԱAnnualInterestRate������ֵ
 SavingAccount::SavingAccount(double a)��Account(a) //savingaccount��Ĺ��캯������
    {Balance=a; }
void  SavingAccount::modifyInterestRate(double r)//�޸������ʵĺ���modifyInterestRate(double)�Ķ���
  {   AnnualInterestRate=r;}

double  SavingAccount::calculateMonthlyInterest()//���������ʵĳ�Ա����
 {double m; m=AnnualInterestRate/12;return m; }//�˴��������������ʳ������
 
double SavingAccount:: getInAllBalance()//��ǰ���
  {double b; b=Balance*(1+calculateMonthlyInterest());return b;

}//��һ�����= ֮ǰ���*��+�����ʣ�

