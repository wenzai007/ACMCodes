#include<iostream>
using namespace std;



#include "nextnaccount.h"




nextnaccount::nextnaccount(double a, double b)
  {Balance=a;AnnualInterestRate=b; }

double  nextnaccount::getanymonthBlance()
{
	  int n;
	  cout<<"please input the number of the month you want to check"<<endl;//���û�����֮��
	                                                                 //�ĵڼ�����
	  cout<<"the number must be bigger than 0"<<endl;
         cin>>n;
  
 
     if (n>=0)   {for (int i=0;i<n;i++)
        { Balance=Balance*(1+calculateInterest());}//��ѭ�����n����֮������Ϊ����
	 cout<<"the Balance of the next "<<n<<"month you are checking will be"<<Balance<<endl; }
	           //��������Ŀ
  else  {cout<<"wrong operation,there must be a number bigger than 0"<<endl;}
  
  return 0;
}