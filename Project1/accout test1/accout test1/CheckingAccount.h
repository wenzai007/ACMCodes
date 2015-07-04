#include<iostream>
#include"Account.h"


using namespace std;

class CheckingAccount:public Account 
{private: double fee;
public: CheckingAccount (double=0 ,double=0);//构造函数
    virtual  double credit(double=0);//增加余额函数，重新定义，虚函数
virtual double debit(double=0);//减少余额函数，重新定义，虚函数
};
