#include "account.h"
#include"checkingaccount.h"
#include "SavingAccount.h"
#include "myexception.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

#define SAVINGACCOUNT 1
#define CHECKINGACCOUNT 2

using namespace std;

int main(){
	int n, i;
	int type;
	double d1, d2;
	ifstream datasource("bank.txt",ios::in);//创建文件 取名为“bank”
	if (!datasource){
		cout << "File could not be opened." << endl;
		exit(1);
	}

	Account **bank;

	datasource >> n;

	bank = new Account*[n];//动态指针数组的创建

	try {
		for (i = 0; i < n; i++){
			datasource >> type;//分别读取文档中的信息。
			datasource >> d1;
			datasource >> d2;
			if (type == SAVINGACCOUNT)//判断类型
			{
				bank[i] = new SavingAccount(d1, d2);
			} else if (type == CHECKINGACCOUNT){
				bank[i] = new CheckingAccount(d1, d2);
			} else {
				cout << "Unknown account type" << endl;
				exit(1);
			}
		}

		
		for (i = 0; i < n; i++){                   //分别调用各个对象的成员函数
			bank[i]->credit(300.00);
			bank[i]->debit(100.00);
		}

		for (i = 0; i < n; i++){
			cout << i << " : " << bank[i]->getBalance() << endl;
		}
	} catch (BalanceLessThanZeroException &balanceLessThanZeroException){//捕获异常，当余额少于0时，报错
		cout << "Exception occurred :"
			<< balanceLessThanZeroException.what() << endl;
	}

	return 0;
}

