#include<iostream>
#include"Account.h"
#include "SavingAccount.h"


using namespace std;

class nextnaccount:public SavingAccount //SavingAccount的继承类
{
public:nextnaccount(double=0,double=0);//构造函数

  
  double getanymonthBlance();//增加的附加函数，用来求今后任意个月份之后的余额为多少


};