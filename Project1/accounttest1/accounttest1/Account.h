#include<iostream>
using namespace std;

class Account       //��Account�Ķ���
{private: double Balance;  //�������ݳ�ԱBalance �����
 


   //��Ա����������
public: Account (double=0);//���캯��
double getBalance();//��ǰ���ĺ���getBalance()
virtual  double credit();
virtual double debit();
};
