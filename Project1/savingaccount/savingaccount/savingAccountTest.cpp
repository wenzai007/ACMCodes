#include "savingaccount.h"
#include <iostream>

using namespace std;

int main(){
	cout << "Create two SavingAccount saver1(2000.00), saver2(3000.00)" << endl;
	savingaccount saver1 = savingaccount(2000.00);//��������saver1 
	savingaccount saver2 = savingaccount(3000.00);//��������saver1 
	cout << "Set annual interest rate to 3%" << endl;
	savingaccount::modifyInterestRate(0.03);//�޸�����Ϊ3%
	cout << "Calculate month interest for saver1" << endl;
	saver1.calculateMonthlyInterest();//��������Ϊ3%ʱ�����������
	cout << "The new balance of saver1 is " << saver1.getBalance() << endl;//�����ǰ���
	cout << "Set annual interest rate to 4%" << endl;
	savingaccount::modifyInterestRate(0.04);//�޸�����Ϊ4%
	cout << "Calculate month interest for saver2" << endl;
	saver2.calculateMonthlyInterest();//��������Ϊ4%ʱ�����������
	cout << "The new balance of saver2 is " << saver2.getBalance() << endl;//�����ǰ���

	

	saver2.plusbalance();//���ø��Ӻ�������Ǯ���������
	saver2.lowerbalance();//���ø��Ӻ�����ȡǮ���������
	saver2.getanymonthBlance();//���ø��Ӻ������鿴������·�֮������
	

	return 0;
}

