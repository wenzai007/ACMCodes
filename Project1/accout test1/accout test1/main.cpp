#include<iostream>
#include "Account.h"
#include"SavingAccount.h"
#include"CheckingAccount.h"
#include"nextnaccount.h"

using namespace std;

int main()
{
	Account a = Account(100.00);//�����ʼ��
	SavingAccount sa = SavingAccount(1000.00, 0.03);
	CheckingAccount ca = CheckingAccount(3000.00, 100.00);

	Account *p=&ca;//ָ������ָ�룬����ʵ�ֶ�̬����



	a.credit(100.00);//���û��ຯ��
	cout<<a.getBalance()<<endl;
	a.debit(50.00);
	cout<<a.getBalance()<<endl;

	sa.credit(1000.00);//������SavingAccount ��������
	cout<<sa.getBalance()<<endl;
	sa.calculateInterest();
	sa.debit(1000.00);
	cout<<sa.getBalance()<<endl;
	cout<<"the month Interest in the class savingaccount is"<<
		sa.calculateInterest()<<endl;
	cout<<"now the Balance in total is "<<sa.getInAllBalance()<<endl;

	p->credit(10.00);//ָ������ָ��p������checkingaccount�ͻ���accountʱ���ֱ���ø��Եĳ�Ա������
	//���õ�ָ��P,ʵ�ֶ�̬���࣡ 
	cout<<ca.getBalance()<<endl;
	p->debit(1000.00);
	cout<<ca.getBalance()<<endl;



	nextnaccount w=nextnaccount(5000.00,0.05);//����������ĳ�Ա�������ã�
	//��������֮�����
	w.getanymonthBlance();

	return 0;
}

