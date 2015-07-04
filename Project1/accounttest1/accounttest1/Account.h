#include<iostream>
using namespace std;

class Account       //类Account的定义
{private: double Balance;  //定义数据成员Balance 即余额
 


   //成员函数的声明
public: Account (double=0);//构造函数
double getBalance();//求当前余额的函数getBalance()
virtual  double credit();
virtual double debit();
};
