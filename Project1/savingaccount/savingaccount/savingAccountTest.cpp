#include "savingaccount.h"
#include <iostream>

using namespace std;

int main(){
	cout << "Create two SavingAccount saver1(2000.00), saver2(3000.00)" << endl;
	savingaccount saver1 = savingaccount(2000.00);//创建对象saver1 
	savingaccount saver2 = savingaccount(3000.00);//创建对象saver1 
	cout << "Set annual interest rate to 3%" << endl;
	savingaccount::modifyInterestRate(0.03);//修改利率为3%
	cout << "Calculate month interest for saver1" << endl;
	saver1.calculateMonthlyInterest();//在年利率为3%时候计算月利率
	cout << "The new balance of saver1 is " << saver1.getBalance() << endl;//输出当前余额
	cout << "Set annual interest rate to 4%" << endl;
	savingaccount::modifyInterestRate(0.04);//修改利率为4%
	cout << "Calculate month interest for saver2" << endl;
	saver2.calculateMonthlyInterest();//在年利率为4%时候计算月利率
	cout << "The new balance of saver2 is " << saver2.getBalance() << endl;//输出当前余额

	

	saver2.plusbalance();//调用附加函数，存钱，增加余额
	saver2.lowerbalance();//调用附加函数，取钱，减少余额
	saver2.getanymonthBlance();//调用附加函数，查看任意个月份之后的余额
	

	return 0;
}

