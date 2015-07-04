#include<iostream>
using namespace std;

void funa(int *p1,int *p2)
{*p1=*p2;
}

void funb(int *&p1,int *&p2){
*p1=*p2;}

void func(int *p1,int *p2){
p1=p2;}


int main()
{int v1=5;int v2=10;
int *p1=&v1;
int *p2=&v2;
funa(p1,p2);
cout<<"v1的值是:"<<v1<<endl;
cout<<"指针p1所指的值是："<<*p1<<endl;
v1=5;
funb(p1,p2);
cout<<"使用传址参数:  v1的值是"<<v1<<endl;
v1=5;
cout<<"p1 address is "<<&p1<<"  p2 address is  "<<&p2<<endl;

func(p1,p2);

cout<<"p1 address is "<<&p1<<"   p2 address is  "<<&p2<<endl;
cout<<"指针p1所指的值是："<<*p1<<"   p2 zhidezhi"<<*p2<<endl;

getchar();

return 0;



}