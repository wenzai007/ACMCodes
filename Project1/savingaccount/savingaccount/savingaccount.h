#include<iostream>
using namespace std;

class savingaccount       //��savingaccount�Ķ���
{private: double Balance;  //�������ݳ�ԱBalance ����� 
   static  double  AnnualInterestRate; //���ݳ�Ա����������


   //��Ա����������
public: savingaccount(double=0);//���캯��
	static 	void modifyInterestRate(double=0);//�޸������ʵĺ�������modifyInterestRate(double=0)
	static	 double calculateMonthlyInterest();//���������ʺ���calculateMonthlyInterest()
  double getBalance();//��ǰ���ĺ���getBalance()


  //���ӵĺ������ܣ�
   
int getanymonthBlance();//�˺������Բ鿴�Ժ�������º�����Ϊ���٣������û��鿴
double plusbalance();
double lowerbalance();

};

 