#include<iostream>
#include"Account.h"
#include "SavingAccount.h"


using namespace std;

class nextnaccount:public SavingAccount //SavingAccount�ļ̳���
{
public:nextnaccount(double=0,double=0);//���캯��

  
  double getanymonthBlance();//���ӵĸ��Ӻ�������������������·�֮������Ϊ����


};