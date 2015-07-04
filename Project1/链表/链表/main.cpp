

#include"list.h"
#include<iostream>
using namespace std;
void main()
{
	List<int>*intlist=new List<int>();
	List<double>*doublelist=new List<double>();
	intlist->Insert(3);
    intlist->Insert(4);
	intlist->Insert(5);
	intlist->Insert(6);
	cout << "int" << endl;
	intlist->Travels( );
	cout<<endl;
	intlist->Remove(5);
	cout << "after delete data 5" << endl;
    intlist->Travels( );
	cout<<endl;
	cout << "double" << endl;
	doublelist->Insert (1.1);
	doublelist->Insert (2.2);
	doublelist->Insert (3.3);
	doublelist->Insert (4.4);
	doublelist->Insert (5.5);
	doublelist->Travels( );
	cout<<endl;
	doublelist->Remove(4.4);
	cout << "after delete data 4.4" << endl;
	doublelist->Travels( );
}

