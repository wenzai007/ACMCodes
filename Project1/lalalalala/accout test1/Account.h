#ifndef ACCOUNT_H 
#define ACCOUNT_H   

#include<iostream>
using namespace std;

class Account       //��Account�Ķ���
{protected: double Balance;  //�������ݳ�ԱBalance �����
 


   //��Ա����������
public: Account (double=0);//���캯��
     double getBalance();//��ǰ���ĺ���getBalance()
virtual  double credit(double=0);
virtual double debit(double=0);
};

#endif 