#include<iostream>
using namespace std;



#include "savingaccount.h"
 


double savingaccount::AnnualInterestRate=0;// 定义静态数据成员AnnualInterestRate并赋初值
 savingaccount::savingaccount(double a) //savingaccount类的构造函数定义
    {Balance=a; }


 void  savingaccount::modifyInterestRate(double r)//修改年利率的函数modifyInterestRate(double)的定义
  {   AnnualInterestRate=r;}

   double  savingaccount::calculateMonthlyInterest()//计算月利率的成员函数 
 {double m; m=AnnualInterestRate/12;return m; }//此处月利率用年利率除以12求得

  double savingaccount::getBalance()//求当前余额
  {double b; b=Balance*(1+calculateMonthlyInterest());return b;

}//下一月余额= 之前余额*（1+月利率）




//附加的函数个数
  int  savingaccount::getanymonthBlance()
  {   
	  int n;
	  cout<<"please input the number of the month you want to check"<<endl;//由用户输入之后的第几个月
	  cout<<"the number must be bigger than 0"<<endl;
  cin>>n;
  
 
  if (n>=0)   {for (int i=0;i<n;i++)
  { Balance=Balance*(1+calculateMonthlyInterest());}//用循环求出n个月之后的余额为多少
  
  cout<<"the Balance of the next "<<n<<"month you are checking will be"<<Balance<<endl; }//输出余额数目
  else  {cout<<"wrong operation,there must be a number bigger than 0"<<endl;}
  
  return 0;
}

  double savingaccount::lowerbalance()//取钱函数   ，取钱后余额减少
  {double a;
  cout<<"please input the money account you want to take away "<<endl;
  cin>>a;
  Balance=Balance-a;
  cout<< "now the Balance is"<<Balance<<endl;
  return Balance;
    
  }


  double savingaccount::plusbalance()//存钱函数，存钱后余额增多
  {double a;
  cout<<"please input the money account you want to add "<<endl;
  cin>>a;
  Balance=Balance+a;
  cout<< "now the Balance is"<<Balance<<endl;
  return Balance;
    
  }