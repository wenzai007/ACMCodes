#include<iostream>
using namespace std;



#include " Account"
 Account::Account(double a) //Account��Ĺ��캯������
{Balance=a; }
double Account::credit()//��Ǯ��������Ǯ���������
  {double a;
  cout<<"please input the money account you want to add "<<endl;
  cin>>a;
  Balance=Balance+a;
  cout<< "now the Balance is"<<Balance<<endl;
  return Balance;
    
  }
double Account::debit()//ȡǮ����  ��ȡǮ��������
  {double a;
  cout<<"please input the money account you want to take away "<<endl;
  cin>>a;
  if (Blance<a) cout<<"there is not enough left for what you want "<<endl;
  else   { Balance=Balance-a;
  
  cout<< "now the Balance is"<<Balance<<endl;}
  return Balance;
}
