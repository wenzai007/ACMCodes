#include<iostream>
using namespace std;



#include "savingaccount.h"
 


double savingaccount::AnnualInterestRate=0;// ���徲̬���ݳ�ԱAnnualInterestRate������ֵ
 savingaccount::savingaccount(double a) //savingaccount��Ĺ��캯������
    {Balance=a; }


 void  savingaccount::modifyInterestRate(double r)//�޸������ʵĺ���modifyInterestRate(double)�Ķ���
  {   AnnualInterestRate=r;}

   double  savingaccount::calculateMonthlyInterest()//���������ʵĳ�Ա���� 
 {double m; m=AnnualInterestRate/12;return m; }//�˴��������������ʳ���12���

  double savingaccount::getBalance()//��ǰ���
  {double b; b=Balance*(1+calculateMonthlyInterest());return b;

}//��һ�����= ֮ǰ���*��1+�����ʣ�




//���ӵĺ�������
  int  savingaccount::getanymonthBlance()
  {   
	  int n;
	  cout<<"please input the number of the month you want to check"<<endl;//���û�����֮��ĵڼ�����
	  cout<<"the number must be bigger than 0"<<endl;
  cin>>n;
  
 
  if (n>=0)   {for (int i=0;i<n;i++)
  { Balance=Balance*(1+calculateMonthlyInterest());}//��ѭ�����n����֮������Ϊ����
  
  cout<<"the Balance of the next "<<n<<"month you are checking will be"<<Balance<<endl; }//��������Ŀ
  else  {cout<<"wrong operation,there must be a number bigger than 0"<<endl;}
  
  return 0;
}

  double savingaccount::lowerbalance()//ȡǮ����   ��ȡǮ��������
  {double a;
  cout<<"please input the money account you want to take away "<<endl;
  cin>>a;
  Balance=Balance-a;
  cout<< "now the Balance is"<<Balance<<endl;
  return Balance;
    
  }


  double savingaccount::plusbalance()//��Ǯ��������Ǯ���������
  {double a;
  cout<<"please input the money account you want to add "<<endl;
  cin>>a;
  Balance=Balance+a;
  cout<< "now the Balance is"<<Balance<<endl;
  return Balance;
    
  }