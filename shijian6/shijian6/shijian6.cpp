#include<iostream>
using namespace std;

void swap(int a, int b)
{int t;t=a;a=b;b=t;}
void swap2(int &a,int &b)
{int t; t=a;a=b;b=t;}
int main(){int x=10;int y=100;
cout<<"initial:  "<<"x:"<<x<<"  y: "<<y<<endl;
swap(x,y);
cout<<"initial:  "<<"x:"<<x<<"  y: "<<y<<endl;
swap2(x,y);
cout<<"initial:  "<<"x:"<<x<<"  y: "<<y<<endl;
return 0;	
}