#include<iostream>
#include"Account.h"


using namespace std;

class CheckingAccount:public Account 
{private: double fee;
public: CheckingAccount (double=0 ,double=0);//���캯��
    virtual  double credit(double=0);//�������������¶��壬�麯��
virtual double debit(double=0);//�������������¶��壬�麯��
};
