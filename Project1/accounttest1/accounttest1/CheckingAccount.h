#include<iostream>
using namespace std;

class CheckingAccount��public  Account 
{public: CheckingAccount (double=0);//���캯��
     virtual  double credit();
       virtual double debit();
};
