#include<iostream>
#include"Account.h"


using namespace std;

class CheckingAccount:public Account 
{private: double fee;
public: CheckingAccount (double=0 ,double=0);//¹¹Ôìº¯Êý
    virtual  double credit(double=0);
virtual double debit(double=0);
};
