#ifndef ACCOUNT_H 
#define ACCOUNT_H   

#include<iostream>
#include "myexception.h"
using namespace std;

class Account       //类Account的定义
{protected: double Balance;  //定义数据成员Balance 即余额
 


   //成员函数的声明
public: Account (double=0);//构造函数
     double getBalance();//求当前余额的函数getBalance()
virtual  double credit(double=0);//定义为虚函数
virtual double debit(double=0);//定义为虚函数
};

#endif 